/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:50:15 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/14 17:58:23 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	elements(t_ps *p)
{
	p->midle = (p->count / 2) - 1;
	if (p->count <= 10)
		p->offset = p->count / 5;
	else if (p->count <= 150)
		p->offset = p->count / 8;
	else if (p->count > 150)
		p->offset = p->count / 18;
	p->start = p->midle - p->offset;
	p->end = p->midle + p->offset;
}

void	helper(t_list **a, int index, void (*cmp)(t_list **))
{
	while (index)
	{
		cmp(a);
		index--;
	}
}

int	element_index(t_list **a, int start, int end)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content <= end && tmp->content >= start)
			break ;
		tmp = tmp->next;
		i++;
	}	
	if (tmp->content <= end && tmp->content >= start)
		return (i);
	return (-1);
}

void	check_end_start(int end, int start, int count, t_ps *p)
{
	if (end > count - 1 && start < 0)
	{
		p->end = count - 1;
		p->start = 0;
	}
	else if (end > count - 1)
		p->end = count - 1;
	else if (start < 0)
		p->start = 0;
}

void	a_to_b(int *sorted, t_ps *p, t_list **a, t_list **b)
{
	int	index;

	while ((*a))
	{
		index = element_index(a, sorted[p->start], sorted[p->end]);
		if (index == -1)
		{
			p->end += p->offset;
			p->start -= p->offset;
			check_end_start(p->end, p->start, p->count, p);
		}
		else if (index < p->count / 2)
			helper(a, index, ra);
		else if (index >= p->count / 2)
			helper(a, index, rra);
		if (index != -1)
			pb(a, b);
		if (ft_lstsize(*b) > 1 && (*b)->content <= sorted[p->midle])
			rb(b);
	}
}
