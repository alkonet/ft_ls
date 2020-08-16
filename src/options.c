/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:09:23 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 17:09:24 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	fills t_opts * from '-lRart1'
*/

void	fill_opts(t_opts *options, char *arg)
{
	int i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] != 'l' && arg[i] != 'R' && arg[i] != 'a' && arg[i] != 'r' \
			&& arg[i] != 't' && arg[i] != '1')
			illegal_option(arg[i]);
		if (arg[i] == 'l')
			options->l = 1;
		if (arg[i] == 'R')
			options->rec = 1;
		if (arg[i] == 'a')
			options->a = 1;
		if (arg[i] == 'r')
			options->r = 1;
		if (arg[i] == 't')
			options->t = 1;
		if (arg[i] == '1')
			options->l = 2;
		i++;
	}
	return ;
}

/*
**	mallocing a t_opts *
*/

t_opts	*init_opts(char **av)
{
	int		i;
	int		tmp;
	t_opts	*options;

	i = 0;
	options = (t_opts *)malloc(sizeof(t_opts));
	options->l = 0;
	options->rec = 0;
	options->a = 0;
	options->r = 0;
	options->t = 0;
	while (av[i] && av[i][0] == '-')
		fill_opts(options, av[i++]);
	sort_args(av);
	tmp = i;
	while (av[i])
	{
		if (valid_arg(av[i]) == 0)
			no_such_file(av[i]);
		i++;
	}
	return (options);
}

/*
**	printing a t_file ** with -l
*/

int		option_l(t_file **dir, t_info info, t_opts *opts, t_pad *pad)
{
	int i;

	i = -1;
	if (dir == NULL)
		return (1);
	not_permitted(dir, info);
	if (info.size > 2 && info.type != 1)
		print_blocks(dir, info.size, opts);
	while (++i < info.size)
	{
		if (!(opts->a == 0 && dir[i]->name[0] == '.'))
			if (dir[i]->error != 1337)
				print_l(dir[i], info, pad);
	}
	if (opts->rec)
		option_rec(dir, info, opts);
	return (0);
}

/*
**	prints standrt ls function with no options or -1
*/

void	no_opts(t_file **dir, t_info info, t_opts *options)
{
	int i;

	i = -1;
	if (dir == NULL)
		return ;
	not_permitted(dir, info);
	while (++i < info.size)
		if (!(options->a == 0 && dir[i]->name[0] == '.'))
		{
			if (dir[i]->error == EACCES && info.type == 1)
				perm_denied(dir[i]->name, info);
			else if (dir[i]->error != EPERM)
				ft_putendl(dir[i]->name);
		}
	if (options->rec)
		option_rec(dir, info, options);
}

/*
**	handles the -R listing all recursively
*/

void	option_rec(t_file **dir, t_info info, t_opts *options)
{
	int		i;
	char	*path;
	char	*tmp;

	i = -1;
	while (++i < info.size)
	{
		path = ft_strjoin(dir[0]->path, dir[i]->name);
		tmp = valid_path(path);
		if (!(options->a == 0 && dir[i]->name[0] == '.'))
		{
			if (ft_strcmp(dir[i]->name, "./") > 0 && dir[i]->perms[0] == 'd')
			{
				ft_putchar('\n');
				ft_putstr(path);
				ft_putstr(":\n");
				if (dir[i]->error != EACCES)
					ls(tmp, options);
				else
					perm_denied(dir[i]->name, info);
			}
		}
		ft_strdel(&path);
		ft_strdel(&tmp);
	}
}
