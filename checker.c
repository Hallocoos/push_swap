/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:55:27 by hde-vos           #+#    #+#             */
/*   Updated: 2019/07/18 13:54:18 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		create_list(int n, t_stack *stack)
{
	while (n-- > 0)
		lstadd(&stack, lstnew(NULL, 0)); 
}

t_stack		*store_args(char **args, char c)
{
	t_stack	*list;
	int		i;
	int		j;

	if (c == '1')
		while (args[0][0] >= '0' || args[0][0] <= '9')
			i++;
	if (c == 'a')
		while (args[0][0] >= 'a' || args[0][0] <= 'z')
			i++;
	create_list(i, list);
	list = (t_stack *)malloc(sizeof(t_stack) * i);
	j = 0;
	while (i--)
	{
		list->value = ft_atoi(args[j++]);
		list = list->next;
	}		
	return (list);
}

int			main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = store_args(argv, '1');
	stackb = store_args(argv, 'a');
	return (0);
}
