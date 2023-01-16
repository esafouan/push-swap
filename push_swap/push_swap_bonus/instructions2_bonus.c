/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:05:34 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/14 18:07:45 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	printerror(char *str)
{
	printf("%s", str);
	exit(0);
}

void	pb(t_list **a, t_list **b)
{
	if ((*a))
	{
		ft_lstadd_front(b, ft_lstnew((*a)->content));
		free(*a);
		*a = (*a)->next;
		write(1, "pb\n", 3);
	}
}

void	pa(t_list **a, t_list **b)
{
	if ((*b))
	{
		ft_lstadd_front(a, ft_lstnew((*b)->content));
		free(*b);
		(*b) = (*b)->next;
		write(1, "pa\n", 3);
	}
}

void	rra(t_list **a)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp1 = *a;
	if (*a != NULL && (*a)->next != NULL)
	{
		while (tmp1)
		{
			if (tmp1->next->next == NULL)
				break ;
			tmp1 = tmp1->next;
		}
		tmp = ft_lstlast(*a);
		tmp1->next = NULL;
		tmp->next = *a;
		*a = tmp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **b)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp1 = *b;
	if (*b != NULL && (*b)->next != NULL)
	{
		while (tmp1)
		{
			if (tmp1->next->next == NULL)
				break ;
			tmp1 = tmp1->next;
		}
		tmp = ft_lstlast(*b);
		tmp1->next = NULL;
		tmp->next = *b;
		*b = tmp;
		write(1, "rrb\n", 4);
	}
}
