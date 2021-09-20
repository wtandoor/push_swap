#include "push_swap.h"

t_stack	*place_argv_in_stack(int argc, char **argv)
{
	int		i;
	t_stack	*temp;
	t_stack	*first;

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

int	check(char *argv)
{
	int	i;
	int	len;

	i = 0;
	if (argv[i] == '-' && !ft_isdigit(argv[i + 1]))
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

int	check_overflow(char *str)
{
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (1);
	}
	if (str[0] != '-')
	{
		if (ft_atoi(str) < 0)
			return (1);
	}
	return (0);
}

void	check_second(t_stack **stack)
{
	int	*array;
	int	len;
	int	i;

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

void	free_memory(char **tmp, char **str1, char **result )
{
	int	i;

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
