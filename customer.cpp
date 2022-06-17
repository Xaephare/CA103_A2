#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <string.h>

//#include "login.h"
//#include "filemanager.h"
//#include "policy.h"
#include "header.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

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

    string fetchClientNum() { 
        int ID = readTxt("data/customer_id_counter.txt");
        writeTxt("data/customer_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }

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

    }


//int main() {
//	newCustomer();
//    newPolicy(customer.ID);
//	cout << "\nTesting completed successfully";
//
//	return 0;
//}