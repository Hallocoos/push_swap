/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:07:06 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/16 11:13:53 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack **stacka, t_stack **stackb, char *args)
{
	if (ft_strequ(args, "sa"))
		ft_sa(stacka, 0);
	else if (ft_strequ(args, "sb"))
		ft_sb(stackb, 0);
	else if (ft_strequ(args, "ss"))
		ft_ss(stacka, stackb, 0);
	else if (ft_strequ(args, "pa"))
		ft_pa(stacka, stackb, 0);
	else if (ft_strequ(args, "pb"))
		ft_pb(stacka, stackb, 0);
	else if (ft_strequ(args, "ra"))
		ft_ra(stacka, 0);
	else if (ft_strequ(args, "rb"))
		ft_rb(stackb, 0);
	else if (ft_strequ(args, "rr"))
		ft_rr(stacka, stackb, 0);
	else if (ft_strequ(args, "rra"))
		ft_rra(stacka, 0);
	else if (ft_strequ(args, "rrb"))
		ft_rrb(stackb, 0);
	else if (ft_strequ(args, "rrr"))
		ft_rrr(stacka, stackb, 0);
	else
		return (1);
	return (0);
}

int	readline(t_stack **stacka, t_stack **stackb)
{	
	char *args;

	while (get_next_line(0, &args))
	{
		if (sort(stacka, stackb, args) == 1)
		{
			free(args);
			return (1);
		}
		free(args);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack *stacka;
	t_stack *stackb;
	char **numbers;
	int i;

	if (argc > 1)
	{
		i = 0;
		numbers = &argv[1];
		argc = argc - 1;
		if (argc == 1 && ft_strchr(numbers[0], ' ') != NULL)
		{
			i = 1;
			if (!ft_is_empty(numbers[0]))
				numbers = ft_strsplit(numbers[0], ' ');
		}
		stackb = NULL;
		if ((argc = ft_arrlen(numbers)) && (stacka = stackfill(argc, numbers)) && readline(&stacka, &stackb) == 0)
		{
			if (checker(&stacka) == 1 && (stackb == NULL))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			write(1, "Error\n", 6);
		if (i == 1)
			ft_free_array(numbers);
		free_stack(&stacka);
		free_stack(&stackb);
	}
	return (0);
}
