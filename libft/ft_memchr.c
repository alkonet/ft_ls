/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:10:58 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/05 15:47:18 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)s;
	c = (unsigned char)c;
	while (n)
	{
		if (*str == c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
