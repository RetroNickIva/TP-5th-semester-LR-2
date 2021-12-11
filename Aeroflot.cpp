#include "Aeroflot.h"

Aeroflot::Aeroflot() : destination("�� ������"), airplaneType("�� ������"), flightNumber(0)
{
	cout << "������ ����������� Aeroflot" << endl;
}

Aeroflot::Aeroflot(string destination, string airplaneType, int flightNumber) :
	destination(destination), airplaneType(airplaneType), flightNumber(flightNumber)
{
	cout << "������ ����������� Aeroflot" << endl;
}

Aeroflot::Aeroflot(const Aeroflot& aeroflot) : destination(aeroflot.destination), airplaneType(aeroflot.airplaneType), flightNumber(aeroflot.flightNumber)
{
	cout << "������ ����������� ����������� Aeroflot" << endl;
}

Aeroflot::~Aeroflot()
{
	cout << "������ ���������� Aeroflot" << endl;
}

void Aeroflot::inputFromConsole()
{
	cout << "������� �������� ������ ���������� �����: ";
	getline(cin, destination);
	cout << "������� ��� ��������: ";
	getline(cin, airplaneType);
	cout << "������� ����� �����: ";
	flightNumber = safeInput(1, 100000);
}

void Aeroflot::printToConsole()
{
	cout << "������ ���������� �����: " << destination << endl;
	cout << "��� ��������: " << airplaneType << endl;
	cout << "����� �����: " << flightNumber << endl;
}

void Aeroflot::change()
{
	cout << "������� ����� �������� ������ ���������� �����: ";
	getline(cin, destination);
	cout << "������� ����� ��� ��������: ";
	getline(cin, airplaneType);
	cout << "������� ����� ����� �����: ";
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