#ifndef LAB4_BINARY_TREE_H
#define LAB4_BINARY_TREE_H

#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>

#include "dynamic-array.h"
#include "complex.h"
#include "student.h"

template <class T>
class BinaryTree {
private:
    struct Node{
        Node* left;
        Node* right;

        T element;
        std::size_t node_level;

        Node(T el, size_t level) : element(el), node_level(level) , left(nullptr), right(nullptr) {};
        explicit Node(Node* other_node) : element(other_node->element), node_level(0) , left(other_node->left), right(other_node->right) {};


    };

    size_t height;
    Node* root;

    Node* BuildTree(T* items, int start, int end, std::size_t level){
        if(start > end){
            return nullptr;
        }

        int point = start + (end - start)/2;

        if(root == nullptr){
            root = new Node(items[point], level);

            //std::cout<<root->element<<"\n";

            level++;
            root->left = BuildTree(items, start, point - 1, level);
            root->right = BuildTree(items, point + 1, end, level);
        }

        else{
            Node* new_node = new Node(items[point], level);
            //std::cout<<new_node->element<<"\n";

            if(height < level){
                height = level;
            }

            level++;
            new_node->left = BuildTree(items, start, point - 1, level);
            new_node->right = BuildTree(items, point + 1, end, level);

            return new_node;
        }

        return nullptr;
    }

    Node* CreateSubTreeFromElement(Node* node, const T& value, std::size_t level){
        if(node == nullptr){
            return nullptr;
        }

        if(node->element == value){
            if(root == nullptr){
                root = new Node(node->element, level);

                level++;
                root->left = CreateSubTreeFromElement(node->left, node->left->element, level);
                root->right = CreateSubTreeFromElement(node->right, node->right->element, level);
            }

            else{
                Node* new_node = new Node(node->element, level);

                if(height < level){
                    height = level;
                }

                level++;
                new_node->left = CreateSubTreeFromElement(node->left, node->left->element, level);
                new_node->right = CreateSubTreeFromElement(node->right, node->right->element, level);

                return new_node;
            }
        }

        CreateSubTreeFromElement(node->left, value, level);
        CreateSubTreeFromElement(node->right, value, level);

        return nullptr;
    }

    Node* AddSubTree(Node* new_node, Node* node, std::size_t level){
        if(node == nullptr){
            return nullptr;
        }

        new_node = new Node(node->element, level);

        if(height < level){
            height = level;
        }

        level++;
        new_node->left = AddSubTree(new_node->left, node->left, level);
        new_node->right = AddSubTree(new_node->right, node->right, level);

        return new_node;
    }

    Node* FindNodeToInsertSubTree(Node* new_node, Node* other_root, std::size_t level){
        if(new_node->node_level == level){

            if(new_node->left == nullptr){
                new_node->left = AddSubTree(new_node->left, other_root, level + 1);

                return nullptr;
            }

            if(new_node->right == nullptr){
                new_node->right = AddSubTree(new_node->right, other_root, level + 1);

                return nullptr;
            }
        }

        else{
            if(FindNodeToInsertSubTree(new_node->left, other_root, level) == nullptr){
                return nullptr;
            }

            if(FindNodeToInsertSubTree(new_node->right, other_root, level) == nullptr){
                return nullptr;
            }
        }

        return nullptr;
    }

    std::size_t Bfactor(std::size_t bfactor, std::size_t lowest, Node* node) const{
        if(node == nullptr){
            return bfactor;
        }

        if(node->left == nullptr && node->right == nullptr){
            if(lowest > node->node_level){
                lowest = node->node_level;
                bfactor = height - lowest;
            }
        }

        bfactor = Bfactor(bfactor, lowest, node->left);
        bfactor = Bfactor(bfactor, lowest, node->right);

        return bfactor;
    };

    void DeleteNode(Node* node){
        if(node == nullptr){
            return;
        }

        DeleteNode(node->left);
        DeleteNode(node->right);

        delete node;
        node = nullptr;


    }

public:
    BinaryTree() : root(nullptr), height(0) {};

    explicit BinaryTree(T el){
        root = new Node(el, 1);
        height = 1;
    }

    BinaryTree(T* items, const size_t size){   //Создание дерева по обходу КЛП (PLR)
        if(size <= 0){
            throw std::out_of_range("Error: Size can't be less than or equal to 0");
        }

        root = nullptr;
        height = 1;
        BuildTree(items, 0, size - 1, 1);

    }

    BinaryTree(const BinaryTree<T>& tree){
        if(tree.root == nullptr){
            throw std::out_of_range("Error: Can't construct a subtree with a tree without elements");
        }

        root = nullptr;
        height = 1;

        CreateSubTreeFromElement(tree.root, tree.root->element, 1);
    }

    BinaryTree(const BinaryTree<T>& tree, const T& value){
        if(tree.root == nullptr){
            throw std::out_of_range("Error: Can't construct a subtree with a tree without elements");
        }

        if(CountElementsByValue(tree.root, value, 0) == 0){
            throw std::out_of_range("Error: Can't construct a subtree from an element that doesn't exist");
        }

        if(CountElementsByValue(tree.root, value, 0) > 1){
            throw std::out_of_range("Error: The element from which a subtree is constructed must be unique");
        }

        root = nullptr;
        height = 1;

        CreateSubTreeFromElement(tree.root, value, 1);
    }

    ~BinaryTree(){
        height = 0;
        DeleteNode(root);
        root = nullptr;
    }

    BinaryTree<T>* Combine(const BinaryTree<T>& tree){
        if(tree.root == nullptr){
            throw std::out_of_range("Error: Can't combine trees with a tree without elements");
        }

        if(root == nullptr){
            throw std::out_of_range("Error: Can't combine trees with a tree without elements");
        }

        DynamicArray<T>* array_1 = LRP();

        DynamicArray<T>* array_2;
        array_2 = new DynamicArray<T>();

        LRP(tree.root, array_2);

        T sum_array[array_1->GetSize() + array_2->GetSize()];

        for(int i=0; i < array_1->GetSize(); i++){
            sum_array[i] = array_1->Get(i);
        }

        for(int i=0; i < array_2->GetSize(); i++){
            sum_array[i + array_1->GetSize()] = array_2->Get(i);
        }

        BinaryTree<T>* new_tree;
        new_tree = new BinaryTree<T>(sum_array, array_1->GetSize() + array_2->GetSize());

        array_1->~DynamicArray();
        delete array_1;
        array_2->~DynamicArray();
        delete array_2;

        return new_tree;

    }

    BinaryTree<T>& AddSubTree(const BinaryTree<T>& tree){
        if(tree.root == nullptr){
            throw std::out_of_range("Error: Can't add a subtree without elements");
        }

        if(root == nullptr){
            throw std::out_of_range("Error: Can't add a subtree to a tree without elements");
        }

        std::size_t incomplete_level = height + 1;

        for(int i=1; i <= height; i++){
            if(CountElementsOnLevel(root, i, 0) < pow(2, i - 1)){
                incomplete_level = i;
            }
        }

        FindNodeToInsertSubTree(root, tree.root, incomplete_level - 1);

        return *this;
    }

    std::size_t Bfactor() const{
        if(root == nullptr){
            throw std::out_of_range("Error: Can't calculate bfactor from a tree without elements");
        }

        return Bfactor(0, height, root);
    }

    BinaryTree<T>& Balance(){
        if(root == nullptr){
            throw std::out_of_range("Error: Can't balance a tree without elements");
        }

        DynamicArray<T>* array_1 = LRP();

        T array[array_1->GetSize()];

        for(int i=0; i < array_1->GetSize(); i++){
            array[i] = array_1->Get(i);
        }

        this->~BinaryTree();
        root = nullptr;
        height = 1;

        BuildTree(array, 0, array_1->GetSize() - 1, 1);

        array_1->~DynamicArray();
        delete array_1;

        return *this;
    };

    BinaryTree<T>& operator=(const BinaryTree<T>& tree){
        this->~BinaryTree();

        root = nullptr;
        height = 1;

        CreateSubTreeFromElement(tree.root, tree.root->element, 1);

        return *this;
    };




private:
    void Map(Node* node){
        if(node == nullptr){
            return;
        }

        node->element = node->element + node->element;


        Map(node->left);
        Map(node->right);
    }

    void Where(std::function<bool(T, T)> function, Node* node, DynamicArray<T>* array, const T& value){
        if(node == nullptr){
            return;
        }

        if(function(node->element, value)){
            array->Append(node->element);
        }

        Where(function, node->left, array, value);
        Where(function, node->right, array, value);
    }


public:
    BinaryTree<T>& Map(){
        if(root == nullptr){
            throw std::out_of_range("Error: Can't map a tree without elements");
        }

        Map(root);

        return *this;
    }

    BinaryTree<T>& Where(std::function<bool(T, T)> function, const T& value){
        if(root == nullptr){
            throw std::out_of_range("Error: Can't where a tree without elements");
        }

        DynamicArray<T>* dynamic_array;
        dynamic_array = new DynamicArray<T>();

        Where(function, root, dynamic_array, value);

        T array[dynamic_array->GetSize()];

        for(int i=0; i < dynamic_array->GetSize(); i++){
            array[i] = dynamic_array->Get(i);
        }

        this->~BinaryTree();

        root = nullptr;
        height = 1;
        BuildTree(array, 0, dynamic_array->GetSize() - 1, 1);

        dynamic_array->~DynamicArray();
        delete dynamic_array;

        return *this;
    }





private:
    void PLR(Node* node, DynamicArray<T>* array) const{
        if(node == nullptr){
            return;
        }

        array->Append(node->element);
        PLR(node->left, array);
        PLR(node->right, array);
    }

    void PRL(Node* node, DynamicArray<T>* array) const{
        if(node == nullptr){
            return;
        }

        array->Append(node->element);
        PLR(node->right, array);
        PLR(node->left, array);
    }

    void LRP(Node* node, DynamicArray<T>* array) const{
        if(node == nullptr){
            return;
        }

        PLR(node->left, array);
        PLR(node->right, array);
        array->Append(node->element);
    }

    void LPR(Node* node, DynamicArray<T>* array) const{
        if(node == nullptr){
            return;
        }

        PLR(node->left, array);
        array->Append(node->element);
        PLR(node->right, array);
    }

    void RLP(Node* node, DynamicArray<T>* array) const{
        if(node == nullptr){
            return;
        }

        PLR(node->right, array);
        PLR(node->left, array);
        array->Append(node->element);
    }

    void RPL(Node* node, DynamicArray<T>* array) const{
        if(node == nullptr){
            return;
        }

        PLR(node->right, array);
        array->Append(node->element);
        PLR(node->left, array);
    }

public:
    DynamicArray<T>* PLR() const{
        DynamicArray<T>* array;
        array = new DynamicArray<T>();

        if(root == nullptr){
            return array;
        }

        PLR(root, array);

        return array;
    }

    DynamicArray<T>* PRL() const{
        DynamicArray<T>* array;
        array = new DynamicArray<T>();

        if(root == nullptr){
            return array;
        }

        PRL(root, array);

        return array;
    }

    DynamicArray<T>* LRP() const{
        DynamicArray<T>* array;
        array = new DynamicArray<T>();

        if(root == nullptr){
            return array;
        }

        LRP(root, array);

        return array;
    }

    DynamicArray<T>* LPR() const{
        DynamicArray<T>* array;
        array = new DynamicArray<T>();

        if(root == nullptr){
            return array;
        }

        LPR(root, array);

        return array;
    }

    DynamicArray<T>* RLP() const{
        DynamicArray<T>* array;
        array = new DynamicArray<T>();

        if(root == nullptr){
            return array;
        }

        RLP(root, array);

        return array;
    }

    DynamicArray<T>* RPL() const{
        DynamicArray<T>* array;
        array = new DynamicArray<T>();

        if(root == nullptr){
            return array;
        }

        RPL(root, array);

        return array;
    }




private:

    std::size_t FindElementsByLevel(Node* node, DynamicArray<T>* array, const std::size_t level, std::size_t count) const{
        if(node == nullptr){
            return count;
        }

        if(node->node_level == level){
            array->Append(node->element);
            count++;
            //std::cout<<level<<": "<<node->element<<"  "<<count<<"\n";
            return count;
        }

        count = FindElementsByLevel(node->left, array, level, count);
        count = FindElementsByLevel(node->right, array, level, count);

        return count;
    }

    std::size_t CountElementsByValue(Node* node, const T& value, std::size_t count) const{
        if(node == nullptr){
            return count;
        }

        if(node->element == value){
            count++;

            count = CountElementsByValue(node->left, value, count);
            count = CountElementsByValue(node->right, value, count);

            return count;
        }

        count = CountElementsByValue(node->left, value, count);
        count = CountElementsByValue(node->right, value, count);

        return count;
    }

    std::size_t GetElementLevel(Node* node, const T& value, std::size_t level) const{
        if(node == nullptr){
            return level;
        }

        if(node->element == value){
            level = node->node_level;
            //std::cout<<level<<": "<<node->element<<"  "<<count<<"\n";
            return level;
        }

        level = GetElementLevel(node->left, value, level);
        level = GetElementLevel(node->right, value, level);

        return level;
    }

    void DeleteElementByValue(Node* node, const T& value){
        if(node == nullptr){
            return;
        }

        if(node->left != nullptr){
            if(node->left->element == value){
                if(height > node->node_level && node->right == nullptr){
                    height = node->node_level;
                }

                DeleteNode(node->left);
                node->left = nullptr;
            }

            DeleteElementByValue(node->left, value);
            DeleteElementByValue(node->right, value);
        }

        if(node->right != nullptr){
            if(node->right->element == value){
                if(height > node->node_level && node->left == nullptr){
                    height = node->node_level;
                }

                DeleteNode(node->right);
                node->right = nullptr;
            }

            DeleteElementByValue(node->left, value);
            DeleteElementByValue(node->right, value);
        }
    }

    void DeleteLevel(Node* node, const std::size_t level){
        if(node == nullptr){
            return;
        }
        if(node->left != nullptr){
            if(node->left->node_level == level){
                DeleteNode(node->left);
                node->left = nullptr;
            }

            DeleteLevel(node->left, level);
            DeleteLevel(node->right, level);
        }

        if(node->right != nullptr){
            if(node->right->node_level == level){
                DeleteNode(node->right);
                node->right = nullptr;
            }

            DeleteLevel(node->left, level);
            DeleteLevel(node->right, level);
        }
    }

    std::size_t CountElementsOnLevel(Node* node, std::size_t level, std::size_t count) const{
        if(node == nullptr){
            return count;
        }

        if(node->node_level == level){
            count++;
            //std::cout<<level<<": "<<node->element<<"  "<<count<<"\n";
            return count;
        }

        count = CountElementsOnLevel(node->left, level, count);
        count = CountElementsOnLevel(node->right, level, count);

        return count;
    }

    Node* FindNodeToInsert(const T& item, Node* node, std::size_t level){

        if(node->node_level == level){

            if(node->left == nullptr){
                node->left = new Node(item, node->node_level + 1);

                if(height < node->node_level + 1){
                    height = node->node_level + 1;
                }

                return nullptr;
            }

            if(node->right == nullptr){
                node->right = new Node(item, node->node_level + 1);

                if(height < node->node_level + 1){
                    height = node->node_level + 1;
                }

                return nullptr;
            }
        }

        else{
            if(FindNodeToInsert(item, node->left, level) == nullptr){
                return nullptr;
            }

            if(FindNodeToInsert(item, node->right, level) == nullptr){
                return nullptr;
            }
        }

        return nullptr;
    }

public:

    void Insert(const T& value){
        if(root == nullptr){
            root = new Node(value, 1);
            return;
        }

        std::size_t incomplete_level = height + 1;

        for(int i=1; i <= height; i++){
            if(CountElementsOnLevel(root, i, 0) < pow(2, i - 1)){
                incomplete_level = i;
            }
        }

        FindNodeToInsert(value, root, incomplete_level - 1);
    }

    DynamicArray<T>* FindElementsByLevel(const int level) const{
        DynamicArray<T>* array;
        array = new DynamicArray<T>();

        if(root == nullptr){
            return array;
        }

        FindElementsByLevel(root, array, level, 0);

        return array;
    }

    T& GetRootElement() const{
        if(root == nullptr){
            throw std::out_of_range("Error: Root must have an element");
        }

        return root->element;
    }

    void DeleteElementByValue(const T& value){
        if(root == nullptr){
            throw std::out_of_range("Error: Can't delete elements from a tree without");
        }

        if(root->element == value){
            this->~BinaryTree();
            return;
        }

        std::size_t count = CountElementsByValue(root, value, 0);

        if(count > 0){
            DeleteElementByValue(root, value);
        }
    }

    void DeleteLevel(const std::size_t level){
        if(root == nullptr){
            throw std::out_of_range("Error: Can't delete a level from a tree without");
        }

        if(level == 1){
            this->~BinaryTree();
            return;
        }

        if(height < level){
            throw std::out_of_range("Error: level can't be greater than height");
        }

        DeleteLevel(root, level);

        height = level - 1;
    }

    std::size_t GetHeight() const{
        return height;
    }




private:
    std::string TreeToString(const std::string& prefix, const Node* node, bool is_left, std::string tree_string) const{
        if(node != nullptr){
            tree_string += prefix;

            if(is_left){
                tree_string += "|--";
                tree_string += std::to_string(node->element);
                tree_string += "\n";
            }

            else{
                tree_string += "\\--";
                tree_string += std::to_string(node->element);
                tree_string += "\n";
            }

            tree_string = TreeToString( prefix + (is_left ? "|   " : "    "), node->left, true, tree_string);
            tree_string = TreeToString( prefix + (is_left ? "|   " : "    "), node->right, false, tree_string);
        }

        return tree_string;
    }

    std::string ComplexElementToString(Complex<double> el) const{
        std::string c_number;

        c_number += "{";
        c_number += std::to_string(el.GetReal());
        c_number += ", ";
        c_number += std::to_string(el.GetImag());
        c_number += "}";

        return c_number;
    }

    std::string ComplexTreeToString(const std::string& prefix, const Node* node, bool is_left, std::string tree_string) const{
        if(node != nullptr){
            tree_string += prefix;

            if(is_left){
                tree_string += "|--";
                tree_string += ComplexElementToString(node->element);
                tree_string += "\n";
            }

            else{
                tree_string += "\\--";
                tree_string += ComplexElementToString(node->element);
                tree_string += "\n";
            }


            tree_string = ComplexTreeToString( prefix + (is_left ? "|   " : "    "), node->left, true, tree_string);
            tree_string = ComplexTreeToString( prefix + (is_left ? "|   " : "    "), node->right, false, tree_string);
        }

        return tree_string;
    }

    std::string StringTreeToStringFromRoot(const std::string& prefix, const Node* node, bool is_left, std::string tree_string) const{
        if(node != nullptr){
            tree_string += prefix;

            if(is_left){
                tree_string += "|--";
                tree_string += node->element;
                tree_string += "\n";
            }

            else{
                tree_string += "\\--";
                tree_string += node->element;
                tree_string += "\n";
            }

            tree_string = StringTreeToStringFromRoot( prefix + (is_left ? "|   " : "    "), node->left, true, tree_string);
            tree_string = StringTreeToStringFromRoot( prefix + (is_left ? "|   " : "    "), node->right, false, tree_string);
        }

        return tree_string;
    }

    std::string StudentElementToString(Student el) const{
        std::string student_string;

        student_string += "{Group: ";
        student_string += std::to_string(el.GetGroupNumber());
        student_string += ", Name: ";
        student_string += el.GetFirstName();
        student_string += " ";
        student_string += el.GetLastName();
        student_string += ", Id: ";
        student_string += std::to_string(el.GetID());
        student_string += "}";

        return student_string;
    }

    std::string StudentTreeToStringFromRoot(const std::string& prefix, const Node* node, bool is_left, std::string tree_string) const{
        if(node != nullptr){
            tree_string += prefix;

            if(is_left){
                tree_string += "|--";
                tree_string += StudentElementToString(node->element);
                tree_string += "\n";
            }

            else{
                tree_string += "\\--";
                tree_string += StudentElementToString(node->element);
                tree_string += "\n";
            }

            tree_string = StudentTreeToStringFromRoot( prefix + (is_left ? "|   " : "    "), node->left, true, tree_string);
            tree_string = StudentTreeToStringFromRoot( prefix + (is_left ? "|   " : "    "), node->right, false, tree_string);
        }

        return tree_string;
    }

public:
    std::string TreeToStringFromRoot() const{
        std::string tree_string;

        tree_string = TreeToString("", root, false, tree_string);

        return tree_string;
    }

    std::string ComplexTreeToStringFromRoot() const{
        std::string tree_string;

        tree_string = ComplexTreeToString("", root, false, tree_string);

        return tree_string;
    }

    std::string StringTreeToStringFromRoot() const{
        std::string tree_string;

        tree_string = StringTreeToStringFromRoot("", root, false, tree_string);

        return tree_string;
    }

    std::string StudentTreeToStringFromRoot() const{
        std::string tree_string;

        tree_string = StudentTreeToStringFromRoot("", root, false, tree_string);

        return tree_string;
    }

};

#endif //LAB4_BINARY_TREE_H
