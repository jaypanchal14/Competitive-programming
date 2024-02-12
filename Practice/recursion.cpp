#include<iostream>
#include<vector>

using namespace std;

//To reverse the string with start and end pointer
void rever(string& s, int start, int end){
    if(start>=end){
        return;
    }
    swap(s[start++],s[end--]);
    rever(s, start, end);
}

//To reverse the string with only one pointer
void rever2(string& s, int start, int& size){
    if(start>=size/2){
        return;
    }
    swap(s[start++],s[size-1-start]);
    rever2(s, start, size);
}

bool checkPalindrome(string& s, int start, int end){
    if(start>=end){
        return true;
    }
    if(s[start++]!=s[end--]){
        return false;
    }
    return checkPalindrome(s, start, end);
}

long long powerExponential(int num, int raise){
    if(raise == 0){
        return 1l;
    }
    if(raise==1){
        return num;
    }
    if(raise&1){
        return num * powerExponential(num*num, raise/2);
    }else{
        return powerExponential(num*num, raise/2);
    }
}

//Merge-sort with recursion
//1)
void merge(int arr[], int start, int mid, int end){
    int size1 = mid-start+1,size2 = end-mid;
    int* ll = new int[size1];
    int* rr = new int[size2];
    for(int i=0; i<size1;i++){
        ll[i] = arr[start+i];
    }
    for(int i=0; i<size2;i++){
        rr[i] = arr[mid+1+i];
    }
    int index1 = 0, index2 = 0, arrayIndex = start;
    while(index1<size1 && index2<size2){
        if(ll[index1]<=rr[index2]){
            arr[arrayIndex++] = ll[index1++];
        }else{
            //in case of inversion count
            //count += size1 - index1;
            arr[arrayIndex++] = rr[index2++];
        }
    }
    while(index1<size1){
        arr[arrayIndex++] = ll[index1++];
    }
    while(index2<size2){
        arr[arrayIndex++] = rr[index2++];
    }

    delete[] ll;
    delete[] rr;
}

void mergeSort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

void printArray(int* arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }    
}

//Quick sort with recursion
int partition(int arr[], int start, int end){
    if(start>=end){
        return start;
    }

    //There are different ways to find the pivot, either first, or last, or any random from in-between
    //1)to find the first correct position of a pivot through loop iteration to get the count and shift the pivot first
    //2)Then run a while loop with two pointer, one from left(i) and another from right(j), swap them when the condition meet
    //3)condition : arr[i]>arr[pivot] && arr[j]<arr[pivot]
    //4)return pivot

    //Here we are considering pivot as the first element
    int current = start+1;
    while(current<= end){
        if(arr[current]>=arr[start]){
            swap(arr[end--],arr[current]);
        }else{
            current++;
        }
    }
    swap(arr[end],arr[start]);
    return end;
}

void quickSort(int arr[], int start, int end){
    if(start>=end){
        return;
    }
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot-1);
    quickSort(arr, pivot+1, end);
}

int main(){
    //string s = "abcba";
    //int size = s.size();
    /*cout<<"Before reverse:"<<s<<endl;
    rever(s, 0, s.size()-1);
    rever2(s,0,size);
    cout<<"After reverse:"<<s<<endl;*/
    //cout<<"is palindrome: "<<checkPalindrome(s, 0, size-1);
    //cout<<"2^10: "<<powerExponential(3, 5)<<endl;
    //int arr[] = {4, 7, 9, 1, 6, 82,8,43,11,42,32,9};
    int arr[] = {8,7,6,5,1,2,3,4,9};
    int size = sizeof(arr)/sizeof(int);
    cout<<"Before sorting: ";
    printArray(arr, size);
    //mergeSort(arr, 0, size-1);
    quickSort(arr, 0, size-1);
    cout<<endl<<"After sorting: ";
    printArray(arr, size);
    cout<<endl;
    return 0;
}