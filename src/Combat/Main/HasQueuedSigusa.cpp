#include <globaldefs.h>

// Non-zero while the character has queued sigusa left to play. +0x17c is the count of a four-entry
// queue at +0x178 with the cursor at +0x17d: func_02053604 returns entry[cursor] and bails
// once the count runs out, and func_02053634 advances the cursor, loads the matching CCHR/CMOT archive
// and plays the animation named by strSigusa. Presumably a gesture or emote queue; the field code's
// "can the player act" chain blocks on it next to the 0x252 active byte and the 0x26c gate. Several
// initialisers zero the count, but nothing decompiled enqueues into it.
extern "C" ARM int HasQueuedSigusa(signed char* obj) {
    return obj[0x17c] > 0;
}
