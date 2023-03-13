#include <iostream>
using namespace std;
#include <string>

enum types
{
   TRUCK = 0,
   BIKE = 1,
   CAR
};

string print[]  {"TRUCK","BIKE","CAR"};

class vehical
{
    types type;
    string reg_number;
    string colour;
    public:
    vehical(types _type, string _reg_number, string _colour)
    {
        type = _type;
        reg_number = _reg_number;
        colour = _colour;
    }

};
