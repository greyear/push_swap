/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:15:21 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/02 19:21:54 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*cur_list;

	if (!*stack || !(*stack)->next)
		return ;
	last = last_elem(*stack);
	cur_list = *stack;
	while (cur_list != NULL)
	{
		if (cur_list->next->next == NULL)
			{
				cur_list->next = NULL;
				break ;
			}
		cur_list = cur_list->next;
	}
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
