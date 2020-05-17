#include <stdexcept>
#include <string>
#include <iostream>

using namespace std; 



class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value)
    {
        Node* temp  = NULL;
        int wartosc = root.getValue();

        if (wartosc == value)
            return true;

        else if (wartosc < value)
        {
            if (root.getRight() != NULL)
            {
                temp = root.getRight();
                return contains(*temp, value);
            }
            else
                return false;
       
        }
        else if (wartosc > value)
        {
            if (root.getLeft() != NULL)
            {
                temp = root.getLeft();
                return contains(*temp, value);
            }
            else
                return false;
        }


    }
};

#ifndef RunTests
int main()
{
    Node n1(1, NULL, NULL);
    Node n5(5, NULL, NULL);
    Node n6(6, &n5, NULL);
    Node n2(2, &n1, &n5);
    Node n3(3, &n2, &n6);
   

    
    cout << BinarySearchTree::contains(n3, 5);
}
#endif

/*umiem drzewa :D*/