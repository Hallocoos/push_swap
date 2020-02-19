/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:03:50 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/12 12:37:40 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_weight(t_stack *stack, int n)
{
	while (stack->next)
	{
		if (stack->weight == n)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack *find_top(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack *find_bottom(t_stack *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack *find_max(t_stack *stack)
{
	// lose i to save some lines
	t_stack	*ret;
	t_stack	*stack_temp;
	int		i;

	i = stack->weight;
	stack_temp = stack;
	ret = stack;
	while (stack_temp)
	{
		if (stack_temp->end == 1)
			stack_temp->end = 0;
		if (stack_temp->weight > i)
		{
			ret = stack_temp;
			i = stack_temp->weight;
		}
		stack_temp = stack_temp->next;
	}
	stack_temp = stack;
	ret->end = 1;
	return (ret);
}

t_stack *find_min(t_stack *stack)
{
	t_stack	*ret;
	t_stack	*stack_temp;
	int		i;

	i = stack->weight;
	stack_temp = stack;
	ret = stack;
	while (stack_temp)
	{
		if (stack_temp->end == -1)
			stack_temp->end = 0;
		if (stack_temp->weight < i)
		{
			ret = stack_temp;
			i = stack_temp->weight;
		}
		stack_temp = stack_temp->next;
	}
	stack_temp = stack;
	ret->end = -1;
	return (ret);
}
