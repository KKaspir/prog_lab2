#include "structs.cpp"
#include <iostream>
#include <vector>
#include <numeric>

// ОЦЕНКА
// Вывод в консоль
void printGrade(const std::vector<Grade>& grades) {
    for (const Grade grade : grades){
        std::cout << "Предмет: " << grade.subject << std::endl;
        std::cout << "Оценка: " << grade.score << std::endl;
        std::cout << "Дата: " << grade.date << std::endl;
        std::cout << std::endl;
    }
}

Grade initializeGrade(
        const std::string& subject,
        double score,
        const std::string& date
) {
    Grade grade;
    grade.subject = subject;
    grade.score = score;
    grade.date = date;

    return grade;
}

void initializeGrades(Student& student, const std::vector<Grade>& initialGrades) {
    student.grades = initialGrades;
}

// СТУДЕНТ
// Рассчет средней оценки
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

// Функуия инициализации
Student initializeStudent(
        const std::string& firstName,
        const std::string& lastName,
        const std::string& dateOfBirth,
        const std::string& studentID,
        const std::string& email,
        const std::vector<Grade>& grades
) {
    Student student;
    student.firstName = firstName;
    student.lastName = lastName;
    student.dateOfBirth = dateOfBirth;
    student.studentID = studentID;
    student.email = email;
    student.grades = grades;

    return student;
}

// Вывод в консоль
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
// Вывод в консоль
void printCourse(Course course) {
    std::cout << "Название курса: " << course.courseName << std::endl;
    std::cout << "Дата начала: " << course.startDate << std::endl;
    std::cout << "Дата окончания: " << course.endDate << std::endl;
    std::cout << "Предподаватель: " << course.instructor << std::endl;
}

Course initializeCourse(
        const std::string& courseName,
        const std::string& startDate,
        const std::string& endDate,
        const std::string& instructor
) {
    Course course;
    course.courseName = courseName;
    course.startDate = startDate;
    course.endDate = endDate;
    course.instructor = instructor;

    return course;
}

// ПРОЕКТ
// Вывод в консоль
void printProject(Project project) {
    std::cout << "Название проекта: " << project.projectName << std::endl;
    std::cout << "Описание: " << project.description << std::endl;
    std::cout << "Дата начала: " << project.startDate << std::endl;
    std::cout << "Дата окончания: " << project.endDate << std::endl;

    std::cout << "\nУчастники:" << std::endl;
    for (const Student student : project.teamMembers) {
        std::cout << "Имя: " << student.firstName << " " << student.lastName << std::endl;
    }
}

Project initializeProject(
        const std::string& projectName,
        const std::string& description,
        const std::string& startDate,
        const std::string& endDate,
        const std::vector<Student> teamMembers
) {
    Project project;
    project.projectName = projectName;
    project.startDate = startDate;
    project.endDate = endDate;
    project.description = description;
    project.teamMembers = teamMembers;

    return project;
}

// EVENT
// Вывод в консоль
void printEvent(Event event) {
    std::cout << "Название мероприятия: " << event.eventName << std::endl;
    std::cout << "Дата: " << event.date << std::endl;
    std::cout << "Место проведения: " << event.location << std::endl;

    std::cout << "\nУчастники:" << std::endl;
    for (const Student student : event.eventMembers) {
        std::cout << "Имя: " << student.firstName << " " << student.lastName << std::endl;
        std::cout << std::endl; // Пустая строка для разделения оценок
    }
}

Event initializeEvent(
                    const std::string& eventName,
                    const std::string& date,
                    const std::string& location,
                    const std::vector<Student>& eventMembers) {
    Event event;
    event.eventName = eventName;
    event.date = date;
    event.location = location;
    event.eventMembers = eventMembers;

    return event;
}


int main() {
    // Создаем студента и добавляем ему оценки
    std::vector<Grade> studentGrades = {
            {"Математика", 5.0, "20.09.2023"},
            {"Физика",     4.5, "20.09.2023"}
    };
    Student student = initializeStudent(
            "Иван",
            "Иванов",
            "01.01.2000",
            "12345",
            "ivan@example.com",
            studentGrades
    );
    Student student2 = initializeStudent(
            "Петр",
            "Петров",
            "01.01.2000",
            "12345",
            "ivan@example.com",
            studentGrades
    );
    Project project = initializeProject(
            "name",
            "description",
            "1",
            " 1",
            {student, student2}
            );
//    project.projectName = "name";
//    project.description = "description";
//    project.startDate = "1";
//    project.endDate = "1";
//    project.teamMembers.push_back(student);

    Course course = initializeCourse(
            "Программирование",
            "01.01.2001",
            "10.10.2001",
            "Троицкий"
            );

    Event event = initializeEvent(
                    "Конференция",
                    "20.10.2023",
                    "Конференц-зал",
                    {student, student2});

    std::cout << "Вызов printGrade\n" << std::endl;
    printGrade(studentGrades);
    std::cout << std::endl;

    std::cout << "Вызов printStudent\n" << std::endl;
    printStudent(student);
    std::cout << std::endl;

    double gpa = avgGrade(student);
    std::cout << "Средний балл студента: " << gpa << std::endl;
    std::cout << std::endl;

    std::cout << "Вызов printProject\n" << std::endl;
    printProject(project);
    std::cout << std::endl;

    std::cout << "Вызов printCourse\n" << std::endl;
    printCourse(course);
    std::cout << std::endl;

    std::cout << "Вызов printEvent\n" << std::endl;
    printEvent(event);
    std::cout << std::endl;
}












