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

   // Particle.function allows control from the cloud.
   Particle.function("select",toggle);
   // When we ask the cloud for the function "select", it will employ the function Toggle() from this app.

   // Initializing relay to OFF for all 4 ouputs, (The way it is wired requires a HIGH signal to be in OFF state)
    digitalWrite(out1, HIGH);
    digitalWrite(out2, HIGH);
    digitalWrite(out3, HIGH);
    digitalWrite(out4, HIGH);
}

void loop()
{
   // Nothing to do here
}

// Function toggle gets called when a matching API request is sent


int toggle(String command) {
    //Particle.functions always take a string as an argument and return an integer


//FSM depending on input command, structure needs to be changed to switch case
    if (command == "1ON") {
        digitalWrite(out1,LOW);
        return 1;
    }

    else if (command == "1OFF") {
        digitalWrite(out1,HIGH);
        return 0;

    else if (command == "2ON") {
        digitalWrite(out2,LOW);
        return 1;
    }

    else if (command == "2OFF") {
        digitalWrite(out2,HIGH);
        return 0;
    }

    else if (command == "3ON") {
        digitalWrite(out3,LOW);
        return 1;
    }

    else if (command == "3OFF") {
        digitalWrite(out3,HIGH);
        return 0;
    }

    else if (command == "4ON") {
        digitalWrite(out4,LOW);
        return 1;
    }

    else if (command == "4OFF") {
        digitalWrite(out4,HIGH);
        return 0;
    }

//"default" case, if input command is unknown return error flag (-1)
    else {
        return -1;
    }

}
