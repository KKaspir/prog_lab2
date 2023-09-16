#include <iostream>
#include <vector>
#include <numeric>


// ################ СТРУКТУРЫ ################
// ОЦЕНКА
struct Grade {
    std::string subject;
    double score;
    std::string date;
};

// СТУДЕНТ
struct Student {
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    std::string studentID;
    std::string email;
    std::vector<Grade> grades;
};

// КУРС
struct Course {
    std::string courseName;
    std::string startDate;
    std::string endDate;
    std::string instructor;
};

// ПРОЕКТ
struct Project {
    std::string projectName;
    std::string description;
    std::string startDate;
    std::string endDate;
    std::vector<Student> teamMembers; // Вектор студентов, участвующих в проекте
};

// EVENT
struct Event {
    std::string eventName;
    std::string date;
    std::string location;
    std::vector<Student> eventMembers;
};


