#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <vector>
#include "header.h"

using std::cout;
using std::cin;
using std::string; 


struct Claim claim;

    string fetchClaimNum() { 
        int ID = readTxt("data/claims_id_counter.txt"); 
        writeTxt("data/claims_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }

    void makeClaim(string policyID) {
        Policy claimPolicy;
        Vehicle claimVehicle;
        claimPolicy = loadPolicy("data/policy_data.csv", policyID);
        claimVehicle = loadVehicle("data/vehicle_data.csv", claimPolicy.insuredVehicle.ID);

        if ("none" == readCSV("data/claim_data.csv", policyID)) {

            string insuredValue = std::to_string(claimVehicle.insuredValue);
            string toCSV = claimPolicy.policyID + "," + claimPolicy.policyType + "," + claimPolicy.policyExcess + "," + claimVehicle.registration + "," + insuredValue + ",0";  //",0" is the claim status set as false
            writeCsv("data/claim_data.csv", toCSV);

            cout << "Your claim number is: " << claimPolicy.policyID << "\n";
            cout << "Your Policy Type is: " << claimPolicy.policyType << "\n";
            cout << "Your excess will be: $" << claimPolicy.policyExcess << "\n";
            cout << "Your insured vehicle is:" << claimVehicle.registration << "\n";
            cout << "The insured value is: $" << claimVehicle.insuredValue << "\n";
            cout << "Your claim status is: Pending approval.\n\n";
        }
        else {
            cout << "You cannot have multiple claims. Please go check your current claim.\n\n";
        }
    }

    bool updateClaim(string filename, string uniqueID) {

        std::fstream fin, fout;
        //opens existing file
        fin.open(filename, std::ios::in);
        //creates new file to store updated info
        fout.open("data/updated_file_temp_name.csv", std::ios::out);

        if (!fin.is_open()) {
            cout << "Error reading file...";
            return false;
        }

        string updatedValue,
            line = "Null, file did not read",
            word,
            fileID;
        int index = 5,
            count = 0;
        std::vector<string> row;

            //runs through the whole original file
            while (!fin.eof()) {
                row.clear();

                //gets line and creates new stringstream variable
                getline(fin, line, '\n');
                if (line.length() != 0) {
                    std::stringstream sstr(line);

                    //pushes each word from the current line into the vector
                    while (getline(sstr, word, ',')) {
                        row.push_back(word);
                    }

                    fileID = row[0];
                    int rowSize = row.size();

                    if (fileID == uniqueID) {
                        count = 1;
                        row[index] = 1;

                        if (!fin.eof()) {
                            for (int i = 0; i < rowSize - 1; i++) {
                                // write the updated data into the new file "data/updated_file_temp_name.csv"
                                fout << row[i] << ",";
                            }
                            fout << row[rowSize - 1] << "\n";
                        }
                    }
                    else {
                        if (!fin.eof()) {
                            for (int i = 0; i < rowSize - 1; i++) {

                                // write existing data into the new file
                                fout << row[i] << ",";
                            }
                            fout << row[rowSize - 1] << "\n";
                        }

                    }
                    if (fin.eof()) {
                        for (int i = 0; i < rowSize - 1; i++) {
                            // write last line to new file without a newline
                            fout << row[i] << ",";
                        }
                        fout << row[rowSize - 1];
                        break;
                    }
                }
            }

            if (count == 0)
                cout << "Data not found, nothing was changed.\n";
            if (count == 2)
                cout << "Program encountered a 'space' character and had to exit.\n";

            fin.close();
            fout.close();

            // removing the existing file
            remove("data/claim_data.csv");

            // renaming the updated file with the existing file name
            rename("data/updated_file_temp_name.csv", "data/claim_data.csv");

            return true;
        }

//int main(){
//    //claim test;
//    //makeClaim();
//    updateClaimStatus(0);
//}