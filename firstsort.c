/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:16:09 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/14 22:17:16 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **a)
{
	int		min;
	t_list	*tmp;

	tmp = *a;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	min_index(t_list **a, int min)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->content == min)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sort_two(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	threehelp(t_list **a, t_ps *p)
{
	if (p->indexation == 2 && (*a)->content > (*a)->next->content)
		sa(a);
	else if (p->indexation == 1
		&& (*a)->content > (*a)->next->next->content)
		rra(a);
	else if (p->indexation == 1
		&& (*a)->content < (*a)->next->next->content)
	{
		sa(a);
		ra(a);
	}
	else if (p->indexation == 0
		&& (*a)->next->content > (*a)->next->next->content)
	{
		ra(a);
		sa(a);
	}
	else if (p->indexation == 0
		&& (*a)->next->content < (*a)->next->next->content)
		ra(a);
}

t_list	*sorthree(t_list **a, t_ps *p)
{
	p->indexation = max_index(a);
	if (p->count == 2)
		sort_two(a);
	if (p->count == 3)
		threehelp(a, p);
	return (*a);
}
