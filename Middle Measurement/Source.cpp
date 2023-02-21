#include <iostream>
#include "data_mining_utils.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "���. ����������� �������� ������" << endl;
    cout << "�����: ��������� �.�." << endl;
    cout << "����������� ��������������� �����������, 2023\n\n";

    const int data_size = 12;
    int data[data_size];

    rand_integer_data(data, data_size, 1000, 2000);
    cout << "�������� ������ (�������� ����������): ";
    print_integer_data(data, data_size);

    cout << "\n\n1. ��������� ����������� ���������:";
    cout << "\n\n������� ��������������: " << arithmetic_mean(data, data_size) << endl;
    cout << "���������� ������� ��������������: " << trimmed_mean(data, data_size) << endl;

    cout << "\n��������� ������..." << endl;
    cout << "���������: ";
    sort(data, data_size);
    print_integer_data(data, data_size);

    cout << "\n\n�������: " << median(data, data_size) << endl;

    std::vector<int> m_d;
    int freq = 0;
    if (mode(data, data_size, m_d, freq))
    {
        cout << "����: ";
        for (int i = 0; i < m_d.size(); i++)
            cout << m_d.at(i) << " ";
        cout << " (" << freq << " ���)" << endl;
    }
    else
        cout << "���� �� ����������!\n";

    cout << "����������� �������� (midrange): " << midrange(data, data_size) << endl;

    cout << "\n\n2. ��������� ���������:\n" << endl;
    cout << "��������: " << range(data, data_size) << endl;

    m_d.clear();
    calculate_quartiles(data, data_size, m_d);
    cout << "\n�������� (IQR = " << m_d.at(2) - m_d.at(0)<< "):" << endl;
    for (int i = 0, percent = 25; i < m_d.size(); i++, percent += 25)
        cout << endl << percent << "% ��������: " << m_d.at(i);
    cout << endl;

    cout << endl << "������� (��������) (";
    cout << "����������� ���������� ������ (Q3+1.5xIQR): " << 1.5 * (m_d.at(2) - m_d.at(0)) + m_d.at(2);
    cout << ", ���������� ���������� ������ (Q1-1.5xIQR): " << m_d.at(0) - 1.5 * (m_d.at(2) - m_d.at(0)) << "): " << endl;
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

    cout << "���� �������� �������� ��������� (five-number summary): " << data[min_pos(data, data_size)] << ", ";
    cout << m_d[0] << ", " << m_d[1] << ", " << m_d[2] << ", " << data[max_pos(data, data_size)] << endl;

    double v = variance(data, data_size);
    cout << "\n��������� (variance): " << v << endl;
    cout << "���������� ���������� (standart Deviation): " << sqrt(v) << endl;
    cout << "����������� �������� (Coefficient of Variation, CV): " << sqrt(v) / arithmetic_mean(data, data_size) << endl;
 } 
