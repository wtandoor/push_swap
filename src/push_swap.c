#include "push_swap.h"

static void	util(t_com *final, t_stack *stack_a)
{
	print_final_result(final->result);
	stack_del(&stack_a);
	free(final);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_com	*final;
	int		len;

	stack_a = place_argv_in_stack(argc, argv);
	if (!stack_a)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	len = stack_len(stack_a);
	stack_b = NULL;
	final = new_final();
	if (len < 4)
	{
		sort_short(&stack_a, len);
		stack_del(&stack_a);
		return (0);
	}
	else
		global_sort(&stack_a, &stack_b, &final, len);
	util(final, stack_a);
	return (0);
}
