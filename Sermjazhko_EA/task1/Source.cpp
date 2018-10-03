#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float h, w, d, l, L, Vp, Vb, Vd, Vz, Vk, m;//высота, ширина, глубина, для полок;
	float dsp = 0.86, dvp = 0.82, tz = 0.05, tbk = 0.15, td = 1.0, p = 0.74;//толщина задней с., толщина боковой и крышки, толщина двери, плотность дуба;
	printf("Введите высоту шкафа (от 180 до 220 см)\n");
	scanf_s("%f", &h);
	printf("Введите ширину шкафа (от 80 до 120 см)\n");
	scanf_s("%f", &w);
	printf("Введите глубину шкафа (от 50 до 90 см)\n");
	scanf_s("%f", &d);
	printf("Введите толщину полки в см\n");
	scanf_s("%f", &l);
	while ((h > 200) || (h < 180) || (w > 120) || (w < 80) || (d > 90) || (d < 50))
	{
		printf("Данные введены неверно. Ещё раз введите высоту, ширину и глубину.\n");
		scanf_s("%f", &h);
		scanf_s("%f", &w);
		scanf_s("%f", &d);
	}
	L = floor((h - 0.3) / (40.0 + 1.0));
	printf("количество полок = &f\n", L);

	Vp = l * (w - 0.3)*d;
	Vb = 0.3*(d + 1.05)*(h - 0.3);
	Vd = (h - 0.3)*w;
	Vz = 0.05*(h - 0.3)*w;
	Vk = 0.3*(d + 1.05);
	m = Vz * dvp + Vb * dsp + Vd * p + Vk * dsp + Vp * dsp;
	printf("Масса шкафа в кг = &f", m / 1000);
}
