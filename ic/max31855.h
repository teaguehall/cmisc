#ifndef CMISC_IC_MAX31855
#define CMISC_IC_MAX31855

#include <stdint.h>
#include <stddef.h>

int max31855_read_temp(uint32_t raw_word, float* ptemp);
int max31855_read_internal(uint32_t raw_word, float* ptemp);
void max31855_get_fault(int error_code, char* error_msg, size_t buffer_size);

#endif // CMISC_IC_MAX31855