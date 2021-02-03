#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int CaseTriangle(int NumLig, int NumCol){
  if(NumCol > NumLig){
    return 0;
  }
  else if((NumLig == 1) || (NumCol == 1)){
    return 1;
  }
  return CaseTriangle(NumLig-1, NumCol) + CaseTriangle(NumLig-1, NumCol-1);
}

void AfficheTrianglePascal(int NbLignes){
  int n = 2;
  for(int i =1; i<NbLignes; i++){
    for(int j = 1; j < n; j++){
      printf("%d ", CaseTriangle(i, j));
    }
    printf("\n");
    n++;
  }
}

int main(){
  AfficheTrianglePascal(7);

}
