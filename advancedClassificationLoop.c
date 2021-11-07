#include <math.h>
#include "NumClass.h"


/*Auxiliary function that calculates the number of digits*/
int IsDigit(int num){
    int count=0;
    while (num!=0){
     num=num/10;
     count++;
    }
   return count;
}

/* will return if a number is a palindrome */
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

/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.*/

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

