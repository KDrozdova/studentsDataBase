#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;

    //Функция сравнения по всем полям
    bool operator==(const Student& other) const{
        return name == other.name && age == other.age && major == other.major && gpa == other.gpa;
    }
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}


//Функция нахождения дубликатов в базе данных
void dublicat(const std::vector<Student>& database){
    bool duplicatesFound = false; // Флаг, чтобы отслеживать наличие дубликатов

    std::cout << "Дубликаты в базе данных:\n";
    for (size_t i = 0; i < database.size(); ++i) {
        for (size_t j = i + 1; j < database.size(); ++j) {
            if (database[i] == database[j]) {
                // Найден дубликат
                std::cout << "Дубликаты:\n";
                std::cout << "Имя: " << database[i].name << "\n";
                std::cout << "Возраст: " << database[i].age << "\n";
                std::cout << "Специальность: " << database[i].major << "\n";
                std::cout << "Средний балл: " << database[i].gpa << "\n";
                std::cout << "Имя: " << database[j].name << "\n";
                std::cout << "Возраст: " << database[j].age << "\n";
                std::cout << "Специальность: " << database[j].major << "\n";
                std::cout << "Средний балл: " << database[j].gpa << "\n\n";
                duplicatesFound = true;
            }
        }
    }
    if (!duplicatesFound) {
        std::cout << "Дубликатов нет.\n";
    }
}

void testStudentComparisonAndDuplicates() {
    std::cout << "Тест 1: Поиск дубликатов в пустой базе данных\n";
    std::vector<Student> emptyDatabase;
    dublicat(emptyDatabase);
    std::cout << "\n";

    std::cout << "Тест 2: Поиск дубликатов с одним студентом в базе данных\n";
    std::vector<Student> singleStudentDatabase;
    Student student1 = {"Alice", 20, "Computer Science", 3.5};
    singleStudentDatabase.push_back(student1);
    dublicat(singleStudentDatabase);
    std::cout << "\n";

    std::cout << "Тест 3: Поиск дубликатов с разными студентами в базе данных\n";
    std::vector<Student> multipleStudentsDatabase;
    Student student2 = {"Bob", 22, "Mathematics", 3.2};
    Student student3 = {"Alice", 20, "Computer Science", 3.5};
    multipleStudentsDatabase.push_back(student2);
    multipleStudentsDatabase.push_back(student3);
    dublicat(multipleStudentsDatabase);
    std::cout << "\n";

    std::cout << "Тест 4: Поиск дубликатов с несколькими дубликатами в базе данных\n";
    std::vector<Student> duplicateStudentsDatabase;
    Student student4 = {"Eve", 21, "Physics", 3.8};
    duplicateStudentsDatabase.push_back(student2);
    duplicateStudentsDatabase.push_back(student3);
    duplicateStudentsDatabase.push_back(student4);
    duplicateStudentsDatabase.push_back(student2);
    dublicat(duplicateStudentsDatabase);
    std::cout << "\n";

    std::cout << "Тест 5: Поиск дубликатов с разными студентами в базе данных без дубликатов\n";
    std::vector<Student> uniqueStudentsDatabase;
    uniqueStudentsDatabase.push_back(student2);
    uniqueStudentsDatabase.push_back(student4);
    dublicat(uniqueStudentsDatabase);
    std::cout << "\n";
}


int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> database;
    testStudentComparisonAndDuplicates();
    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "16. Поиск дубликатов\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 16:
                dublicat(database);
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
