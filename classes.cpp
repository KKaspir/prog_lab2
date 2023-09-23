#include <iostream>
#include <vector>
#include <numeric>

class Grade {
public:
    std::string subject;
    double score;
    std::string date;

    Grade(const std::string& subj, double scr, const std::string& dt)
            : subject(subj), score(scr), date(dt) {}

    void print() const {
        std::cout << "Предмет: " << subject << std::endl;
        std::cout << "Оценка: " << score << std::endl;
        std::cout << "Дата: " << date << std::endl;
    }
};

class Student {
public:
    std::string firstName;
    std::string lastName;
    std::string dateOfBirth;
    std::string studentID;
    std::string email;
    std::vector<Grade> grades;

    Student(
            const std::string& first,
            const std::string& last,
            const std::string& dob,
            const std::string& id,
            const std::string& mail,
            const std::vector<Grade>& gr
    ) : firstName(first), lastName(last), dateOfBirth(dob), studentID(id), email(mail), grades(gr) {}

    double avgGrade() const {
        if (grades.empty()) {
            return 0.0;
        }
        double totalScore = 0.0;
        for (const Grade& grade : grades) {
            totalScore += grade.score;
        }
        return totalScore / grades.size();
    }

    void print() const {
        std::cout << "Имя: " << firstName << std::endl;
        std::cout << "Фамилия: " << lastName << std::endl;
        std::cout << "Дата рождения: " << dateOfBirth << std::endl;
        std::cout << "Номер студенческого билета: " << studentID << std::endl;
        std::cout << "Email: " << email << std::endl;

        std::cout << "\nОценки:" << std::endl;
        for (const Grade& grade : grades) {
            grade.print();
            std::cout << std::endl;
        }
    }
};

class Project {
public:
    std::string projectName;
    std::string description;
    std::string startDate;
    std::string endDate;
    std::vector<Student> teamMembers;

    Project(
            const std::string& name,
            const std::string& desc,
            const std::string& start,
            const std::string& end,
            const std::vector<Student>& members
    ) : projectName(name), description(desc), startDate(start), endDate(end), teamMembers(members) {}

    void addTeamMember(const Student& student) {
        teamMembers.push_back(student);
    }

    void print() const {
        std::cout << "Название проекта: " << projectName << std::endl;
        std::cout << "Описание: " << description << std::endl;
        std::cout << "Дата начала: " << startDate << std::endl;
        std::cout << "Дата окончания: " << endDate << std::endl;

        std::cout << "\nУчастники:" << std::endl;
        for (const Student& student : teamMembers) {
            std::cout << "Имя: " << student.firstName << " " << student.lastName << std::endl;
        }
    }
};

class Event {
public:
    std::string eventName;
    std::string date;
    std::string location;
    std::vector<Student> eventMembers;

    Event(
            const std::string& name,
            const std::string& dt,
            const std::string& loc,
            const std::vector<Student>& members
    ) : eventName(name), date(dt), location(loc), eventMembers(members) {}

    void addParticipant(const Student& student) {
        eventMembers.push_back(student);
    }

    void print() const {
        std::cout << "Название мероприятия: " << eventName << std::endl;
        std::cout << "Дата: " << date << std::endl;
        std::cout << "Место проведения: " << location << std::endl;

        std::cout << "\nУчастники:" << std::endl;
        for (const Student& student : eventMembers) {
            std::cout << "Имя: " << student.firstName << " " << student.lastName << std::endl;
        }
    }
};

class Course {
public:
    std::string courseName;
    std::string startDate;
    std::string endDate;
    std::string instructor;
    std::vector<Event> events;

    Course(
            const std::string& name,
            const std::string& start,
            const std::string& end,
            const std::string& instr,
            const std::vector<Event>& evts
    ) : courseName(name), startDate(start), endDate(end), instructor(instr), events(evts) {}

    void addEvent(const Event& event) {
        events.push_back(event);
    }

    void print() const {
        std::cout << "Название курса: " << courseName << std::endl;
        std::cout << "Дата начала: " << startDate << std::endl;
        std::cout << "Дата окончания: " << endDate << std::endl;
        std::cout << "Предподаватель: " << instructor << std::endl;

        std::cout << "Мероприятия: " << std::endl;
        for (const Event& event : events) {
            std::cout << "Название: " << event.eventName << std::endl;
        }
    }
};
