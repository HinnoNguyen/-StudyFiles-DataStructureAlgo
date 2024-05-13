#include <iostream>

using namespace std;

void inmang(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<"\n";
}

void mergee(int arr[], int const left, int const mid,
           int const right, int const n)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
    for(int i=0;i<left;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"[ ";
    if(right==n-1)
    {
        for(int i=left;i<=right-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[right]<<" ]"<<"\n";
    }
    else{
    for(int i=left;i<=right;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"] ";
    for(int i=right+1;i<n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[n-1]<<"\n"; }
}

void mergeSort(int arr[], int const beginn, int const endd, int const n)
{
    if (beginn >= endd)
        return;

    int mid = beginn + (endd - beginn) / 2;
    mergeSort(arr, beginn, mid,n);
    mergeSort(arr, mid + 1, endd,n);
    mergee(arr, beginn, mid, endd,n);
}
int main()
{
    int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,n-1,n);
    return 0;
}