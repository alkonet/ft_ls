/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:10:25 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 17:22:16 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	puts number with endl
*/

void	ft_intendl(int n)
{
	ft_putnbr(n);
	ft_putchar('\n');
}

/*
**	returns the amount of characters in number
*/

int		ft_nbrlen(int nb)
{
	int ret;

	ret = 1;
	while ((nb / 10) != 0)
	{
		ret++;
		nb /= 10;
	}
	return (ret);
}

/*
**	sorts a t_file ** by ASCII order
*/

void	sort_dir(t_file **dir, int size)
{
	int		i;
	t_file	*tmp;

	i = 0;
	while (i < size - 1)
	{
		if (ft_strcmp(dir[i]->name, dir[i + 1]->name) > 0)
		{
			tmp = dir[i];
			dir[i] = dir[i + 1];
			dir[i + 1] = tmp;
			if (i > 0)
				i -= 1;
		}
		else
			i++;
	}
}

/*
**	reverses a t_file **
*/

void	reverse_dir(t_file **dir, int size)
{
	int		i;
	t_file	*tmp;

	i = 0;
	size--;
	while (i < size)
	{
		tmp = dir[i];
		dir[i] = dir[size];
		dir[size] = tmp;
		i++;
		size--;
	}
	return ;
}

/*
**	sorts a t_file ** by time of last modification
*/

void	option_t(t_file **dir, int size)
{
	int		i;
	t_file	*tmp;

	i = 0;
	while (i < size - 1)
	{
		if ((dir[i]->ts < dir[i + 1]->ts) || (dir[i]->ts == dir[i + 1]->ts &&
			dir[i]->nts < dir[i + 1]->nts))
		{
			tmp = dir[i];
			dir[i] = dir[i + 1];
			dir[i + 1] = tmp;
			if (i > 0)
				i -= 1;
		}
		else
			i++;
	}
}
