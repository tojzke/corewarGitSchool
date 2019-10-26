/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:18:49 by lcutjack          #+#    #+#             */
/*   Updated: 2019/05/27 15:26:00 by lcutjack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*i;
	char	*j;

	i = s1;
	j = (char*)s2;
	while (*i)
		i++;
	while (*j)
		*(i++) = *(j++);
	*i = '\0';
	return (s1);
}