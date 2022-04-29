#include <iostream>
#include <fstream>
using namespace std;

class Room{
private:
    int beds, guest_q, type; //type 1-standard 2-lux 3-royal
    int date_of_rent[3], date_of_expire[3], date_of_clean[3];
    string room_id, guest_first_name, guest_last_name;
    float price_per_night;
    long guest_phone;
public: 
    Room(){}
    void setRoom_id(string r){ room_id = r;}
    void setBeds(int b){ beds = b;}    
    void setGuest_q(int r){ guest_q = r;}
    void setGuestName(string a){ guest_first_name = a;}
    void setGuestLast(string a){ guest_last_name = a;}
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
    void setDateClean(int d, int m, int y)
    {
        date_of_clean[0] = d;
        date_of_clean[1] = m;
        date_of_clean[2] = y;
    }
    void setPrice(float p){ price_per_night = p;}
    void setType(int t){ type = t;}
    void setGuestPhone(long p){ guest_phone = p;}


    string getRoom_id(){ return room_id;}
    int getBeds(){ return beds;}    
    int getGuest_q(){ return guest_q;}
    int getDateRentDay(){ return date_of_rent[0];}
    int getDateRentMonth(){ return date_of_rent[1];}
    int getDateRentYear(){ return date_of_rent[2];}
    int getDateExpireDay(){ return date_of_expire[0];}
    int getDateExpireMonth(){ return date_of_expire[1];}
    int getDateExpireYear(){ return date_of_expire[2];}
    int getDateCleanDay(){ return date_of_clean[0];}
    int getDateCleanMonth(){ return date_of_clean[1];}
    int getDateCleanYear(){ return date_of_clean[2];}
    int getType(){ return type;}
    string getGuestName(){ return guest_first_name;}
    string getGuestLast(){ return guest_last_name;}
    float getPrice(){ return price_per_night;}
    long getGuestPhone(){ return guest_phone;}
};