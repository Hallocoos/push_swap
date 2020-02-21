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

#include "push_swap.h"

void		stacka_move_count(t_stack *stack)
{
	int		i;
	int		stack_len;

	i = 0;
	stack_len = stacksize(stack);
	while (i + 1 <= stack_len/2)
	{
		i++;
		stack->move_count = i;
		stack = stack->next;
	}
	if (stack_len % 2 == 1)
	{
		stack->move_count = i + 1;
		stack = stack->next;
	}
	i++;
	while (i > 1)
	{
		stack->move_count = i * -1;
		stack = stack->next;
		i--;
	}	
}

void		stackb_move_count(t_stack *stack)
{
	int		i;
	int		stack_len;

	i = 0;
	stack_len = stacksize(stack);
	while (i + 1 <= stack_len/2)
	{
		stack->move_count = i;
		stack = stack->next;
		i++;
	}
	if (stack_len % 2 == 1)
	{
		stack->move_count = i;
		stack = stack->next;
	}
	i++;
	while (i > 1)
	{
		i--;
		stack->move_count = i * -1;
		stack = stack->next;
	}	
}

t_stack		*get_last_in_stack(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void		find_best_stackb_pos(t_stack *stacka, t_stack *stackb)
{
	t_stack	*stackb_curr;
	t_stack	*stackb_next;

	while (stacka)
	{
		stackb_curr = stackb;
		while (stackb_curr)
		{
			if (stackb_curr->next)
				stackb_next = stackb_curr->next;
			else
				stackb_next = stackb;
			find_min(stackb);
			find_max(stackb);
			if (stacka->weight < find_min(stackb)->weight)
			{
				if (find_min(stackb)->next)
					stacka->best_pos_weight = find_min(stackb)->next->weight;
				else
					stacka->best_pos_weight = stackb->weight;
			}
			else if (stacka->weight > find_max(stackb)->weight)
			{
				if (find_max(stackb))
					stacka->best_pos_weight = find_max(stackb)->weight;
				else
					stacka->best_pos_weight = stackb->weight;
			}
			else if (stacka->weight < stackb_curr->weight && stacka->weight > stackb_next->weight &&
			((stackb_curr->end != 1 && stackb_next->end != -1) || (stackb_curr->end != -1 && stackb_next->end != 1)))
			{
				stacka->best_pos_weight = (int)stackb_next->weight;
			}
			stackb_curr = stackb_curr->next;
		}
		stacka = stacka->next;
	}
}

int			stackb_is_sorted(t_stack *stackb)
{
	int		i;
	i = 0;

	while (stackb->next)
	{
		if (stackb->weight < stackb->next->weight)
			i++;
		if (stackb->next)
			stackb = stackb->next;
		else
			break ;
	}
	if (i > 1)
	{
		// write(1, "sort_all algo failed.\n", 22);
		return (1);
	}
	else
	{
		// write(1, "sort_all algo passed.\n", 22);
		return (0);
	}	
}

int		move_calc(t_stack *stacka, t_stack *stackb)
{
	int	stacka_move_count;
	int	stackb_move_count;

	while (stacka)
	{
		stacka_move_count = stacka->move_count;
		stackb_move_count = find_weight(stackb, stacka->best_pos_weight)->move_count;
		if (stacka_move_count < 0)
			stacka_move_count *= -1;
		if (stackb_move_count < 0)
			stackb_move_count *= -1;
		stacka->total_move_count = stacka_move_count + stackb_move_count;
		stacka = stacka->next;
	}
	return (1);
}