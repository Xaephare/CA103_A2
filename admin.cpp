#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <string.h>

#include "header.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Customer admin;
//struct customer {
//    login userLoginInfo;
//	string ID; 
//	string firstName,
//	    lastName,
//
//    
//    customer(){
//        ID = firstName = lastName =  "null";
//    }

    string fetchAdminNum() { 
        int ID = readTxt("data/admin_id_counter.txt");
        writeTxt("data/admin_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }

    void newAdmin() {
        admin.ID = fetchAdminNum();
        cout << "Your Admin ID number is: " << admin.ID << "\n";
        cout << "First Name: ";
        cin >> admin.firstName;
        cout << "Last name: ";
        cin >> admin.lastName;
        cout << "Phone number: ";
        cin >> admin.phone;
        registerNewUser(admin.ID);
        
        string toCSV = admin.ID + "," + admin.firstName + "," + admin.lastName;
        ::writeCsv("data/admin_data.csv", toCSV);

    }

//int main() {
//    customer test;
//	test.newAdmin();
//	cout << "\nTesting completed successfully";
//
//	return 0;
//}
