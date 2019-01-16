#include "Arduino.h"

struct DeltaTime {
public:
    static void update(unsigned long &t_delta);
    
private:
    static unsigned long lastTime;
};
