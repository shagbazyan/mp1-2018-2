#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <locale.h>
int random(int a, int b)
{
	srand(time(NULL));
	if (a > 0)
		return a + rand() % (b - a);
}
void ostro_fras(int a)
{
	switch (a)
	{
	case 1:
	{
		printf("Ты все еще не угадал, эх мне так жаль тебя. \n");
		break;
	}
	case 2:
	{
		printf("Еще чуть-чуть и у тебя получится отгадать число. \n");
		break;
	}
	case 3:
	{
		printf("Даже я уже знаю это число, а ты до сих пор нет. \n");
		break;
	}
	case 0:
	{
		printf("Удача отвернулась от тебя пользователь. Мухахахаххахa. \n");
		break;
	}
	case 4:
	{
		printf("Тебе там еще не надоело так лажать? \n");
		break;
	}
	case 5:
	{
		printf("Эх, ну ты вроде был близок(но это не точно) \n");
		break;
	}
	}
}
char answer(int k, int b)
{
	if (k < b)
	{
		return '<';
	}
	else if (k > b)
	{
		return '>';
	}
	else
	{
		return '=';
	}
}
/*int gadalka(int d_1, int d_2, int n)
{
	char ci;
	int g = random(d_1, d_2);
	printf("Число высшего разума(нет) = %d \n", g);
	scanf_s("%c", &ci);
	if (ci == '>')
	{

		gadalka(d_1, g, n + 1);
	}
	else if (ci == '<')
	{
		gadalka(g, d_2, n + 1);
	}
	else
		return n;
}*/
void main()
{
	setlocale(LC_ALL, "Rus");
	bool flag_prog = true;
	while (flag_prog)
	{
		int choose;
		printf("Кого унижать вас(1), или компьюктер(2), или обоих(3), или секретный режим(4)???\n");
		scanf_s("%d", &choose);
		if (choose == 1)
		{
			int i = random(1, 1001);
			printf("Загаданное число компом = %d \n", i);
			bool flag = true;
			int a;
			printf("Компьютер уже загадал число в диапазоне от 1 до 1000, а чего ждешь ты? Отгадывай давай!\n");
			while (flag)
			{
				scanf_s("%d", &a);
				if (i == a)
				{
					flag = false;
					printf("Вы угадали! Похлопайте себе.\n");
				}
				else
				{
					ostro_fras(random(1, 6));
					if (a > i)
						printf("Дам подсказку, твое число больше нужного тебе числа\n");
					else
						printf("Дам подсказку, твое число меньше нужного тебе числа\n");
				}
			}
		}
		else if (choose == 2)
		{
			int b, n, d_1, d_2, ch;
			char otvet = 'kl';
			printf("Введите число от 1 до 1000\n");
			scanf_s("%d", &b);
			n = 1;
			d_1 = 1;
			d_2 = 1001;
			ch = random(d_1, d_2);
			printf("Очередной ответ компа %d \n", ch);

			while (otvet != '=')
			{
				scanf_s("%c", &otvet);
				if (otvet == '>')
				{
					d_1 = ch + 1;
					ch = random(d_1, d_2);
					printf("Очередной ответ компа %d \n", ch);
					n++;
				}
				else if (otvet == '<')
				{
					d_2 = ch;
					ch = random(d_1, d_2);
					printf("Очередной ответ компа %d \n", ch);
					n++;
				}
			}

			printf("Компьютер вас превзошел и отгадал с %d попытки?", n);
		}
		else if (choose == 3)
		{
			printf("Ладно, давай теперь сыграем в довольно типичную для человека игру. Узнаем кто лучше угадывает числа, ты или компьютер?");
			int komp_mind, komp_gaduka, people_mind, d_1, d_2;
			komp_gaduka = random(1, 1001);
			printf("Компьютер уже загадал число в диапазоне от 1 до 1000, а чего ждешь ты? Будь разумнее, ведь ты соревнуешься с машиной =)\n");
			int flag = 0; // 1-победа человека, 2- победа компьютера, 4 - ничья? 
			d_1 = 1;
			d_2 = 1001;
			while (flag == 0)
			{

				printf("Компьютер уже дал ответ. Давай, не подведи человечество!!!! Мы верим в тебя!! \n");
				scanf_s("%d", &people_mind);
				komp_mind = random(d_1, d_2);
				//printf("Ответ компьютера: %d\n", komp_mind);
				if (answer(komp_mind, komp_gaduka) == '>')
					d_2 = komp_mind;
				else if (answer(komp_mind, komp_gaduka) == '<')
					d_1 = komp_mind + 1;
				else
					flag = 2;
				if (komp_gaduka < people_mind)
					printf_s("Ваше число больше нужного\n");
				else if (komp_gaduka > people_mind)
					printf_s("Ваше число меньше нужного\n");
				else
				{
					flag = 1;
					printf("Вы угадали!\n");
				}
				if ((komp_mind == komp_gaduka) && (komp_gaduka == people_mind))
					flag = 4;
			}
			switch (flag)
			{
			case 1:
			{
				printf("Вы обыграли компьютер. Уряяяяяяяяяяяяя!\n");
				break;
			}
			case 2:
			{
				printf("Компьютер выиграл. Стоит задуматься...\n");
				break;
			}
			case 4:
				printf("Вы угадали одновремено. Ну что же победила дружба =)");
				break;
			}
		}
		else if (choose == 4)
		{
			printf("Теперь вы загадайте число. Компьютер тоже загадал вам число.\n Посмотрим кто быстрее.\n");
			int komp_zagadka, komp_ygadaika, people_zagadka, people_ygadalka, d_1_4, d_2_4;
			d_1_4 = 1;
			d_2_4 = 1001;
			komp_zagadka = random(d_1_4, d_2_4);
			printf("Введите число, которое будет угадывать компьютер:\n");
			scanf_s("%d", &people_zagadka);
			printf("Теперь угадываем \n");
			int r_n = 1;
			char res;
			int flag_4 = 0;
			while (flag_4 == 0)
			{
				komp_ygadaika = random(d_1_4, d_2_4);
				//printf("Ответ компьютера: %d\n", komp_ygadaika);
				if (answer(komp_ygadaika, people_zagadka) == '>')
					d_2_4 = komp_ygadaika;
				else if (answer(komp_ygadaika, people_zagadka) == '<')
					d_1_4 = komp_ygadaika + 1;
				else
					flag_4 = 2;
				printf("Введите ваш ответ: \n");
				scanf_s("%d", &people_ygadalka);
				if ((people_ygadalka == komp_zagadka) && (flag_4 == 2))
					flag_4 = 4;
				else if (people_ygadalka == komp_zagadka)
					flag_4 = 1;
				else if (people_ygadalka > komp_zagadka)
					printf("Ваше число больше загаданного \n");
				else if (people_ygadalka < komp_zagadka)
				{
					printf("Ваше число меньше загаданного \n");
				}
				printf("Подведем итог %d раунда:\n", r_n);
				printf("Пользователь:         Компьютер:\n     %d              %d\n", people_ygadalka, komp_ygadaika);
				r_n++;
			}
			if (flag_4 == 1)
				printf("Победил пользователь! \n");
			else if (flag_4 == 2)
				printf("Победил компьютер =( \n");
			else
				printf("Победила дружба.... \n");
		}
		printf("Хотите еще, так сказать, посидеть в программе или нет?(да(1) нет(2))\n");
		scanf_s("%d", &choose);
		if (choose == 2)
			flag_prog = false;


	}

	/*
	  ████████████████████████████████████████
	  ███████████░─██████████████████████▒████
	  ███████████─░─███████████████████▓░──▓██
	  ██████████▓─░░─████████████████▒░─░─░▒██
	  ██████████░─░░─░█████████████░─░─░░░─░██
	  ██████████─░░░░░───░░▒▒▒▓██▒──▒─▒█▓░─░██
	  ██████████░─░░░░░░░░░░░░░░░─░▒░░██▒─░░██
	  ███████▓░─░░░░░░░░░░░░░░░░░─█░─░█░──░─██
	  █████▓░░░░░░░░░░░░░░░░░░░░░─▒▒░▓──░░─░██
	  ████───────░░░░░░░░░░░░░░░░░──░██▒▒─░███
	  ███───░██▓░─░░░░░░───────░░░░░──░█░─░███
	  ██▒─░─█░██▓─░░░░░─░▓██▓─░░░░░░░░──░─████
	  ██─░░─░▒██─░░░░░─██▒████─░░░░░░░░░░░▒▒██
	  █▒─░░──────░░░░░─▒▓░██▓░─░░░░░░░░░░░░░░█
	  █░───░█▓───░░░░░────────░░░░░░░░░░░░░░░█
	  ░──▒██████▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ───▓███████░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ─░░─░████▒─░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ──▒█──█▒──░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ░──█████▒░░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░█
	  ▒─░─░████████▓▒▒▒▒░░░░░░░░░░░░░░░░░░░░░█
	  █──░─░▒░──░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  █▓─░░─░▒▒▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ██▒─░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ███▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ███─░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  █░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█
	  ████████████████████████████████████████
	  ████████████████████████████████████████
	  █████████────██────█────█───████████████
	  █████████─██──█─██─█─████─██████████████
	  █████████─██──█─██─█─█──█───████████████
	  █████████─██──█─██─█─██─█─██████████████
	  █████████────██────█────█───████████████
	  ████████████████████████████████████████
	  ████████████████████████████████████████
	  */
}