/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:59:11 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/04 14:07:55 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		ft_sa(stack, 1);
}

void	sort_three(t_stack **stack)
{
	t_stack *one;
	t_stack *two;
	t_stack *three;

	one = *stack;
	sort_two(&one);
	two = one->next;
	three = two->next;
	if (three->value < one->value)
		ft_rra(stack, 1);
	else if (three->value > one->value && three->value < two->value)
	{
		ft_rra(stack, 1);
		print_stack(stack);
		ft_sa(stack, 1);
	}
}
