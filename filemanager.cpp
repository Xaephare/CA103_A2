#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>


using std::cout;
using std::cin;
using std::string; 
using std::ios;
using std::fstream;


int writeTxt(string filename, int assignedID){  // To be called after ID has been assigned, will increment existing ID by one so it's ready to be assigned the next time readTxt is called
    int newID = assignedID + 1;
    fstream newfile;
    newfile.open(filename,ios::out); //open a file to perform read operation using file object
    if(newfile.is_open()){ //checking whether the file is open 
        newfile << newID;//inserting text
        newfile.close(); //close the file object
    }
    return newID;
}

int readTxt(string filename){   // Reads ID number ready to be assigned
    string txtID;
    fstream newfile;
    int assignedID = 0;
    newfile.open(filename,ios::in);  // Opens file and finds current ID to be assigned
        if(newfile.is_open()){  
            getline(newfile, txtID);
            assignedID = stoi(txtID); 
            newfile.close(); 
        }
    writeTxt(filename, assignedID);
    return assignedID;
}

void writeCsv(string filename, string incomingData) { // Called within other functions, takes incoming data as a string and writes it to CSV.
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

string readCSV(string filename, string uniqueID){  // Searches CSV for ID to return correct line of
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

std::vector<std::string> CSVtoVector(string filename, string uniqueID){
    string data = readCSV(filename, uniqueID);
    std::vector<std::string> vectorData;
    std::stringstream sstr(data);
    while(sstr.good())
    {
        std::string substr;
        getline(sstr, substr, ',');
        vectorData.push_back(substr);
    }
    // FOLLOWING TWO LINES PRINT VECTORS AS TEST 
    ///*
    for (std::size_t i = 0; i < vectorData.size(); i++)
        std::cout << vectorData[i] << std::endl; 
    //*/
    return vectorData;
}

// int main(){
//     // --==  Test for reading txt files ==--
//     //int test2 = readTxt("data/","vehicle_id_counter.txt");
//     //cout << "\n" << "test read = " << test2 << "\n";

//     // --== Test for writing csv ==--
//     // string testCSV1 = "customerID1, username1, password1";
//     // string testCSV2 = "customerID2, username2, password2";
//     // writeCsv("data/login_data.csv", testCSV1);
//     // writeCsv("data/login_data.csv", testCSV2);


//     // --==Test for readCSV ==--
//     string testCSV3 = "101";
//     string testCSV4 = "103";
//     cout << readCsv("data/login_data.csv", testCSV4) << "\n";
//     string test = "111,ddd,fff";
//     CSVtoVector("data/login_data.csv", testCSV4);
//     // cout << test.find_first_of(","); 
//     // cout << getID(test) << "\n";
//     return 0;
// }
