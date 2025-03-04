#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

std::wstring stringToWString(const std::string& str) {

    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0); // конвертируем строку в UTF-8 в широкую строку (UTF-16) и получаем размер
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

void printBinaryFile(const char* filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening binary file!" << std::endl;
        return;
    }

    struct employee {
        int num;
        char name[10];
        double hours;
    };

    employee emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(emp))) {
        std::cout << "Employee Number: " << emp.num << ", Name: " << emp.name
            << ", Hours Worked: " << emp.hours << std::endl;
    }

    inFile.close();
}

void printReportFile(const char* filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening report file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
}

int main() {
    

    setlocale(LC_ALL, "rus");

    std::string binary_file, report_file;
    int recordCount;
    double hourlyRate;

    // 1 Запрашиваем с консоли имя бинарного файла и количество записей в этом файле
    std::cout << "Enter the name of the binary file: ";
    std::cin >> binary_file;
    std::cout << "Enter the number of records: ";
    std::cin >> recordCount;

    binary_file = binary_file + ".bin";

    // 2 Запускаем утилиту Creator
    STARTUPINFO si = { sizeof(STARTUPINFO) }; 
    PROCESS_INFORMATION pi; 

    std::string creatorCmd = "Creator " + binary_file + " " + std::to_string(recordCount);

    std::wstring wCreatorCmd = stringToWString(creatorCmd);

    if (!CreateProcess(NULL, const_cast<wchar_t*>(wCreatorCmd.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
    {
        std::cerr << "Failed to launch Creator process!" << std::endl;
        return 1;
    }

    // 3 Ждем завершения работы утилиты Creator
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess); //дескриптор нового процесса
    CloseHandle(pi.hThread); //дескриптор основного потока нового процесса.

    // 4 Выводим содержимое созданного бинарного файла на консоль
    std::cout << "Contents of the binary file:" << std::endl;
    printBinaryFile(binary_file.c_str());

    // 5 Запрашивает с консоли: Имя файла отчета, Оплату за час работы
    std::cout << "Enter the name of the report file: ";
    std::cin >> report_file;
    std::cout << "Enter the hourly rate: ";
    std::cin >> hourlyRate;

    report_file = report_file + ".txt";

    // 6 Запускаем утилиту Reporter, которой передаем через командную строку: Имя исходного бинарного файла, Имя файла отчета, Оплату за час работы
    std::string reporterCmd = "Reporter " + binary_file + " " + report_file + " " + std::to_string(hourlyRate);
    std::wstring wreporterCmd = stringToWString(reporterCmd);

    if (!CreateProcess(NULL, const_cast<wchar_t*>(wreporterCmd.c_str()), NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cerr << "Failed to launch Reporter process!" << std::endl;
        return 1;
    }

    // 7 Ждем завершения работы утилиты Reporter
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    // 8 Выводим отчет на консоль
    std::cout << "Report contents:" << std::endl;
    printReportFile(report_file.c_str());

    // 9 Завершаем свою работу
    return 0;
}
