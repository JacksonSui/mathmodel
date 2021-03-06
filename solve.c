#include<stdio.h>
#include<stdlib.h>
int rand1(void);
int main()
{
    FILE *fp=fopen("output.csv","w");//确定输出文件名
    float origin[25]={348,352,347,349,347.5,347,330,329,329,327.5,329,331.5,348.5,347,346.5,348,347.5,348,333,330,332.5,331.5,331.5,332,332};
    float target[25]={0};//建立随机分配的工件质量数组
    float total[5]={0};//建立每一次计算出的的各扇形零件质量和数组
    int solve=0;//记录已求得解的个数
    int runtime=0;//记录程序运行的次数
    int index,m,max;
    printf("Please enter the max value:");
    scanf("%d",&max);
    getchar();
    while(1)
    {
      for(m=0;m<25;m++)
      {
        index=rand1();//随机分配索引
        target[index]=origin[m];
      }
      for(m=0;m<25;m++)
        total[m/5] += target[m];
      if(abs(total[0]-total[1])<max&&abs(total[1]-total[2])<max&&abs(total[2]-total[3])<max&&abs(total[3]-total[4])<max&&abs(total[4]-total[0])<max)
      {        for(m=0;m<25;m++)
          fprintf(fp,"%.1f,",target[m]);
        for(m=0;m<5;m++)
          fprintf(fp,"%.1f,",total[m]);
        fprintf(fp,"\n");
        fflush(fp);
	      solve++;
      }
      for(m=0;m<25;m++)
      {
        target[m]=0;
        total[m/5]=0;
      }
      if(runtime%500000==0)
      {
        printf("Number of possible solution found in %d solve run:%d\n",runtime,solve);
        printf("counting...(PRESS CTRL+C to stop.)\n");
      }
      runtime++;
      if(runtime==100000000||solve==10000)
      {
	       printf("enough.");
	       break;
      }
      if(runtime==100000000&&solve==0)
      {
        printf("No solution found.");
        break;
    }
}

int rand1(void)
{
  static int randindex[25]={-1};//建立每个运行周期所分配的随机索引数组
  static int times=0;
  int a;
  int n=(unsigned int)rand()%25;
  while(1)
  {
    for(a=0;a<24;a++)
    {
      if(n!==randinde[a]&&times!=0)//保证在同一个运行周期中随机分配的索引各不相同
        continue;
      break;
    }
    if(a==24||times==0)
    {
      randindex[times]=n;
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
      randindex[a]=-1;
  }//运行周期结束，清空记录的索引
return n;
}
