#include <globaldefs.h>

#pragma define_section initcode ".init" RX

void CopyGPCSignature(unsigned int* dst, unsigned int* src);
unsigned int* SetGPCSignatureGPC0(unsigned int* dst);
unsigned int* SetGPCSignatureGPC1(unsigned int* dst);
unsigned int* SetGPCSignatureGPC2(unsigned int* dst);

struct GPCImplementationData020e6710 {
    const char* pRevisionNumberString;
    const char* pRevisionString;
};
extern GPCImplementationData020e6710 data_020f27c0;
extern unsigned int data_020f27c8;
extern unsigned int data_020f27cc;
extern unsigned int data_020f27d0;

// USA: func_020e6710  (semantic: UpdateGPCSignatures020e6710)
extern "C" __declspec(initcode) ARM void func_020e6710(void) {
    data_020f27c0.pRevisionNumberString = data_020f27c0.pRevisionString + 0xb;
    unsigned int buf3;
    SetGPCSignatureGPC0(&buf3);
    CopyGPCSignature(&data_020f27c8, &buf3);
    unsigned int buf2;
    SetGPCSignatureGPC1(&buf2);
    CopyGPCSignature(&data_020f27cc, &buf2);
    unsigned int buf1;
    SetGPCSignatureGPC2(&buf1);
    CopyGPCSignature(&data_020f27d0, &buf1);
}
