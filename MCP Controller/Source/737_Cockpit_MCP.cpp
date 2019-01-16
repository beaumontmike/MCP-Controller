
#define UBRRH

#include "Arduino.h"
#include "Stream.h"
#include "DeltaTime.h"
#include "MCPDefs.h"
#include "MCPKey.h"
#include "HardwareSerial.h"

unsigned long g_delta;

template<size_t N, class U>
size_t array_len(U (&arr)[N])
{
    return N;
}

void updateMCP(unsigned long t_delta) {
	// Loop through MCPKeys and update.
	for(int inx = 0; inx < array_len(Keys); ++inx) {
			Keys[inx]->update(t_delta);
		}
}

void parseCommand(String t_message) {
	t_message.trim();
	t_message.toUpperCase();
    
	if(t_message == "") return;

	if(t_message == DEVICE_NAME_QUERY) {
		while(!Serial.availableForWrite());
		Serial.println(DEVICE_NAME);
	} else {

	// Loop through MCPKeys, update activeState and break loop if found.
	for(int inx = 0; inx < array_len(Keys); ++inx) {
			if(t_message == Keys[inx]->on_command) {
				Keys[inx]->setLedOn(true);
				break;
			}
			if(t_message == Keys[inx]->off_command) {
				Keys[inx]->setLedOn(false);
				break;
			}
		}
	}

	// Echo command for debugging.
	while(!Serial.availableForWrite());
	Serial.println("DEBUG :" + t_message);

}

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(SERIAL_BAUD);
	Serial.setTimeout(100);
	delay(1000);
}


// the loop function runs over and over again until power down or reset
void loop() {
    DeltaTime::update(g_delta);
	if(Serial.available() > 0) {
		parseCommand(Serial.readString());
	}
	updateMCP(g_delta);
}



