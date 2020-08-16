/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:48 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 12:41:13 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		count_space(char *str, char c)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (str[i] != '\0')
		if (str[i++] == c)
			res++;
	return (res + 1);
}

static char		*next_line(char *str, char c)
{
	int		i;
	char	*end;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if ((end = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != '\0' && str[i] != c)
		end[i] = str[i];
	end[i] = '\0';
	return (end);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**tab;
	int		a;

	i = 0;
	a = -1;
	if (!s || !(tab = malloc(sizeof(char*) * (count_space((char*)s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			tab[++a] = next_line((char*)&s[i], c);
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	tab[++a] = NULL;
	return (tab);
}
