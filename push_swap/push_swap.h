/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esafouan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:24:47 by esafouan          #+#    #+#             */
/*   Updated: 2023/01/16 17:54:40 by esafouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct atoii
{
	int		i;
	long	j;
	int		sign;
}	t_atoii;

typedef struct help
{
	int		*arr;
	char	**split;
	int		i;
	int		j;
	int		t;
}	t_help;

typedef struct pushswap
{
	int	indexation;
	int	indexmin;
	int	max;
	int	next_max;
	int	min;
	int	count;
	int	midle;
	int	offset;
	int	start;
	int	end;
	int	*tabsorted;
	int	*tab;
}	t_ps;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
char	*free_split(char **split, int len);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		countlen(char const *s1, char c);
int		*param(int a, char **v, t_ps *w);
void	check_dup(int c, int *array);
void	sa(t_list **a);
void	sb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
int		*sorting_array(int *array, int size);
int		find_min(t_list **a);
int		get_max(t_list **a);
int		max_index(t_list **a);
int		min_index(t_list **a, int min);
int		element_index(t_list **a, int start, int end);
void	sort_two(t_list **a);
t_list	*sorthree(t_list **a, t_ps *p);
void	sortfive(t_list **a, t_list **b, t_ps *p);
void	paramsum(int ac, char **av, t_ps *p);
void	elements(t_ps *p);
void	helper(t_list **a, int index, void (*cmp)(t_list **));
void	check_end_start(int end, int start, int count, t_ps *p);
void	a_to_b(int *sorted, t_ps *p, t_list **a, t_list **b);
void	check_head_b(t_list **b, t_list **a, t_ps *p, void (*cmp)(t_list **));
void	b_to_a(t_ps *p, t_list **a, t_list **b);
void	creat_stack(t_list **a, t_ps *index);
void	printerror(char *str);
int		ft_atoi(char *str);
int		check_sort(t_list **a);
void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);
void	check_space(char *str);
void	help(t_list *a, t_list *b, t_ps index);

#endif
