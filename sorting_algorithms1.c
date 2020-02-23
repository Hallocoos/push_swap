/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:59:11 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/19 14:11:53 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_stack **stack)
{
	if ((*stack)->weight > (*stack)->next->weight)
		ft_sa(stack, 0);
}

void sort_three(t_stack **stack)
{
	if ((*stack)->weight == 3 && (*stack)->next->weight == 1 && (*stack)->next->next->weight == 2)
		ft_ra(stack, 0);
	sort_two(stack);
	if ((*stack)->next->next->weight == 1)
		ft_rra(stack, 0);
	else if ((*stack)->weight == 1 && (*stack)->next->weight == 3 && (*stack)->next->next->weight == 2)
	{
		ft_rra(stack, 0);
		ft_sa(stack, 0);
	}
	else if ((*stack)->weight == 3 && (*stack)->next->weight == 2 && (*stack)->next->next->weight == 1)
	{
		ft_ra(stack, 0);
		ft_sa(stack, 0);
	}
}

void sort_five(t_stack **stacka, t_stack **stackb)
{
	if (stacksize(*stacka) == 5)
	{
		while ((*stacka)->weight != 1)
			ft_ra(stacka, 0);
		ft_pb(stacka, stackb, 0);
		set_weight(*stacka);
	}
	while ((*stacka)->weight != 1)
		ft_ra(stacka, 0); 
	ft_pb(stacka, stackb, 0);
	set_weight(*stacka);

	sort_three(stacka);
	while (stacksize(*stackb) != 0)
		ft_pa(stacka, stackb, 0);
	set_weight(*stacka);
}


void sort_three_desc(t_stack **stack)
{
	if ((*stack)->end == -1 && (*stack)->next->end == 1 && (*stack)->next->next->end == 0)
		ft_ra(stack, 0);
	else {
		sort_two(stack);
		if ((*stack)->end == -1)
			ft_rra(stack, 0);
		else if ((*stack)->end == 1 && (*stack)->next->end == -1 && (*stack)->next->next->end == 0)
		{
			ft_rra(stack, 0);
			ft_sa(stack, 0);
		}
		else if ((*stack)->end == 0 && (*stack)->next->end == -1 && (*stack)->next->next->end == 1)
		{
			ft_ra(stack, 0);
			ft_sa(stack, 0);
		}
	}
}

int		is_sorted_desc(t_stack *stackb)
{
	if (stackb->end == 1 && stackb->next->end == 0 && stackb->next->next->end == -1)
		return (0);
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

void sort_all(t_stack **stacka, t_stack **stackb)
{
	// START ==================================================
	ft_pb(stacka, stackb, 0);
	ft_pb(stacka, stackb, 0);
	ft_pb(stacka, stackb, 0);

	while (*stackb != find_max(*stackb))
		ft_rb(stackb, 0);
	find_min(*stackb);

	if (is_sorted_desc(*stackb))
		sort_three_desc(stackb);
	// START ==================================================

	// MIDDLE ==================================================
	t_stack	*smallest_move_count;
	// t_stack	*weight;
	// stacka_move_count(*stacka);
	// stackb_move_count(*stackb);
	// find_best_stackb_pos(*stacka, *stackb);
	// move_calc(*stacka, *stackb);
	// print_stack(stacka);
	// print_stack(stackb);

	while (*stacka)
	{
		stacka_move_count(*stacka);
		stackb_move_count(*stackb);
		find_best_stackb_pos(*stacka, *stackb);
		move_calc(*stacka, *stackb);
		print_stack(stacka);
		print_stack(stackb);
		smallest_move_count = find_smallest_move_count(*stacka);
		// weight = find_weight(*stackb, (*stacka)->best_pos_weight);
		while ((*stacka)->weight != smallest_move_count->weight)
		{
			// smallest_move_count = find_smallest_move_count(*stacka);
			// weight = find_weight(*stackb, (*stacka)->best_pos_weight);
			// if (smallest_move_count->move_count > 0)
				ft_ra(stacka, 0);
			// else if (smallest_move_count->move_count < 0 && weight->move_count < 0)
				// ft_rrr(stacka, stackb, 0);
			// else if (smallest_move_count->move_count < 0)
				// ft_rra(stacka, 0);
		}
		// smallest_move_count = find_smallest_move_count(*stacka);
		// weight = find_weight(*stackb, (*stacka)->best_pos_weight);
		while ((*stackb)->weight != (*stacka)->best_pos_weight)
		{
			// smallest_move_count = find_smallest_move_count(*stacka);
			// weight = find_weight(*stackb, (*stacka)->best_pos_weight);
			// if (weight->move_count > 0)
				ft_rb(stackb, 0);
			// else if (smallest_move_count->move_count < 0 && weight->move_count < 0)
				// ft_rrr(stacka, stackb, 0);
			// else if (weight->move_count < 0)
				// ft_rrb(stackb, 0);
		}
		ft_pb(stacka, stackb, 0);
	}
	// MIDDLE ==================================================

	// END =====================================================
	while (*stackb != find_max(*stackb))
		ft_rb(stackb, 0);

	// stacka_move_count(*stacka);
	// stackb_move_count(*stackb);

	while (*stackb)
		ft_pa(stacka, stackb, 0);
	// END =====================================================
}