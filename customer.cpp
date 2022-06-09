#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct customer {

	string custNum = "0"; //Any client number of 0 is a void client or maybe an admin?
	string firstName = "null";
	string lastName = "null";
	string phone = "0";
	string email = "null";

};

vector <customer> customerInfo;

void newCustomer() {

	customer addCust;

	addCust.custNum = //last number + 1

	cout << "First Name: ";
	cin >> addCust.firstName;
	cout << "Last name: ";
	cin >> addCust.lastName;
	cout << "Phone number: ";
	cin >> addCust.phone;
	cout << "Email adress: ";
	cin >> addCust.email;
	//Add all the new structure values to the vector.
	customerInfo.push_back(addCust);
}

bool writeCsv(string fileName, string customerNumber, string firstName, string lastName, string phoneNumber, string emailAddress) {


	std::ofstream file;
	file.open(fileName, std::ios_base::app);
	file << customerNumber << "," << firstName << "," << lastName << "," << phoneNumber << "," << emailAddress << endl;
	file.close();

	return true;
}

int main() {

	//vector size
	newCustomer();

	writeCsv("data/customer_data.csv", customerInfo[0].custNum, customerInfo[0].firstName, customerInfo[0].lastName, customerInfo[0].phone, customerInfo[0].email);

	return 0;

}