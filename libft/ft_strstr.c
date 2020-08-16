/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:45:27 by gloggins          #+#    #+#             */
/*   Updated: 2019/04/10 14:43:54 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = (char *)haystack;
	i = 0;
	if (ft_strlen(needle) == 0)
		return (tmp);
	while (tmp[i])
	{
		j = 0;
		while (tmp[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (&tmp[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
