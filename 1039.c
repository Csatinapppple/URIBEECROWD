#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define sumAndCompare(x,y,z,a,b,c) (x>=a && x+y+z>=a+b+c) ? true : false

//circle one encompasses circle two return true

int main(){
  int rad1,x1,y1; //hunter
  int rad2,x2,y2; //flower
  while(scanf("%d %d %d %d %d %d"
        ,&rad1,&x1,&y1,&rad2,&x2,&y2) != EOF){

    bool print = sumAndCompare(rad1,x1,y1,rad2,x2,y2);
    printf(print ? "RICO\n" : "MORTO\n");
  }
  return EXIT_SUCCESS;
}
