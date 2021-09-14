#include "push_swap.h"
//1st file

int stack_rotation(t_stack **stack, t_com **final, int rot)
{
	rab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\n");
	rot++;
	return(rot);
}

int div_stack_a(t_stack **stack_a, t_stack **stack_b, t_com **final, int len)
{
	int rot;
	int mid;
	t_stack *tmp;
	int part;

	part = len / 2;
	tmp = *stack_a;
	rot = 0;
	mid = find_mid(*stack_a, len);
	while (tmp && part >= 0)
	{
		if (((*stack_a)->dif == 1 && tmp->n < mid) || ((*stack_a)->dif == 2 && tmp->n <= mid))
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

int stack_push(t_stack **stack_a, t_stack **stack_b, t_com **final, int part)
{
	if ((*stack_a)->dif == 1)
		(*stack_a)->dif = 2;
	else
		(*stack_a)->dif == 1;
	pab(stack_b, stack_a);
	if ((*stack_a)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "pb\n");
	else
		(*final)->result = add_to_string((*final)->result, "pa\n");
	part--;
	return(part);
}

int div_stack_b(t_stack **stack_a, t_stack **stack_b, t_com **final, int len)
{
	int rot;
	int mid;
	t_stack *tmp;
	int part;

	part = len - len / 2;
	tmp = *stack_a;
	rot = 0;
	mid = find_mid(*stack_a, len);
	while (tmp && part >= 0)
	{
		if (((*stack_a)->dif == 1 && tmp->n < mid) || ((*stack_a)->dif == 2 && tmp->n <= mid))
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

void stack_del(t_stack **stack)
{
	t_stack *del;
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*stack = NULL;
}

t_stack	*create_new(void)
{
	t_stack	*first;

	first = (t_stack*)malloc(sizeof(t_stack));
	first->n = 0;
	first->dif = 1;
	first->next = NULL;
	return (first);
}

t_stack *place_argv_in_stack(int argc, char **argv)
{
	int i;
	t_stack *temp;
	t_stack *first;

	i = 1;
	first = create_new();
	temp = first;
	while (i < argc)
	{
		if (check(argv[i]))
		{
			stack_del(&first);
			return (NULL);
		}
		temp->n = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			temp->next = create_new();
			temp = temp->next;
			temp->dif = 1;
		}
		i++;
	}
	check_second(&first);
	return (first);
}
/////

int stack_len(t_stack *stack)
{
	int len;
	t_stack *tmp;

	len = 0;
	tmp = stack;
	while(tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return(len);
}

void sort_short(t_stack **stack, int len)
{
	if (len == 1)
		return ;
	else if (len == 2 && (*stack)->n > (*stack)->next->n)
		ft_printf("sa\n");
	else if (len == 3)
		sort_three(stack);
	return ;
}

void sort_three(t_stack **stack)
{
	if ((*stack)->n < (*stack)->next->n && (*stack)->next->n < (*stack)->next->next->n)
		return ;
	if ((*stack)->n > (*stack)->next->n && (*stack)->next->n < (*stack)->next->next->n && (*stack)->n < (*stack)->next->next->n)
		ft_printf("sa\n");
	else if ((*stack)->n < (*stack)->next->n && (*stack)->next->n > (*stack)->next->next->n && (*stack)->n < (*stack)->next->next->n)
		ft_printf("rra\nsa\n");
	else if ((*stack)->n > (*stack)->next->n && (*stack)->n > (*stack)->next->next->n && (*stack)->next->n < (*stack)->next->next->n)
		ft_printf("ra\n");
	else if ((*stack)->n < (*stack)->next->n && (*stack)->n > (*stack)->next->next->n && (*stack)->next->n > (*stack)->next->next->n)
		ft_printf("rra\n");
	else if ((*stack)->n > (*stack)->next->n && (*stack)->next->n > (*stack)->next->next->n)
		ft_printf("ra\nsa\n");
}

int create_a(t_stack **stack_a, t_com **final, int len)
{
	int result;
	if ((*stack_a)->dif == 1)
	{
		(*final)->rotation = 1;
		result = len - len / 2;
	}
	else
		result = len / 2;
	return (result);
}

int create_b(t_stack **stack_a, t_com **final, int len)
{
	int result;
	
	if ((*stack_a)->dif == 1)
	{
		(*final)->rotation = 1;
		result = len / 2;
	}
	else
		result = len - len / 2;
	return (result);
}

void swap_2(t_stack **stack, t_com **final)
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

void swap_3(t_stack **stack, t_com **final)
{
	if ((*stack)->dif == 1)
		swap_3_a(stack, final);
	else
		swap_3_b(stack, final);

}

void swap_3_a(t_stack **stack, t_com **fin)
{

}

void swap_3_b(t_stack **stack, t_com **fin)
{

}

void swap_len1_more_2(t_stack **stack_a, t_stack **stack_b, t_com **final, int len)
{
	int len1;
	int len2;

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

void swap_len1_2(t_stack **stack_a, t_stack **stack_b, t_com **final, int len)
{
	int len1;
	int len2;

	len1 = create_a(stack_a, final, len);
	len2 = create_b(stack_a, final, len);
	if (len1 == 2 && (!(*stack_a) || stack_len(stack_a) < 2))
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



void elements_swap(t_stack **stack_a, t_stack  **stack_b, t_com **final, int len)
{
	int len1;

	len1 = create_a(stack_a, final, len);
	if (len1 == 2)
		swap_len1_2(stack_a, stack_b, final, len);
	else if (len1 > 2)
		swap_len1_more_2(stack_a, stack_b, final, len);
}

void global_sort(t_stack **stack_a, t_stack **stack_b, t_com **final, int len)
{
	int rot;

	if ((*stack_a)->dif == 1)
		rot = div_stack_a(stack_a, stack_b, final, len); //здесь остановился
	else
		rot = div_stack_b(stack_a, stack_b, final, len);
	if ((*final)->rotation == 1)
		rotate_back(stack_a, final, rot);
	if (((*stack_a)->dif == 1) && (len / 2 == 3 || len / 2 == 2))
		elements_swap(stack_a, stack_b, final, len);
	else if ((*stack_a)->dif == 2 && (len / 2 == 3 || len / 2 == 2))
		elements_swap(stack_a, stack_b, final, len);
	if ((*stack_a)->dif != 1)
		global_sort(stack_a, stack_b, final, len / 2);
	else
		global_sort(stack_a, stack_b, final, len - len / 2);
	if ((*stack_a)->dif == 1)
		global_sort(stack_b, stack_a, final, len / 2);
	else
		global_sort(stack_b, stack_a, final, len - len / 2);
	if ((*stack_a)->dif == 1)
		push_back(stack_a, stack_b, final, len / 2);
	else
		push_back(stack_a, stack_b, final, len - len / 2);
}

t_com *new_final(void)
{
	t_com *new;
	int i;

	i = 0;
	new = (t_com*)malloc(sizeof(t_com));
	new->rotation = 0;
	new->result = ft_strdup("\0");
	return (new);
}

int ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return(1);
	return (0);
}

void ft_delete_string(char **str)
{
	if (str == NULL)
		return ;
	free(*str);
	*str = NULL;
}

void free_memory(char **tmp, char **str1, char **result )
{
	int i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	ft_delete_string(str1);
	ft_delete_string(result);
}

int sa(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmpnext;

	if ((*stack)->next == NULL)
		return(0);
	else
	{
		tmp = stack;
		tmpnext = (*stack)->next;
		(*stack) = tmpnext;
		(*stack)->next = tmp;
	}
	return(0);
}

int ss(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	
	i = sa(stack_a);
	i = sb(stack_b);
	return (i);
}

void	ft_swap_elem(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int sab(t_stack **first)
{
	t_stack *stack;

	stack = *first;
	if (stack && stack->next)
		ft_swap_elem(&stack->n, &stack->next->n);
	return (0);
}

int pab(t_stack **first_to, t_stack **first_from)
{
	t_stack *temp;
	t_stack *temp_to;
	t_stack *temp_from;

	temp_to = *first_to;
	temp_from = *first_from;
	if (!temp_from)
		return(0);
	temp = temp_from;
	temp_from = temp_from->next;
	*first_from = temp_from;
	if (!temp_to)
	{
		temp_to = temp;
		temp_to->next = NULL;
		*first_to = temp_to;
	}
	else
	{
		temp->next = temp_to;
		*first_to = temp;
	}
	return (0);
}

int rr(t_stack **stack_a, t_stack **stack_b)
{
	rab(stack_a);
	rab(stack_b);
	return (0);
}

int rab(t_stack **first)
{
	t_stack *temp_first;
	t_stack *temp_last;
	t_stack *stack;

	stack = *first;
	if (!(stack && stack->next))
		return (0);
	temp_first = stack;
	stack = stack->next;
	temp_last = stack;
	while (temp_last->next)
		temp_last = temp_last->next;
	temp_last->next = temp_first;
	temp_first->next = NULL;
	*first = stack;
	return(0);
}

int rrab(t_stack **first)
{
	t_stack *temp_last;
	t_stack *prev;
	t_stack *stack;

	stack = *first;
	if (!(stack && stack->next))
		return (0);
	temp_last = stack;
	while (temp_last->next)
	{
		prev = temp_last;
		temp_last = temp_last->next;
	}
	temp_last->next = stack;
	prev->next = NULL;
	*first = temp_last;
	return (0);	
}

int rrr(t_stack **stack_a, t_stack *stack_b)
{
	rrab(stack_a);
	rrab(stack_b);
	return (0);
}

int sb(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmpnext;

	if ((*stack)->next == NULL)
		return(0);
	else
	{
		tmp = stack;
		tmpnext = (*stack)->next;
		(*stack) = tmpnext;
		(*stack)->next = tmp;
	}
	return(0);
}

void print_final_result(char *str1)
{
	char **tmp;
	char *result;
	int i;

	i = 0;
	result = ft_strdup("\0");
	tmp = ft_split(str1, "\n");
	while(tmp[i])
	{
		if ((tmp[i]) && (ft_strcmp(tmp[i], "pa") == 1 || ft_strcmp(tmp[i], "pb") == 1))
			i = add_pa_pb(tmp, &result, i);
		if ((tmp[i]) && (ft_strcmp(tmp[i], "ra") == 1 || ft_strcmp(tmp[i], "rra")))
			i = add_ra_rra(tmp, &result, i);
		if ((tmp[i]) && (ft_strcmp(tmp[i], "rb") == 1 || ft_strcmp(tmp[i], "rrb")))
			i = add_rb_rrb(tmp, &result, i);
		if ((tmp[i]) && !(ft_strcmp(tmp[i], "pa") == 1 || ft_strcmp(tmp[i], "pb") == 1 || ft_strcmp(tmp[i], "ra") == 1 || ft_strcmp(tmp[i], "rra") || ft_strcmp(tmp[i], "rb") == 1 || ft_strcmp(tmp[i], "rrb")))
			i = add_other(tmp, &result, i);
	}
	ft_printf("%s", result);
	free_memory(tmp, &str1, &result);
}

void first(t_stack **stack, t_com **final)
{
	sab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "sa\n");
	else
		(*final)->result = add_to_string((*final)->result, "sb\n");
}

void second(t_stack **stack, t_com **final)
{
	rab(stack);
	sab(stack);
	rrab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\nsa\nrra\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\nsa\nrra\n");
}

void third(t_stack **stack, t_com **final)
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

void forth(t_stack **stack, t_com **final)
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

void fifth(t_stack **stack, t_com **final)
{
	
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_com	*final;
	int len;

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
		return(0);
	}
	else
		global_sort(&stack_a, &stack_b, &final, len);
	print_final_result(final->result);
	stack_del(&stack_a);
	free(final);
	return (0);
}