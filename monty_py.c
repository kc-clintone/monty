#include "monty.h"
/**
 * verbose - This function prints all elements on the stack.
 * @stk_ptr: This is a pointer to head of stack.
 * @ln: Once again, not a logarithm.
 * Return: Nada
*/
void verbose(stack_t **stk_ptr, unsigned int ln)
{
(void)ln;
stack_t *h = *stk_ptr;

while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
/**
 * push_function - Thus funtion pushes an element to the stack.
 * @stk_ptr: The pointer to head of stack.
 * @ln: You know it.
 * @n: Just a random variable.
 * Return: Returns the address of new stack element.
*/
void push_function(stack_t **stk_ptr, unsigned int ln, int n)
{
stack_t *new, *h = *stk_ptr;

if (stack == NULL)
{
fprintf(stderr, "L%d: usage: push integer", ln);
exit(EXIT_FAILURE);
}
new = malloc(sizeof(stack_t));
if (new == NULL)
exit(EXIT_FAILURE);
new->prev = NULL;
new->n = n;
new->next = *stk_ptr;
if (*stk_ptr)
h->prev = new;
*stk_ptr = new;
}
/**
 * rm - Removes the top element of the stack
 * @stk_ptr: The pointer to head of stack.
 * @ln: Same old stuff.
 * Return: Nada.
*/
void rm(stack_t **stk_ptr, unsigned int ln)
{
stack_t *h = *stk_ptr;

if (!(*stk_ptr))
{
fprintf(stderr, "L%u: can't pop an empty stack\n", ln);
exit(EXIT_FAILURE);
}
if (h)
{
*stk_ptr = (h)->next;
free(h);
}
}
/**
 * swapper - This function swaps the top two elements of the stack.
 * @stk_ptr: The pointer to head of stack.
 * @ln: The line number.
 * Return: Nada.
*/
void swapper(stack_t **stk_ptr, unsigned int ln)
{
stack_t *h = *stk_ptr, *ptr;

if ((*stk_ptr) == NULL || (*stk_ptr)->next == NULL)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", ln);
exit(EXIT_FAILURE);
}

if (h && h->next)
{
ptr = h->next;
if (ptr->next)
ptr->next->prev = h;
h->next = ptr->next;
ptr->prev = NULL;
ptr->next = h;
h->prev = ptr;
*stk_ptr = ptr;
}
}
