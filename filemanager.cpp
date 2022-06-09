#include <iostream>
#include <fstream>
#include <string>
using namespace std;  //remove later 


int readTxt(string path, string filename){
    int newID = 0;
    fstream newfile;
    newfile.open(path + filename,ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()){ //checking whether the file is open
        string lastID;
        getline(newfile, lastID); //read data from file object and put it into string.
        cout << "here\n" << lastID;
        cout << "\n" << lastID << "\n"; // debug printing, previous ID
        newID = stoi(lastID);
        string newIDstring = std::to_string(newID);
        cout << newID << "\n"; // debug printing, previous ID
        newfile << newIDstring; //inserting text
        newfile.close(); //close the file object
   }
   return newID;
}

int main(){
    int test = readTxt("data/","vehicle_id_counter.txt");
    cout << "\n" << test << "\n";
    return 0;
}
// read & write csv text file