/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:37:12 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/18 21:00:37 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_sort(t_list **a)
{	
	while ((*a)->next)
	{
		if ((*a)->content > (*a)->next->content)
			return (0);
		(*a) = (*a)->next;
	}
	return (1);
}

int	*param(int a, char **v, t_ps *w)
{
	t_help	go;

	go.i = 1;
	go.j = 0;
	go.t = 0;
	go.arr = malloc (sizeof(int) * w->count);
	while (go.i < a)
	{
		go.j = 0;
		if (v[go.i][0] == '\0')
			printerror("Error\n");
		check_space(v[go.i]);
		go.split = ft_split(v[go.i], ' ');
		while (go.split[go.j] != 0)
		{
			go.arr[go.t] = ft_atoi(go.split[go.j]);
			free(go.split[go.j]);
			go.j++;
			go.t++;
		}
		free(go.split);
		go.i++;
	}	
	return (go.arr);
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

void	paramsum(int ac, char **av, t_ps *p)
{
	int	i;

	p->count = 0;
	i = 1;
	while (i < ac)
	{
		p->count += countlen(av[i], ' ');
		i++;
	}
}
