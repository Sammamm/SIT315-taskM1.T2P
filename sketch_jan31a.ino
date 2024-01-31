int led_pin=13;
int motion_pin=2;

void setup() {
    pinMode(led_pin, OUTPUT);
    pinMode(motion_pin, INPUT);
    Serial.begin(9600);

    attachInterrupt(digitalPinToInterrupt(motion_pin), toggle, CHANGE);
}

int motion_value;

void loop(){
}

void toggle() {
    motion_value=digitalRead(motion_pin);

    if(motion_value==true) {
        Serial.println("Motion");
        digitalWrite(led_pin, true);
        delay(5000);
    }

    else if(motion_value==false) {
        Serial.println("No Motion");
        digitalWrite(led_pin, false);
    }
}