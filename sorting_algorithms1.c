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
	{
		// write(1, "sa", 2);
		ft_sa(stack, 0);
	}
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

void sort_all(t_stack **stacka, t_stack **stackb)
{
		ft_putstr("STACKA INDEX: ");
	ft_pb(stacka, stackb, 0);
	ft_pb(stacka, stackb, 0);
	ft_pb(stacka, stackb, 0);
	stacka_move_count(*stacka);
	stackb_move_count(*stackb);

	while (*stackb != find_max(*stackb))
		ft_rb(stackb, 0);

	while (*stacka)
	{
		find_best_stackb_pos(*stacka, *stackb);
		while ((*stackb)->weight != (*stacka)->best_pos_weight)
			ft_rb(stackb, 0);
		ft_pb(stacka, stackb, 0);
	}

	while (*stackb != find_max(*stackb))
		ft_rb(stackb, 0);

	stacka_move_count(*stacka);
	stackb_move_count(*stackb);
}
