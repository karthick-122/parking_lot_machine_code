#include "C:\Users\KARTHICK\Documents\vs code\cpp\parking lot system\slot.cpp"

#include<vector>

class parking_lot
{
    string name;
    int floor;
    int slots;
    vector<vector<slot>> pk;
public:
    
    bool  create_parking_lot(string _name, int _floor, int _slots_in_each_floor)
    {
        name = _name;
        floor = _floor;
        slots = _slots_in_each_floor;
        for(int i=0;i<floor;i++)
        {
            vector<slot>slt;
            types tt= TRUCK;
            for(int j=0;j<slots;j++)
            {
                
                if   (j==0) tt = TRUCK;
                else if(j==1 || j==2) tt = BIKE;
                else
                    tt= CAR;
               // cout<<tt<<" : ";
                slot ss(tt);
                slt.push_back(ss);
            }
        //    cout<<endl;
            pk.push_back(slt);
        }
        cout<<"---------"<<_name<<" is the name &  the num.of floors is: "<<_floor<<" & num.of slots is:  "<<_slots_in_each_floor<<" ------"<<endl;
        cout<<"********************** parking lot created sucessfully *************************"<<endl<<endl;
        return 1;
    }
    bool Display_free_count()
    {
            types tt;
            int type;
            cout<<endl<<"ENTER 0 FOR TRUCK : 1 FOR BIKE : 2 FOR CAR"<<endl<<endl;
             cout<<"ENTER THE VEHICAL TYPE :";
             cin>>type;
            tt = (types)type;
        for(int flr = 0;flr<floor;flr++)
        {
            int count = 0;
            for(int slt=0;slt<slots;slt++)
            {
                if(pk[flr][slt].give_vehical_type()==tt && pk[flr][slt].is_full()==0)
                   count+=1;
            }
            cout<<"No. of free slots for "<< print[tt]<<" on Floor "<<flr+1 <<" : "<<count<<endl;
        }

        return 1;
    }
    bool Display_free_slots()
    {
         types tt;
        int type;
        cout<<endl<<"ENTER 0 FOR TRUCK : 1 FOR BIKE : 2 FOR CAR"<<endl<<endl;
        cout<<"ENTER THE VEHICAL TYPE :";
        cin>>type;
            tt = (types)type;
         for(int flr = 0;flr<floor;flr++)
        {
             cout<<"Free slots for "<<print[tt]<<" on Floor "<<flr+1 <<" : ";

            for(int slt=0;slt<slots;slt++)
            {
                if(pk[flr][slt].give_vehical_type()==tt && pk[flr][slt].is_full()==0)
                {
                    cout<<slt+1<<",";
                }

            }
            cout<<endl;
        }
        cout<<endl<<endl;

        return 1;

    }

    void Display_occupied_slots()
    {
        types tt;
        int type;
        cout<<endl<<"ENTER 0 FOR TRUCK : 1 FOR BIKE : 2 FOR CAR"<<endl<<endl;
        cout<<"ENTER THE VEHICAL TYPE :";
        cin>>type;
        tt = (types)type;
         for(int flr = 0;flr<floor;flr++)
        {
             cout<<"occupied_slots "<<print[tt]<<" on Floor "<<flr+1 <<" : ";

            for(int slt=0;slt<slots;slt++)
            {
                if(pk[flr][slt].give_vehical_type()==tt && pk[flr][slt].is_full()==1)
                {
                    cout<<slt+1<<",";
                }

            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }

    bool park_the_vehical()
    {
        types tt;
        string reg_num, colour;
        int typ;
        cout<<endl<<"ENTER 0 FOR TRUCK : 1 FOR BIKE : 2 FOR CAR"<<endl<<endl;
        cout<<"ENTER THE VEHICAL TYPE : REG.NUM : COLOUR";
        cin>>typ>>reg_num>>colour;
        tt = (types)typ;

        for(int flr =0;flr<floor;flr++)
        {
            int slt ;
            int till;

            if   (tt == TRUCK)
            {
                slt =0;
                till=1;
            }

            else if(tt == BIKE) 
            {
                slt =1;
                till =3;
            }
            else
            {
                slt = 3;
                till = slots;
            }

            for(slt ;slt<till;slt++)
            {
                if(pk[flr][slt].is_full()==0)
                {
                    pk[flr][slt]. park_here(tt,reg_num, colour);
                cout<<"VEHICAL PARKED TICKET ID IS : "<<name<<"_"<<flr+1<<"_"<<slt+1<<endl;
                return 1;
                }
            }
        }
        cout<<" ---------- SORRY NO SPACE TO PARK ----------"<<endl;
        return 0;
    }
    bool un_park_the_vehical()
    {
        string _name;int flr, slot;
        cout<<"ENTER TICKET ID -  NAME : FLR : SLOT to unpark the vehical"; 
        cin>>_name>>flr>>slot;
            flr-=1;
            slot-=1;
        if(flr>floor||flr<0||slot>slots||slot<0)
        {
            cout<<"++++++++++++++++ INVALID ticket ID ++++++++++++++"<<endl;return 0;
        }

        if(_name==name && pk[flr][slot].is_full()==1 )
        {
            pk[flr][slot].un_park_here();
            cout<<"UNPARKED SUCESSFULLY"<<endl;
            return 1;
        }
        cout<<"++++++++++++++++ INVALID ticket ID ++++++++++++++"<<endl;
        return  0;
    }

    bool boot_the_software(string _name,int _floor, int _slots)
    {
         parking_lot my_parking_lot;
         my_parking_lot.create_parking_lot(_name,_floor,_slots);
         int expression =0;
         while(1)
         {
            expression =0;
            cout<<endl<<"ENTER 1 TO park the vechical "<<endl;
            cout<<"ENTER 2 TO un_park the vehical "<<endl;
            cout<<"ENTER 3 TO view the parked vehicals "<<endl;
            cout<<"ENTER 4 TO view the free slots "<<endl;
            cout<<"ENTER 5 TO view the free slots count ";
            cin>>expression;

            switch (expression)
            {
            case 1:
                my_parking_lot.park_the_vehical();
                break;
            case 2:
                my_parking_lot.un_park_the_vehical();
                break;
            case 3:
                my_parking_lot.Display_occupied_slots();
                break;
            case 4:
                my_parking_lot.Display_free_slots();
                break;
            case 5:
                my_parking_lot.Display_free_count();
                break;
            default:
                break;
            }
         }
        return 1;
    }

};

int main()
{
    parking_lot pflt;
    pflt.boot_the_software("PL123",2,6);
    /*
    pflt.create_parking_lot("PK123",2,6);
    pflt.Display_free_slots(BIKE);
     pflt.Display_occupied_slots(CAR);

     pflt.park_the_vehical(BIKE,"TN 36 Y 2222","GREEN");
      pflt.Display_occupied_slots(BIKE);
*/
    cout<<"you can do it"<<endl;
    return 0;
}

