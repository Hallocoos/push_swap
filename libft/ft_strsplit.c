/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:07:38 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:56:59 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**arraywords;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	if (!(arraywords = (char **)malloc(sizeof(*arraywords)
					* (ft_wordcount(s, c, 0) + 1))))
		return (NULL);
	while (i < ft_wordcount(s, c, 0))
	{
		j = 0;
		while (s[k] == c)
			k++;
		arraywords[i] = ft_strnew(ft_wordlen(s, c, k));
		while (s[k] != c && s[k])
			arraywords[i][j++] = (char)s[k++];
		i++;
	}
	arraywords[i] = 0;
	return (arraywords);
}
