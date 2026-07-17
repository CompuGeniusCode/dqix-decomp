#include <globaldefs.h>

extern unsigned char data_ov031_0224e56c;
extern unsigned char data_ov031_0224e570[16];

#pragma optimize_for_size off

// USA: func_ov031_0220f394
ARM void RecordRingBuffer_0220f394(int input) {
    int computed = input >> 2;
    if ((input & 2) == 0) {
        computed += 0x19;
    }
    unsigned char cursor = data_ov031_0224e56c;
    data_ov031_0224e570[(int)cursor % 16] = (unsigned char)computed;
    if (cursor < 0x10) {
        data_ov031_0224e56c = cursor + 1;
        return;
    }
    data_ov031_0224e56c = (int)(cursor + 1) % 16 + 0x10;
}
