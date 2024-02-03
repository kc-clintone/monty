#include "monty.h"
/**
 * my_strcmp - Custom strcmp funtion to compare strings.
 * @opc: The target string to be compared.
 * @lstring: The dest string to be compared.
 * Return: 0.
*/
int my_strcmp(char *opc, char *lstring)
{
while (*lstring != '\0')
{
if (*lstring == ' ')
lstring++;
else if (*opc == *lstring)
{
opc++;
lstring++;
if (*opc == '\0' && (*lstring == ' ' || *lstring == '\n' || *lstring == '\0'))
return (1);
}
else
return (0);
}
return (0);
}
/**
 * get_new_line - This funtion finds a new line.
 * @target: The target string to locate the newline.
 * Return: Returns 0 or 1 depending on the output.
*/
int get_new_line(char *target)
{
char *opc = "\n";

while (*target != '\0')
{
if (*opc == *target)
{
opc++;
target++;
if (*opc == '\0')
return (1);
}
else
target++;
}
return (0);
}
/**
 * put_n - This function pushes an integer.
 * @props: Properties.
 * @len: The line number.
 * Return: The line number.
*/
int put_n(char *props, int len)
{
char *opc = "push";

while (*props != '\0')
{
if (*opc == *proos)
{
opc++;
props++;
if (*opc == '\0')
while (*props)
{
if ((*props >= '0' && *props <= '9') || *props == '-')
{
char_finder(props, len);
return (atoi(props));
}
else if (*props == ' ')
props++;
else
{
fprintf(stderr, "L%d: usage: push integer\n", len);
exit(EXIT_FAILURE);
}
}
}
else
props++;
}
return (0);
}
/**
 * char_finder - This function finds nonnumbers and
 * some number combinations.
 * @target: The target string.
 * @len: The line number.
 * Return: 1.
*/
int char_finder(char *target, int len)
{
int index = 1;

while (target[index])
{
if (target[index] == '\0' || target[index] == '\n')
break;
if ((target[index] >= '0' && target[index] <= '9') || target[index] == ' ')
index++;
else
{
fprintf(stderr, "L%d: usage: push integer\n", len);
exit(EXIT_FAILURE);
}
}
return (1);
}
