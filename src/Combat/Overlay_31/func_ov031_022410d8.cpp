#include <globaldefs.h>

struct TextBuffer_022410d8 { int length; };

extern "C" int func_ov031_022404e8(TextBuffer_022410d8* buf, int start, int end, int* outColon);
extern "C" int func_ov031_022405b8(TextBuffer_022410d8* buf, int start, int end);
extern "C" int func_ov031_02240628(TextBuffer_022410d8* buf, int start, int end, const char* name, int flags);

// USA: func_ov031_022410d8
#pragma optimize_for_size off
extern "C" ARM int func_ov031_022410d8(TextBuffer_022410d8* buf, const char* name, int* outStart) {
	int colon;
	int lineStart = func_ov031_022404e8(buf, 0xc, buf->length, &colon);
	if (lineStart <= 0) {
		goto fail;
	}
	{
		int next;
		do {
			next = func_ov031_022404e8(buf, lineStart, buf->length, &colon);
			if (colon > 0 && func_ov031_02240628(buf, lineStart, colon, name, 0) == 0) {
				if (colon + 1 < buf->length) {
					// volatile read: the ROM reloads the length here instead of reusing the
					// register from the bounds check above.
					int lineEnd = func_ov031_022404e8(buf, colon + 1, *(volatile int*)buf, 0);
					int valueEnd;
					if (lineEnd <= 0) {
						valueEnd = buf->length;
					} else {
						if (lineEnd < 2) {
							return -1;
						}
						valueEnd = lineEnd - 2;
					}
					int valueStart = func_ov031_022405b8(buf, colon + 1, valueEnd);
					if (valueStart < 0) {
						valueStart = valueEnd;
					}
					*outStart = valueStart;
					return valueEnd - valueStart;
				}
				return 0;
			}
			lineStart = next;
		} while (next > 0);
	}
fail:
	return -1;
}
