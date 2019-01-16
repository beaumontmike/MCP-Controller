#include "DeltaTime.h"

unsigned long lastTime;

void DeltaTime::update(unsigned long &t_delta) {
    unsigned long current = millis();
    if(lastTime < current && lastTime > 0) {
        t_delta = current - lastTime;
        lastTime = current;
    } else {
        lastTime = current;
        return;
    }
}
