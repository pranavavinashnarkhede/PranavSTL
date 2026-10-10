#ifndef PSTL_TREE_HPP
#define PSTL_TREE_HPP

#include <iostream>

namespace pstl
{
    struct TreeNode
    {
        int data;
        TreeNode *lchild;
        TreeNode *rchild;
    };

    typedef TreeNode NODE;
    typedef TreeNode* PNODE;
    typedef TreeNode** PPNODE;

    class Tree
    {
        private:
            PNODE first;

            void Destroy(PNODE first);

        public:
            Tree();
            ~Tree();

            void Insert(int iNo);

            void Inorder(PNODE first);
            void Preorder(PNODE first);
            void Postorder(PNODE first);

            int Count(PNODE first);
            bool Search(PNODE first, int iNo);
            int CountLeaf(PNODE first);
            int CountParent(PNODE first);

            PNODE GetRoot();
    };

    // Constructor
    inline Tree::Tree()
    {
        first = NULL;
    }

    // Destructor
    inline Tree::~Tree()
    {
        Destroy(first);
        first = NULL;
    }

    // Release allocated tree nodes
    inline void Tree::Destroy(PNODE first)
    {
        if(first != NULL)
        {
            Destroy(first->lchild);
            Destroy(first->rchild);

            delete first;
        }
    }

    // Insert an element
    inline void Tree::Insert(int iNo)
    {
        PNODE newn = new NODE();
        PNODE temp = NULL;

        newn->data = iNo;
        newn->lchild = NULL;
        newn->rchild = NULL;

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(true)
            {
                if(iNo > temp->data)
                {
                    if(temp->rchild == NULL)
                    {
                        temp->rchild = newn;
                        break;
                    }

                    temp = temp->rchild;
                }
                else if(iNo < temp->data)
                {
                    if(temp->lchild == NULL)
                    {
                        temp->lchild = newn;
                        break;
                    }

                    temp = temp->lchild;
                }
                else
                {
                    std::cout
                        << "Unable to insert as element is duplicate\n";

                    delete newn;
                    break;
                }
            }
        }
    }

    // Inorder: Left, Data, Right
    inline void Tree::Inorder(PNODE first)
    {
        if(first != NULL)
        {
            Inorder(first->lchild);
            std::cout << first->data << std::endl;
            Inorder(first->rchild);
        }
    }

    // Preorder: Data, Left, Right
    inline void Tree::Preorder(PNODE first)
    {
        if(first != NULL)
        {
            std::cout << first->data << std::endl;
            Preorder(first->lchild);
            Preorder(first->rchild);
        }
    }

    // Postorder: Left, Right, Data
    inline void Tree::Postorder(PNODE first)
    {
        if(first != NULL)
        {
            Postorder(first->lchild);
            Postorder(first->rchild);
            std::cout << first->data << std::endl;
        }
    }

    // Count total nodes
    inline int Tree::Count(PNODE first)
    {
        if(first == NULL)
        {
            return 0;
        }

        return 1 + Count(first->lchild) + Count(first->rchild);
    }

    // Search for an element
    inline bool Tree::Search(PNODE first, int iNo)
    {
        while(first != NULL)
        {
            if(first->data == iNo)
            {
                return true;
            }
            else if(first->data > iNo)
            {
                first = first->lchild;
            }
            else
            {
                first = first->rchild;
            }
        }

        return false;
    }

    // Count leaf nodes
    inline int Tree::CountLeaf(PNODE first)
    {
        if(first == NULL)
        {
            return 0;
        }

        if(first->lchild == NULL && first->rchild == NULL)
        {
            return 1;
        }

        return CountLeaf(first->lchild)
             + CountLeaf(first->rchild);
    }

    // Count parent nodes
    inline int Tree::CountParent(PNODE first)
    {
        if(first == NULL)
        {
            return 0;
        }

        int iCount = 0;

        if(first->lchild != NULL || first->rchild != NULL)
        {
            iCount = 1;
        }

        return iCount
             + CountParent(first->lchild)
             + CountParent(first->rchild);
    }

    // Return the root node
    inline PNODE Tree::GetRoot()
    {
        return first;
    }
}

#endif