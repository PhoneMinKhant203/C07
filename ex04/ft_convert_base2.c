/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:20:13 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/02 10:27:42 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len = 0;

	while (str[len])
		len++;
	return (len);
}

char	*rev_str(char *str)
{
	int	start = 0;
	int	end = ft_strlen(str) - 1;
	char	tmp;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	return (str);
}

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
