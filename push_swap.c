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

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

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
	freestack(&stacka);
	freestack(&stackb);
}

int main(int argc, char **argv)
{
	char 	**args;

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
		free_array(args);
		free(args);
	}
	return (0);
}
