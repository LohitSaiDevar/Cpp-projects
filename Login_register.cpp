//Login and registration
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;

string user, pass, un, pw;
bool login()
{
	ifstream in("D:\\" + user + ".txt");
	getline(in, un);
	getline(in, pw);

	if (un == user && pw == pass)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int choice;
	system("CLS");
	cout << "1) Register\n2) Login\n\nChoice: ";
	cin >> choice;

	if (choice == 1)
	{
		cout << "Enter a new username: ";
		cin >> user;

		cout << "Enter a new password: ";
		cin >> pass;

		ofstream out;
		out.open("D:\\" + user + ".txt");
		cout << user << endl << pass;
		out << user << endl << pass;
		out.close();

		main();
	}
	else if (choice == 2)
	{
		cout << "Enter your username: ";
		cin >> user;

		cout << "Enter your password: ";
		cin >> pass;

		bool status = login();

		if (!status)
		{
			cout << "Invalid Username and password\n\n";
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "You've successfully logged in!\n\n";
			system("PAUSE");
			return 1;
		}
	}
}
