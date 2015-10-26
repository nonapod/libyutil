#ifndef RADIOTIDE_YUTIL_KEYPAID_H
#define RADIOTIDE_YUTIL_KEYPAID_H

#import "Yutil.h"


KeyDict* initKeyDict();

int hashKeyPair(char *key);

int insertKeyDict(char* key, void* data, KeyDict* dict);

int removeKeyDict(char* key, KeyDict* dict);

KeyPair* findKeyDict(char* key, KeyDict* dict);

KeyPair* initKeyPair();

#endif //RADIOTIDE_YUTIL_KEYPAID_H
