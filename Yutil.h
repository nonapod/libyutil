#ifndef YUTIL_H
#define YUTIL_H

typedef struct KeyPair KeyPair;
typedef struct Node Node;

// key/val pair
struct KeyPair {
    void* key;
    void* val;
    int32_t hash;
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
