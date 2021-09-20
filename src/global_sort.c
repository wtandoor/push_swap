#include "push_swap.h"

void	global_sort(t_stack **stack_a,
	t_stack **stack_b, t_com **final, int len)
{
	int	rot;

	if (len == 2 || len == 3)
		return ;
	if ((*stack_a)->dif == 1)
		rot = div_stack_a(stack_a, stack_b, final, len);
	else
		rot = div_stack_b(stack_a, stack_b, final, len);
	if ((*final)->rotation == 1)
		rotate_back(stack_a, final, rot);
	if (((*stack_a)->dif == 1) && (len / 2 == 3 || len / 2 == 2))
		elements_swap(stack_a, stack_b, final, len);
	else if (((*stack_a)->dif == 2) && (len / 2 == 3 || len / 2 == 2))
		elements_swap(stack_a, stack_b, final, len);
	if ((*stack_a)->dif != 1)
		global_sort(stack_a, stack_b, final, len / 2);
	else
		global_sort(stack_a, stack_b, final, len - len / 2);
	global_sort_utils(stack_a, stack_b, final, len);
}

int	add_others(char **temp, char **fin, int i)
{
	while (temp[i] && !(scmp(temp[i], "pa") || scmp(temp[i], "pb")
			|| scmp(temp[i], "ra") || scmp(temp[i], "rb")
			|| scmp(temp[i], "rra") || scmp(temp[i], "rrb")))
	{
		*fin = add_to_string(*fin, temp[i]);
		*fin = add_to_string(*fin, "\n");
		i++;
	}
	return (i);
}

int	add_pa_pb(char **str, char **fin, int i)
{
	int	pa;
	int	pb;
	int	x;

	pa = 0;
	pb = 0;
	x = 0;
	while (str[i] && (scmp(str[i], "pa") || scmp(str[i], "pb")))
	{
		if (scmp(str[i], "pa"))
			pa++;
		if (scmp(str[i], "pb"))
			pb++;
		i++;
	}
	pa_pb_add(fin, pa, pb, x);
	return (i);
}

int	add_ra_rra(char **str, char **fin, int i)
{
	int	ra;
	int	rra;
	int	x;

	ra = 0;
	rra = 0;
	x = 0;
	while (str[i] && (scmp(str[i], "ra") || scmp(str[i], "rra")))
	{
		if (scmp(str[i], "ra"))
			ra++;
		if (scmp(str[i], "rra"))
			rra++;
		i++;
	}
	ra_rra_add(fin, ra, rra, x);
	return (i);
}

int	add_rb_rrb(char **str, char **fin, int i)
{
	int	rb;
	int	rrb;
	int	x;

	rb = 0;
	rrb = 0;
	x = 0;
	while (str[i] && (scmp(str[i], "rb") || scmp(str[i], "rrb")))
	{
		if (scmp(str[i], "rb"))
			rb++;
		if (scmp(str[i], "rrb"))
			rrb++;
		i++;
	}
	rb_rrb_add(fin, rb, rrb, x);
	return (i);
}
