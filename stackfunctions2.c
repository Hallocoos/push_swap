/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:28:54 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/09 12:51:40 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack_a, int i)
{
	t_stack	*first;
	t_stack	*last;

	if ((!*stack_a) || (stacksize(*stack_a) < 2))
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
	first->prev = last;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stackb, int n)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

	first = *stackb;
	last = *stackb;
	temp = first->next;
	if (first && last)
	{
		while (last->next)
			last = last->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		temp->prev = NULL;
		*stackb = temp;
		if (n == 1)
			write(1, "rb\n", 3);
	}
}

void	ft_rr(t_stack **stacka, t_stack **stackb, int i)
{
	ft_ra(stacka, 0);
	ft_ra(stackb, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
