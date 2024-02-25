#include <iostream>
#include <fstream>


using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int &numOfcomp)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (numOfcomp++, arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int random_partition(int arr[], int low, int high, int &numOfcomp)
{
    int random_index = (rand() % (high + 1));

    if (arr[random_index] != arr[high])
        swap(&arr[random_index], &arr[high]);

    return partition(arr, low, high, numOfcomp);
}

void random_quickSort(int arr[], int low, int high, int &numOfcomp)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, numOfcomp);
        random_quickSort(arr, low, pi - 1, numOfcomp);
        random_quickSort(arr, pi + 1, high, numOfcomp);
    }
}

void generate_random_array(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 1000);
    }
}

void average_case(int cases, int min, int max)
{
    ofstream average_case_file("average_quick_Random.csv");
    int interval = (((max - min) / cases) / 10.0) * 10;
    int count = 0;
    for (int i = min; count < cases; i += interval, count++)
    {
        int *random_array = new int[i];
        generate_random_array(random_array, i);
        int numOfcomp = 0;
        random_quickSort(random_array, 0, i - 1, numOfcomp);
        average_case_file << i << "," << numOfcomp << "\n";
        delete[] random_array;
    }
    average_case_file.close();
}

int main()
{
    average_case(100, 30, 1000);
}