/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:39:36 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/03 12:44:05 by hde-vos          ###   ########.fr       */
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
		new->weight = 0;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}
void	add_head(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
	{
		node->prev = NULL;
		node->next = *stack;
		*stack = node;
	}
	else
	{
		node->next = NULL;
		node->prev = NULL;
		*stack = node;
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
	t_stack *prev;

	new = *stack;
	prev = NULL;
	if (new && stack)
	{
		ft_putstr("--- Stack ---\n");
		while (new)
		{
			if (new == prev)
			{
				ft_putstr("Cycle in linked list\n");
				break ;
			}
			ft_putnbr(new->value);
			ft_putstr("\t[");
			ft_putnbr(new->weight);
			ft_putstr("]\t{");
			ft_putnbr(new->move_count);
			ft_putstr("}\t(");
			ft_putnbr(new->best_pos_weight);
			ft_putstr(")\t[");
			ft_putnbr(new->end);
			ft_putstr("]\t{");
			ft_putnbr(new->total_move_count);
			ft_putstr("}\n");
			prev = new;
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

	i = 0;
	new = NULL;
	if (ft_strequ(ft_itoa(ft_atoi(args[0])), args[0]) != 0 && is_duplicate(args) != 0)
	{
		stack = createnode(ft_atoi(args[i]));
		while (++i < n)
		{
			if (ft_strequ(ft_itoa(ft_atoi(args[i])), args[i]) == 0)
				return (NULL);
			new = createnode(ft_atoi(args[i]));
			add_tail(new, &stack);
		}
	}
	else
		return (NULL);
	return (stack);
}
