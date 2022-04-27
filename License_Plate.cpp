#include <iostream>
#include <string>
using namespace std;

int main (){
    string plateNumber;

    cout << "Enter the current license plate number: " << endl;
    cin >> plateNumber;
    // Itterates throught the Numeric part of the lisence
    for (int i = plateNumber.size() - 1; i > 2; --i){
        if (plateNumber.at(i) == '9'){
            plateNumber.at(i) = '0';
        }
        else{
            plateNumber.at(i) += 1;
            break;
        }
    }

    // If Numeric is all 0 this happens
    if((plateNumber.at(3) == '0') && (plateNumber.at(4) == '0') && (plateNumber.at(5) == '0')){
        // Itterates throught the Alphabetic part of the lisence
        for (int i = plateNumber.size() - 4; i >= 0; --i){
            if (plateNumber.at(i) == 'Z'){
                plateNumber.at(i) = 'A';
            }
            else{
                plateNumber.at(i) += 1;
                break;
            }
        }
    }

    cout << "The next license plate number as per the DMV would be:" << endl;
    cout << plateNumber;
}
