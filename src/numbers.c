#include "push_swap.h"

void	first(t_stack **stack, t_com **final)
{
	sab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "sa\n");
	else
		(*final)->result = add_to_string((*final)->result, "sb\n");
}

void	second(t_stack **stack, t_com **final)
{
	rab(stack);
	sab(stack);
	rrab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\nsa\nrra\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\nsa\nrra\n");
}

void	third(t_stack **stack, t_com **final)
{
	sab(stack);
	rab(stack);
	sab(stack);
	rrab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "sa\nra\nsa\nrra\n");
	else
		(*final)->result = add_to_string((*final)->result, "sb\nrb\nsb\nrrb\n");
}

void	forth(t_stack **stack, t_com **final)
{
	rab(stack);
	sab(stack);
	rrab(stack);
	sab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\nsa\nrra\nsa\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\nsb\nrrb\nsb\n");
}

void	fifth(t_stack **stack, t_com **final)
{
	sab(stack);
	rab(stack);
	sab(stack);
	rrab(stack);
	sab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "sa\nra\nsa\nrra\nsa\n");
	else
		(*final)->result = add_to_string((*final)->result, "sb\nrb\nsb\nrrb\nsb\n");
}
