#pragma once
#include "helper.h"
#include "Marray.h"
using namespace std;

class Aeroflot
{
private:
	string destination, airplaneType;
	int flightNumber;

public:
	Aeroflot();
	Aeroflot(string destination, string airplaneType, int flightNumber);
	Aeroflot(const Aeroflot& aeroflot);
	~Aeroflot();

	void inputFromConsole();
	void printToConsole();
	void change();
	void checkEquipment();

	string getDestination() { return destination; }
	void setDestination(string destination) { this->destination = destination; }

	string getAirplaneType() { return airplaneType; }
	void setAirplaneType(string airplaneType) { this->airplaneType = airplaneType; }

	int getFlightNumber() { return flightNumber; }
	void setFlightNumber(int flightNumber) { this->flightNumber = flightNumber; }

	Aeroflot& operator=(const Aeroflot& aeroflot);
	bool operator>(Aeroflot& aeroflot);
};