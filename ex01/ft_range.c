/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:13:27 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/02 10:18:15 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*a;
	int		i;

	if (min >= max)
		return (NULL);
	a = (int *)malloc(sizeof(*a) * (max - min));
	if (a == NULL)
		return (NULL);
	else
	{
		i = -1;
		while (++i < max - min)
			a[i] = min + i;
		return (a);
	}
}

// int	main(void)
// {
// 	int i;
// 	int *a;
// 	int min;
// 	int max;

// 	min = 3;
// 	max = 5;
// 	a = ft_range(min, max);
// 	if (a != NULL)
// 	{
// 		i = -1;
// 		while (++i < max - min)
// 		{
// 			printf("%d\n", a[i]);
// 		}
// 	}
// 	else
// 		printf("lololol");
// }
