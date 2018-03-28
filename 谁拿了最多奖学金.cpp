 #include <stdio.h>
#include <string.h>
struct student
{

    char name[20];

    int endingresult;//期末平均成绩

    int classresult;//班级评议成绩

    char a;//a为干部；

    char b;//b为西部学生；

    int number;//论文数目

}data[100];

int main()

{

    int n,i;

    scanf("%d",&n);

    for(i=1;i<=n;i++)

    {

        scanf("%s %d %d %c %c %d",
			data[i].name,
			&data[i].endingresult,
			&data[i].classresult,
			&data[i].a,
			&data[i].b,
			&data[i].number);

    }

    int data1[101]={0};

    for(i=1;i<=n;i++)

    {

        data1[i]=0;

        if((data[i].endingresult>80)&&(data[i].number>=1))

        data1[i]=data1[i]+8000;

        if((data[i].endingresult>85)&&(data[i].classresult>80))

        data1[i]=data1[i]+4000;

        if(data[i].endingresult>90)

        data1[i]=data1[i]+2000;

        if((data[i].endingresult>85)&&(data[i].b=='Y'))

        data1[i]=data1[i]+1000;

        if((data[i].classresult>80)&&(data[i].a=='Y'))

        data1[i]=data1[i]+850;

    }

    int max;

    max=0;

    int sum;

    sum=0;

    for(i=1;i<=n;i++)

    {

        sum=sum+data1[i];

        printf("%d\n",sum);

    }

    for(i=1;i<=n;i++)

    {

        if(data1[i]<data1[i+1])

        {

            max=i+1;

        }

    }

    printf("%s\n%d\n",data[max].name,data1[max]);





    printf("%d",sum);

    return 0;

}