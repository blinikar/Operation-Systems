#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	double x;
    double y;
} Point;

float distance(Point A, Point B){
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

float area(Point A, Point B, Point C){
	return 0.5 * fabs(A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y);
}

int main(void){

    Point A; A.x = 2.5; A.y = 6;
    Point B; B.x = 1; B.y = 2.2;
    Point C; C.x = 10; C.y = 6;

	float f = distance(A, B);
	printf("A -- B distance is %f\n", f);


	float a = area(A, B, C);
	printf("Area of triangle ABC is %f\n", a);

	return EXIT_SUCCESS;
}