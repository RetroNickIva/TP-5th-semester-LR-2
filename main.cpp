#include "Aeroflot.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void printMenu();
void addObject(Marray<Aeroflot>& aeroflots);
void changeObject(Marray<Aeroflot>& aeroflots);
void deleteObject(Marray<Aeroflot>& aeroflots);
void print(Marray<Aeroflot>& aeroflots);
void searchObjects(Marray<Aeroflot>& aeroflots);
void checkEquipment(Marray<Aeroflot>& aeroflots);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Aeroflot> aeroflots;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 6);
		cout << endl;
		switch (method)
		{
		case 1:
			addObject(aeroflots);
			cout << endl;
			break;
		case 2:
			changeObject(aeroflots);
			cout << endl;
			break;
		case 3:
			deleteObject(aeroflots);
			cout << endl;
			break;
		case 4:
			print(aeroflots);
			cout << endl;
			break;
		case 5:
			searchObjects(aeroflots);
			cout << endl;
			break;
		case 6:
			checkEquipment(aeroflots);
			cout << endl;
			break;

		case 0:
			isExit = true;
			break;
		}
	}
}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "5. Вывести пункты назначения и номера рейсов, обслуживаемых самолетов, тип которого введен с клавиатуры" << endl;
	cout << "6. Вывести назначение самолета" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Marray<Aeroflot>& aeroflots) {
	Aeroflot airplane;
	airplane.inputFromConsole();
	aeroflots += airplane;
	aeroflots.sort();
}

void changeObject(Marray<Aeroflot>& aeroflots) {
	if (aeroflots.getSize() > 0) {
		print(aeroflots);
		cout << "Введите название пункта назначения рейса: ";
		aeroflots[safeInput(1, aeroflots.getSize()) - 1].change();
	}
	else
		cout << "Список рейсов пуст. Нечего изменять\n";
	aeroflots.sort();
}

void deleteObject(Marray<Aeroflot>& aeroflots) {
	if (aeroflots.getSize() > 0) {
		print(aeroflots);
		cout << "Введите номер рейса для удаления: ";
		aeroflots -= safeInput(1, aeroflots.getSize()) - 1;
	}
	else
		cout << "Список рейсов пуст. Нечего удалять\n";
	aeroflots.sort();
}

void print(Marray<Aeroflot>& aeroflots) {
	if (aeroflots.getSize() == 0)
		cout << "Список рейсов пуст.\n";
	else {
		cout << "Список рейсов\n";
		for (int i = 0; i < aeroflots.getSize(); i++) {
			cout << i + 1 << ". Рейс\n";
			aeroflots[i].printToConsole();
		}
	}
}

void searchObjects(Marray<Aeroflot>& airplaneType) {
	if (airplaneType.getSize() == 0)
		cout << "Список рейсов пуст\n";
	else {
		bool isPrint = false;
		cout << "Введите тип самолета: ";
		string type;
		getline(cin, type);
		cout << endl;
		for (int i = 0; i < airplaneType.getSize(); i++) {
			if (airplaneType[i].getAirplaneType() == type) {
				isPrint = true;
				airplaneType[i].printToConsole();
				cout << endl;
			}
		}
		if (!isPrint)
			cout << "Самолетов с таким типом нет\n";
	}
}

void checkEquipment(Marray<Aeroflot>& aeroflots) {
	string equipment[7] = { "грузовой", "пассажирский", "спасательный", "военный", "частный",
		"спец-борт", "пожарный" };

	if (aeroflots.getSize() == 0)
		cout << "Рейсов нет" << endl;
	else
	{
		for (int i = 0; i < aeroflots.getSize(); i++) {
			cout << i + 1 << ". Рейс\n";
			aeroflots[i].printToConsole();
			cout << endl;
		}
		cout << "Введите номер рейса, назначение самолета которого, хотите узнать: ";
		int choice1 = safeInput(1, aeroflots.getSize());

		srand(time(NULL));
		int checkAirplane = rand() % 7;
		cout << "Назначение самолета: " << equipment[checkAirplane] << endl;
	}
}