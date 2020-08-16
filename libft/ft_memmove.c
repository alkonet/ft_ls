/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:57:42 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/08 11:57:55 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char*)dest;
	s2 = (char*)src;
	if (s2 < s1)
	{
		while (n--)
			s1[n] = s2[n];
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
