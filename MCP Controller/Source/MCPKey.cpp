#include "MCPKey.h"

bool MCPKey::isPressed(unsigned long t_delta) {
	if(digitalRead(this->m_switch_pin) == LOW) {
		this->m_elapsed_time_since_pressed += t_delta;
	} else {
		this->m_elapsed_time_since_pressed = 0;
	}

	if(this->m_elapsed_time_since_pressed >= 250) {
		return true;
	}

	return false;
}

bool MCPKey::isReleased(unsigned long t_delta) {
	if(digitalRead(this->m_switch_pin) == HIGH) {
		this->m_elapsed_time_since_released += t_delta;
	} else {
		this->m_elapsed_time_since_released = 0;
	}

	if(this->m_elapsed_time_since_released >= 250) {
		return true;
	}

	return false;
}

void MCPKey::setLedOn(bool t_value) {
	this->m_led_on = t_value;
}

MCPKey::MCPKey(uint8_t t_switch_pin, uint8_t t_led_pin, uint8_t t_pin_mode, const char* t_serial_message) {
	this->m_switch_pin = t_switch_pin;
	this->m_led_pin = t_led_pin;
	this->m_pin_mode = t_pin_mode;
    this->m_message = t_serial_message;
    this->m_elapsed_time_since_pressed = 0;
    this->m_elapsed_time_since_released = 0;
    this->m_long_press = false;
    this->m_led_on = false;
    this->m_time_since_last_led_update = 0;
    
    this->on_command = this->m_message + "_ON";
    this->off_command = this->m_message + "_OFF";

	pinMode(this->m_switch_pin, this->m_pin_mode);
	pinMode(this->m_led_pin, OUTPUT);
}

void MCPKey::update(unsigned long t_delta) {
	if(this->isPressed(t_delta) && !this->m_long_press) {
		this->m_long_press = true;
		while(!Serial.availableForWrite());
		Serial.println((this->m_message + "_PRESS").c_str());
		Serial.flush();
	}

	if(this->isReleased(t_delta)) {
		this->m_long_press = false;
	}

	this->m_time_since_last_led_update += t_delta;
	if(this->m_time_since_last_led_update > 250) {
		digitalWrite(this->m_led_pin, this->m_led_on ? HIGH : LOW);
		this->m_time_since_last_led_update = 0;
	}
}
