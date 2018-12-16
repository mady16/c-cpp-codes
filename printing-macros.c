#include <stdio.h>

#define str(s) #s
#define merge(s1, s2) s1##s2

int main () {

	printf (str (Printing from macros in C));
	printf ("\n");
	printf ("%d\n", merge (1, 2));
	return (0);
}