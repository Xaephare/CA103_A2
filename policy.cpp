#include <iostream>
#include <vector>
#include <ctime>


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

    string getPolicyType(int policyChoice){
        policy.policyType = "No policy selected";

        switch(policyChoice) {
            case 1:
                policy.policyType = "BASIC";
                policy.policyExcess = "300";
                break;
            case 2:
                policy.policyType = "STANDARD";
                policy.policyExcess = "100";
                break;
            case 3:
                policy.policyType = "PREMIUM";
                policy.policyExcess = "0";
                break;
        }
        return policy.policyType;
    }

    void printPolicy() {
        cout << "\n POLICY INFORMATION FOR: " << policy.policyID << "\n";
        cout << "   ---------------------------------- \n";
        cout << "   Policy Type:            " + policy.policyType << "\n";
        cout << "   Policy Excess:          " + policy.policyExcess << "\n";
        cout << "   Vehicles on policy :     1 \n";
        cout << "   ---------------------------------- \n";
    }

   void newPolicy(string customerID){  // Called in customer struct.
        policy.policyID = customerID;
        int selection;
        cout << "Please select a policy: \n";
        cout << "1. BASIC: $10/month per insured vehicle. $300 claim excess.\n";
        cout << "2. STANDARD: $15/month per insured vehicle. $100 claim excess.\n";
        cout << "3. PREMIUM: $25/month per insured vehicle. $0 claim excess.\n";
        cin >> selection;
        getPolicyType(selection);
        while (selection > 3 || selection < 1) {
            cout << "Please enter a valid option \n"; // Need to add logic to catch strings and characters
            cin >> policy.policyType;
        } 
        cout << "\nYou have selected " + policy.policyType << "\n";
        string vehicleID = fetchVehicleIDNum();
        getVehicleInfo(vehicleID);  // Calls from vehicle cpp

        string toCSV = policy.policyID + "," + policy.policyType + "," +  vehicleID + "," + policy.policyExcess;
        ::writeCsv("data/policy_data.csv", toCSV);  
    }

   Policy loadPolicy(string filename, string ID) {
       std::vector<std::string> dataVector = CSVtoVector(filename, ID);

       if (dataVector.size() == 1) {
           policy.policyID = dataVector[0];
       }
       else {
           policy.policyID = dataVector[0];
           policy.policyType = dataVector[1];
           policy.insuredVehicle.ID = dataVector[2];
           policy.policyExcess = dataVector[3];
       }

       if (dataVector[0] == "none") {
           cout << "not found";
       }
       else {
           return policy;
       }
   }

//int main(){
//    policy test;
//    newPolicy("4500");
//    printPolicy();
//    return 0;
//}