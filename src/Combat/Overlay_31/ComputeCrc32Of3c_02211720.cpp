#include <globaldefs.h>

void GenCrc32Table(unsigned int* table, unsigned int poly);
unsigned int Crc32Compute(const unsigned int* table, const unsigned char* data, unsigned int len);

// USA: func_ov031_02211720
ARM unsigned int ComputeCrc32Of3c_02211720(const unsigned char* data) {
	unsigned int table[0x100];
	GenCrc32Table(table, 0xedb88320);
	return Crc32Compute(table, data, 0x3c);
}
