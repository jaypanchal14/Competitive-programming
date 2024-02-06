#include<iostream>

using namespace std;

//Below function is equivalent to : int getSum(int *arr, int size)
int getSum(int arr[], int size){

    int ans = 0;
    for(int i=0; i<size; i++){
        ans += i[arr];
    }
    return ans;
}

int main(){

    /*
    Pointer : A variable which stores the address of another variable(It can be of any data-type).
    As, it just stores the address of variable, it would always be 8 bytes in normal computer.

    There are two ways of initializing the pointer.
    */

    int a = 10;

    //Null pointer initialization -> int *p1 = 0;
    
    //First way
    int *p1 = &a; 
    //cout<<"Size of pointer:"<<sizeof(p1)<<endl;
    
    //Second way
    int *p2 = 0;
    p2 = &a;

    //This will print : 11 and 10 respectively from a and p1
    //cout<<"Before with variable a:"<<a<<", or from pointer p1:"<<(*p1)++<<endl;
    //This will print 11 and 11 respectively from a and p1
    //cout<<"Before with variable a:"<<a++<<", or from pointer p1:"<<(*p1)<<endl;
    //This will print 12 and 12 respectively from a and p2
    //cout<<"After with variable a:"<<a<<", or from pointer p2:"<<*p2<<endl;
    
    //int x[3] = {2}; // it is equivalent to x = {2,0,0}
    //int b[4] = {1,2,3,4};
    //cout<<"sum of b from 0th index:"<<getSum(b,4)<<endl;  //10
    //cout<<"sum of b from 4th index:"<<getSum(b+3,1)<<endl; //4
    
    //cout<<"Address of b or its first element:"<<&b<<endl;
    //cout<<"Second element :"<<*(b+1)<<endl; //2
    //cout<<"First element :"<<0[b]<<endl; //1
    //cout<<sizeof(*b)<<" or "<<sizeof(b)<<endl; // 4 or 16

    //Character array (last character is '\n' by implicit, and if we explicitly change it, it will give error)
    char cc[6] = "ashfh";
    cout<<cc<<endl;  //It will print till it will reach the '\n' character

    //int* asad = &a;
    //cout<<a<<","<<&a<<","<<asad<<","<<&asad<<","<<*asad<<endl;

    //Difference betweene printing int array and char array is this :
    //In int array, it will only print int stored at current address, whereas for char array, it will keep printing till we reach '\n'.

    //int **pDouble = &p1;
    //cout<<"a:"<<a<<"(from a variable) or "<<**pDouble<<"(from double-pointer)"<<endl;

    //------------------------End of pointers--------------------------

    //Reference variable
    //int i = 11;
    //int& j = i; //Used for call by reference approach, here this variable will point to i as well, same location
    
    //cout<<i<<","<<j<<endl;   //11,11

    //'new' keyword allocated memory from the heap

    //Static allocation of memory from the stack
    //int var = 13423;  //At the time of compiling the program

    //Dynamic allocation fo memory from the heap
    int* memory = new int;   //RHS of the equation returns a memory address from the heap, where we can store an int dynamically
    //Total 12 bytes of memory is being used here, as int takes 8 bytes from the stack (to store the address), and 4 bytes from heap(to store the value). 
    *memory = 12;

    //BAD practice to get the flexible size of array at the run time
    //int arr[*memory];

    //GOOD pratice
    //int* arr = new int[*memory];
    cout<<"Address: "<<memory<<endl; //This will print the memory address
    cout<<"Value: "<<*memory<<endl;

    //As dynamically allocated memory don't get deleted implicitly, we need to unallocate/release the memory from the heap
    //with delete memory; //(in case of single integer) //In case of array //delete []arr;

    //--------------------------------------------------

    //Creating 2D array with dynamic memory allocation
    int* oneD = new int[5];  //This calls constructor of class int


    //Another way using malloc function
    int* oneDd = (int*)malloc(5*sizeof(int));  //Malloc doesn't call the constructor
    /*for(int i=1;i<6;i++){
        oneD[i] = i;
    }
    for(int i=1;i<6;i++){
        cout<<oneD[i]<<" ";
    }
    cout<<endl;*/

    //One thing to notice here is, for creating a single-data variable from heap memory, we need to use '*' for assigning and
    //retrieving its value, wheread for 1D or 2D array, we don't need to use '*' for assigning and retrieving.
    //It is because, an array variable itself represents the address, and while performing operations, it implicitly considers the '*' operator.
    
    //This will return a pointer to an array of pointer of size 10, but we have not allotted the size
    //of array each pointer will point to, from the array.
    int** twoD = new int*[5];  
    /*for(int i=0; i<5; i++){
        twoD[i] = new int[5];
        for(int j=0;j<5;j++){
            twoD[i][j] = i+j;
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0;j<5;j++){
            cout<<twoD[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/

    //Releasing the assigned memory from the heap
    delete memory;
    delete []oneD;
    for(int i=0; i<5; i++){
        delete[] twoD[i];   //To release the individual arrays
    }
    delete[] twoD;  //To release the memory allocated to array of pointers
    free(oneDd); //Associated with malloc function
    return 0;
}

