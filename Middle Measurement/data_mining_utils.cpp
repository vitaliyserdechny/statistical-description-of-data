#include "data_mining_utils.h"
#include <iostream>
#include <algorithm>

//100 500 300 200

double variance(const int* arr, size_t size)
{
    double mean = arithmetic_mean(arr, size);
    double sum = 0;
    for (size_t i = 0; i < size; i++)
        sum += pow(arr[i],2);
    return (sum / size) - pow(mean, 2);
}

void calculate_quartiles(const int* arr, size_t size, std::vector<int>& result)
{
    for (size_t i = 25; i <= 75; i += 25)
        result.push_back(arr[((i * size) / 100)]);
}

int range(const int* arr, size_t size)
{
    return arr[max_pos(arr, size)] - arr[min_pos(arr, size)];
}

//*****************************************************

double midrange(const int* arr, size_t size)
{
    return (arr[min_pos(arr, size)] + arr[max_pos(arr, size)]) / 2.0;
}
 
bool mode(const int* arr, size_t size, std::vector<int>& modes, int& frequency)
{
    int best_frequency_value_pos = -1;
    int max_count = 0;

    for (size_t i = 0; i < size; i++)
    {
        int count = 0;
        for (size_t j = 0; j < size; j++)
            if (arr[i] == arr[j])
                count++;
        if (count > max_count)
        {
            best_frequency_value_pos = i;
            max_count = count;
        }
    }

    if (max_count == 1)
        return false;
    else
    {
        for (int i = 0; i < size; i++)
        {
            int count = 0;
            for (size_t j = 0; j < size; j++)
                if (arr[i] == arr[j])
                    count++;
            if (count == max_count && 
                std::find(modes.begin(), modes.end(), arr[i]) == std::end(modes))
                modes.push_back(arr[i]);
        }
        frequency = max_count;
        return true;
    }
}

double median(int* arr, size_t size)
{
    if (size % 2 != 0)
        return arr[size / 2];
    else
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
}

double trimmed_mean(int* arr, size_t size, double percent_ignored) {
    int ignored_count = (percent_ignored * size) / 100;
    int sum = 0;
    for (size_t i = ignored_count; i < size - ignored_count; i++)
        sum += arr[i];
    return (double)sum / (size - ignored_count);
}

double arithmetic_mean(const int* arr, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++)
        sum += arr[i];
    return (double)sum / size;
}

//********************************************

void sort(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        bool is_sorted = true;
        for (size_t j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                is_sorted = false;
            }
        }
        if (is_sorted)
            break;
    }
}

int min_pos(const int* arr, size_t size)
{
    int imin = 0;
    for (size_t i = 1; i < size; i++)
        if (arr[i] < arr[imin]) imin = i;
    return imin;
}

int max_pos(const int* arr, size_t size)
{
    int imax = 0;
    for (size_t i = 1; i < size; i++)
        if (arr[i] > arr[imax]) imax = i;
    return imax;
}

void rand_integer_data(int* arr, size_t size, int minrnd, int maxrnd) {
    if (arr == nullptr)
        return;
    for (size_t i = 0; i < size; i++)
        arr[i] = minrnd + rand() % (maxrnd - minrnd + 1);
}

void print_integer_data(const int* arr, size_t size) {
    if (arr == nullptr)
        return;
    for (size_t i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}