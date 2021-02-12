#include "hc_sr04.h"
#include "sdk_wrapper.h"

void hc_sr04_init()
{
    GPIO_INIT_W_DIR(TRIG, _GPIO_OUT);
    GPIO_INIT_W_DIR(ECHO, _GPIO_IN);
}

void hc_sr04_wait_trig()
{
    GPIO_PUT(TRIG, 0);
    sleep_ms(3000);
}

int hc_sr04_echo_us()
{
    int startTime = 0;
    int endTime = 0;

    if (BLINK_ON_ECHO)
    {
        GPIO_PUT(LED, 1);
        sleep_ms(250);
        GPIO_PUT(LED, 0);
    }

    GPIO_PUT(TRIG, 1);
    sleep_us(10);
    GPIO_PUT(TRIG, 0);

    while (GPIO_GET(ECHO) == 0)
    {
        startTime = to_us_since_boot(get_absolute_time());
    }

    while (GPIO_GET(ECHO) > 0)
    {
        endTime = to_us_since_boot(get_absolute_time());
    }
    return endTime - startTime;
}

float hc_sr04_echo_ms()
{
    int dif = hc_sr04_echo_us();
    return ((float)dif) / 1000;
}

float echo_us_to_distance(int echo_us)
{
    return ((((float)echo_us) / 1000000) * 17150.0);
}