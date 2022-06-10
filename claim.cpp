#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::string; 

struct claim {
    int id,
        policyType,
        policyID,
        payout;
        //vehicle claimedVehicle;  Will call vehicle.h file
   

    claim(){
        id = payout = policyType = policyID = 0;
    }

    int getPayOut(){
        int excess;
            if (policyType == 1){
                excess = 300;
            }
            if (policyType == 2){
                excess = 100;
            }
            if (policyType == 3){
                excess = 0;
            }
           // payout = claimedVehicle.insuredValue - excess; Needs vehicle.h file
            
            return payout;
    }



    // void makeClaim() {
    //     // claimID to be added when file manager.cpp complete
    //     cout << "Please enter the registration of the insured vehicle: ";
    //     getline(cin, vehicleRegistration);
    //     // Logic to be added. Check registration is valid, return not on policy if not.
    //     cout << "If your claim is approved. Your payout amount will be: ";
    //     //Add payout amount. It will be Ins Value - excess
    //}
};