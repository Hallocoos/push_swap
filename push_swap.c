/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:55:35 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/19 14:02:44 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sortstack(t_stack **stacka, t_stack **stackb)
{
	int len;

	len = stacksize(*stacka);
	if (len > 1)
	{
		if (len == 2)
			sort_two(stacka);
		else if (len == 3)
			sort_three(stacka);
		else if (len > 3 && len < 6)
			sort_five(stacka, stackb);
		else if (len > 5)
			sort_all(stacka, stackb);
	}
}

void initialize(int argc, char **args)
{
	t_stack *stacka;
	t_stack *stackb;

	stackb = NULL;
	if ((stacka = stackfill(argc, args)))
	{
		set_weight(stacka);
		stacka_move_count(stacka);
		if (checker(&stacka) == 0)
			sortstack(&stacka, &stackb);
	}
	else
		write(1, "Error\n", 6);
	free_stack(&stacka);
	free_stack(&stackb);
}

int main(int argc, char **argv)
{
	char	**numbers;

	numbers = argv + 1;
	if (argc < 2 || ft_is_empty(numbers[0]))
		write(1, "Error\n", 6);
	else if (argc == 2)
	{
		numbers = ft_strsplit(argv[1], ' ');
		argc = ft_arrlen(numbers);
		initialize(argc, numbers);
		ft_free_array(numbers);
	}
	else
	{
		argc -= 1;
		initialize(argc, numbers);
	}
	return (0);
}
