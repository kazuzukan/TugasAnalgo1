/*
Nama : Risyad Pangestu
NPM : 140810170003
Kelas : A
Program Merge Sorting
*/

#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<ctime>

#define MAX_SIZE 5

using namespace std;

void merge_sort(int, int);
void merge_array(int, int, int, int);

int arr_sort[MAX_SIZE];

int main() {
    int i;

    cout << "\nEnter " << MAX_SIZE << " Elements for Sorting : " << endl;
    for (i = 0; i < MAX_SIZE; i++)
        cin >> arr_sort[i];

    cout << "\nYour Data   :";
    for (i = 0; i < MAX_SIZE; i++) {
        cout << "\t" << arr_sort[i];
    }

    merge_sort(0, MAX_SIZE - 1);

    cout << "\n\nSorted Data :";
    for (i = 0; i < MAX_SIZE; i++) {
        cout << "\t" << arr_sort[i];
    }

    //time
    int start_s=clock();
	// the code you wish to time goes here
    int stop_s=clock(); 
    cout << "\ntime: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    getch();

}

void merge_sort(int i, int j) {
    int m;

    if (i < j) {
        m = (i + j) / 2;
        merge_sort(i, m);
        merge_sort(m + 1, j);
        // Merging two arrays
        merge_array(i, m, m + 1, j);
    }
}

void merge_array(int a, int b, int c, int d) {
    int t[50];
    int i = a, j = c, k = 0;

    while (i <= b && j <= d) {
        if (arr_sort[i] < arr_sort[j])
            t[k++] = arr_sort[i++];
        else
            t[k++] = arr_sort[j++];
    }

    //collect remaining elements 
    while (i <= b)
        t[k++] = arr_sort[i++];

    while (j <= d)
        t[k++] = arr_sort[j++];

    for (i = a, j = 0; i <= d; i++, j++)
        arr_sort[i] = t[j];
}
