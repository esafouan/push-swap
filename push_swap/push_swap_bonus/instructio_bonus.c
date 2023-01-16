/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructio_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:29:38 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/16 17:58:26 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}

int	*sorting_array(int *array, int size)
{
	int	i;
	int	j;
	int	x;

	while (size)
	{
		i = 0;
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				x = array[i];
				array [i] = array[j];
				array[j] = x;
			}
			i++;
			j++;
		}
		size--;
	}
	return (array);
}

int	countlen(char const *s1, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (*s1)
	{
		if (*s1 != c && a == 0)
		{
			a = 1;
			i++;
		}
		else if (*s1 == c)
			a = 0;
		s1++;
	}
	return (i);
}
