/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:38:24 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/18 21:04:48 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	prerror(char *str)
{
	printf("%s", str);
	exit(0);
}

int	ft_atoii(char *str)
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
		prerror("Error\n");
	while (str && str[q.i])
	{
		if (!(str[q.i] <= '9' && str[q.i] >= '0'))
			prerror("Error\n");
		q.j = q.j * 10 + str[q.i] - 48;
		q.i++;
	}
	if (q.j * q.sign > 2147483647 || q.j * q.sign < -2147483648)
		prerror("Error\n");
	return (q.j * q.sign);
}

void	read_instruction(int fd, t_list **a, t_list **b)
{
	char	*gnl;

	gnl = get_next_line(fd);
	while (gnl != NULL)
	{
		do_instructions(gnl, a, b);
		free(gnl);
		gnl = get_next_line(fd);
	}
}

void	check_sort(t_list **a, t_list **b)
{
	if ((*a))
	{
		while ((*a)->next)
		{
			if ((*a)->content > (*a)->next->content)
			{
				write(1, "KO\n", 3);
				exit(0);
			}
			(*a) = (*a)->next;
		}
		if (ft_lstsize((*b)) == 0)
		{
			write(1, "OK\n", 3);
			exit(0);
		}
		else
		{
			write(1, "KO\n", 3);
			exit(0);
		}
	}
	write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;
	t_checker	index;

	b = NULL;
	if (ac == 1)
		exit(0);
	numofparam(ac, av, &index);
	index.tab = transfer_para(ac, av, &index);
	index.tabsorted = transfer_para(ac, av, &index);
	index.tabsorted = sorting_array(index.tabsorted, index.count);
	check_duplicate(index.count, index.tabsorted);
	make_stack(&a, &index);
	read_instruction(0, &a, &b);
	check_sort(&a, &b);
}
