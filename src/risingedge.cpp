void opcontrol() {
    pros::Controller master(CONTROLLER_MASTER); //I always name the controller "master" don't judge
    int count = 0;
    bool btnA = false;
    int n = 150;
    int target = 0;
    
    while (true) { //rising edge 
        if(master.get_digital(DIGITAL_A) && !btnA){  //if button is pressed and the button hasn't been pressed before add one to "count"
            count++; //MISSING SEMI-COLONS ON LINE 12, 15, and 18
            if (count %2 == 1) { //elaborate on the logic behind "target = target"
                target = target
            }
            if (count %2 == 0) {
                target = 150
            }
            if (count %2 == 1/3) { //when will the remainder by 1/3? 
                target = target
                count = 1
            }

        } //check the brackets as well 
        btnA = master.get_digital(DIGITAL_A); //defining variable as button press
        pros::delay(20);
    }

}
