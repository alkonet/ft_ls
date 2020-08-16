/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:09:21 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 11:49:47 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]) && s[i])
		i++;
	while (ft_isspace(s[j]) && j > 0)
		j--;
	if (j >= i)
		return (ft_strsub(s, i, j - i + 1));
	return (ft_strdup(""));
}
