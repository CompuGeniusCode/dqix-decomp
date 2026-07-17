#include <globaldefs.h>

extern "C" int LengthUntilDotOrEnd_0220868c(const char*);

// USA: func_ov031_022086b0
ARM int MatchWildcard_022086b0(const char* subject, const char* pattern) {
	const char* s = subject;
	const char* p = pattern;
	char sc, pc;
	goto entry;
check_eq:
	if (sc == 0) return 0;
entry:
	pc = *p++;
	sc = *s++;
	if (sc == pc) goto check_eq;
	if (pc != '*') return 1;
	s--;
	{
		int remSubj = LengthUntilDotOrEnd_0220868c(s);
		int remPat = LengthUntilDotOrEnd_0220868c(p);
		if (remPat > remSubj) return 1;
		s += remSubj - remPat;
	}
	goto entry;
}
