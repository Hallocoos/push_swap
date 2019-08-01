/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 10:08:07 by hde-vos           #+#    #+#             */
/*   Updated: 2019/07/01 12:23:21 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(needle) == 0 || needle == 0)
		return ((char *)haystack + i);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if ((needle[j + 1] == '\0')
				|| ((haystack[i + j + 1] == '\0')
				&& (haystack[i + j + 1] == ' ')))
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
