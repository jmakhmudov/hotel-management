#include <iostream>
#include <fstream>
using namespace std;

class Room{
private:
    int beds, resident_q, type; //type 1-standard 2-lux 3-royal
    int date_of_rent[3], date_of_expire[3];
    string room_id, renter_first_name, renter_last_name;
    float price_per_night;
public: 
    Room(){}
    void setRoom_id(string r){ room_id = r;}
    void setBeds(int b){ beds = b;}    
    void setResident_q(int r){ resident_q = r;}
    void setRenterName(string a){ renter_first_name = a;}
    void setRenterLast(string a){ renter_last_name = a;}
    void setDateRent(int d, int m, int y){ 
        date_of_rent[0] = d;
        date_of_rent[1] = m;
        date_of_rent[2] = y;
    }
    void setDateExpire(int d, int m, int y){ 
        date_of_expire[0] = d;
        date_of_expire[1] = m;
        date_of_expire[2] = y;
    }
    void setPrice(float p){ price_per_night = p;}
    void setType(int t){ type = t;}


    string getRoom_id(){ return room_id;}
    int getBeds(){ return beds;}    
    int getResident_q(){ return resident_q;}
    int getDateRentDay(){ return date_of_rent[0];}
    int getDateRentMonth(){ return date_of_rent[1];}
    int getDateRentYear(){ return date_of_rent[2];}
    int getDateExpireDay(){ return date_of_expire[0];}
    int getDateExpireMonth(){ return date_of_expire[1];}
    int getDateExpireYear(){ return date_of_expire[2];}
    int getType(){ return type;}
    string getRenterName(){ return renter_first_name;}
    string getRenderLast(){ return renter_last_name;}
    float getPrice(){ return price_per_night;}
};