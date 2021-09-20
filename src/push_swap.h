#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

typedef struct s_stack
{
	int				n;
	int				dif;
	struct s_stack	*next;
}				t_stack;

typedef struct s_com
{
	int				rotation;
	char			*result;
}				t_com;

t_stack	*create_new(void);
t_stack	*place_argv_in_stack(int argc, char **argv);
t_com	*new_final(void);
int		check(char *argv);
int		check_overflow(char *str);
int		stack_rotation(t_stack **stack, t_com **final, int rot);
int		stack_len(t_stack *stack);
int		div_stack_a(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int len);
int		stack_push(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int part);
int		div_stack_b(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int len);
int		create_a(t_stack **stack_a, t_com **final, int len);
int		create_b(t_stack **stack_a, t_com **final, int len);
int		scmp(char *str1, char *str2);
int		add_pa_pb(char **str, char **fin, int i);
int		add_ra_rra(char **str, char **fin, int i);
int		add_rb_rrb(char **str, char **fin, int i);
int		add_others(char **temp, char **fin, int i);
int		sab(t_stack **first);
int		pab(t_stack **first_to, t_stack **first_from);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rab(t_stack **first);
int		rrab(t_stack **first);
int		rrr(t_stack **stack_a, t_stack **stack_b);
int		*create_array(t_stack *stack, int len);
int		part(int *stack, int start, int end);
int		find_mid(t_stack *stack, int len);
void	first(t_stack **stack, t_com **final);
void	second(t_stack **stack, t_com **final);
void	third(t_stack **stack, t_com **final);
void	forth(t_stack **stack, t_com **final);
void	fifth(t_stack **stack, t_com **final);
void	sixth(t_stack **stack, t_com **final);
void	seventh(t_stack **stack, t_com **final);
void	eight(t_stack **stack, t_com **final);
void	nineth(t_stack **stack, t_com **final);
void	print_final_result(char *str1);
void	ft_swap_elem(int *a, int *b);
void	stack_del(t_stack **stack);
void	check_second(t_stack **stack);
void	sort_short(t_stack **s, int len);
void	swap_2(t_stack **stack, t_com **final);
void	sort_three(t_stack **stack);
void	swap_3(t_stack **stack, t_com **final);
void	swap_3_a(t_stack **stack, t_com **fin);
void	swap_3_a_add(t_stack **s, t_com **fin);
void	swap_3_b_add(t_stack **s, t_com **fin);
void	swap_3_b(t_stack **stack, t_com **fin);
void	pa_pb_add(char **fin, int pa, int pb, int x);
void	ra_rra_add(char **fin, int ra, int rra, int x);
void	rb_rrb_add(char **fin, int rb, int rrb, int x);
void	swap_len1_more_2(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int len);
void	swap_len1_2(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int len);
void	elements_swap(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int len);
void	rotate_back(t_stack **stack, t_com **final, int rot);
void	global_sort_utils(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int len);
void	push_back(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int part);
void	global_sort(t_stack **stack_a,
			t_stack **stack_b, t_com **final, int len);
void	ft_delete_string(char **str);
void	sort_quick(int *stack, int start, int end);
void	free_memory(char **tmp, char **str1, char **result );
char	*add_to_string(char *str, char *str1);

#endif