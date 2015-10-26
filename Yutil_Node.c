#include "Yutil_Node.h"


/* -------------------------
    Doubly Linked List Node
   ------------------------- */

/**
 * initNode
 * creates a new node list with self as the head
 * and tail
 */
Node* initNode() {
    Node *node = calloc(1, sizeof(Node));

    node->data = NULL;
    node->next = NULL;
    node->prev = NULL;

    node->append = appendNode;
    node->remove = removeNode;
    node->shift = shiftNode;
    node->pop = popNode;
    node->head = headNode;
    node->length= lengthNode;
    node->tail = tailNode;

    return node;
}

/**
 * appendNode
 * append a new data node onto the end of the list
 */
void appendNode(Node* node, void *data){

    Node *this = node;
    Node *new_node = initNode();

    new_node->data = data;

    while (this->next != NULL) {
        this = this->next;
    }

    new_node->prev = this;
    this->next = new_node;

}

/**
 * removeNode
 * remove a node from the list by index if it exists
 */
void removeNode(Node** node, int idx){
    Node *this = *node;
    if (idx == 0) {
        this->shift(node);
    }
    else {
        if (this != NULL) {
            // rewind to head
            while(this->prev != NULL) {
                this = this->prev;
            }
            for(int i = 0; i <= idx; i++, this = this->next) {
                if (this != NULL) {
                    if (i == idx) {
                        if (this->prev != NULL) {
                            this->prev->next = (this->next != NULL) ? this->next : NULL;
                        }
                        if (this->next != NULL) {
                            this->next->prev = (this->prev != NULL) ? this->prev : NULL;
                        }
                        // set the node back to head
                        (*node)->head(node);
                        free(this);
                    }
                }
                else {
                    break;
                }
            }
        }
    }
}

/**
 * shiftNode
 * remove the first node from the list
 */
void shiftNode(Node** node){
    if (*node != NULL) {
        if((*node)->next != NULL) {
            *node = (*node)->next;
            if ((*node)->prev != NULL) {
                free((*node)->prev);
                ((*node)->prev = NULL);
            }
        }
        else {
            free(*node);
            *node = NULL;
        }
    }
}

/**
 * lengthNode
 * go back to the head node and then count forward
 * all of the nodes in the list.
 */
int lengthNode(Node* node){
    int length = 0;
    if(node != NULL) {
        length++;
        // return to the node head
        while(node->prev != NULL) {
            node = node->prev;
        }
        while(node->next != NULL) {
            length++;
            node = node->next;
        }
    }
    return length;
}

/**
 * headNode
 * return to the first node in the list
 */
void headNode(Node** node) {
    if(node != NULL) {
        while((*node)->prev != NULL) {
            *node = (*node)->prev;
        }
    }
}

/**
 * tailNode
 * move to the last node in the list
 */
void tailNode(Node** node){
    if(node != NULL) {
        while((*node)->next != NULL) {
            *node = (*node)->next;
        }
    }
}

/**
 * popNode
 * remove a node from the end of the list
 */
void popNode(Node** node){
    int len = 0;
    if (*node != NULL) {
        // rewind
        (*node)->head(node);
        len = (*node)->length(*node);
        (*node)->remove(node, len-1);
    }
}

