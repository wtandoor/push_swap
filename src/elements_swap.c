#include "push_swap.h"

void	elements_swap(t_stack **stack_a,
	t_stack **stack_b, t_com **final, int len)
{
	int	len1;

	len1 = create_a(stack_a, final, len);
	if (len1 == 2)
		swap_len1_2(stack_a, stack_b, final, len);
	else if (len1 > 2)
		swap_len1_more_2(stack_a, stack_b, final, len);
}

void	swap_2(t_stack **stack, t_com **final)
{
	if ((*stack)->dif == 1 && ((*stack)->n > (*stack)->next->n))
	{
		sab(stack);
		(*final)->result = add_to_string((*final)->result, "sa\n");
	}
	else if ((*stack)->dif == 2 && ((*stack)->n < (*stack)->next->n))
	{
		sab(stack);
		(*final)->result = add_to_string((*final)->result, "sb\n");
	}
}

void	swap_len1_2(t_stack **stack_a,
	t_stack **stack_b, t_com **final, int len)
{
	int	len1;
	int	len2;

	len1 = create_a(stack_a, final, len);
	len2 = create_b(stack_a, final, len);
	if (len1 == 2 && (!(*stack_a) || stack_len(*stack_a) < 2))
		return ;
	else if (len1 == 2 && (!(*stack_b) || stack_len(*stack_b) < 2 || len2 > 3))
		swap_2(stack_a, final);
	else if (len1 == 2 && len2 == 2)
	{
		swap_2(stack_a, final);
		swap_2(stack_b, final);
	}
	else if (len1 == 2 && len2 == 3 && stack_len(*stack_b) > 2)
	{
		swap_2(stack_a, final);
		swap_3(stack_b, final);
	}
}

void	rotate_back(t_stack **stack, t_com **final, int rot)
{
	if (stack_len(*stack) == 2)
	{
		swap_2(stack, final);
		return ;
	}
	if (stack_len(*stack) == 3)
	{
		swap_3(stack, final);
		return ;
	}
	while (rot != 0)
	{
		rrab(stack);
		if ((*stack)->dif == 1)
			(*final)->result = add_to_string((*final)->result, "rra\n");
		else
			(*final)->result = add_to_string((*final)->result, "rrb\n");
		rot--;
	}
}

void	push_back(t_stack **stack_a, t_stack **stack_b, t_com **final, int part)
{
	while (part > 0)
	{
		if ((*stack_b)->dif == 1)
			(*stack_b)->dif = 2;
		else
			(*stack_b)->dif = 1;
		pab(stack_a, stack_b);
		if ((*stack_a)->dif == 2)
			(*final)->result = add_to_string((*final)->result, "pb\n");
		else
			(*final)->result = add_to_string((*final)->result, "pa\n");
		part--;
	}
}
