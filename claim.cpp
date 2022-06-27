#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "header.h"
#include <sstream>
//#include "TEST_filemanager.h"

using std::cout;
using std::cin;
using std::string;
using std::fstream;
using std::ifstream;
using std::istringstream;


string fetchClaimNum() {
    int ID = readTxt("data/claims_id_counter.txt");
    writeTxt("data/claims_id_counter.txt", ID);
    string stringID = std::to_string(ID);
    return stringID;
}

void makeClaim() {
    string ID = fetchClaimNum();
    string policyIDinput;
    std::vector<std::string> customerPolicy;
    string claimStatus = "Pending approval";
    cout << "\nPlease enter your Policy ID number to make a claim: ";
    getline(cin, policyIDinput);
    customerPolicy = CSVtoVector("data/policy_data.csv", policyIDinput);
    cout << "Your claim number is: " << ID << "\n";
    cout << "Your Policy Type is: " << customerPolicy[1] << "\n";
    cout << "Your excess will be: " << customerPolicy[2] << "\n";
    cout << "Your insured vehicle is: \n";
    cout << "LOGIC TO PRINT VEHICLE INFO from vehicle csv \n";
    cout << "Your claim status is: " << claimStatus << "\n\n";

    string toCSV = ID + "," + customerPolicy[0] + "," + customerPolicy[2] + "," + claimStatus;  //Vechile Registration and possible ins value to be added. 
    cout << toCSV;
    writeCsv("data/claim_data.csv", toCSV);
}

void updateClaimStatus(string ID, bool newStatus) {
    std::fstream claims("data/claim_data.csv");
    string temp;

    string line;
    while (getline(claims, line)) {
        if (line.rfind(ID, 0) == 0) {
            std::istringstream linestream(line);

            string item;
            getline(linestream, item, ',');
            string currentID = item;
            getline(linestream, item, ',');
            string customerPolicy0 = item;
            getline(linestream, item, ',');
            string customerPolicy2 = item;
            getline(linestream, item, ',');
            string currentClaimStatus = item;

            string tempLine = currentID + ',' +
                customerPolicy0 + ',' +
                customerPolicy2 + ',' +
                std::to_string(int(newStatus));
            temp += tempLine + '\n';

        }
        else {
            temp += line + '\n';
        }
    }

    claims << temp;
    claims.close();
}



int main() {
    //    claim test;
    //    test.makeClaim();

    string read = readCSV("data/claim_data.csv", "3");
    cout << read;
}