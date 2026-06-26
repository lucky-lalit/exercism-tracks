#include "resistor_color_trio.h"
#include <stdio.h>
#include <math.h>

resistor_value_t color_code(resistor_band_t *trio)
{
    resistor_value_t result;
    uint64_t total_ohms = (trio[0] * 10 + trio[1]);
    
    // int zeros = (int)trio[2];
    for (int i = 0; i < (int)trio[2]; i++) {
        total_ohms *= 10;
    }
    // total_ohms *= pow(10,trio[2]);
    if (total_ohms >= 1000000000) {
        result.value = total_ohms / 1000000000;
        result.unit = GIGAOHMS;
    } 
    else if (total_ohms >= 1000000) {
        result.value = total_ohms / 1000000;
        result.unit = MEGAOHMS;
    } 
    else if (total_ohms >= 1000) {
        result.value = total_ohms / 1000;
        result.unit = KILOOHMS;
    } 
    else {
        result.value = total_ohms;
        result.unit = OHMS;
    }
    
    return result;
}




// resistor_value_t color_code(resistor_band_t *trio)
// {
    
//     resistor_value_t result;
//     result.unit = OHMS;
    
//     if (trio == NULL)
//         return result;

//     // 1. Calculate the total resistance in Ohms.
//     // We use uint64_t to safely hold up to 99 * 10^9 without overflowing.
//     uint64_t val = (trio[0] * 10 + trio[1]);
//     for (int i = 0; i < trio[2]; i++) {
//         val *= 10;
//     }

//     // 2. Determine the appropriate unit based on the total calculated value
//     if (val >= 1000000000) {
//         result.value = val / 1000000000;
//         result.unit = GIGAOHMS;
//     } 
//     else if (val >= 1000000) {
//         result.value = val / 1000000;
//         result.unit = MEGAOHMS;
//     } 
//     else if (val >= 1000) {
//         result.value = val / 1000;
//         result.unit = KILOOHMS;
//     } 
//     else {
//         result.value = val;
//         result.unit = OHMS;
//     }

//     return result;

// //     // resistor_value_t result = resistor_value_t{unit:OHMS};
// //     resistor_value_t result;
// //     result.unit = OHMS;
// //     if (trio == NULL)
// //         return result;

// // // int val_sum = (trio[0] * 10 + trio[1]) * pow(10,trio[2]);
// // //     if (val_sum % 1000000000 == 0)
        

    
// //     printf("%i first color \n",trio[0]);
// //     printf("%i second color \n",trio[1]);
// //     printf("%i third color \n",trio[2]);
// //     int val_sum = (trio[0] * 10 + trio[1]);
// //     printf("debug0 %i\n",val_sum);
// //     result.value = val_sum; 
// //     if (trio[2] < 3)
// //     {
// //         printf("debug 1\n");
// //         val_sum *= pow(10,trio[2]);
// //         printf("ohm condition");
// //         printf("debug vsl_sum after add %i\n",val_sum);
// //         result.value = val_sum;
// //         result.unit = OHMS;
// //     }
// //     else if (trio[2] < 6 )
// //     {
// //         printf("debug kilo condition\n");
// //         val_sum *= pow(10,trio[2]-3);
// //         result.value = val_sum;
// //         result.unit = KILOOHMS;
// //     }
// //     else if (trio[2] < 9 )
// //     {
// //         printf("debug mega condition\n");
// //         val_sum *= pow(10,trio[2]-6);
// //         result.value = val_sum;
// //         result.unit = MEGAOHMS;
// //     }
// //     else if (trio[2] >= 9 )
// //     {
// //         printf("debug giga condition\n");
// //         val_sum *= pow(10,trio[2]-9);
// //         result.value = val_sum;
// //         result.unit = GIGAOHMS;
// //     }
// //     printf("debug 2 %d\n",result.unit);
// //     printf("debug 3 %d\n",result.value);
// //     return result;
// }