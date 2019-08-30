/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:03:50 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/29 13:08:32 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find(t_stack *stack, int n)
{
	while (stack->next)
	{
		if (stack->value == n)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*findtop(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*findbottom(t_stack *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*findmax(t_stack *stack)
{
	t_stack	*ret;
	int		i;

	stack = findtop(stack);
	i = stack->value;
	while (stack->next)
	{
		if (stack->value > i)
		{
			ret = stack;
			i = stack->value;
		}
		stack = stack->next;
	}
	return (ret);
}

t_stack	*findmin(t_stack *stack)
{
	t_stack	*ret;
	int		i;

	stack = findtop(stack);
	i = stack->value;
	while (stack->next)
	{
		if (stack->value > i)
		{
			ret = stack;
			i = stack->value;
		}
		stack = stack->next;
	}
	return (ret);
}
