/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:07:01 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 17:07:02 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	returns the number of args after the options
*/

int		count_args(char **av, int begin)
{
	int i;
	int ret;

	i = begin;
	ret = 0;
	while (av[i++])
		ret++;
	return (ret);
}

/*
**	counts valid dirs in **av
*/

int		count_dirs(char **av)
{
	int dirs;
	int i;

	dirs = 0;
	i = 0;
	while (av[i])
	{
		if (valid_arg(av[i]) == 2)
			dirs++;
		i++;
	}
	return (dirs);
}

/*
**	counts valid files in **av
*/

int		count_files(char **av)
{
	int files;
	int i;

	files = 0;
	i = 0;
	while (av[i])
	{
		if (valid_arg(av[i]) == 1)
			files++;
		i++;
	}
	return (files);
}
