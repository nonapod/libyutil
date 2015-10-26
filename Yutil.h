#ifndef YUTIL_H
#define YUTIL_H

#include <string.h>
#define KEYPAIR_HASH_SIZE 500

typedef struct KeyPair KeyPair;
typedef struct KeyDict KeyDict;
typedef struct Node Node;

// key/val pair dict
struct KeyDict {
    Node *list[KEYPAIR_HASH_SIZE];
    int (*hash)(char*);
    int (*insert)(char*, void*, KeyDict *dict);
    int (*remove)(char*, KeyDict *dict);
    KeyPair* (*find)(char*, KeyDict *dict);
};

// key/val pair
struct KeyPair {
    char* key;
    void* data;
};


// linked node
struct Node {
    Node *next;
    Node *prev;

    void (*append)(Node*, void*);
    void (*remove)(Node**, int);
    void (*shift)(Node**);
    void (*pop)(Node**);
    void (*head)(Node**);
    void (*tail)(Node**);
    int (*length)(Node*);

    void *data;
};


#endif //YUTIL_H
