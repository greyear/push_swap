/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:33:49 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/01 18:32:04 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}
