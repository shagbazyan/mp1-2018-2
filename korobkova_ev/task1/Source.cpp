#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	float height, width, depth; //высота, ширина, глубина
	float pdsp = 0.8, pdvp = 0.82, pwood = 0.75; //плотности дсп, двп, дерева(бук)
	int k; //количество полок
	float v1, v2, v3, v4, v5; //где, v1 - объем задней части, v2 - объем боковин, v3 - объем верхней и нижней крышки, v4 - объем двух накладных дверей, v5 - объем внутренних полок
	float m; // где m-масса шкафа

	printf("Введите высоту в диапозоне от 180 до 220 в см\n");
	scanf_s("%f", &height);
	printf("Введите ширину в диапозоне от 80 до 120 в см\n");
	scanf_s("%f", &width);
	printf("Введите глубину в диапозоне от 50 до 90 в см\n");
	scanf_s("%f", &depth);

	v1 = height * width * 0.5;
	v2 = 2 * (height * depth * 1.5);
	v3 = 2 * (width * depth * 1.5);
	v4 = height * width * 1;
	k = ceil((height - 3) / 41.5) - 1;
	v5 = k * width *depth* 1.5;
	m = pdvp * v1 + pdsp * (v2 + v3 + v5) + pwood * v4;
	printf("Масса шкафа %f", m / 1000);
}