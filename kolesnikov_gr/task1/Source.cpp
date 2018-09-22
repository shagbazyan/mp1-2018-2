#include <stdio.h>

#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float pDSP, pDEREVA, pDVP;
	float H, W, D;
	float Tzstenki;
	float Tbok;
	float Tdver;
	float Tpolok;
	float Tkrish;
	float Npolok;
	float Mzstenki, Mdver, Mbok, Mvnutr, Mkrish, Mpolok, Mobsh;
	float a;

	printf("Введите высоту(h), ширину(w) и глубину(d) в сантиметрах\n");
	scanf_s("%f%f%f", &H, &W, &D);
	printf("Введите плотность ДЛП, ДВП и дерева в граммах на сантиметрах кубических\n");
	scanf_s("%f%f%f", &pDSP, &pDVP, &pDEREVA);
	printf("Введите толщину задней стенки в сантиметрах\n");
	scanf_s("%f", &Tzstenki);
	printf("Введите толщину боковой стенки в сантиметрах\n");
	scanf_s("%f", &Tbok);
	printf("Введите толщину двери в сантиметрах\n");
	scanf_s("%f", &Tdver);
	printf("Введите толщину полок в сантиметрах\n");
	scanf_s("%f", &Tpolok);
	printf("Введите толщину крышек в сантиметрах\n");
	scanf_s("%f", &Tkrish);

	Mzstenki = pDVP * H*W*Tzstenki;
	printf("Масса задней стенки %f\n", Mzstenki);
	Mbok = 2 * pDSP*H*D*Tbok;
	printf("Масса боковин %f\n", Mbok);
	Mkrish = 2 * pDSP*W*D*Tkrish;
	printf("Масса крышек %f\n", Mkrish);
	Mdver = pDEREVA * H*W*Tdver;
	printf("Масса дверей %f\n", Mdver);
	Npolok = (int)((H - 2 * Tkrish - 00000.1) / 40);
	printf("Количество полок %f\n", Npolok);
	Mpolok = Npolok * pDSP*W*D*Tpolok;
	printf("Масса полок %f\n", Mpolok);
	Mobsh = Mzstenki + Mbok + Mkrish + Mdver + Mpolok;
	printf("Общая масса шкафа %f\n", Mobsh);
	scanf_s("%f", &a);
}