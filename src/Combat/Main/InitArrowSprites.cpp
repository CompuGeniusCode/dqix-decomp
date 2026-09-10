#include <globaldefs.h>
#include "std_library_functions.h"

struct SpriteObject;
extern "C" void func_0204719c(struct SpriteObject* obj);
extern "C" void LoadAniSprFile(struct SpriteObject* obj, char* name, int flag);

extern char strArrowNumSpr[];

// Builds the four arrow sprites from data/ani/arrow0.spr through arrow3.spr - the ROM holds
// exactly those four - into the 0x88-byte sprite objects that start the caller's structure,
// then zeroes the bytes that follow them from 0x220 to 0x230. LoadAniSprFile rejects any name
// whose last character is not a lower-case 'r' and loads the rest as /data/ani/<name>; in
// data/ani only the .spr files pass that test.
// The one caller is func_ov017_0219b624, which in the same pass pulls wing1-3.spr,
// ev_icon0.spr and field_bat.spr out of data/bin/icon.nsarc. What the arrows point at, and
// whether these four belong with that group, is not established.
extern "C" ARM void InitArrowSprites(char* arrowSet, int flag) {
    int arrowIndex;
    char spriteName[0x40];
    for (arrowIndex = 0; arrowIndex < 4; arrowIndex++) {
        sprintf(spriteName, strArrowNumSpr, arrowIndex);
        func_0204719c((struct SpriteObject*)(arrowSet + arrowIndex * 0x88));
        LoadAniSprFile((struct SpriteObject*)(arrowSet + arrowIndex * 0x88), spriteName, flag);
    }
    *(unsigned char*)(arrowSet + 0x220) = 0;
    *(unsigned char*)(arrowSet + 0x221) = 0;
    *(unsigned char*)(arrowSet + 0x222) = 0;
    *(unsigned char*)(arrowSet + 0x223) = 0;
    *(unsigned char*)(arrowSet + 0x224) = 0;
    *(unsigned char*)(arrowSet + 0x225) = 0;
    *(unsigned short*)(arrowSet + 0x228) = 0;
    *(unsigned short*)(arrowSet + 0x22a) = 0;
    *(unsigned short*)(arrowSet + 0x22c) = 0;
    *(unsigned char*)(arrowSet + 0x230) = 0;
    *(unsigned char*)(arrowSet + 0x226) = 0;
}
