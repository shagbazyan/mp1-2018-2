#include <stdio.h>

int main() {
	int width, heigth, deep;
	float densityDSP = 0.8, densityDVP = 0.75, densityWood = 0.5;// г/см^3
	int volumeDSP, volumeDVP, volumeWood;
	float weight;
	scanf_s("%d,%d,%d", &heigth, &width, &deep);

	width *= 10;
	heigth *= 10;
	deep *= 10;

	volumeDVP = width * heigth * 5;
	volumeDSP = 2 * heigth*deep * 15;
	volumeDSP += 2 * width*deep * 15;
	volumeDSP += width * heigth * 10;
	volumeWood = width * deep * 15 * ((heigth - 15) / 400);
	
	volumeDSP /= 1000;// перевод в см^3
	volumeDVP /= 1000;
	volumeWood /= 1000;
	
	weight = volumeDSP * densityDSP + volumeDVP * densityDVP + volumeWood * densityWood;

	printf("%f", weight);
	scanf_s("%d", &width);
	return 0;
}
