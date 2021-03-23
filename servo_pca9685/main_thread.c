#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/UART.h>
#include <ti/drivers/I2C.h>
#include "ti_drivers_config.h"
#include "servo_pca9685.h"


/*
    FINGERS:

          15
     14   |   13
   11 \   |   /
    \  \  |  /
     \  \ | / ______ 12
      (     )
      (     )
*/

void start_position() {
    PCA_ServoWrite(11, 0);
    usleep(10000);
    PCA_ServoWrite(12, 0);
    usleep(10000);
    PCA_ServoWrite(13, 0);
    usleep(10000);
    PCA_ServoWrite(14, 0);
    usleep(10000);
    PCA_ServoWrite(15, 0);
    usleep(10000);
}

void move_all_fingers(uint8_t angle) {
    PCA_ServoWrite(11, angle);
    usleep(10000);
    PCA_ServoWrite(12, angle);
    usleep(10000);
    PCA_ServoWrite(13, angle);
    usleep(10000);
    PCA_ServoWrite(14, angle);
    usleep(10000);
    PCA_ServoWrite(15, angle);
    usleep(10000);
}


void *mainThread(void *arg0) {

    char input;
    UART_Handle uart;
    UART_Params uartParams;

    GPIO_init();
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);

    UART_init();
    UART_Params_init(&uartParams);
    uart = UART_open(CONFIG_UART_0, &uartParams);
    if (uart == NULL) {
        while (1);
    }

    PCA_ServoInit();
    start_position();

    while (1) {
        UART_read(uart, &input, 1);
        UART_write(uart, &input, 1);
        if (input == 'a')
            move_all_fingers(0);
        if (input == 'b')
            move_all_fingers(18);
        if (input == 'c')
            move_all_fingers(32);
        if (input == 'd')
            move_all_fingers(50);
        if (input == 'e')
            move_all_fingers(68);
        if (input == 'f')
            move_all_fingers(86);
        if (input == 'g')
            move_all_fingers(104);
        if (input == 'h')
            move_all_fingers(122);
        if (input == 'i')
            move_all_fingers(140);
        if (input == 'j')
            move_all_fingers(158);
        if (input == 'k')
            move_all_fingers(180);
        usleep(10000);
        GPIO_toggle(CONFIG_GPIO_LED_0);
    }
}
