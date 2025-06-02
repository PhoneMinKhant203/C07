#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cur = 0;
	while (str[cur])
		cur++;
	return (cur);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i = 0;
	int	j = ft_strlen(dest);

	while (src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}

int	get_size_of_future_str(int size, char **strs, char *sep)
{
	int	total_len = 0;

	for (int i = 0; i < size; i++)
		total_len += ft_strlen(strs[i]);
	total_len += (size - 1) * ft_strlen(sep);
	return total_len;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	if (size <= 0)
	{
		char *empty = (char *)malloc(1);
		if (empty)
			empty[0] = '\0';
		return empty;
	}

	int	total_len = get_size_of_future_str(size, strs, sep);
	char *joined = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!joined)
		return NULL;

	joined[0] = '\0'; // Important: initialize to empty string

	for (int i = 0; i < size; i++)
	{
		ft_strcat(joined, strs[i]);
		if (i < size - 1)
			ft_strcat(joined, sep);
	}
	return joined;
}
