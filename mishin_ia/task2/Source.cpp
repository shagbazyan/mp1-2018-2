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
		int r;
		int player;
		r = rand() % 10 + 1;
		short int flag = 0;
			
		while (flag == 0) {
			attemps++;
			scanf_s("%d", &player);
			if (player == r) {
				printf("You win\n");
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
		int player,r, bottom = 1, up = 10;
		scanf_s("%d", &player);
		
		
		short int flag = 0;

		while (flag == 0) {
			attemps++;
					
			r = rand() % (up-bottom+1) + bottom;
			
			printf("Is it number %d ?\n", r);
			printf("%d,%d\n", up, bottom);
			scanf_s("%c", &point);
			scanf_s("%c", &point);
			
			if (point == '=') {
				printf("You win\n");
				flag = 1;
			}
			else
			{
				if (point == '>') {
					printf("Ok!\n");
					bottom = r;

					
				}
				if (point == '<')
				{
					printf("Ok!\n");
					up = r;
				}
			}
		}
		

	}
	
	

	
	
		

	
	

	printf("Your attemps: %d", attemps);
	_getch();
	return 0;

}
