/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:38:24 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/16 17:29:08 by esafouan         ###   ########.fr       */
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
		gnl = get_next_line(fd);
	}
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
	if (check_sort(&a) == 0)
		printf("KO\n");
	else if (check_sort(&a) == 1)
		printf("OK\n");
}
