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

void inputContainerSubscriber(vector<Subscribers> &staff);
void printContainerSubscriber(vector<Subscribers> &staff);
void findItemContainerSubscriber(vector<Subscribers> &staff);
void sortContainerSubscriber(vector<Subscribers> &staff);
void eraseItemContainerSubscriber(vector<Subscribers> &staff);
class Pred_full_name;
class Pred_connection_year;
class Pred_current_tariff_plan;

/////////////////////////////////////////

int main() {
	setlocale(LC_ALL, "russian");
	vector<Subscribers> staff;
	int code;
	{

		do {
			cout << "------------------------------------------------------------------------------------------------- " << endl;
			cout << " 1 - ввести нового абонента   |   3 - удалить абонента из сети  |  5 - поиск абонентов          | " << endl;
			cout << " 2 - вывести список абонентов |   4 - сортировка абонентов      |  6 - индивидуальное задание   | " << endl;
			cout << "------------------------------------------------------------------------------------------------- " << endl;
			cout << " 0 - выход                                                                                        " << endl;
			cin >> code;
			system("cls");
			switch (code) {
			case 1:
				inputContainerSubscriber(staff);
				break;
			case 2:
				printContainerSubscriber(staff);
				break;
			case 3:
				eraseItemContainerSubscriber(staff);
				break;
			case 4:
				sortContainerSubscriber(staff);
				break;
			case 5:
				findItemContainerSubscriber(staff);
				break;
			}
		} while (code != 0);

		cout << "by by";

	}
	return 0;
}
