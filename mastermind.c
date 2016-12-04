#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void rules()
{
FILE *fp;
char c;
fp=fopen("rules.txt","r");
while(!feof(fp))
{
c=fgetc(fp);
printf("%c",c);
}
fclose(fp);
}
void credits()
{
FILE *fp;
char c;
fp=fopen("credits.txt","r");
while(!feof(fp))
{
c=fgetc(fp);
printf("%c",c);
}
fclose(fp);
}
int player_select()
{ 
int n;
printf("\n\t\t\tMAIN MENU");
printf("\n\t\t1.Rules");
printf("\n\t\t2.Single Player");
printf("\n\t\t3.Two Players");
printf("\n\t\t4.Exit");
printf("\n\t\tEnter Your Choice <<1,2,3,4>>:");
scanf("%d",&n);
return n;
}
int difficulty_select(int d)
{ 
int n,j,a[4],flag=0,i;
srand(time(NULL));
while(1)
{
int r = 1000 +rand() % 9000;
n=r;
if(d==1)
{
for(j=0;j<4;j++)
{
a[j]=r%10;
r/=10;
}  
if(a[0]!=a[1] && a[0]!=a[2] && a[0]!=a[3] && a[1]!=a[2] && a[1]!=a[3] && a[2]!=a[3])
break;   
} 
if(d==2)
{
for(j=0;j<4;j++)
{
a[j]=r%10;
r/=10;
}  
for(i=0;i<4;i++)
{
for(j=i+1;j<4;j++)
{
if(a[i]==a[j])
{
flag=1;
break;
}
}
}             
if(flag==1)
break;
}  
}
return n;
}
void single_player()
{  
system("clear");
int j,a[4],d;
printf("\tSelect the Difficulty:");
printf("\n\n\t\t1.Easy");
printf("\n\n\t\t2.Hard");
printf("\n\n\t\tEnter Your Choice <<1,2>>:");
scanf("%d",&d);
int r=difficulty_select(d);
for(j=0;j<4;j++)
{
a[j]=r%10;
r/=10;
}
printf("You have been provided with ten chances to guess the number! Good Luck!\n");
second_player(a);  
}
void two_player()
{
system("clear");
int i,j,a[4];
printf("\nPlayer 1: Enter a four digit number:");
scanf("%d",&i);
for(j=0;j<4;j++)
{
a[j]=i%10;
i/=10;
}
system("clear");
printf("Now its Player Two's Turn!\nYou Have Ten Chances!! Good Luck!\n");
second_player(a);  
}
second_player(int a[4])
{	
int i,j,k,b[4],flag=0;
for(k=0;k<10;k++)
{
printf("\nTry No:%d\n",k+1);
scanf("%d",&i);
for(j=0;j<4;j++)
{
b[j]=i%10;
i/=10;
}
if(a[0]==b[0] && a[1]==b[1] && a[2]==b[2] && a[3]==b[3])
{
flag=k+1; 
break;
}	
else 
{ 
cows(b,a);
bulls(b,a);
}
}
switch(flag)
{
case 0:
printf("\n\nSorry! Ten chances are done! GAME OVER.");
printf("\nThe Number Was:");
for(i=3;i>=0;i--)
printf("%d",a[i]);
break;
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
case 8:
case 9:
case 10:printf("\bWOW! Amazing! That is perfectly correct!");
system("clear");
break;
}


}
cows(int b[4],int a[4])
{ 
int count=0,i,j;
int index[4]={-2,-2,-2,-2};
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
if(j!=index[0] && j!=index[1] && j!=index[2] && j!=index[3])
{
if(a[j]==b[i] && b[j]!=a[j])
{
count++;
index[i]=j;
break;
}
if(b[j]==a[j])
{
index[i]=j;
}
}
}
}
printf("The No of Cows:%d\n",count);
}
bulls(int b[4],int a[4])
{
int count=0,i; 
for(i=0;i<4;i++)
{
if(a[i]==b[i])
count++;
}
printf("The No of Bulls:%d\n",count);

}

main()
{    
system("clear");
printf("\t\t\tWELCOME TO MASTERMIND...\n");
while(1)
{
int n=player_select();
if(n==1)
rules();
if(n==2)
single_player();
if(n==3)
two_player();
if(n==4)
{
credits();
break;
}
}
}
