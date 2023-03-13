#include "C:\Users\KARTHICK\Documents\vs code\cpp\parking lot system\vehicle.cpp"

class slot
{
    types vehical_type;
    vehical* veh;
    public:
    slot(types _vehical_type)
    {
         veh = NULL;
         vehical_type = _vehical_type;
    }
    bool park_here(types _type, string _reg_number, string _colour)
    {
         veh = new vehical( _type, _reg_number,  _colour);
         return 1;
    }
    bool un_park_here()
    {
        free (veh);
        veh = NULL;
        return 1;
    }
    bool is_full()
    {
        return veh!=NULL;
    }
    types give_vehical_type()
    {
      //  cout<<"im here"<<endl;
        return vehical_type ;
    }



};