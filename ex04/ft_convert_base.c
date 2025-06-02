/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:20:16 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/02 11:18:32 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*rev_str(char *str);
int		pos_in_str(char *str, char c);

int	ft_check_base(char *base)
{
	int	cur;
	int	cur2;

	cur = 0;
	if (ft_strlen(base) < 2)
		return (0);
	cur = 0;
	while (base[cur])
	{
		if (base[cur] == '+' || base[cur] == '-')
			return (0);
		if ((base[cur] >= 9 && base[cur] <= 13) || base[cur] == ' ')
			return (0);
		if (base[cur] < 32 || base[cur] > 126)
			return (0);
		cur2 = cur + 1;
		while (base[cur2])
		{
			if (base[cur] == base[cur2])
				return (0);
			cur2++;
		}
		cur++;
	}
	return (1);
}

int	ft_malloc(char **nbr_str, int *is_neg, long *nbrl)
{
	*nbr_str = (char *)malloc(sizeof(char) * 33);
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

char	*ft_getnbr_base(int nbr, char *base)
{
	long	nbrl;
	char	*nbr_str;
	int		base_len;
	int		cur;
	int		is_neg;

	nbrl = nbr;
	if (ft_malloc(&nbr_str, &is_neg, &nbrl) == 0)
		return (0);
	base_len = ft_strlen(base);
	cur = 0;
	while (nbrl > 0)
	{
		nbr_str[cur++] = base[nbrl % base_len];
		nbrl /= base_len;
	}
	if (nbr == 0)
	{
		cur = 1;
		nbr_str[0] = '0';
	}
	if (is_neg == -1)
		nbr_str[cur++] = '-';
	nbr_str[cur] = 0;
	return (rev_str(nbr_str));
}

int	ft_atoi_base(char *str, char *base)
{
	int	cur;
	int	is_neg;
	int	result;
	int	base_len;

	base_len = ft_strlen(base);
	result = 0;
	is_neg = 1;
	cur = 0;
	while ((str[cur] >= 9 && str[cur] <= 13) || str[cur] == ' ')
		cur++;
	while (str[cur] && (str[cur] == '+' || str[cur] == '-'))
	{
		if (str[cur] == '-')
			is_neg *= -1;
		cur++;
	}
	while (str[cur] && pos_in_str(base, str[cur]) != -1)
	{
		result = result * base_len + pos_in_str(base, str[cur]);
		cur++;
	}
	return (result * is_neg);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		str_to_int;
	char	*int_to_str;

	if (ft_check_base(base_from) == 0)
		return (0);
	if (ft_check_base(base_to) == 0)
		return (0);
	str_to_int = ft_atoi_base(nbr, base_from);
	int_to_str = ft_getnbr_base(str_to_int, base_to);
	return (int_to_str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_convert_base("   \n -10101010", "01", "01"));
// 	printf("%s\n", ft_convert_base("\t\n\r\v\f--+++++-45", "0123456789", 
// "0123456789ABCDEF"));
// 	printf("%s\n", ft_convert_base("15", "0123456789", "01"));
// 	printf("%s\n", ft_convert_base("10000", "01", "0123456789"));
// 	printf("%s\n", ft_convert_base("-31", "0123456789", "0123456789abcdef"));
// 	printf("%s\n", ft_convert_base("+1f", "0123456789abcdef", "0123456789"));
// 	printf("%s\n", ft_convert_base("0", "0123456789", "0123456789abcdef"));
// 	printf("%s\n", ft_convert_base("0.1234567", "0123456789", "0123456789"));
// 	printf("%s\n", ft_convert_base("2147483647", "0123456789", 
// "0123456789abcdef"));
// 	printf("%s\n", ft_convert_base("-80000000", "0123456789abcdef", 
// "0123456789"));
// 	printf("%s\n", ft_convert_base("01", "0123456789", "poneyvif"));
// 	printf("%s\n", ft_convert_base("", "0123456789", "poney vif"));
// 	printf("%s\n", ft_convert_base("-25738", "0123456789", "1234567890ertyu"));

// 	char *str = ft_convert_base("2147l45", "0123456789", "0123456789abcdef");
// 	int cur = 0;
// 	while (str[cur] != 0)
// 	{
// 		printf("%c", str[cur]);
// 		cur++;
// 	}
// 	printf("\n");
// }
