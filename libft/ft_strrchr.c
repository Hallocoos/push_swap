/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:33:23 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:56:55 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *ptr;
	const char *found;

	if (c == '\0')
		return (ft_strchr(s, c));
	found = NULL;
	while ((ptr = ft_strchr(s, c)) != NULL)
	{
		found = ptr;
		s = ptr + 1;
	}
	return ((char *)found);
}
