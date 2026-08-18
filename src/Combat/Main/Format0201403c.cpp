#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "std_library_functions.h"

int IsInRange0201b5b0(int id);
int IsValueInRange0201b5d8(int x);

extern char data_020ef106;
extern char data_020ef116;
extern char data_020ef11f;
extern char data_020ef12f;

// USA: func_0201403c  (semantic: Format0201403c)
extern "C" ARM void func_0201403c(void* obj) {
    char* o = (char*)obj;
    int handle = (int)BackgroundLoader::GetInstance();
    char buf[0x14];

    if (IsInRange0201b5b0(*(unsigned short*)o)) {
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)(o + 0x23ec);
        int env = grotto->GetActiveGrottoEnviron();
        if (env == 0) env = 1;
        if (env > 5) env = 5;
        sprintf(buf, &data_020ef106, &data_020ef116, env);
    } else if (IsValueInRange0201b5d8(*(unsigned short*)o)) {
        ActiveGrottoClass* grotto = (ActiveGrottoClass*)(o + 0x23ec);
        int env = grotto->GetActiveGrottoEnviron();
        sprintf(buf, &data_020ef11f, &data_020ef116, env);
    } else {
        sprintf(buf, &data_020ef12f, &data_020ef116, *(int*)(o + 8) + 5);
    }

    *(int*)(o + 0x438) = ((BackgroundLoader*)(handle))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
}
