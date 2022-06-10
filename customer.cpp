#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::string; 


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