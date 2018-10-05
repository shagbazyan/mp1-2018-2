#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>

void get_tip(int number, int guessed_number)
{
	int delta = guessed_number - number;
	int q = 0, tmp = abs(delta);

	while (tmp > 0)
	{
		tmp = tmp / 10;
		q++;
	}
	tmp = number % int(pow(10, q - 1));
	if (q == 1)
		printf("The computer's number is between %d and %d\n", number - 1, number + 1);
	else
		printf("The computer's number is between %d and %d\n", number - tmp, number + int(pow(10, q - 1)) - tmp);
}

void mode_1()
{
	srand(time(NULL));
	int guessed_number, prev_guess_num, tips = 1, score = 0, average_score = 0;
	int new_round, rounds = 0;

	printf("Guess a computer's number between 1 and 1000!\n");
	printf("If you manage to guess the number in less than seven attemts, you'll recieve a bonus tip!\n");
	printf("The tip will let you know a bit more about the number you're guessing. ;)\n");
	printf("\n");
	printf("Press 1 to start the game; 0 to exit to main menu\n");
	scanf_s("%d", &new_round);

	while (new_round == 1)
	{
		int number = rand() % 1000 + 1;
		bool win = false;
		int used_tips = 0, attempts = 0;
		rounds++;
		printf("\n");
		printf("Round %d\n", rounds);
		printf("Tips remaining: %d\n", tips);
		printf("To use a tip, type 0 instead of a number. (The tip is available to use after entering the first number)\n");
		printf("\n");
		printf("Enter your first number to start the round!\n");

		do
		{
			scanf_s("%d", &guessed_number);
			if (guessed_number == 0)
			{
				if (attempts == 0)
					printf("You should enter the first number to use a tip.\n");
				else if (tips > 0)
				{
					get_tip(number, prev_guess_num);
					tips--;
					used_tips++;
					printf("Tips remaining: %d.\n", tips);
				}
				else
					printf("Sorry, you are out of the tips right now... :(\n");
				continue;
			}
			else if (guessed_number > number)
				printf("Your number is greater than the computer's number! Guess better! (^_^)\n");
			else if (guessed_number < number)
				printf("Your number is less than the computer's number! Try again! (.-.)\n");
			else
			{
				printf("Absolutely correct! CONGRATULATIONS!!! (^-^)\n");
				win = true;
			}
			attempts++;
			prev_guess_num = guessed_number;
		} while (!(win));

		score = score + 1000 * 10 / attempts /*- used_tips * 500*/; //Возможно, стоит снижать очки за использование подсказок
		printf("\n");
		printf("Your score: %d\n", score);
		average_score = score / rounds;
		printf("Your average score: %d\n", average_score);
		printf("\n");
		printf("Number of attempts: %d\n", attempts);
		if (attempts < 7)
		{
			tips++;
			printf("\n");
			printf("You reached one more tip! Use it wisely...\n");
		}

		printf("\n");
		printf("Wanna play another round to increase your score?\n");
		printf("1 - Play another round; 0 - Exit to main menu\n");
		scanf_s("%d", &new_round);
	}
}

void mode_2()
{
	srand(time(NULL));
	int new_game;

	do
	{
		bool win = false;
		int number, guessed_number, up = 1000, down = 0;
		int attempts = 0;
		char sym;

		printf("\n");
		printf("Enter the number between 1 and 1000. The computer will try to guess it! (-_-)\n");
		scanf_s("%d", &number);

		do
		{
			guessed_number = int(rand()) % (up - down - 1) + down + 1;
			printf("The computer supposes %d as a right number. Type > if your number is greater or < if less or = if equal!\n", guessed_number);
			scanf_s("%c", &sym);
			scanf_s("%c", &sym);
			if (sym == '<')
				up = guessed_number;
			else if (sym == '>')
				down = guessed_number;
			else
				win = true;
			attempts++;
		} while (!(win));
		printf("FINALLY! - says the computer.\n");
		printf("\n");
		printf("Wanna play again?\n");
		printf("1 - Play; 0 - Exit to main menu\n");
		scanf_s("%d", &new_game);
	} while (new_game == 1);
}

int main()
{
	int mode, exit_game = 0;

	do
	{
		printf("What mode will you play?\n");
		printf("1 - You guess; 2 - Computer guesses; 0 - Exit the game\n");
		scanf_s("%d", &mode);

		if (mode == 1)
			mode_1();
		else if (mode == 2)
			mode_2();
		else if (mode == 0)
			exit_game = 1;
	} while (exit_game == 0);
}