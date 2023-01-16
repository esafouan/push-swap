/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:09:48 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/14 18:17:30 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	get_max(t_list **a)
{
	int		min;
	t_list	*tmp;

	tmp = *a;
	min = find_min(a);
	while (tmp)
	{
		if (tmp->content > min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	max_index(t_list **a)
{
	t_list	*tmp;
	int		max;
	int		i;

	max = get_max(a);
	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->content == max)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	check_head_b(t_list **b, t_list **a, t_ps *p, void (*cmp)(t_list **))
{
	if ((*b)->content == p->tabsorted[p->count - 1])
	{
		pa(a, b);
		p->next_max = 1;
	}
	else
		cmp(b);
}

void	sortfive(t_list **a, t_list **b, t_ps *p)
{
	while (p->count > 3)
	{
		p->min = find_min(a);
		p->indexmin = min_index(a, p->min);
		while ((*a)->content != p->min && p->indexmin <= (ft_lstsize(*a) / 2))
			ra(a);
		while ((*a)->content != p->min && p->indexmin > (ft_lstsize(*a) / 2))
			rra(a);
		pb(a, b);
		p->count--;
	}
	p->indexation = max_index(a);
	sorthree(a, p);
	while (*b)
		pa(a, b);
}

void	b_to_a(t_ps *p, t_list **a, t_list **b)
{
	int	size;

	p->next_max = 0;
	p->count -= 1;
	while (*b)
	{
		p->max = get_max(b);
		p->indexation = max_index(b);
		size = ft_lstsize(*b) / 2;
		if (p->indexation == 0)
		{
			pa(a, b);
			p->count -= 1;
			if (p->next_max == 1)
			{
				sa(a);
				p->next_max = 0;
				p->count -= 1;
			}
		}
		else if (p->indexation < size)
			check_head_b(b, a, p, rb);
		else if (p->indexation >= size)
			check_head_b(b, a, p, rrb);
	}
}
