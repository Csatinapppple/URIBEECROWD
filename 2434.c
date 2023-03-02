#include <stdio.h>
#include <stdlib.h>

int main(void){

  int saldo_adicional,saldo_atual,menor_saldo,casos;
  scanf("%d %d",&casos,&saldo_atual);getchar();
  menor_saldo = saldo_atual;

  for(size_t i = 0; i<casos; i++){ 

    scanf("%d",&saldo_adicional);getchar();
    
    saldo_atual+=saldo_adicional;
    if(saldo_atual<menor_saldo)
      menor_saldo = saldo_atual;
  }
  printf("%d\n", menor_saldo);

  return EXIT_SUCCESS;
}
