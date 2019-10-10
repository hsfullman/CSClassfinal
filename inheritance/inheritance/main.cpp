#include <iostream>
#include "inheritance.h"
using namespace std;

int main()
{

	Car miniVan(1000, 4, 7, "Dodge Caravan", true, 1);
	cout << "Mini Van:";
	cout << "\n Weight = " << miniVan.getWeight();
	cout << "\n Number of Tires = " << miniVan.getNumTires();
	cout << "\n Radio = " << miniVan.getRadio();
	cout << "\n Model = " << miniVan.getModel();
	cout << "\n Number of Doors = " << miniVan.getNumDoors();
	cout << "\n Number of Passengers = " << miniVan.getNumPassengers();

	Bike myBike(50, 2, 1, "Trek", 5);
	cout << "\nMy Bike:";
	cout << "\n Weight = " << myBike.getWeight();
	cout << "\n Number of Tires = " << myBike.getNumTires();
	cout << "\n Number of Passengers = " << myBike.getNumPassengers();
	cout << "\n Model = " << myBike.getModel();
	cout << "\n Helmet Size = " << myBike.getHelmetSize();


}