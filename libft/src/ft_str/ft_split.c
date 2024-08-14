/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:02:07 by azinchen          #+#    #+#             */
/*   Updated: 2024/08/01 20:15:06 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdio.h> //delete!

static int	ft_clean(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (-1);
}

static int	ft_count(const char *str, char c)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static void	ft_elem(char *dest, const char *str, int start, char c)
{
	int	i;

	i = 0;
	while (str[start] != c && str[start] != '\0')
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	dest[i] = '\0';
}

static int	ft_array(char **array, const char *str, char c)
{
	int		i;
	int		j;
	int		index;

	index = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			array[index] = (char *)malloc((j + 1) * sizeof(char));
			if (!array[index])
				return (ft_clean(array, index));
			ft_elem(array[index], str, i, c);
			//printf("%d - %s ", index, array[index]); //delete!
			i = i + j;
			index++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		count;

	count = ft_count(str, c);
	res = (char **)malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (ft_array(res, str, c) == -1)
		return (NULL);
	res[count] = 0;
	return (res);
}
/*
int main(int argc, char *argv[])
{
	if (argc == 1 || (argc == 2 && !argv[1][0])) //second argument is what exactly? \0?
		return (1); //error message code? can be -1?
	else if (argc == 2)
		argv  = ft_split(argv[1], ' '); //nuzhen ne ft_split, a split!
	return (0);
}*/
