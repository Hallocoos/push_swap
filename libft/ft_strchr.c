/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:22:08 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:54:33 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen((char *)s);
	if (c == 0 || c == '\0')
		return ((char *)&s[j]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&(s[i]));
		i++;
	}
	return (NULL);
}
