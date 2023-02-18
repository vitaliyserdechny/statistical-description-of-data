#pragma once
#include <vector>

//Helpers
void print_integer_data(const int* arr, int size);
void rand_integer_data(int* arr, int size, int minrnd = 1, int maxrnd = 100);
void sort(int* arr, int size);
int min_pos(const int* arr, int size);
int max_pos(const int* arr, int size);

//Measurement of Central Tendency
double arithmetic_mean(const int* arr, int size);
double trimmed_mean(int* arr, int size, double percent_ignored = 2.0);
double median(int* arr, int size);
bool mode(const int* arr, int size, std::vector<int>& modes, int& frequency);
double midrange(const int* arr, int size);

//Measurement of Dispersion
int range(const int* arr, int size);
void calculate_quartiles(const int* arr, int size, std::vector<int>& result);
double variance(const int* arr, int size);