#include <globaldefs.h>

struct Row0202ad4c { unsigned short cells[32]; };
extern struct Row0202ad4c data_020fe9cc[];

// USA: func_0202ad4c
extern "C" ARM void PackTextRow0202ad4c(int col, int row, unsigned int colorNibble, const char* str) {
    unsigned short* base = data_020fe9cc[row].cells;
    colorNibble = colorNibble << 28;
    while (*str != 0) {
        unsigned short ch = (unsigned short)*str;
        base[col] = ch | (colorNibble >> 16);
        col++;
        if (col >= 0x100) return;
        str++;
    }
}
