/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:09:55 by hde-vos           #+#    #+#             */
/*   Updated: 2019/07/02 13:32:29 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void *string;

	string = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	else
		ft_memcpy(string, s1, ft_strlen(s1) + 1);
	return (string);
}
