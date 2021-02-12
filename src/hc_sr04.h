
#define TRIG 11
#define ECHO 10

#define LED 25

#define BLINK_ON_ECHO true

void hc_sr04_init();
void hc_sr04_wait_trig();
int hc_sr04_echo_us();
float hc_sr04_echo_ms();
float echo_us_to_distance(int echo_us);