/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:21:46 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 23:16:45 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_split - Splits the string 's' into words separated by the delimiter char 'c'.

@param s: The string to split.
@param c: The delimiter character used to separate words.

@return: - A pointer to an array of strings (words). 
	 The array is null-terminated.
         - NULL if memory allocation fails or if the string is NULL.
*/

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	word_count;
	int	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			word_count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word_count);
}

static int	allocate_word(char **words_buffer, int word_i, size_t word_length)
{
	int	i;

	i = 0;
	words_buffer[word_i] = (char *)malloc((word_length + 1) * sizeof(char));
	if (!words_buffer[word_i])
	{
		while (i < word_i)
			free(words_buffer[i++]);
		free(words_buffer);
		return (1);
	}
	words_buffer[word_i][word_length] = '\0';
	return (0);
}

static void	fill_word(char *words_buff, char const *s, int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		words_buff[i] = s[start + i];
		i++;
	}
}

static int	fill_buffer(char **words_buffer, char const *s, char delimiter)
{
	int		word_count;
	int		i;
	size_t	word_len;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		word_len = 0;
		while (s[i] && s[i] == delimiter)
			i++;
		while (s[i] && s[i] != delimiter)
		{
			word_len++;
			i++;
		}
		if (word_len)
		{
			if (allocate_word(words_buffer, word_count, word_len))
				return (1);
			fill_word(words_buffer[word_count], s, i - word_len, word_len);
			word_count++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**words_buffer;
	size_t	num_words;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	words_buffer = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!words_buffer)
		return (NULL);
	words_buffer[num_words] = NULL;
	if (fill_buffer(words_buffer, s, c))
		return (NULL);
	return (words_buffer);
}

/*
int	main(void)
{
	const char	*str = "  Hello  world   how   are  you ";
	char		**result;
	int 		i;

	printf("ft_split...\n");
	printf("@param str: \"%s\"\n", str);
	printf("@param delimiter: ' '\n");

	result = ft_split(str, ' ');
	printf("\n@return:\n");
	i = 0; 
	while (result[i])
	{
	printf("Word %d: \"%s\"\n", i + 1, result[i]);
	free(result[i]);
	i++;
	}
	free(result);

	return (0);
}
*/
