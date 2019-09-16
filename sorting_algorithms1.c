/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:59:11 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/16 11:42:19 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		//write(1, "sa", 2);
		ft_sa(stack, 1);
	}
}

void	sort_three(t_stack **stack)
{
	t_stack *one;
	t_stack *two;
	t_stack *three;

	sort_two(stack);
	one = *stack;
	two = one->next;
	three = two->next;
	if (three->value < one->value)
		ft_rra(stack, 1);
	else if (three->value > one->value && three->value < two->value)
	{
		ft_rra(stack, 1);
	//	write(1, "rra", 3);
		ft_sa(stack, 1);
	//	write(1, "sa", 2);
	}
}

void	sort_five(t_stack **stacka, t_stack **stackb)
{
	if (stacksize(stacka) == 5)
	{
		while ((*stacka)->weight != 1)
			ft_ra(stacka, 1);
		ft_pb(stacka, stackb, 1);
		set_weight(*stacka);
	}
	while ((*stacka)->weight != 1)
		ft_ra(stacka, 1);
	ft_pb(stacka, stackb, 1);
	set_weight(*stacka);

	sort_three(stacka);
	while (stacksize(stackb) != 0)
		ft_pa(stacka, stackb, 1);
	set_weight(*stacka);
}

void	sort_all(t_stack **stacka, t_stack **stackb)
{
	stacka = NULL;
	stackb = NULL;
}
