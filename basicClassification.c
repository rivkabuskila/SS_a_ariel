
#include <math.h>
#include "NumClass.h"

int isPrime(int num){
    if(num<0)return 0;
    for (int i = 2; i <= sqrt(num); i++)
    {
       if(num%i==0){return 0;}
    }
    return 1;
}

int facto(int num){
    if (num < 1){ return 1;}
    return num*facto(num-1);
}

int isStrong(int num){
    int temp=num;
    int ans=0;
    int sum=0;
    while(temp!=0){
    sum=temp%10;
    temp=temp/10;
    sum=facto(sum);
    ans+=sum;
    }
    if(ans==num){
        return 1;
        }
    return 0;
}