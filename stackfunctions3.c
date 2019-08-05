/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:04:21 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/05 14:47:43 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//rra :reverse rotate a- shift down all elements of stacka by 1. The last
//element becomes the first one.

void	ft_rra(t_stack **stacka, int n)
{
	t_stack *first;
	t_stack *last;
	t_stack *temp;

	first = *stacka;
	last = *stacka;
	if (first && last)
	{
		while (last->next)
			last = last->next;
		temp = last->prev;
		first->prev = last;
		last->next = first;
		temp->next = NULL;
		last->prev = NULL;
		*stacka = last;
		if (n == 1)
			ft_putstr("rra\n");
	}
}

//rrb :reverse rotate b- shift down all elements of stackb by 1. The last 
//element becomes the first one.

void	ft_rrb(t_stack **stackb, int n)
{
	t_stack *first;
	t_stack *last;
	t_stack *temp;

	first = *stackb;
	last = *stackb;
	if (first && last)
	{
		while (last->next)
			last = last->next;
		temp = last->prev;
		first->prev = last;
		last->next = first;
		temp->next = NULL;
		last->prev = NULL;
		*stackb = last;
		if (n == 1)
			ft_putstr("rrb\n");
	}
}

//rrr :rra and rrb at the same time.

void	ft_rrr(t_stack **stacka, t_stack **stackb)
{
	ft_rra(stacka, 0);
	ft_rrb(stackb, 0);
	ft_putstr("rrr\n");
}
