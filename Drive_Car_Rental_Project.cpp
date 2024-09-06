#include <iostream> // To inout / output in the terminal
#include <fstream>  // To read / write / append in text file
#include <string>	// To use string functions
#include <stdlib.h>
#include <cstdlib>
#include <vector>  //To use vectors
#include <conio.h> 

using namespace std;

class mainMenu {   // Creating main menu class
public:

	void menu();  // Defining the menu method
};


class clients : public mainMenu {     // Creating clients class 
public:

	virtual void clientMenu() {     // Display clients menu

		int choice;
		cout << "\t -----------------------------------------\n";
		cout << "\t|                                         |\n";
		cout << "\t|                 Clients                 |\n";
		cout << "\t|                                         |\n";
		cout << "\t -----------------------------------------\n";
		cout << "\t|                                         |\n";
		cout << "\t|    1. List of current clients           |\n";
		cout << "\t|                                         |\n";
		cout << "\t|    2. Specific information of a client  |\n";
		cout << "\t|                                         |\n";
		cout << "\t|    3. Add a new client                  |\n";
		cout << "\t|                                         |\n";
		cout << "\t|    4. Update a client information       |\n";
		cout << "\t|                                         |\n";
		cout << "\t|    5. Back to Main Menu                 |\n";
		cout << "\t|                                         |\n";
		cout << "\t -----------------------------------------\n";
		cout << "\t                                          \n";
		cout << "\t           Please Select : ";
		cin >> choice;
		cout << "\t                                         \n";

		switch (choice) {
		case 1: {
			system("cls");
			currentClient();  // Calling the currentClient method to display the list
		}
		case 2: {
			system("cls");
			specificClient(); // Calling the specificClient method to display a client info
		}
		case 3: {
			system("cls");
			addClient(); // Calling the addClient to add a new client
		}
		case 4: {
			system("cls");
			updateClient(); // Calling the updateClient to update the client info
		}
		case 5: {
			system("cls");
			mainMenu d; // Creating a object of a class
			d.menu();   // Calling the method through the object
		}
		default: {

			cout << "\t                                         \n";
			cout << "\t   Please choose from the given options! \n";
			clientMenu();
		}

		}

	}
	void currentClient() {

		fstream currClients; // Using the fstream lib variable to read the text file

		string fname, lname, dateofBirth, address;
		int driLisNo, saleTT;

		currClients.open("Currentclient.txt", ios::in); // Opening the client text file in read mode
		if (currClients.is_open()) {
			cout << "\t -----------------------------------------\n";
			cout << "\t|                                         |\n";
			cout << "\t|          Current Clients List           |\n";
			cout << "\t|                                         |\n";
			cout << "\t -----------------------------------------\n";

			while (currClients >> driLisNo >> fname >> lname >> dateofBirth >> address >> saleTT) {

				cout << "\t                                 \n";
				cout << "\t        Drivers Lic No : " << driLisNo << "\n";
				cout << "\t        Name           : " << fname << " " << lname << "\n";
				cout << "\t        Date of Birth  : " << dateofBirth << "\n";
				cout << "\t        Address        : " << address << "\n";
				cout << "\t        Sales          : $" << saleTT << "\n";
				cout << "\t                                  \n";

			}
			currClients.close();  // Closing the client text file
		}
		clientMenu(); // Calling the client menu after done.
	}

	void specificClient() {

		fstream currClients; // Using the fstream lib variable to read the text file
		int driLis;
		string fname, lname, dateofBirth, address;
		int driLisNo, saleTT, count = 0;

		currClients.open("Currentclient.txt", ios::in);  // Opening the client text file in read mode
		cout << "\t -----------------------------------------\n";
		cout << "\t|                                         |\n";
		cout << "\t|      Specific Client's Information      |\n";
		cout << "\t|                                         |\n";
		cout << "\t -----------------------------------------\n";
		cout << "\t                                 \n";
		cout << "\tEnter the Client's Drivers License no: ";
		cin >> driLis;
		cout << "\t                                 \n";
		while (!currClients.eof()) {
			currClients >> driLisNo >> fname >> lname >> dateofBirth >> address >> saleTT;

			if (driLis == driLisNo) {

				cout << "\t                                  \n";
				cout << "\t        Name           : " << fname << " " << lname << "\n";
				cout << "\t        Date of Birth  : " << dateofBirth << "\n";
				cout << "\t        Address        : " << address << "\n";
				cout << "\t        Sales          : $" << saleTT << "\n";
				cout << "\t                                  \n";
				count++;
				break;
			}

		}
		currClients.close();  // Closing the client text file
		if (count == 0) {
			cout << "\t\t      No Client Found!  \n";
			cout << "\t\t                       \n";

		}
		clientMenu();  // Calling the client menu after done.
	}

	void addClient() {

		fstream currClients; // Using the fstream lib variable to read the text file
		string fname, lname, dateofBirth, address;
		int driLisNo, saleTT;

		currClients.open("Currentclient.txt", ios::app);  // Opening the client text file in append mode(to add)
		if (currClients.is_open()) {
			cout << "\t -----------------------------------------\n";
			cout << "\t|                                         |\n";
			cout << "\t|            Add a New Client             |\n";
			cout << "\t|                                         |\n";
			cout << "\t -----------------------------------------\n";
			cout << "\t                                           \n";

			cout << "\t      Drivers License No: ";
			cin >> driLisNo;
			cout << "\t                                 \n";
			cout << "\t      Name: ";
			cin >> fname >> lname;
			cout << "\t                                 \n";
			cout << "\t      Date of Birth: ";
			cin >> dateofBirth;
			cout << "\t                                 \n";
			cout << "\t      Address: ";
			cin >> address;
			cout << "\t                                 \n";
			cout << "\t      Sales: $";
			cin >> saleTT;
			cout << "\t                                 \n";
			currClients << "\n";
			currClients << driLisNo << " " << fname << " " << lname << " " << dateofBirth << " " << address << " " << saleTT;


			currClients.close();  // Closing the clients text file
			cout << "\t     New client is successfully added! \n";
			cout << "\t                       \n";
		}
		clientMenu();  // Calling the client menu after done.

	}

	void updateClient() {

		fstream current, temp; // Using the fstream lib variable to read the text file

		int driL, salet, count = 0;
		string firstn, lastn, datebirth, addrs;

		int udriL, usalet, userCrn;
		string ufirstn, ulastn, udatebirth, uaddrs;

		cout << "\t -----------------------------------------\n";
		cout << "\t|                                         |\n";
		cout << "\t|        Update Clients Information       |\n";
		cout << "\t|                                         |\n";
		cout << "\t -----------------------------------------\n";
		cout << "\t                                           \n";
		cout << "\t Enter the Client's Drivers License Number: ";
		cin >> userCrn;
		cout << "\t                                    \n";

		current.open("Currentclient.txt", ios::in);
		temp.open("Tempclient.txt", ios::app | ios::out); // Opening a temparory text file in append and write mode.

		while (current >> driL >> firstn >> lastn >> datebirth >> addrs >> salet) {
			if (driL != userCrn) {
				temp << driL << " " << firstn << " " << lastn << " " << datebirth <<
					" " << addrs << " " << salet << "\n";
			}
			else {
				cout << "\t      Drivers License No: ";
				cin >> udriL;
				cout << "\t                                 \n";
				cout << "\t      Name: ";
				cin >> ufirstn >> ulastn;
				cout << "\t                                 \n";
				cout << "\t      Date of Birth: ";
				cin >> udatebirth;
				cout << "\t                                 \n";
				cout << "\t      Address: ";
				cin >> uaddrs;
				cout << "\t                                 \n";
				cout << "\t      Sales: $";
				cin >> usalet;
				cout << "\t                                 \n";

				temp << udriL << " " << ufirstn << " " << ulastn << " " << udatebirth <<
					" " << uaddrs << " " << usalet << "\n";
				count++;
			}

		}
		if (count == 0) {
			cout << "\t\t     No Client Found! \n";
			cout << "\t\t                     \n";
		}
		else {
			cout << "\t Client's Information is successfully updated! \n";
			cout << "\t\t                     \n";

		}
		current.close();
		temp.close();
		remove("Currentclient.txt");
		rename("Tempclient.txt", "Currentclient.txt");
		clientMenu();
	}
};



class salesRepresentatives
{

public:
	string name, phone_no, address, email_id;
	void salesList();
	void salesMenu();
	void insert();
	void modify();
};

void salesRepresentatives::salesMenu()
{
menustart:

	int choice;
	char x;

	cout << "\t -----------------------------------------\n";
	cout << "\t ------ Hello Sales Representative -------\n";
	cout << "\t -----------------------------------------\n";


	cout << "\t -----------------------------------------\n";
	cout << "\t|                                         |\n";
	cout << "\t|           Sales Reps Menu               |\n";
	cout << "\t|                                         |\n";
	cout << "\t ------------------------------------------\n";
	cout << "\t|                                         |\n";
	cout << "\t|           1. List of Sales Reps         |\n";
	cout << "\t|                                         |\n";
	cout << "\t|           2. Add Sales Rep              |\n";
	cout << "\t|                                         |\n";
	cout << "\t|           3. Update Sales Rep           |\n";
	cout << "\t|                                         |\n";
	cout << "\t|           4. Return to Main Menu        |\n";
	cout << "\t|                                         |\n";
	cout << "\t -----------------------------------------\n";
	cout << "\t                                          \n";
	cout << "\t           Please Select an option: ";
	cin >> choice;
	cout << "\t                                          \n";


	switch (choice) {
	case 1:
	{
		system("cls");
		salesList();  // This "displays the sales reps list 
		break;
	}

	case 2:
	{
		system("cls");

		do
		{
			insert();
			cout << "\n\t\t Add Sales Rep Record (Y,N): ";
			cin >> x;
			if (x == 'n' || x == 'N') {
				salesMenu();
			}
		} while (x == 'y' || x == 'Y');

		break;

	}
	case 3: {
		system("cls");
		modify();
		break;
	}
	case 4:
	{
		system("cls");
		mainMenu d; // Creating a object of a class
		d.menu();   // Calling the method through the object
	}
	default:
	{
		cout << "\t Please choose from the given options \n";
	}
	int getch();
	goto menustart;

	}

}
void salesRepresentatives::salesList()
{
	system("cls");
	fstream file;
	int total = 1;
	cout << "\t -----------------------------------------\n";
	cout << "\t ------ Sales Representative List --------\n";
	cout << "\t -----------------------------------------\n";
	file.open("salesReplist.txt", ios::in);
	if (!file)
	{
		cout << "\n\t\t\t\t\tNo Data is Present...";
		file.close();
	}
	else {
		file >> name >> phone_no >> email_id >> address;
		while (!file.eof()) {
			cout << "\n\t\t Sales Rep Nbr:  " << total++ << endl;
			cout << "\t\t   Name       :  " << name << endl;
			cout << "\t\t   Phone Nbr. :  " << phone_no << endl;
			cout << "\t\t   Email      :  " << email_id << endl;
			cout << "\t\t   Address    :  " << address << endl;
			file >> name >> phone_no >> email_id >> address;
		}
	}


	file.close();
	if (total == 0)
	{
		cout << "\n\t\ttNo Data is Present...";
	}
	salesMenu();
}

void  salesRepresentatives::insert()
{
	system("cls");
	fstream file;
	cout << "\t -----------------------------------------\n";
	cout << "\t ------- Add Sales Representative --------\n";
	cout << "\t -----------------------------------------\n";
	cout << "\n\t\tEnter Name: ";
	cin >> name;
	cout << "\n\t\tEnter Phone No: ";
	cin >> phone_no;
	cout << "\n\t\tEnter Email Id: ";
	cin >> email_id;
	cout << "\n\t\tEnter Address: ";
	cin >> address;
	file.open("salesReplist.txt", ios::app);
	file << name << " " << phone_no << " " << email_id << " " << address << "\n";
	file.close();
}

void salesRepresentatives::modify() {
	system("cls");
	fstream file, file1;
	int found = 0;
	string name1;
	cout << "\n\t-----------------------------------------" << endl;
	cout << "\n\t|  Sales Rep Modify Details  |" << endl;
	cout << "\n\t-----------------------------------------" << endl;
	if (!file) {
		cout << "\n\t\tNo Data is Present...";
		file.close();
	}
	else {
		cout << "\n Enter Name of Sales Rep you want to Modify:  ";
		cin >> name1;

		file.open("salesReplist.txt", ios::in);
		file1.open("Record.txt", ios::app | ios::out);

		while (file >> name >> phone_no >> email_id >> address)
		{
			if (name1 != name) {
				file1 << name << " " << phone_no << " " << email_id << " " << address << "\n";

			}
			else
			{
				cout << "\n\t\t\tEnter Name: ";
				cin >> name;
				cout << "\n\t\t\tEnter Phone No: ";
				cin >> phone_no;
				cout << "\n\t\t\tEnter Email Id: ";
				cin >> email_id;
				cout << "\n\t\t\tEnter Address: ";
				cin >> address;
				file1 << name << " " << phone_no << " " << email_id << " " << address << "\n";
				found++;
			}
		}
		if (found == 0)
		{
			cout << "\n\t\t  Sales Rep not found...." << endl;
		}

		file.close();
		file1.close();
		remove("salesReplist.txt");
		rename("Record.txt", "salesReplist.txt");
		salesMenu();
	}
}








class services {
public:

	virtual void serviceMenu() {

		int choice;
		cout << "\t --------------------------------------------\n";
		cout << "\t|                                            |\n";
		cout << "\t|                 Services                   |\n";
		cout << "\t|                                            |\n";
		cout << "\t --------------------------------------------\n";
		cout << "\t|                                            |\n";
		cout << "\t|    1. List of current Services             |\n";
		cout << "\t|                                            |\n";
		cout << "\t|    2. Specific information of a Service    |\n";
		cout << "\t|                                            |\n";
		cout << "\t|    3. Add a new Service                    |\n";
		cout << "\t|                                            |\n";
		cout << "\t|    4. Update a Service information         |\n";
		cout << "\t|                                            |\n";
		cout << "\t|    5. Back to Main Menu                    |\n";
		cout << "\t|                                            |\n";
		cout << "\t --------------------------------------------\n";
		cout << "\t                                             \n";
		cout << "\t           Please Select : ";
		cin >> choice;
		cout << "\t                                         \n";

		switch (choice) {
		case 1: {
			system("cls");
			currentService();

		}
		case 2: {
			system("cls");
			specificService();
		}
		case 3: {
			system("cls");
			addService();
		}
		case 4: {
			system("cls");
			updateService();
		}
		case 5: {
			system("cls");
			mainMenu d;
			d.menu();
		}
		default: {

			cout << "\t                                         \n";
			cout << "\t    Please choose from the given options! \n";
			serviceMenu();
		}
		}
	}


	void currentService() {
		fstream currService; // Using the fstream lib variable to read the text file

		string plan, car1, car2, car3, range;
		int rate;

		currService.open("CurrentServices.txt", ios::in); // Opening the file in read mode
		if (currService.is_open()) {
			cout << "\t -----------------------------------------\n";
			cout << "\t|                                         |\n";
			cout << "\t|            Current Services             |\n";
			cout << "\t|                                         |\n";
			cout << "\t -----------------------------------------\n";
			while (currService >> plan >> range >> car1 >> car2 >> car3 >> rate) {
				cout << "\t                                        \n";
				cout << "\t      Rental Plan  : " << plan << "\n";
				cout << "\t      Rental Range : " << range << "\n";
				cout << "\t      Cars         : " << car1 << ", " << car2 << ", " << car3 << " \n";
				cout << "\t      Rate         : $" << rate << "\n";
				cout << "\t                                        \n";

			}
			currService.close();  // Closing the text file
		}
		serviceMenu();
	}


	void specificService() {
		fstream service;
		string plan, plan1, car1, car2, car3, range;
		int rate, count = 0;


		service.open("CurrentServices.txt", ios::in);  // Opening the file in read mode
		cout << "\t -----------------------------------------\n";
		cout << "\t|                                         |\n";
		cout << "\t|      Specific Service Information       |\n";
		cout << "\t|                                         |\n";
		cout << "\t -----------------------------------------\n";
		cout << "\t                                 \n";
		cout << "\t   Enter the Rental plan: ";
		cin >> plan1;
		cout << "\t                                 \n";
		while (!service.eof()) {
			service >> plan >> range >> car1 >> car2 >> car3 >> rate;

			if (plan1 == plan) {

				cout << "\t                                        \n";
				cout << "\t      Rental Plan  : " << plan << "\n";
				cout << "\t      Rental Range : " << range << "\n";
				cout << "\t      Cars         : " << car1 << ", " << car2 << ", " << car3 << " \n";
				cout << "\t      Rate         : $" << rate << "\n";
				cout << "\t                                        \n";
				count++;
				break;
			}

		}
		service.close();  // Closing the text file
		if (count == 0) {
			cout << "\t\t      No Service Found!  \n";
			cout << "\t\t                       \n";

		}
		serviceMenu();
	}


	void addService() {
		fstream service;
		string plan, car1, car2, car3, range;
		int rate;

		service.open("CurrentServices.txt", ios::app);  // Opening the file in append mode
		if (service.is_open()) {
			cout << "\t -----------------------------------------\n";
			cout << "\t|                                         |\n";
			cout << "\t|            Add a New Service            |\n";
			cout << "\t|                                         |\n";
			cout << "\t -----------------------------------------\n";
			cout << "\t                                           \n";
			cout << "\t      Rental Plan  : ";
			cin >> plan;
			cout << "\t                                           \n";
			cout << "\t      Rental Range : ";
			cin >> range;
			cout << "\t                                           \n";
			cout << "\t      Cars         : ";
			cin >> car1 >> car2 >> car3;
			cout << "\t                                           \n";
			cout << "\t      Rate         : $";
			cin >> rate;
			cout << "\t                                        \n";
			service << "\n";
			service << plan << " " << range << " " << car1 << " " << car2 << " " << car3 << " " << rate;
			service.close();  // Closing the text file
			cout << "\t     New Service is successfully added! \n";
			cout << "\t                       \n";
		}
		serviceMenu();
	}

	void updateService() {

		fstream currentservice, tempservice;

		int rate, count = 0;
		string plan, range, car1, car2, car3;
		string matchplan;
		int userrate;
		string userplan, userrange, usercar1, usercar2, usercar3;

		cout << "\t -----------------------------------------\n";
		cout << "\t|                                         |\n";
		cout << "\t|        Update Service Information       |\n";
		cout << "\t|                                         |\n";
		cout << "\t -----------------------------------------\n";
		cout << "\t                                           \n";
		cout << "\t Enter the Service plan you want to update: ";
		cin >> matchplan;
		cout << "\t                                    \n";

		currentservice.open("CurrentServices.txt", ios::in);
		tempservice.open("TempService.txt", ios::app | ios::out);

		while (currentservice >> plan >> range >> car1 >> car2 >> car3 >> rate) {
			if (plan != matchplan) {
				tempservice << plan << " " << range << " " << car1 << " " << car2 <<
					" " << car3 << " " << rate << "\n";
			}
			else {
				cout << "\t      Rental Plan: ";
				cin >> userplan;
				cout << "\t                                 \n";
				cout << "\t      Rental range: ";
				cin >> userrange;
				cout << "\t                                 \n";
				cout << "\t      Cars: ";
				cin >> usercar1 >> usercar2 >> usercar3;
				cout << "\t                                 \n";
				cout << "\t      Rate: $";
				cin >> userrate;
				cout << "\t                                 \n";

				tempservice << userplan << " " << userrange << " " << usercar1 << " " << usercar2 <<
					" " << usercar3 << " " << userrate << "\n";
				count++;
			}

		}
		if (count == 0) {
			cout << "\t\t     No Service Found! \n";
			cout << "\t\t                     \n";
		}
		else {
			cout << "\t Service Information is successfully updated! \n";
			cout << "\t\t                     \n";

		}
		currentservice.close();
		tempservice.close();
		remove("CurrentServices.txt");
		rename("TempService.txt", "CurrentServices.txt");
		serviceMenu();

	}
};




class sales {
public:

	virtual void salesMenu() {
		int choice;

		cout << "\t --------------------------------------------\n";
		cout << "\t|                                            |\n";
		cout << "\t|                  Sales                     |\n";
		cout << "\t|                                            |\n";
		cout << "\t --------------------------------------------\n";
		cout << "\t|                                            |\n";
		cout << "\t|       1. Annual Sales                      |\n";
		cout << "\t|                                            |\n";
		cout << "\t|       2. Monthly Sales                     |\n";
		cout << "\t|                                            |\n";
		cout << "\t|       3. Back to Sales Menu                |\n";
		cout << "\t|                                            |\n";
		cout << "\t --------------------------------------------\n";
		cout << "\t                                             \n";
		cout << "\t            Please Select : ";
		cin >> choice;
		cout << "\t                                         \n";

		switch (choice) {
		case 1:
			system("cls");
			annualsales();
			break;

		case 2:
			system("cls");
			monthlysales();
			break;

		case 3:
			system("cls");
			mainMenu s;
			s.menu();
			break;

		default:
			cout << "\t                                         \n";
			cout << "\t    Please choose from the given options! \n";
			salesMenu();
		}

	}

	void annualsales() {

		fstream salesobj;
		string bsales, ssales, psales, upsales, total;
		int count = 0;
		string year, useryear;


		salesobj.open("AnnualSales.txt", ios::in);  // Opening the file in read mode
		cout << "\t -----------------------------------------\n";
		cout << "\t|                                         |\n";
		cout << "\t|              Annual Sales               |\n";
		cout << "\t|                                         |\n";
		cout << "\t -----------------------------------------\n";
		cout << "\t                                 \n";
		cout << "\t   Enter the year: ";
		cin >> useryear;
		cout << "\t                                 \n";
		while (!salesobj.eof()) {
			salesobj >> year >> bsales >> ssales >> psales >> upsales >> total;

			if (useryear == year) {

				cout << "\t                                        \n";
				cout << "\t    Basic plan         : $" << bsales << "\n";
				cout << "\t    Standard plan      : $" << ssales << "\n";
				cout << "\t    Premium plan       : $" << psales << " \n";
				cout << "\t    Ultra Premium plan : $" << upsales << "\n";
				cout << "\t-------------------------------------------\n";
				cout << "\t    Total Sales        : $" << total << "\n";
				cout << "\t                                        \n";
				count++;
				break;
			}

		}
		salesobj.close();  // Closing the text file
		if (count == 0) {
			cout << "\t\t      No Sales Found!  \n";
			cout << "\t\t                       \n";
		}
		salesMenu();
	}

	void monthlysales() {
		fstream salesobj1;
		string bsales, ssales, psales, upsales, total;
		int count = 0;
		string year, useryear, month, usermonth;


		salesobj1.open("MonthlySales.txt", ios::in);  // Opening the file in read mode
		cout << "\t -----------------------------------------\n";
		cout << "\t|                                         |\n";
		cout << "\t|              Monthly Sales              |\n";
		cout << "\t|                                         |\n";
		cout << "\t -----------------------------------------\n";
		cout << "\t                                 \n";
		cout << "\t   Enter the year: ";
		cin >> useryear;
		cout << "\t                                 \n";
		cout << "\t   Enter the month: ";
		cin >> usermonth;
		cout << "\t                                 \n";

		while (!salesobj1.eof()) {
			salesobj1 >> year >> month >> bsales >> ssales >> psales >> upsales >> total;

			if (useryear == year && usermonth == month) {

				cout << "\t                                        \n";
				cout << "\t    Basic plan         : $" << bsales << "\n";
				cout << "\t    Standard plan      : $" << ssales << "\n";
				cout << "\t    Premium plan       : $" << psales << " \n";
				cout << "\t    Ultra Premium plan : $" << upsales << "\n";
				cout << "\t-------------------------------------------\n";
				cout << "\t    Total Sales        : $" << total << "\n";
				cout << "\t                                        \n";
				count++;
				break;
			}

		}
		salesobj1.close();  // Closing the text file
		if (count == 0) {
			cout << "\t\t      No Sales Found!  \n";
			cout << "\t\t                       \n";
		}
		salesMenu();
	}
};


void mainMenu::menu() { // Display the main menu


	int choice;

	cout << "\t -----------------------------------------\n";
	cout << "\t|                                         |\n";
	cout << "\t|           DRIVE CAR RENTAL              |\n";
	cout << "\t|                                         |\n";
	cout << "\t ------------------------------------------\n";
	cout << "\t|                                         |\n";
	cout << "\t|           1. Clients                    |\n";
	cout << "\t|                                         |\n";
	cout << "\t|           2. Sales Representatives      |\n";
	cout << "\t|                                         |\n";
	cout << "\t|           3. Services                   |\n";
	cout << "\t|                                         |\n";
	cout << "\t|           4. Sales                      |\n";
	cout << "\t|                                         |\n";
	cout << "\t|           5. Exit                       |\n";
	cout << "\t|                                         |\n";
	cout << "\t -----------------------------------------\n";
	cout << "\t                                          \n";
	cout << "\t           Please Select : ";
	cin >> choice;
	cout << "\t                                          \n";

	switch (choice) {
	case 1: {
		system("cls");

		clients c;
		c.clientMenu();

		break;
	}
	case 2: {
		system("cls");

		salesRepresentatives s;
		s.salesMenu();

		break;
	}
	case 3: {
		system("cls");

		services r;
		r.serviceMenu();

		break;
	}
	case 4: {
		system("cls");

		sales s1;
		s1.salesMenu();

		break;
	}
	case 5: {
		exit(0);

		break;
	}
	default:
		cout << "\t                                         \n";
		cout << "\t   Please choose from the given options \n";

		menu();
	}

}

int main() {

	mainMenu w;
	w.menu();

	return 0;
}