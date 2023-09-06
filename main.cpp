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
                
            }
        }
    }
}

int main() {
    std::vector<Student> database;

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
