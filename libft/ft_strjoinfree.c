/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:11 by gloggins          #+#    #+#             */
/*   Updated: 2020/02/18 14:14:13 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** ft_strjoinfree - works like ft_strjoin, but free one
** of the input str in the end
**
** to_free param works that way:
** 0: free nothing
** 1-: free only s1
** 2: free both
** 3+: free only s2
*/

char	*ft_strjoinfree(char *s1, char *s2, t_llong amount, char to_free)
{
	char	*new;

	if (!amount || (!*s1 && !*s2))
	{
		new = ft_strdup(s1);
		if (to_free && to_free < 3)
			free(s1);
		if (to_free && to_free > 1)
			free(s2);
		return (new);
	}
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (amount != -1)
		ft_strncat(ft_strcat(new, s1), s2, amount);
	else
		ft_strcat(ft_strcat(new, s1), s2);
	if (to_free && to_free < 3)
		free(s1);
	if (to_free && to_free > 1)
		free(s2);
	return (new);
}
