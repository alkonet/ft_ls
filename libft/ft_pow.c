/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:17:35 by gloggins          #+#    #+#             */
/*   Updated: 2020/02/18 14:17:37 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** ft_pow - raise number to a power, for decimal nums
** ft_pow_dbl - raise number to a power, for power < 0 or double nums
*/

t_llong		ft_pow(t_llong to_raise, short power)
{
	if (power == 0)
		return (1);
	if (power > 0)
		return (to_raise * ft_pow(to_raise, --power));
	else
		return (ft_pow(to_raise, ++power) / to_raise);
}

long double	ft_pow_dbl(long double to_raise, short power)
{
	if (power == 0)
		return (1l);
	else if (power > 0)
		return (to_raise * ft_pow_dbl(to_raise, --power));
	else
		return (ft_pow_dbl(to_raise, ++power) / to_raise);
}
