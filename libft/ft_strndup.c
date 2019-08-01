/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:27:00 by hde-vos           #+#    #+#             */
/*   Updated: 2019/07/02 14:28:01 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = ft_strnew(n)))
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
