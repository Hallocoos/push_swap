/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:05:42 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/02 13:36:34 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort(t_stack **stacka, t_stack **stackb)
{
	ft_sa(stacka, 1);
	print_stack(stacka);
	ft_sb(stackb, 1);
	print_stack(stacka);
	ft_ss(stacka, stackb);
	ft_pa(stacka, stackb, 1);
	print_stack(stacka);
	print_stack(stackb);
	ft_pb(stacka, stackb, 1);
	print_stack(stacka);
	print_stack(stackb);
	ft_ra(stacka, 1);
	print_stack(stacka);
	ft_rb(stackb, 1);
	print_stack(stackb);
	ft_rra(stacka, 1);
	print_stack(stacka);
	ft_rrb(stackb, 1);
	print_stack(stacka);
	ft_rrr(stacka, stackb);
	print_stack(stacka);
}

int			checker(t_stack **stack)
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
	free(temp);
	free(tempnext);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack *stackb;

	if (argc > 1)
	{
		stacka = stackfill(argc, argv);
		stackb = stackfill(argc, NULL); 
//		print_stack(&stacka);
//		print_stack(&stackb);
		if (!(checker(&stacka) == 1))
			sort(&stacka, &stackb);
	}
	return (0);
}
