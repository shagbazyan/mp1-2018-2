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

	printf("Enter the height, width and depth of the wardrobe\n");
	scanf_s("%d %d %d", &height, &width, &depth);

	reminder = (height * 10) % 400;
	quantity = height * 10 / 400;
	if (reminder < quantity)
	{
		quantity--;
		reminder = reminder + 400;
	}
	shelf_thickness = reminder / quantity;
	if (shelf_thickness > 40)
		shelf_thickness = 40;

	back_mass = DVP * (height / 100.0) * (width / 100.0) * BACK_THICKNESS;
	side_mass = DSP * (height / 100.0) * (depth / 100.0) * SIDE_THICKNESS;
	cover_mass = DSP * (width / 100.0) * (depth / 100.0) * COVER_THICKNESS;
	door_mass = WOOD * (height / 100.0) * (width / 100.0) * DOOR_THICKNESS;
	shelf_mass = DSP * ((width / 100.0) - 2 * SIDE_THICKNESS) * ((depth / 100.0) - BACK_THICKNESS - DOOR_THICKNESS) * (shelf_thickness / 1000.0);

	mass = back_mass + 2 * side_mass + 2 * cover_mass + door_mass + quantity * shelf_mass;
	printf("The mass of the wardrobe is %f kg", mass);

	_getch();
}