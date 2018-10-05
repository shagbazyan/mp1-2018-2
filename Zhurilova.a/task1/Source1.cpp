#include <stdio.h>
#include <math.h>

void main()
{

	float h, w, d, tz, tbv, td,tp, r1, r2, r3, masz, masb, masv, masdv, masp, kol, Mas;
	
	tz = 0.05; //Толщина задней стенки
	tbv = 0.15;//Толщина боковых стенок, верхней инижней крышки
	td = 1;//Толщина дверей
	
	printf ("Введите высоту шкафа от 1.8 до 2.2 метров, затем ширину от 0.8 до 1.2 метров и глубину от 0.5 до 0.9\n Строго последовательно!");
	scanf("%f %f %f", &h, &w, &d);
	
	r1 = 900;//Плотность двп в кг/м3
	r2 = 735;//Плотность дсп в кг/м3
	r3 = 680;//Плотность дерева (Бук)
	
	printf("Введите толщину полок");
	scanf("%f", &tp);
	
	kol = int( (h - 0.4) / (tp + 0.4) );//Расчет количество полок с учетом расстояния от нижней стенки до последний полки в 0.4 метра
	
	masz = h * w * tz * r1;//Расчет массы задней стенки
	
	masb = 2 * (h * d * tbv * r2);//Расчет массы боковых стенок
   
	masv = 2 * (w * d * tbv * r2); //Расчет массы верхней и нижней стенки
	
	masdv = h * w * td * r3;//Расчет массы дверей
	
	masp = kol  *(w * d * tp * r2);//Расчет массы всех полок
	
	Mas = masz + masb + masv + masdv + masp;//Расчет массы всего шкафа
	
	printf("Масса шкафа %d", Mas);
}
