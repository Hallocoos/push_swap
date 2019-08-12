/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:24 by hde-vos           #+#    #+#             */
/*   Updated: 2019/08/08 13:13:40 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef	struct		s_stack
{
	int				value;
	int				weight;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*lstnew(void const *content, size_t content_size);
void	lstdelone(t_stack **alst, void (*del)(void *, size_t));
void	lstdel(t_stack **alst, void (*del)(void *, size_t));
void	lstadd(t_stack **alst, t_stack *new);
t_stack	*createnode(int n);
void	add_tail(t_stack *new, t_stack **stack);
void	print_stack(t_stack **stack);
t_stack	*stackfill(int n, char **args);
void	ft_sa(t_stack **stacka, int n);
void	ft_sb(t_stack **stacka, int n);
void	ft_ss(t_stack **stacka, t_stack **stackb);
void	ft_pa(t_stack **stacka, t_stack **stackb, int n);
void	ft_pb(t_stack **stacka, t_stack **stackb, int n);
void	ft_ra(t_stack **stacka, int n);
void	ft_rb(t_stack **stackb, int n);
void	ft_rr(t_stack **stacka, t_stack **stackb);
void	ft_rra(t_stack **stacka, int n);
void	ft_rrb(t_stack **stackb, int n);
void	ft_rrr(t_stack **stacka, t_stack **stackb);

# endif
