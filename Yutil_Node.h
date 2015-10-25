//
// Created by Leslie Cordell on 15-10-23.
//

#ifndef YUTIL_NODE_H
#define YUTIL_NODE_H

#include <stdlib.h>
#include <stdio.h>
#include "Yutil.h"

Node* initNode();

void appendNode(Node* node, void *data);
void removeNode(Node** node, int idx);
void shiftNode(Node** node);
void popNode(Node** node);
void headNode(Node** node);
void tailNode(Node** node);
int lengthNode(Node* node);






#endif //YUTIL_H
