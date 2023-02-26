/*
  terceiro link, t              2
  segundo link , t*2            4
  primeiro link, (t*2)*2 / t*4  8
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
  size_t t;
  scanf("%u",&t);getchar();
  printf("%u\n",t*4);
  return EXIT_SUCCESS;
}