/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:04:21 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/12 12:49:21 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_rra(t_stack **stacka, int i)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!(*stacka) || (stacksize(stacka) < 2))
		return ;
	last = *stacka;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stacka;
	second_last->prev = *stacka;
	(*stacka)->prev = last;
	(*stacka)->next = second_last;
	*stacka = last;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stackb, int i)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!(*stackb) || (stacksize(stackb) < 2))
		return ;
	last = *stackb;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stackb;
	second_last->prev = *stackb;
	(*stackb)->prev = last;
	(*stackb)->next = second_last;
	*stackb = last;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stacka, t_stack **stackb)
{
	ft_rra(stacka, 0);
	ft_rrb(stackb, 0);
	ft_putstr("rrr\n");
}

int		check_chars(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			if (ft_isdigit(arr[i][j++]) == 0 && arr[i][0] != '-')
				return (1);
		i++;
	}
	return (0);
}

int		isDuplicate(char **arr)
{
	int i;
	char *n;

	i = 0;
	if (check_chars(arr))
		return (0);
	else
	{
		while(arr[i])
		{
			n = ft_itoa(ft_atoi(arr[i]));
			printf("%s = %s\n", n, arr[i]);
			if (!ft_strequ(arr[i], n))
			{
				free(n);
				return (0);
			}
			free(n);
			i++;
		}
	}
	return (1);
}
