/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:46:42 by azinchen          #+#    #+#             */
/*   Updated: 2024/07/22 16:16:36 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack_node
{
    int n;
    int index;
    struct s_stack_node *next;
    struct s_stack_node *prev;
} t_stack_node;

#endif
