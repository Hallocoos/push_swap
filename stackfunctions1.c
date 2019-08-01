/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:32:20 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/01 17:47:10 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

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

	if (*stacka && *stackb)
	{
		tempa = *stacka;
		tempb = (*stackb)->next;
		tempa->next = *stackb;
		(*stackb)->prev = tempa;
		(*stackb)->next = NULL;
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

	if (*stacka && *stackb)
	{
		tempb = *stackb;
		tempa = (*stacka)->next;
		tempb->next = *stacka;
		(*stacka)->prev = tempb;
		(*stacka)->next = NULL;
		tempa->prev = NULL;
		*stackb = *stacka;
		*stacka = tempa;
		if (n == 1)
			ft_putstr("pb\n");
	}
}
