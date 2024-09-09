#ifndef LAB4_STUDENT_H
#define LAB4_STUDENT_H

#include <string>


class Student{
private:
    std::size_t student_id;
    std::string first_name;
    std::string last_name;

    std::size_t group_number;

public:
    /*Student(const std::size_t id, const char name_1[20], const char name_2[20], const std::size_t g_number){
        student_id = id;
        strcpy(first_name, name_1);
        strcpy(last_name, name_2);
        group_number = g_number;
    }*/

    void AssignID(const std::size_t id){
        student_id = id;
    }

    void AssignFirstName(std::string name_1){
       first_name = name_1;
    }

    void AssignLastName(std::string name_2){
        last_name = name_2;
    }

    void AssignGroupNumber(const std::size_t g_number){
        group_number = g_number;
    }


    std::size_t GetID() const{
        return student_id;
    }

    std::string GetFirstName() const{
        return first_name;
    }

    std::string GetLastName() const{
        return last_name;
    }

    std::size_t GetGroupNumber() const{
        return group_number;
    }

    bool operator==(const Student& student){
        if(student_id == student.student_id && first_name == student.first_name && last_name == student.last_name && group_number == student.group_number){
            return true;
        }

        return false;
    }

};


#endif //LAB4_STUDENT_H
