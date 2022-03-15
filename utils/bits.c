#include "bits.h"

int bits_uint8_read_bit(uint8_t input, int bit)
{
    return (input >> bit) & 1;
}

uint8_t bits_uint8_read_bits(uint8_t input, int msbit, int lsbit)
{
    return (input << (7 - msbit)) >> (7 - msbit + lsbit);
}

int bits_uint16_read_bit(uint16_t input, int bit)
{
    return (input >> bit) & 1;
}

uint16_t bits_uint16_read_bits(uint16_t input, int msbit, int lsbit)
{
    return (input << (15 - msbit)) >> (15 - msbit + lsbit);
}


int bits_uint32_read_bit(uint32_t input, int bit)
{
    return (input >> bit) & 1;
}

uint32_t bits_uint32_read_bits(uint32_t input, int msbit, int lsbit)
{
   
    return (input << (31 - msbit)) >> (31 - msbit + lsbit);
}
