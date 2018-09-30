#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int main() {

	srand(time(NULL));
	int game, attemps = 0;
	char point;
	printf("Choose game: write 1 for first mode, 2 for second mode \n");
	scanf_s("%d", &game);
	
	printf("Start\nEnter number between 1 and 1000 \n");

	if (game == 1) {
		int r, bottom = 1, up = 1000;;
		int player;
		r = rand() % up + bottom;
		short int flag = 0;
			
		while (flag == 0) {
			attemps++;
			scanf_s("%d", &player);
			if (player == r) {
				printf("\nYou win\n");
				flag = 1;
			}
			else
			{
				if (player > r) {
					printf("Yor number is higher then hidden number\n");
				}
				else
				{
					printf("Yor number is lower then hidden number\n");
				}
			}
		}
	}
	else
	{
		int player,r, bottom = 1, up = 1000;
		scanf_s("%d", &player);
		
		short int flag = 0;

		while (flag == 0) {
			attemps++;
					
			r = rand() % (up-bottom+1) + bottom;
			
			printf("Is it number %d ?\n", r);
			scanf_s("%c", &point);
			scanf_s("%c", &point);
			
			switch (point)
			{
				case('='): {
					printf("\nYeah! I am win\n");
					flag = 1;
					break;
				}
				case('<'): {
					printf("Ok!\n");
					up = r - 1;
					break;
				}
				case('>'): {
					printf("Ok!\n");
					bottom = r + 1;
					break;
				}
			default:
				break;
			}
		}
	}
	printf("Attemps: %d", attemps);
	_getch();
	return 0;
}
