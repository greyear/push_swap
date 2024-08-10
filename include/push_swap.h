/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:46:42 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/10 19:22:14 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_stack_node
{
	int					n;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*prev; //Maybe I don't need it even. Try to write rev rotate first!!
	struct s_stack_node	*target;
	int					cost;
}	t_stack_node;

//Operations (bool??)
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//Error utils
int				is_in_stack(t_stack_node *stack, int num);
void			free_stack(t_stack_node **stack);
void			print_error_and_exit(t_stack_node **stack);

//Split
char			**custom_split(char *s, char c);

//Stack
void			create_stack(t_stack_node **stack, char *argv[]);
void			put_index(t_stack_node *stack);
int				is_sorted(t_stack_node *stack);
t_stack_node	*last_elem(t_stack_node *stack);
t_stack_node	*min_elem(t_stack_node *stack);
t_stack_node	*max_elem(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
int				above_median(t_stack_node *stack, t_stack_node *checked_node);

//Moving costs
void			make_top_a(t_stack_node **stack, t_stack_node *future_top);
void			make_top_b(t_stack_node **stack, t_stack_node *future_top);
void			push_cost_both(t_stack_node *a, t_stack_node *b);
t_stack_node	*cheapest_node(t_stack_node *stack);
void			put_fields_a(t_stack_node *a, t_stack_node *b);
void			put_fields_b(t_stack_node *a, t_stack_node *b);

//Sorting
void			sort_three(t_stack_node **stack);
void			sort_more(t_stack_node **a, t_stack_node **b);

#endif
