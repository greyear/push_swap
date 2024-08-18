/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:30:49 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/15 18:14:29 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_issign(int c) //I created this function in libft, so you can use it now from there
{
	if (c == '+'|| c == '-')
		return (1);
	return (0);
}

int	ft_isdigit(int c) //Delete it and use one from libft for sake of god!
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int is_wrong_input(char *str)  //should it be in error_utils? static?
{
	int i;

	if (!ft_issign(str[0]) && !ft_isdigit(str[0])) //how can I test the function?
		return (1);
	if (ft_issign(str[0]) && !(ft_isdigit(str[1])))
		return (1);
	i = 0;
	while (str[++i]) //is the incrementation here bc we already checked the first symbol? Ans what about the last one then?
	{
		if (!(ft_isdigit(str[i])))
			return (1);
	}
	return (0);
}

static long ft_atol(const char *str) //What if bigger than long?
{
	long    res;
	int     sign;
	int     i;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]) && str[i++] == '-')
		sign = -1;
	res = 0;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0'); // do I need to handle long overflows here like with int in atoi?
	return (sign * res);
}

static void add_node_back(t_stack_node **stack, int num)
{
	t_stack_node    *last_node;
	t_stack_node    *new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	//which variables in list we should fill in? all of them or can we set up values only for n and next?
	new_node->n = num;
	new_node->next = NULL;
	if (!(*stack))
	{
		*stack = new_node;
		//new_node->prev = NULL;
	}
	else
	{
		last_node = last_elem(*stack);
		last_node->next = new_node;
		//new_node->prev = last_node;
	}
}

void    create_stack(t_stack_node **stack, char **numbers, int clean_numbers)
{
	int     i;
	long    lnum;
	int     num;
	
	i = 0;
	while (numbers[i])
	{
		if (is_wrong_input(numbers[i]))
			cleanup_exit(stack, numbers, clean_numbers);
		lnum = ft_atol(numbers[i]);
		if (lnum < INT_MIN || lnum > INT_MAX)
			cleanup_exit(stack, numbers, clean_numbers);
		num = (int)lnum;
		if (is_in_stack(*stack, num))
			cleanup_exit(stack, numbers, clean_numbers);
		add_node_back(stack, num);
		i++;
	}
	if (clean_numbers)
		free_array(numbers);
}

void	put_index(t_stack_node *stack) //Do we need some more variables? If yes, add them. If no, think about putting this functionality into other function
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