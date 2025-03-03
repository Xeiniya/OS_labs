#include <iostream>
#include <windows.h>  // Для работы с потоками и Sleep
#include <vector>
#include <limits>  // Для std::numeric_limits

// Глобальные переменные
std::vector<double> arr;       // Массив чисел
double min_val;                // Минимальное значение
double max_val;                // Максимальное значение
double average_val;         // Среднее арифметическое

// Мьютекс для синхронизации
HANDLE mutex;

DWORD WINAPI min_max(LPVOID lpParam) {
    
    min_val = arr[0];
    max_val = arr[0];

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        Sleep(7);
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        Sleep(7);
    }

    // Выводим результат
    std::cout << "Минимальное значение: " << min_val << std::endl;
    std::cout << "Максимальное значение: " << max_val << std::endl;

    return 0;
}

DWORD WINAPI average(LPVOID lpParam) {
    double sum = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        Sleep(12);
    }
    average_val = sum/ arr.size();

    // Выводим результат
    std::cout << "Среднее значение: " << average_val << std::endl;

    return 0;
}

int main() {
    setlocale(LC_ALL, "rus");

    // Инициализация мьютекса
   //mutex = CreateMutex(NULL, FALSE, NULL);  
   //мьютекс (механизм синхронизации) для предотвращения одновременного доступа к общим данным из разных потоков.

    // Ввод данных
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    arr.resize(n);
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Создаем потоки min_max и average
    HANDLE hMinMax = CreateThread(NULL, 0, min_max, NULL, 0, NULL);

    HANDLE hAverage = CreateThread(NULL, 0, average, NULL, 0, NULL); 
    // Ожидаем завершения потоков
    // Закрываем дескрипторы потоков
    WaitForSingleObject(hAverage, INFINITE);
    WaitForSingleObject(hMinMax, INFINITE);
    CloseHandle(hMinMax);             //атрибут безопастности, нач размер стека, имя функции, аргументы этой функции, флаги, куда пойдёт новый идентификатор
    CloseHandle(hAverage);

    // Замена минимального и максимального значения на среднее
    for (int i = 0; i < n; ++i) {
        if (arr[i] == min_val) {
            arr[i] = average_val;
        }
        if (arr[i] == max_val) {
            arr[i] = average_val;
        }
    }

    // Вывод модифицированного массива
    std::cout << "Измененный массив: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Закрытие мьютекса
    //CloseHandle(mutex);

    return 0;
}