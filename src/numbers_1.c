#include "push_swap.h"

void	sixth(t_stack **stack, t_com **final)
{
	rrab(stack);
	sab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "rra\nsa\n");
	else
		(*final)->result = add_to_string((*final)->result, "rrb\nsb\n");
}

void	seventh(t_stack **stack, t_com **final)
{
	rab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\n");
}

void	eight(t_stack **stack, t_com **final)
{
	rrab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "rra\n");
	else
		(*final)->result = add_to_string((*final)->result, "rrb\n");
}

void	nineth(t_stack **stack, t_com **final)
{
	rab(stack);
	sab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\nsa\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\nsb\n");
}
