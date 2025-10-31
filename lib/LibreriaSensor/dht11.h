#ifndef dht11_h_
#define dht11_h_
#include "stm32f103xb.h"
#include <stdint.h>
#define dht11_t
int sensor=1;
bool dht11_read(dht11_t* sensor);
void dht11_init(dht11_t* sensor);
typedef struct {
    // Configuración
    GPIO_TypeDef* port;       
    uint16_t      pin_num;    
    
    // Datos
    float         temperature;
    float         humidity;
} dht11_t;

#endif