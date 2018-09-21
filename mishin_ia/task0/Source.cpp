
#include <stdio.h>
#include <math.h>

int main() {
	int x1 = 0, y1 = 0, x2 = 5, y2 = 5;
	int rad1 = 3, rad2 = 4;

	float  length = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	
	if ((x1 == x2) && (y1 == y2)) {
		if (rad1 == rad2)
		{
			printf("Circles match");
		}
		else
		{
			if (rad1 > rad2)	
			{
				printf("Circle2 in circle1");
			}
			else
			{
				printf("Circle1 in circle2");
			}
		}
		
	}
	else {
		if ((rad1 + rad2) < length) {
			printf("not intersect");
		}
		else {
			if ((rad1 + rad2 == length) || (abs(rad1 - rad2) == length)) {
				printf("Circles kasaytsya");
			}
			else
			{
				if (abs(rad1 - rad2) < length) {
					printf("Circles intersect");
				}
				else
				{
					printf("not intersect");
				}
			}
		}
	}
	
	return 0;
}