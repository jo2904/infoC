#include <stdio.h>

int main(){
  float x, y, z;
  int i;
  printf( "Multiplication\n" );
  x = 0.0f;
  for ( i = 0; i < 1000; i++ ){
    x += 0.01f;
  }
  printf( "1000 * 0.01 = %f\n", x );
  x = 0.01f;
  printf( "1000 * 0.01 = %f\n\n", 1000.0f * x );
  printf( "Associativite et commutativite\n" );
  x =  100000000.0f;
  y = -100000000.0f;
  z =  1.0f;
  printf( "x = %f, y = %f, z = %f\n", x, y, z );
  printf( "x + y + z = %f\n", x + y + z );
  printf( "x + z + y = %f\n", x + z + y );
  printf( "(x + y) + z = %f\n", (x + y) + z );
  printf( "x + (y + z) = %f\n", x + (y + z) );
  return 0;
}
