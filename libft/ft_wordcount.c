/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:42:02 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 16:38:56 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *str, char delim, int index)
{
	int		count;

	if (!(str[index]))
		return (0);
	count = 0;
	while (str[index] == delim)
		index++;
	while (str[index] != '\0' && str[index] != delim)
	{
		index++;
		count = 1;
	}
	return (count + ft_wordcount(str, delim, index));
}
