#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main() {

	//custFile == customer data file
	std::ofstream custFile("data/customer_data.csv");

	custFile << "test column 1,test column 2,testcolumn 3";
	custFile << "1,2,3";
	custFile << "2,3,4";
	custFile << "3,4,5";

	custFile.close();

	return 0;
}