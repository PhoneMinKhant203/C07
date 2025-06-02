/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:06:18 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/02 10:18:04 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*a;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	a = (int *)malloc(sizeof(*a) * (max - min));
	if (a == NULL)
		return (-1);
	else
	{
		i = -1;
		while (++i < max - min)
			a[i] = min + i;
		*range = a;
		return (i);
	}
}

// int	main(void)
// {
// 	int i;
// 	int *a;
// 	int min;
// 	int max;
// 	int size;

// 	min = 3;
// 	max = 5;
// 	size = ft_ultimate_range(&a, min, max);
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
