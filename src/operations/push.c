/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:05:45 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/01 18:20:28 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src) //Check prev variable if needed?
{
	t_stack_node	*buf;
	if (!*src)
		return ;
	buf = *src;
	*src = (*src)->next;
	if (!*dst)
	{
		*dst = buf;
		(*dst)->next = NULL; //or buf, it doesn't matter!!
	}
	else
	{
		buf->next = *dst;
		*dst = buf;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)//bool?
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b)//bool?
{
	push(b, a);
	ft_printf("pb\n");
}
