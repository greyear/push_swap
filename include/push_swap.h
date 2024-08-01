/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:46:42 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/01 18:20:02 by azinchen         ###   ########.fr       */
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
}	t_stack_node;

//Error utils
int				is_in_stuck(t_stack_node *stack, int num);
void			free_stuck(t_stack_node **stack);

//Stack utils
int				is_sorted(t_stack_node *stack);
t_stack_node	*last_elem(t_stack_node *stack);
t_stack_node	*min_elem(t_stack_node *stack);
t_stack_node	*max_elem(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

#endif
