/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:28:54 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/05 13:45:08 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ra :rotate a- shift up all elements of stackaby 1. The first element becomesthe 
//last one.

void	ft_ra(t_stack **stacka, int n)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*temp;

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
		temp->prev = NULL;
		*stacka = temp;
		if (n == 1)
			ft_putstr("ra\n");
	}
}

//rb :rotate b- shift up all elements of stackbby 1. The first element
//becomes the last one.

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
			ft_putstr("rb\n");
	}
}

//rr :ra and rb at the same time.

void	ft_rr(t_stack **stacka, t_stack **stackb)
{
	ft_ra(stacka, 0);
	ft_ra(stackb, 0);
	ft_putstr("rr\n");
}
