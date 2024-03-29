#include <iostream>
#include <cassert>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
using namespace std;

// short integer random number generator from stdlib
int rand(void); 

//insertion sort algorithm
void insertionsort(int a[], size_t size) {
    int i, key;
    for (int j=1; j<= size; j++) {
        key = a[j];
        i = j-1;
        while (i>=0 and a[i]>key){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}



//partition algorithm used in quicksort
int partition(int a[], int l, int r){
    int pivot = a[r];
    int i = l-1;
    int j = r;
    while(1){
        while(a[++i]<pivot && i<=r){}
        while(a[--j]>pivot && j>=l){}
        if (i<j)
                swap(a[i],a[j]);
        else
                break;
    }
    swap(a[i],a[r]);
    return i;
}


//quicksort algorithm
void quicksort(int a[], int l, int r) {
    if (l<r) {
        int p = partition(a,l,r);
        quicksort(a, l, p-1);
        quicksort(a, p+1, r);
    }
}


int main()
{ 
  int size;
  //hrtime_t start, total;  // defined in sys/time.h  long long int
  timeval start, end; // type defined in sys/time.h.
  double start_sec, end_sec, t_sec;

  //double t_sec;

  cout << endl << " ----- insertion/quicksort comparison ----- " << endl;
  cout << endl << "How many elements to sort: - ";  cin >> size;
  int* dataArray = new int [size];   // get array of right size
  int* copyArray = new int [size];   // to hold a copy of random ints
  assert ( (dataArray != NULL) && (copyArray != NULL) );

  //  ============ insertion sort random integers  ===================

  for (int k=0; k< size ; k++)  dataArray[k] = rand();

  // copy the array for later use by quicksort
  for (int k=0; k< size ; k++)  copyArray[k] = dataArray[k];

  cout << endl << "Insertion sort of Integer data initially in random order" << endl;

  //start = gethrtime();   // hi_resolution time nanoseconds

  gettimeofday(&start, NULL);  // get time at start of function

  
  insertionsort(dataArray, size-1);
  // implement your insertionSort here or call it as a function
  //   =====================InsertionSort===============
  //   You can refer Mark Allan Weiss Third Edition Figure 7.2 page 263

  gettimeofday(&end, NULL);  // get time at end of function
  // convert to seconds and print out
  start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
  end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
  t_sec = end_sec - start_sec;

  //total = gethrtime() - start;
  //t_sec = double(total) * 1.0e-9;  // convert to seconds
  cout << "For N = " << size << " # seconds = " << t_sec << "\n";

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << dataArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << dataArray[size-k] << ", " ;
  cout << endl << endl;

  //  ============ quicksort random integers  ===================

  cout << endl << "quicksort of Integer data initially in random order" << endl;

  //start = gethrtime();   // hi_resolution time nanoseconds
  gettimeofday(&start, NULL);  // get time at start of function


  quicksort(copyArray,0, size-1);

  // implement your quicksort here or call it as a function
  // =====================Quicksort ======================
  // you can refer Mark Allan Weiss Third Edition Figure 7.16 page 286. Note that this piece 
  // of code only use quick sort when the input has size at least 10. Please only implement 
  // the quicksort part no matter how large the input is. 


  gettimeofday(&end, NULL);  // get time at end of function
  // convert to seconds and print out
  start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
  end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
  t_sec = end_sec - start_sec;

  //total = gethrtime() - start;
  //t_sec = double(total) * 1.0e-9;  // convert to seconds
  cout << "For N = " << size << " # seconds = " << t_sec << "\n";

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << copyArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << copyArray[size-k] << ", " ;
  cout << endl << endl;

}
