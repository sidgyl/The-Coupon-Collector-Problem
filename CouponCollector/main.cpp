//
//  main.cpp
//  CouponCollector
//
//  Created by Sidharth Goyal on 6/21/15.
//  Copyright (c) 2015 Sidharth Goyal. All rights reserved.
//

#include <iostream>
#include <math.h>
//#include <random>

using namespace::std;

#include <iostream>
//#include <random>
using namespace std;

int* createDistribution(int *frequency, int sumOfFrequencies, int m){
    int *distribution = new int [sumOfFrequencies]();
    int counter = 0;
    for (int j=0; j<m ; j++) {
        int i=0;
        for (; i<frequency[j]; i++) {
            distribution[i+counter] = j+1;
        }
        counter += i;
    }
    
    return distribution;
}

float couponCollector(int number, int *frequencies, int seed, int sumOfFrequencies, int numOfIterations) {
    
    //dynamic memory allocation
    
    srand(seed);
    
//    random_device rd;
//    mt19937 engine(rd());
//    uniform_int_distribution<int> distribution(1,number);
    double sumValue = 0;
    
    for (int j=0; j<numOfIterations; j++) {
        int iteration = 0, unique = 0;
        int *collected = new int[number];
        for(int i=0; i < number; i++){
            collected[i] = false;
        }
        int *distribution = createDistribution(frequencies, sumOfFrequencies, number);
//        for (int i=0; i<sumOfFrequencies; i++) {
//            cout << distribution[i]<<endl;
//        }
        while(unique < number) {
            int num =  (rand()%sumOfFrequencies);
            int random = distribution[num];
            if(!collected[random]){
                unique++;
                collected[random] = true;
            }
                iteration++;
        }
        
        sumValue += iteration;
    }

//    delete[] collected;
//    delete[] frequencies;
    return sumValue/numOfIterations;
}

float printSet(int array[],int size, float *probabilities, int inputSize){
    float tempSum = 0;
    
    for (int i=1;i<=size;i++){
        tempSum += probabilities[array[i]-1];
        
    }
    
    if (size == inputSize) {
        return 0;
    }else{
        return pow(-1, size)/(1-tempSum);
    }
    
}

float printPowerset (int n, float *probabilities){
    int stack[50],k;
    float calculate = 0;
    
    stack[0]=0; /* 0 is not considered as part of the set */
    k = 0;
    
    while(1){
        if (stack[k]<n){
            stack[k+1] = stack[k] + 1;
            k++;
        }else{
            stack[k-1]++;
            k--;
        }
        
        if (k==0)
            break;
        
        calculate += printSet(stack,k, probabilities, n);
    }
    
//    delete[] probabilities;
    return 1+calculate;
}

int main(){
    int* frequency = NULL;
    float* probabilities = NULL;
    float sumOfFrequencies = 0,theoretical = 0;
    int m=0, numOfIterations=0, randomSeed=0;
    cout<<"Please enter the total number of coupons: ";
    cin>>m;
    cout<<"Please enter all the frequencies separated by a comma: ";
    frequency = new int[m]();
    probabilities = new float[m]();
    for (int i=0; i<m; i++){
        int readval;
        cin>> readval;
        frequency[i] = readval;
        sumOfFrequencies = sumOfFrequencies + frequency[i];
    }
    
    for(int i=0; i<m; i++){
        probabilities[i] = frequency[i]/sumOfFrequencies;
    }
    
    
    theoretical = printPowerset(m, probabilities);
    cout<<"Theoretical Value: " << fabs(theoretical)<<endl;
    
    cout<<"Enter # of iterations: ";
    cin>>numOfIterations;
    cout<<"Enter Seed: ";
    cin>>randomSeed;
    cout << "experimental value: " << couponCollector(m, frequency, randomSeed, sumOfFrequencies, numOfIterations);
    delete[] frequency;
    delete[] probabilities;
    return 0;
}