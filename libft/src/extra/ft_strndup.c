/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:22:08 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 16:27:56 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strndup - Allocates and returns a new string that is a duplicate of
	     the string 'str', but with a maximum length of 'max_len'.

@param str: A pointer to the string to be duplicated.
@param max_len: The maximum number of characters to copy from 'str'.

@return: A pointer to the newly allocated string that contains a copy of 'str'
         up to 'max_len' characters. NULL if memory allocation fails or if
         'str' is NULL. The result is always null-terminated.
*/

#include "libft.h"

char	*ft_strndup(const char *str, size_t max_len)
{
	char	*dup;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (max_len < len)
		len = max_len;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, len + 1);
	return (dup);
}
