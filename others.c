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
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
