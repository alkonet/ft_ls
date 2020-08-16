/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:01:15 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 12:17:57 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		neg;
	int		answ;
	int		check;

	i = 0;
	neg = 1;
	answ = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg = -1;
	check = i;
	while (str[i] && ft_isdigit(str[i]))
		answ = (answ * 10) + (str[i++] - 48);
	if (i - check > 19 && neg == 1)
		return (-1);
	if (i - check > 19 && neg == -1)
		return (0);
	return (answ * neg);
}
