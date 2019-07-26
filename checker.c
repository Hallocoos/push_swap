/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:05:42 by hde-vos           #+#    #+#             */
/*   Updated: 2019/07/26 12:46:51 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack		*sort(t_stack **stacka, t_stack **stackb)
{
	stackb = stacka;
	return (*stacka);
}

int		checker(t_stack **stack)
{
	t_stack	*temp;
	t_stack *tempnext;

	temp = *stack;
	tempnext = (*stack)->next;
	if (temp && temp->next)
	{
		while (tempnext)
		{
			if (tempnext->value < temp->value)
				return (0);
			temp = tempnext;
			tempnext = tempnext->next;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack *stackb;

	stacka = stackfill(argc, argv);
	stackb = (t_stack *)malloc(sizeof(t_stack) * argc - 1);
	print_stack(&stacka);
	if (!(checker(&stacka) == 1))
		sort(&stacka, &stackb);
	return (0);
}
