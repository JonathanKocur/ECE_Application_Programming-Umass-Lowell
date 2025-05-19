// Jonathan Kocur
// 1/28/23
// Program 2


/* This program takes inputs for specifications of a wall's dimensions and paint cost per can, 
and calculates the total cost of paint that is needed for the project. */

#include <stdio.h>
#include <math.h>

int main() {

	// The initialized values below represent the input variables
	double WallHeight = 8.0;
	double WallWidth = 8.0;
	double PaintCanCost = 49.20;
	

	// These variables are the output varibles of the program
	double WallArea;
	double PaintNeeded;
	double CansNeeded;
	double PaintCost;
	double SalesTax;
	double TotalCost;


	// This is the scan of the input variables
	//scanf("%lf", &WallHeight);
	//scanf("%lf", &WallWidth);
	//scanf("%lf", &PaintCanCost);


	// The mathematical functions used to calculate the outputs with the given inputs
	WallArea = WallWidth * WallHeight;
	PaintNeeded = WallArea / 350;
	CansNeeded = ceil(PaintNeeded);
	PaintCost = CansNeeded * PaintCanCost;
	SalesTax = PaintCost * 0.07;
	TotalCost = PaintCost + SalesTax;


	// The print of all of the variables
	printf("Wall area: %0.1lf sq ft\n", WallArea);
	printf("Paint needed: %0.3lf gallons\n", PaintNeeded);
	printf("Cans needed: %0.0lf can(s)\n", CansNeeded);
	printf("Paint cost: $%0.2lf\n", PaintCost);
	printf("Sales tax: $%0.2lf\n", SalesTax);
	printf("Total cost: $%0.2lf\n", TotalCost);

	return 0;
}
