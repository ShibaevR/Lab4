#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

#include "test-constructors.h"
#include "binary-tree.h"
#include "dynamic-array.h"



void TestConstructors(){
    BinaryTree<int> tree;
    assert(tree.GetHeight() == 0 && "Error: Failed construction of Binary Tree");


    BinaryTree<int> tree_1(1);

    DynamicArray<int>* da_1 = tree_1.LPR();
    assert(da_1->GetSize() == 1 && "Error: Failed construction of Binary Tree");

    assert(da_1->Get(0) == 1 && "Error: Failed construction of Binary Tree");


    int array[5] = {1,2,3,4,5};

    BinaryTree<int> tree_2(array, 5);
    BinaryTree<int> tree_3(tree_2, 1);

    DynamicArray<int>* da_2 = tree_3.LPR();
    assert(da_2->GetSize() == 2 && "Error: Failed construction of Binary Tree");

    assert(da_2->Get(0) == 1 && "Error: Failed construction of Binary Tree");
    assert(da_2->Get(1) == 2 && "Error: Failed construction of Binary Tree");

    try{
        BinaryTree<int> tree_111(array, 0);
        assert(false && "Error: Constructed a Binary Tree with an array with size 0");
    }
    catch(...){
        assert(true);
    }

    try{
        BinaryTree<int> tree_0;
        BinaryTree<int> tree_111(tree_0, 1);
        assert(false && "Error: Constructed a SubTree with an array with size 0");
    }
    catch(...){
        assert(true);
    }

    try{
        BinaryTree<int> tree_0(array, 5);
        BinaryTree<int> tree_111(tree_0, 6);
        assert(false && "Error: Constructed a SubTree with an element that doesn't exist");
    }
    catch(...){
        assert(true);
    }

    try{
        int array_1[5] = {1,2,3,0,0};
        BinaryTree<int> tree_0(array_1, 5);
        BinaryTree<int> tree_111(tree_0, 0);
        assert(false && "Error: Constructed a SubTree with an element that isn't unique");
    }
    catch(...){
        assert(true);
    }

    da_1->~DynamicArray();
    delete da_1;
    da_2->~DynamicArray();
    delete da_2;

    tree.~BinaryTree();
    tree_1.~BinaryTree();
    tree_2.~BinaryTree();
    tree_3.~BinaryTree();

    int a = 0;
    for(int i=0; i < 14; i++){
        a += pow(2, i);
    }
    std::cout<<a;


}