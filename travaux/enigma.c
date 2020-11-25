#include <stdio.h>
#include <stdio.h>
#include <string.h>

char connexions[26] = "abcdefghijklmnopqrstuvwxyz";
char textRotor[3][26] = {{"EKMFLGDQVZNTOWYHXUSPAIBRCJ"}, {"AJDKSIRUXBLHWTMCQGZNPYFVOE"},{"BDFHJLCPRTXVZNYEIWGAKMUSQO"}};
char textReflector[26] = "EJMZALYXVBWFCRQUONTSPIKHGD";
int rotor[3][26];
int reflector[26];
int decallage[3] = {0,0,0};

int Encrypt(char lettre){
  int chiffre = lettre - 97; //transfo en chiffre
  printf("%d ", chiffre);
  chiffre = connexions[chiffre] - 97; //passage par cable

  chiffre = (rotor[0][chiffre + 25 - decallage[0] ])- 25 + decallage[0]; // les 3 rotors
  chiffre = (rotor[1][chiffre + 25 - decallage[1] ])- 25 + decallage[1];
  chiffre = (rotor[2][chiffre + 25 - decallage[2] ])- 25 + decallage[2];

  chiffre = reflector[chiffre]; //reflector
  
   chiffre = connexions[chiffre] - 97; //passage par cable

  decallage[0]++;             //decallage rotor
  if( decallage[0] == 26){
    decallage[1]++;
    decallage[0] =0;
  }
  if(decallage[1] == 26){
    decallage[2]++;
    decallage[1]=0;
  }
  if(decallage[2] == 26)
    decallage[2] =0;

  return chiffre;
}

void Text2Value(){
  for(int i=0; i<3; i++){
    for(int j =0; j<26; j++){
      rotor[i][j] = textRotor[i][j]-65;
      }
  }
  for(int i =0; i<26; i++){
    reflector[i] = textReflector[i]-65;
  }
}

void ConnectCables(){
  char test[12] ="";
  int diff = 0;
  do{
    diff =0;
    printf("Cables à inversés:\n ex: abcdefghijkl\n");
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
    connexions[test[i]-97] = test[i+1];
    connexions[test[i+1]-97] = test[i];
  }
  printf("Les cables ont bien été inversé \n");
}

int main() {
  char string[] = "test";
  int taille = strlen(string);

  ConnectCables();
  Text2Value();

  printf("chiffrement du message en cours\n");
  for(int h = 0; h<taille; h++){
    printf("%d ", Encrypt(string[h]));
  }

  return 0;
}
