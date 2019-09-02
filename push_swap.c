/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:55:35 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/02 15:56:23 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sortstack(t_stack **stacka, t_stack **stackb)
{
	write(1, "C\n", 1);
	stacka = NULL;
	stackb = NULL;
	return (0);
}

void	initialize(int argc, char **args)
{
	t_stack	*stacka;
	t_stack *stackb;

	if ((stacka = stackfill(argc, &args[1])))
	{
		stackb = NULL;
		sortstack(&stacka, &stackb);
		print_stack(&stacka);
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv = &argv[1];
		if (argc == 2)
			argv = ft_strsplit(argv[1], ' ');
		ft_putnbr(ft_arrlen(argv));
		argc = ft_arrlen(argv);
//		initialize(argc, argv);
//		write(1, "D", 1);
	}
	return (0);
}
