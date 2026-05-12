#include <iostream>
#include <string>
#include <vector>
#include "node.hpp"

Node *create_node(int value)
{
    Node *newNode = new Node{.value = value};
    return newNode;
}

