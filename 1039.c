#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define sumAndCompare(x,y) (x<=y) ? true : false

//circle one encompasses circle two return true

int main(){
  int rad1,x1,y1; //hunter
  int rad2,x2,y2; //flower
  
  while(scanf("%d %d %d %d %d %d"
  ,&rad1,&x1,&y1,&rad2,&x2,&y2) != EOF){
      
    float distance_squared = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));

    bool print = sumAndCompare(distance_squared+rad2,rad1);
    printf(print ? "RICO\n" : "MORTO\n");
  }

  return EXIT_SUCCESS;
}
