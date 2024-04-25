/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:02:43 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/16 17:53:00 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	int		x;

	if (*a != NULL && (*a)->next != NULL)
	{
		x = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = x;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **b)
{
	int		x;

	if (*b != NULL && (*b)->next != NULL)
	{
		x = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = x;
		write(1, "sb\n", 3);
	}
}

void	ra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp1;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp1 = (*a)->next;
		tmp = ft_lstlast(*a);
		tmp->next = *a;
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
		tmp1 = (*b)->next;
		tmp = ft_lstlast(*b);
		tmp->next = *b;
		(*b)->next = NULL;
		*b = tmp1;
		write(1, "rb\n", 3);
	}
}
