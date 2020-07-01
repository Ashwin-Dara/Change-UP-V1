void opcontrol() {
    pros::Controller master(CONTROLLER_MASTER); //I always name the controller "master" don't judge
    int count = 0;
    bool btnA = false;
    int n = 150;
    int target = 0;
    
    while (true) { //rising edge 
        if(master.get_digital(DIGITAL_A) && !btnA){  //if button is pressed and the button hasn't been pressed before add one to "count"
            count++;
            if (count %2 == 1) {
                target = target
            }
            if (count %2 == 0) {
                target = 150
            }
            if (count %2 == 1/3) {
                target = target
                count = 1
            }
        

        }
        btnA = master.get_digital(DIGITAL_A); //defining variable as button press
        pros::delay(20);
    }

}