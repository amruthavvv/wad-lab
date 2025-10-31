#include<stdio.h>
#define MAX 100


int max[MAX][MAX];
int alloc[MAX][MAX];
int need[MAX][MAX];
int avail[MAX];
int n,r;

void input();

void cal();
int main()
{
    input();
 
    cal();
    return 0;
}
void input()
{
  int i,j;
  printf("enter the no of process:");
  scanf("%d",&n);
  printf("enter the no of resources types:");
  scanf("%d",&r);
  printf("enter the max matrix:");
  for(i=0;i<n;i++)
    {
       for(j=0;j<r;j++)
        {
          scanf("%d",&max[i][j]);
        }
    }
    printf("enter the allocation matrix:");
  for(i=0;i<n;i++)
    {
       for(j=0;j<r;j++)
        {
          scanf("%d",&alloc[i][j]);
        }
    }
   printf("enter the  availability resources:");
  for(j=0;j<r;j++)
        {
          scanf("%d",&avail[j]);
        }
  for(i=0;i<n;i++)
    {
       for(j=0;j<r;j++)
        {
          need[i][j]=max[i][j]-alloc[i][j];
        }
    }
}

void cal()
{
int i,j,k,finish[MAX]={0},safeseq[MAX],count=0;
printf("\n p\t max \t alloc \t need \t avail\t");
  while(count<n)
   {
      int found=0;
       for(i=0;i<n;i++)
        {
          if(!finish[i])
           {
             int canrun=1;
               for(j=0;j<r;j++)
                {
                  if(need[i][j]>avail[j])
                   {
                     canrun=0;
                     break;
                   }
                }
               if(canrun) 
                {
                  for(k=0;k<r;k++)
                   avail[k]+=alloc[i][k];
                
                  printf("\np%d ",i);
                  printf("\t");
                  for(j=0;j<r;j++)
                  printf("%d ",max[i][j]);
                  printf("\t");
                  for(j=0;j<r;j++)
                  printf("%d ",alloc[i][j]);
                  printf("\t");
                  for(j=0;j<r;j++)
                  printf("%d ",need[i][j]);
                  printf("\t");
                  for(j=0;j<r;j++)
                  printf("%d ",avail[j]);
                  printf("\t");
                
                
                safeseq[count++]=i;
                finish[i]=1;
                found=1;
                }
           }
        }
        if(!found)
         {
           printf("not safe");
           return;
         }
   }
   printf("\n safe sequence is : ");
   for(i=0;i<n;i++)
    printf("p%d->",safeseq[i]);
    printf("\nsafe");
}
