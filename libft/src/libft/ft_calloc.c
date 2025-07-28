/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:49:52 by didguill          #+#    #+#             */
/*   Updated: 2025/01/03 16:19:40 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_calloc - Allocates memory for an array of 'nmemb' elements,
	    each of size 'size', and initializes all bytes to zero.

@param nmemb: The number of elements to allocate.
@param size: The size of each element in bytes.

@return: A pointer to the allocated memory block.
	 NULL if memory allocation fails or if int overflow occurs
         during the size calculation.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	memory = (void *)malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, nmemb * size);
	return (memory);
}

/*
int	main(void)
{
	size_t	nmemb = 5;
	size_t	size = sizeof(int);
	int	*array;

	printf("ft_calloc...\n");
	printf("@param nmemb: %zu\n", nmemb);
	printf("@param size: %zu\n", size);

	array = (int *)ft_calloc(nmemb, size);
        printf("\nAllocated memory (initialized to zero):\n");
        for (size_t i = 0; i < nmemb; i++)
		printf("array[%zu] = %d\n", i, array[i]);
        free(array);

	return (0);
}
*/
