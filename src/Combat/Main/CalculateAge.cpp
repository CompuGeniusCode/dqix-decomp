#include <globaldefs.h>

extern "C" void func_020cf0fc(void* dateOut);

struct Date02098f20 { int year; int month; int day; int pad; };

// USA: func_02098f20
ARM int CalculateAge(int birthYear, int birthMonth, int birthDay) {
    struct Date02098f20 now;
    int age;
    func_020cf0fc(&now);
    now.year += 0x7d0;
    age = now.year - birthYear;
    if (birthMonth * 100 + birthDay > now.month * 100 + now.day) age -= 1;
    return age;
}
