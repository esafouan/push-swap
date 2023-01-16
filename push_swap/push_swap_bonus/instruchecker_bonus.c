/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:05:34 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/16 16:29:01 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_list **a, t_list **b)
{
	if ((*b) == NULL && ft_lstsize((*a)) == 1)
		return ;
	if ((*a))
	{
		ft_lstadd_front(b, ft_lstnew((*a)->content));
		free(*a);
		*a = (*a)->next;
	}
}

void	pa(t_list **a, t_list **b)
{
	if ((*b))
	{
		ft_lstadd_front(a, ft_lstnew((*b)->content));
		free(*b);
		(*b) = (*b)->next;
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
	}
}

void	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == 32)
		i++;
	if (i == ft_strlen(str))
		printerror("Error\n");
}
