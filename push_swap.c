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
		(*stack_a)->dif = 1;
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

t_stack	*create_new(void)//complete
{
	t_stack	*first;

	first = (t_stack*)malloc(sizeof(t_stack));
	first->n = 0;
	first->dif = 1;
	first->next = NULL;
	return (first);
}

t_stack *place_argv_in_stack(int argc, char **argv)//complete
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

int check(char *argv)
{
	int i;
	int len;

	i = 0;
	if (argv[i] == '-' && !ft_isdigit(argv[i + 1]))//podozritelno
		return (1);
	if (argv[i] == '-' && ft_isdigit(argv[i + 1]))
		i++;
	len = ft_strlen(&argv[i]);
	if (len > 10)
		return (1);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	if (len == 10 && check_overflow(argv))
		return (1);
	return (0);
}

int check_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return(1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

void check_second(t_stack **stack)
{
	int *array;
	int len;
	int i;

	i = 0;
	len = stack_len(*stack);
	array = create_array(*stack, len);
	sort_quick(array, 0, len - 1);
	while (i < len - 1)
	{
		if (array[i] >= array[i + 1])
		{
			stack_del(stack);
			free(array);
			return ;
		}
		i++;
	}
	free(array);
}

int stack_len(t_stack *stack)//complete
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

void sort_short(t_stack **stack, int len)//complete
{
	if (len == 1)
		return ;
	else if (len == 2 && (*stack)->n > (*stack)->next->n)
		ft_printf("sa\n");
	else if (len == 3)
		sort_three(stack);
	return ;
}

void sort_three(t_stack **stack)//complete
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
	if ((*stack)->n < (*stack)->next->n && (*stack)->next->n < (*stack)->next->next->n)
		return ;
	if ((*stack)->n > (*stack)->next->n && (*stack)->next->n < (*stack)->next->next->n && (*stack)->n < (*stack)->next->next->n)
	{
		if(stack_len(*stack) > 3)
			first(stack, fin);
		else
			swap_2(stack, fin);
	}
	else if ((*stack)->n < (*stack)->next->n && (*stack)->next->n > (*stack)->next->next->n && (*stack)->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			second(stack, fin);
		else
			sixth(stack, fin);
	}
	else if ((*stack)->n > (*stack)->next->n && (*stack)->n > (*stack)->next->next->n && (*stack)->next->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack))
			third(stack, fin);
		else
			seventh(stack, fin);
	}
	else
		swap_3_a_add(stack, fin);
}

void swap_3_a_add(t_stack **stack, t_com **fin)
{
	if ((*stack)->n < (*stack)->next->n && (*stack)->n > (*stack)->next->next->n && (*stack)->next->n > (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			forth(stack, fin);
		else
			eight(stack, fin);
	}
	else if ((*stack)->n > (*stack)->next->n && (*stack)->next->n > (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			fifth(stack, fin);
		else
			nineth(stack, fin);
	}
}

void swap_3_b_add(t_stack **stack, t_com **fin)
{
	if ((*stack)->n > (*stack)->next->n && (*stack)->next->n < (*stack)->next->next->n && (*stack)->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			forth(stack, fin);
		else
			eight(stack, fin);
	}
	else if ((*stack)->n < (*stack)->next->n && (*stack)->next->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			fifth(stack, fin);
		else
			eight(stack, fin);
	}
}

void swap_3_b(t_stack **stack, t_com **fin)
{
	if ((*stack)->n > (*stack)->next->n && (*stack)->next->n > (*stack)->next->next->n)
		return ;
	else if ((*stack)->n < (*stack)->next->n && (*stack)->n > (*stack)->next->next->n && (*stack)->next->n > (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			first(stack, fin);
		else
			swap_2(stack, fin);
	}
	else if ((*stack)->n > (*stack)->next->n && (*stack)->n > (*stack)->next->next->n && (*stack)->next->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			second(stack, fin);
		else
			sixth(stack, fin);
	}
	else if ((*stack)->n < (*stack)->next->n && (*stack)->next->n > (*stack)->next->next->n && (*stack)->n < (*stack)->next->next->n)
	{
		if (stack_len(*stack) > 3)
			third(stack, fin);
		else
			seventh(stack, fin);
	}
	else
		swap_3_b_add(stack, fin);
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
	if (len1 == 2 && (!(*stack_a) || stack_len(*stack_a) < 2))
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

void rotate_back(t_stack **stack, t_com **final, int rot)
{
	if (stack_len(*stack) == 2)
	{
		swap_2(stack, final);
		return ;
	}
	if (stack_len(*stack) == 3)
	{
		swap_3(stack, final);
		return ;
	}
	while (rot != 0)
	{
		rrab(stack);
		if ((*stack)->dif == 1)
			(*final)->result = add_to_string((*final)->result, "rra\n");
		else
			(*final)->result = add_to_string((*final)->result, "rrb\n");
		rot--;
	}
}

void push_back(t_stack **stack_a, t_stack **stack_b, t_com **final, int part)
{
	while (part > 0)
	{
		if ((*stack_b)->dif == 1)
			(*stack_b)->dif = 2;
		else
			(*stack_b)->dif = 1;
		pab(stack_a, stack_b);
		if ((*stack_a)->dif == 2)
			(*final)->result = add_to_string((*final)->result, "pb\n");
		else
			(*final)->result = add_to_string((*final)->result, "pa\n");
		part--;
	}
}

void global_sort(t_stack **stack_a, t_stack **stack_b, t_com **final, int len)//complete
{
	int rot;

	if (len == 2 || len == 3)
		return ;
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

void	ft_swap_elem(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int add_pa_pb(char **str, char **fin, int i)
{
	int pa;
	int pb;
	int x;

	pa = 0;
	pb = 0;
	x = 0;
	while (str[i] && (ft_strcmp(str[i], "pa") || ft_strcmp(str[i], "pb")))
	{
		if (ft_strcmp(str[i], "pa"))
			pa++;
		if (ft_strcmp(str[i], "pb"))
			pb++;
		i++;
	}
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
	return (i);
}

int add_ra_rra(char **str, char **fin, int i)
{
	int ra;
	int rra;
	int x;

	ra = 0;
	rra = 0;
	x = 0;
	while (str[i] && (ft_strcmp(str[i], "ra") || ft_strcmp(str[i], "rra")))
	{
		if (ft_strcmp(str[i], "ra"))
			ra++;
		if (ft_strcmp(str[i], "rra"))
			rra++;
		i++;
	}
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
	return (i);
}

int add_rb_rrb(char **str, char **fin, int i)
{
	int rb;
	int rrb;
	int x;

	rb = 0;
	rrb = 0;
	x = 0;
	while (str[i] && (ft_strcmp(str[i], "rb") || ft_strcmp(str[i], "rrb")))
	{
		if (ft_strcmp(str[i], "rb"))
			rb++;
		if (ft_strcmp(str[i], "rrb"))
			rrb++;
		i++;
	}
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
	return (i);
}

int add_others(char **temp, char **fin, int i)
{
	while (temp[i] && !(ft_strcmp(temp[i], "pa") || ft_strcmp(temp[i], "pb") ||
		ft_strcmp(temp[i], "ra") || ft_strcmp(temp[i], "rb") ||
		ft_strcmp(temp[i], "rra") || ft_strcmp(temp[i], "rrb")))
	{
		*fin = add_to_string(*fin, temp[i]);
		*fin = add_to_string(*fin, "\n");
		i++;
	}
	return (i);
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

int rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrab(stack_a);
	rrab(stack_b);
	return (0);
}

void print_final_result(char *str1)
{
	char **tmp;
	char *result;
	int i;

	i = 0;
	result = ft_strdup("\0");
	tmp = ft_split(str1, '\n');
	while(tmp[i])
	{
		if ((tmp[i]) && (ft_strcmp(tmp[i], "pa") == 1 || ft_strcmp(tmp[i], "pb") == 1))
			i = add_pa_pb(tmp, &result, i);
		if ((tmp[i]) && (ft_strcmp(tmp[i], "ra") == 1 || ft_strcmp(tmp[i], "rra")))
			i = add_ra_rra(tmp, &result, i);
		if ((tmp[i]) && (ft_strcmp(tmp[i], "rb") == 1 || ft_strcmp(tmp[i], "rrb")))
			i = add_rb_rrb(tmp, &result, i);
		if ((tmp[i]) && !(ft_strcmp(tmp[i], "pa") == 1 || ft_strcmp(tmp[i], "pb") == 1 || ft_strcmp(tmp[i], "ra") == 1 || ft_strcmp(tmp[i], "rra") || ft_strcmp(tmp[i], "rb") == 1 || ft_strcmp(tmp[i], "rrb")))
			i = add_others(tmp, &result, i);
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

void sixth(t_stack **stack, t_com **final)
{
	rrab(stack);
	sab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "rra\nsa\n");
	else
		(*final)->result = add_to_string((*final)->result, "rrb\nsb\n");
}

void seventh(t_stack **stack, t_com **final)
{
	rab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\n");
}

void eight(t_stack **stack, t_com **final)
{
	rrab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "rra\n");
	else
		(*final)->result = add_to_string((*final)->result, "rrb\n");
}

void nineth(t_stack **stack, t_com **final)
{
	rab(stack);
	sab(stack);
	if ((*stack)->dif == 1)
		(*final)->result = add_to_string((*final)->result, "ra\nsa\n");
	else
		(*final)->result = add_to_string((*final)->result, "rb\nsb\n");
}

char *add_to_string(char *str, char *str1)
{
	char *rem;

	rem = str;
	str = ft_strjoin(str, str1);
	ft_delete_string(&rem);
	return(str);
}

int *create_array(t_stack *stack, int len)//complete
{
	int *array;
	int i;

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

int find_mid(t_stack *stack, int len)
{
	int *array;
	int mid;

	if (stack_len(stack) < len)
		len = stack_len(stack);
	array = create_array(stack, len);
	sort_quick(array, 0, len - 1);
	mid = array[len / 2];
	free(array);
	return (mid);
}

void sort_quick(int *stack, int start, int end)
{
	int stack1[end + 1];
	int top;
	int base;

	top = -1;
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
}

int part(int *stack, int start, int end)
{
	int end_v;
	int currency;
	int str_index;

	end_v = stack[end];
	str_index = start - 1;
	currency = start;
	while (currency <= end - 1)
	{
		if(stack[currency] <= end_v)
		{
			str_index++;
			ft_swap_elem(&stack[str_index], &stack[currency]);
		}
		currency++;
	}
	ft_swap_elem(&stack[str_index + 1], &stack[end]);
	return (str_index + 1);
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