#include <stdio.h>
#include <stdlib.h>
struct lst
{
	char *buff;
	struct lst *next;
};

int main()
{
	struct lst *a = malloc(sizeof(struct lst));
	a -> next = malloc(sizeof(struct lst));
	a -> next -> buff = malloc (5);
	a -> next -> buff[0] = 'a';
	a -> next -> buff[1] = 'b';
	a -> next -> buff[2] = 'c';
	a = a->next;

	printf ("%s", a->buff);
	
}
