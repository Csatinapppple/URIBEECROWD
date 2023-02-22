#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define JUDGES 5
#define equals(x,y) (x==y) ? true : false;

typedef unsigned int uint;

int main(){
  uint teaType,teaOpinions[JUDGES],answer=0;
  scanf("%d",&teaType);
  scanf("%d %d %d %d %d",&teaOpinions[0],
    &teaOpinions[1],
    &teaOpinions[2],
    &teaOpinions[3],
    &teaOpinions[4]);
  
  for(int x =0;x<JUDGES;x++){
    answer += equals(teaType,teaOpinions[x]);
  }
  printf("%d\n",answer);
  
  return EXIT_SUCCESS;
}
