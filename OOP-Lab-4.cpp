#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>

using namespace std;

class Person
{
protected:
    string name;
    int id;

public:
    Person()
    {
        name = "Unknown";
        id = 0;
    }

    Person(string name, int id)
    {
        this->name = name;
        this->id = id;
    }

    Person(const Person& other)
    {
        name = other.name;
        id = other.id;
    }

    virtual ~Person()
    {
        cout << "Деструктор Person: " << name << endl;
    }

    virtual void showInfo() const
    {
        cout << "Ім'я: " << name << endl;
        cout << "ID: " << id << endl;
    }

    string getName() const
    {
        return name;
    }

    int getId() const
    {
        return id;
    }

    void setName(string newName)
    {
        name = newName;
    }

    void setId(int newId)
    {
        id = newId;
    }
};

class Student : public Person
{
private:
    string group;
    double averageGrade;

public:
    Student() : Person()
    {
        group = "Unknown";
        averageGrade = 0.0;
    }

    Student(string name, int id, string group, double averageGrade)
        : Person(name, id)
    {
        this->group = group;
        this->averageGrade = averageGrade;
    }

    Student(const Student& other)
        : Person(other)
    {
        group = other.group;
        averageGrade = other.averageGrade;
    }

    ~Student() override
    {
        cout << "Деструктор Student: " << name << endl;
    }

    void showInfo() const override
    {
        cout << "----- Студент -----" << endl;
        cout << "Ім'я: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Група: " << group << endl;
        cout << "Середній бал: " << averageGrade << endl;
    }

    void study() const
    {
        cout << name << " навчається на курсі." << endl;
    }

    string getGroup() const
    {
        return group;
    }

    void setGroup(string newGroup)
    {
        group = newGroup;
    }

    double getAverageGrade() const
    {
        return averageGrade;
    }

    void setAverageGrade(double grade)
    {
        averageGrade = grade;
    }
};

class Teacher : public Person
{
private:
    string department;
    int experience;

public:
    Teacher() : Person()
    {
        department = "Unknown";
        experience = 0;
    }

    Teacher(string name, int id, string department, int experience)
        : Person(name, id)
    {
        this->department = department;
        this->experience = experience;
    }

    Teacher(const Teacher& other)
        : Person(other)
    {
        department = other.department;
        experience = other.experience;
    }

    ~Teacher() override
    {
        cout << "Деструктор Teacher: " << name << endl;
    }

    void showInfo() const override
    {
        cout << "----- Викладач -----" << endl;
        cout << "Ім'я: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Кафедра: " << department << endl;
        cout << "Стаж: " << experience << " років" << endl;
    }

    void announceCourse(string courseName) const
    {
        cout << "Викладач " << name
            << " оголошує курс: " << courseName << endl;
    }

    void setGrade(string studentName, int grade) const
    {
        cout << "Викладач " << name
            << " виставив студенту " << studentName
            << " оцінку " << grade << endl;
    }

    void uploadMaterial(string materialName) const
    {
        cout << "Викладач " << name
            << " завантажив матеріал: "
            << materialName << endl;
    }

    string getDepartment() const
    {
        return department;
    }

    void setDepartment(string newDepartment)
    {
        department = newDepartment;
    }
};

class Semester
{
private:
    string name;
    string startDate;
    string endDate;

public:
    Semester()
    {
        name = "Невідомий";
        startDate = "--";
        endDate = "--";
    }

    Semester(string name, string startDate, string endDate)
    {
        this->name = name;
        this->startDate = startDate;
        this->endDate = endDate;
    }

    Semester(const Semester& other)
    {
        name = other.name;
        startDate = other.startDate;
        endDate = other.endDate;
    }

    ~Semester()
    {
        cout << "Деструктор Semester: " << name << endl;
    }

    void showInfo() const
    {
        cout << "----- Семестр -----" << endl;
        cout << "Назва: " << name << endl;
        cout << "Початок: " << startDate << endl;
        cout << "Кінець: " << endDate << endl;
    }

    string getName() const
    {
        return name;
    }

    void setName(string newName)
    {
        name = newName;
    }

    string getStartDate() const
    {
        return startDate;
    }

    string getEndDate() const
    {
        return endDate;
    }

    void setDates(string start, string end)
    {
        startDate = start;
        endDate = end;
    }
};

class Material
{
private:
    string title;
    string type;
    string description;

public:
    Material()
    {
        title = "Без назви";
        type = "Невідомий";
        description = "";
    }

    Material(string title, string type, string description)
    {
        this->title = title;
        this->type = type;
        this->description = description;
    }

    Material(const Material& other)
    {
        title = other.title;
        type = other.type;
        description = other.description;
    }

    ~Material()
    {
        cout << "Деструктор Material: " << title << endl;
    }

    void showInfo() const
    {
        cout << "----- Матеріал -----" << endl;
        cout << "Назва: " << title << endl;
        cout << "Тип: " << type << endl;
        cout << "Опис: " << description << endl;
    }

    string getTitle() const
    {
        return title;
    }

    string getType() const
    {
        return type;
    }

    string getDescription() const
    {
        return description;
    }

    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setType(string newType)
    {
        type = newType;
    }

    void setDescription(string newDescription)
    {
        description = newDescription;
    }
};

class Schedule
{
private:
    string day;
    string time;
    string room;

public:
    Schedule()
    {
        day = "Невідомо";
        time = "--:--";
        room = "Невідомо";
    }

    Schedule(string day, string time, string room)
    {
        this->day = day;
        this->time = time;
        this->room = room;
    }

    Schedule(const Schedule& other)
    {
        day = other.day;
        time = other.time;
        room = other.room;
    }

    ~Schedule()
    {
        cout << "Деструктор Schedule" << endl;
    }

    void showInfo() const
    {
        cout << "----- Розклад -----" << endl;
        cout << "День: " << day << endl;
        cout << "Час: " << time << endl;
        cout << "Аудиторія: " << room << endl;
    }

    string getDay() const
    {
        return day;
    }

    string getTime() const
    {
        return time;
    }

    string getRoom() const
    {
        return room;
    }

    void setDay(string newDay)
    {
        day = newDay;
    }

    void setTime(string newTime)
    {
        time = newTime;
    }

    void setRoom(string newRoom)
    {
        room = newRoom;
    }
};

class Course
{
private:
    string name;
    Teacher* teacher;
    Semester* semester;
    vector<Material> materials;
    vector<Schedule> schedules;

public:
    Course()
    {
        name = "Без назви";
        teacher = nullptr;
        semester = nullptr;
    }

    Course(string name, Teacher* teacher, Semester* semester)
    {
        this->name = name;
        this->teacher = teacher;
        this->semester = semester;
    }

    Course(const Course& other)
    {
        name = other.name;
        teacher = other.teacher;
        semester = other.semester;
        materials = other.materials;
        schedules = other.schedules;
    }

    ~Course()
    {
        cout << "Деструктор Course: " << name << endl;
    }

    void showInfo() const
    {
        cout << "----- Курс -----" << endl;
        cout << "Назва: " << name << endl;

        if (teacher != nullptr)
            cout << "Викладач: " << teacher->getName() << endl;

        if (semester != nullptr)
            cout << "Семестр: " << semester->getName() << endl;

        cout << "Кількість матеріалів: "
            << materials.size() << endl;

        cout << "Кількість занять: "
            << schedules.size() << endl;
    }

    void addMaterial(const Material& material)
    {
        materials.push_back(material);
    }

    void addSchedule(const Schedule& schedule)
    {
        schedules.push_back(schedule);
    }

    void setTeacher(Teacher* newTeacher)
    {
        teacher = newTeacher;
    }

    void setSemester(Semester* newSemester)
    {
        semester = newSemester;
    }

    string getName() const
    {
        return name;
    }

    void setName(string newName)
    {
        name = newName;
    }

    void showMaterials() const
    {
        cout << "\nМатеріали курсу:\n";

        for (const auto& material : materials)
        {
            material.showInfo();
            cout << endl;
        }
    }

    void showSchedule() const
    {
        cout << "\nРозклад курсу:\n";

        for (const auto& schedule : schedules)
        {
            schedule.showInfo();
            cout << endl;
        }
    }
};

class Grade
{
private:
    Student* student;
    Course* course;
    int value;

public:
    Grade()
    {
        student = nullptr;
        course = nullptr;
        value = 0;
    }

    Grade(Student* student, Course* course, int value)
    {
        this->student = student;
        this->course = course;
        this->value = value;
    }

    Grade(const Grade& other)
    {
        student = other.student;
        course = other.course;
        value = other.value;
    }

    ~Grade()
    {
        cout << "Деструктор Grade" << endl;
    }

    void showInfo() const
    {
        cout << "----- Оцінка -----" << endl;

        if (student != nullptr)
            cout << "Студент: "
            << student->getName() << endl;

        if (course != nullptr)
            cout << "Курс: "
            << course->getName() << endl;

        cout << "Оцінка: " << value << endl;
    }

    int getValue() const
    {
        return value;
    }

    void setValue(int newValue)
    {
        value = newValue;
    }

    Student* getStudent() const
    {
        return student;
    }

    Course* getCourse() const
    {
        return course;
    }

    void setStudent(Student* newStudent)
    {
        student = newStudent;
    }

    void setCourse(Course* newCourse)
    {
        course = newCourse;
    }
};

class Archive
{
private:
    vector<Grade> grades;

public:
    Archive()
    {}

    Archive(const vector<Grade>& grades)
    {
        this->grades = grades;
    }

    Archive(const Archive& other)
    {
        grades = other.grades;
    }

    ~Archive()
    {
        cout << "Деструктор Archive" << endl;
    }

    void addGrade(const Grade& grade)
    {
        grades.push_back(grade);
    }

    void showInfo() const
    {
        cout << "\n===== АРХІВ ОЦІНОК =====\n";

        for (const auto& grade : grades)
        {
            grade.showInfo();
            cout << endl;
        }
    }

    double calculateAverage(Student* student) const
    {
        double sum = 0;
        int count = 0;

        for (const auto& grade : grades)
        {
            if (grade.getStudent() == student)
            {
                sum += grade.getValue();
                count++;
            }
        }

        if (count == 0)
            return 0;

        return sum / count;
    }

    int getGradeCount() const
    {
        return grades.size();
    }

    void clear()
    {
        grades.clear();
    }

    void showRating(Student* students[], int count) const
    {
        cout << "\n===== РЕЙТИНГ СТУДЕНТІВ =====\n";

        for (int i = 0; i < count; i++)
        {
            cout << students[i]->getName()
                << " : "
                << fixed << setprecision(2)
                << calculateAverage(students[i])
                << endl;
        }
    }
};

int main()
{   
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "========================================\n";
    cout << "      СИСТЕМА ФАКУЛЬТАТИВ\n";
    cout << "========================================\n\n";

    Teacher teacher1(
        "Іваненко Олександр",
        101,
        "Комп'ютерних наук",
        10
    );

    Teacher teacher2(
        "Петренко Олена",
        102,
        "Інформаційних технологій",
        7
    );

    Student student1(
        "Коваленко Андрій",
        201,
        "КН-21",
        0
    );

    Student student2(
        "Шевченко Марія",
        202,
        "КН-21",
        0
    );

    Student student3(
        "Мельник Ігор",
        203,
        "КН-22",
        0
    );

    Semester semester(
        "Осінній семестр 2026",
        "01.09.2026",
        "31.12.2026"
    );

    Course programmingCourse(
        "Програмування на C++",
        &teacher1,
        &semester
    );

    Course databaseCourse(
        "Бази даних",
        &teacher2,
        &semester
    );

    Material presentation(
        "Лекція 1. Основи C++",
        "Презентація",
        "Основи мови програмування C++"
    );

    Material article(
        "ООП у C++",
        "Стаття",
        "Основні принципи об'єктно-орієнтованого програмування"
    );

    Material task(
        "Практична робота №1",
        "Завдання",
        "Створення класів та об'єктів"
    );

    programmingCourse.addMaterial(presentation);
    programmingCourse.addMaterial(article);
    programmingCourse.addMaterial(task);

    Schedule schedule1(
        "Понеділок",
        "10:00",
        "301"
    );

    Schedule schedule2(
        "Середа",
        "12:00",
        "305"
    );

    programmingCourse.addSchedule(schedule1);
    programmingCourse.addSchedule(schedule2);

    teacher1.announceCourse(
        programmingCourse.getName()
    );

    cout << endl;

    student1.study();
    student2.study();
    student3.study();

    cout << endl;

    teacher1.uploadMaterial(
        presentation.getTitle()
    );

    teacher1.uploadMaterial(
        task.getTitle()
    );

    cout << endl;

    teacher1.showInfo();
    cout << endl;

    student1.showInfo();
    cout << endl;

    semester.showInfo();
    cout << endl;

    programmingCourse.showInfo();
    cout << endl;

    programmingCourse.showMaterials();
    programmingCourse.showSchedule();

    Grade grade1(
        &student1,
        &programmingCourse,
        95
    );

    Grade grade2(
        &student2,
        &programmingCourse,
        88
    );

    Grade grade3(
        &student3,
        &programmingCourse,
        76
    );

    teacher1.setGrade(
        student1.getName(),
        grade1.getValue()
    );

    teacher1.setGrade(
        student2.getName(),
        grade2.getValue()
    );

    teacher1.setGrade(
        student3.getName(),
        grade3.getValue()
    );

    Archive archive;

    archive.addGrade(grade1);
    archive.addGrade(grade2);
    archive.addGrade(grade3);

    archive.showInfo();

    Student* students[] =
    {
        &student1,
        &student2,
        &student3
    };

    archive.showRating(students, 3);

    cout << "\n===== КОПІЮВАННЯ ОБ'ЄКТІВ =====\n";

    Student studentCopy(student1);

    cout << "\nКопія студента:\n";
    studentCopy.showInfo();

    Teacher teacherCopy(teacher1);

    cout << "\nКопія викладача:\n";
    teacherCopy.showInfo();

    cout << "\n========================================\n";
    cout << "Програма завершена.\n";
    cout << "========================================\n";

    return 0;
}

