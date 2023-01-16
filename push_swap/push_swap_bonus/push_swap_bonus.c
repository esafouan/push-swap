/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:07:04 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/16 16:34:13 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_atoi(char *str)
{
	t_atoii	q;

	q.sign = 1;
	q.i = 0;
	q.j = 0;
	while (str[q.i] == 32 || (str[q.i] >= 9 && str[q.i] <= 13))
		q.i++;
	if (str[q.i] == '-' || str[q.i] == '+')
	{
		if (str[q.i] == '-')
			q.sign *= -1;
		q.i++;
	}
	if (str[q.i] == '\0')
		printerror("Error\n");
	while (str && str[q.i])
	{
		if (!(str[q.i] <= '9' && str[q.i] >= '0'))
			printerror("Error\n");
		q.j = q.j * 10 + str[q.i] - 48;
		q.i++;
	}
	if (q.j * q.sign > 2147483647 || q.j * q.sign < -2147483648)
		printerror("Error\n");
	return (q.j * q.sign);
}

void	check_dup(int c, int *array)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (array[i] == array[i + 1])
			printerror("Error\n");
		i++;
	}
}

int	check_srt(t_list **a)
{
	while ((*a)->next)
	{
		if ((*a)->content > (*a)->next->content)
			return (0);
		(*a) = (*a)->next;
	}
	return (1);
}

void	creat_stack(t_list **a, t_ps *index)
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

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*tm;
	t_ps	index;

	b = NULL;
	if (ac > 1)
	{
		paramsum(ac, av, &index);
		index.tab = param(ac, av, &index);
		index.tabsorted = param(ac, av, &index);
		index.tabsorted = sorting_array(index.tabsorted, index.count);
		check_dup(index.count, index.tabsorted);
		creat_stack(&a, &index);
		tm = a;
		if (check_srt(&tm) == 1)
			exit(0);
		elements(&index);
		if (index.count == 3)
			a = sorthree(&a, &index);
		else if (index.count <= 5)
			sortfive(&a, &b, &index);
		else if (index.count > 5)
			help(a, b, index);
	}
}
