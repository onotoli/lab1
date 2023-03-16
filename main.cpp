#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <random>

int lineary_search(const int * const array, const int n, const int c) {
    int i = -1;
    for (int j = 0; j < n; ++j) {
        if (array[j] == c)
            i = j;

    }

    return i;
}

int binary_search(const int * const array, const int n, const int c) {
    int l = 0;
    int r = n - 1;
    int mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (c < array[mid]) {
            r = mid - 1;
            mid = (l + r) / 2;
        }
        else {
            l = mid + 1;
            mid = (l + r) / 2;
        }
        if (array[mid] == c) {
            return mid;
        }
    }
    return -1;
}

int* new_array(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}

void OUT (std::string file_name, int n, long long t){
    std::ofstream out(file_name, std::ios::app);
    if (out.is_open())
    {
        out << n << ";" << t <<std::endl;
    }
    out.close();
}

void sum_search(const int * const array, const int n, const int c, int* a, int* b) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (array[i] + array[j] == c) {
                *a = i;
                *b = j;
                return;
            }
        }

    }
    *a = -1;
    *b = -1;
}

void sum_binsearch(const int * const array, const int n, const int c) {
    int a = 0;
    int b = n - 1;
    while (a <= b) {
        if (array[a] + array[b] < c)
            a++;
        else if (array[a] + array[b] > c)
            b--;
        else if (array[a] + array[b] == c) {
            std::cout << a << '\t' << b << '\r';
            break;
        }
    }
}

int swap_A(int* const array, const int n, const int c){
    for (int i = 0; i < n; ++i) {
        if (array[i] == c){
            if (i != 0) {
                array[i] = array[0];
                array[0] = c;
            }
            return i;
        }
    }
    return -1;
}

int swap_B(int* const array, const int n, const int c){
    for (int i = 0; i < n; ++i) {
        if (array[i] == c){
            if (i != 0) {
                array[i] = array[i - 1];
                array[i - 1] = c;
            }
            return i;
        }
    }
    return -1;
}

int swap_C(int* const array, int* const counter, const int n, const int c){
    for (int i = 0; i < n; ++i) {
        if (array[i] == c){
            ++counter[i];
            if (i != 0 && counter[i] > counter[i -1]) {
                array[i] = array[i - 1];
                array[i - 1] = c;
            }
            return i;
        }
    }
    return -1;
}


/*int main() {
    long long t;
    clock_t end, begin;
    begin = clock();
    int j = 100;
    while (j <= 1000000) {
        int *a = new_array(j);
        for (int i = 0; i < 1000000; ++i) {
            binary_search(a, j, -1);
        }
        end = clock();
        t = (long long) (end - begin);
        std::cout << t << '\t' << j << std::endl;
        OUT("binary_data.csv", j, t);
        if (j < 2000)
            j = j + 100;
        else if (j < 20000)
            j = j + 3000;
        else if (j < 100000)
            j = j + 10000;
        else
            j = j + 25000;
    }

    return 0;
}
*/

/*

int main() {
    long long t;
    clock_t end, begin;
    begin = clock();
    int j = 100;
    while (j <= 1000000) {
        int *a = new_array(j);
        for (int i = 0; i < 10000; ++i) {
            sum_binsearch(a, j, -1);
        }
        end = clock();
        t = (long long) (end - begin);
        std::cout << t << '\t' << j << std::endl;
        OUT("binsum_data.csv", j, t);
        if (j < 2000)
            j = j + 100;
        else if (j < 20000)
            j = j + 3000;
        else if (j < 100000)
            j = j + 10000;
        else
            j = j + 100000;
    }

    return 0;
}
*/

int main() {
    long long t;
    clock_t end, begin;
    begin = clock();
    int j = 100;
    while (j <= 500000) {
        int *a = new_array(j);
        int* counter = new int[j];
        for (int i = 0; i < j; ++i)
            counter[i] = 0;
        for (int i = 0; i < 100000; ++i) {
            int c;
            if (i % 4 == 0)
                c = j / 5;
            else if (i % 2 == 0)
                c = j / 3;
            else if (i % 3 == 0)
                c = j / 7;
            else if (i % 5 == 0)
                c = j / 4;
            else
                c = rand() % j;
            swap_A(a, j, c);
        }
        end = clock();
        t = (long long) (end - begin);
        std::cout << t << '\t' << j << std::endl;
        OUT("A_det.csv", j, t);
        if (j < 2000)
            j = j + 100;
        else if (j < 20000)
            j = j + 3000;
        else if (j < 100000)
            j = j + 10000;
        else
            j = j + 50000;
    }

    return 0;
}