/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fields.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:21:36 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 20:35:50 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	put_index(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	target_in_b(t_stack *a, t_stack *b)
{
	long	closest_smaller;
	t_stack	*target;
	t_stack	*cur_b;

	while (a)
	{
		closest_smaller = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if (cur_b->n < a->n && cur_b->n > closest_smaller)
			{
				closest_smaller = cur_b->n;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (closest_smaller == LONG_MIN)
			a->target = max_elem(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	target_in_a(t_stack *a, t_stack *b)
{
	long	closest_bigger;
	t_stack	*target;
	t_stack	*cur_a;

	while (b)
	{
		closest_bigger = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->n > b->n && cur_a->n < closest_bigger)
			{
				closest_bigger = cur_a->n;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (closest_bigger == LONG_MAX)
			b->target = min_elem(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	put_fields_a(t_stack *a, t_stack *b)
{
	put_index(a);
	put_index(b);
	target_in_b(a, b);
	push_cost_both(a, b);
}

void	put_fields_b(t_stack *a, t_stack *b)
{
	put_index(a);
	put_index(b);
	target_in_a(a, b);
}
