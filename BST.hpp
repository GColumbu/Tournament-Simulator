#include "coada.hpp"
class BST{
    echipa team;
    BST *left, *right;
public:
    BST(echipa);
    friend BST* Insert(BST*, echipa);
    friend BST* makeTree(winners *);
    friend void showTree(BST*, ofstream &);
};
