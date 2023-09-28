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

    static Grade inputFromConsole() {
        std::string subject;
        double score;
        std::string date;

        std::cout << "Введите предмет: ";
        std::cin >> subject;
        std::cout << "Введите оценку: ";
        std::cin >> score;
        std::cout << "Введите дату: ";
        std::cin >> date;

        return Grade(subject, score, date);
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

    static Student inputFromConsole() {
        std::string first, last, dob, id, mail;
        std::vector<Grade> grades;

        std::cout << "Введите имя: ";
        std::cin >> first;
        std::cout << "Введите фамилию: ";
        std::cin >> last;
        std::cout << "Введите дату рождения: ";
        std::cin >> dob;
        std::cout << "Введите номер студенческого билета: ";
        std::cin >> id;
        std::cout << "Введите email: ";
        std::cin >> mail;

        char addGrade;
        do {
            Grade grade = Grade::inputFromConsole();
            grades.push_back(grade);

            std::cout << "Добавить еще одну оценку? (y/n): ";
            std::cin >> addGrade;
        } while (addGrade == 'y' || addGrade == 'Y');

        return Student(first, last, dob, id, mail, grades);
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

    static Project inputFromConsole() {
        std::string name, desc, start, end;
        std::vector<Student> members;

        std::cout << "Введите название проекта: ";
        std::cin >> name;
        std::cout << "Введите описание проекта: ";
        std::cin >> desc;
        std::cout << "Введите дату начала: ";
        std::cin >> start;
        std::cout << "Введите дату окончания: ";
        std::cin >> end;

        char addMember;
        do {
            Student student = Student::inputFromConsole();
            members.push_back(student);

            std::cout << "Добавить еще одного участника? (y/n): ";
            std::cin >> addMember;
        } while (addMember == 'y' || addMember == 'Y');

        return Project(name, desc, start, end, members);
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

    static Event inputFromConsole() {
        std::string name, date, location;
        std::vector<Student> members;

        std::cout << "Введите название мероприятия: ";
        std::cin >> name;
        std::cout << "Введите дату мероприятия: ";
        std::cin >> date;
        std::cout << "Введите место проведения мероприятия: ";
        std::cin >> location;

        char addParticipant;
        do {
            Student student = Student::inputFromConsole();
            members.push_back(student);

            std::cout << "Добавить еще одного участника мероприятия? (y/n): ";
            std::cin >> addParticipant;
        } while (addParticipant == 'y' || addParticipant == 'Y');

        return Event(name, date, location, members);
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

    static Course inputFromConsole() {
        std::string name, start, end, instructor;
        std::vector<Event> events;

        std::cout << "Введите название курса: ";
        std::cin >> name;
        std::cout << "Введите дату начала курса: ";
        std::cin >> start;
        std::cout << "Введите дату окончания курса: ";
        std::cin >> end;
        std::cout << "Введите имя предподавателя: ";
        std::cin >> instructor;

        char addEvent;
        do {
            Event event = Event::inputFromConsole();
            events.push_back(event);

            std::cout << "Добавить еще одно мероприятие курса? (y/n): ";
            std::cin >> addEvent;
        } while (addEvent == 'y' || addEvent == 'Y');

        return Course(name, start, end, instructor, events);
    }
};


int main() {
    Grade few("Математика", 5.0, "20.09.2023");

    std::vector<Grade> studentGrades = {
            Grade("Математика", 5.0, "20.09.2023"),
            Grade("Физика", 4.5, "20.09.2023")
    };



    Student student("Иван", "Иванов", "01.01.2000", "12345", "ivan@example.com", studentGrades);

    Project project("name", "description", "1", "1", {student});
    Student student3("Третий", "Студент", "03.03.2003", "33333", "student3@example.com", {});
    project.addTeamMember(student3);

    Course course("Программирование", "01.01.2001", "10.10.2001", "Троицкий", {});
    Event event("Конференция", "20.10.2023", "Конференц-зал", {student});
    course.addEvent(event);
    Event event2("Семинар", "25.10.2023", "Аудитория 101", {student3});
    course.addEvent(event2);


    std::cout << "Вызов printStudent\n" << std::endl;
    student.print();
    std::cout << std::endl;

    double gpa = student.avgGrade();
    std::cout << "Средний балл студента: " << gpa << std::endl;
    std::cout << std::endl;

    std::cout << "Вызов printProject\n" << std::endl;
    project.print();
    std::cout << std::endl;

    std::cout << "Вызов printProject после добавления 3 студента\n" << std::endl;
    project.addTeamMember(student3);
    project.print();
    std::cout << std::endl;

    std::cout << "Вызов printCourse\n" << std::endl;
    course.print();
    std::cout << std::endl;

    std::cout << "Вызов printCourse с новым event\n" << std::endl;
    course.addEvent(event2);
    course.print();
    std::cout << std::endl;

    std::cout << "Вызов printEvent\n" << std::endl;
    event.print();
    std::cout << std::endl;

    Grade grade123123 = grade123123.inputFromConsole();
    grade123123.print();

    return 0;
};

