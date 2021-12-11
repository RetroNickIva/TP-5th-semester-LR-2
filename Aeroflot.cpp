#include "Aeroflot.h"

Aeroflot::Aeroflot() : destination("Не задано"), airplaneType("Не задано"), flightNumber(0)
{
	cout << "Вызван конструктор Aeroflot" << endl;
}

Aeroflot::Aeroflot(string destination, string airplaneType, int flightNumber) :
	destination(destination), airplaneType(airplaneType), flightNumber(flightNumber)
{
	cout << "Вызван конструктор Aeroflot" << endl;
}

Aeroflot::Aeroflot(const Aeroflot& aeroflot) : destination(aeroflot.destination), airplaneType(aeroflot.airplaneType), flightNumber(aeroflot.flightNumber)
{
	cout << "Вызван конструктор копирования Aeroflot" << endl;
}

Aeroflot::~Aeroflot()
{
	cout << "Вызван деструктор Aeroflot" << endl;
}

void Aeroflot::inputFromConsole()
{
	cout << "Введите название пункта назначения рейса: ";
	getline(cin, destination);
	cout << "Введите тип самолета: ";
	getline(cin, airplaneType);
	cout << "Введите номер рейса: ";
	flightNumber = safeInput(1, 100000);
}

void Aeroflot::printToConsole()
{
	cout << "Пункта назначения рейса: " << destination << endl;
	cout << "Тип самолета: " << airplaneType << endl;
	cout << "Номер рейса: " << flightNumber << endl;
}

void Aeroflot::change()
{
	cout << "Введите новое название пункта назначения рейса: ";
	getline(cin, destination);
	cout << "Введите новый тип самолета: ";
	getline(cin, airplaneType);
	cout << "Введите новый номер рейса: ";
	flightNumber = safeInput(1, 100000);
}

Aeroflot& Aeroflot::operator=(const Aeroflot& aeroflot) {
	if (this == &aeroflot)
		return *this;
	destination = aeroflot.destination;
	airplaneType = aeroflot.airplaneType;
	flightNumber = aeroflot.flightNumber;
	return *this;
}

bool Aeroflot::operator>(Aeroflot& aeroflot) {
	return destination > aeroflot.destination;
}