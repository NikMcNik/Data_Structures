#include "treeNode.h"
#include <iomanip>

template <class V>
class tree
{
    TreeNode<V> *root;
    int size;

public:
    // default constructor
    // by default, the tree is empty
    tree()
    {
        root = nullptr;
        size = 0;
    }

    // search value x in tree rooted at node t
    bool treeSearch(V x, TreeNode<V> *t)
    {

        if (t == nullptr)
            return false;
        if (t->getDatum() == x)
            return true;
        return treeSearch(x, t->getLeft()) || treeSearch(x, t->getRight());
    }

    bool treeSearch(V x)
    {
        treeSearch(x, root);
    }

    // binary search value x in tree rooted at node t
    bool treeBSearch(V x, TreeNode<V> *t)
    {
        while (t->getDatum != x)
        {
            // if tree empty;
            if (t == nullptr)
            {
                return;
            }
            if (x == t->getDatum)
            {
                return true;
            }

            if (x > t->getDatum)
            {
                return treeBSearch(x, t->getRight);
            }
            if (x < t->getDatum)
            {
                return treeBSearch(x, t->getLeft);
            }
        }
        // implement this method
        return false;
    }

    bool treeBSearch(V x)
    {
        return treeBSearch(x, root);
    }

    // check node t is leaf
    bool isLeaf(TreeNode<V> *t)
    {
        if ((t->getLeft == nullptr) && (t->getRight == nullptr))
        {
            return true;
        }
        // implement this method
        return false;
    }

    // find the height of the tree rooted at node t
    int height(TreeNode<V> *t)
    {
        // implement this method
        return 0;
    }

    int height()
    {
        return height(root);
    }

    // find the number of nodes of tree rooted at t
    int nNodes(TreeNode<V> *t)
    {
        // implement this method
        return 0;
    }

    int nNodes()
    {
        return nNodes(root);
    }

    // insert value x to the current tree object
    void insert(V x)
    {
        // implement this method
    }

    // print out the values of tree rooted at x
    // it shows the hierarchy of the tree
    // it will be useful for debugging
    void print(TreeNode<V> *x, int indent)
    {
        if (x == nullptr)
            return;
        if (x->getRight() != nullptr)
        {
            print(x->getRight(), indent + 4);
        }

        if (indent != 0)
        {
            cout << std::setw(indent) << ' ';
        }

        if (x->getRight() != nullptr)
        {
            cout << " /\n"
                 << std::setw(indent) << ' ';
        }

        cout << x->getDatum() << endl;

        if (x->getLeft() != nullptr)
        {
            cout << std::setw(indent) << ' ' << " \\\n";
            print(x->getLeft(), indent + 4);
        }
    }

    void print()
    {
        int count = 0;
        print(root, count);
    }
};
