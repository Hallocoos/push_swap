/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:05:42 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/05 15:23:40 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort(t_stack **stacka, t_stack **stackb, char **args)
{
	int	i;

	if (args[i] == "sa")
		ft_sa(stacka, 1);
	if (args[i] == "sb")
		ft_sb(stackb, 1);
	if (args[i] == "ss")
		ft_ss(stacka, stackb);
	if (args[i] == "pa")
		ft_pa(stacka, stackb, 1);
	if (args[i] == "pb")
		ft_pb(stacka, stackb, 1);
	if (args[i] == "ra")
		ft_ra(stacka, 1);
	if (args[i] == "rb")
		ft_rb(stackb, 1);
	if (args[i] == "rr")
		ft_rr(stacka, stackb);
	if (args[i] == "rra")
		ft_rra(stacka, 1);
	if (args[i] == "rrb")
		ft_rrb(stackb, 1);
	if (args[i] == "rrr")
		ft_rrr(stacka, stackb);
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
	int		ret;

	line = ft_memalloc(sizeof(char **));
	while ((ret = get_next_line(0, args)) > 0);
	if (argc > 1)
	{
		stacka = stackfill(argc, argv);
		stackb = stackfill(argc, NULL); 
		if (!(checker(&stacka) == 1))
			sort(&stacka, &stackb, args);
	}
	return (0);
}
