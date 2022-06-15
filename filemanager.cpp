#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>


using std::cout;
using std::cin;
using std::string; 
using std::ios;
using std::fstream;


int writeTxt(string path, string filename, int assignedID){
    int newID = assignedID + 1;
    fstream newfile;
    newfile.open(path + filename,ios::out); //open a file to perform read operation using file object
    if(newfile.is_open()){ //checking whether the file is open 
        newfile << newID;//inserting text
        newfile.close(); //close the file object
    }

    return newID;
}

int readTxt(string path, string filename){
    string txtID;
    fstream newfile;
    int assignedID;
    newfile.open(path + filename,ios::in);  
        if(newfile.is_open()){ //checking whether the file is open 
            getline(newfile, txtID);
            assignedID = stoi(txtID); //convert string ID to int ID
            newfile.close(); //close the file object
        }
    writeTxt(path, filename, assignedID);
    return assignedID;
 }


void writeCsv(string filename, string incomingData) {
	std::ofstream file;
	file.open(filename, std::ios::app);
	file << incomingData << "\n";
	file.close();
}


string getID(string csvString){
    int index = csvString.find_first_of(","); 
    string ID = csvString.substr(0,index);
    return ID;
}


string readCsv(string filename, string uniqueID){
    std::ifstream file;
    bool idNotFound = true;
    string data = "none";

    file.open(filename, std::ios::in);
    if (file.is_open()){
        string currentLine;
        while(getline(file, currentLine) && idNotFound){
            if (uniqueID == getID(currentLine)){
                data = currentLine;
                idNotFound = false;
            }
        }
        file.close();
    }
    return data;
}


int main(){
    // --==  Test for reading txt files ==--
    //int test2 = readTxt("data/","vehicle_id_counter.txt");
    //cout << "\n" << "test read = " << test2 << "\n";

    // --== Test for writing csv ==--
    // string testCSV1 = "customerID1, username1, password1";
    // string testCSV2 = "customerID2, username2, password2";
    // writeCsv("data/login_data.csv", testCSV1);
    // writeCsv("data/login_data.csv", testCSV2);


    // --==Test for readCSV ==--
    string testCSV3 = "101";
    string testCSV4 = "103";
    cout << readCsv("data/login_data.csv", testCSV4) << "\n";
    string test = "111,ddd,fff";

    // cout << test.find_first_of(","); 
    // cout << getID(test) << "\n";
    return 0;
}
