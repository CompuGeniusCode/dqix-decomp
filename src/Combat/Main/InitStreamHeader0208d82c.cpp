#include <globaldefs.h>

struct StreamHeader0208d82c {
    unsigned int w0;      /* 0x00 */
    unsigned short h4;    /* 0x04 */
    unsigned short h6;    /* 0x06 */
    unsigned int w8;      /* 0x08 */
    unsigned short hc;    /* 0x0c */
    unsigned short he;    /* 0x0e */
};

// USA: func_0208d82c
ARM void InitStreamHeader0208d82c(struct StreamHeader0208d82c* h) {
    h->w0 = 0;
    h->h6 = 0;
    h->h4 = 0;
    h->w8 = 0;
    h->hc = 0;
    h->he = 0xfff;
}
