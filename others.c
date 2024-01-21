#include "monty.h"
/**
 * free_node - Frees the stack_t stack.
 * @stack_p: A pointer to the top and bottom stacks.
*/
void free_node(stack_t **stack_p)
{
stack_t *tmp = *stack_p;

while (*stack_p)
{
tmp = (*stack_p)->next;
free(*stack_p);
*stack_p = tmp;
}
}
