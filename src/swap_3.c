#include "push_swap.h"

void	swap_3(t_stack **stack, t_com **final)
{
	if ((*stack)->dif == 1)
		swap_3_a(stack, final);
	else
		swap_3_b(stack, final);
}

void	swap_3_a(t_stack **stack, t_com **fin)
{
	if ((*stack)->n < (*stack)->next->n
		&& (*stack)->next->n < (*stack)->next->next->n)
		return ;
	if ((*stack)->n > (*stack)->next->n
		&& (*stack)->next->n < (*stack)->next->next->n
		&& (*stack)->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			first(stack, fin);
		else
			swap_2(stack, fin);
	}
	else if ((*stack)->n < (*stack)->next->n
		&& (*stack)->next->n > (*stack)->next->next->n
		&& (*stack)->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			second(stack, fin);
		else
			sixth(stack, fin);
	}
	else
		swap_3_a_add(stack, fin);
}

void	swap_3_a_add(t_stack **s, t_com **fin)
{
	if ((*s)->n > (*s)->next->n && (*s)->n > (*s)->next->next->n
		&& (*s)->next->n < (*s)->next->next->n)
	{
		if (stack_len(*s))
			third(s, fin);
		else
			seventh(s, fin);
	}
	else if ((*s)->n < (*s)->next->n
		&& (*s)->n > (*s)->next->next->n
		&& (*s)->next->n > (*s)->next->next->n)
	{
		if (stack_len(*s) > 3)
			forth(s, fin);
		else
			eight(s, fin);
	}
	else if ((*s)->n > (*s)->next->n
		&& (*s)->next->n > (*s)->next->next->n)
	{
		if (stack_len(*s) > 3)
			fifth(s, fin);
		else
			nineth(s, fin);
	}
}

void	swap_3_b_add(t_stack **s, t_com **fin)
{
	if ((*s)->n < (*s)->next->n && (*s)->next->n
		> (*s)->next->next->n && (*s)->n < (*s)->next->next->n)
	{
		if (stack_len(*s) > 3)
			third(s, fin);
		else
			seventh(s, fin);
	}
	else if ((*s)->n > (*s)->next->n && (*s)->next->n
		< (*s)->next->next->n && (*s)->n < (*s)->next->next->n)
	{
		if (stack_len(*s) > 3)
			forth(s, fin);
		else
			eight(s, fin);
	}
	else if ((*s)->n < (*s)->next->n
		&& (*s)->next->n < (*s)->next->next->n)
	{
		if (stack_len(*s) > 3)
			fifth(s, fin);
		else
			eight(s, fin);
	}
}

void	swap_3_b(t_stack **stack, t_com **fin)
{
	if ((*stack)->n > (*stack)->next->n
		&& (*stack)->next->n > (*stack)->next->next->n)
		return ;
	else if ((*stack)->n < (*stack)->next->n
		&& (*stack)->n > (*stack)->next->next->n
		&& (*stack)->next->n > (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			first(stack, fin);
		else
			swap_2(stack, fin);
	}
	else if ((*stack)->n > (*stack)->next->n
		&& (*stack)->n > (*stack)->next->next->n
		&& (*stack)->next->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			second(stack, fin);
		else
			sixth(stack, fin);
	}
	else
		swap_3_b_add(stack, fin);
}
