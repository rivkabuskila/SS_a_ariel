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

int powNumber(int num, int p, int sum){
    if(num==0){return sum;}
    sum+=pow(num%10,p);
    return powNumber(num/10,p,sum);

}

int reverseNumber(int num,int rev){
    if(num==0)return rev;
    rev=rev*10+num%10;
    return reverseNumber(num/10,rev);
}


int isPalindrome(int num){
int ans=reverseNumber(num,0);
if(ans==num){return 1;}
return 0;
}



int isArmstrong(int num){
    int ans=powNumber(num, IsDigit(num),0);
    if(ans==num){return 1;}
    return 0;
}

