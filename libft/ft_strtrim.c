/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 11:37:31 by hde-vos           #+#    #+#             */
/*   Updated: 2019/06/10 15:57:11 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*newstr;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	if (j < 0)
		j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	if (!(newstr = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (i <= j)
		newstr[k++] = s[i++];
	newstr[k] = '\0';
	return (newstr);
}
