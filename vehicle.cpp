//Import filemanager.cpp
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::string; 

struct vehicle{
	int id,
        insuredValue;
    string registration,
        make,
	    model,
	    colour;
    

    vehicle(){
        id = insuredValue = 0;
        registration = make = model = colour = "unassigned";
    } 
    //int year;
	//int doors{};
	//string transmission{}

    void printVehicle(){
        cout << "\n";
        cout << "   VEHICLE INFORMATION FOR: " << id << "\n";
        cout << "   ---------------------------------- \n";
        cout << "   Vehicle Registration:  " << registration << "\n";
        cout << "   Make:                  " << make << "\n";
        cout << "   Model:                 " << model << "\n";
        cout << "   Colour:                " << colour << "\n";
        cout << "   Insured Value:         $" << insuredValue << "\n";
        cout << "   ---------------------------------- \n";

    }

    void getVehicleInfo(){
        // unique id to be generated once filemanager.cpp built
        cout << "Please input vehicle information \n";
        cout << "Enter registration: ";
        getline(cin, registration);
        cout << "Enter make: ";
        getline(cin, make);
        cout << "Enter model: ";
        getline(cin, model);
        cout << "Enter colour: ";
        getline(cin, colour);
        cout << "Enter insured value: " ;
        cin >> insuredValue;
            if (insuredValue <= 0 || insuredValue >= 100000){
                cout << "Invalid value. Insured value must be more than $0 and less than $100000\n";
            }

    }

};


int main() {
    vehicle test;
    test.getVehicleInfo(); 
    test.printVehicle();
    return 0;
}