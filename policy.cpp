#include <iostream>
#include <vector>
#include <ctime>
#include "filemanager.h"

using std::cout;
using std::cin;
using std::string; 

struct policy {
    int id,
        policyType;
    //vector<insVehicle>; Vehicles to be pulled from vehicle cpp
    //start date & exp date to be added
    //could add bool for policy status. false if exp date has passed.
    policy(){
        id = policyType = 0;
    }


    void printPolicyType(){
        switch(policyType) {
            case 1:
                cout << "BASIC";
                break;
            case 2:
                cout << "STANDARD";
                break;
            case 3:
                cout << "PREMIUM";
                break;
        }
    }

    int assignPolicyID(){
       int lastID = readTxt("data/policy_data.csv");
       int id = writeTxt("data/policy_data.csv", lastID);

    }

    void printPolicy(){
        cout << "   \nPOLICY INFORMATION FOR: " << id << "\n";
        cout << "   ---------------------------------- \n";
        cout << "   Policy Type:            "; printPolicyType(); cout << "\n";
        cout << "TO DO: Add vector of vehicles and logic to print them.\n";
        cout << "\n   ---------------------------------- \n";
    }


    int getPolicyinfo(){
        //// unique id to be generated once filemanager.cpp built
        cout << "Please select a policy: \n";
        cout << "1. BASIC: $10/month per insured vehicle. $300 claim excess.\n";
        cout << "2. STANDARD: $15/month per insured vehicle. $100 claim excess.\n";
        cout << "3. PREMIUM: $25/month per insured vehicle. $0 claim excess.\n";
        cin >> policyType;
        while (policyType > 3 || policyType < 1) {
            cout << "Please enter a valid option \n"; // Need to add logic to catch strings and characters
            cin >> policyType;
        } 
        cout << "\nYou have selected "; printPolicyType(); cout << "\n";

    return policyType;

    };
};

int main(){
    policy test;
    test.getPolicyinfo();
    test.printPolicy();
    return 0;
}