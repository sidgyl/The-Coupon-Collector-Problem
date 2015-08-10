//  CouponCollector
//
//  Created by Sidharth Goyal on 6/21/15.
//  Copyright (c) 2015 Sidharth Goyal. All rights reserved.
//
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h> 
#include <set>
#include <iostream>
#include <iostream>
using namespace::std;
#include <iostream>
using namespace std;
//
//int couponCollector(int number);
//
//int main(){
//    cout <<  "result= " << couponCollector(m) <<endl;
//}
//
//int couponCollector(int number) {
//    
//    //dynamic memory allocation
//    bool *collected = new bool[number];
//    
//    //initialize each element to false
//    for(int i=0; i < number; i++){
//        collected[i] = false;
//    }
//    
//    int iteration = 0, unique = 0;
//    
//    random_device rd;
//    mt19937 engine(rd());
//    uniform_int_distribution<int> distribution(1,365);
//    
//    while(unique < number) {
//        int random =  distribution(engine);
//        if(!collected[random]){
//            unique++;
//            collected[random] = true;
//        }
//        iteration++;
//    } 
//    
//    delete[] collected;
//    return iteration;
//}

//==================POWER SET ==============================================================//
/*
void printPowerSet(char *set, int set_size,)
{
	float sum;
	
	float probabilities[w];	
	set_size of power set of a set with set_size
      n is (2**n -1)
    unsigned int pow_set_size = pow(2, set_size);
 
    /*Run from counter 000..0 to 111..1
    for(int counter = 0; counter < pow_set_size; counter++)
    {
      for(int j = 0; j < set_size; j++)
       {
          Check if jth bit in the counter is set
             If set then pront jth element from set 
           if(counter & (1<<j))
            //printf("%c", set[j]);
            sum+=probabilities[w];
            cout << sum <<endl;
        }
        
       //printf("\n");
		
	}
}*/

/*==============================================================*/


void printSet(int array[],int size){
    int i;

    for (i=1;i<=size;i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return;
}

void printPowerset (int n){
    int stack[10],k;

    stack[0]=0; /* 0 is not considered as part of the set */
    k = 0;

    while(1){
        if (stack[k]<n){
            stack[k+1] = stack[k] + 1;
            k++;
        }

        else{
            stack[k-1]++;
            k--;
        }

        if (k==0)
            break;

        printSet(stack,k);
    }

    return;
}
//***********************************************************************************







/*void printSet(int array[],int size){
    int i;
    
    for (i=1;i<=size;i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    
    return;
}*/

/*void printPowerset (int n){
    int stack[10],k;
    
    stack[0]=0; /* 0 is not considered as part of the set 
    k = 0;
    
    while(1){
        if (stack[k]<n){
            stack[k+1] = stack[k] + 1;
            k++;
        }
        
        else{
            stack[k-1]++;
            k--;
        }
        
        if (k==0)
            break;
        
        printSet(stack,k);
    }
    
    return;
}
*/
//===============================MAIN CLASS ===========================================//
int main(){
    int* frequency = NULL;
    float* probabilities = NULL;
    float sumOfFrequencies = 0;
	int m=0, frequencySize=0;
    cout<<"Please enter the total number of coupons: ";
    cin>>m;
    cout<<"Please enter all the frequencies separated by a comma: ";
    frequency = new int[m]();  
    probabilities = new float[m]();
    float sumofprobabilities = 0;
    float john = 0;
    for (int i=0; i<m; i++) 
		{
		   int readval;
		   cin>> readval;
		   frequency[i] = readval;
		  
		   sumOfFrequencies = sumOfFrequencies + frequency[i];
			
		}

   cout << "sumOfFrequencies: " << sumOfFrequencies << endl;
    for (int p=1; p<=m; p++)
    {
	
		   john = (p/sumOfFrequencies);
		   probabilities[p] = john;
		   cout<< john;
	}

	
	
   printPowerset(4);
    return 0;
}            
