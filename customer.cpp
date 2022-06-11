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