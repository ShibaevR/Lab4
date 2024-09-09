#include <iostream>

#include "dynamic-array.h"
#include "complex.h"
#include "binary-tree.h"

#include "test-traversal.h"
#include "test-constructors.h"
#include "test-operations.h"

#include "ui.h"


int main() {

    TestTraversal();
    TestConstructors();
    TestOperations();

    std::cout<<"\nAll tests completed successfully\n";

    UserInterface();


    return 0;
}
