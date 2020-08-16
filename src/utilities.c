/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:11:10 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 17:11:12 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	returns the number of files in the specified directory
*/

int		ft_dirlen(char *name, char *path)
{
	int				ret;
	DIR				*dir;
	struct dirent	*files;
	char			*tmp;

	ret = 0;
	tmp = ft_strdup(path);
	path = ft_strjoin(tmp, name);
	ft_strdel(&tmp);
	if ((dir = opendir(path)) == NULL)
		ret = 1;
	else
		while ((files = readdir(dir)) != NULL)
			ret++;
	(void)closedir(dir);
	ft_strdel(&path);
	return (ret);
}

/*
**	prints the 'total nb\n' in -l with the total number
**  of blocks in a directory
*/

void	print_blocks(t_file **dir, int size, t_opts *options)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (i < size)
	{
		if (!(options->a == 0 && dir[i]->name[0] == '.'))
			ret += dir[i]->blocks;
		i++;
	}
	ft_putstr("total ");
	ft_intendl(ret);
}

/*
**	returns the last modification
**	if there is no valid file - returns 0
*/

long	get_timestamp(char *dir)
{
	struct stat	*stats;
	int			ret;

	ret = 0;
	stats = malloc(sizeof(struct stat));
	ret = lstat(dir, stats) == -1 ? -1 : stats->st_mtime;
	free(stats);
	return (ret);
}

/*
**	returns the number of files before the next dir
**  in **av or 0 if there is no remaining ones
*/

int		next_dir_offset(char **av)
{
	int ret;

	ret = 1;
	while (av[ret] && valid_arg(av[ret]) != 2)
		ret++;
	return (valid_arg(av[ret]) == 2) ? ret : 0;
}

/*
**	adds a '/' to a path if there is no one
*/

char	*valid_path(char *path)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!path)
		return (NULL);
	if (ft_strcmp(path, ".") == 0)
		return (ft_strdup("./"));
	while (path[i])
		i++;
	if (i == 1 || path[i] == '/')
		return (path);
	else
	{
		tmp = ft_strdup(path);
		path = ft_strjoin(tmp, "/");
		ft_strdel(&tmp);
		return (path);
	}
}
