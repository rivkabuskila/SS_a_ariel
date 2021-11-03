#include <math.h>
#include "NumClass.h"
int IsDigit(int num){
    int count=0;
    while (num!=0){
     num=num/10;
     count++;
    }
   return count;
}

int isPalindrome(int num){
    int temp=num;
    int sum=0;
    int rem=0;
    while(temp!=0){
        rem=temp%10;
        sum=sum*10 +rem;
        temp=temp/10;
    }
    if(sum==num){return 1;}
    return 0;
}

int isArmstrong(int num){
int temp=num;
int ans=0;
int sum=0;
int digit=IsDigit(num);
while(temp!=0){
    sum=temp%10;
    temp=temp/10;
    ans+=pow(sum,digit);
}
if(ans==num){return 1;}
return 0;
}

