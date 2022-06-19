#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <string.h>
#include <sstream>

//#include "login.h"
//#include "filemanager.h"
//#include "policy.h"
#include "header.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

struct Customer customer;
//struct customer {
//    login userlogininfo;
//    string id; //any client number of 0 is a void client or maybe an admin?
//    string firstname,
//        lastname,
//        phone;
//    policy customerpolicyinfo;
//
//    customer() {
//        id = firstname = lastname = phone = "null";
//    }
//};

    string fetchClientNum() { 
        int ID = readTxt("data/customer_id_counter.txt");
        writeTxt("data/customer_id_counter.txt", ID);
        string stringID = std::to_string(ID);
        return stringID;
    }

    void newCustomer() {
        customer.ID = fetchClientNum();
        cout << "Your Customer ID number is: " << customer.ID << "\n";
        cout << "First Name: ";
        cin >> customer.firstName;
        cout << "Last name: ";
        cin >> customer.lastName;
        cout << "Phone number: ";
        cin >> customer.phone;
        registerNewUser(customer.ID);
        
        string toCSV = customer.ID + "," + customer.firstName + "," + customer.lastName + "," + customer.phone;
        writeCsv("data/customer_data.csv", toCSV);

    }

    bool updateCsv(string filename, string uniqueID) {

        std::fstream fin, fout;
        //opens existing file
        fin.open(filename, std::ios_base::in);
        //creates new file to store updated info
        fout.open("data/updated_file_temp_name.csv", std::ios_base::out);

        string updatedValue,
            line = "Null, file did not read",
            word,
            fileID;
        int index = 0,
            option = 0,
            count = 0;
        vector<string> row;


        cout << "What would you like to edit?";

        //different choices are given depending on file name
        if (filename == "data/customer_data.csv") {
            cout << "\n1 - First name"
                "\n2 - Last name"
                "\n3 - Phone number" << endl;
            cin >> option;

            switch (option) {
            case 1: index = 1;
                break;
            case 2: index = 2;
                break;
            case 3: index = 3;
                break;
            default: cout << "non-real choice";
                return false;
            }

            cout << "What should this be changed to? \n";
            cin >> updatedValue;

            //runs through the whole original file
            while (!fin.eof()) {

                row.clear();

                //gets line and creates new stringstream variable
                getline(fin, line);
                std::stringstream sstr(line);

                //pushes each word from the current line into the vector
                while (getline(sstr, word, ',')) {
                    row.push_back(word);
                }

                fileID = row[0];
                int rowSize = row.size();

                if (fileID == uniqueID) {
                    count = 1;
                    row[index] = updatedValue;

                    if (!fin.eof()) {
                        for (int i = 0; i < rowSize - 1; i++) {
                            // write the updated data into the new file "data/updated_file_temp_name.csv"
                            fout << row[i] << ", ";
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
                    break;
                }
            }
            if (count == 0)
                cout << "Data not found.\n";

            fin.close();
            fout.close();

            // removing the existing file
            remove("data/customer_data.csv");

            // renaming the updated file with the existing file name
            rename("data/updated_file_temp_name.csv", "customer_data.csv");

            return true;
        }




        //else if (filename == "vehicle_data.csv") {

        //}
        //else if (filename == "login_data.csv") {
        //    cout << "\n1 - Email"
        //        "\n2 - Password";
        //    cin >> option;
        //}
        //else if (filename == "policy_data.csv") {
        //    cout << "What should replace the current policy?";
        //}
        //else if (filename == "vehicle_data.csv") {
        //    
        //}
        //else {
        //    cout << "ERROR - filename incorrect";
        //    return false;
        //}
   
        return true;
 }

int main() {
	//newCustomer();
    //newPolicy(customer.ID);
    string customerID = "0";
    cout << "customer ID to be edited? \n";
    cin >> customerID;

    bool testingCompleted = updateCsv("data/customer_data.csv", customerID);
	cout << "\nTesting completed successfully: " << testingCompleted;

	return 0;
}