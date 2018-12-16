//Using and removing preprocessor macros in C

#include <stdio.h>

float perimeter (float l);
float area (float l);

#define PI 3.14159265359
#define perimeter(r) (2 * PI * r)
#define area(r) (PI * r * r)

int main () {
	
	float r = 0.5;
	printf ("Perimeter of the circle: %0.5f\n", perimeter (r));  
	printf ("Area of the circle: %0.5f\n", area (r));
	
	//Removing macros
	#undef perimeter
	#undef area
	
	//Macros are removed and the defined functions are called
	printf ("Perimeter of the square: %0.5f\n", perimeter (r));  
	printf ("Area of the square: %0.5f\n", area (r));
	
	return (0);
}

float perimeter (float l) { return (4 * l);}
float area (float l) { return (l * l); }