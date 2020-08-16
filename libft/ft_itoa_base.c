/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:21:35 by gloggins          #+#    #+#             */
/*   Updated: 2020/02/06 15:21:36 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_ullong	ft_nmult_base(t_ullong to_count, short base)
{
	size_t	mult;

	mult = 1;
	while (to_count /= base)
		mult *= base;
	return (mult);
}

short		ft_nsize_base(t_ullong n, short base)
{
	short	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

int			ft_isupper(int chr)
{
	return ((chr >= 65 && chr <= 90) ? 1 : 0);
}

static char	overbase(t_ushort n, char letter)
{
	if (n < 10)
		return (n + '0');
	else
		return (ft_isupper(letter) ? n + 55 : n + 87);
}

char		*ft_itoa_base(t_ullong num, unsigned short base, char letter)
{
	size_t		i;
	t_ullong	mult;
	char		*ret;

	i = 0;
	if (!base)
		base = 10;
	ret = ft_strnew(ft_nsize_base(num, base));
	if (!num)
	{
		ret[0] = '0';
		return (ret);
	}
	mult = ft_nmult_base(num, base);
	while (mult)
	{
		ret[i++] = overbase(num / mult, letter);
		num -= (num / mult) * mult;
		mult /= base;
	}
	ret[i] = '\0';
	return (ret);
}
