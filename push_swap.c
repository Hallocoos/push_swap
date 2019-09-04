/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:55:35 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/04 13:36:25 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sortstack(t_stack **stacka, t_stack **stackb)
{
	int		len;

	stackb = NULL;
	len = stacksize(stacka);
	if (len == 2)
		sort_two(stacka);	
	return (0);
}

void	initialize(int argc, char **args)
{
	t_stack	*stacka;
	t_stack *stackb;

	if ((stacka = stackfill(argc, args)))
	{
		stackb = NULL;
		sortstack(&stacka, &stackb);
		print_stack(&stacka);
	}
	freestack(&stacka);
	freestack(&stackb);
}


int		main(int argc, char **argv)
{
	char	**args;

	args = argv + 1;
	if (argc > 1)
	{
		argc = argc - 1;
		if (argc == 1 && ft_strchr(args[0], ' ') != NULL)
		{
			args = ft_strsplit(args[0], ' ');
			argc = ft_arrlen(args);
			initialize(argc, args);
		}
		else
			initialize(argc, args);
	}
	while (1);
	return (0);
}
