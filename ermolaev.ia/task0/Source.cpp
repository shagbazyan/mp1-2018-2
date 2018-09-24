#include <stdio.h>
#include <math.h>

void main()
{
	int x1, y1, r1, x2, y2, r2;
	printf("x1, y1, r1\n");
	scanf_s("%d" "%d" "%d", &x1, &y1, &r1);
	printf("x2, y2, r2\n");
	scanf_s("%d" "%d" "%d", &x2, &y2, &r2);
	float rast = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if (rast > r1 + r2)
	{
		printf("Ne peresek");
	}
	else if (rast == r1 + r2)
	{
		printf("Kacanie");
	}
	else if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Sovpadenie");
	}
	else if ((r1 >= r2) && ((r1 - rast) == r2) || (r1 <= r2) && ((r2 - rast) == r1))
	{
		printf("Kasanie");
	}
	else if ((r1 >= r2) && ((r1 - rast) > r2) || (r1 <= r2) && ((r2 - rast) > r1))
	{
		printf("Okr v Okr");
	}
	else if ((r1 >= r2) && ((r1 - rast) < r2) || (r1 <= r2) && ((r2 - rast) < r1))
	{
		printf("Peresechenie");
	}
	
	while (true);

}
