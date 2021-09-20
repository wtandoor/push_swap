#include "push_swap.h"

int	sab(t_stack **first)
{
	t_stack	*stack;

	stack = *first;
	if (stack && stack->next)
		ft_swap_elem(&stack->n, &stack->next->n);
	return (0);
}

int	pab(t_stack **first_to, t_stack **first_from)
{
	t_stack	*temp;
	t_stack	*temp_to;
	t_stack	*temp_from;

	temp_to = *first_to;
	temp_from = *first_from;
	if (!temp_from)
		return (0);
	temp = temp_from;
	temp_from = temp_from->next;
	*first_from = temp_from;
	if (!temp_to)
	{
		temp_to = temp;
		temp_to->next = NULL;
		*first_to = temp_to;
	}
	else
	{
		temp->next = temp_to;
		*first_to = temp;
	}
	return (0);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	rab(stack_a);
	rab(stack_b);
	return (0);
}

int	rab(t_stack **first)
{
	t_stack	*temp_first;
	t_stack	*temp_last;
	t_stack	*stack;

	stack = *first;
	if (!(stack && stack->next))
		return (0);
	temp_first = stack;
	stack = stack->next;
	temp_last = stack;
	while (temp_last->next)
		temp_last = temp_last->next;
	temp_last->next = temp_first;
	temp_first->next = NULL;
	*first = stack;
	return (0);
}

int	rrab(t_stack **first)
{
	t_stack	*temp_last;
	t_stack	*prev;
	t_stack	*stack;

	stack = *first;
	if (!(stack && stack->next))
		return (0);
	temp_last = stack;
	while (temp_last->next)
	{
		prev = temp_last;
		temp_last = temp_last->next;
	}
	temp_last->next = stack;
	prev->next = NULL;
	*first = temp_last;
	return (0);
}
