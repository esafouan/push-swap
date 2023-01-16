/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:02:43 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/16 17:59:08 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_list **a)
{
	t_list	*tmp;
	int		x;

	tmp = *a;
	if (*a != NULL && (*a)->next != NULL)
	{
		x = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = x;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **b)
{
	t_list	*tmp;
	int		x;

	tmp = *b;
	if (*b != NULL && (*b)->next != NULL)
	{
		x = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = x;
		write(1, "sb\n", 3);
	}
}

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = ft_lstlast(*a);
		tmp->next = *a;
		tmp1 = (*a)->next;
		(*a)->next = NULL;
		*a = tmp1;
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = ft_lstlast(*b);
		tmp->next = *b;
		tmp1 = (*b)->next;
		(*b)->next = NULL;
		*b = tmp1;
		write(1, "rb\n", 3);
	}
}

void	help(t_list *a, t_list *b, t_ps index)
{
	a_to_b(index.tabsorted, &index, &a, &b);
	b_to_a(&index, &a, &b);
}
