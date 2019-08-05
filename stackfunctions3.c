/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:04:21 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/05 14:07:21 by hde-vos          ###   ########.fr       */
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
	temp = last->prev;
	if (first && last)
	{
		if (*stacka)
			write(1, "5", 1);
		while (last->next)
			last = last->next;
		first->prev = last;
		last->next = first;
		last->prev = NULL;
		write(1, "4", 1);
		temp->next = NULL;
		if (*stacka)
			write(1, "5", 1);
		*stacka = last;
		write(1, "6", 1);
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
	temp = first->next;
	if (first && last)
	{
		while (last->next)
			last = last->next;
		first->prev = last;
		last->next = first;
		last->prev = NULL;
		temp->next = NULL;
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
