/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:13:14 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/05/23 12:35:06 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nmemb_mem;
	size_t	max_size;

	max_size = nmemb * size;
	if (size != 0 && nmemb != (max_size / size))
		return (NULL);
	nmemb_mem = malloc(nmemb * size);
	if (!nmemb_mem)
		return (NULL);
	ft_bzero(nmemb_mem, nmemb * size);
	return (nmemb_mem);
}
