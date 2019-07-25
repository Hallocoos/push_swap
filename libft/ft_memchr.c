/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:03:25 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:52:28 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	x = c;
	while (i < n)
	{
		if (str[i] == x)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
