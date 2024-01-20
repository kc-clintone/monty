#include "monty.h"
/**
 * node_stack - Makes a node stack for tye node.
 * @stack_ptr: A pointer to the top and the bottom stack.
 * Return: Returns: EXIT_SUCCESS, upon success.
*/
int node_stack(stack_t **stack_ptr)
{
stack_t *ptr;

ptr = malloc(sizeof(stack_t));
if (ptr == NULL)
stderr_malloc();
ptr->n = STACK;
ptr->prev = NULL;
ptr->next = NULL;

*stack_ptr = ptr;
return (EXIT_SUCCESS);
}
/**
 * sq - Goes throught the opcode to check it is STACK or QUEUE.
 * @stk: A pointer to the top and bottom stack.
 * Return: Returns the value of Stack or Queue
 */
int sq(stack_t *stk)
{
int _val = 2;

if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (_val);
}
