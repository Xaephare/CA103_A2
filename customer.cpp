#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <string.h>

//#include "login.h"
<<<<<<< HEAD
//#include "filemanager.h"
//#include "policy.h"
#include "header.h"
=======
//#include "TEST_filemanager.h"
//#include "policy.h"
//#include "header.h"
>>>>>>> 94d2f21 (Add files via upload)

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

<<<<<<< HEAD
struct Customer customer;
//struct customer {
//    login userlogininfo;
//    string id; //any client number of 0 is a void client or maybe an admin?
//    string firstname,
//        lastname,
//        phone;
//    policy customerpolicyinfo;
//
//    customer() {
//        id = firstname = lastname = phone = "null";
//    }
//};
=======
//struct Customer customer;
struct customer {
   //login userlogininfo;
   string id; //any client number of 0 is a void client or maybe an admin?
   string firstname,
       lastname,
       phone;
  // policy customerpolicyinfo;

   customer() {
       id = firstname = lastname = phone = "null";
   }
};
>>>>>>> 94d2f21 (Add files via upload)

    string fetchClientNum() { 
        int ID = readTxt("data/customer_id_counter.txt");
        writeTxt("data/customer_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }

<<<<<<< HEAD
    void newCustomer() {
        customer.ID = fetchClientNum();
        cout << "Your Customer ID number is: " << customer.ID << "\n";
        cout << "First Name: ";
        cin >> customer.firstName;
        cout << "Last name: ";
        cin >> customer.lastName;
        cout << "Phone number: ";
        cin >> customer.phone;
        registerNewUser(customer.ID);
        
        string toCSV = customer.ID + "," + customer.firstName + "," + customer.lastName + "," + customer.phone;
        writeCsv("data/customer_data.csv", toCSV);
=======
    // void newCustomer() {
    //     customer.ID = fetchClientNum();
    //     cout << "Your Customer ID number is: " << customer.ID << "\n";
    //     cout << "First Name: ";
    //     cin >> customer.firstName;
    //     cout << "Last name: ";
    //     cin >> customer.lastName;
    //     cout << "Phone number: ";
    //     cin >> customer.phone;
    //     registerNewUser(customer.ID);
        
    //     string toCSV = customer.ID + "," + customer.firstName + "," + customer.lastName + "," + customer.phone;
    //     writeCsv("data/customer_data.csv", toCSV);
>>>>>>> 94d2f21 (Add files via upload)

    // }
    // void loadCSV(string filename, string ID){
    //     string data = "ID not found\n";
    //     std::vector<std::string> dataVector = CSVtoVector(filename, ID);
    //     customer.id = dataVector[0];
    //     customer.firstname = dataVector[1];
    //     customer.lastname = dataVector[2];
    //     customer.phone = dataVector[3];
    // }

    void overWriteCsv(string filename, string incomingData) { // Called within other functions, takes incoming data as a string and writes it to CSV.
	    std::ofstream file;
	    file.open(filename, std::ios::trunc);
	    file << incomingData << "\n";
	    file.close();
    }

<<<<<<< HEAD

//int main() {
//	newCustomer();
//    newPolicy(customer.ID);
//	cout << "\nTesting completed successfully";
//
//	return 0;
//}
=======
    string updateInfo(string filename, string id){
        std::vector<std::string> info;
        //bool updateNotComplete = true;
        int updateSelection;
        string newInfo;
        info = CSVtoVector(filename, id);
        
        cout << "What would you like to update? \n";
        cout << "1. First name: " << info[1] << "\n";
        cout << "2. Last name: " << info[2] << "\n";
        cout << "3. Phone number: " << info[3] << "\n";
        cin >> updateSelection;
        switch(updateSelection){
        case 1:
            cout << "Please enter updated first name: ";
            cin.ignore();
            getline(cin, newInfo);
            info[1] = newInfo;
        case 2:
            cout << "Please enter updated last name: ";
            cin.ignore();
            getline(cin, newInfo);
            info[2] = newInfo;
        case 3:
            cout << "Please enter new phone number: ";
            cin.ignore();
            getline(cin, newInfo);
            info[3] = newInfo;
        }
        string toCSV =  id + "," + info[1]+ "," + info[2] + "," + info[3];
        overWriteCsv("data/customer_data.csv", toCSV);
        return toCSV;
    }

int main() {
    //Customer update;
    updateInfo("data/customer_data.csv", "2006");

	//cout << "\nTesting completed successfully";

	return 0;
}
>>>>>>> 94d2f21 (Add files via upload)
