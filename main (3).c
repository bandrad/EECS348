
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int points;
    
    printf("----NFL Points Simulator----\n");
    printf("( enter 0 or 1 to STOP )\n\n");
    printf("ENTER a NFL score: ");
    
    scanf("%d",&points);
    
    if(points <= 1)
    {
        exit(1);
    }
    else
        pointCombos(points, 0);


}

void  pointCombos ( int points, int i)
{
    int scores[5];
    int sum = 0;
    
    
    int safety = points / 2;
    
    safety = safety - i;
    if (safety < 0)
        safety = 0;
    
    
    int r = points % 2;
    r += i*2;
    sum +=safety*2;
    
    scores[4] = safety;
    
    int fieldGoal = r / 3;
    r = r % 3;
    scores[3] = fieldGoal;
    sum += fieldGoal*3;
    
    int touchDown = r / 6;
    r =r % 6;
    scores[2] = touchDown; 
    sum += touchDown *6;
    
    int tD1 = r/7;
    r=r % 7;
    scores[1] = tD1;
    sum += tD1*7;
    
    int tD2 = r/8;
    scores[0] = tD2;
    sum += tD2 *8;
    
    
    if (sum == points)
        printCombos(scores);
     
     
     i++;
     pointCombos(points, i);  

}//end pointCombos
    
void printCombos (int a[])
{
    printf("%d TD + 2, %d TD + FG, %d TD, %d 3pt, %d Saftey \n", a[0],a[1], 
    a[2], a[3], a[4] );
    
}

  
