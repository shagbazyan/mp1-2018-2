#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	float h = 0, w = 0, d = 0; //h - высота, w - ширина, d - глубина
	float pDsp = 0.8, pDvp = 0.82, pWood = 0.6; //плотности Дсп, Двп, дерева в гр/см^2
	int n; //количество полок
	float Vzadn, Vbok, Vkrush, Vdver, Vpolk; //объемы : Vzadn - задняя стенка, Vbok - боковинки, Vkrush - верхняя и нижняя крышка, Vpolk - полка, Vdver - дверцы
	float massa; // масса шкафа
	float tpolok; //толщина полок
	bool flag = 0;

	do {
		if (flag == 1)
			printf("Неверно!!!\n");
		printf("Введите высоту в диапозоне от 180 до 220 в СМ\n");
		scanf_s("%f", &h);
		flag = 1;
	} while (h < 180 || h>220);

	flag = 0;

	do {
		if (flag == 1)
			printf("Неверно!!!\n");
		printf("Введите ширину в диапозоне от 80 до 120 в СМ\n");
		scanf_s("%f", &w);
		flag = 1;
	} while (w < 80 || w > 120);

	flag = 0;

	do {
		if (flag == 1)
			printf("Неверно!!!\n");
		printf("Введите глубину в диапозоне от 50 до 90 в СМ\n");
		scanf_s("%f", &d);
		flag = 1;
	} while (d < 50 || d > 90);

	printf("Введите толщину полок в СМ\n");
	scanf_s("%f", &tpolok);

	Vbok = 2 * h * d * 1.5;
	Vzadn = h * w * 0.5;
	Vkrush = 2 * w * d * 1.5;
	Vdver = h * w;
	n = int((h - tpolok) / 40);
	Vpolk = n * w * d * tpolok;
	massa = (pDvp * Vzadn + pDsp * (Vbok + Vkrush + Vpolk) + pWood * Vdver) / 1000;
	printf("Масса шкафа в килограммах %f", massa);
	scanf_s("%d", &n);
}