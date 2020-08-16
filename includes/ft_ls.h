/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:40:47 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 12:40:49 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <sys/stat.h>
# include <stdio.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <dirent.h>
# include "../libft/includes/libft.h"

/*
**	structure for storing options
*/

typedef struct		s_options
{
	int				l;
	int				rec;
	int				a;
	int				r;
	int				t;
}					t_opts;

/*
**	structure for storing the width
**	of the fields in '-l'
*/

typedef struct		s_padding
{
	int				directory_number;
	int				perms;
	int				links;
	int				user;
	int				group;
	int				size;
	int				timestamp;
	int				name;
}					t_pad;

/*
**	structure for storing all the fields of a directory or a file
**  path - path to the file
**  name - name of the file
**  perms - contains permissions for file
**  links - the number of links to the file
**  linkpath - if the link it is - holds the linkpath
**  user - current user
**  group - if the user is in a group
**  size - size of a file or all files in a directory
**  ts - the time of the file (timestamp)
**  In database version 10gR1 and above, the TIMESTAMP# column
**  is obsoleted in favor of the new NTIMESTAMP# column.
**  blocks - total amount of blocks used in a system file
**  errors - if there are errors like perm denied or oper denied
*/

typedef struct		s_file
{
	char			*path;
	char			*name;
	char			*perms;
	int				links;
	char			*linkpath;
	char			*user;
	char			*group;
	char			*size;
	long			ts;
	long			nts;
	long			blocks;
	int				error;
}					t_file;

/*
**	structure to save size and type in single file
*/

typedef struct		s_info
{
	int				size;
	int				type;
}					t_info;

typedef struct stat	t_stats;

/*
**  Arguments.c
*/

void				sort_args(char **av);
void				reverse_args(char **av);
void				sort_by_time(char **av);
void				treat_args(char **av, t_opts *options);
void				treat_dirs(char **av, t_opts *options);

/*
**  Counter.c
*/

int					count_dirs(char **av);
int					count_files(char **av);
int					count_args(char **av, int begin);

/*
**  Direct.c
*/

t_file				**init_dir(t_file **dir, int size);
t_file				**fill_dir(t_file **d, t_info info, char *p);
t_file				**sfiles(char **av, t_info info, t_file **d);
t_file				*fill_stats(t_file *dir, char *n, char *p, t_stats *s);

/*
**  Errors.c
*/

int					valid_arg(char *arg);
void				no_such_file(char *file);
void				not_permitted(t_file **dir, t_info info);
void				perm_denied(char *file, t_info info);
void				illegal_option(char option);

/*
**  Fill.c
*/

int					replace_if(int value1, int value2);
t_pad				*init_pad(void);
t_pad				*fill_pad(t_pad *padding, t_file **dir, int size);

/*
**  Ft_ls.c
*/

int					single_files_ls(char **av, t_opts *options);
int					ls(char *name, t_opts *options);
void				opts(t_file **d, t_info info, t_opts *o, t_pad *p);

/*
**  ft_print.c
*/

void				print_l(t_file *file, t_info info, t_pad *pad);
void				print_timestamp(long timestamp);
void				two_points(char *file);
void				print_spaces(int nb);
void				print_link(char *filepath);

/*
**  Memory_free.c
*/

void				free_file(t_file *dir);
void				free_dir(t_file **dir, int size);
char				*find_majmin(struct stat *stats);

/*
**  Options.c
*/

int					option_l(t_file **d, t_info info, t_opts *o, t_pad *p);
void				fill_opts(t_opts *options, char *arg);
void				option_rec(t_file **dir, t_info info, t_opts *options);
void				no_opts(t_file **dir, t_info info, t_opts *options);
t_opts				*init_opts(char **av);

/*
**  Reader_output.c
*/

char				*find_user(struct stat *stats);
char				*find_group(struct stat *stats);
char				*find_link(char *path, char *name);
int					find_error(char *file);
char				*find_modes(struct stat *file);

/*
**  Sorting.c
*/

int					ft_nbrlen(int nb);
void				sort_dir(t_file **dir, int size);
void				reverse_dir(t_file **dir, int size);
void				option_t(t_file **dir, int size);
void				ft_intendl(int n);

/*
**  Utilities.c
*/

int					ft_dirlen(char *name, char *path);
int					next_dir_offset(char **av);
void				print_blocks(t_file **dir, int size, t_opts *options);
long				get_timestamp(char *dir);
char				*valid_path(char *path);

#endif
