/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:48:48 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/02 23:36:31 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_find_len(int *size, char **strs, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		*size += ft_strlen(strs[index]);
		index++;
	}
}

void	ft_write_data(int size, char **result, char **strs, char *sep)
{
	int	index;
	int	str_index;
	int	sep_index;
	int	total;

	total = 0;
	index = 0;
	while (index < size)
	{
		str_index = 0;
		while (strs[index][str_index])
			(*result)[total++] = strs[index][str_index++];
		sep_index = 0;
		while (index < (size -1) && sep[sep_index])
			(*result)[total++] = sep[sep_index++];
		index++;
	}
	(*result)[total] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_size;
	char	*result;

	if (size == 0)
	{
		result = malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	ft_find_len(&total_size, strs, size);
	total_size += ft_strlen(sep) * (size - 1);
	result = (char *)malloc(sizeof(char) * (total_size + 1));
	if (result == NULL)
	{
		result = NULL;
		return (result);
	}
	ft_write_data(size, &result, strs, sep);
	return (result);
}

// #include <stdio.h>
// int main(void)
// {
// 	int size = 2;
// 	char *strs[2] = {"Hello", "world"};
// 	char *sep = "_";
// 	char *ret = ft_strjoin(size, strs, sep);
// 	printf("-> %s|\n", ret);
// 	free(ret);
// }
