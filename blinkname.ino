// blinkname.ino by Mitchell Burcheri - 220206872

//int led1 = D0; // Instead of writing D0 over and over again, we'll write led1
// You'll need to wire an LED to this one to see it blink.

int led2 = D7; // Instead of writing D7 over and over again, we'll write led2
// This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.

void setup() {
    //pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT); // assigns output pin to the led on particle argon
}

void loop() {
    // Morse code of "mitchell" is -- .. - -.-. .... . .-.. .-..
    letterm(); // m is --
    letteri(); // i is ..
    lettert(); // t is -
    letterc(); // c is -.-.
    letterh(); // h is ....
    lettere(); // e is .
    letterl(); // l is .-..
    letterl(); // l is .-..
    nextword(); // also know as " / "
    
}

// SIGNALS
/*
There are rules to help people distinguish dots from dashes in Morse code.
    - The length of a dot is 1 time unit.
    - A dash is 3 time units.
    - The space between symbols (dots and dashes) of the same letter is 1 time unit.
    - The space between letters is 3 time units.
    - The space between words is 7 time units.
*/
int timeunit = 300; // my time unit

void dot(){ // dot
    digitalWrite(led2, HIGH); // turn led on
    delay(timeunit); // keep led on for a time unit
    space(); // next signal
}
void dash(){ // dash
    digitalWrite(led2, HIGH); // turn led on
    delay(timeunit*3); // keep led on for 3 time units
    space(); // next signal
}
void space(){ // gap/space between signals
    digitalWrite(led2, LOW); // turn led off
    delay(timeunit); // keep led off for a time unit
}
void nextletter(){ // space needed for next letter
     // was going to use this to revisit for loops but was eaier to copy and paste space() three times
    /*int i;
    for(i=0;i<3;i++){
        int timesran = i + 1;
        space();
        //printf("This has ran " + timesran + " times for next letter");
    }*/
    
    // space between letters is 3 time units
    space();
    space();
    space();
}
void nextword(){ // space needed for next word
    // space(); // removed a space() compensate for the space() used in nextletter()
    // The space between words is 7 time units.
    space();
    space();
    space();
    space();
    space();
    space();
}

// ------

// LETTERS
void letterm(){
    // m is --
    dash();
    dash();
    
    nextletter(); // long gap for next letter works by adding another gap to the existing gap after letter is done
}
void letteri(){
    // i is ..
    dot();
    dot();
    
    nextletter();
}
void lettert(){
    // t is -
    dash();
    
    nextletter();
}
void letterc(){
    // c is -.-.
    dash();
    dot();
    dash();
    dot();
    
    nextletter();
}
void letterh(){
    // h is ....
    dot();
    dot();
    dot();
    dot();
    
    nextletter();
}
void lettere(){
    // e is .
    dot();
    
    nextletter();
}
void letterl(){
    // l is .-..
    dot();
    dash();
    dot();
    dot();
    
    nextletter();
}


