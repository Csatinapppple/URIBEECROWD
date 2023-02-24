#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET 26
#define BUFFER 1000
#define isDot(x,y) (x=='.') ? true : -y
 
typedef struct{
  const char letter;
  const char *code;
}Code;

Code listOfLetters[ALPHABET] = {
  {.letter='a',.code="=.==="},
  {.letter='b',.code="===.=.=.="},
  {.letter='c',.code="===.=.===.="},
  {.letter='d',.code="===.=.="},
  {.code="=",            .letter='e'},
  {.code="=.=.===.=",	  .letter='f'},
  {.code="===.===.=",     .letter='g'},
  {.code="=.=.=.=",		  .letter='h'},
  {.code="=.=",			  .letter='i'},
  {.code="=.===.===.===", .letter='j'},
  {.code="===.=.===",	  .letter='k'},
  {.code="=.===.=.=",	  .letter='l'},
  {.code="===.===", 	  .letter='m'},
  {.code="===.=",		  .letter='n'},
  {.code="===.===.===",	  .letter='o'},
  {.code="=.===.===.=",	  .letter='p'},
  {.code="===.===.=.===", .letter='q'},
  {.code="=.===.=",		  .letter='r'},
  {.code="=.=.=",		  .letter='s'},
  {.code="===",			  .letter='t'},
  {.code="=.=.===",		  .letter='u'},
  {.code="=.=.=.===",	  .letter='v'},
  {.code="=.===.===",	  .letter='w'},
  {.code="===.=.=.===",   .letter='x'},
  {.code="===.=.===.===", .letter='y'},
  {.code="===.===.=.=",   .letter='z'},
};

char returnLetter(const char code[]){
  char ret=0;
  
  for(int i=0;i<ALPHABET;i++)
    if(strcmp(listOfLetters[i].code,code)==0){
      ret = listOfLetters[i].letter;
      break;
    }
    
  return ret;
}
//{"=.=.=0..."} {"=.=.=...."}
char *translate(const char morse[]){
  static char save[BUFFER],ret[BUFFER];
  size_t saveIndex = 0,dotCount=0,retIndex=0;
  for(size_t i = 0;morse[i]!='\0';i++){
    save[saveIndex] = morse[i];

    dotCount+=isDot(save[saveIndex],dotCount);

    if(dotCount==3){
      save[saveIndex-2]=0;
      ret[retIndex++]=returnLetter(save);
      saveIndex=-1;
    }else if(dotCount==7){
      save[saveIndex-6]=0;
      ret[retIndex++]=' ';
      saveIndex=-1;
    }

    saveIndex++;
  }
  save[saveIndex]=0;
  ret[retIndex++]=returnLetter(save);ret[retIndex]=0;
  return ret;
}

int main(){
  
  size_t t;
  scanf("%u",&t);getchar();
  
  for(size_t i=0;i<t;i++){ 
    char morse[BUFFER];
    gets(morse);
    printf("%s\n",translate(morse));
  }

  return EXIT_SUCCESS;
}
