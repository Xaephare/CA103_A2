#include <iostream>
#include <vector>


#include "header.h"
//#include "TEST_filemanager.h"

using std::cout;
using std::cin;
using std::string; 



struct claim {
    string ID;
    string policyID;
    string claimStatus;
        //vehicle claimedVehicle;  Will call vehicle.h file
   

    claim(){
        claimStatus = ID = policyID = "null";
    }
    
    string fetchClaimNum() { 
        int ID = readTxt("data/claims_id_counter.txt"); 
        writeTxt("data/claims_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }

    void makeClaim() {
        ID = fetchClaimNum();
        string policyIDinput;
        std::vector<std::string> customerPolicy;
        claimStatus = "Pending approval";
        cout << "\nPlease enter your Policy ID number to make a claim: ";
        getline(cin, policyIDinput);
        customerPolicy = CSVtoVector("data/policy_data.csv", policyIDinput);
        cout << "Your claim number is: " << ID << "\n";
        cout << "Your Policy Type is: " << customerPolicy[1] << "\n";
        cout << "Your excess will be: " << customerPolicy[2] << "\n" ;
        cout << "Your insured vehicle is: \n";
        cout << "LOGIC TO PRINT VEHICLE INFO from vehicle csv \n";
        cout << "Your claim status is: " << claimStatus << "\n\n";

        string toCSV = ID + "," + customerPolicy[0] + "," + customerPolicy[2] + "," + claimStatus;  //Vechile Registration and possible ins value to be added. 
        cout << toCSV;
        writeCsv("data/claim_data.csv", toCSV);
    }
};

int main(){
    claim test;
    test.makeClaim();
}