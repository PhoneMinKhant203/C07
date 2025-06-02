/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:20:16 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/03 00:08:58 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *rev_str(char *str)
{
    int i = 0;
    int j = ft_strlen(str) - 1;
    char tmp;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return str;
}

int pos_in_str(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return i;
        i++;
    }
    return -1;
}

int ft_check_base(char *base)
{
    int i, j;
    if (ft_strlen(base) < 2)
        return 0;
    for (i = 0; base[i]; i++)
    {
        if (base[i] == '+' || base[i] == '-')
            return 0;
        if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
            return 0;
        if (base[i] < 32 || base[i] > 126)
            return 0;
        for (j = i + 1; base[j]; j++)
        {
            if (base[i] == base[j])
                return 0;
        }
    }
    return 1;
}

// Converts integer to string in given base (without malloc)
// Caller must provide a buffer large enough (e.g., 33 chars)
// Returns pointer to buffer with null-terminated string result
char *ft_getnbr_base_no_malloc(int nbr, char *base, char *buffer, int buffer_size)
{
    long nbrl = nbr;
    int base_len = ft_strlen(base);
    int cur = 0;
    int is_neg = 1;

    if (buffer_size < 2) // at least room for '0' and '\0'
        return NULL;

    if (nbrl < 0)
    {
        nbrl = -nbrl;
        is_neg = -1;
    }

    if (nbrl == 0)
        buffer[cur++] = base[0];

    while (nbrl > 0 && cur < buffer_size - 1)
    {
        buffer[cur++] = base[nbrl % base_len];
        nbrl /= base_len;
    }

    if (is_neg == -1)
    {
        if (cur >= buffer_size - 1) // not enough space for '-'
            return NULL;
        buffer[cur++] = '-';
    }
    buffer[cur] = '\0';

    return rev_str(buffer);
}

int ft_atoi_base(char *str, char *base)
{
    int cur = 0;
    int is_neg = 1;
    int result = 0;
    int base_len = ft_strlen(base);
    int pos;

    while ((str[cur] >= 9 && str[cur] <= 13) || str[cur] == ' ')
        cur++;
    while (str[cur] == '+' || str[cur] == '-')
    {
        if (str[cur] == '-')
            is_neg *= -1;
        cur++;
    }
    while (str[cur] && (pos = pos_in_str(base, str[cur])) != -1)
    {
        result = result * base_len + pos;
        cur++;
    }
    return (result * is_neg);
}

// Converts nbr string from base_from to base_to, writing result to buffer
// Returns pointer to buffer or NULL on error
char *ft_convert_base_no_malloc(char *nbr, char *base_from, char *base_to, char *buffer, int buffer_size)
{
    int num;
    if (!ft_check_base(base_from) || !ft_check_base(base_to))
        return NULL;
    num = ft_atoi_base(nbr, base_from);
    return ft_getnbr_base_no_malloc(num, base_to, buffer, buffer_size);
}

// int main(void)
// {
//     char result[33];

//     char *converted = ft_convert_base_no_malloc("42", "0123456789", "0123456789ABCDEF", result, sizeof(result));
//     if (converted)
//         printf("Converted: %s\n", converted);
//     else
//         printf("Conversion error\n");

//     return 0;
// }

// int main(void)
// {
// 	char *result;

// 	// Convert from base 10 to base 16 (e.g. "42" to "2A")
// 	result = ft_convert_base("42", "0123456789", "0123456789ABCDEF");

// 	if (result)
// 	{
// 		printf("Converted: %s\n", result);
// 		free(result); //
// 	}
// 	else
// 	{
// 		printf("Conversion failed.\n");
// 	}
// 	return 0;
// }
