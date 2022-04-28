#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "settime.h"
#include "room.h"
using namespace std;

void registration(Room r){
    
    string n, l;
    int q, d, m , y;
    

    cout << "\nEnter the firts name of renter : ";
    cin >> n;
    cout << "\nEnter the last name of renter : ";
    cin >> l;
    cout << "\nEnter the number of residents : ";
    cin >> q;
    cout << "\nEnter the last date of the rent (DD>>MM>>YYYY) : ";
    cin >> d >> m >> y;
    char ch;
    do{
    
    cout << "\n\n------Confirm ? (Y/N)------";
    cin >> ch;
    if(ch == 'y' || ch == 'Y'){
        r.setRenterName(n);
        r.setRenterLast(l);
        r.setResident_q(q);
        r.setDateExpire(d, m, y);
        cout << "\n\n\t✓ Sucessfully added ✓\n";
        break;
    }
    else if(ch == 'n' || ch == 'N'){
        cout << "\n\n\tⓧ Canceled ⓧ\n";
        break;
    }
    }while(ch !='Y' || ch != 'y' || ch != 'n' || ch != 'N');
}

int main(){
    // try {
    // int age = 15;
    // if (age >= 18) {
    //     cout << "Access granted - you are old enough.";
    // } else {
    //     throw runtime_error("404");
    // }
    // }
    // catch (...) {
    // cout << "Access denied - You must be at least 18 years old.\n";
    // } 
    Room r;
    registration(r);
    
    

    system("pause");
    return 0;
}


