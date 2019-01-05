// -----------------------------------
// Controlling Powerbar over the Internet
// -----------------------------------

// Initializing PINs

int out1 = D1;
int out2 = D2;
int out3 = D3;
int out4 = D4;

void setup()
{

   // pin configuration
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(out3, OUTPUT);
    pinMode(out4, OUTPUT);

   // Particle.function so that we can turn the LED on and off from the cloud.
   Particle.function("select",outToggle);

   // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

   // For good measure, let's also make sure both LEDs are off when we start:
    digitalWrite(out1, HIGH);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, HIGH);
    digitalWrite(out4, HIGH);

}

void loop()
{
   // Nothing to do here
}

// We're going to have a super cool function now that gets called when a matching API request is sent
// This is the ledToggle function we registered to the "led" Particle.function earlier.


int outToggle(String command) {
    /* Particle.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will turn the LED on and telling it "off" will turn the LED off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 for the LEDs turning on, 0 for the LEDs turning off,
    and -1 if we received a totally bogus command that didn't do anything to the LEDs.
    */


    if (command == "1ON") {
        digitalWrite(out1,LOW);
        return 1;
    }

    if (command == "1OFF") {
        digitalWrite(out1,HIGH);
        return 0;




    if (command == "2ON") {
        digitalWrite(out2,LOW);
        return 1;
    }

    if (command == "2OFF") {
        digitalWrite(out2,HIGH);
        return 0;
    }




    if (command == "3ON") {
        digitalWrite(out3,LOW);
        return 1;
    }

    if (command == "3OFF") {
        digitalWrite(out3,HIGH);
        return 0;
    }




    if (command == "4ON") {
        digitalWrite(out4,LOW);
        return 1;
    }

    if (command == "4OFF") {
        digitalWrite(out4,HIGH);
        return 0;
    }



    else {
        return -1;
    }

}

    /*if (command=="on") {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        return 0;
    }
    else {
        return -1;
    }
    */
