#include "push_swap.h"

int	div_stack_a(t_stack **stack_a, t_stack **stack_b, t_com **final, int len)
{
	int		rot;
	int		mid;
	t_stack	*tmp;
	int		part;

	part = len / 2;
	tmp = *stack_a;
	rot = 0;
	mid = find_mid(*stack_a, len);
	while (tmp && part >= 0)
	{
		if (((*stack_a)->dif == 1 && tmp->n < mid)
			|| ((*stack_a)->dif == 2 && tmp->n <= mid))
		{
			while ((*stack_a)->n != tmp->n)
				rot = stack_rotation(stack_a, final, rot);
			tmp = tmp->next;
			part = stack_push(stack_a, stack_b, final, part);
		}
		else
			tmp = tmp->next;
	}
	return (rot);
}

int	div_stack_b(t_stack **stack_a, t_stack **stack_b, t_com **final, int len)
{
	int		rot;
	int		mid;
	t_stack	*tmp;
	int		part;

	part = len - len / 2;
	tmp = *stack_a;
	rot = 0;
	mid = find_mid(*stack_a, len);
	while (tmp && part > 0)
	{
		if (((*stack_a)->dif == 1 && tmp->n > mid)
			|| ((*stack_a)->dif == 2 && tmp->n >= mid))
		{
			while ((*stack_a)->n != tmp->n)
				rot = stack_rotation(stack_a, final, rot);
			tmp = tmp->next;
			part = stack_push(stack_a, stack_b, final, part);
		}
		else
			tmp = tmp->next;
	}
	return (rot);
}

int	stack_rotation(t_stack **stack, t_com **final, int rot)
{
	rab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\n");
	rot++;
	return (rot);
}

int	stack_push(t_stack **stack_a, t_stack **stack_b, t_com **final, int part)
{
	if ((*stack_a)->dif == 1)
		(*stack_a)->dif = 2;
	else
		(*stack_a)->dif = 1;
	pab(stack_b, stack_a);
	if ((*stack_a)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "pb\n");
	else
		(*final)->result = add_to_string((*final)->result, "pa\n");
	part--;
	return (part);
}

int	find_mid(t_stack *stack, int len)
{
	int	*array;
	int	mid;

	if (stack_len(stack) < len)
		len = stack_len(stack);
	array = create_array(stack, len);
	sort_quick(array, 0, len - 1);
	mid = array[len / 2];
	free(array);
	return (mid);
}
