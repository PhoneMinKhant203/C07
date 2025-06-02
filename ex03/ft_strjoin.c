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

int ft_strlen(char *str)
{
    int count = 0;
    while (str[count])
        count++;
    return count;
}

void ft_write_data_no_malloc(int size, char *result, char **strs, char *sep, int buffer_size)
{
    int index = 0;
    int str_index;
    int sep_index;
    int total = 0;

    while (index < size)
    {
        str_index = 0;
        while (strs[index][str_index])
        {
            if (total >= buffer_size - 1) // Leave space for null terminator
                return;
            result[total++] = strs[index][str_index++];
        }
        sep_index = 0;
        while (index < (size - 1) && sep[sep_index])
        {
            if (total >= buffer_size - 1)
                return;
            result[total++] = sep[sep_index++];
        }
        index++;
    }
    if (total < buffer_size)
        result[total] = '\0';
}

int ft_strjoin_no_malloc(int size, char **strs, char *sep, char *buffer, int buffer_size)
{
    int total_size = 0;
    int i;

    if (size == 0)
    {
        if (buffer_size < 1)
            return 0; // failure: not enough space for '\0'
        buffer[0] = '\0';
        return 1; // success
    }

    // Calculate total length needed
    for (i = 0; i < size; i++)
        total_size += ft_strlen(strs[i]);
    total_size += ft_strlen(sep) * (size - 1);

    if (total_size + 1 > buffer_size)
        return 0; // failure: buffer too small

    ft_write_data_no_malloc(size, buffer, strs, sep, buffer_size);

    return 1; // success
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
