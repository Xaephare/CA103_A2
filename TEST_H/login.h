#include <iostream>
#include <regex>
#include <fstream>
#include <cstring>  
#include <vector>
#include "filemanager.h"

using std::cout;
using std::cin;
using std::string; 
using std::endl;

#ifndef LOGIN_H_
#define LOGIN_H_

struct login {
    string userID;
    string email;
    string password;

    login() {
        userID = email = password = "null";
    }

    // Checks email address is valid
    bool validEmail(string email){
        const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(email,pattern);
    }

    // Register new customer or admin.
    void registerNewUser(string newUserID){
        string newEmail;
        string newPassword;
        bool emailNotVerified = true;
        bool passwordNotVerified = true;
        userID = newUserID;
   
        while (emailNotVerified) {
            cout << "Please enter a valid email eddress: ";
            cin.ignore();
            getline(cin, newEmail);
            if (validEmail(newEmail)) {
                email = newEmail;
                cout << "**EMAIL ACCEPTED**\n";
                emailNotVerified = false;
            }
            else {
                cout << "\nEMAIL INVALID.\n";
            }
        }
        // If email is verified, then function will move on to password.
        cout << "\nPasswords must be a min 6 characters long and include at least 1 numeral\n";
        while (passwordNotVerified){
            cout << "\nPlease enter a valid password:\n";
            getline(cin, newPassword);
            if (validPassword(newPassword)) {
                password = newPassword;
                passwordNotVerified = false;
                cout << "**PASSWORD ACCEPTED**\n";
            }
        }
        string toCSV = userID + "," + email + "," + password;
        writeCsv("data/login_data.csv", toCSV);
    }


    void printDetails(){
        cout << "ID = " << userID << ", email = " << email << ", password = " << password << "\n"; 
    }

    // Password min 6 characters, with at least 1 number
    bool validPassword(string pass){
        bool notValid = true;
        while (notValid) {
            if (pass.size() < 6){
                cout << "Password is too short.";
                break;
            }
            if (pass.size() >= 6 && notValid) {
                int passwordIndex, numFlag = 0; //check password contains a number
                for (passwordIndex = 0; passwordIndex < pass.size(); passwordIndex++) {
                    if (isdigit(pass[passwordIndex])) {
                        numFlag = 1;
                        notValid = false;
                    }   
                }
                if (numFlag == 0 && notValid){   
                    cout << "\nInvalid password."; 
                    cout <<  "Password must contain at least one numeral and be 6 characters long\n"; 
                }
            }
            break;  
        }
    return !notValid;
    }


    void printFromCSV(string filename, string ID){
        string data = "ID not found\n";
        data = readCSV(filename, ID);
        cout << data << "\n";
    }

    
    void loadCSV(string filename, string ID){
        string data = "ID not found\n";
        std::vector<std::string> dataVector = CSVtoVector(filename, ID);
        userID = dataVector[0];
        email = dataVector[1];
        password = dataVector[2];
    
    }

};
#endif

// int main() {
//     login test;
//     // test.registerNewUser("testID");
//     //test.printFromCSV("data/login_data.csv", "101");
//     test.loadCSV("data/login_data.csv", "101");
//     return 0;
// }
