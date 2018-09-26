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

	printf("Vvedite visoty(h), shiriny(w) i glubiny(d) v sanrimetrah\n");
	scanf_s("%f%f%f", &H, &W, &D);
	printf("Vvedite plotnost DSP, DVP i dereva v kilogrammah na santimetri kybi4eskie\n");
	scanf_s("%f%f%f", &pDSP, &pDVP, &pDEREVA);
	printf("Vvedite tolshiny zadnei stenki v sanrimetrah\n");
	scanf_s("%f", &Tzstenki);
	printf("Vvedite tolshiny bokovoi stenki v sanrimetrah\n");
	scanf_s("%f", &Tbok);
	printf("Vvedite tolshiny dveri v sanrimetrah\n");
	scanf_s("%f", &Tdver);
	printf("Vvedite tolshiny polok v sanrimetrah\n");
	scanf_s("%f", &Tpolok);
	printf("Vvedite tolshiny krishek v sanrimetrah\n");
	scanf_s("%f", &Tkrish);

	Mzstenki = pDVP * H*W*Tzstenki;
	printf("Massa zadnei stenki %f\n", Mzstenki);
	Mbok = 2 * pDSP*H*D*Tbok;
	printf("Massa bokovin %f\n", Mbok);
	Mkrish = 2 * pDSP*W*D*Tkrish;
	printf("Massa krishek %f\n", Mkrish);
	Mdver = pDEREVA * H*W*Tdver;
	printf("Massa dverei %f\n", Mdver);
	Npolok = (int)((H - 2 * Tkrish - 00000.1) / 40);
	printf("Koli4estvo polok %f\n", Npolok);
	Mpolok = Npolok * pDSP*W*D*Tpolok;
	printf("Massa polok %f\n", Mpolok);
	Mobsh = Mzstenki + Mbok + Mkrish + Mdver + Mpolok;
	printf("Obshaya Massa Shkafa %5.1f kilogramm\n", Mobsh);
	scanf_s("%f", &a);
}