/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:09:48 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/03 17:09:49 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	malloc a t_pad *
*/

t_pad	*init_pad(void)
{
	t_pad *padding;

	padding = malloc(sizeof(t_pad));
	padding->directory_number = 0;
	padding->perms = 0;
	padding->links = 0;
	padding->user = 0;
	padding->group = 0;
	padding->size = 0;
	padding->timestamp = 0;
	padding->name = 0;
	return (padding);
}

/*
**	fills t_pad * with max width of each field of a t_file **
*/

t_pad	*fill_pad(t_pad *padding, t_file **dir, int filesize)
{
	int i;
	int links;
	int user;
	int group;
	int size;

	i = 0;
	if (dir == NULL)
		return (NULL);
	while (i < filesize)
	{
		links = ft_nbrlen(dir[i]->links);
		user = ft_strlen(dir[i]->user);
		group = ft_strlen(dir[i]->group);
		size = ft_strlen(dir[i]->size);
		padding->links = replace_if(links, padding->links);
		padding->user = replace_if(user, padding->user);
		padding->group = replace_if(group, padding->group);
		padding->size = replace_if(size, padding->size);
		i++;
	}
	return (padding);
}

/*
**	returns value depending of which one is higher
*/

int		replace_if(int value1, int value2)
{
	return (value1 > value2) ? value1 : value2;
}
