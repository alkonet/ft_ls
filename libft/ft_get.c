/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:21:59 by gloggins          #+#    #+#             */
/*   Updated: 2020/02/18 14:22:00 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** ft_get - return NULL-terminated string with number of symbols
*/

char	*ft_get(int amount, int symbol)
{
	char	*nulles;
	char	*ret;

	if (amount < 0)
		return (ft_strnew(1));
	nulles = ft_memsetloc(amount + 1, symbol);
	ret = ft_strsub(nulles, 0, amount);
	free(nulles);
	return (ret);
}
