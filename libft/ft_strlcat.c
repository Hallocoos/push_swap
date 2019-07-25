/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:28:45 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:55:43 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t length;
	size_t i;

	length = 0;
	while (dst[length] != '\0' && length < dstsize)
		length++;
	i = length;
	while ((src[length - i] != '\0') && (length + 1 < dstsize))
	{
		dst[length] = src[length - i];
		length++;
	}
	if (i < dstsize)
		dst[length] = '\0';
	return (i + ft_strlen((char *)src));
}
