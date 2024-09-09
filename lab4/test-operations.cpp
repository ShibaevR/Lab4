#include <iostream>
#include <cassert>

#include "test-operations.h"
#include "binary-tree.h"
#include "dynamic-array.h"

bool GreaterThanG(const int x, const int y){
    return (x > y);
}

void TestOperations(){

    int array[5] = {1,2,3,4,5};

    BinaryTree<int> tree_1(array, 5);

    BinaryTree<int> tree_2(array, 5);

    BinaryTree<int>* tree_3 = tree_1.Combine(tree_2);

    DynamicArray<int>* da_1 = tree_3->LPR();
    assert(da_1->GetSize() == 10 && "Error: Failed combination of 2 Binary Trees");

    assert(da_1->Get(0) == 2 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(1) == 1 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(2) == 4 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(3) == 5 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(4) == 3 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(5) == 4 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(6) == 1 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(7) == 2 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(8) == 5 && "Error: Failed combination of 2 Binary Tree");
    assert(da_1->Get(9) == 3 && "Error: Failed combination of 2 Binary Tree");

    try{
        int array_1[5] = {1,2,3,0,0};
        BinaryTree<int> tree_0(array_1, 5);
        BinaryTree<int> tree_111;
        BinaryTree<int>* tree_222 = tree_0.Combine(tree_111);
        assert(false && "Error: Combined trees with a tree without elements");
    }
    catch(...){
        assert(true);
    }

    try{
        int array_1[5] = {1,2,3,0,0};
        BinaryTree<int> tree_0(array_1, 5);
        BinaryTree<int> tree_111;
        BinaryTree<int>* tree_222 = tree_111.Combine(tree_0);
        assert(false && "Error: Combined trees with a tree without elements");
    }
    catch(...){
        assert(true);
    }


    tree_1.AddSubTree(tree_2);

    DynamicArray<int>* da_2 = tree_1.LPR();
    assert(da_2->GetSize() == 10 && "Error: Failed addition of a subtree");

    assert(da_2->Get(0) == 1 && "Error: Failed addition of a subtree");
    assert(da_2->Get(1) == 3 && "Error: Failed addition of a subtree");
    assert(da_2->Get(2) == 1 && "Error: Failed addition of a subtree");
    assert(da_2->Get(3) == 2 && "Error: Failed addition of a subtree");
    assert(da_2->Get(4) == 4 && "Error: Failed addition of a subtree");
    assert(da_2->Get(5) == 5 && "Error: Failed addition of a subtree");
    assert(da_2->Get(6) == 2 && "Error: Failed addition of a subtree");
    assert(da_2->Get(7) == 3 && "Error: Failed addition of a subtree");
    assert(da_2->Get(8) == 4 && "Error: Failed addition of a subtree");
    assert(da_2->Get(9) == 5 && "Error: Failed addition of a subtree");

    try{
        int array_1[5] = {1,2,3,0,0};
        BinaryTree<int> tree_0(array_1, 5);
        BinaryTree<int> tree_111;
        tree_0.AddSubTree(tree_111);
        assert(false && "Error: Added a subtree without elements");
    }
    catch(...){
        assert(true);
    }

    try{
        int array_1[5] = {1,2,3,0,0};
        BinaryTree<int> tree_0(array_1, 5);
        BinaryTree<int> tree_111;
        tree_111.AddSubTree(tree_0);
        assert(false && "Error: Added a subtree to a tree without elements");
    }
    catch(...){
        assert(true);
    }


    assert(tree_1.Bfactor() == 2 && "Error: Failed calculation of bfactor");

    try{
        BinaryTree<int> tree_111;
        tree_111.Bfactor();
        assert(false && "Error: Calculated a bfactor from a tree without elements");
    }
    catch(...){
        assert(true);
    }


    tree_1.Balance();

    DynamicArray<int>* da_3 = tree_1.LPR();
    assert(da_3->GetSize() == 10 && "Error: Failed to balance a Binary Trees");

    assert(da_3->Get(0) == 3 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(1) == 1 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(2) == 1 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(3) == 2 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(4) == 4 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(5) == 4 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(6) == 5 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(7) == 2 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(8) == 5 && "Error: Failed to balance a Binary Trees");
    assert(da_3->Get(9) == 3 && "Error: Failed to balance a Binary Trees");

    try{
        BinaryTree<int> tree_111;
        tree_111.Balance();
        assert(false && "Error: Balanced a tree without elements");
    }
    catch(...){
        assert(true);
    }


    tree_1.Map();

    DynamicArray<int>* da_4 = tree_1.LPR();
    assert(da_4->GetSize() == 10 && "Error: Failed to Map a Binary Trees");

    assert(da_4->Get(0) == 3*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(1) == 1*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(2) == 1*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(3) == 2*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(4) == 4*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(5) == 4*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(6) == 5*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(7) == 2*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(8) == 5*2 && "Error: Failed to Map a Binary Trees");
    assert(da_4->Get(9) == 3*2 && "Error: Failed to Map a Binary Trees");

    try{
        BinaryTree<int> tree_111;
        tree_111.Map();
        assert(false && "Error: Mapped a tree without elements");
    }
    catch(...){
        assert(true);
    }


    std::function<bool(int, int)> function = GreaterThanG;
    tree_1.Where(function, 9);

    DynamicArray<int>* da_5 = tree_1.LPR();
    assert(da_5->GetSize() == 2 && "Error: Failed to Where a Binary Trees");

    assert(da_5->Get(0) == 10 && "Error: Failed to Where a Binary Trees");
    assert(da_5->Get(1) == 10 && "Error: Failed to Where a Binary Trees");

    try{
        BinaryTree<int> tree_111;
        tree_111.Map();
        assert(false && "Error: Applied where to a tree without elements");
    }
    catch(...){
        assert(true);
    }


    tree_1.Insert(111);

    DynamicArray<int>* da_6 = tree_1.LPR();
    assert(da_6->GetSize() == 3 && "Error: Failed to insert an element into a Binary Trees");

    assert(da_6->Get(0) == 111 && "Error: Failed to insert an element into a Binary Trees");
    assert(da_6->Get(1) == 10 && "Error: Failed to insert an element into a Binary Trees");
    assert(da_6->Get(2) == 10 && "Error: Failed to insert an element into a Binary Trees");


    DynamicArray<int>* da_7 = tree_1.FindElementsByLevel(2);
    assert(da_7->GetSize() == 2 && "Error: Failed to find elements by level");

    assert(da_7->Get(0) == 111 && "Error: Failed to find elements by level");
    assert(da_7->Get(1) == 10 && "Error: Failed to find elements by level");


    assert(tree_1.GetRootElement() == 10 && "Error: Failed to find the root element");

    try{
        BinaryTree<int> tree_111;
        tree_111.GetRootElement();
        assert(false && "Error: Got a root element from a tree without elements");
    }
    catch(...){
        assert(true);
    }


    tree_1.DeleteElementByValue(111);

    DynamicArray<int>* da_8 = tree_1.LPR();
    assert(da_8->GetSize() == 2 && "Error: Failed to delete an element by value");

    assert(da_8->Get(0) == 10 && "Error: Failed to delete an element by value");
    assert(da_8->Get(1) == 10 && "Error: Failed to delete an element by value");

    try{
        BinaryTree<int> tree_111;
        tree_111.DeleteElementByValue(1);
        assert(false && "Error: Deleted elements from a tree without elements");
    }
    catch(...){
        assert(true);
    }


    tree_3->DeleteLevel(2);

    DynamicArray<int>* da_9 = tree_3->LPR();
    assert(da_9->GetSize() == 1 && "Error: Failed to delete a level");

    assert(da_9->Get(0) == 3 && "Error: Failed to delete a level");

    try{
        BinaryTree<int> tree_111;
        tree_111.DeleteLevel(1);
        assert(false && "Error: Deleted a level from a tree without elements");
    }
    catch(...){
        assert(true);
    }


    tree_1.~BinaryTree();
    tree_2.~BinaryTree();
    tree_3->~BinaryTree();
    delete tree_3;

    da_1->~DynamicArray();
    delete da_1;
    da_2->~DynamicArray();
    delete da_2;
    da_3->~DynamicArray();
    delete da_3;
    da_4->~DynamicArray();
    delete da_4;
    da_5->~DynamicArray();
    delete da_5;
    da_6->~DynamicArray();
    delete da_6;
    da_7->~DynamicArray();
    delete da_7;
    da_8->~DynamicArray();
    delete da_8;
    da_9->~DynamicArray();
    delete da_9;

}
