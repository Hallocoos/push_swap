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

void	movecount(t_stack *stack)
{
	t_stacka *temp;
	int		i;

	temp = stack;
	while (!(temp->value > stack->value && temp->value < stack->next->value))
	{
		stack->next;
		i++;
	}
	if (i > stacksize(stacka)/2)
		i = (stacksize(stacka) - i) * 1;
	return (i);
}
