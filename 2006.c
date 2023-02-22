#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define JUDGES 5
#define equals(x,y) (x==y) ? true : false;

typedef unsigned int uint;

int main(){
  uint teaType,teaOpinions[JUDGES],answer=0;
  scanf("%u",&teaType);
  scanf("%u %u %u %u %u",&teaOpinions[0],
    &teaOpinions[1],
    &teaOpinions[2],
    &teaOpinions[3],
    &teaOpinions[4]);
  
  for(int x =0;x<JUDGES;x++){
    answer += equals(teaType,teaOpinions[x]);
  }
  printf("%u\n",answer);
  
  return EXIT_SUCCESS;
}
