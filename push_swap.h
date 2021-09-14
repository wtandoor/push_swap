#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/libft.h"
#include "libft/ft_printf.h"

typedef struct s_stack
{
    int n;
    int dif;
    struct s_stack *next;
}               t_stack;

typedef struct  s_com
{
    int rotation;
    char *result;
}               t_com;

t_stack	*create_new(void);
t_stack *place_argv_in_stack(int argc, char **argv);



void stack_del(t_stack **stack);
void sort_short(t_stack **stack, int len);
void sort_three(t_stack **stack);
void global_sort(t_stack **stack_a, t_stack **stack_b, t_com **final, int len);
void ft_delete_string(char **str);
void free_memory(char **tmp, char **str1, char **result );

int ft_strcmp(char *str1, char *str2);
int stack_len(t_stack *stack);
int stack_rotation(t_stack **stack, t_com **final, int rot);
int div_stack_a(t_stack **stack_a, t_stack **stack_b, t_com **final, int len);
int stack_push(t_stack **stack_a, t_stack **stack_b, t_com **final, int part);
int div_stack_b(t_stack **stack_a, t_stack **stack_b, t_com **final, int len);

#endif