#ifndef LAB4_DYNAMIC_ARRAY_H
#define LAB4_DYNAMIC_ARRAY_H

#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H

#include <iostream>
#include <string>

template <class T>
class DynamicArray{
private:
    T* da_data = nullptr;
    int da_size = 0;

public:
    DynamicArray() : da_data(nullptr), da_size(0) {}

    DynamicArray(T* data, int size) : da_size(size){
        if(da_size <= 0)
            throw std::out_of_range("Error: Size can't be equal to or less than 0");

        da_data = new T[size];
        for (int i=0; i < size; i++)
            da_data[i] = data[i];
    }

    explicit DynamicArray(const int size) : da_size(size) {
        if (da_size <= 0){
            throw std::out_of_range("Error: Size can't be equal to or less than 0");
        }
        da_data = new T[da_size];
    }

    DynamicArray(const DynamicArray<T>& array) : da_size(array.da_size){
        if (da_size <= 0){
            throw std::out_of_range("Error: Size can't be equal to or less than 0");
        }

        da_data = new T[da_size];
        for (int i=0; i < da_size; i++)
            da_data[i] = array.da_data[i];
    }

    virtual ~DynamicArray(){
        delete[] da_data;
        da_data = nullptr;
        da_size = 0;
    }


    const T& Get(const int index) const{
        if(index < 0 || index >= da_size)
            throw std::out_of_range("Error: Index is out of range");

        return da_data[index];
    }

    int GetSize() const{
        return da_size;
    }

    DynamicArray<T>& Set(const int index, const T& value){
        if(index < 0 || index >= da_size)
            throw std::out_of_range("Error: Index is out of range");

        da_data[index] = value;

        return *this;
    }

    DynamicArray<T>& Resize(const int new_size){
        if(new_size <= 0)
            throw std::out_of_range("Error: Size can't be equal to or less than 0");

        if(da_size == 0){
            da_data = new T[new_size];
            da_size = new_size;

            return *this;
        }

        T new_data[new_size];
        for(int i=0; i < da_size; i++){
            new_data[i] = da_data[i];
        }

        delete[] da_data;

        da_size = new_size;
        da_data = new T[new_size];

        for (int i=0; i < da_size; i++){
            da_data[i] = new_data[i];
        }

        return *this;
    }

    DynamicArray<T>& Append(const T& element){
        Resize(da_size + 1);
        Set(da_size - 1, element);

        return *this;
    }


    bool CheckInitialization() const{
        if(da_size == 0)
            return true;
        return false;
    }


    bool operator==(const DynamicArray<T>& array) const{
        if(da_size != array.da_size)
            return false;

        for(int i=0; i < da_size; i++){
            if(da_data[i] != array.da_data[i])
                return false;
        }
        return true;
    }

    bool operator!=(const DynamicArray<T>& array) const{
        if(da_size != array.da_size)
            return true;

        for(int i=0; i < da_size; i++){
            if(da_data[i] != array.da_data[i])
                return true;
        }
        return false;
    }

    DynamicArray<T>& operator=(const DynamicArray<T>& array) {
        if (array.da_size <= 0){
            throw std::out_of_range("Error: Size can't be equal to or less than 0");
        }
        this.~DynamicArray();

        da_size = array.da_size;

        da_data = new T[da_size];
        for (int i=0; i < da_size; i++)
            da_data[i] = array.da_data[i];

        return *this;
    }


};


#endif //LAB2_DYNAMICARRAY_H


#endif //LAB4_DYNAMIC_ARRAY_H
