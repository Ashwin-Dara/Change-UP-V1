#include "main.h"
#include "drive.h"
// author @Aayush
namespace drive{
    /*
    void opcontrol(){
        int rPwr, lPwr; 
        int rYaxis, lYaxis; 
        rYaxis = controller.get_analog(ANALOG_RIGHT_Y);
        lYaxis = controller.get_analog(ANALOG_LEFT_Y);
        rPwr = (abs(rYaxis) > 2) ? rYaxis : 0;
        lPwr = (abs(lYaxis) > 2) ? lYaxis : 0; 
        right_move(rPwr);
        left_move(lPwr);
    }
    */
   void opcontrol(){
        int fPwr, tPwr; //forwardpower and turnpower
        int rYaxis, lXaxis; //controller axis 
        rYaxis = controller.get_analog(ANALOG_RIGHT_Y);
        lXaxis = controller.get_analog(ANALOG_LEFT_X);
        fPwr = (abs(rYaxis) > 2) ? rYaxis : 0;
        tPwr = (abs(lXaxis) > 2) ? lXaxis : 0;  
        chas_move(fPwr + tPwr, fPwr - tPwr);
    }
}