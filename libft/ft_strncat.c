/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:50:56 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/03 18:01:08 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *add, size_t size)
{
	size_t	i;

	i = ft_strlen(dest);
	while (*add && size--)
		dest[i++] = *add++;
	dest[i] = '\0';
	return (dest);
}
