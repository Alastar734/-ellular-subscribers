#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "�ellular subscribers.h"

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
    cout << "���������� ��������� ����� �������� �� ��������� ������� �����!" << endl << "�����������/�����������(r/a): ";
    cin >> ra;
    if (ra == "r")
    {
        cout << "�����: ";
        cin >> rlogin;
        cout << "������: ";
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
        cout << "...��������..." << endl;
        ifstream flogin("login.txt");
        ifstream fpass("pass.txt");
        while (!flogin.eof() & !fpass.eof())
        {
            flogin >> clogin;
            fpass >> cpass;
        };
        cout << "�����: ";
        cin >> login;
        cout << "������: ";
        cin >> pass;
        fpass.close();
        flogin.close();
        if (login == clogin & pass == cpass)
        {
            cout << "����� ����������! ������������: " << login  << endl;
			vector<Subscribers> staff;
			int code;
			{

				do {
			cout << "------------------------------------------------------------------------------------------------- " << endl;
			cout << " 1 - ������ ������ ��������   |   3 - ������� �������� �� ����  |  5 - ����� ���������          | " << endl;
			cout << " 2 - ������� ������ ��������� |   4 - ���������� ���������      |  6 - �������������� �������   | " << endl;
			cout << "------------------------------------------------------------------------------------------------- " << endl;
			cout << " 0 - �����                                                                                        " << endl;
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
