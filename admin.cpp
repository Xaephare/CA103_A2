#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>


using std::string;
using std::ifstream;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Marker {
	//string brand;
	//string color;
	//double price;

	//constructor to initialize the variables of the structure
	//you can provide a default value to your variables
	Marker(/*string b = "Warwick", string c = "red", double p = 2.5 * / */) {
		//brand = b;
		//color = c;
		//price = p;
	}
};


vector <Marker> readClients() {
	std::fstream myFile("data/customer_data.csv", std::ios::in);
	vector<Marker> tempMarker2;

	Marker m2;
	string line2;
	while (getline(myFile, line2)) {
		cout << line2 << endl;
		//std::istringstream linestream(line);//to split the row into columns/properties

		tempMarker2.push_back(m2);
		
	}


	myFile.close();

	return tempMarker2;
}

vector <Marker> readClaimNums() {
	std::fstream myFile("data/claim_data.csv", std::ios::in);
	vector<Marker> tempMarker;

	Marker m;
	string line;
	while (getline(myFile, line)) {
		cout << line << endl;
		//std::istringstream linestream(line);//to split the row into columns/properties

		tempMarker.push_back(m);

	}


	myFile.close();

	return(tempMarker);
}


//#############################################       Old functions for reading claims and opening claims, probably will delete   ########################################################//
//void openClaims() {
//	ifstream fin{};
//	string line;
//	string row;
//	fin.open("data/claim_data.csv");
//	while (!fin.eof()) {
//		fin >> line;
//		cout << line << row << " ";
//		}
//}
//
//void countClaims() {
//	int rows = 0;
//	ifstream file("data/claim_data.csv");
//	string line;
//	while (getline(file, line))
//	cout << rows << "\n";
//	}
//#############################################       Old functions for reading claims and opening claims, probably will delete   ########################################################//
void mainMenu() {

	int choice = 0;

	cout << "\n------------------------------------------------";
	cout << "\nAdmin controls";
	cout << "\nPending applications: " << "(displays number of pending applications)";
	cout << "\n------------------------------------------------";
	cout << "\n\n1 - View/approve insurance applications";
	cout << "\n2 - View/approve claim requests";
	cout << "\n3 - View/edit client information";
	cout << "\n4 - Create a new admin account";
	cout << "\n5 - Exit program\n";

	choice:
	cout << "\nPick an option: ";
	cin >> choice;


	switch (choice) {
	case 1: readClaimNums;
		break;
	case 2: 
		break;
	case 3: readClients;
		break;
	case 4: cout << "create new account that is an admin one";
		break;
	case 5: break;
	default: cout << "Please pick one of the displayed options by pressing their respective number.";
		goto choice;
	}
}



int main() {
	mainMenu();
	readClaimNums();
	readClients();
	return 0;
}