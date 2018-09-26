#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <cmath>

int main()
{
	float x1, y1, r1, x2, y2, r2;
	float delta;

	printf("Enter coordinates of the center of the first circle and it's radius\n");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Enter coordinates of the center of the second circle and it's radius\n");
	scanf_s("%f %f %f", &x2, &y2, &r2);

	delta = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (delta > r1 + r2)
		printf("The circles are outside of each other\n");
	else if ((delta == r1 + r2) && (delta > 0))
		printf("The circles touch each other from the outside\n");
	else if (delta > abs(r1 - r2))
		printf("The circles cross each other\n");
	else if ((delta == abs(r1 - r2)) && (delta > 0))
		if (r1 > r2)
			printf("The circles touch each other from the inside of the first circle\n");
		else
			printf("The circles touch each other from the inside of the second circle\n");
	else if ((delta < abs(r1 - r2)) || (delta == 0))
		if (r1 > r2)
			printf("The second circle is inside the first circle\n");
		else if (r1 == r2)
			printf("The circles match\n");
		else
			printf("The first circle is inside the second circle\n");
	_getch();
}