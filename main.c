#include "monty.h"
/**
 * main - Entry to tue monty interperter.
 * @argn: The number of arguments.
 * @argv: The actual arguments.
 * Return: void.
*/
int main(int argn, char *argv[])
{
stack_t *stack = NULL;
static char *string[1000] = {NULL};
int index = 0;
FILE *fd;
size_t buffer_size = 1000;

if (argn != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
fd = fopen(argv[1], "r");
if (fd == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
for (index = 0; getline(&(string[index]), &buffer_size, fd) > 0; index++)
		;
run(string, stack);
free_list_fn(string);
fclose(fd);
return (0);
}
/**
 * run - This function executes the opcode.
 * @str_props: File properties.
 * @stack: This is the list.
 * Return: Nada.
*/
void run(char *str_props[], stack_t *stack)
{
int len, x, index;

instruction_t st[] = {
{"verbose", verbose},
{"put_n", put_n},
{"add", add},
{"swapper", swapper},
{"rm", rm},
{"null", NULL}
};
for (len = 1, x = 0; str_props[x + 1]; x++, len++)
{
if (my_strcmp("push", string[x]))
push(&stack, len, push_n(str_props[x], len));
else if (my_strcmp("nop", str_props[x]))
;
else
{
index = 0;
while (!my_strcmp(st[index].opcode, "null"))
{
if (my_strcmp(st[index].opcode, str_props[x]))
{
st[index].f(&stack, len);
break;
}
index++;
}
if (my_strcmp(st[index].opcode, "null") && !my_strcmp(str_props[x], "\n"))
{
fprintf(stderr, "L%u: unknown instruction %s", len, str_props[x]);
if (!get_new_line(str_props[x]))
fprintf(stderr, "\n");
exit(EXIT_FAILURE);
}
}
}
free_stack_fn(stack);
}
