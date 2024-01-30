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

/**
 * add_fn - A funtion that adds the top two elements of the
 * stack.
 * @hd: Head of stack
 * @cn: The line_number
 * Return: Nada
*/
void add_fn(stack_t **hd, unsigned int cn)
{
stack_t *h;
int len = 0, aux;

h = *hd;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", cn);
fclose(bus.file);
free(bus.content);
free_stack(*hd);
exit(EXIT_FAILURE);
}
h = *hd;
aux = h->n + h->next->n;
h->next->n = aux;
*hd = h->next;
free(h);
}
