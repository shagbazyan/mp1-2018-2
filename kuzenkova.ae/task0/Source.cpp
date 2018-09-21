
#include <stdio.h>
#include <math.h>
int main() {
	float x1=5, y1=5, x2=14, y2=5, r1, r2;
	float rastoyn;
	scanf_s ("%f %f", &r1, &r2);
	rastoyn = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (rastoyn == 0)
		if (r2 == r1) 
			 printf("Okrujnosti sovpadaut");
		else printf("Okrujnost vnuti okrujnosti, centru sovpadaut");
	else 
		if (rastoyn + r1 < r2 || rastoyn + r2 < r1) 
			printf("Okrujnost vnuti okrujnosti");
	    else 
			if ((rastoyn + r1) == r2 || (rastoyn + r2) == r1) 
				printf("Okrujnost kasautsy vnutrenne");
	        else 
				if (rastoyn < (r1 + r2)) 
					printf("Okrujnost peresekautsy");
	            else 
					if (rastoyn == (r1 + r2)) 
						printf("Okrujnost kasautsy vneshne");
	                else 
					    if (rastoyn > (r1 + r2)) 
							printf("Okrujnost ne peresecautsy");
	scanf_s("%d", 0);
}