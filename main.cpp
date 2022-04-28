#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Room{
private:
    int room_id, beds, resident_q;
    string renter_first_name, renter_last_name, date_of_rent, date_of_expire;
    float price_per_night;
public: 
    void setRoom_id(int r){ room_id = r;}
    void setBeds(int b){ beds = b;}    
    void setResident_q(int r){ resident_q = r;}
    void setRenterName(string a){ renter_first_name = a;}
    void setRenterLast(string a){ renter_last_name = a;}
    void setDateRent(string d){ date_of_rent = d;}
    void setDateExpire(string d){ date_of_expire = d;}
    void setPrice(float p){ price_per_night = p;}

    int getRoom_id(){ return room_id;}
    int getBeds(){ return beds;}    
    int getResident_q(){ return resident_q;}
    string getRenterName(){ return renter_first_name;}
    
    string getDateRent(){ return date_of_rent;}
    string getDateExpire(){ return date_of_expire;}
    float getPrice(){ return price_per_night;}
};

void registration(){
    string s;
    int i;
    float f;
    cout << "\nEnter the name of renter : ";
    cin >> s;
    cout << ""
}

int main(){
    

    
    
    
    

    system("pause");
    return 0;
}
