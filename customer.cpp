#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <string.h>

#include "login.h"
#include "filemanager.h"
#include "policy.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

struct customer {
    login userLoginInfo;
	string ID; //Any client number of 0 is a void client or maybe an admin?
	string firstName,
	    lastName,
	    phone;
    policy customerPolicyInfo;
    
    customer(){
        ID = firstName = lastName = phone = "null";
    }

    string fetchClientNum() { 
        int ID = readTxt("data/customer_id_counter.txt");
        writeTxt("data/customer_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }

    void newCustomer() {
        ID = fetchClientNum();
        cout << "Your Customer ID number is: " << ID << "\n";
        cout << "First Name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
        cout << "Phone number: ";
        cin >> phone;
        userLoginInfo.registerNewUser(ID);
        
        string toCSV = ID + "," + firstName + "," + lastName + "," + phone;
        ::writeCsv("data/customer_data.csv", toCSV);

    }

    void createNewPolicy(){
        customerPolicyInfo.newPolicy(ID);
    }

    
};
#endif

int main() {
    customer test;
	test.newCustomer();
    test.createNewPolicy();
	cout << "\nTesting completed successfully";
	return 0;
}