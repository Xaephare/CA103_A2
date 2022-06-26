#include <iostream>
#include <regex>
#include <fstream>
#include <cstring>  
#include <vector>
//#include "filemanager.h"
#include "header.h"

using std::cout;
using std::cin;
using std::string; 
using std::endl;

struct Login login;
//struct login {
//    string userID;
//    string email;
//    string password;
//
//    login() {
//        userID = email = password = "null";
//    }
//};

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
        login.userID = newUserID;
   
        while (emailNotVerified) {
            cout << "Please enter a valid email eddress: ";
            cin.ignore();
            getline(cin, newEmail);
            if (validEmail(newEmail)) {
                login.email = newEmail;
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
                login.password = newPassword;
                passwordNotVerified = false;
                cout << "**PASSWORD ACCEPTED**\n";
            }
        }
        string toCSV = login.userID + "," + login.email + "," + login.password;
        writeCsv("data/login_data.csv", toCSV);
    }


    void printDetails(){
        cout << "ID = " << login.userID << ", email = " << login.email << ", password = " << login.password << "\n"; 
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
                if (numFlag == 0 && notValid) {   
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

    
    bool loadLogin(string filename, string ID) {
        std::vector<std::string> dataVector = CSVtoVector(filename, ID);

        if (dataVector.size() == 1) {
            login.userID = dataVector[0];
        }
        else {
        login.userID = dataVector[0];
        login.email = dataVector[1];
        login.password = dataVector[2];
        }

        if (dataVector[0] == "none") {
            return false;
        }
        else {
            return true;
        }
    }

    void checkLogin() {
        
        bool notConfirmed = true;
        Login compare;

        for (int loginAttempt = 0; notConfirmed && loginAttempt < 3; loginAttempt++) {
            cout << "Please enter your customer number: ";
            cin >> compare.userID; 
            cout << "Please enter you password: ";
            cin >> compare.password;
            if (loadLogin("data/login_data.csv", compare.userID) && compare.password == login.password) {
                notConfirmed = false;
            }
            else {
                cout << "Try again: ";
            }
        }
    }

 int main() {
     // test.registerNewUser("testID");
     //test.printFromCSV("data/login_data.csv", "101");
     //loadLogin("data/login_data.csv", "0");
     checkLogin();
     return 0;
 }