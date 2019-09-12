/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackmanipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:00:22 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/12 12:37:31 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_weight(t_stack *stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*head;

	head = stack;
	i = stacksize(&head);
	while (stack)
	{
		temp = head;
		stack->weight = i;
		while (temp)
		{
			if (temp->value > stack->value && temp->value != stack->value)
				stack->weight--;
			temp = temp->next;
		}
		stack = stack->next;
	}
}

void	freestack(t_stack **stack)
{
	t_stack *next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
}

int		stacksize(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int		is_smallest(t_stack *stack)
{
	int		i;
	t_stack	*temp;

	temp = stack;
	i = stack->value;
	while (temp->next)
	{
		if (i > temp->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
