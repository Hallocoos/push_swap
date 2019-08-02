/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:04:21 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/02 13:37:04 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rra :reverse rotate a- shift down all elements of stackaby 1. The last element
//becomes the first one.

void	ft_rra(t_stack **stacka, int n)
{
	t_stack *first;
	t_stack *last;
	t_stack *temp;

	first = *stacka;
	last = *stacka;
	temp = first->next;
	if (first && last)
	{
		while (last->next)
			last = last->next;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		temp->next = NULL;
		*stacka = temp;
		if (n == 1)
			ft_putstr("rra\n");
	}
}

//rrb :reverse rotate b- shift down all elements of stackbby 1. The last element
//becomes the first one.

void	ft_rrb(t_stack **stackb, int n)
{
	t_stack *first;
	t_stack *last;
	t_stack *temp;

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
		temp->next = NULL;
		*stackb = temp;
		if (n == 1)
			ft_putstr("rrb\n");
	}
}

//rrr :rraandrrbat the same time.

void	ft_rrr(t_stack **stacka, t_stack **stackb)
{
	ft_rra(stacka, 0);
	ft_rrb(stackb, 0);
	ft_putstr("rrr\n");
}
