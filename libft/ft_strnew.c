/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:00:36 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:56:46 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if (size <= INTMAX)
	{
		if (!(s = (char *)malloc(size + 1)))
			return (0);
		else
		{
			bzero(s, size + 1);
			return (s);
		}
	}
	else
		return (0);
}
