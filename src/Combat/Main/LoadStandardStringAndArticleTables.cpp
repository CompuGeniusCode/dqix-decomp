#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};
extern "C" void func_020dfc40(Struct020dfc40* p);

struct Slot020e5114 {
    Struct020dfc40 inner;
    unsigned char pad2[4];
};

extern Slot020e5114 data_02153694[2];
extern SafeAllocator data_02153680;

extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);

extern char strDataPrmArticleGp2;
extern char strArticleLgNat;
extern char strDataBinStrstdGp2;
extern char strStrstdLgNat;

// Resets the allocator these tables live in and reloads both localized text tables:
// strstd_<LG>.nat from data/bin/strstd.gp2 into slot 0, article_<LG>.nat from
// data/prm/article.gp2 into slot 1. article.gp2 is not prose - the German member holds measure
// words like "Haufen", "Flasche" and "Handvoll" - so slot 1 seems to be the grammar an item-name
// builder would need, though no reader of slot 1 has been found. The BackgroundLoader lock is held
// while its allocations are dropped, since both slots are rebuilt from scratch.
extern "C" ARM int LoadStandardStringAndArticleTables(void) {
    data_02153680.Reset();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    for (int i = 0; i < 2; i++) {
        Slot020e5114* slot = &data_02153694[i];
        func_020dfc40(&slot->inner);
        unsigned int size;
        void* fileData;
        if (i != 0) {
            fileData = ExtractFileFromGP2((const char*)&strDataPrmArticleGp2, (const char*)&strArticleLgNat, &size);
        } else {
            fileData = ExtractFileFromGP2((const char*)&strDataBinStrstdGp2, (const char*)&strStrstdLgNat, &size);
        }
        if (fileData != NULL) {
            func_020dfec0(slot, &data_02153680, fileData, size);
        }
    }
    BackgroundLoader::RemoveLockGlobal();
    return 0;
}
