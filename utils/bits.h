#ifndef CMISC_UTILS_BITS
#define CMISC_UTILS_BITS

#include <stdint.h>

int bits_uint8_read_bit(uint8_t input, int bit);
uint8_t bits_uint8_read_bits(uint8_t input, int msbit, int lsbit); // full range = [7..0]
int bits_uint16_read_bit(uint16_t input, int bit);
uint16_t bits_uint16_read_bits(uint16_t input, int msbit, int lsbit); // full range = [15..0]
int bits_uint32_read_bit(uint32_t input, int bit);
uint32_t bits_uint32_read_bits(uint32_t input, int msbit, int lsbit); // full range = [31..0]

#endif // CMISC_UTILS_BITS