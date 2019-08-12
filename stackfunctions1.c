/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:32:20 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/12 12:00:48 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if
//there is only one or no elements).

void	ft_sa(t_stack **head, int n)
{
	t_stack	*first;
	t_stack *second;
	t_stack *third;
	
	first = *head;
	second = (*head)->next;
	if (first && second)
	{	
		third = second->next;
		first->next = third;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		*head = second;
		if (n == 1)
			ft_putstr("sa\n");
	}
}

//sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if
//there is only one or no elements).

void	ft_sb(t_stack **head, int n)
{
	t_stack	*first;
	t_stack *second;
	t_stack *third;
	
	first = *head;
	second = (*head)->next;
	if (first && second)
	{	
		third = second->next;
		first->next = third;
		first->prev = second;
		second->next = first;
		second->prev = NULL;
		*head = second;
		if (n == 1)
			ft_putstr("sb\n");
	}
}

//ss : sa and sb at the same time.

void	ft_ss(t_stack **stacka, t_stack **stackb)
{
	ft_sa(stacka, 0);
	ft_sb(stackb, 0);
	ft_putstr("ss\n");
}

//pa : push a - take the first element at the top of b and put it at the top of
//a. Do nothing if b is empty.

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

//pb : push b - take the first element at the top of a and put it at the top of
//b. Do nothing if a is empty.

void	ft_pb(t_stack **stacka, t_stack **stackb, int n)
{
	t_stack	*tempb;
	t_stack	*tempa;

	tempb = *stackb;
	tempa = (*stacka)->next;
	if (tempa && tempb)
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
