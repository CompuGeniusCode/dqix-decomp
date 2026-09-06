#include <globaldefs.h>

void InsertShortIntoTable021098f4(unsigned short);

// USA: func_0206ece8
ARM void ClearNibble0206ece8(int unused, int idx, unsigned char* arr, unsigned int limit) {
    int rem = idx % 2;
    int q = idx / 2;
    if (limit <= q) {
        InsertShortIntoTable021098f4(0x3e7);
        return;
    }
    {
        unsigned char b = arr[q];
        if (rem != 0) {
            arr[q] = b & 0xf0;
        } else {
            arr[q] = b & 0xf;
        }
    }
}
