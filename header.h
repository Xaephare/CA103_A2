#pragma once
#include <iostream>
#include <vector>


//Structs
struct Login {
    std::string userID;
    std::string email;
    std::string password;

    Login() {
        userID = email = password = "null";
    }
};
struct Vehicle {
    std::string ID;
    int insuredValue;
    std::string registration,
        make,
        model,
        colour;


    Vehicle() {
        ID = '0';
        insuredValue = 0;
        registration = make = model = colour = "unassigned";
    }
    //int year;
    //int doors{};
    //string transmission{}
};
struct Policy {
    Vehicle insuredVehicle;
    std::string policyID; // Same as customer ID, as each customer can only have one policy.
    std::string policyExcess;
    std::string policyType;
    //vector<insVehicle>; Vehicles to be pulled from vehicle cpp
    Policy() {
        policyType = policyExcess = policyID = "null";
    }
};

struct Admin {
    Login userLoginInfo;
    std::string ID; //Any client number of 0 is a void client or maybe an admin?
    std::string firstName,
        lastName,
        phone;
};
//customer
struct Customer {
    Login userLoginInfo;
    std::string ID; //Any client number of 0 is a void client or maybe an admin?
    std::string firstName,
        lastName,
        phone;
    Policy customerPolicyInfo;

    Customer() {
        ID = firstName = lastName = phone = "null";
    }
};



//admin
std::string fetchAdminNum();
void newAdmin();
void loadAdmin(std::string filename, std::string ID);

//customer
std::string fetchClientNum();
void newCustomer();
void createNewPolicy();
bool updateCsv();
void customerMenu(Login session);
Customer loadCustomer(std::string filename, std::string ID);

//file manager
int writeTxt(std::string filename, int assignedID);
int readTxt(std::string filename);
void writeCsv(std::string filename, std::string incomingData);
std::string getID(std::string csvString);
std::string readCSV(std::string filename, std::string uniqueID);
std::vector<std::string> CSVtoVector(std::string filename, std::string uniqueID);

//login
bool validEmail(std::string email);
void registerNewUser(std::string newUserID);
void printDetails();
bool validPassword(std::string pass);
void printFromCSV(std::string filename, std::string ID);
bool loadLogin(std::string filename, std::string ID);
Login checkLogin();

//menus
void openingMenu();
void customerOpeningMenu();
void adminOpeningMenu();

//policy
std::string getPolicyType(int policyChoice);
void printPolicy();
void newPolicy(std::string customerID);
Policy loadPolicy(std::string filename, std::string ID);

//vehicle
void printVehicle();
Vehicle getVehicleInfo(std::string ID);
std::string fetchVehicleIDNum();
Vehicle loadVehicle(std::string filename, std::string ID);