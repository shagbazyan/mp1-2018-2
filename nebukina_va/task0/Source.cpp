#include <stdio.h>
#include <math.h>
int main()
{
	float end;
	float r1, r2, x1, x2, y1, y2; // r1, r2 - ������� �����������, x1, y1 - ���������� ������ ������ ����������, x1, y2 - ���������� ������ ������ ����������
	float L; // L - ���������� ������������� �����������
	printf("������� ���������� x1, y1 ������ ������ ���������� � � ������ � ��������������� ������� ����� ������");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("������� ���������� x2, y2 ������ ������ ���������� � � ������ � ��������������� ������� ����� ������");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	L = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	if ((r1 > r2) && (L > (r1 - r2)) && (L < (r1 + r2))) printf("���������� ������������");
	if ((r1 < r2) && (L > (r2 - r1)) && (L < (r1 + r2))) printf("���������� ������������");
	if ((x1 == x2)&&(y1 == y2))
		if (r1 > r2)
			printf("���������� �����������������, ������ ��������� ������ ������");
		else
			if (r1 == r2)
				printf("���������� ���������");
			else printf("���������� �����������������, ������ ��������� ������ ������");
	else
		if (L > (r1 + r2))
			printf("���������� �� ������������, ����������� �����");
		else
			if (L == (r1 + r2))
				printf("���������� �������� ������� �������");
			else
				if ((r1 > r2)&&(L == (r1 - r2)))
						printf("���������� �������� ���������� �������, ������ ���������� - �������");
					if ((r1<r2)&&(L == (r2 - r1)))
						printf("���������� �������� ���������� �������, ������ ���������� - �������");
					if ((r1 > r2)&&(L<(r1-r2))) printf("���������� �� ������������, ������ ����������� ������ ������");
					if ((r2 > r1)&&(L<(r2-r1))) printf("���������� �� ������������, ������ ����������� ������ ������");
				scanf_s("%f", &end);
				return 0;
}