/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:39:36 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/01 17:56:10 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*createnode(int n)
{
	t_stack *new;
	
	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->value = n;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

void	add_head(t_stack *new, t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		temp->prev = new;
		new->next = *stack;
		new->prev = NULL;
		*stack = new;
	}
	else 
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
}

void	add_tail(t_stack *new, t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void	print_stack(t_stack **stack)
{
	t_stack	*new;

	new = *stack;
	if (new)
	{
		ft_putstr("--- Stack ---\n");
		while (new)
		{
			ft_putnbr(new->value);
			ft_putendl("");
			new = new->next;
		}
		ft_putstr("-------------\n");
	}
}

t_stack	*stackfill(int n, char **args)
{
	t_stack *stack;
	t_stack	*new;
	int		i;

	i = 1;
	if (args)
	{
		stack = createnode(ft_atoi(args[i]));
		while (++i < n)
		{
			new = createnode(ft_atoi(args[i]));
			add_tail(new, &stack);
		}
	}
	else
	{
		stack = createnode(0);
		while (++i < n)
		{
			new = createnode(0);
			add_tail(new, &stack);
		}
	}
	return (stack);
}