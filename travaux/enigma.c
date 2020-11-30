#include <stdio.h>
#include <stdio.h>
#include <string.h>

int connexions[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
char textRotor[3][26] = {{"EKMFLGDQVZNTOWYHXUSPAIBRCJ"}, {"AJDKSIRUXBLHWTMCQGZNPYFVOE"},{"BDFHJLCPRTXVZNYEIWGAKMUSQO"}};
char textReflector[26] = "EJMZALYXVBWFCRQUONTSPIKHGD";
int rotor[3][26];
int reflector[26];
int invRotor[3][26];
int shift[3] = {0,0,0};

int passagerotor(int chiffre, int shift, int n){
  chiffre = (chiffre - shift + 26)%26;
  chiffre = rotor[n][chiffre];
  chiffre = (chiffre + shift)%26;
  return chiffre;
}

int inverserotor(int chiffre, int shift, int n){
  chiffre = (chiffre - shift + 26)%26;
  chiffre = invRotor[n][chiffre];
  chiffre = (chiffre + shift)%26;
  return chiffre;
}

int Encrypt(char lettre){
  int a, b;
  int chiffre;

  if((lettre - 'a' < 0) || (lettre - 'a' > 25)){
    chiffre = lettre - 'A';
  }
  else{
    chiffre = lettre - 'a';
  }

  chiffre = connexions[chiffre]; //passage par cable


  chiffre = passagerotor(chiffre, shift[0], 0);
  chiffre = passagerotor(chiffre, shift[1], 1);
  chiffre = passagerotor(chiffre, shift[2], 2);

  chiffre = reflector[chiffre]; //reflector

  chiffre = inverserotor(chiffre, shift[2], 2);
  chiffre = inverserotor(chiffre, shift[1], 1);
  chiffre = inverserotor(chiffre, shift[0], 0);

  chiffre = connexions[chiffre]; //passage par cable

  shift[0]++;             //shift rotor
  if( shift[0] == 26){
    shift[1]++;
    shift[0] =0;
  }
  if(shift[1] == 26){
    shift[2]++;
    shift[1]=0;
  }
  if(shift[2] == 26)
    shift[2] =0;

  return chiffre;
}

void Text2Value(){    //création des matrices rotor et reflector en chiffre
  for(int i=0; i<3; i++){
    for(int j =0; j<26; j++){
      rotor[i][j] = textRotor[i][j] - 'A';
    }
  }
  for(int i =0; i<26; i++){
    reflector[i] = textReflector[i] - 'A';
  }
}

void InitCle(){
  char string[3];
  printf("\nClé des rotors: \nex: abc\n");
  scanf("%s", string);
  for(int i =0; i < 3; i++){
    shift[i] = string[i] -'a';
  }
}

void GenerateInvPerm(){   //création de rotor inverse
  for(int i =0; i<3; i++){
    for(int j=0; j<26; j++){
      for(int x = 0; x< 26; x++){ // r-1
        if(rotor[i][x] == j){
          invRotor[i][j] = x;
        }
      }
    }
  }
}

void ConnectCables(){   //on récupère une chaine et on inverse deux par deux les cables
  char test[12] ="";
  int diff = 0;
  do{
    diff =0;
    printf("\nCables à inversés:\n ex: abcdefghijkl\n");
    scanf("%12s", test);
    if(strlen(test) != 12){
      printf("! il n'y a pas assez de caractères !\n");
      diff ++;
      }
    else{
    for(int i=0; i<12; i++){
      for(int j =0; j<12; j++){
        if(test[i] == test[j] && i!=j){
          printf("! deux caractères sont identiques !\n");
          diff ++;
        }
      }
    }
    }
  }while (diff != 0);
  for(int i=0; i<12; i=i+2){
    connexions[test[i]-'a'] = test[i+1] -'a';
    connexions[test[i+1]-'a'] = test[i] -'a';
  }
  printf("Les cables ont bien été inversé \n");
}

int main() {
  char string[100];
  printf("message: ");
  scanf("%100s", string);
  int taille = strlen(string);

  InitCle();
  ConnectCables();
  Text2Value();
  GenerateInvPerm();

  printf("\nchiffrement du message en cours\n");
  for(int h = 0; h<taille; h++){
    printf("%c", Encrypt(string[h])+ 'a');
  }
  printf("\n");

  return 0;
}
