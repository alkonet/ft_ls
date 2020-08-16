/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:08:26 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 17:08:30 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	freeing a t_file *
*/

void	free_file(t_file *dir)
{
	if (dir != NULL)
	{
		ft_strdel(&dir->name);
		ft_strdel(&dir->perms);
		ft_strdel(&dir->user);
		ft_strdel(&dir->group);
		ft_strdel(&dir->size);
		ft_strdel(&dir->linkpath);
		free(dir);
	}
}

/*
**	freeing a whole t_file **
*/

void	free_dir(t_file **dir, int size)
{
	int i;

	i = 0;
	if (dir != NULL)
	{
		ft_strdel(&dir[0]->path);
		while (i < size)
			free_file(dir[i++]);
		free(dir);
	}
}

/*
**  counting into dir->size size of everything in a directory
**  character special file /\ block special file
*/

char	*find_majmin(struct stat *stats)
{
	char *ret;

	if (!S_ISCHR(stats->st_mode) && !S_ISBLK(stats->st_mode))
		return (ft_itoa(stats->st_size));
	else
	{
		ret = ft_strjoin(ft_itoa(major(stats->st_rdev)), ", ");
		ret = ft_strjoin(ret, ft_itoa(minor(stats->st_rdev)));
		ret = ft_strjoin(ret, "\0");
	}
	return (ret);
}
