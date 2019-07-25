/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:24 by hde-vos           #+#    #+#             */
/*   Updated: 2019/07/18 14:09:18 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef	struct		s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*lstnew(void const *content, size_t content_size);
void	lstdelone(t_stack **alst, void (*del)(void *, size_t));
void	lstdel(t_stack **alst, void (*del)(void *, size_t));
void	lstadd(t_stack **alst, t_stack *new);

# endif
