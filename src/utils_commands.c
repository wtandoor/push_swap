#include "push_swap.h"

void	pa_pb_add(char **fin, int pa, int pb, int x)
{
	if (pa > pb)
		x = pa - pb;
	else
		x = 0;
	while (x-- > 0)
		*fin = add_to_string(*fin, "pa\n");
	if (pa < pb)
		x = pa - pb;
	else
		x = 0;
	while (x-- > 0)
		*fin = add_to_string(*fin, "pb\n");
}

void	ra_rra_add(char **fin, int ra, int rra, int x)
{
	if (ra > rra)
		x = ra - rra;
	else
		x = 0;
	while (x-- > 0)
		*fin = add_to_string(*fin, "ra\n");
	if (ra < rra)
		x = rra - ra;
	else
		x = 0;
	while (x-- > 0)
		*fin = add_to_string(*fin, "rra\n");
}

void	rb_rrb_add(char **fin, int rb, int rrb, int x)
{
	if (rb > rrb)
		x = rb - rrb;
	else
		x = 0;
	while (x-- > 0)
		*fin = add_to_string(*fin, "rb\n");
	if (rb < rrb)
		x = rrb - rb;
	else
		x = 0;
	while (x-- > 0)
		*fin = add_to_string(*fin, "rrb\n");
}

void	global_sort_utils(t_stack **stack_a,
	t_stack **stack_b, t_com **final, int len)
{
	if ((*stack_a)->dif == 1)
		global_sort(stack_b, stack_a, final, len / 2);
	else
		global_sort(stack_b, stack_a, final, len - len / 2);
	if ((*stack_a)->dif == 1)
		push_back(stack_a, stack_b, final, len / 2);
	else
		push_back(stack_a, stack_b, final, len - len / 2);
}
