/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:46:42 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 20:38:35 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_stack
{
	int					n;
	int					index;
	struct s_stack		*next;
	struct s_stack		*target;
	int					cost;
}	t_stack;

//Operations (bool??)
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rr_and_refresh(t_stack **a, t_stack **b, t_stack *cheapest);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			rrr_and_refresh(t_stack **a, t_stack **b, t_stack *cheapest);

//Error utils
int				is_in_stack(t_stack *stack, int num);
void			free_stack(t_stack **stack);
void			free_array(char **array);
void			error_and_exit(void);
void			cleanup_exit(t_stack **stack, char **num, int clean_num);

//Stack & fields
void			create_stack(t_stack **stack, char **num, int clean_num);
int				is_sorted(t_stack *stack);
int				stack_len(t_stack *stack);
int				above_median(t_stack *stack, t_stack *checked_node);
int				moves_to_top(t_stack *stack, t_stack *required_node);
t_stack			*last_elem(t_stack *stack);
t_stack			*min_elem(t_stack *stack);
t_stack			*max_elem(t_stack *stack);
void			put_index(t_stack *stack);
void			target_in_b(t_stack *a, t_stack *b);
void			target_in_a(t_stack *a, t_stack *b);
void			put_fields_a(t_stack *a, t_stack *b);
void			put_fields_b(t_stack *a, t_stack *b);

//Moving costs
void			make_top_a(t_stack **stack, t_stack *future_top);
void			make_top_b(t_stack **stack, t_stack *future_top);
void			push_cost_both(t_stack *a, t_stack *b);
t_stack			*cheapest_node(t_stack *stack);

//Sorting
void			sort_three(t_stack **stack);
void			sort_all(t_stack **a, t_stack **b);

#endif
