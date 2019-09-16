/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:34:57 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/16 11:54:58 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	movecounta(t_stack *stacka, t_stack *stackb)
{
	int		len;
	int		i;
	t_stack	*temp;
	t_stack *tempb;

	temp = stacka;
	tempb = stackb;
	len = stacksize(&temp);
	i = 0;
	while (temp)
	{
		if (i < len/2)
			temp->movecounta = i++;
		else
			temp->movecounta = i-- * -1;
		temp = temp->next;
	}
}
