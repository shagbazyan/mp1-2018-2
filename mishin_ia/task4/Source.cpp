#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define length 4

typedef struct{
	char *name;
	int price;
	int sale;
	int code[4];	
}product;

int main() {
	product products[length];
	
	products[0] = { "Cheese", 100, 5 , {2,1,3,4} };
	products[1] = { "Meat" ,200, 10 , {5,1,3,4} };
	products[2] = { "Milk", 50 , 20 , {8,1,3,4} };
	products[3] = { "Bread", 30, 2 , {7,1,3,4} };


	while (true)
	{
		int code;
		printf("\nPlese enter product code: ");
		scanf_s("%d", &code);

		int prodType = -1;

		for (int i = 0; i < length; i++)
		{
			int k = 0, pow = 1;
			for (int j = 3; j >= 0; j--)
			{
				k += products[i].code[j] * pow;
				pow *= 10;
			}

			if (code == k)
			{
				prodType = i;
				break;
			}
		}

		if (prodType == -1)
		{
			printf("\nWrong code.\n");
		}
		else
		{
			printf("Name: %s, price: %d, sale: %d ", products[prodType].name, products[prodType].price, products[prodType].sale);
		}

	}
	_getch();
	return 0;
}