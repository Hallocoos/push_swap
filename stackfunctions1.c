/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:32:20 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/09 15:52:04 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_sa(t_stack **stacka, int i)
{
	t_stack *first;
	t_stack *second;

	if (!(*stacka))
		return ;
	first = (*stacka);
	second = (*stacka)->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*stacka = second;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stackb, int i)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!(*stackb) || (stacksize(*stackb) < 2))
		return ;
	first = (*stackb);
	second = (*stackb)->next;
	third = second->next;
	first->next = second->next;
	first->prev = second;
	third->prev = first;
	second->prev = NULL;
	second->next = first;
	*stackb = second;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stacka, t_stack **stackb, int i)
{
	if (stacka && stackb)
	{
		ft_sa(stacka, 0);
		ft_sb(stackb, 0);
	}
	if (i == 1)
		write(1, "ss\n", 3);
}

void	ft_pa(t_stack **stacka, t_stack **stackb, int i)
{
	t_stack	*temp;

	if (!*stackb)
		return ;
	if (stackb != NULL)
	{
		temp = *stackb;
		if ((*stackb)->next)
			*stackb = (*stackb)->next;
		else
			*stackb = NULL;
		if (*stackb)
			(*stackb)->prev = NULL;
		if (stacka == NULL)
			add_head(stacka, temp);
		else if (stacka != NULL)
			add_head(stacka, temp);
	}
	if (i == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stacka, t_stack **stackb, int i)
{
	t_stack *temp;

	(*stacka)->move_count = 0;
	if (!*stacka)
		return ;
	if (stacka != NULL)
	{
		temp = *stacka;
		if ((*stacka)->next)
			*stacka = (*stacka)->next;
		else
			*stacka = NULL;
		if (*stacka)
			(*stacka)->prev = NULL;
		if (stackb == NULL)
			add_head(stackb, temp);
		else if (stackb != NULL)
			add_head(stackb, temp);
	}
	if (i == 1)
		write(1, "pb\n", 3);
}
