#include <stdlib.h>
#include <stdio.h> // For testing and printf

int	ft_strlen(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

// Reverses a string in-place and returns the same pointer
char	*rev_str(char *str)
{
	int		i = 0;
	int		j = ft_strlen(str) - 1;
	char	temp;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

// Returns index of char c in str, or -1 if not found
int	pos_in_str(char *str, char c)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// Validates the base string
int	ft_check_base(char *base)
{
	int	i, j;

	if (ft_strlen(base) < 2)
		return (0);
	for (i = 0; base[i]; i++)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		for (j = i + 1; base[j]; j++)
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

// Allocates memory for result string and handles sign
int	ft_malloc(char **nbr_str, int *is_neg, long *nbrl)
{
	*nbr_str = (char *)malloc(sizeof(char) * 33); // Enough for 32 digits + null
	if (*nbr_str == NULL)
		return (0);
	*is_neg = 1;
	if (*nbrl < 0)
	{
		*nbrl *= -1;
		*is_neg = -1;
	}
	return (1);
}

// Converts integer to string in given base
char	*ft_getnbr_base(int nbr, char *base)
{
	long	nbrl = nbr;
	char	*nbr_str;
	int		base_len = ft_strlen(base);
	int		cur = 0;
	int		is_neg;

	if (!ft_malloc(&nbr_str, &is_neg, &nbrl))
		return (0);

	while (nbrl > 0)
	{
		nbr_str[cur++] = base[nbrl % base_len];
		nbrl /= base_len;
	}
	if (nbr == 0)
		nbr_str[cur++] = '0';
	if (is_neg == -1)
		nbr_str[cur++] = '-';
	nbr_str[cur] = '\0';

	return rev_str(nbr_str);
}

// Converts string number in given base to integer
int	ft_atoi_base(char *str, char *base)
{
	int	cur = 0;
	int	is_neg = 1;
	int	result = 0;
	int	base_len = ft_strlen(base);

	while ((str[cur] >= 9 && str[cur] <= 13) || str[cur] == ' ')
		cur++;
	while (str[cur] == '+' || str[cur] == '-')
	{
		if (str[cur] == '-')
			is_neg *= -1;
		cur++;
	}
	while (pos_in_str(base, str[cur]) != -1)
	{
		result = result * base_len + pos_in_str(base, str[cur]);
		cur++;
	}
	return (result * is_neg);
}

// Converts a number string from one base to another
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		str_to_int;
	char	*int_to_str;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	str_to_int = ft_atoi_base(nbr, base_from);
	int_to_str = ft_getnbr_base(str_to_int, base_to);
	return (int_to_str); // Caller is responsible for freeing
}

// --- Example Usage with Free to Avoid Memory Leak ---
int main(void)
{
	char *result;

	// Convert from base 10 to base 16 (e.g. "42" to "2A")
	result = ft_convert_base("42", "0123456789", "0123456789ABCDEF");

	if (result)
	{
		printf("Converted: %s\n", result);
		free(result); // ✅ Prevent memory leak
	}
	else
	{
		printf("Conversion failed.\n");
	}
	return 0;
}
