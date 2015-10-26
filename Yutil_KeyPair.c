#ifndef YUTIL_KEYPAIR_C
#define YUTIL_KEYPAIR_C

#include "Yutil_KeyPair.h"

/**
 * initKeyDict
 * initialised a new KeyPair dictionary
 */
KeyDict* initKeyDict() {
    KeyDict *keyDict = calloc(1, sizeof(KeyDict));

    for (int i = 0; i < KEYPAIR_HASH_SIZE; i++) {
        keyDict->list[i] = NULL;
    }

    keyDict->hash = hashKeyPair;
    keyDict->find = findKeyDict;
    keyDict->insert = insertKeyDict;
    keyDict->remove = removeKeyDict;

    return keyDict;
}

/**
 * initKeyPair
 * initialises a new KeyPair
 */
KeyPair* initKeyPair() {
    KeyPair *keyPair = calloc(1, sizeof(KeyPair));
    keyPair->key = NULL;
    keyPair->data = NULL;
    return keyPair;
}

/**
 * insertKeyDict
 * inserts data by key to an existing KeyPair dict
 */
int insertKeyDict(char* key, void* data, KeyDict* dict) {
    int hash = dict->hash(key);
    printf("%d\n", hash);
    KeyPair *keyPair = initKeyPair();

    keyPair->key = key;
    keyPair->data = data;

    if (dict->list[hash] != NULL) {
        dict->list[hash]->append(dict->list[hash], keyPair);
        return 1;
    }
    else {
        Node *node = initNode();
        node->data = keyPair;
        dict->list[hash] = node;
        return 1;
    }

    return 0;
}

/**
 * removeKeyDict
 * removes data by key from an existing KeyPair dictionary
 */
int removeKeyDict(char* key, KeyDict* dict) {
    int hash = dict->hash(key);
    Node *node = dict->list[hash];

    if (node != NULL) {
        node->head(&node);
        int length = node->length(node);
        for(int i = 0; i < length; i++, node = node->next) {
            KeyPair *this_key_pair = node->data;
            size_t key_size = strlen(key);
            if(!strncmp(this_key_pair->key, key, key_size)) {
                node->remove(&node, i);
            }
        }
    }

    return 0;
}

/**
 * findKeyDict
 * finds a KeyPair by key from an existing KeyPair dictionary
 */
KeyPair* findKeyDict(char* key, KeyDict*dict) {
    int hash = dict->hash(key);
    Node *node = dict->list[hash];

    if (node != NULL) {
        node->head(&node);
        int length = node->length(node);
        for (int i = 0; i < length; i++, node = node->next) {
            KeyPair *this_key_pair = node->data;
            size_t key_size = strlen(key);
            if(!strncmp(this_key_pair->key, key, key_size)) {
                return node->data;
            }
        }
    }

    return NULL;
}

/**
 * hashKeyPair
 * returns a simple hash from a c string
 */
int hashKeyPair(char *key) {
    int32_t hash = 0;

    while(*key != '\0') {
        hash += (int32_t) *key;
        key++;
    }

    hash = hash * 32 % KEYPAIR_HASH_SIZE;
    return abs(hash);
}


#endif


