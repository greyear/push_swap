/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:00:37 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/09 17:40:02 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int is_in_stack(t_stack_node *stack, int num) //why here int then instead of long?
{
	t_stack_node    *cur_node;
	
	if (!stack)
		return (0);
	cur_node = stack;
	while(cur_node)
	{
		if (cur_node->n == num)
			return (1);
		cur_node = cur_node->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node    *next_node;
	t_stack_node    *cur_node;

	if (!stack)
		return ;
	cur_node = *stack;
	while(cur_node)
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
	exit(1); //1 or -1? 1 is more common, -1 is used e.g. in printf
}

void	cleanup_exit(t_stack_node **stack, char **numbers, int clean_numbers)
{
	free_stack(stack);
	if (clean_numbers == 1)
		free_array(numbers);
	error_and_exit();
}
