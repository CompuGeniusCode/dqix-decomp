#include <globaldefs.h>

void Crc8Update(const unsigned char* table, unsigned char* pcrc, const unsigned char* data, unsigned int len);

// USA: func_020d1ca0
ARM unsigned char Crc8Compute(const unsigned char* table, const unsigned char* data, unsigned int len) {
    unsigned char crc = 0;
    Crc8Update(table, &crc, data, len);
    return crc;
}
