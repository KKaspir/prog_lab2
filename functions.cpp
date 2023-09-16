#include "structs.cpp"
#include <iostream>
#include <vector>
#include <numeric>

// ОЦЕНКА
void printGrade(Grade grade) {
    std::cout << "Предмет: " << grade.subject << std::endl;
    std::cout << "Оценка: " << grade.score << std::endl;
    std::cout << "Дата: " << grade.date << std::endl;
}

// СТУДЕНТ
double avgGrade(Student structure) {
    if (structure.grades.empty()) {
        return 0.0; // Если нет оценок, средний балл равен 0
    }
    double totalScore = 0.0;
    for (const Grade grade : structure.grades) {
        totalScore += grade.score;
    }
    return totalScore / structure.grades.size();
}

void printStudent(Student student) {
    std::cout << "Имя: " << student.firstName << std::endl;
    std::cout << "Фамилия: " << student.lastName << std::endl;
    std::cout << "Дата рождения: " << student.dateOfBirth << std::endl;
    std::cout << "Номер студенческого билета: " << student.studentID << std::endl;
    std::cout << "Email: " << student.email << std::endl;

    std::cout << "\nОценки:" << std::endl;
    for (const Grade grade : student.grades) {
        std::cout << "Предмет: " << grade.subject << std::endl;
        std::cout << "Оценка: " << grade.score << std::endl;
        std::cout << "Дата: " << grade.date << std::endl;
        std::cout << std::endl; // Пустая строка для разделения оценок
    }
}

// КУРС
void printCourse(Course course) {
    std::cout << "Название курса: " << course.courseName << std::endl;
    std::cout << "Дата начала: " << course.startDate << std::endl;
    std::cout << "Дата окончания: " << course.endDate << std::endl;
    std::cout << "Предподаватель: " << course.instructor << std::endl;
}

// ПРОЕКТ
void printProject(Project project) {
    std::cout << "Название курса: " << project.courseName << std::endl;
    std::cout << "Дата начала: " << project.startDate << std::endl;
    std::cout << "Дата окончания: " << project.endDate << std::endl;
    std::cout << "Предподаватель: " << project.instructor << std::endl;

    std::cout << "\nУчастники:" << std::endl;
    for (const Student student : project.teamMembers) {
        std::cout << "Имя: " << student.firstName << student.lastName << std::endl;
        std::cout << std::endl; // Пустая строка для разделения оценок
    }
}





int main() {
    // Создаем студента и добавляем ему оценки
    Student student;
    student.firstName = "Иван";
    student.lastName = "Иванов";
    student.dateOfBirth = "01.01.2000";
    student.studentID = "12345";
    student.email = "ivan@ivav.com";

    Project project;
    project.projectName = "name";
    project.description = "description";
    project.startDate = "1";
    project.endDate = "1";
    project.teamMembers.push_back(student);



    // Добавляем оценки
    Grade mathGrade = {"Математика", 5.0, "20.09.2023"};
    Grade physicsGrade = {"Физика", 4.0, "20.09.2023"};
    student.grades.push_back(mathGrade);
    student.grades.push_back(physicsGrade);

    // Вызываем функцию avgGrade() и выводим результат
    double gpa = avgGrade(student);
    std::cout << "Средний балл студента: " << gpa << std::endl;

    printStudent(student);
    printProject(project);
}