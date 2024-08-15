/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:05:45 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/15 18:32:03 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dst) //Check prev variable if needed?
{
	t_stack_node	*buf;
	if (!*src)
		return ;
	buf = *src;
	*src = (*src)->next;
	if (!*dst)
	{
		*dst = buf;
		(*dst)->next = NULL;
	}
	else
	{
		buf->next = *dst;
		*dst = buf;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)//bool?
{
	push(b, a);
	ft_printf("pa\n");
}

//Does the order matter here? I think I put it right in input
void	pb(t_stack_node **a, t_stack_node **b)//bool?
{
	push(a, b);
	ft_printf("pb\n");
}
