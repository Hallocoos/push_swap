/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:07:06 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/13 09:53:46 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort(t_stack **stacka, t_stack **stackb)
{
	int		i;
	char	*args;

	i = 0;
	while (get_next_line(0, &args) > 0)
	{
		if (ft_strequ(args, "sa"))
			ft_sa(stacka, 1);
		else if (ft_strequ(args, "sb"))
			ft_sb(stackb, 1);
		else if (ft_strequ(args, "ss"))
			ft_ss(stacka, stackb);
		else if (ft_strequ(args, "pa"))
			ft_pa(stacka, stackb, 1);
		else if (ft_strequ(args, "pb"))
			ft_pb(stacka, stackb, 1);
		else if (ft_strequ(args, "ra"))
			ft_ra(stacka, 1);
		else if (ft_strequ(args, "rb"))
			ft_rb(stackb, 1);
		else if (ft_strequ(args, "rr"))
			ft_rr(stacka, stackb);
		else if (ft_strequ(args, "rra"))
			ft_rra(stacka, 1);
		else if (ft_strequ(args, "rrb"))
			ft_rrb(stackb, 1);
		else if (ft_strequ(args, "rrr"))
			ft_rrr(stacka, stackb);
		else
			break ;
		i++;
	}
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
		stackb = NULL; 
		sort(&stacka, &stackb);
		if ((checker(&stacka) == 1) && (stackb == NULL))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		print_stack(&stacka);
		print_stack(&stackb);
	}
	return (0);
}
