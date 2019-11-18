/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:06:51 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:27:02 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*w;
	unsigned char	sym;

	sym = (unsigned char)c;
	w = (unsigned char*)s;
	while (n-- > 0)
	{
		if (*w == sym)
			return ((void*)w);
		w++;
	}
	return (NULL);
}
