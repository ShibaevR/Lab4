#include <iostream>
#include <cassert>

#include "test-traversal.h"
#include "binary-tree.h"
#include "dynamic-array.h"


void TestTraversal(){

    int array[3] = {1,2,3};

    BinaryTree<int> tree(array, 3);

    /*Tree:
     * -------1
     * 2
     * -------3
     */

    DynamicArray<int>* da_1 = tree.LPR();
    assert(da_1->GetSize() == 3 && "Error: Failed LPR traversal");

    assert(da_1->Get(0) == 1 && "Error: Failed LPR traversal");
    assert(da_1->Get(1) == 2 && "Error: Failed LPR traversal");
    assert(da_1->Get(2) == 3 && "Error: Failed LPR traversal");


    DynamicArray<int>* da_2 = tree.LRP();
    assert(da_2->GetSize() == 3 && "Error: Failed LRP traversal");

    assert(da_2->Get(0) == 1 && "Error: Failed LRP traversal");
    assert(da_2->Get(1) == 3 && "Error: Failed LRP traversal");
    assert(da_2->Get(2) == 2 && "Error: Failed LRP traversal");


    DynamicArray<int>* da_3 = tree.PLR();
    assert(da_3->GetSize() == 3 && "Error: Failed PLR traversal");

    assert(da_3->Get(0) == 2 && "Error: Failed PLR traversal");
    assert(da_3->Get(1) == 1 && "Error: Failed PLR traversal");
    assert(da_3->Get(2) == 3 && "Error: Failed PLR traversal");


    DynamicArray<int>* da_4 = tree.PRL();
    assert(da_4->GetSize() == 3 && "Error: Failed PRL traversal");

    assert(da_4->Get(0) == 2 && "Error: Failed PRL traversal");
    assert(da_4->Get(1) == 3 && "Error: Failed PRL traversal");
    assert(da_4->Get(2) == 1 && "Error: Failed PRL traversal");


    DynamicArray<int>* da_5 = tree.RLP();
    assert(da_5->GetSize() == 3 && "Error: Failed RLP traversal");

    assert(da_5->Get(0) == 3 && "Error: Failed RLP traversal");
    assert(da_5->Get(1) == 1 && "Error: Failed RLP traversal");
    assert(da_5->Get(2) == 2 && "Error: Failed RLP traversal");


    DynamicArray<int>* da_6 = tree.RPL();
    assert(da_6->GetSize() == 3 && "Error: Failed RPL traversal");

    assert(da_6->Get(0) == 3 && "Error: Failed RPL traversal");
    assert(da_6->Get(1) == 2 && "Error: Failed RPL traversal");
    assert(da_6->Get(2) == 1 && "Error: Failed RPL traversal");


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

    tree.~BinaryTree();

}
