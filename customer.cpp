#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>


using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct customer {

	int custNum = 0; //Any client number of 0 is a void client or maybe an admin?
	string firstName = "null";
	string lastName = "null";
	string phone = "0";
	string email = "null";

};

vector <customer> customerInfo;


int fetchLastClientNum() {

	string numStr;
	std::fstream clientId;
	clientId.open("data/customer_id_counter.txt", std::ios::in);

	getline(clientId, numStr);
	int customerNum = std::stoi(numStr);
	clientId.close();

	return customerNum;
}

void writeTxt(string fileName, int customerNumber) {
	std::fstream file;
	file.open(fileName, std::ios::out);
	file << customerNumber;
	file.close();
}

void newCustomer() {

	customer addCust;

	int lastCustNum = fetchLastClientNum();
	addCust.custNum = ++lastCustNum;
	writeTxt("data/customer_id_counter.txt", lastCustNum);

	cout << "First Name: ";
	cin >> addCust.firstName;
	cout << "Last name: ";
	cin >> addCust.lastName;
	cout << "Phone number: ";
	cin >> addCust.phone;
	cout << "Email address: ";
	cin >> addCust.email;
	//Add all the new structure values to the vector.
	customerInfo.push_back(addCust);
}

void writeCsv(string fileName, int customerNumber, string firstName, string lastName, string phoneNumber, string emailAddress) {

	std::ofstream file;
	file.open(fileName, std::ios::app);
	file << customerNumber << "," << firstName << "," << lastName << "," << phoneNumber << "," << emailAddress << endl;
	file.close();
}

int main() {

	newCustomer();
	writeCsv("data/customer_data.csv", customerInfo[0].custNum, customerInfo[0].firstName, customerInfo[0].lastName, customerInfo[0].phone, customerInfo[0].email);

	cout << "\nTesting completed successfully";

	return 0;
}


//Emmas commit starts here
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::string; 
using std::vector;


struct customer {
    //login to be added from login struct
    string firstName,
        lastName,
        email; // may be used in login instead
    int phone;

    customer(){
        firstName = lastName = email = "unassigned";
        phone = 0;
    }

    void getCustomerInfo(){
        cout << "Thankyou for registering with LEGEND Insurance.\n";
        cout << "Please enter your information when prompted: \n";
        cout << "First name: ";
        getline(cin, firstName);
        cout << "Last name:  ";
        getline(cin, lastName);
        cout << "Email address: ";
        getline(cin, email); // code for verifying email to be added
        cout << "Phone number: ";
        cin >> phone;
    }

    void printCustomer(){
        cout << "Customer information for: " << firstName << " " << lastName;
        cout << "\nEmail address:       " << email;
        cout << "\nPhone number:        " << phone;
        // To be added. Policy number and number of registered vehicles.
    }



   

};

int main(){
    customer test;
    test.getCustomerInfo();
    test.printCustomer();
    return 0;
}