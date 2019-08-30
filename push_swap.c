/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:55:35 by hde-vos           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/30 10:14:43 by hde-vos          ###   ########.fr       */
=======
/*   Updated: 2019/08/28 12:21:23 by hde-vos          ###   ########.fr       */
>>>>>>> bb89423082ddde0b486f0a44bd811b34275dd09d
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
int		sortstack(t_stack **stacka, t_stack **stackb)
{
	stacka = NULL;
	stackb = NULL;
	return (0);
}

int main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack *stackb;
	t_stack *temp;
	char	**args;

	args = &argv[1];
	if (argc > 1)
	{
		if (argc == 2)
			args = ft_strsplit(argv[1], ' ');
		argc = ft_arrlen(args);
		if ((stacka = stackfill(argc, args)))
		{
			print_stack(&temp);
			temp = stacka;
			while (temp)
			{
				ft_putnbr(temp->weight);
				temp = temp->next;
			}
			stackb = NULL;
			sortstack(&stacka, &stackb);
		}
	}
	return (0);
=======
int	main(void)
{
	
>>>>>>> bb89423082ddde0b486f0a44bd811b34275dd09d
}
