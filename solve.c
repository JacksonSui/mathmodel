#include<stdio.h>
#include<stdlib.h>
int rand1(void);
int main()
{
    FILE *fp;
    fp=fopen("output.csv","w");
    float origin[25]={348,352,347,349,347.5,347,330,329,329,327.5,329,331.5,348.5,347,346.5,348,333,330,332.5,331.5,331.5,332,332};
    float target[25]={0};
    float total[5]={0};
    int times=0;
    int r_times=0;
    int k,m,n,t,max;
    printf("Please enter the max value:");
    scanf("%d",&max);
    getchar();
    while(1)
    {
      for(m=0;m<25;m++)
      {
        k=rand1();
        target[k]=origin[m];
      }
      for(n=0;n<25;n++)
      {
        total[n/5] += target[n];
      }
	    if(abs(total[0]-total[1])<max&&abs(total[1]-total[2])<max&&abs(total[2]-total[3])<max&&abs(total[3]-total[4])<max&&abs(total[4]-total[0])<max)
      {
        for(m=0;m<25;m++)
          fprintf(fp,"%.1f,",target[m]);
        for(m=0;m<5;m++)
          fprintf(fp,"%.1f,",total[m]);
        fprintf(fp,"\n");
          times++;
      }
      for(n=0;n<25;n++)
      {
        target[n]=0;
        total[n/5]=0;
      }
      if(r_times%100000==0)
      {
        printf("Number of possible solution found in %d times run:%d\n",r_times,times);
        printf("counting...(PRESS CTRL+C to stop.)\n");
      }
      r_times++;
      if(r_times>20000000000&&times==0)
        printf("No solution found.");
    }
}

int rand1(void)
{
  static int arr[25]={-1};
  static int times=0;
  int a;
  int n=(unsigned int)rand()%25;
  while(1)
  {
    for(a=0;a<24;a++)
    {
      if(n!=arr[a]&&times!=0)
        continue;
      break;
    }
    if(a==24||times==0)
    {
      arr[times]=n;
      times++;
      break;
    }
    else
      n=rand()%25;
  }
  if(times==25)
  {
    times=0;
    for(a=0;a<25;a++)
      arr[a]=-1;
  }

  return n;
}
