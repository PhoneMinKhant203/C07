/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:36:06 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/03 14:50:34 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>

int		checkbase(char *base);
int		fn(char c, char *base_from);
char	*ft_putnbr_base(long nbr, char *base, int sign);
int		ft_strlen(char *nbr);
void	skip(char *nbr, int *i, int *sign);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	long	returned;
	int		sign;

	i = 0;
	sign = 0;
	returned = 0;
	if (checkbase(base_from) == 0 || checkbase(base_to) == 0)
		return (0);
	skip(nbr, &i, &sign);
	while (i < ft_strlen(nbr) - 1 && nbr[i] && fn(nbr[i], base_from) != -1)
	{
		returned += fn(nbr[i], base_from);
		if (++i && fn(nbr[i], base_from) == -1)
			break ;
		returned *= ft_strlen(base_from);
	}
	if (fn(nbr[i], base_from) != -1)
		returned += fn(nbr[i], base_from);
	return (ft_putnbr_base(returned, base_to, sign));
}

// int	main(void)
// {
// 	printf("-10101010 : %s\n", ft_convert_base("   \n -10101010", "01", "01"));
// 	printf("-2D : %s\n", ft_convert_base("\t\n\r\v\f--+++++-45", 
// "0123456789", "0123456789ABCDEF"));
// 	printf("1111 : %s\n", ft_convert_base("15", "0123456789", "01"));
// 	printf("16 : %s\n", ft_convert_base("10000", "01", "0123456789"));
// 	printf("-1f : %s\n", ft_convert_base("-31", "0123456789", 
// "0123456789abcdef"));
// 	printf("31 : %s\n", ft_convert_base("+1f", "0123456789abcdef", 
// "0123456789"));
// 	printf("0 : %s\n", ft_convert_base("0", "0123456789", "0123456789abcdef"));
// 	printf("0 : %s\n", ft_convert_base("0.1234567", 
// "0123456789", "0123456789"));
// 	printf("7fffffff : %s\n", ft_convert_base("2147483647", "
// 0123456789", "0123456789abcdef"));
// 	printf("-2147483648 : %s\n", ft_convert_base("-80000000", 
// "0123456789abcdef", "0123456789"));
// 	printf("o : %s\n", ft_convert_base("01", "0123456789", "poneyvif"));
// 	printf("(null) : %s\n", ft_convert_base("", "0123456789", "poney vif"));
// 	printf("-806y : %s\n", ft_convert_base("-25738", "0123456789", 
// "1234567890ertyu"));

// 	char *str = ft_convert_base("2147l45", "0123456789", 
// "0123456789abcdef");
// 	int cur = 0;
// 	printf("863 : ");
// 	while (str[cur] != 0)
// 	{
// 		printf("%c", str[cur]);
// 		cur++;
// 	}
// 	printf("\n");
// }
