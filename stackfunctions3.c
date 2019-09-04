/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfunctions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 12:04:21 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/04 14:17:44 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */ #include "push_swap.h"
#include <stdio.h>

void	ft_rra(t_stack **stacka, int n)
{
	t_stack *first;
	t_stack *last;
	t_stack *temp;

	first = *stacka;
	last = *stacka;
	if (first && last)
	{
		while (last->next)
			last = last->next;
		temp = last->prev;
		first->prev = last;
		last->next = first;
		temp->next = NULL;
		last->prev = NULL;
		*stacka = last;
		if (n == 1)
			ft_putstr("rra\n");
	}
}

void	ft_rrb(t_stack **stackb, int n)
{
	t_stack *first;
	t_stack *last;
	t_stack *temp;

	first = *stackb;
	last = *stackb;
	if (first && last)
	{
		while (last->next)
			last = last->next;
		temp = last->prev;
		first->prev = last;
		last->next = first;
		temp->next = NULL;
		last->prev = NULL;
		*stackb = last;
		if (n == 1)
			ft_putstr("rrb\n");
	}
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
			if (ft_isdigit(arr[i][j++]) == 0)
				return (1);
		i++;
	}
	return (0);
}

int		isDuplicate(char **arr)
{
	int i;
	int j;
	char *n;

	i = 0;
	if (check_chars(arr))
		return (0);
	else
	{
		while(arr[i])
		{
			j = 0;
			while (arr[i][j])
			{
				n = ft_itoa(ft_atoi(arr[j]));
				if (ft_strequ(arr[i], n) && i != j)
				{
					free(n);
					return (0);
				}
				free(n);
				j++;
			}
			i++;
		}
	}
	return (1);
}
