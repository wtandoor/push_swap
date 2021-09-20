#include "push_swap.h"

void	sort_short(t_stack **stack, int len)
{
	if (len == 1)
		return ;
	else if (len == 2 && (*stack)->n > (*stack)->next->n)
		ft_printf("sa\n");
	else if (len == 3)
		sort_three(stack);
	return ;
}

void	sort_three(t_stack **s)
{
	if ((*s)->n < (*s)->next->n
		&& (*s)->next->n < (*s)->next->next->n)
		return ;
	if ((*s)->n > (*s)->next->n && (*s)->next->n
		< (*s)->next->next->n && (*s)->n < (*s)->next->next->n)
		ft_printf("sa\n");
	else if ((*s)->n < (*s)->next->n && (*s)->next->n
		> (*s)->next->next->n && (*s)->n < (*s)->next->next->n)
		ft_printf("rra\nsa\n");
	else if ((*s)->n > (*s)->next->n && (*s)->n
		> (*s)->next->next->n && (*s)->next->n < (*s)->next->next->n)
		ft_printf("ra\n");
	else if ((*s)->n < (*s)->next->n && (*s)->n
		> (*s)->next->next->n && (*s)->next->n > (*s)->next->next->n)
		ft_printf("rra\n");
	else if ((*s)->n > (*s)->next->n
		&& (*s)->next->n > (*s)->next->next->n)
		ft_printf("ra\nsa\n");
}
