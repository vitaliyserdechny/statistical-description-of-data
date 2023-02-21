#include <iostream>
#include "data_mining_utils.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "ИАД. Статическое описание данных" << endl;
    cout << "Автор: Сердечный В.С." << endl;
    cout << "Харьковский технологический университет, 2023\n\n";

    const int data_size = 12;
    int data[data_size];

    rand_integer_data(data, data_size, 1000, 2000);
    cout << "Исходные данные (зарплаты работников): ";
    print_integer_data(data, data_size);

    cout << "\n\n1. Измерение центральной тенденции:";
    cout << "\n\nСреднее арифметическое: " << arithmetic_mean(data, data_size) << endl;
    cout << "Обрезанное среднее арифметическое: " << trimmed_mean(data, data_size) << endl;

    cout << "\nСортируем данные..." << endl;
    cout << "Результат: ";
    sort(data, data_size);
    print_integer_data(data, data_size);

    cout << "\n\nМедиана: " << median(data, data_size) << endl;

    std::vector<int> m_d;
    int freq = 0;
    if (mode(data, data_size, m_d, freq))
    {
        cout << "Мода: ";
        for (int i = 0; i < m_d.size(); i++)
            cout << m_d.at(i) << " ";
        cout << " (" << freq << " раз)" << endl;
    }
    else
        cout << "Мода не обнаружена!\n";

    cout << "Усредненный диапазон (midrange): " << midrange(data, data_size) << endl;

    cout << "\n\n2. Измерение дисперсии:\n" << endl;
    cout << "Диапазон: " << range(data, data_size) << endl;

    m_d.clear();
    calculate_quartiles(data, data_size, m_d);
    cout << "\nКвартили (IQR = " << m_d.at(2) - m_d.at(0)<< "):" << endl;
    for (int i = 0, percent = 25; i < m_d.size(); i++, percent += 25)
        cout << endl << percent << "% квартиль: " << m_d.at(i);
    cout << endl;

    cout << endl << "Выбросы (аномалии) (";
    cout << "Максимально допустимый предел (Q3+1.5xIQR): " << 1.5 * (m_d.at(2) - m_d.at(0)) + m_d.at(2);
    cout << ", минимально допустимый предел (Q1-1.5xIQR): " << m_d.at(0) - 1.5 * (m_d.at(2) - m_d.at(0)) << "): " << endl;
    for (int i = 0; i < data_size; i++)
    {
        //1.5*IQR > Q3
        if (data[i] >= 1.5 * (m_d.at(2) - m_d.at(0)) + m_d.at(2))
            cout << data[i] << " ";
        //1.5*IQR < Q1
        else if (data[i] <= m_d.at(0) - 1.5 * (m_d.at(2) - m_d.at(0)))
            cout << data[i] << " ";
    }
    cout << endl;

    cout << "Пять значений описания дисперсии (five-number summary): " << data[min_pos(data, data_size)] << ", ";
    cout << m_d[0] << ", " << m_d[1] << ", " << m_d[2] << ", " << data[max_pos(data, data_size)] << endl;

    double v = variance(data, data_size);
    cout << "\nДисперсия (variance): " << v << endl;
    cout << "Стндартное отклонение (standart Deviation): " << sqrt(v) << endl;
    cout << "Коэффициент девиации (Coefficient of Variation, CV): " << sqrt(v) / arithmetic_mean(data, data_size) << endl;
 } 
