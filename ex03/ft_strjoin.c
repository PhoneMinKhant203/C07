/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 22:52:34 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/02 10:18:52 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	cur;

	cur = 0;
	while (str[cur] != 0)
		cur++;
	return (cur);
}

char	*ft_strcat(char *dest, char *src)
{
	int	cur;
	int	destcur;

	cur = 0;
	destcur = ft_strlen(dest);
	while (src[cur] != 0)
	{
		dest[destcur] = src[cur];
		cur++;
		destcur++;
	}
	dest[destcur] = 0;
	return (dest);
}

int	get_size_of_future_str(int size, char **strs, char *sep)
{
	int	joined_size;
	int	cur;

	joined_size = 0;
	cur = -1;
	while (cur++, cur < size)
		joined_size += ft_strlen(strs[cur]);
	joined_size += (size - 1) * ft_strlen(sep);
	return (joined_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		cur;
	int		joined_size;

	if (size <= 0)
	{
		joined = (char *)malloc(0);
		return (joined);
	}
	joined_size = get_size_of_future_str(size, strs, sep);
	joined = (char *)malloc(sizeof(char) * (joined_size + 1));
	while (joined_size-- >= 0)
		joined[joined_size] = '\0';
	cur = -1;
	while (cur++, cur < size)
	{
		joined = ft_strcat(joined, strs[cur]);
		if (cur != size - 1)
			joined = ft_strcat(joined, sep);
	}
	return (joined);
}

// int main(void)
// {
// 	char	**strs;

// 	strs = (char **)malloc(sizeof(char *) * 3);
// 	strs[0] = (char *)malloc(sizeof(char) * 6);
// 	strs[0] = "Hello";
// 	strs[1] = (char *)malloc(sizeof(char) * 6);
// 	strs[1] = "World";
// 	strs[2] = (char *)malloc(sizeof(char) * 6);
// 	strs[2] = "!!";
// 	for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 6; j++) {
//             printf("%c", strs[i][j]);
//         }
//       	printf("\n");
//     }
// 	printf("\n");
// 	printf("%s", ft_strjoin(3, strs, " - "));
// }
