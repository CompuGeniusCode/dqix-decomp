#include <globaldefs.h>

void Crc16Update(const unsigned short* table, unsigned short* pcrc, const unsigned char* data, unsigned int len);

// USA: func_020d1cc8
ARM unsigned short Crc16Compute(const unsigned short* table, const unsigned char* data, unsigned int len) {
    unsigned short crc = 0;
    Crc16Update(table, &crc, data, len);
    return crc;
}
