#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void setTime(){
    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);
    // print various components of tm structure.
    cout << "Year: "<< 1900 + ltm->tm_year << endl;
    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    cout << "Day: "<< ltm->tm_mday << endl;
    
    
    cout << "Time: "<< 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
}