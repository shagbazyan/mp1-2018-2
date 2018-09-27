#include <stdio.h>
#include <conio.h>

#define DSP 650
#define DVP 820
#define WOOD 510
#define BACK_THICKNESS 0.005
#define SIDE_THICKNESS 0.015
#define COVER_THICKNESS 0.015
#define DOOR_THICKNESS 0.01

int main()
{
	int height, width, depth;
	int reminder, quantity, shelf_thickness;
	float mass, back_mass, side_mass, cover_mass, door_mass, shelf_mass;
	int another;

	do
	{
		printf("Enter the height, width and depth of the wardrobe in cm\n");
		scanf_s("%d %d %d", &height, &width, &depth);
		printf("Enter the thickness of the shelves in mm\n");
		scanf_s("%d", &shelf_thickness);

		reminder = (height * 10) % 400;
		quantity = height * 10 / 400;
		if (reminder < quantity * shelf_thickness)
			quantity--;

		back_mass = DVP * (height / 100.0) * (width / 100.0) * BACK_THICKNESS;
		side_mass = DSP * (height / 100.0) * (depth / 100.0) * SIDE_THICKNESS;
		cover_mass = DSP * (width / 100.0) * (depth / 100.0) * COVER_THICKNESS;
		door_mass = WOOD * (height / 100.0) * (width / 100.0) * DOOR_THICKNESS;
		shelf_mass = DSP * ((width / 100.0) - 2 * SIDE_THICKNESS) * ((depth / 100.0) - BACK_THICKNESS - DOOR_THICKNESS) * (shelf_thickness / 1000.0);

		mass = back_mass + 2 * side_mass + 2 * cover_mass + door_mass + quantity * shelf_mass;
		printf("\n");
		printf("The mass of the wardrobe is %f kg\n", mass);

		printf("\n");
		printf("Want to enter new parameters of the wardrobe?\n");
		printf("1 - Yes; 0 - No\n");
		scanf_s("%d", &another);

	} while (another == 1);
}