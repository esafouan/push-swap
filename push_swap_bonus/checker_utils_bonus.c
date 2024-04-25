/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:37:05 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/16 16:37:40 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_duplicate(int c, int *array)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (array[i] == array[i + 1])
			prerror("Error\n");
		i++;
	}
}

void	numofparam(int ac, char **av, t_checker *p)
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

int	*transfer_para(int a, char **v, t_checker *w)
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
			prerror("Error\n");
		go.split = ft_split(v[go.i], ' ');
		while (go.split[go.j] != 0)
		{
			go.arr[go.t] = ft_atoii(go.split[go.j]);
			free(go.split[go.j]);
			go.j++;
			go.t++;
		}
		free(go.split);
		go.i++;
	}
	return (go.arr);
}

void	do_instructions(char *gnl, t_list **a, t_list **b)
{
	if (ft_strcmp(gnl, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(gnl, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(gnl, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(gnl, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(gnl, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(gnl, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(gnl, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(gnl, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(gnl, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(gnl, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(gnl, "sb\n") == 0)
		sb(b);
	else
		prerror("Error\n");
}

void	make_stack(t_list **a, t_checker *index)
{
	int	i;

	i = 1;
	*a = ft_lstnew(index->tab[0]);
	while (i < index->count)
	{
		ft_lstadd_back(a, ft_lstnew(index->tab[i]));
		i++;
	}
}
