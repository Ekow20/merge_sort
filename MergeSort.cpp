
#include <iostream>
#include<conio.h>
#include<stdlib.h>



using namespace std;

void merge_sort(int, int);
void merge_array(int, int, int, int);
int n =5;
int array[5];

int main() {
    int i;
    cout << "\nEnter "<<n<<" Elements You want to sort : " << endl;
   	for(int i =0; i<n; i++){
		cout<<"Enter number "<<i+1<<":  ";
		cin>>array[i];
		}

    merge_sort(0, n-1);

    cout << "\nSorted Array :";
    for (i = 0; i < n; i++) {
        cout << "\t" << array[i];
    }

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
        if (array[i] < array[j])
            t[k++] = array[i++];
        else
            t[k++] = array[j++];
    }

    //collect remaining elements 
    while (i <= b)
        t[k++] = array[i++];

    while (j <= d)
        t[k++] = array[j++];

    for (i = a, j = 0; i <= d; i++, j++)
        array[i] = t[j];
}
