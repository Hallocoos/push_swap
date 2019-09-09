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

void	ft_rr(t_stack **stacka, t_stack **stackb)
{
	ft_ra(stacka, 0);
	ft_ra(stackb, 0);
	ft_putstr("rr\n");
}
