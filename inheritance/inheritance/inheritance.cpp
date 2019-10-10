#include <iostream>
#include "inheritance.h"
using namespace std;

Vehicle::Vehicle() {

};
Vehicle::Vehicle(int weight1, int num_tires1, int num_passengers1, string model1) {
	weight = weight1;
	num_tires = num_tires1;
	num_passengers = num_passengers1;
	model = model1;
};

Car::Car() {

}
Car::Car(int weight1, int num_tires1, int num_passengers1, string model1, bool radio1, int num_doors1) 
: Vehicle(weight1, num_tires1, num_passengers1, model1)
{
	weight = weight1;
	num_tires = num_tires1;
	num_passengers = num_passengers1;
	model = model1;
	radio = radio1;
	num_doors = num_doors1;
}


Bike::Bike() {

}
Bike::Bike(int weight1, int num_tires1, int num_passengers1, string model1, int helmetSize1) 
: Vehicle(weight1, num_tires1, num_passengers1, model1)
{
	weight = weight1;
	num_tires = num_tires1;
	num_passengers = num_passengers1;
	model = model1;
	helmetSize = helmetSize1 ;
}
