#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define TIME_LIMIT 120
#define CITY_SIZE 15

typedef struct{
  int c1,c2,time;
}Road;

typedef struct{
  int elapsedTime,path[CITY_SIZE],target;
}Result;

typedef enum{
  UNDEFINED=false,
  DEFINED=true,
  INFINITY=INT_MAX,
}State;

void resetGraph(int graphMap[][CITY_SIZE],int vertices){
  for (int i = 0; i < vertices; i++)
    for (int j = 0; j < vertices; j++)
      graphMap[i][j]^=graphMap[i][j];
}
void fillGraph(int graphMap[][CITY_SIZE],Road road){
  graphMap[road.c1-1][road.c2-1] = road.time;
  graphMap[road.c2-1][road.c1-1] = road.time;
}

void printPath(int arr[],int target){
  int loop = target;

  printf("%d ",target+1);
  while(loop>0){
    printf("%d",arr[loop]+1);
    loop = arr[loop];
    if(loop>0)
      putchar(' ');
  }
  putchar('\n');
}

int minDistance(int dist[],int prev[],int vertices){
  int min=INFINITY,minIndex;
  
  for(int i=0;i<vertices;i++)
    if(!prev[i] && dist[i] < min)
      min = dist[i],minIndex=i;
  
  return minIndex;
}

Result dijkstra(int graph[CITY_SIZE][CITY_SIZE], int target,int vertices){
  int distance[CITY_SIZE],previous[CITY_SIZE];
  Result ret = {.target=target};
  
  for (int v=0;v<vertices;v++)
    distance[v]=INFINITY,previous[v]=UNDEFINED,ret.path[v]=-1;
  
  distance[0]=0;
  for(int q = 0;q<vertices;q++){
    int u = minDistance(distance,previous,vertices);
    previous[u]=DEFINED;
    for(int v=0;v<vertices;v++){
      if(!previous[v] && graph[u][v] && distance[u] != INFINITY 
      && distance[u] + graph[u][v] < distance[v]){
        distance[v] = graph[u][v] + distance[u];
        ret.path[v]=u;
      }
    }
    if(u==target){
      break;
    }
  }

  ret.elapsedTime=distance[target];
  return ret;
}

void printResult(Result result){
  if(result.elapsedTime>TIME_LIMIT){
    printf("It will be %d minutes late. Travel time - ",result.elapsedTime-TIME_LIMIT);
  }else{
    printf("Will not be late. Travel time - ");
  } 
  printf("%d - best way - ",result.elapsedTime);
  printPath(result.path,result.target);
}

int main(void){
  int graphMap[CITY_SIZE][CITY_SIZE];
  int c,e;
  int c1,c2,t;
  int d;
  while(1){
    scanf("%d %d",&c,&e);
    resetGraph(graphMap,c);
    
    if (c==0||e==0)
      break;
    
    for(int x=0;x<e;x++){
      scanf("%d %d %d",&c1,&c2,&t);
      Road new = {.c1=c1,.c2=c2,.time=t};
      fillGraph(graphMap,new);
    }
    scanf("%d",&d);
    //dijkstra(graphMap,d-1,c);
    printResult(dijkstra(graphMap,d-1,c));
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
