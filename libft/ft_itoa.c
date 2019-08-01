/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:35:37 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 16:04:42 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_len(n);
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	if (!(str = ft_strnew(i)))
		return (NULL);
	str = ft_convert(n, str, i);
	return (str);
}
