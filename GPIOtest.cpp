#include "GPIOClass.h"

using namespace std;

int main (void)
{

    string inputstate;
    int i = 0;
    GPIOClass* gpio1 = new GPIOClass("6");
    GPIOClass* gpio2 = new GPIOClass("13");
    GPIOClass* gpio3 = new GPIOClass("19");
    GPIOClass* gpio4 = new GPIOClass("26");

    GPIOClass* led_green = new GPIOClass("20");
    GPIOClass* led_red = new GPIOClass("21");

    GPIOClass* beep = new GPIOClass("16");

    GPIOClass* hold_input = new GPIOClass("12");
    cout << " GPIO pins exported" << endl;

    led_green->setdir_gpio("out");
    led_red->setdir_gpio("out");
    beep->setdir_gpio("out");

    hold_input->setdir_gpio("in");
    gpio1->setdir_gpio("in");
    gpio2->setdir_gpio("in");
    gpio3->setdir_gpio("in");
    gpio4->setdir_gpio("in");

    cout << "GPIO pin directions set" << endl;

    while(i < 10)
    {
        usleep(500000);  // wait for 0.5 seconds
        gpio1->getval_gpio(inputstate); //read state of GPIO1 input pin
        cout <<"GPIO" << gpio1->get_gpionum() << " Value : " << inputstate  <<endl;
        gpio2->getval_gpio(inputstate); //read state of GPIO2 input pin
        cout <<"GPIO" << gpio2->get_gpionum() << " Value : " << inputstate  <<endl;
        gpio3->getval_gpio(inputstate); //read state of GPIO3 input pin
        cout <<"GPIO" << gpio3->get_gpionum() << " Value : " << inputstate  <<endl;
        gpio4->getval_gpio(inputstate); //read state of GPIO4 input pin
        cout <<"GPIO" << gpio4->get_gpionum() << " Value : " << inputstate  <<endl;

        hold_input->getval_gpio(inputstate); //read state of GPIO4 input pin
        int tries = 0;
        while(tries < 200){
          tries++;
          cout << inputstate;
          hold_input->getval_gpio(inputstate); //read state of GPIO4 input pin
        }
        hold_input->setdir_gpio("out");
        hold_input->setval_gpio("1");

        led_green->setval_gpio("1");
        usleep(500000);  // wait for 0.5 seconds
        led_green->setval_gpio("0");

        led_red->setval_gpio("1");
        usleep(500000);  // wait for 0.5 seconds
        // beep->setval_gpio("1");
        // usleep(500000);  // wait for 0.5 seconds
        // beep->setval_gpio("0");

    }
    cout << "Exiting....." << endl;

    return 0;
}
