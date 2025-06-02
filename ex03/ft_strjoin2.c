#include <stdlib.h>
#include <stdio.h> // Required for printf

// Function to calculate the length of a string
int	ft_strlen(char *str)
{
	int	cur = 0;
	while (str[cur] != 0)
		cur++;
	return (cur);
}

// Function to concatenate src string to dest string
char	*ft_strcat(char *dest, char *src)
{
	int	cur = 0;
	int	destcur = ft_strlen(dest);
	while (src[cur] != 0)
	{
		dest[destcur] = src[cur];
		cur++;
		destcur++;
	}
	dest[destcur] = 0; // Null-terminate the result
	return (dest);
}

// Function to calculate total size of the final joined string
int	get_size_of_future_str(int size, char **strs, char *sep)
{
	int	joined_size = 0;
	int	cur = 0;
	while (cur < size)
	{
		joined_size += ft_strlen(strs[cur]);
		cur++;
	}
	joined_size += (size - 1) * ft_strlen(sep);
	return (joined_size);
}

// Main join function: concatenates all strings with separator
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		cur;
	int		joined_size;

	if (size <= 0)
	{
		joined = (char *)malloc(1);
		joined[0] = '\0';
		return (joined);
	}

	joined_size = get_size_of_future_str(size, strs, sep);
	joined = (char *)malloc(sizeof(char) * (joined_size + 1)); // +1 for null terminator

	// Initialize with null characters
	for (int i = 0; i <= joined_size; i++)
		joined[i] = '\0';

	cur = 0;
	while (cur < size)
	{
		ft_strcat(joined, strs[cur]);
		if (cur != size - 1)
			ft_strcat(joined, sep);
		cur++;
	}
	return (joined);
}

int main(void)
{
	// Allocate array of 3 string pointers
	char	**strs = (char **)malloc(sizeof(char *) * 3);

	// Assign string literals directly — no need for malloc for each string
	strs[0] = "Hello";
	strs[1] = "World";
	strs[2] = "!!";

	// Optional debug print: print each string
	for (int i = 0; i < 3; i++) {
        printf("%s\n", strs[i]);
    }

	// Join the strings with a separator
	char *result = ft_strjoin(3, strs, " - ");
	printf("\n%s\n", result);

	// We don't free anything since the task says not to use free()
	// But in real code, you should free `result` and `strs` if allocated dynamically

	return 0;
}
