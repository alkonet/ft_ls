/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:19:36 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/07 11:21:13 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	ft_bzero(*as, ft_strlen(*as));
	free(*as);
	*as = NULL;
}
