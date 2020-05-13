/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-vos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:24 by hde-vos           #+#    #+#             */
/*   Updated: 2019/09/16 11:55:34 by hde-vos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct	s_stack
{
	int			value;
	int			weight;
	int			move_count;
	int			best_pos_weight;
	int			end;
	int			total_move_count;
	struct		s_stack *next;
	struct		s_stack *prev;
}				t_stack;

int		checker(t_stack **stack); 
int		move_calc(t_stack *stacka, t_stack *stackb);
int		is_sorted_desc(t_stack *stackb);
void	sort_three_desc(t_stack **stack);
t_stack	*lstnew(void const *content, size_t content_size);
void	lstdelone(t_stack **alst, void (*del)(void *, size_t));
void	lstdel(t_stack **alst, void (*del)(void *, size_t));
void	lstadd(t_stack **alst, t_stack *new);
t_stack	*createnode(int n);
void	add_tail(t_stack *new, t_stack **stack);
void	add_head(t_stack **stack, t_stack *node);
void	print_stack(t_stack **stack);
t_stack	*stackfill(int n, char **args);
void	ft_sa(t_stack **stacka, int n);
void	ft_sb(t_stack **stacka, int n);
void	ft_ss(t_stack **stacka, t_stack **stackb, int i);
void	ft_pa(t_stack **stacka, t_stack **stackb, int n);
void	ft_pb(t_stack **stacka, t_stack **stackb, int n);
void	ft_ra(t_stack **stacka, int n);
void	ft_rb(t_stack **stackb, int n);
void	ft_rr(t_stack **stacka, t_stack **stackb, int i);
void	ft_rra(t_stack **stacka, int n);
void 	ft_rrb(t_stack **stackb, int n);
void	ft_rrr(t_stack **stacka, t_stack **stackb, int i);
int		is_duplicate(char **arr);
void	set_weight(t_stack *stack);
void	freestack(t_stack **stack);
int		stacksize(t_stack *stack);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **stacka, t_stack **stackb);
void	sort_all(t_stack **stacka, t_stack **stackb);
t_stack	*smallest(t_stack *stack);
int		move_count(t_stack *index_stack, t_stack *search_stack);
void	stacka_move_count(t_stack *stack);
void	stackb_move_count(t_stack *stack);
t_stack	*get_last_in_stack(t_stack *stack);
void	find_best_stackb_pos(t_stack *stacka, t_stack *stackb);
t_stack	*find_smallest_move_count(t_stack *stacka);
int		stackb_is_sorted(t_stack *stackb);
t_stack	*find_weight(t_stack *stack, int n);
t_stack	*find_top(t_stack *stack);
t_stack	*find_bottom(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	stackb_sort_two(t_stack **stack);
void	free_stack(t_stack **head);

#endif
