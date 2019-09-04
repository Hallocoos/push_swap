/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:07:06 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/04 11:52:55 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void		sort(t_stack **stacka, t_stack **stackb, char *args)
{
	if (ft_strequ(args, "sa"))
		ft_sa(stacka, 0);
	else if (ft_strequ(args, "sb"))
		ft_sb(stackb, 0);
	else if (ft_strequ(args, "ss"))
		ft_ss(stacka, stackb);
	else if (ft_strequ(args, "pa"))
		ft_pa(stacka, stackb, 0);
	else if (ft_strequ(args, "pb"))
		ft_pb(stacka, stackb, 0);
	else if (ft_strequ(args, "ra"))
		ft_ra(stacka, 0);
	else if (ft_strequ(args, "rb"))
		ft_rb(stackb, 0);
	else if (ft_strequ(args, "rr"))
		ft_rr(stacka, stackb);
	else if (ft_strequ(args, "rra"))
		ft_rra(stacka, 0);
	else if (ft_strequ(args, "rrb"))
		ft_rrb(stackb, 0);
	else if (ft_strequ(args, "rrr"))
		ft_rrr(stacka, stackb);
}

void		readline(t_stack **stacka, t_stack **stackb)
{
	char 	*args;

	args = malloc(1);
	while (get_next_line(0, &args))
	{
		sort(stacka, stackb, args);
		//ft_putstr(args);
		free(args);
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
	char	**args;

	args = &argv[1];
	if (argc > 1)
	{
		if (argc == 2)
			args = ft_strsplit(argv[1], ' ');
		argc = ft_arrlen(args);
		if ((stacka = stackfill(argc, args)))
		{
			stackb = NULL; 
			readline(&stacka, &stackb);
			if ((checker(&stacka) == 1) && (stackb == NULL))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			print_stack(&stacka);
		}
	}
	freestack(stacka);
	freestack(stackb);
	while (1);
	return (0);
}
