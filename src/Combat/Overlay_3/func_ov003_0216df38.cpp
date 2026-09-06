#include <globaldefs.h>

extern "C" void* __clear(void* buf, int len);

struct Container020e0310;
extern int GetFieldByKey020e0434(struct Container020e0310* c, int key);

extern "C" int func_020420e8(void* p, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern int AppendString02042058(char* dst, const char* src);

extern const char data_ov003_02180208;
extern const char data_ov003_02180215;

// USA: func_ov003_0216df38
extern "C" ARM short func_ov003_0216df38(char* dst, struct Container020e0310* c, int flag) {
    char buf[0x80];
    __clear(buf, 0x80);

    int w1;
    int key1 = 5;
    int f1, f2;
    if (flag) key1 = 6;
    f1 = GetFieldByKey020e0434(c, key1);
    f2 = GetFieldByKey020e0434(c, 7);

    w1 = func_020420e8((void*)f1, 0);
    int w2 = func_020420e8((void*)f2, 0);
    if (w1 < w2) w1 = w2;

    sprintf(buf, &data_ov003_02180208, f1);
    AppendString02042058(dst, buf);

    sprintf(buf, &data_ov003_02180215, f2);
    AppendString02042058(dst, buf);

    int f3 = GetFieldByKey020e0434(c, 0xe);
    sprintf(buf, (const char*)f3);
    AppendString02042058(dst, buf);

    int rounded = (w1 + 0x1b) & ~7;
    int half = rounded >> 3;
    return (short)(half + (half & 1));
}
