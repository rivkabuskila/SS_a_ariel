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
/*An auxiliary function that recursively calculates the sum of each digit to the power of n the digits of the number*/
int powNumber(int num, int p, int sum){
    if(num==0){return sum;}
    sum+=pow(num%10,p);
    return powNumber(num/10,p,sum);

}
/*Auxiliary function that returns the number in reverse order*/
int reverseNumber(int num,int rev){
    if(num==0)return rev;
    rev=rev*10+num%10;
    return reverseNumber(num/10,rev);
}

/* will return if a number is a palindrome */
int isPalindrome(int num){
int ans=reverseNumber(num,0);
if(ans==num){return 1;}
return 0;
}


/* will return if a number is Armstrong number
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.*/
int isArmstrong(int num){
    int ans=powNumber(num, IsDigit(num),0);
    if(ans==num){return 1;}
    return 0;
}

