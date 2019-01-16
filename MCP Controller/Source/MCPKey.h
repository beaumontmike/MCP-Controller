
#ifndef MCPKEY_H_
#define MCPKEY_H_
#define UBRRH

#include "Arduino.h"

struct MCPKey {

public:
	MCPKey(uint8_t, uint8_t, uint8_t, const char*);
	void update(unsigned long);
	void setLedOn(bool);
    
    String              off_command;
    String              on_command;
    
private:
    uint8_t             m_switch_pin;
    uint8_t             m_led_pin;
    uint8_t             m_pin_mode;
    unsigned long       m_elapsed_time_since_pressed;
    unsigned long       m_elapsed_time_since_released;
    unsigned long       m_time_since_last_led_update;
    bool                m_long_press = false;
    String              m_message;
    bool                m_led_on;
    
    
    bool isPressed(unsigned long delta);
    bool isReleased(unsigned long delta);
    

};

#endif
