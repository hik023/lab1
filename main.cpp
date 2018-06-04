#include <iostream>
#include<ctime>
#include <math.h>

using namespace std;

//Constants
const int n = 5;   //Length of array

//Prototypes
void filler(double *arr, int arr_length);
void printer(double *arr, int arr_length);
double sum_of_positive(double *arr, int arr_length);
double product_between_min_max(double (&arr)[n], int arr_length);
void array_sort(double (&arr)[n], int arr_length);

//Main program
int main() {
    double a[n];
    filler(a,n);
    cout << "Our array: [ ";
    printer(a,n);
    cout << "]" << endl << endl;
    cout << "Summ of positive elements: " << sum_of_positive(a,n)<< endl;
    cout << "Product of numbers between minimum and maximum elements: " << product_between_min_max(a,n)<< endl;
    cout << "Sorted array: [ ";
    array_sort(a,n);
    printer(a,n);
    cout << "]";
    getchar();
    return 0;
}

//Functions

//filler
void filler(double *arr, int arr_length){
    srand(time(NULL));
    for (int i = 0; i<arr_length; i++){

        *arr = rand()%10000/100.0-50;
        arr++;
    }
}
//printer
void printer(double *arr, int arr_length){
    for (int i = 0; i<arr_length; i++){
        cout << *arr << " ";
        arr++;
    }
}
//1 function
double sum_of_positive(double *arr, int arr_length){
    double sum = 0;
    for (int i = 0;i<arr_length;i++){
        if (*arr>0){
            sum += *arr;
        }
        arr++;
    }
    return sum;
}
//2 function
double product_between_min_max(double (&arr)[n], int arr_length){
    double product = 1;
    int min_abs = 0, max_abs = 0;
    for (int i = 0;i<arr_length;i++){
        if (fabs(arr[i])>fabs(arr[max_abs])){
            max_abs = i;
        }
        if (fabs(arr[i])<fabs(arr[min_abs])){
            min_abs = i;
        }
    }
    if(min_abs>max_abs){
        for(int i=max_abs+1;i<min_abs;i++){
            product *= arr[i];
        }
    }
    else{
        for(int i=min_abs+1;i<max_abs;i++){
            product *= arr[i];
        }
    }
    return product;
}
//sorting
void array_sort(double (&arr)[n], int arr_length){
    double buffer;
    for(int i = 0;i<arr_length;i++){
        for(int j = 0; j<arr_length;j++){
            if (arr[i]<arr[j]){
                buffer = arr[i];
                arr[i] = arr[j];
                arr[j] = buffer;
            }
        }
    }
}