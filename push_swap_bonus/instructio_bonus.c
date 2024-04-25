/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructio_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:29:38 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/18 21:05:26 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}

void	printerror(char *str)
{
	printf("%s", str);
	exit(0);
}
