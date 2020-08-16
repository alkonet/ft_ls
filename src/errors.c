/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:07:50 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 17:07:51 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	returning 2 if arg is a directory
**	returning 1 if arg is a file
**	returning 0 if arg cannot be accessed or doesnt exist
*/

int		valid_arg(char *arg)
{
	DIR			*dir;
	struct stat	*stats;
	int			ret;

	stats = NULL;
	ret = 0;
	if ((dir = opendir(arg)) != NULL)
	{
		(void)closedir(dir);
		return (2);
	}
	if ((stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		ret = 0;
	ret = (lstat(arg, stats) == -1) ? 0 : 1;
	free(stats);
	return (ret);
}

/*
**	printing EACCES permission error
*/

void	perm_denied(char *file, t_info info)
{
	if (info.size > 1)
		ft_putchar('\n');
	ft_putstr_fd("./ft_ls: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
}

/*
**	printing EAPERM permission error
*/

void	not_permitted(t_file **dir, t_info info)
{
	int i;

	i = -1;
	while (++i < info.size)
		if (dir[i]->error == EPERM)
		{
			ft_putstr_fd("./ft_ls: ", STDERR_FILENO);
			ft_putstr_fd(dir[i]->name, STDERR_FILENO);
			ft_putstr_fd(": Operation not permitted\n", STDERR_FILENO);
		}
}

/*
**	printing usage in case of invalid options
*/

void	illegal_option(char option)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(option, STDERR_FILENO);
	ft_putstr_fd("\nusage: ./ft_ls [-lartR] [file ...]\n", STDERR_FILENO);
	exit(1);
}

/*
**	printing missing file error
*/

void	no_such_file(char *file)
{
	ft_putstr_fd("ls: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
}
