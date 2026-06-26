#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>

// const char* OHMS = "ohms";
// const char* KILOOHMS = "kiloohms";
// const char* MEGAOHMS = "megaohms";
// const char* GIGAOHMS = "gigaohms";

typedef enum{
    OHMS = 0,
    KILOOHMS = 3,
    MEGAOHMS = 6,
    GIGAOHMS = 9
}ohms_unit_t;


typedef enum{
BLACK,
BROWN,
RED,
ORANGE,
YELLOW,
GREEN,
BLUE,
VIOLET,
GREY,
WHITE    
}resistor_band_t;

typedef struct{
    uint16_t value;
    ohms_unit_t unit;
    
}resistor_value_t;

resistor_value_t color_code(resistor_band_t* trio);

#endif
