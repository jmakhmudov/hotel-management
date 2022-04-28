#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "room.h"
using namespace std;

void setTime(Room r){
    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    int year =1900 + ltm->tm_year, month = 1 + ltm->tm_mon, day = ltm->tm_mday;
    r.setDateRent(day, month, year);
    

    
    // cout << "Time: "<< 1 + ltm->tm_hour << ":";
    // cout << 1 + ltm->tm_min << ":";
    // cout << 1 + ltm->tm_sec << endl;
}

void registration(Room r){
    
    string n, l;
    int q, d, m , y;
    char ch;

    cout << "\n\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ REGISTRATION ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
    cout << "\nEnter the first name of renter : ";
    cin >> n;
    cout << "\nEnter the last name of renter : ";
    cin >> l;
    cout << "\nEnter the number of residents : ";
    cin >> q;
    cout << "\nEnter the last date of the rent (DD>>MM>>YYYY) : ";
    cin >> d >> m >> y;
    do{
    cout << "\n\n------Confirm ? (Y/N)------";
    cin >> ch;
    if(ch == 'y' || ch == 'Y'){
        r.setRenterName(n);
        r.setRenterLast(l);
        r.setResident_q(q);
        r.setDateExpire(d, m, y);
        setTime(r);
        cout << "\n\n\t✓ Sucessfully added ✓\n";
        break;
    }
    else if(ch == 'n' || ch == 'N'){
        cout << "\n\n\tⓧ Canceled ⓧ\n";
        break;
    }
    }while(ch !='Y' || ch != 'y' || ch != 'n' || ch != 'N');
}

void addRoom(){
    int t, b;
    string i;
    float p;
    char ch;

    cout << "\n\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ADD A ROOM ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
    do{
        cout<<"\nChoose the type of room :\n➊ Standard\n➋ Lux\n➌ Royal\n";
        cin >> t;
        if(t==1||t==2||t==3){
            break;
        }
    }while(t!=1||t!=2||t!=3);
    
    cout << "\nEnter the room ID : ";
    cin >> i;
    cout << "\nEnter the number of beds : ";
    cin >> b;
    cout << "\nEnter the price per night : ";
    cin >> p;
    Room r;
    cout << "\n\n▨▨▨▨▨▨▨▨▨▨▨▨▨▨ NEW ROOM "<< i << " ▨▨▨▨▨▨▨▨▨▨▨▨▨▨";
    cout << "\nType : ";
    switch(t){
    case 1:
        cout << "STANDARD";
        break;
    case 2:
        cout << "LUX";
        break;
    case 3: 
        cout << "ROYAL";
        break;
    }
    cout << "\nBeds : " << b;
    cout << "\nPrice : $" << p;

    do{
    cout << "\n\n------Confirm ? (Y/N)------";
    cin >> ch;
    if(ch == 'y' || ch == 'Y'){
        r.setType(t);
        r.setRoom_id(i);
        r.setBeds(b);
        r.setPrice(p);
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
    fstream file("database.dat", ios::binary);
    addRoom();
    
    
    
    

    system("pause");
    return 0;
}


