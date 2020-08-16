/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsetloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:23:22 by gloggins          #+#    #+#             */
/*   Updated: 2020/02/18 14:23:25 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** ft_memsetloc - malloc (size) of memory and fills it with (val)
*/

void	*ft_memsetloc(size_t size, int val)
{
	void	*ret;

	if (!(ret = malloc(size)))
		return (NULL);
	ft_memset(ret, val, size);
	return (ret);
}
