
#include <stdio.h>
#include <math.h>

int main() {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int rad1 = 1, rad2 = 1;

	float  length = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	
	if ((x1 == x2) && (y1 == y2)) {
		if (rad1 == rad2)
		{
			printf("Circles match");
		}
		else
		{
			printf("Circles  not intersect");
		}
		
	}
	else {
		if ((rad1 + rad2) < length) {
			printf("Circles  not intersect");
		}
		else {
			if ((rad1 + rad2 == length) || (abs(rad1 - rad2) == length)) {
				printf("Circles touch at one point");
			}
			else
			{
				if (abs(rad1 - rad2) < length) {
					printf("Circles intersect");
				}
				else
				{
					printf("Circles not intersect");
				}
			}
		}
	}
	scanf_s("%f", &length);
	return 0;
}