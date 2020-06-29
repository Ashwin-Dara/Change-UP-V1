void opcontrol() {
    pros::Controller master(CONTROLLER_MASTER); //I always name the controller "master" don't judge
    int count;
    bool btnA;
    int n = 150;
    int target;
    
    while (true) { //rising edge 
        if(master.get_digital(DIGITAL_A) && !btnA){  //if button is pressed and the button hasn't been pressed before add one to "count"
            count++;
            if (count == 1) {
                target = n
            }
            if (count == 2) {
                target = n % 150
            }
            if (count == 3) {
                target = n
                count = 1
            }
        

        }
        btnA = master.get_digital(DIGITAL_A); //defining variable as button press
        pros::delay(20);
    }

}