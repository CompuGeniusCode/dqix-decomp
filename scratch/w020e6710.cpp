#include <globaldefs.h>

unsigned int* SetGPCSignatureGPC0(unsigned int* dst);
unsigned int* SetGPCSignatureGPC1(unsigned int* dst);
unsigned int* SetGPCSignatureGPC2(unsigned int* dst);
void CopyGPCSignature(unsigned int* dst, unsigned int* src);

struct GPCImplementationData020e6710 {
    const char* pRevisionNumberString;
    const char* pRevisionString;
};
extern GPCImplementationData020e6710 data_020f27c0;
extern unsigned int data_020f27c8;
extern unsigned int data_020f27cc;
extern unsigned int data_020f27d0;

// USA: func_020e6710
ARM void InitGPCSignatures020e6710(void) {
    unsigned int buf0, buf1, buf2;
    data_020f27c0.pRevisionNumberString = data_020f27c0.pRevisionString + 0xb;
    SetGPCSignatureGPC0(&buf0);
    CopyGPCSignature(&data_020f27c8, &buf0);
    SetGPCSignatureGPC1(&buf1);
    CopyGPCSignature(&data_020f27cc, &buf1);
    SetGPCSignatureGPC2(&buf2);
    CopyGPCSignature(&data_020f27d0, &buf2);
}
