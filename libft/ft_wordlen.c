/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:42:43 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:57:50 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordlen(char const *s, char c, int k)
{
	int		i;

	i = 0;
	while (s[k] != c && s[k] != '\0')
	{
		i++;
		k++;
	}
	return (i);
}
