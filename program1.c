#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct sales
{
    double profit;
    char month[30];
}; 

struct sales * readFile( )
{
    struct sales a[11];
    struct sales* n = a;
    
    a[0].profit = 23458.01;
    a[1].profit = 40112.00;
    a[2].profit = 56011.85;
    a[3].profit = 37820.88;
    a[4].profit = 37904.67;
    a[5].profit = 60200.22;
    a[6].profit = 72400.31;
    a[7].profit = 56210.89;
    a[8].profit = 67230.84;
    a[9].profit = 68233.12;
    a[10].profit = 80950.34;
    a[11].profit = 95225.22;

 
  strcpy(a[0].month, "January");
  strcpy(a[1].month, "February");
  strcpy(a[2].month, "March");
  strcpy(a[3].month, "April");
  strcpy(a[4].month, "May");
  strcpy(a[5].month, "June");
  strcpy(a[6].month, "July");
  strcpy(a[7].month, "August");
  strcpy(a[8].month, "September");
  strcpy(a[9].month, "October");
  strcpy(a[10].month, "November");
  strcpy(a[11].month, "December");

  return n;
    
}//end readFile

//takes an array and finds both the minimum and the maximum
struct sales minMax (struct sales m[], int n)
{
    struct sales min, max = m[0];
    //float max = m[0].profit;
    
     
    for(int i = 1; i <= 11; i++)
    {
        if (min.profit > m[i].profit)
            min = m[i];
        
        
        if (max.profit < m[i].profit)
            max = m[i];
        
        
        if (n==0)
            return min;
            
        if (n==1)
            return max;
        
    }
   
} //end minMax


float average (struct sales m[])
{
    float total = 0;
    
    for(int i = 0; i <= 11; i++)
    {
        total= total+m[i].profit;
    }
    
    total = total/12;
    
    return total;
    
}//end average


float * movingAverage(struct sales m[])
{
    float averages[6];
    
    
    for(int i= 0; i < 8; i++)
    {
        float total = 0;
        for(int j=0; j<6; j++)
        {
            total += m[i].profit;
            j++;
        }
        
        averages[i] = total;
        i++;
    }//end for
    
}//end movingAverages

struct sales* sortSales(struct sales m[])
{
    struct sales s[11];
    
    for (int i = 0; i < 11; i++)
    {
        s[i] = m[i];
    }


    struct sales temp;
    
    for (int i = 0; i < 11; i++)
    {
        
        for (int j = i+1; j < 11; j++)
        {
            if (s[i].profit < s[j].profit)
            {
              temp = s[i];
              s[i] = s[j];
              s[j] = temp;
                
            }// end if
        }
    }// end nested loop
    
    return s;
    
}//end sort sales



int main()
{
    
struct sales* a = readFile();
struct sales report[11];

for(int i = 0; i <12; i++)
{
    *(a+i)= report[i];
}

printf("Monthly sales report for 2022\n");
printf("Month     Sales\n");

for (int i=0; i <12; i++)
{
    printf("%s,  $%f",report[i].month, *report[i]profit);
}

printf("\nSales Summary: \n\n");

struct sales min = minMax(report[],0);
struct sales max = minMax(report[],1);
float average = average(report[]);

printf("Minimum Sales: $%f (%s)\n", min.profit, min.month);
printf("Maximum Sales: $%f (%s)\n", max.profit, max.month);
printf("Average Sales: $%f\n\n", average);

printf("Six-Month Moving Average Report:\n\n");

float* t = movingAverages(report[]);

printf("January - June    $%f\n", *(t + 0));
printf("February - July   $%f\n", *(t + 1));
printf("February - July   $%f\n", *(t + 2));
printf("March - August    $%f\n", *(t + 3));
printf("April - September $%f\n", *(t + 4));
printf("May - October     $%f\n", *(t + 5));
printf("June - November   $%f\n", *(t + 6));
printf("July - December   %%f\n",*(t + 7));

a = sortSales(report[i]);


for(int i = 0; i <12; i++)
{
    *(a+i)= report[i];
}

printf("\nSales Report: (Highest to Lowest)\n\n");
printf("   Month   Sales   \n\n");

for(int i = 0; i <12; i++)
{
    printf("%s   $%f\n", report[i].month, report[i].profit);
}


return 0;
}

