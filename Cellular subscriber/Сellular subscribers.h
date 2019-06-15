#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>


using namespace std;

// перевод числа value в строку
template<class T>
string toString(T value) {
	ostringstream sd;
	sd << value;
	return sd.str();
}
//перевод строки str в число типа T
template<class T>
T fromString(string str) {
	istringstream sd(str);
	T value;
	sd >> value;
	return value;
}
class Subscribers {
private:
	string full_name;
	int number_phone;
	int connection_year;
	string current_tariff_plan;
public:
	Subscribers() {
	}
	Subscribers(string full_name, int number_phone, int connection_year, string current_tariff_plan) {
		this->full_name = full_name;
		this->number_phone = number_phone;
		this->connection_year = connection_year;
		this->current_tariff_plan = current_tariff_plan;
	}
	void set_full_name(string full_name) {
		this->full_name = full_name;
	}
	void set_number_phone(int number_phone) {
		this->number_phone = number_phone;
	}
	void set_connection_year(int connection_year) {
		this->connection_year = connection_year;
	}
	void set_current_tariff_plan(string current_tariff_plan) {
		this->current_tariff_plan = current_tariff_plan;
	}
	string get_full_name() {
		return full_name;
	}
	int get_number_phone() {
		return number_phone;
	}
	int get_connection_year() {
		return connection_year;
	}
	string get_current_tariff_plan() {
		return current_tariff_plan;
	}
	string printFormat() {
		return "ФИО абонента - " + full_name + ", номер телефона - " + toString<int>(number_phone) + ", год подключения - " + toString<int>(connection_year) + ", наименование текущего тарифного плана - " + current_tariff_plan;
	}
	friend bool pred_full_name(const Subscribers &item1, const Subscribers &item2);
	friend bool pred_number_phone(const Subscribers &item1, const Subscribers &item2);
	friend bool pred_connection_year(const Subscribers &item1, const Subscribers &item2);
	friend bool pred_current_tariff_plan(const Subscribers &item1, const Subscribers &item2);
};
