// Output PWM on pins 20, 21 & 19

#include "pico/stdlib.h"
#include "hardware/pwm.h"

uint LED1 = 19;
uint LED2 = 20;
uint LED3 = 21;

uint slice_num_LED1;
uint slice_num_LED2;
uint slice_num_LED3;

uint channel_LED1;
uint channel_LED2;
uint channel_LED3;

uint i = 1;
bool toggle = false;
void mainloop() {
    uint output = 0;
    
    if (i < 255) {
        i++;
    }
    else {
        i = 0;
        toggle = !toggle;
    }

    output = i*i;

    if (toggle) output = 65025-output;


    pwm_set_chan_level(slice_num_LED1, channel_LED1, output);
    pwm_set_chan_level(slice_num_LED3, channel_LED3, output);
    pwm_set_chan_level(slice_num_LED2, channel_LED2, 65025-output);
    sleep_ms(20);
}

int main() {
    // GPIO mit PWM verbinden
    gpio_set_function(LED1, GPIO_FUNC_PWM);
    gpio_set_function(LED2, GPIO_FUNC_PWM);
    gpio_set_function(LED3, GPIO_FUNC_PWM);

    // PWM Slices abspeichern 
    slice_num_LED1 = pwm_gpio_to_slice_num(LED1);
    slice_num_LED2 = pwm_gpio_to_slice_num(LED2);
    slice_num_LED3 = pwm_gpio_to_slice_num(LED3);

    // PWM Channels abspeichern
    channel_LED1 = pwm_gpio_to_channel(LED1);
    channel_LED2 = pwm_gpio_to_channel(LED2);
    channel_LED3 = pwm_gpio_to_channel(LED3);

    // 16 bit resolution
    pwm_set_wrap(slice_num_LED1, 65535);
    pwm_set_wrap(slice_num_LED2, 65535);
    pwm_set_wrap(slice_num_LED3, 65535);

    // Set everything to 0 brightness
    pwm_set_chan_level(slice_num_LED1, channel_LED1, 0);
    pwm_set_chan_level(slice_num_LED2, channel_LED2, 0);
    pwm_set_chan_level(slice_num_LED3, channel_LED3, 0);

    // Set the PWM running
    pwm_set_enabled(slice_num_LED1, true);
    pwm_set_enabled(slice_num_LED2, true);
    pwm_set_enabled(slice_num_LED3, true);

    while (1)
    {
        mainloop();
    }
    
}

