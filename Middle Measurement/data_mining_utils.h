#pragma once
#include <vector>

//Допоміжні функції
void print_integer_data(const int* arr, size_t size);
void rand_integer_data(int* arr, size_t size, int minrnd = 1, int maxrnd = 100);
void sort(int* arr, size_t size);
int min_pos(const int* arr, size_t size);
int max_pos(const int* arr, size_t size);

//Вимірювання центральної тенденції
double arithmetic_mean(const int* arr, size_t size);
double trimmed_mean(int* arr, size_t size, double percent_ignored = 2.0);
double median(int* arr, size_t size);
bool mode(const int* arr, size_t size, std::vector<int>& modes, int& frequency);
double midrange(const int* arr, size_t size);

//Вимірювання дисперсії
int range(const int* arr, size_t size);
void calculate_quartiles(const int* arr, size_t size, std::vector<int>& result);
double variance(const int* arr, size_t size);