#pragma once
#include <iostream>
#include <string>
#include <vector>
struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    bool is_leaf() const
    {
        if (value = 0)
            ;

        return true
    }
};

void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const &node)
{
    pretty_print_left_right(node, "", true);
}
