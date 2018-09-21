#include <stdio.h>
#include <math.h>
int main() {
	float x1=1, y1=2, x2=3, y2=4, r1, r2;
	float rastoyn;
	scanf_s ("%f %f", &r1, &r2);
	rastoyn = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (rastoyn == 0)
		if (r2 > r1) printf("1 окружность в 2, и их центры совпадают");
		else printf("2 окружность в 1, и их центры совпадают");
	else if (rastoyn + r1 < r2 || rastoyn + r2 < r1) printf("Окружность внутри окружности");
	else if ((rastoyn + r1) == r2 || (rastoyn + r2) == r1) printf("Окружность касаются внутренне");
	else if (rastoyn < (r1 + r2)) printf("Окружности пересекаются");
	else if (rastoyn == (r1 + r2)) printf("Окружности касаются внешне");
	else if (rastoyn > (r1 + r2)) printf("Окружности не касаются");
	   
}