#include <globaldefs.h>

void SetData02249b54_022167a8(int v);
extern int data_ov031_02249a14;
extern int data_ov031_02249a3c;
extern int data_ov031_02249a60;

// USA: func_ov031_02211c50
ARM void SetDataFromIndex_02211c50(int idx) {
	switch (idx) {
		case 0: SetData02249b54_022167a8((int)&data_ov031_02249a14); break;
		case 1: SetData02249b54_022167a8((int)&data_ov031_02249a3c); break;
		case 2: SetData02249b54_022167a8((int)&data_ov031_02249a60); break;
	}
}
