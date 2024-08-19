/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:00:37 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/19 19:47:16 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_in_stack(t_stack *stack, int num) //why here int then instead of long?
{
	t_stack	*cur_node;

	if (!stack)
		return (0);
	cur_node = stack;
	while (cur_node)
	{
		if (cur_node->n == num)
			return (1);
		cur_node = cur_node->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_node;
	t_stack	*cur_node;

	if (!stack)
		return ;
	cur_node = *stack;
	while (cur_node)
	{
		next_node = cur_node->next;
		cur_node->n = 0;
		free(cur_node);
		cur_node = next_node;
	}
	*stack = NULL;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);//1 or -1? 1 is more common, -1 is used e.g. in printf
}

void	cleanup_exit(t_stack **stack, char **num, int clean_num)
{
	free_stack(stack);
	if (clean_num == 1)
		free_array(num);
	error_and_exit();
}
