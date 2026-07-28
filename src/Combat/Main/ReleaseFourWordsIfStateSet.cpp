#include <globaldefs.h>

struct RefNode020c80f8;
int ReleaseNodeRef020c80f8(struct RefNode020c80f8*);

struct GlobalState0214e4a8 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
};
extern GlobalState0214e4a8 data_0214e4a8;

struct FourWords;
extern struct FourWords data_0214e4b0;

// USA: func_020d974c  (semantic: ReleaseFourWordsIfStateSet)
extern "C" ARM void func_020d974c(void) {
    if (data_0214e4a8.byte2 && data_0214e4a8.byte1) {
        data_0214e4a8.field4 -= 1;
        ReleaseNodeRef020c80f8((struct RefNode020c80f8*)&data_0214e4b0);
    }
}
