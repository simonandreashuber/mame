#include "mane.h"

int main()
{
	//create:
	ime reileen({ 2,3,7 }); //2^3^7

	//calculate:
	reileen % 1999;
	reileen.mod(1999);
}