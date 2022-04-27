#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Room{
private:
    int room_id, beds, resident_q;
    string renter, date_of_rent, date_of_expire;
    float price_per_night;
public: 
    void setRoom_id(int r){ room_id = r;}
    void setBeds(int b){ beds = b;}    
    void setResident_q(int r){ resident_q = r;}
    void setRenter(string a){ renter = a;}
    void setDateRent(string d){ date_of_rent = d;}
    void setDateExpire(string d){ date_of_expire = d;}
    void setPrice(float p){ price_per_night = p;}

    int getRoom_id(){ return room_id;}
    int getBeds(){ return beds;}    
    int getResident_q(){ return resident_q;}
    string getRenter(){ return renter;}
    string getDateRent(){ return date_of_rent;}
    string getDateExpire(){ return date_of_expire;}
    float getPrice(){ return price_per_night;}





};




int main(){
    

    
    
    
    

    system("pause");
    return 0;
}
