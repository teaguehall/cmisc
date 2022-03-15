#include "max31855.h"
#include "../utils/bits.h"
#include <string.h>

#define DEGS_PER_BIT                0.25

#define MAX31855_BIT_FAULT_OC       0
#define MAX31855_BIT_FAULT_SCG      1
#define MAX31855_BIT_FAULT_SCV      2
#define MAX31855_BIT_INTERNAL_LSB   4
#define MAX31855_BIT_INTERNAL_MSB   15
#define MAX31855_BIT_FAULT          16
#define MAX31855_BIT_TEMP_LSB       18
#define MAX31855_BIT_TEMP_MSB       31 

int max31855_read_temp(uint32_t raw_word, float* ptemp)
{
    // check for fault
    if(bits_uint32_read_bit(raw_word, MAX31855_BIT_FAULT))
        return 1;

    // read temperature
    *ptemp = DEGS_PER_BIT * bits_uint32_read_bits(raw_word, MAX31855_BIT_TEMP_MSB, MAX31855_BIT_TEMP_LSB); 
    
    // success
    return 0;
}

int max31855_read_internal(uint32_t raw_word, float* ptemp)
{
    // check for fault
    if(bits_uint32_read_bit(raw_word, MAX31855_BIT_FAULT))
        return 1;

    // read temperature
    *ptemp = DEGS_PER_BIT * bits_uint32_read_bits(raw_word, MAX31855_BIT_INTERNAL_MSB, MAX31855_BIT_INTERNAL_LSB); 
    
    // success
    return 0;
}

void max31855_get_fault(uint32_t raw_word, char* error_msg, size_t buffer_size)
{
    // open circuit fault
    if(bits_uint32_read_bit(raw_word, MAX31855_BIT_FAULT_OC))
    {
        strncpy(error_msg, "Thermocouple is open-circuited", buffer_size);
        return;
    }
    
    
    switch(error_code)
    {
        case 0:
            strncpy(error_msg, "No error", buffer_size);
            break;
        case 1:
            strncpy(error_msg, "Thermocouple short-circuits to Vcc", buffer_size);
            break;
        case 2:
            strncpy(error_msg, "Thermocouple short-circuits to GND", buffer_size);
            break;
        case 3:
            strncpy(error_msg, "Thermocouple is open-circuited", buffer_size);
            break;
        default:
            strncpy(error_msg, "Unrecognized error code", buffer_size);
            break;
    }

    error_msg[buffer_size - 1] = 0; // ensure null terminated
}