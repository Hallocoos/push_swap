/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 12:02:03 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:52:16 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *s;

	if (size <= INTMAX)
	{
		if (!(s = (void *)malloc(size)))
			return (0);
		else
		{
			bzero(s, size);
			return (s);
		}
	}
	else
		return (0);
}
