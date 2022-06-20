#include <iostream>
#include <vector>
#include <ctime>

//#include "filemanager.h"
#include "header.h"

using std::cout;
using std::cin;
using std::string; 

struct Policy policy;
//struct policy {
//    string policyID; // Same as customer ID, as each customer can only have one policy.
//    int policyType;
//    //vector<insVehicle>; Vehicles to be pulled from vehicle cpp
//    policy(){
//        policyType = 0;
//        policyID = "null"; 
//     
//    }
//};

    string getPolicyType(){
        string policyString = "No policy selected";
        switch(policy.policyType) {
            case 1:
                policyString = "BASIC";
                policy.policyExcess = "300";
                break;
            case 2:
                policyString = "STANDARD";
                policy.policyExcess = "100";
                break;
            case 3:
                policyString = "PREMIUM";
                policy.policyExcess = "0";
                break;
        }
        return policyString;
    }

    // Policy vectorToPolicyStruct(std::vector<std::string> CSVpolicyData){
    //     Policy policyInfo;
    //     policy.policyID = CSVpolicyData[0];
    //     if (CSVpolicyData[1] == "BASIC")
    //         policy.policyType = 1;
    //     if (CSVpolicyData[1] == "STANDARD")
    //         policy.policyType = 2;
    //     if (CSVpolicyData[1] == "PREMIUM")
    //         policy.policyType = 2;

    //     return policyInfo;
    //}

    void printPolicy(){
        cout << "   \nPOLICY INFORMATION FOR: " << policy.policyID << "\n";
        cout << "   ---------------------------------- \n";
        cout << "   Policy Type:            " + getPolicyType() << "\n";
        cout << "   TO DO: Add vector of vehicles and logic to print them.\n";
        cout << "\n   ---------------------------------- \n";
    }

   void newPolicy(string customerID){  // Called in customer struct.
        policy.policyID = customerID;
        cout << "Please select a policy: \n";
        cout << "1. BASIC: $10/month per insured vehicle. $300 claim excess.\n";
        cout << "2. STANDARD: $15/month per insured vehicle. $100 claim excess.\n";
        cout << "3. PREMIUM: $25/month per insured vehicle. $0 claim excess.\n";
        cin >> policy.policyType;
        while (policy.policyType > 3 || policy.policyType < 1) {
            cout << "Please enter a valid option \n"; // Need to add logic to catch strings and characters
            cin >> policy.policyType;
        } 
        cout << "\nYou have selected " + getPolicyType() << "\n";

        string toCSV = policy.policyID + "," + getPolicyType() + "," + policy.policyExcess;
        ::writeCsv("data/policy_data.csv", toCSV);  
    }

// int main(){
//     policy test;
//     test.newPolicy();
//     test.printPolicy();
//     return 0;
// }