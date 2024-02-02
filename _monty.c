#include "monty.h"
/**
 * print_stack - This function prints all values on
 * the stack.
 * @stk_ptr: The pointer to head of stack.
 * @ln: Not a logarithm, it's like a line number.
 * Return: Nada 🙃
*/
void print_stack(stack_t **stk_ptr, unsigned int ln)
{
stack_t *h = *stk_ptr; (void)ln;

while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
/**
 * push_fn - This function simply pushes a new element to
 * the stack.
 * @stk_ptr: Still a pointer to head of stack.
 * @ln: You guessed it right, not a logarithm.
 * @x: Now, this is a random variable. Don't overthink it 😁.
 * Return: Returns address of the new location.
*/
void push_fn(stack_t **stk_ptr, unsigned int ln, int x)
{
stack_t *new, *h = *stk_ptr;

if (stk_ptr == NULL)
{
fprintf(stderr, "L%d: usage: push <integer>", ln);
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
 * pop_fn - This function pops the top element on the stack.
 * @stk_ptr: Yep, still the same.
 * @ln: Also still the same.
 * Return: Nada.
*/
void pop_fn(stack_t **stk_ptr, unsigned int ln)
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
 * @stk_ptr: Same old same old
 * @ln: You already know 😆
 * Return: Nada
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
