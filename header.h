#pragma once
#include <iostream>
#include <vector>

//file manager
int writeTxt(std::string filename, int assignedID);
int readTxt(std::string filename);
void writeCsv(std::string filename, std::string incomingData);
std::string getID(std::string csvString);
std::string readCSV(std::string filename, std::string uniqueID);
std::vector<std::string> CSVtoVector(std::string filename, std::string uniqueID);

//login
struct Login {
    std::string userID;
    std::string email;
    std::string password;

    Login() {
        userID = email = password = "null";
    }
};
bool validEmail(std::string email);
void registerNewUser(std::string newUserID);
void printDetails();
bool validPassword(std::string pass);
void printFromCSV(std::string filename, std::string ID);
void loadCSV(std::string filename, std::string ID);

//vehicle
struct Vehicle {
    int insuredValue;
    std::string ID,
    registration,
        make,
        model,
        colour;


    Vehicle() {
        ID = insuredValue = 0;
        registration = make = model = colour = "unassigned";
    }
    //int year;
    //int doors{};
    //string transmission{}
};

//policy
struct Policy {
    std::string policyID; // Same as customer ID, as each customer can only have one policy.
    std::string policyExcess;
    Vehicle insuredVehicle;
    int policyType;

    //vector<insVehicle>; Vehicles to be pulled from vehicle cpp
    Policy() {
        policyExcess = "null"; //Will be zero for PREMIUM policy holders
        policyType = 0;
        policyID = "null";
    }
};
std::string getPolicyType();
void printPolicy();
void newPolicy(std::string customerID);

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
std::string fetchClientNum();
void newCustomer();
void createNewPolicy();

void printVehicle();
void getVehicleInfo();

//menus
void mainMenu();
