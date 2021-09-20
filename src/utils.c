#include "push_swap.h"

void	stack_del(t_stack **stack)
{
	t_stack	*del;
	t_stack	*tmp;

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

	first = (t_stack *)malloc(sizeof(t_stack));
	first->n = 0;
	first->dif = 1;
	first->next = NULL;
	return (first);
}

int	stack_len(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	scmp(char *str1, char *str2)
{
	int	i;

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
		return (1);
	return (0);
}

void	ft_delete_string(char **str)
{
	if (str == NULL)
		return ;
	free(*str);
	*str = NULL;
}
