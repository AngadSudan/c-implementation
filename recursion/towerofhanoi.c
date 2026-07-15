#include <stdio.h>


int toh(int n, int f, int t, int h){
  if(n==0) return 0;
  toh(n-1,f,h,t);
  printf("%c - %c\n",f,t);
  toh(n-1,h,t,f);
}

void main(){
  int n;
  scanf("%d",&n);
  toh(n,'a','b','c');
}
