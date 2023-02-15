#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TIME_LIMIT 120
#define CITYSIZE 15
typedef struct{
  int c1,c2,time;
}Road;
typedef struct{
  int elapsedTime,path[CITYSIZE],pathSize;
}Result;
void resetGraph(int graphMap[][CITYSIZE]){
  for (int i = 0; i < CITYSIZE; i++){
    for (int j = 0; j < CITYSIZE; j++){
      graphMap[i][j]^=graphMap[i][j];
    }
  }
}
void fillGraph(int graphMap[][CITYSIZE],Road road){
  graphMap[road.c1-1][road.c2-1] = road.time;
  graphMap[road.c2-1][road.c1-1] = road.time;
}
void printGraph(int graphMap[][CITYSIZE]){
  for (int i = 0; i < CITYSIZE; i++){
    for (int j = 0; j < CITYSIZE; j++){
        printf("%u ", graphMap[i][j]);
    }
    printf("\n");
  }
}
void printPath(int array[CITYSIZE],int arrLen){
  for(int x=0;x<arrLen;x++)
    printf("%u ",array[x]);
  putchar('\n');
}
bool includes(int array[],int value){
  for(int x=0;array[x]!=0;x++){
    if(value==array[x])
      return true;
  }
  return false;
}
Result dijsktra(int graphMap[][CITYSIZE], int dest,int vertices){
  Result ret={.path={0},.elapsedTime=0};
  int pathIndex=1,sum=0,lastValue=0,lastCity=0;
  ret.path[0]=1;
  for(int x=0;x!=dest-1;){
    for(int y=0;y<vertices;y++){
      if (graphMap[x][y]!=0 && !includes(ret.path,y+1)){
        if(lastValue==0||graphMap[x][y]<lastValue){
          lastValue=graphMap[x][y];
          lastCity=y;
        }
      }
    }
    ret.path[pathIndex]=lastCity+1;
    pathIndex++;
    x=lastCity;
    ret.elapsedTime+=lastValue;
    lastValue^=lastValue;
  }
  ret.pathSize=pathIndex;
  return ret;
}
void printArrayReverse(int arr[CITYSIZE],int len){
  for(int x = len-1;x>=0;x--){
    printf("%u ",arr[x]);
  }
  putchar('\n');
}
void printResult(Result result){
  if(result.elapsedTime>TIME_LIMIT){
    printf("It will be %u minutes late. Travel time - %u - best way - ",
      result.elapsedTime-TIME_LIMIT,result.elapsedTime);
    printArrayReverse(result.path,result.pathSize);
  }else{
    printf("Will not be late. Travel time - %u - best way - ",result.elapsedTime);
    printArrayReverse(result.path,result.pathSize);
  } 
}
int main(void){
  int graphMap[CITYSIZE][CITYSIZE];
  int c,e;
  int c1,c2,t;
  int d;
  while(1){
    resetGraph(graphMap);
    scanf("%u %u",&c,&e);
    if (c==0||e==0)
      break;
    for(int x=0;x<e;x++){
      scanf("%u %u %u",&c1,&c2,&t);
      Road new = {.c1=c1,.c2=c2,.time=t};
      fillGraph(graphMap,new);
    }
    scanf("%u",&d);
    printGraph(graphMap);
    printResult(dijsktra(graphMap,d,c));
  }
  return EXIT_SUCCESS;
}
/*
  Valentina will start a new challenge this year: she will give programming classes!
She is really excited about this new activity, once programming is one of her biggest passions. 
These classes will happen at afternoons, in schools of many cities of her region and she has to go to these cities by car.
As Valentina is in the 3º year of Computer Science course, she needs to go back to her city in time to go to the univerisity.
The classes that she will teach end at 5:30 p.m. and her college classes start at 7:30 p.m, giving her 2 hours to come back to her city and go to her college classes.
Once that she is really smart and organized, Valentina collected information about the average travel time, in minutes, between the cities that she has to go to teach.
She wrote a list with this information and enumerated the cities with numbers from 1 to D, where city number 1 is her city.
The average time collected is bidirectional, that is, if from city 1 to city 2 the average travel time is 20 minutes, to go from city 2 to city 1 the time is the same.
Noting that she is really busy with the organization of her classes, you offered your help to build a program that discover the faster way to she goes and comes back
to her destiny and if she will come back to her city in time to her college classes, or if she will be late. You know that exist at least one road
that leads to each city and there's just one faster way to her travel.
Input:
The input consists of several test cases. The first line of each test contains two integers C (1 ≤ C ≤ 15) and E (1 ≤ E ≤ 225), 
indicating the number of cities and roads. The following E lines have three integers C1, C2 and T, 
identifying the average travel time T between the cities C1, C2. In the end, an integer D identifies the city that Valentina needs to go to teach.
A line with "0 0" ends the input.
Output:
If the travel time is less than 2 hours, you need to print "Will not be late. Travel time - M - best way - C1 C... CN", where M is the time travel
and CN are the cities that made the best sequence. Otherwise, you need to print "It will be L minutes late. Travel time - M - best way - C1 C... CN",
where L is the minutes of Valentina will be late.

input: 
  4 4
  1 2 20
  2 3 15
  2 4 10
  3 4 60
  4
  5 6
  1 4 120
  1 3 60
  2 3 30
  2 5 33
  3 4 50
  4 5 20
  5
  0 0

output:
  Will not be late. Travel time - 30 - best way - 4 2 1
  It will be 3 minutes late. Travel time - 123 - best way - 5 2 3 1 
*/
