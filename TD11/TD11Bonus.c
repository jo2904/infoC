#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int taillechaine(char *string, int i){
  if(string[i] == '\0'){
    return i;
  }
  else{
    return taillechaine(string, i+1);
  }
}

int NbA(char *string, int i, int a){
  if (string[i] == '\0'){
    return a;
  }
  else{
    if(string[i] == 'a'){
      a++;
    }
    return NbA( string, i+1, a);
  }
}

int OrdreAlpha(char *stringA, char *stringB, int n){
  if(stringA[n] > stringB[n]){
    return 2;
  }
  else if(stringA[n] < stringB[n]){
    return 1;
  }
  else{
    return OrdreAlpha(stringA, stringB, n+1);
  }
}


int TailleInt(int n, int i){
  if(n/10 <= 0){
    return i+1;
  }
  else{
    return TailleInt(n/10, i+1);
  }
}
int main(){
  char aaaa[] = "aua";
  char bbbb[] = "aujourd'hui";
  printf("%d\n", OrdreAlpha(aaaa, bbbb, 0));
}
