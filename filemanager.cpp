#include <iostream>
#include <fstream>
#include <string>
using namespace std;  //remove later 

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




//     newfile.open(path + filename,ios::in); //open a file to perform read operation using file object
//     if (newfile.is_open()){ //checking whether the file is open
//       string tp;
//       while(getline(newfile, tp)){ //read data from file object and put it into string.
//          cout << tp << "\n"; //print the data of the string
//       }
//       newfile.close(); //close the file object.
//    }



int main(){
    int test2 = readTxt("data/","vehicle_id_counter.txt");
    cout << "\n" << "test read = " << test2 << "\n";
    return 0;
}
