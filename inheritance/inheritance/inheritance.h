#pragma once
#include <iostream>
//make attributes private
using namespace std;
class Vehicle {
public:
	int weight;
	int num_tires;
	int num_passengers;
	string model;

	Vehicle();
	Vehicle(int weight, int num_tires, int num_passengers, string model);

	int getWeight() {
		return weight;
	}

	int getNumTires() {
		return num_tires;
	}

	int getNumPassengers() {
		return num_passengers;
	}

	string getModel() {
		return model;
	}
};

class Car : public Vehicle {
private:
	bool radio;
	int num_doors;
public:
	Car();
	Car(int weight, int num_tires, int num_passengers, string model, bool radio1, int num_doors1);

	bool getRadio() {
		return radio;
	}

	int getNumDoors() {
		return num_doors;
	}
};

class Bike : public Vehicle {
private:
	int helmetSize;
public:
	Bike();
	Bike(int weight, int num_tires, int num_passengers, string model, int helmetSize);
	int getHelmetSize() {
		return helmetSize;
	}
};