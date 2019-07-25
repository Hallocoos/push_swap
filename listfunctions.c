/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:54:23 by hde-vos           #+#    #+#             */
/*   Updated: 2019/07/18 14:09:09 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	*createlist(int	n, t_stack *stack)
{
	stack->value = NULL;
	stack->next = NULL;
	stack->prev = NULL;
	while (n-- > 0)
	{
		stack->value = NULL;
		stack->next = NULL;
		stack->prev = NULL;
	}
}
