#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
#include <cstring>
#include <functional>

#include "ui.h"
#include "binary-tree.h"
#include "complex.h"
#include "student.h"

std::string RandomString(){
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    std::string random_string;

    for (int i = 0; i < 20; ++i) {
        random_string += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return random_string;
}





bool GreaterThanY(const int x, const int y){
    return (x > y);
}

bool SmallerThanY(const int x, const int y){
    return (x < y);
}

bool EqualToY(const int x, const int y){
    return (x == y);
}

void IntTreeOptions(BinaryTree<int>& t_1){

    while(true){

        std::cout<<"\n\n-----------------Options-----------------\n";
        std::cout<<"Enter <1> to combine trees\n";
        std::cout<<"Enter <2> to add a subtree\n";
        std::cout<<"Enter <3> to get bfactor\n";
        std::cout<<"Enter <4> to balance the tree\n";
        std::cout<<"Enter <5> to apply map\n";
        std::cout<<"Enter <6> to apply where\n";

        std::cout<<"----------------------------------\n";
        std::cout<<"Enter <7> for PLR traversal\n";
        std::cout<<"Enter <8> for PRL traversal\n";
        std::cout<<"Enter <9> for LRP traversal\n";
        std::cout<<"Enter <10> for LPR traversal\n";
        std::cout<<"Enter <11> for RLP traversal\n";
        std::cout<<"Enter <12> for RPL traversal\n";
        std::cout<<"----------------------------------\n";

        std::cout<<"Enter <13> to insert an element\n";
        std::cout<<"Enter <14> to find elements of a level\n";
        std::cout<<"Enter <15> to get the root element\n";
        std::cout<<"Enter <16> to delete elements by value\n";
        std::cout<<"Enter <17> to delete a level\n";
        std::cout<<"Enter <18> to get the height\n";
        std::cout<<"Enter <19> to print the tree\n";
        std::cout<<"----------------------------------\n";
        std::cout<<"Enter 'STOP' to finish\n";
        std::cout<<"----------Or----------\n";
        std::cout<<"Choose action: ";

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                int array[number_of_elements];

                char user_input_int[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_int;

                    array[i] = strtol(user_input_int, &endptr_1, 10);
                }

                BinaryTree<int> t_2(array, number_of_elements);

                std::cout<<"\nYour second tree: \n\n";
                std::cout<<t_2.TreeToStringFromRoot();

                BinaryTree<int>* t_3 = t_1.Combine(t_2);

                t_1 = *t_3;

                std::cout<<"\nYour combined tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                t_2.~BinaryTree();
                t_3->~BinaryTree();
                delete t_3;

                break;
            }

            case 2:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                int array[number_of_elements];

                char user_input_int[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_int;

                    array[i] = strtol(user_input_int, &endptr_1, 10);
                }

                BinaryTree<int> t_2(array, number_of_elements);

                std::cout<<"\nYour subtree: \n\n";
                std::cout<<t_2.TreeToStringFromRoot();

                t_1.AddSubTree(t_2);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                t_2.~BinaryTree();

                break;
            }

            case 3:{
                std::cout<<"\nBfactor: "<<t_1.Bfactor()<<"\n";
                break;
            }

            case 4:{
                t_1.Balance();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 5:{
                t_1.Map();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 6:{
                std::cout<<"\nEnter <1> to get elements greater than X";
                std::cout<<"\nEnter <2> to get elements smaller than X";
                std::cout<<"\nEnter <3> to get elements equal to X";

                std::cout<<"\n\nChoose action: ";

                std::cin>>user_input_1;

                int option = strtol(user_input_1, &endptr_1, 10);

                switch(option){
                    case 1:{
                        std::function<bool(int, int)> function = GreaterThanY;

                        std::cout<<"\nEnter the X: ";
                        std::cin>>user_input_1;
                        int value = strtol(user_input_1, &endptr_1, 10);

                        t_1.Where(function, value);

                        break;
                    }
                    case 2:{
                        std::function<bool(int, int)> function = SmallerThanY;

                        std::cout<<"\nEnter the X: ";
                        std::cin>>user_input_1;
                        int value = strtol(user_input_1, &endptr_1, 10);

                        t_1.Where(function, value);

                        break;
                    }
                    case 3:{
                        std::function<bool(int, int)> function = EqualToY;

                        std::cout<<"\nEnter the X: ";
                        std::cin>>user_input_1;
                        int value = strtol(user_input_1, &endptr_1, 10);

                        t_1.Where(function, value);

                        break;
                    }
                    default:{
                        std::cout<<"\nError: This action doesn't exist. Please try again";
                        break;
                    }
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 7:{
                DynamicArray<int>* array = t_1.PLR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 8:{
                DynamicArray<int>* array = t_1.PRL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 9:{
                DynamicArray<int>* array = t_1.LRP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 10:{
                DynamicArray<int>* array = t_1.LPR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 11:{
                DynamicArray<int>* array = t_1.RLP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 12:{
                DynamicArray<int>* array = t_1.RPL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 13:{
                std::cout<<"\nEnter the new element: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int value = strtol(user_input_int, &endptr_1, 10);

                t_1.Insert(value);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 14:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                DynamicArray<int>* array = t_1.FindElementsByLevel(level);

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 15:{
                std::cout<<"\nRoot element: "<<t_1.GetRootElement();
                break;
            }

            case 16:{
                std::cout<<"\nEnter the value of the elements you want to delete: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int value = strtol(user_input_int, &endptr_1, 10);

                t_1.DeleteElementByValue(value);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 17:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                t_1.DeleteLevel(level);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 18:{
                std::cout<<"\nHeight: "<<t_1.GetHeight();
                break;
            }

            case 19:{
                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();
                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}





bool DoubleGreaterThanY(const double x, const double y){
    return (x > y);
}

bool DoubleSmallerThanY(const double x, const double y){
    return (x < y);
}

bool DoubleEqualToY(const double x, const double y){
    return (x == y);
}

void DoubleTreeOptions(BinaryTree<double>& t_1){

    while(true){

        std::cout<<"\n\n-----------------Options-----------------\n";
        std::cout<<"Enter <1> to combine trees\n";
        std::cout<<"Enter <2> to add a subtree\n";
        std::cout<<"Enter <3> to get bfactor\n";
        std::cout<<"Enter <4> to balance the tree\n";
        std::cout<<"Enter <5> to apply map\n";
        std::cout<<"Enter <6> to apply where\n";

        std::cout<<"----------------------------------\n";
        std::cout<<"Enter <7> for PLR traversal\n";
        std::cout<<"Enter <8> for PRL traversal\n";
        std::cout<<"Enter <9> for LRP traversal\n";
        std::cout<<"Enter <10> for LPR traversal\n";
        std::cout<<"Enter <11> for RLP traversal\n";
        std::cout<<"Enter <12> for RPL traversal\n";
        std::cout<<"----------------------------------\n";

        std::cout<<"Enter <13> to insert an element\n";
        std::cout<<"Enter <14> to find elements of a level\n";
        std::cout<<"Enter <15> to get the root element\n";
        std::cout<<"Enter <16> to delete elements by value\n";
        std::cout<<"Enter <17> to delete a level\n";
        std::cout<<"Enter <18> to get the height\n";
        std::cout<<"Enter <19> to print the tree\n";
        std::cout<<"----------------------------------\n";
        std::cout<<"Enter 'STOP' to finish\n";
        std::cout<<"----------Or----------\n";
        std::cout<<"Choose action: ";

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                double array[number_of_elements];

                char user_input_int[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_int;

                    array[i] = strtod(user_input_int, &endptr_1);
                }

                BinaryTree<double> t_2(array, number_of_elements);

                std::cout<<"\nYour second tree: \n\n";
                std::cout<<t_2.TreeToStringFromRoot();

                BinaryTree<double>* t_3 = t_1.Combine(t_2);

                t_1 = *t_3;

                std::cout<<"\nYour combined tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                t_2.~BinaryTree();
                t_3->~BinaryTree();
                delete t_3;

                break;
            }

            case 2:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                double array[number_of_elements];

                char user_input_int[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_int;

                    array[i] = strtod(user_input_int, &endptr_1);
                }

                BinaryTree<double> t_2(array, number_of_elements);

                std::cout<<"\nYour subtree: \n\n";
                std::cout<<t_2.TreeToStringFromRoot();

                t_1.AddSubTree(t_2);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                t_2.~BinaryTree();

                break;
            }

            case 3:{
                std::cout<<"\nBfactor: "<<t_1.Bfactor()<<"\n";
                break;
            }

            case 4:{
                t_1.Balance();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 5:{
                t_1.Map();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 6:{
                std::cout<<"\nEnter <1> to get elements greater than X";
                std::cout<<"\nEnter <2> to get elements smaller than X";
                std::cout<<"\nEnter <3> to get elements equal to X";

                std::cout<<"\n\nChoose action: ";

                std::cin>>user_input_1;

                int option = strtol(user_input_1, &endptr_1, 10);

                switch(option){
                    case 1:{
                        std::function<bool(double , double )> function = DoubleGreaterThanY;

                        std::cout<<"\nEnter the X: ";
                        std::cin>>user_input_1;
                        double value = strtod(user_input_1, &endptr_1);

                        t_1.Where(function, value);

                        break;
                    }
                    case 2:{
                        std::function<bool(double , double )> function = DoubleSmallerThanY;

                        std::cout<<"\nEnter the X: ";
                        std::cin>>user_input_1;
                        double value = strtod(user_input_1, &endptr_1);

                        t_1.Where(function, value);

                        break;
                    }
                    case 3:{
                        std::function<bool(double , double )> function = DoubleEqualToY;

                        std::cout<<"\nEnter the X: ";
                        std::cin>>user_input_1;
                        double value = strtod(user_input_1, &endptr_1);

                        t_1.Where(function, value);

                        break;
                    }
                    default:{
                        std::cout<<"\nError: This action doesn't exist. Please try again";
                        break;
                    }
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 7:{
                DynamicArray<double>* array = t_1.PLR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 8:{
                DynamicArray<double>* array = t_1.PRL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 9:{
                DynamicArray<double>* array = t_1.LRP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 10:{
                DynamicArray<double>* array = t_1.LPR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 11:{
                DynamicArray<double>* array = t_1.RLP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 12:{
                DynamicArray<double>* array = t_1.RPL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 13:{
                std::cout<<"\nEnter the new element: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                double value = strtod(user_input_int, &endptr_1);

                t_1.Insert(value);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 14:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                DynamicArray<double>* array = t_1.FindElementsByLevel(level);

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 15:{
                std::cout<<"\nRoot element: "<<t_1.GetRootElement();
                break;
            }

            case 16:{
                std::cout<<"\nEnter the value of the elements you want to delete: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                double value = strtod(user_input_int, &endptr_1);

                t_1.DeleteElementByValue(value);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 17:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                t_1.DeleteLevel(level);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                break;
            }

            case 18:{
                std::cout<<"\nHeight: "<<t_1.GetHeight();
                break;
            }

            case 19:{
                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();
                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}




void ComplexTreeOptions(BinaryTree<Complex<double>>& t_1){

    while(true){

        std::cout<<"\n\n-----------------Options-----------------\n";
        std::cout<<"Enter <1> to combine trees\n";
        std::cout<<"Enter <2> to add a subtree\n";
        std::cout<<"Enter <3> to get bfactor\n";
        std::cout<<"Enter <4> to balance the tree\n";
        std::cout<<"Enter <5> to apply map\n";

        std::cout<<"----------------------------------\n";
        std::cout<<"Enter <6> for PLR traversal\n";
        std::cout<<"Enter <7> for PRL traversal\n";
        std::cout<<"Enter <8> for LRP traversal\n";
        std::cout<<"Enter <9> for LPR traversal\n";
        std::cout<<"Enter <10> for RLP traversal\n";
        std::cout<<"Enter <11> for RPL traversal\n";
        std::cout<<"----------------------------------\n";

        std::cout<<"Enter <12> to insert an element\n";
        std::cout<<"Enter <13> to find elements of a level\n";
        std::cout<<"Enter <14> to get the root element\n";
        std::cout<<"Enter <15> to delete elements by value\n";
        std::cout<<"Enter <16> to delete a level\n";
        std::cout<<"Enter <17> to get the height\n";
        std::cout<<"Enter <18> to print the tree\n";
        std::cout<<"----------------------------------\n";
        std::cout<<"Enter 'STOP' to finish\n";
        std::cout<<"----------Or----------\n";
        std::cout<<"Choose action: ";

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++) {
                    number_of_elements += pow(2, i);
                }

                Complex<double> array[number_of_elements];
                double real;
                double imag;

                char user_input_double[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter real part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    real = strtod(user_input_double, &endptr_1);

                    std::cout<<"\nEnter imaginary part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    imag = strtod(user_input_double, &endptr_1);

                    Complex<double> c(real, imag);

                    array[i] = c;
                }

                BinaryTree<Complex<double>> t_2(array, number_of_elements);

                std::cout<<"\nYour second tree: \n\n";
                std::cout<<t_2.ComplexTreeToStringFromRoot();

                BinaryTree<Complex<double>>* t_3 = t_1.Combine(t_2);

                t_1 = *t_3;

                std::cout<<"\nYour combined tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                t_2.~BinaryTree();
                t_3->~BinaryTree();
                delete t_3;

                break;
            }

            case 2:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                Complex<double> array[number_of_elements];
                double real;
                double imag;

                char user_input_double[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter real part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    real = strtod(user_input_double, &endptr_1);

                    std::cout<<"\nEnter imaginary part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    imag = strtod(user_input_double, &endptr_1);

                    Complex<double> c(real, imag);

                    array[i] = c;
                }

                BinaryTree<Complex<double>> t_2(array, number_of_elements);

                std::cout<<"\nYour subtree: \n\n";
                std::cout<<t_2.ComplexTreeToStringFromRoot();

                t_1.AddSubTree(t_2);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                t_2.~BinaryTree();

                break;
            }

            case 3:{
                std::cout<<"\nBfactor: "<<t_1.Bfactor()<<"\n";
                break;
            }

            case 4:{
                t_1.Balance();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                break;
            }

            case 5:{
                t_1.Map();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                break;
            }

            case 6:{
                DynamicArray<Complex<double>>* array = t_1.PLR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{"<<array->Get(i).GetReal()<<", "<<array->Get(i).GetImag()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 7:{
                DynamicArray<Complex<double>>* array = t_1.PRL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{"<<array->Get(i).GetReal()<<", "<<array->Get(i).GetImag()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 8:{
                DynamicArray<Complex<double>>* array = t_1.LRP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{"<<array->Get(i).GetReal()<<", "<<array->Get(i).GetImag()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 9:{
                DynamicArray<Complex<double>>* array = t_1.LPR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{"<<array->Get(i).GetReal()<<", "<<array->Get(i).GetImag()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 10:{
                DynamicArray<Complex<double>>* array = t_1.RLP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{"<<array->Get(i).GetReal()<<", "<<array->Get(i).GetImag()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 11:{
                DynamicArray<Complex<double>>* array = t_1.RPL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{"<<array->Get(i).GetReal()<<", "<<array->Get(i).GetImag()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 12:{
                double real;
                double imag;

                char user_input_double[20];

                std::cout<<"\nEnter real part of the new element: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr_1);

                std::cout<<"\nEnter imaginary part of the new element: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr_1);

                Complex<double> value(real, imag);

                t_1.Insert(value);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                break;
            }

            case 13:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                DynamicArray<Complex<double>>* array = t_1.FindElementsByLevel(level);

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{"<<array->Get(i).GetReal()<<", "<<array->Get(i).GetImag()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 14:{
                std::cout<<"\nRoot element: "<<"{"<<t_1.GetRootElement().GetReal()<<", "<<t_1.GetRootElement().GetImag()<<"} ";
                break;
            }

            case 15:{
                double real;
                double imag;

                char user_input_double[20];

                std::cout<<"\nEnter real part of the elements you want to delete: ";
                std::cin>>user_input_double;
                real = strtod(user_input_double, &endptr_1);

                std::cout<<"\nEnter imaginary part of the elements you want to delete: ";
                std::cin>>user_input_double;
                imag = strtod(user_input_double, &endptr_1);

                Complex<double> value(real, imag);

                t_1.DeleteElementByValue(value);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                break;
            }

            case 16:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                t_1.DeleteLevel(level);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                break;
            }

            case 17:{
                std::cout<<"\nHeight: "<<t_1.GetHeight();
                break;
            }

            case 18:{
                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();
                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}





void StringTreeOptions(BinaryTree<std::string>& t_1){

    while(true){

        std::cout<<"\n\n-----------------Options-----------------\n";
        std::cout<<"Enter <1> to combine trees\n";
        std::cout<<"Enter <2> to add a subtree\n";
        std::cout<<"Enter <3> to get bfactor\n";
        std::cout<<"Enter <4> to balance the tree\n";
        std::cout<<"Enter <5> to apply map\n";

        std::cout<<"----------------------------------\n";
        std::cout<<"Enter <6> for PLR traversal\n";
        std::cout<<"Enter <7> for PRL traversal\n";
        std::cout<<"Enter <8> for LRP traversal\n";
        std::cout<<"Enter <9> for LPR traversal\n";
        std::cout<<"Enter <10> for RLP traversal\n";
        std::cout<<"Enter <11> for RPL traversal\n";
        std::cout<<"----------------------------------\n";

        std::cout<<"Enter <12> to insert an element\n";
        std::cout<<"Enter <13> to find elements of a level\n";
        std::cout<<"Enter <14> to get the root element\n";
        std::cout<<"Enter <15> to delete elements by value\n";
        std::cout<<"Enter <16> to delete a level\n";
        std::cout<<"Enter <17> to get the height\n";
        std::cout<<"Enter <18> to print the tree\n";
        std::cout<<"----------------------------------\n";
        std::cout<<"Enter 'STOP' to finish\n";
        std::cout<<"----------Or----------\n";
        std::cout<<"Choose action: ";

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                std::string array[number_of_elements];

                char user_input_string[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_string;

                    array[i] = user_input_string;
                }

                BinaryTree<std::string> t_2(array, number_of_elements);

                std::cout<<"\nYour second tree: \n\n";
                std::cout<<t_2.StringTreeToStringFromRoot();

                std::cout<<"gvadvbdf\n";

                BinaryTree<std::string>* t_3 = t_1.Combine(t_2);

                t_1 = *t_3;

                std::cout<<"\nYour combined tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                t_2.~BinaryTree();
                t_3->~BinaryTree();
                delete t_3;

                break;
            }

            case 2:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                std::string array[number_of_elements];

                char user_input_string[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_string;

                    array[i] = user_input_string;
                }

                BinaryTree<std::string> t_2(array, number_of_elements);

                std::cout<<"\nYour subtree: \n\n";
                std::cout<<t_2.StringTreeToStringFromRoot();

                t_1.AddSubTree(t_2);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                t_2.~BinaryTree();

                break;
            }

            case 3:{
                std::cout<<"\nBfactor: "<<t_1.Bfactor()<<"\n";
                break;
            }

            case 4:{
                t_1.Balance();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                break;
            }

            case 5:{
                t_1.Map();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                break;
            }

            case 6:{
                DynamicArray<std::string>* array = t_1.PLR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 7:{
                DynamicArray<std::string>* array = t_1.PRL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 8:{
                DynamicArray<std::string>* array = t_1.LRP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 9:{
                DynamicArray<std::string>* array = t_1.LPR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 10:{
                DynamicArray<std::string>* array = t_1.RLP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 11:{
                DynamicArray<std::string>* array = t_1.RPL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 12:{
                std::cout<<"\nEnter the new element: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                std::string value = user_input_int;

                t_1.Insert(value);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                break;
            }

            case 13:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                DynamicArray<std::string>* array = t_1.FindElementsByLevel(level);

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<array->Get(i)<<" ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 14:{
                std::cout<<"\nRoot element: "<<t_1.GetRootElement();
                break;
            }

            case 15:{
                std::cout<<"\nEnter the value of the elements you want to delete: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                std::string value = user_input_int;

                t_1.DeleteElementByValue(value);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                break;
            }

            case 16:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                t_1.DeleteLevel(level);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                break;
            }

            case 17:{
                std::cout<<"\nHeight: "<<t_1.GetHeight();
                break;
            }

            case 18:{
                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();
                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}




void StudentTreeOptions(BinaryTree<Student>& t_1){

    while(true){

        std::cout<<"\n\n-----------------Options-----------------\n";
        std::cout<<"Enter <1> to combine trees\n";
        std::cout<<"Enter <2> to add a subtree\n";
        std::cout<<"Enter <3> to get bfactor\n";
        std::cout<<"Enter <4> to balance the tree\n";

        std::cout<<"----------------------------------\n";
        std::cout<<"Enter <5> for PLR traversal\n";
        std::cout<<"Enter <6> for PRL traversal\n";
        std::cout<<"Enter <7> for LRP traversal\n";
        std::cout<<"Enter <8> for LPR traversal\n";
        std::cout<<"Enter <9> for RLP traversal\n";
        std::cout<<"Enter <10> for RPL traversal\n";
        std::cout<<"----------------------------------\n";

        std::cout<<"Enter <11> to insert an element\n";
        std::cout<<"Enter <12> to find elements of a level\n";
        std::cout<<"Enter <13> to get the root element\n";
        std::cout<<"Enter <14> to delete elements by value\n";
        std::cout<<"Enter <15> to delete a level\n";
        std::cout<<"Enter <16> to get the height\n";
        std::cout<<"Enter <17> to print the tree\n";
        std::cout<<"----------------------------------\n";
        std::cout<<"Enter 'STOP' to finish\n";
        std::cout<<"----------Or----------\n";
        std::cout<<"Choose action: ";

        char user_input_1[20];
        std::cin>>user_input_1;

        if(strcmp(user_input_1, "STOP") == 0)
            return;

        char *endptr_1;

        int action = strtol(user_input_1, &endptr_1, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                Student array[number_of_elements];

                char user_input_string[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter "<<i+1<<" student's group number: ";
                    std::cin>>user_input_string;
                    array[i].AssignGroupNumber(strtol(user_input_string, &endptr_1, 10));

                    std::cout<<"\nEnter "<<i+1<<" student's first name: ";
                    std::cin>>user_input_string;
                    array[i].AssignFirstName(user_input_string);

                    std::cout<<"\nEnter "<<i+1<<" student's last name: ";
                    std::cin>>user_input_string;
                    array[i].AssignLastName(user_input_string);

                    std::cout<<"\nEnter "<<i+1<<" student's id: ";
                    std::cin>>user_input_string;
                    array[i].AssignID(strtol(user_input_string, &endptr_1, 10));
                }

                BinaryTree<Student> t_2(array, number_of_elements);

                std::cout<<"\nYour second tree: \n\n";
                std::cout<<t_2.StudentTreeToStringFromRoot();

                std::cout<<"gvadvbdf\n";

                BinaryTree<Student>* t_3 = t_1.Combine(t_2);

                t_1 = *t_3;

                std::cout<<"\nYour combined tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();

                t_2.~BinaryTree();
                t_3->~BinaryTree();
                delete t_3;

                break;
            }

            case 2:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                Student array[number_of_elements];

                char user_input_string[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter "<<i+1<<" student's group number: ";
                    std::cin>>user_input_string;
                    array[i].AssignGroupNumber(strtol(user_input_string, &endptr_1, 10));

                    std::cout<<"\nEnter "<<i+1<<" student's first name: ";
                    std::cin>>user_input_string;
                    array[i].AssignFirstName(user_input_string);

                    std::cout<<"\nEnter "<<i+1<<" student's last name: ";
                    std::cin>>user_input_string;
                    array[i].AssignLastName(user_input_string);

                    std::cout<<"\nEnter "<<i+1<<" student's id: ";
                    std::cin>>user_input_string;
                    array[i].AssignID(strtol(user_input_string, &endptr_1, 10));
                }

                BinaryTree<Student> t_2(array, number_of_elements);

                std::cout<<"\nYour subtree: \n\n";
                std::cout<<t_2.StudentTreeToStringFromRoot();

                t_1.AddSubTree(t_2);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();

                t_2.~BinaryTree();

                break;
            }

            case 3:{
                std::cout<<"\nBfactor: "<<t_1.Bfactor()<<"\n";
                break;
            }

            case 4:{
                t_1.Balance();

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();

                break;
            }


            case 5:{
                DynamicArray<Student>* array = t_1.PLR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{Group: "<<array->Get(i).GetGroupNumber()<<", Name: "<<array->Get(i).GetFirstName()<<" "<<array->Get(i).GetLastName()<<", Id: "<<array->Get(i).GetID()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 6:{
                DynamicArray<Student>* array = t_1.PRL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{Group: "<<array->Get(i).GetGroupNumber()<<", Name: "<<array->Get(i).GetFirstName()<<" "<<array->Get(i).GetLastName()<<", Id: "<<array->Get(i).GetID()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 7:{
                DynamicArray<Student>* array = t_1.LRP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{Group: "<<array->Get(i).GetGroupNumber()<<", Name: "<<array->Get(i).GetFirstName()<<" "<<array->Get(i).GetLastName()<<", Id: "<<array->Get(i).GetID()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 8:{
                DynamicArray<Student>* array = t_1.LPR();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{Group: "<<array->Get(i).GetGroupNumber()<<", Name: "<<array->Get(i).GetFirstName()<<" "<<array->Get(i).GetLastName()<<", Id: "<<array->Get(i).GetID()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 9:{
                DynamicArray<Student>* array = t_1.RLP();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{Group: "<<array->Get(i).GetGroupNumber()<<", Name: "<<array->Get(i).GetFirstName()<<" "<<array->Get(i).GetLastName()<<", Id: "<<array->Get(i).GetID()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 10:{
                DynamicArray<Student>* array = t_1.RPL();

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{Group: "<<array->Get(i).GetGroupNumber()<<", Name: "<<array->Get(i).GetFirstName()<<" "<<array->Get(i).GetLastName()<<", Id: "<<array->Get(i).GetID()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 11:{
                Student value;

                char user_input_string[20];

                std::cout<<"\nEnter student's group number: ";
                std::cin>>user_input_string;
                value.AssignGroupNumber(strtol(user_input_string, &endptr_1, 10));

                std::cout<<"\nEnter student's first name: ";
                std::cin>>user_input_string;
                value.AssignFirstName(user_input_string);

                std::cout<<"\nEnter student's last name: ";
                std::cin>>user_input_string;
                value.AssignLastName(user_input_string);

                std::cout<<"\nEnter student's id: ";
                std::cin>>user_input_string;
                value.AssignID(strtol(user_input_string, &endptr_1, 10));

                t_1.Insert(value);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();

                break;
            }

            case 12:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                DynamicArray<Student>* array = t_1.FindElementsByLevel(level);

                std::cout<<"\nResult: ";

                for(int i=0; i < array->GetSize(); i++){
                    std::cout<<"{Group: "<<array->Get(i).GetGroupNumber()<<", Name: "<<array->Get(i).GetFirstName()<<" "<<array->Get(i).GetLastName()<<", Id: "<<array->Get(i).GetID()<<"} ";
                }
                std::cout<<"\n ";

                array->~DynamicArray();
                delete array;

                break;
            }

            case 13:{
                std::cout<<"\nRoot element: {Group: "<<t_1.GetRootElement().GetGroupNumber()<<", Name: "<<t_1.GetRootElement().GetFirstName()<<" "<<t_1.GetRootElement().GetLastName()<<", Id: "<<t_1.GetRootElement().GetID()<<"} ";;
                break;
            }

            case 14:{
                Student value;

                char user_input_string[20];

                std::cout<<"\nEnter student's group number: ";
                std::cin>>user_input_string;
                value.AssignGroupNumber(strtol(user_input_string, &endptr_1, 10));

                std::cout<<"\nEnter student's first name: ";
                std::cin>>user_input_string;
                value.AssignFirstName(user_input_string);

                std::cout<<"\nEnter student's last name: ";
                std::cin>>user_input_string;
                value.AssignLastName(user_input_string);

                std::cout<<"\nEnter student's id: ";
                std::cin>>user_input_string;
                value.AssignID(strtol(user_input_string, &endptr_1, 10));

                t_1.DeleteElementByValue(value);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();

                break;
            }

            case 15:{
                std::cout<<"\nEnter the level: ";

                char user_input_int[20];
                std::cin>>user_input_int;

                int level = strtol(user_input_int, &endptr_1, 10);

                if(level <= 0 || level > t_1.GetHeight()){
                    std::cout<<"\nError: The level must be greater than 0 and smaller than height\n";
                }

                t_1.DeleteLevel(level);

                if(t_1.GetHeight() == 0){
                    std::cout<<"\nTree was deleted\n";
                    return;
                }

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();

                break;
            }

            case 16:{
                std::cout<<"\nHeight: "<<t_1.GetHeight();
                break;
            }

            case 17:{
                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();
                break;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}


void AutoCreateTree(){
    srand((unsigned)time(NULL));

    while(true){

        std::cout<<"\n\n-------------Type Menu-------------\n";
        std::cout<<"Enter <1> to create an int tree\n";
        std::cout<<"Enter <2> to create a double tree\n";
        std::cout<<"Enter <3> to create a complex tree\n";
        std::cout<<"Enter <4> to create a string tree\n";
        std::cout<<"Enter <5> to create a student tree\n";
        std::cout<<"Enter <6> to go back\n";
        std::cout<<"Choose action: ";

        char user_input_1[20];
        std::cin>>user_input_1;
        char *endptr;
        int action = strtol(user_input_1, &endptr, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                int array[number_of_elements];

                for(int i=0; i < number_of_elements; i++){
                    array[i] = rand()/(RAND_MAX/100);
                }

                BinaryTree<int> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                IntTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }


            case 2:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                double array[number_of_elements];

                for(int i=0; i < number_of_elements; i++){
                    array[i] = (double)rand()/((double)RAND_MAX/100.0);
                }

                BinaryTree<double> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                DoubleTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }


            case 3:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                Complex<double> array[number_of_elements];
                double real;
                double imag;

                for(int i=0; i < number_of_elements; i++){
                    real = (double)rand()/((double)RAND_MAX/100.0);

                    imag = (double)rand()/((double)RAND_MAX/100.0);

                    Complex<double> c(real, imag);

                    array[i] = c;
                }

                BinaryTree<Complex<double>> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                ComplexTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }


            case 4:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                std::string array[number_of_elements];

                for(int i=0; i < number_of_elements; i++){
                    array[i] = RandomString();
                }

                BinaryTree<std::string> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                StringTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }

            case 5:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                Student array[number_of_elements];

                for(int i=0; i < number_of_elements; i++){
                    array[i].AssignFirstName(RandomString());
                    array[i].AssignLastName(RandomString());
                    array[i].AssignID(rand()/(RAND_MAX/10000));
                    array[i].AssignGroupNumber(rand()/(RAND_MAX/10000));
                }

                BinaryTree<Student> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();

                StudentTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }

            case 6:{
                return;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }
}




void CreateTree(){

    while(true){

        std::cout<<"\n\n-------------Type Menu-------------\n";
        std::cout<<"Enter <1> to create an int tree\n";
        std::cout<<"Enter <2> to create a double tree\n";
        std::cout<<"Enter <3> to create a complex tree\n";
        std::cout<<"Enter <4> to create a string tree\n";
        std::cout<<"Enter <5> to create a student tree\n";
        std::cout<<"Enter <6> to go back\n";
        std::cout<<"Choose action: ";

        char user_input_1[20];
        std::cin>>user_input_1;
        char *endptr;
        int action = strtol(user_input_1, &endptr, 10);

        switch(action){
            case 1:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                int array[number_of_elements];

                char user_input_int[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_int;

                    array[i] = strtol(user_input_int, &endptr, 10);
                }

                BinaryTree<int> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                IntTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }


            case 2:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                double array[number_of_elements];

                char user_input_double[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_double;

                    array[i] = strtod(user_input_double, &endptr);
                }

                BinaryTree<double> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.TreeToStringFromRoot();

                DoubleTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }


            case 3:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                Complex<double> array[number_of_elements];
                double real;
                double imag;

                char user_input_double[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter real part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    real = strtod(user_input_double, &endptr);

                    std::cout<<"\nEnter imaginary part of the element "<<i + 1<<": ";
                    std::cin>>user_input_double;
                    imag = strtod(user_input_double, &endptr);

                    Complex<double> c(real, imag);

                    array[i] = c;
                }

                BinaryTree<Complex<double>> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.ComplexTreeToStringFromRoot();

                ComplexTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }


            case 4:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                std::string array[number_of_elements];

                for(int i=0; i < number_of_elements; i++){
                    array[i] = RandomString();
                }

                char user_input_string[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>user_input_string;

                    array[i] = user_input_string;
                }

                BinaryTree<std::string> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StringTreeToStringFromRoot();

                StringTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }

            case 5:{
                std::cout<<"\nEnter the height of the tree: ";

                char user_input_size[20];
                std::cin>>user_input_size;

                char *endptr_1;

                int height = strtol(user_input_size, &endptr_1, 10);

                if(height <= 0){
                    std::cout<<"\nError: Height can't less than or equal to 0\n";
                    break;
                }

                int number_of_elements = 0;

                for(int i=0; i < height; i++){
                    number_of_elements += pow(2, i);
                }

                Student array[number_of_elements];

                char user_input_string[20];

                for(int i=0; i < number_of_elements; i++){
                    std::cout<<"\nEnter "<<i+1<<" student's group number: ";
                    std::cin>>user_input_string;
                    array[i].AssignGroupNumber(strtol(user_input_string, &endptr, 10));

                    std::cout<<"\nEnter "<<i+1<<" student's first name: ";
                    std::cin>>user_input_string;
                    array[i].AssignFirstName(user_input_string);

                    std::cout<<"\nEnter "<<i+1<<" student's last name: ";
                    std::cin>>user_input_string;
                    array[i].AssignLastName(user_input_string);

                    std::cout<<"\nEnter "<<i+1<<" student's id: ";
                    std::cin>>user_input_string;
                    array[i].AssignID(strtol(user_input_string, &endptr, 10));
                }

                BinaryTree<Student> t_1(array, number_of_elements);

                std::cout<<"\nYour tree: \n\n";
                std::cout<<t_1.StudentTreeToStringFromRoot();

                StudentTreeOptions(t_1);

                t_1.~BinaryTree();

                break;
            }

            case 6:{
                return;
            }


            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }

}




void UserInterface(){

    while(true){

        std::cout<<"\n\n-----------------Main Menu-----------------\n";
        std::cout<<"Enter <1> to create a tree automatically\n";
        std::cout<<"Enter <2> to create a tree manually\n";
        std::cout<<"Enter <3> to finish\n";
        std::cout<<"Choose action: ";

        char user_input_1[20];
        std::cin>>user_input_1;
        char *endptr;
        int action = strtol(user_input_1, &endptr, 10);

        switch(action){
            case 1:{
                AutoCreateTree();
                break;
            }
            case 2:{
                CreateTree();
                break;
            }
            case 3:{
                exit(0);
            }
            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }
}