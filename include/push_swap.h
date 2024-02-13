/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:22:45 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/26 13:03:55 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft_1.1/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				push_cost;
	int				position;
	bool			cheapest;
	bool			above_mid;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

char	**ft_check_arg(int ac, char **av);
void	ft_error(void);
int		ft_is_valid(char *str);
int		ft_is_int(char *str);
int		ft_check_max(long nbr, int sign);
int		ft_not_duplicate(char **stack, char *item, int index);
void	ft_init_stack(t_stack **a, int ac, char **av);
void	ft_lstadd_new(t_stack **a, int value);
t_stack	*ft_lst_tail(t_stack *lst);
void	ft_free_error(t_stack *lst);
void	ft_free_stack(t_stack *lst);
void	ft_print_stacks(t_stack *a, t_stack *b);
void	ft_swap(t_stack **a);
void	ft_swap_p(t_stack **a, char stack);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_push_p(t_stack **from, t_stack **to, char dest);
void	ft_push(t_stack **from, t_stack **to);
void	ft_rotate_p(t_stack **stack, char c);
void	ft_rotate(t_stack **stack);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_reverse_rotate_p(t_stack **a, char c);
void	ft_reverse_rotate(t_stack **stack);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b);
bool	ft_is_sorted(t_stack *a);
int		ft_stack_size(t_stack *stack);
void	ft_sort_3(t_stack **a);
t_stack	*ft_highest(t_stack *stack);
void	ft_sort_5(t_stack **a, t_stack **b);
t_stack	*ft_smallest(t_stack *stack);
void	ft_big_sort(t_stack **a, t_stack **b);
int		ft_full_value(t_stack *stack);
void	ft_set_cheapest(t_stack *a, t_stack *b);
void	ft_set_position(t_stack *stack);
void	ft_target(t_stack *a, t_stack *b);
void	ft_cost(t_stack *a, t_stack *b);
void	ft_cheapest(t_stack *b);
void	ft_push_cheapest(t_stack **a, t_stack **b);
t_stack	*ft_get_cheapest(t_stack *stack);
void	ft_double_rot(t_stack **a, t_stack **b, t_stack *cheapest_node,
			bool rev);
void	ft_topping_node(t_stack **stack, t_stack *to_top, char c);
void	ft_first_top(t_stack **a);
long	ft_mid(t_stack *a);
void	ft_free(char **av);
#endif
