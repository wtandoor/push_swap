#include "push_swap.h"

int	create_a(t_stack **stack_a, t_com **final, int len)
{
	int	result;

	if ((*stack_a)->dif == 1)
	{
		(*final)->rotation = 1;
		result = len - len / 2;
	}
	else
		result = len / 2;
	return (result);
}

int	create_b(t_stack **stack_a, t_com **final, int len)
{
	int	result;

	if ((*stack_a)->dif == 1)
	{
		(*final)->rotation = 1;
		result = len / 2;
	}
	else
		result = len - len / 2;
	return (result);
}

int	*create_array(t_stack *stack, int len)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		array[i] = stack->n;
		stack = stack->next;
		i++;
	}
	return (array);
}
