#include <stdio.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");

	/*  Õàðàêòåðèñòèêè ÷àñòåé øêàôà
	 Ïåðâûé  áóêâà - õàðàêòåðèñòèêà
	 Âòîðàÿ - ìàòåðèàë (v - ÄÂÏ, s - äñï, d - äåðåâî)
	 Òðåòüÿ - öèôðà, íîìåð â ñïèñêå â îïèñàíèè çàäà÷è */
	
	float h, w, d;
	float tv1, ts2, ts3, td4, ts5;
	float v1, v2, v3, v4, v5; // Îáúåìû îòäåëüíûõ ÷àñòåé 
	float _s, _v, _d, m; // Ïëîòíîñòè è îáùàÿ ìàññà
	float imp;

	_s = 750;
	_v = 250;
	_d = 720;

	tv1 = 5.0 / 1000;
	ts2 = 15.0 / 1000;
	ts3 = 15.0 / 1000;
	td4 = 10.0 / 1000;
	ts5 = 10.0 / 1000; // ?

	printf("Ââåäèòå âûñîòó øêàôà:\n");
	scanf_s("%f", &imp);
	h = imp / 100;

	printf("Ââåäèòå øèðèíó øêàôà:\n");
	scanf_s("%f", &imp);
	w = imp / 100;

	printf("Ââåäèòå ãëóáèíó øêàôà:\n");
	scanf_s("%f", &imp);
	d = imp / 100;

	v1 = h * w * tv1;
	v2 = 2 * h * d * ts2;
	v3 = 2 * w * d * ts3;
	v4 = h * w * td4;
	v5 = int(h / 40) * (w - ts2) * ts5;

	m = v1 * _v + v4 * _d + (v2 + v3 + v5) * _s;
	printf("Ìàññà øêàôà ðàâíà %f\n", m);
	scanf_s("%f", &imp);
	
}
