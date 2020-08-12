#ifndef SRC_INCLUDE_MORE_STRING_H_
#define SRC_INCLUDE_MORE_STRING_H_

#include <string.h>

// array version
int
ALen (char[]);

int
ACopy (char[], char[]);

int
ACompare (char[], char[]);

char*
AAppend (char[], char[]);

// pointer version

int
PLen (char*);

int
PCopy (char*, char*);

int
PCompare (char*, char*);

char*
PAppend (char*, char*);

#endif /* SRC_INCLUDE_MORE_STRING_H_ */
