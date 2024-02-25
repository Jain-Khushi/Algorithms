#include <bits/stdc++.h>
using namespace std;

//function to sort an array and return the number of comparisons
int insertion_sort(int arr[], int n)
{
    int comparison = 0;
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
            comparison++;
        }
        if (j >= 0)
        {
            comparison++;
        }
        arr[j + 1] = current;
    }
    return comparison;
}

//function to generate random array and create .csv file
void generate_random_array(int size, int check)
{
    fstream fout;
    int comp;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100);
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    if (check == 0) //average case
    {
        comp = insertion_sort(arr, size);
        fout.open("average_case.csv", ios::out | ios::app);
        fout << size << "," << comp << endl;
    }

    else if (check == 1) //best_case
    {
        sort(arr, arr + n);
        comp = insertion_sort(arr, size);
        fout.open("best_case.csv", ios::out | ios::app);
        fout << size << "," << comp << endl;
    }

    else if (check == 2) //worst_case
    {
        sort(arr, arr + n, greater<int>());
        comp = insertion_sort(arr, size);
        fout.open("worst_case.csv", ios::out | ios::app);
        fout << size << "," << comp << endl;
    }
}

//average case
void average_case(int start, int end)
{
    int interval = (end - start) / 60;
    int count = 0;
    for (int i = start; i < end && count < 60; i += interval)
    {
        generate_random_array(i, 0);
        count++;
    }
}

//best_case
void best_case(int start, int end)
{
    int interval = (end - start) / 20;
    int count = 0;
    for (int i = start; i < end && count < 20; i += interval)
    {
        generate_random_array(i, 1);
        count++;
    }
}

//worst_case
void worst_case(int start, int end)
{
    int interval = (end - start) / 20;
    int count = 0;
    for (int i = start; i < end && count < 20; i += interval)
    {
        generate_random_array(i, 2);
        count++;
    }
}

//main function
int main()
{
    int min_value = 30;
    int max_value = 1000;

    average_case(min_value, max_value);
    best_case(min_value, max_value);
    worst_case(min_value, max_value);

    return 0;
}
