/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:59:31 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/03 14:24:33 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

long long	ft_strlen(char *str)
{
	long long	length;

	length = 0;
	while (*str++)
		length++;
	return (length);
}

char	*empty_string(void)
{
	char	*str;

	str = malloc (sizeof(*str));
	*str = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char		*str;
	char		*tmp;
	int			index;
	long long	total;

	if (!size)
		return (empty_string());
	total = 0;
	index = 0;
	while (index < size)
		total += ft_strlen(strs[index++]);
	str = malloc (total + ft_strlen(sep) * (size - 1) + 1);
	tmp = ft_strcat(str, strs[0]);
	index = 1;
	while (index < size)
	{
		tmp = ft_strcat(tmp, sep);
		tmp = ft_strcat(tmp, strs[index++]);
	}
	*tmp = '\0';
	return (str);
}

// int	main(void)
// {
// 	int size = 2;
// 	char *strs[2] = {"Hello", "world"};
// 	char *sep = "-";
// 	char *ret = ft_strjoin(size, strs, sep);
// 	printf("-> %s|\n", ret);
// 	free(ret);
// }
