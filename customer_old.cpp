#include <iostream>
#include <stdlib.h>

#ifndef ADD_H_FILES
#define ADD_H_FILES

#include "login.h"
#include "filemanager.h"

using std::cout;
using std::cin;
using std::string; 
using std::vector;


struct customer {
    login id, email, password;
    string firstName,
        lastName;
    int phone;

    customer(){
        firstName = lastName =  "unassigned";
        phone = 0;
    }

    void getCustomerInfo(){
        cout << "Thankyou for registering with LEGEND Insurance.\n";
        cout << "Please enter your information when prompted: \n";
        cout << "First name: ";
        getline(cin, firstName);
        cout << "Last name:  ";
        getline(cin, lastName);
        cout << "Phone number: ";
        cin >> phone;
    }

    void printCustomer(){
        cout << "Customer information for: " << firstName << " " << lastName;
        cout << "\nPhone number:        " << phone;
        // To be added. Policy number and number of registered vehicles.
    }



   

};

#endif

int main(){
    customer test;
    test.getCustomerInfo();
    test.printCustomer();
    return 0;
}