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
	int	cur;

	cur = 0;
	while (str[cur] != 0)
		cur++;
	return (cur);
}

char	*rev_str(char *str)
{
	int		size;
	int		cur;
	char	tmp;

	size = ft_strlen(str) - 1;
	cur = 0;
	while (cur < size - cur)
	{
		tmp = str[cur];
		str[cur] = str[size - cur];
		str[size - cur] = tmp;
		cur++;
	}
	return (str);
}

int	pos_in_str(char *str, char c)
{
	int	cur;

	cur = 0;
	while (str[cur] != 0)
	{
		if (str[cur] == c)
			return (cur);
		cur++;
	}
	return (-1);
}
