#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "Сellular subscribers.h"

using namespace std;

bool pred_full_name(const Subscribers &item1, const Subscribers &item2) {
	return item1.full_name < item2.full_name;
}
bool pred_number_phone(const Subscribers &item1, const Subscribers &item2) {
	return item1.number_phone < item2.number_phone;
}
bool pred_connection_year(const Subscribers &item1, const Subscribers &item2) {
	return item1.connection_year < item2.connection_year;
}
bool pred_current_tariff_plan(const Subscribers &item1, const Subscribers &item2) {
	return item1.current_tariff_plan < item2.current_tariff_plan;
}
////////////////////metod/////////////////
void inputContainerSubscriber(vector<Subscribers> &staff) {
	cout << "Введите кол-во абонентов для заполнения => ";
	int n;
	cin >> n;

	string full_name;
	int number_phone;
	int connection_year;
	string current_tariff_plan;

	ofstream f;
	f.open("Subscriber.txt", ios::out);
	for (int i = 0; i < n; i++) {
		fflush(stdin);

		cout << "Введите ФИО абонента ----> ";
		getline(cin, full_name);
		f << full_name << "\t";

		cout << "Введите текущий тарифный план абонента ----> ";
		getline(cin, current_tariff_plan);
		f << current_tariff_plan << "\t";

		cout << "Введите номер телефона абонента ----> ";
		cin >> number_phone;
		f << number_phone << "\t";

		cout << "Введите год подключения абонента ----> ";
		cin >> connection_year;
		f << connection_year << "\t";

		fflush(stdin);

		Subscribers sub(full_name,number_phone,connection_year,current_tariff_plan);
		staff.push_back(sub);
	}
	f.close();
}

void printContainerSubscriber(vector<Subscribers> &staff) {
	vector<Subscribers>::iterator it;
	for (it = staff.begin(); it != staff.end(); ++it)
		cout << it->printFormat() << endl;
	cout << endl;
}

class Pred_full_name {
private:
	string full_name;
public:
	Pred_full_name(string _full_name) {
		full_name = _full_name;
	}
	bool operator ()(Subscribers &item) {
		return item.get_full_name() == full_name;
	}
};

class Pred_connection_year {
private:
	int connection_year;
public:
	Pred_connection_year(int _connection_year) {
		connection_year = _connection_year;
	}
	bool operator ()(Subscribers &item) {
		return item.get_connection_year() == connection_year;
	}
};

class Pred_current_tariff_plan {
private:
	string current_tariff_plan;
public:
	Pred_current_tariff_plan(string _current_tariff_plan) {
		current_tariff_plan = _current_tariff_plan;
	}
	bool operator ()(Subscribers &item) {
		return item.get_current_tariff_plan() == current_tariff_plan;
	}
};

void findItemContainerSubscriber(vector<Subscribers> &staff) {
	cout << "Выберите поле для поиска:" << endl;
	cout << "1 - ФИО абонента \n2 - Наименование текущего тарифного плана\n3 - Год подключения абонента\n---->";
	int code;
	cin >> code;
	vector<Subscribers>::iterator it;
	fflush(stdin);
	switch (code) {
	case 1: {
		cout << "Введите ФИО абонента для поиска\n---->";
		string full_name;
		getline(cin, full_name);
		it = find_if(staff.begin(), staff.end(), Pred_full_name(full_name));
		break;
	}
	case 2: {
		cout << "Введите год подключения абонента для поиска\n---->";
		int connection_year;
		cin >> connection_year;
		it = find_if(staff.begin(), staff.end(), Pred_connection_year(connection_year));
		break;
	}
	default: {
		cout << "Введите наименование текущего тарифного плана абонента для поиска\n---->";
		string current_tariff_plan;
		getline(cin, current_tariff_plan);
		it = find_if(staff.begin(), staff.end(), Pred_current_tariff_plan(current_tariff_plan));
		break;
	}
	}
	cout << "Результаты поиска:" << endl;
	if (it != staff.end())
		cout << it->printFormat();
	else
		cout << "Элементов не найдено";
}

void eraseItemContainerSubscriber(vector<Subscribers> &staff) {
	cout << "Введите позицию для удаления =>";
	int pos;
	cin >> pos;
	if (pos > staff.size() || pos < 0) return;
	vector<Subscribers>::iterator it = staff.begin();
	it += pos; // только для вектора
	staff.erase(it);
}

void sortContainerSubscriber(vector<Subscribers> &staff) {
	cout << "Выберите поле для сортировки:" << endl;
	cout << "1 - ФИО абонента \n2 - Наименование текущего тарифа \n3 - Год подключения \n=>";
	int code;
	cin >> code;
	fflush(stdin);
	switch (code) {
	case 1: {
		sort(staff.begin(), staff.end(), pred_full_name);
		break;
	}
	case 2: {
		sort(staff.begin(), staff.end(), pred_current_tariff_plan);
		break;
	}
	case 3: {
		sort(staff.begin(), staff.end(), pred_connection_year);
		break;
	}
	}
}