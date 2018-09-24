#include <stdio.h>

int main() {
	int width, heigth, deep;
	float densityDSP = 3.2, densityDVP = 3;// г/см^3
	int volumeDSP, volumeDVP;
	float weight;
	scanf_s("%d,%d,%d", &heigth, &width, &deep);

	volumeDVP = width * heigth * 5;
	volumeDSP = 2 * heigth*deep * 15;
	volumeDSP += 2 * width*deep * 15;
	volumeDSP += width * heigth * 10;
	volumeDSP += width * deep * 15 * ((heigth - 1) / 40);
	volumeDSP /= 1000;// перевод в см^3
	volumeDVP /= 1000;
	weight = volumeDSP * densityDSP + volumeDVP * volumeDVP;

	printf("%f", weight);
	scanf_s("%d", &width);
	return 0;
}
