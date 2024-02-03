#include "monty.h"
/**
 * free_stack_fn - This funtion frees the list.
 * @h: The pointer to next node.
 * Return: Nada
*/
void free_stack_fn(stack_t *h)
{
stack_t *node = h;

if (h == NULL)
return;
while (h != NULL)
{
node = h;
h = h->next;
free(node);
}
}
/**
 * free_list_fn - This function frees the getline list or something.
 * @ptr: A pointer to array of strings.
 * Return: Nada
*/
void free_list_fn(char *ptr[])
{
int index = 0;

while (ptr[index] != NULL)
{
free(ptr[index]);
index++;
}
}

