#include <iostream>
#include <regex>
#include <fstream>

using std::cout;
using std::cin;
using std::string; 
using std::endl;

struct login {
    string userID;
    string email;
    string password;

    login() {
        userID = email = password = "unassigned";
    }

    // Checks email address is valid
    bool validEmail(string email){
        const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(email,pattern);
    }

    // Register new customer or admin.
    // Still need add writing to login_data.txt for storing
    void registerNewUser(string newUserID){
        string newEmail;
        string newPassword;
        bool emailVerified;
        userID = newUserID;
        
        cout << "\nREGISTER NEW LEGEND INSURANCE USER\n";
        cout << "Please enter a valid email eddress: ";
        getline(cin, newEmail);
        if (validEmail(newEmail)){
            emailVerified = true;
            email = newEmail;
            cout << "**EMAIL ACCEPTED**\n";
        }       
            while (emailVerified != true) {
            cout << "\nEMAIL INVALID.\nPlease enter a valid email: ";
            getline(cin, newEmail);
            
                if (validEmail(newEmail)) {
                emailVerified = true;
                email = newEmail;
                cout << "**EMAIL ACCEPTED**\n";
                }
        }
        // If email is verified, then function will move on to password.
        if (emailVerified == true){
            bool pwVerified;
            cout << "\nPasswords must be a min 6 characters long and include at least 1 numeral\n";
            cout << "Please enter a valid password:\n";
            getline(cin, newPassword);
            pwVerified = validPassword(newPassword);
            password = newPassword;

            while (pwVerified == false){
                cout << "Please enter a valid password: \n";
                getline(cin, newPassword);
                pwVerified = validPassword(newPassword);
            }
        }
        //writeCsv("data/login_data.csv", email, password);
    }
    

    // Password min 6 characters, with at least 1 number
    bool validPassword(string pass){
        bool valid;
        while (valid != true) {
            if (pass.size() < 6){
                cout << "Password is too short.";
                break;
            }
            if (pass.size() >= 6) {
                int passwordIndex, numFlag = 0; //check password contains a number
                for (passwordIndex = 0; passwordIndex < pass.size(); passwordIndex++) {
                if (isdigit(pass[passwordIndex])) {
                    numFlag = 1;
                    valid = true;
                    cout << "**PASSWORD ACCEPTED**\n";
                    
                }   
                }
                if (numFlag == 0){   
                    cout << "\nInvalid password."; 
                    cout <<  "Password must contain at least one numeral and be 6 characters long\n"; 
                }
            }
            break;  
        }
     return valid;
    }


//  --== Early testing to be deleted once Filemanager is working ==--
//     void writeCsv(string filename, string email, string password) {
// 	std::ofstream file;
// 	file.open(filename, std::ios::app);
// 	file << email << "," << password << endl;
// 	file.close();
// }



};
    

int main() {
    login test;
    test.registerNewUser("testID");
    return 0;
}