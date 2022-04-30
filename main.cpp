#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "room.h"
using namespace std;

void setTime(Room& r, int a){
    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year =1900 + ltm->tm_year, month = 1 + ltm->tm_mon, day = ltm->tm_mday;
    
    if (a==1){
        r.setDateRent(day, month, year);
    }
    else if (a==2){
        r.setDateClean(day, month, year);
    }
    // cout << "Time: "<< 1 + ltm->tm_hour << ":";
    // cout << 1 + ltm->tm_min << ":";
    // cout << 1 + ltm->tm_sec << endl;
}

void registration(Room& r){
    
    string n, l;
    int q, d, m , y;
    char ch;
    long p;

    cout << "\n\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ REGISTRATION ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
    cout << "\nEnter the first name of guest : ";
    cin >> n;
    cout << "Enter the last name of guest : ";
    cin >> l;
    cout << "Enter the phone number : ";
    cin >> p;
    cout << "Enter the number of guests : ";
    cin >> q;
    cout << "Enter the last date of the rent (DD>>MM>>YYYY) : ";
    cin >> d >> m >> y;
    do{
    cout << "\n\n------Confirm ? (Y/N)------";
    cin >> ch;
    if(ch == 'y' || ch == 'Y'){
        r.setGuestName(n);
        r.setGuestLast(l);
        r.setGuest_q(q);
        r.setDateExpire(d, m, y);
        r.setGuestPhone(p);
        setTime(r, 1);
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
    ofstream fout("database.dat", ios_base::binary|ios_base::app);

    do{
        cout << "\033[2J\033[1;1H";
        cout << "\n\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ NEW ROOM ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
        cout<<"\n\nChoose the type of room :\n➊ Standard\n➋ Lux\n➌ Royal\n";
        cin >> t;
        if(t==1||t==2||t==3){
            break;
        }
    }while(t!=1||t!=2||t!=3);
    
    cout << "\nEnter the room ID : ";
    cin >> i;
    cout << "Enter the number of beds : ";
    cin >> b;
    cout << "Enter the price per night : ";
    cin >> p;
    cout << "\033[2J\033[1;1H";
    Room r;

    do{
        cout << "\033[2J\033[1;1H";
        cout << "\n\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ NEW ROOM "<< i << " ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
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
        cout << "\n\n------ Confirm ? (Y/N) ------";
        cin >> ch;
    if(ch == 'y' || ch == 'Y'){
        
        r.setType(t);
        r.setRoom_id(i);
        r.setBeds(b);
        r.setPrice(p);
        
        do{
        cout << "\n\n------ Is the room cleaned? (Y/N) ------";
        cin >> ch;
        if(ch == 'y' || ch == 'Y'){
            setTime(r, 2);
            cout << "\033[2J\033[1;1H";
            cout << "\n\t✓ The Last Cleaning Date Was Successfully Added ( "<< r.getDateCleanDay()<<"/"<<r.getDateCleanMonth()<<"/"<<r.getDateCleanYear() <<" ) ✓";
            
            break;

        }
        else if(ch == 'n' || ch == 'N'){
            cout << "\033[2J\033[1;1H";
            cout << "\n\n\tⓧ Cleaning Date Was Not Set ⓧ\n";
            break;
        }
        }while(ch !='Y' || ch != 'y' || ch != 'n' || ch != 'N');
        fout.seekp(fout.tellp(), ios::end);
        fout.write((char*)&r, sizeof(r));
        fout.close();
        cout << "\n\t✓ Room Was Sucessfully Added ✓\n";

        break;
    }
    else if(ch == 'n' || ch == 'N'){
        cout << "\n\n\tⓧ Canceled ⓧ\n";
        fout.close();
        break;
    }
    }while(ch !='Y' || ch != 'y' || ch != 'n' || ch != 'N');
    
}

void showRooms(){
    int m;
    ifstream fin("database.dat", ios::binary);
    Room r;
    do{
        cout << "\n\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ SHOW ROOM ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
        cout << "\n\n\t\t➊ STANDARD\n\t\t➋ LUX\n\t\t➌ ROYAL\n\n\t\t⓿ EXIT\n";
        cin >> m;
        switch(m){
        case 1:
            cout << "\n\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ STANDARD ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
            cout << "\nID\tBEDS\tPRICE\tSTATUS\tCLEANING DATE";
            while (fin.read((char*)&r, sizeof(r))){
                if (r.getType()==1){
                    if (r.getGuest_q()==0){
                        if(r.getDateCleanDay()==0){

                            cout << "\n" << r.getRoom_id()<<"\t"<<r.getBeds()<<"\t"<<"$"<<r.getPrice()<<"\t"<<"Empty\tNone"<<endl;
                        }
                        else{cout << "\n" << r.getRoom_id()<<"\t"<<r.getBeds()<<"\t"<<"$"<<r.getPrice()<<"\t"<<"Empty\t"<< r.getDateCleanDay()<<"/"<<r.getDateCleanMonth()<<"/"<<r.getDateCleanYear()<<endl;}

                    }
                    else if(r.getGuest_q()!=0){
                        if(r.getDateCleanDay()==0){

                            cout << "\n" << r.getRoom_id()<<"\t"<<r.getBeds()<<"\t"<<"$"<<r.getPrice()<<"\t"<<"Occupied\tNone"<<endl;
                        }
                        else{cout << "\n" << r.getRoom_id()<<"\t"<<r.getBeds()<<"\t"<<"$"<<r.getPrice()<<"\t"<<"Occupied\t"<< r.getDateCleanDay()<<"/"<<r.getDateCleanMonth()<<"/"<<r.getDateCleanYear()<<endl;}
                    }
                }
                
            }
            cout << "\n\n\t\t⓿ EXIT\n";
            cin>>m;
            fin.close();
            break;
        case 2:
            break;
        }
    }while(m!=0);
    
}

void menu(){
    int m=1;
    fstream file("database.dat", ios::binary);
    file.close();
    while(m!=0){
        cout << "\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ HOTEL MANAGEMENT SYSTEM ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
        cout << "\n\n\t\t➊ REGISTRATION\n\t\t➋ ROOMS\n\t\t➌ GUESTS\n\t\t➍ DATA EXPORT\n\n\t\t⓿ EXIT\n";
        cin >> m;
        switch(m){
        case 0: 
            m=0;
            break;
        case 1: 
            cout << "\033[2J\033[1;1H";
            break;
        case 2:
            int a;
            cout << "\033[2J\033[1;1H";
            cout << "\n▓▓▓▓▓▓▓▓▓▓▓▓▓▓ ROOMS ▓▓▓▓▓▓▓▓▓▓▓▓▓▓";
            cout << "\n\n\t\t➊ SHOW ROOMS\n\t\t➋ NEW ROOM\n\n\t\t⓿ EXIT\n";
            cin >> a;
            switch(a){
            case 1:
                cout << "\033[2J\033[1;1H";
                showRooms();
                break;
            case 2: 
                cout << "\033[2J\033[1;1H";
                addRoom();
                break;
            }
            break;
        default: break;

        }
    }
    
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
    menu();
    system("pause");
    return 0;
}


