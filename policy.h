#include <iostream>
#include <vector>
#include <ctime>

#include "filemanager.h"

using std::cout;
using std::cin;
using std::string; 

#ifndef POLICY_H_
#define POLICY_H_

struct policy {
    string policyID; // Same as customer ID, as each customer can only have one policy.
    int policyType;
    //vector<insVehicle>; Vehicles to be pulled from vehicle cpp
    policy(){
        policyType = 0;
        policyID = "null"; 
     
    }

    string getPolicyType(){
        string policyString = "No policy selected";
        switch(policyType) {
            case 1:
                policyString = "BASIC";
                break;
            case 2:
                policyString = "STANDARD";
                break;
            case 3:
                policyString = "PREMIUM";
                break;
        }
        return policyString;
    }

    void printPolicy(){
        cout << "   \nPOLICY INFORMATION FOR: " << policyID << "\n";
        cout << "   ---------------------------------- \n";
        cout << "   Policy Type:            " + getPolicyType() << "\n";
        cout << "   TO DO: Add vector of vehicles and logic to print them.\n";
        cout << "\n   ---------------------------------- \n";
    }

   void newPolicy(string customerID){  // Called in customer struct.
        policyID = customerID;
        cout << "Please select a policy: \n";
        cout << "1. BASIC: $10/month per insured vehicle. $300 claim excess.\n";
        cout << "2. STANDARD: $15/month per insured vehicle. $100 claim excess.\n";
        cout << "3. PREMIUM: $25/month per insured vehicle. $0 claim excess.\n";
        cin >> policyType;
        while (policyType > 3 || policyType < 1) {
            cout << "Please enter a valid option \n"; // Need to add logic to catch strings and characters
            cin >> policyType;
        } 
        cout << "\nYou have selected " + getPolicyType() << "\n";

        string toCSV = policyID + "," + getPolicyType();
        ::writeCsv("data/policy_data.csv", toCSV);  
    }
};
#endif

// int main(){
//     policy test;
//     test.newPolicy();
//     test.printPolicy();
//     return 0;
// }