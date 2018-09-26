#include <stdio.h>
#include <math.h>
int main()
{
	printf("hello world\n");
	float ad;
	float x1, y1;
	float x2, y2;
	float r1, r2;
	float d;
	x1 = 1.0;
	x2 = 2.0;
	y1 = 2.0;
	y2 = 1.0;

	r1 = 3.0;
	r2 = 4.0;
	d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if (d == 0)
	{
		if (r1 == r2)
			printf("Okryzhnosti sovpadayt");
		else
			printf("Odna orkuzhnost nahoditsya vnutri drugui");
	}
	if (d > (r1 + r2)) printf("Okryzhnosti ne imeut obshih to4ek");
	if (d == (r1 + r2)) printf("Okryzhnosti kasautsya");
	if (d < (r1 + r2)) printf("Okruzhnosti peresekautsya");
	scanf_s("%f", &ad);
	return 0;
}

