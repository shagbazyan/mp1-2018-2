#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	/*  Характеристики частей шкафа
	 Первый  буква - характеристика
	 Вторая - материал (v - ДВП, s - дсп, d - дерево)
	 Третья - цифра, номер в списке в описании задачи */
	
	float h, w, d;
	float tv1, ts2, ts3, td4, ts5;
	float v1, v2, v3, v4, v5; // Объемы отдельных частей 
	float _s, _v, _d, m; // Плотности и общая масса
	float imp;

	_s = 750;
	_v = 250;
	_d = 720;

	tv1 = 5.0 / 1000;
	ts2 = 15.0 / 1000;
	ts3 = 15.0 / 1000;
	td4 = 10.0 / 1000;
	ts5 = 10.0 / 1000; // ?

	printf("Введите высоту шкафа:\n");
	scanf_s("%f", &imp);
	h = imp / 100;

	printf("Введите ширину шкафа:\n");
	scanf_s("%f", &imp);
	w = imp / 100;

	printf("Введите глубину шкафа:\n");
	scanf_s("%f", &imp);
	d = imp / 100;

	v1 = h * w * tv1;
	v2 = 2 * h * d * ts2;
	v3 = 2 * w * d * ts3;
	v4 = h * w * td4;
	v5 = int(h / 40) * (w - ts2) * ts5;

	m = v1 * _v + v4 * _d + (v2 + v3 + v5) * _s;
	printf("Масса шкафа равна %f\n", m);
	scanf_s("%f", &imp);
}