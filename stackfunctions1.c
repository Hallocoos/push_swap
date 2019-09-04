/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:32:20 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/04 14:20:48 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//void	ft_sa(t_stack **stack, int n)
//{
//	t_stack	*first;
//	t_stack *second;
//	
//	if (*stack && stacksize(stack) > 1)
//	{	
//		first = *stack;
//		second = (*stack)->next;
//		first->prev = second;
//		first->next = second->next;
//		second->prev = NULL;
//		second->next = first;
//		*stack = second;
//		if (n == 1)
//			ft_putstr("sa\n");
//	}
//}

void	ft_sa(t_stack **stacka, int i)
{
	t_stack *first;
	t_stack *second;

	if (!(*stacka) || (stack_size(stacka) < 2))
		return ;
	first = (*stacka);
	second = (*stacka)->next;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*stacka = second;
	if (i == 1 || i == 4 || i == 5 || i == 7)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack, int n)
{
	t_stack	*first;
	t_stack *second;
	
	if (*stack && stacksize(stack) > 1)
	{	
		first = *stack;
		second = (*stack)->next;
		first->prev = second;
		first->next = second->next;
		second->prev = NULL;
		second->next = first;
		*stack = second;
		if (n == 1)
			ft_putstr("sb\n");
	}
}

void	ft_ss(t_stack **stacka, t_stack **stackb)
{
	ft_sa(stacka, 0);
	ft_sb(stackb, 0);
	ft_putstr("ss\n");
}

void	ft_pa(t_stack **stacka, t_stack **stackb, int n)
{
	t_stack	*tempa;
	t_stack	*tempb;

	tempa = *stacka;
	tempb = (*stackb)->next;
	if (tempa && tempb)
	{
		tempa->prev = *stackb;
		(*stackb)->next = tempa;
		(*stackb)->prev = NULL;
		tempb->prev = NULL;
		*stacka = *stackb;
		*stackb = tempb;
		if (n == 1)
			ft_putstr("pa\n");
	}
}

void	ft_pb(t_stack **stacka, t_stack **stackb, int n)
{
	t_stack	*tempb;
	t_stack	*tempa;

	tempb = *stackb;
	tempa = (*stacka)->next;
	{
		tempb->prev = *stacka;
		(*stacka)->next = tempb;
		(*stacka)->prev = NULL;
		tempa->prev = NULL;
		*stackb = *stacka;
		*stacka = tempa;
		if (n == 1)
			ft_putstr("pb\n");
	}
}
