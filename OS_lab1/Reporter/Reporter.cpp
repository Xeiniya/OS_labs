#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

struct employee {
    int num;        // Идентификационный номер сотрудника
    char name[10];  // Имя сотрудника
    double hours;   // Количество отработанных часов
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: Reporter <binary file> <report file> <hourly rate>" << std::endl;
        return 1;
    }
    
    const char* binary_file = argv[1];
    const char* report_file = argv[2];
    double hourlyRate = std::stod(argv[3]);

    std::ifstream input_file(binary_file, std::ios::binary);
    if (!input_file) {
        std::cerr << "Error opening binary file!" << std::endl;
        return 1;
    }

    std::ofstream output_file(report_file);
    if (!output_file) {
        std::cerr << "Error opening report file!" << std::endl;
        return 1;
    }

    output_file << "File report \"" << binary_file << "\"\n";
    output_file << "Employee number\tEmployee name\ttimepiece\tSalary\n";

    employee emp;
    while (input_file.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        double salary = emp.hours * hourlyRate;
        output_file << emp.num << "\t\t" << emp.name << "\t\t" << emp.hours << "\t\t" << salary << "\n";
    }

    input_file.close();
    output_file.close();
    std::cout << "Report generated successfully." << std::endl;
    return 0;
}
