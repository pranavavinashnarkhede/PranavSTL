#include "../include/pstl/pstl.hpp"
#include <iostream>

using namespace pstl;

int main()
{
    Tree t;

    t.Insert(11);
    t.Insert(5);
    t.Insert(17);
    t.Insert(21);
    t.Insert(4);
    t.Insert(7);
    t.Insert(15);

    std::cout << "Inorder Display:\n";
    t.Inorder(t.GetRoot());

    std::cout << "Preorder Display:\n";
    t.Preorder(t.GetRoot());

    std::cout << "Postorder Display:\n";
    t.Postorder(t.GetRoot());

    std::cout << "Number of nodes: "
              << t.Count(t.GetRoot()) << std::endl;

    if(t.Search(t.GetRoot(), 25))
    {
        std::cout << "25 is present in BST\n";
    }
    else
    {
        std::cout << "25 is not present in BST\n";
    }

    std::cout << "Number of leaf nodes: "
              << t.CountLeaf(t.GetRoot()) << std::endl;

    std::cout << "Number of parent nodes: "
              << t.CountParent(t.GetRoot()) << std::endl;

    return 0;
}