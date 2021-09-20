#include "push_swap.h"

t_com	*new_final(void)
{
	t_com	*new;
	int		i;

	i = 0;
	new = (t_com *)malloc(sizeof(t_com));
	new->rotation = 0;
	new->result = ft_strdup("\0");
	return (new);
}

void	ft_swap_elem(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrab(stack_a);
	rrab(stack_b);
	return (0);
}

void	print_final_result(char *str1)
{
	char	**tmp;
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup("\0");
	tmp = ft_split(str1, '\n');
	while (tmp[i])
	{
		if ((tmp[i]) && (scmp(tmp[i], "pa") == 1
				|| scmp(tmp[i], "pb") == 1))
			i = add_pa_pb(tmp, &result, i);
		if ((tmp[i]) && (scmp(tmp[i], "ra") == 1
				|| scmp(tmp[i], "rra")))
			i = add_ra_rra(tmp, &result, i);
		if ((tmp[i]) && (scmp(tmp[i], "rb") == 1
				|| scmp(tmp[i], "rrb")))
			i = add_rb_rrb(tmp, &result, i);
		if ((tmp[i]) && !(scmp(tmp[i], "pa") == 1 || scmp(tmp[i], "pb") == 1
				|| scmp(tmp[i], "ra") == 1 || scmp(tmp[i], "rra")
				|| scmp(tmp[i], "rb") == 1 || scmp(tmp[i], "rrb")))
			i = add_others(tmp, &result, i);
	}
	ft_printf("%s", result);
	free_memory(tmp, &str1, &result);
}

char	*add_to_string(char *str, char *str1)
{
	char	*rem;

	rem = str;
	str = ft_strjoin(str, str1);
	ft_delete_string(&rem);
	return (str);
}
