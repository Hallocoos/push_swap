/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:07:06 by hde-vos           #+#    #+#             */
/*   Updated: 2020/02/28 11:13:53 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted_desc(t_stack *stackb)
{
	if (stackb->end == 1 && stackb->next->end == 0 && stackb->next->next->end == -1)
		return (0);
	return (1);
}


void stackb_sort_two(t_stack **stack)
{
	if ((*stack)->weight > (*stack)->next->weight)
		ft_sb(stack, 1);
}

void sort_three_desc(t_stack **stack)
{
	if ((*stack)->end == -1 && (*stack)->next->end == 1 && (*stack)->next->next->end == 0)
		ft_rb(stack, 1);
	else {
		stackb_sort_two(stack);
		if ((*stack)->end == -1)
			ft_rrb(stack, 1);
		else if ((*stack)->end == 1 && (*stack)->next->end == -1 && (*stack)->next->next->end == 0)
		{
			ft_rrb(stack, 1);
			ft_sb(stack, 1);
		}
		else if ((*stack)->end == 0 && (*stack)->next->end == -1 && (*stack)->next->next->end == 1)
		{
			ft_rb(stack, 1);
			ft_sb(stack, 1);
		}
	}
}

int	checker(t_stack **stack)
{
	t_stack *temp;
	t_stack *tempnext;

	temp = *stack;
	tempnext = (*stack)->next;
	if (temp && temp->next)
	{
		while (tempnext)
		{
			if (tempnext->value < temp->value)
				return (0);
			temp = tempnext;
			tempnext = tempnext->next;
		}
	}
	free(tempnext);
	return (1);
}

t_stack	*find_smallest_move_count(t_stack *stacka)
{
	t_stack	*smallest_move_count;

	smallest_move_count = stacka;
	while (stacka)
	{
		if (stacka->total_move_count < smallest_move_count->total_move_count)
			smallest_move_count = stacka;
		stacka = stacka->next;
	}
	return (smallest_move_count);
}