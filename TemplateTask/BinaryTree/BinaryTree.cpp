#include <iostream>
#include "BinaryTree.h"
#include<vector>

using namespace std;

int main()
{
    BinaryTree<int> tree;

    tree.add(15);
    tree.add(13);


    cout << endl;


    tree.deleting(13);

    return 0;
}