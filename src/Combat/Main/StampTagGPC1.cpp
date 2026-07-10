#include <globaldefs.h>

struct FourSignedBytes020d9654 { signed char a, b, c, d; };
void CopyFourSignedBytes020d9654(struct FourSignedBytes020d9654* dst, struct FourSignedBytes020d9654* src);
extern struct FourSignedBytes020d9654 data_020f27f0;

// USA: func_020d9678
ARM struct FourSignedBytes020d9654* StampTagGPC1(struct FourSignedBytes020d9654* obj) {
    CopyFourSignedBytes020d9654(obj, &data_020f27f0);
    return obj;
}
