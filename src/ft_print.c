/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:10:11 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 17:10:12 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	prints one line/file from t_file * (-l)
*/

void	print_l(t_file *dir, t_info info, t_pad *pad)
{
	if (dir->error == EACCES && info.type == 1)
		perm_denied(dir->name, info);
	else if (dir->error == EPERM)
		return ;
	else
	{
		ft_putstr(dir->perms);
		print_spaces(pad->links - ft_nbrlen(dir->links) + 1);
		ft_putnbr(dir->links);
		print_spaces(pad->user - ft_strlen(dir->user));
		ft_putstr(dir->user);
		print_spaces(pad->group - ft_strlen(dir->group) + 1);
		ft_putstr(dir->group);
		print_spaces(pad->size - ft_strlen(dir->size) + 1);
		ft_putstr(dir->size);
		print_spaces(0);
		print_timestamp(dir->ts);
		print_spaces(0);
		ft_putstr(dir->name);
		if (dir->linkpath != NULL)
			print_link(dir->linkpath);
		ft_putchar('\n');
	}
}

/*
**	prints "file:"
*/

void	two_points(char *file)
{
	ft_putstr(file);
	ft_putstr(":\n");
}

/*
**	printing timestamp from a file in case of -l
*/

void	print_timestamp(long ts)
{
	char *ret;

	if ((ret = ctime(&ts)) == NULL)
		return ;
	ret[16] = '\0';
	ft_putstr(ret + 4);
}

/*
**	prints number of spaces
*/

void	print_spaces(int nb)
{
	int i;

	i = -1;
	while (++i <= nb)
		ft_putchar(' ');
}

/*
**	prints -> path of the link
*/

void	print_link(char *linkpath)
{
	ft_putstr(" -> ");
	ft_putstr(linkpath);
}
