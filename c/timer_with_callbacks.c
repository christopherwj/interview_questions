#include "ecl_timer.h"

int count1 = 0;
void callback1(){  
  ++count1;
}

int count2 = 0;
void callback2(){  
  ++count2;
}

int count3 = 0;
void callback3(){  
  ++count3;
}

#define NTIMERS 3struct ecl_timer_config[NTIMERS];
//***************************************************************************// The main loop.//********************************************
int main(){  
  ecl_timer_init(timers, NTIMERS);
  ecl_timer_id_t id1 = ecl_timer_register(callback1, 1000,ECL_TIMER_SINGLE_SHOT);
  ecl_timer_id_t id2 = ecl_timer_register(callback2, 100,ECL_TIMER_REPEATING);
  ecl_timer_id_t id3 = ecl_timer_register(callback3, 10,ECL_TIMER_REPEATING);
  ecl_timer_start(id1, ECL_TIMER_START_DELAYED);  
  ecl_timer_start(id2, ECL_TIMER_START_DELAYED);  
  ecl_timer_start(id3, ECL_TIMER_START_DELAYED);
  ecl_timer_enable(ECL_TIMER_ENABLED);
  // Start timer interrupts here.
  while (1){}    
    // Loop forever.  
  return 0;
}
//***************************************************************************// The interrupt timer callback.//****************************
void timer_interrupt(void){  
  const uint32_t TICK = 1;  
  static uint32_t nticks = TICK;
  if (ecl_timer_tick(nticks)){
    nticks = TICK;
  }
  else{    
    nticks += TICK;  
  }
}
