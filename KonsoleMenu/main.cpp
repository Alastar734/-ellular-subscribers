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

int main(){
	string ra, login, pass, rpass, rlogin, clogin, cpass;
	setlocale(LC_ALL, "russian");
    cout << "Разработка программы учета сведений об абонентах сотовой связи!" << endl << "регистрация/авторизация(r/a): ";
    cin >> ra;
    if (ra == "r")
    {
        cout << "логин: ";
        cin >> rlogin;
        cout << "пароль: ";
        cin >> rpass;
        ofstream flogin("login.txt");
        flogin << rlogin;
        flogin.close();
        ofstream fpass("pass.txt");
        fpass << rpass;
        fpass.close();
    };
    if (ra == "a")
    {
        cout << "...загрузка..." << endl;
        ifstream flogin("login.txt");
        ifstream fpass("pass.txt");
        while (!flogin.eof() & !fpass.eof())
        {
            flogin >> clogin;
            fpass >> cpass;
        };
        cout << "логин: ";
        cin >> login;
        cout << "пароль: ";
        cin >> pass;
        fpass.close();
        flogin.close();
        if (login == clogin & pass == cpass)
        {
            cout << "Добро пожаловать! Пользователь: " << login  << endl;
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
        else if (login != clogin)
         {
            cerr << "Error: invalid login" << endl;
            system("pause");
        }
        else if(pass != cpass)
        {
            cerr << "Error: invalid password" << endl;
            system("pause");
        };
    };
    if (ra != "a" & ra != "r")
    {
        cerr << "Fatal error: invalid value" << endl;
        system("pause");
    };
}
