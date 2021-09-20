#include "push_swap.h"

int	part(int *stack, int start, int end)
{
	int	end_v;
	int	currency;
	int	str_index;

	end_v = stack[end];
	str_index = start - 1;
	currency = start;
	while (currency <= end - 1)
	{
		if (stack[currency] <= end_v)
		{
			str_index++;
			ft_swap_elem(&stack[str_index], &stack[currency]);
		}
		currency++;
	}
	ft_swap_elem(&stack[str_index + 1], &stack[end]);
	return (str_index + 1);
}

void	sort_quick(int *stack, int start, int end)
{
	int	*stack1;
	int	top;
	int	base;

	top = -1;
	stack1 = (int *)malloc(sizeof(int) * (end + 1));
	stack1[++top] = start;
	stack1[++top] = end;
	while (top >= 0)
	{
		end = stack1[top--];
		start = stack1[top--];
		base = part(stack, start, end);
		if (base - 1 > start)
		{
			stack1[++top] = start;
			stack1[++top] = base - 1;
		}
		if (base + 1 < end)
		{
			stack1[++top] = base + 1;
			stack1[++top] = end;
		}
	}
	free(stack1);
}

void	swap_len1_more_2(t_stack **stack_a,
t_stack **stack_b, t_com **final, int len)
{
	int	len1;
	int	len2;

	len1 = create_a(stack_a, final, len);
	len2 = create_b(stack_a, final, len);
	if (len1 > 3 && len2 == 2)
		swap_2(stack_b, final);
	else if (len1 == 3 && (!(*stack_a) || stack_len(*stack_a) < 3))
		return ;
	else if (len1 == 3 && (!(stack_b) || stack_len(*stack_b) < 2 || len2 > 3))
		swap_3(stack_a, final);
	else if (len1 == 3 && len2 == 2)
	{
		swap_3(stack_a, final);
		swap_2(stack_b, final);
	}
	else if (len1 == 3 && len2 == 3 && stack_len(*stack_b) > 2)
	{
		swap_3(stack_a, final);
		swap_3(stack_b, final);
	}
	else if (len1 > 3 && len2 == 3)
		swap_3(stack_b, final);
}
