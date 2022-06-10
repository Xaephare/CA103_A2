#include <iostream>
#include <regex>
using std::cout;
using std::cin;
using std::string; 

struct login {
    string email;
    string password;

    login() {
        email = password = "unassigned";
    }

    // Checks email address is valid
    bool validEmail(string email){
        const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(email,pattern);
    }

    // Register new customer or admin.
    // Still need add writing to login_data.txt for storing
   login registerNewUser(){
        login user;
        string newEmail;
        string newPwd;
        bool emVerified;
        
        cout << "\nREGISTER NEW LEGEND INSURANCE USER\n";
        cout << "Please enter a valid email eddress: ";
        getline(cin, newEmail);
        if (validEmail(newEmail)){
            emVerified = true;
            newEmail = user.email;
            cout << "**EMAIL ACCEPTED**\n";
        }       
            while (emVerified != true) {
            cout << "\nEMAIL INVALID.\nPlease enter a valid email: ";
            getline(cin, newEmail);
            
                if (validEmail(newEmail)) {
                emVerified = true;
                newEmail = user.email;
                cout << "**EMAIL ACCEPTED**\n";
                }
        }
        // If email is verified, then function will move on to password.
        if (emVerified == true){
            bool pwVerified;
            cout << "\nPasswords must be a min 6 characters long and include at least 1 numeral\n";
            cout << "Pleas enter a valid password:\n";
            getline(cin, newPwd);
            pwVerified = validPassword(newPwd);

            while (pwVerified == false){
                cout << "Please enter a valid password: \n";
                getline(cin, newPwd);
                pwVerified = validPassword(newPwd);

            }
        }
        return user;
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
};
    

int main() {
    login test;
    test.registerNewUser();
    return 0;
}