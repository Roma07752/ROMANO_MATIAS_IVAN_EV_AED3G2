#include "dht11.h"

void dht11_init(dht11_t* sensor) {
    // Habilita el reloj del puerto correspondiente
    if (sensor->port == GPIOA) RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    if (sensor->port == GPIOB) RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    if (sensor->port == GPIOC) RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

    // Configura pin como entrada flotante
    if (sensor->pin_num < 8) {
        sensor->port->CRL &= ~(0xF << (sensor->pin_num * 4));
        sensor->port->CRL |=  (0x4 << (sensor->pin_num * 4));
    } else {
        uint8_t pin = sensor->pin_num - 8;
        sensor->port->CRH &= ~(0xF << (pin * 4));
        sensor->port->CRH |=  (0x4 << (pin * 4));
    }
}

bool dht11_read(dht11_t* sensor) {
    
}
