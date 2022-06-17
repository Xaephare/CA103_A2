#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <string.h>

#include "login.h"
#include "filemanager.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

#ifndef ADMIN_H_
#define ADMIN_H_

struct customer {
    login userLoginInfo;
	string ID; 
	string firstName,
	    lastName,

    
    customer(){
        ID = firstName = lastName =  "null";
    }

    string fetchAdminNum() { 
        int ID = readTxt("data/admin_id_counter.txt");
        writeTxt("data/admin_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }

    void newAdmin() {
        ID = fetchAdminNum();
        cout << "Your Admin ID number is: " << ID << "\n";
        cout << "First Name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
        cout << "Phone number: ";
        cin >> phone;
        userLoginInfo.registerNewUser(ID);
        
        string toCSV = ID + "," + firstName + "," + lastName;
        ::writeCsv("data/admin_data.csv", toCSV);

    }

    
};
#endif

int main() {
    customer test;
	test.newAdmin();
	cout << "\nTesting completed successfully";

	return 0;
}
