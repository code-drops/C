#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm,i,j;
 int xmid=0,ymid=0,maxx,maxy,color;
 int p[2][2],t,x=-1,y=-1;
 clrscr();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 printf("Enter the coordinates: ");
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
{
  scanf("%d",&p[i][j]);
}
 }
printf("Enter the axis to reflect about\n1.X axis\n2.Y axis \n3.Origin : ");
scanf("%d",&t);
xmid=getmaxx()/2;
ymid=getmaxy()/2;
maxx=getmaxx();
maxy=getmaxy();
line(xmid,0,xmid,maxy);
line(0,ymid,maxx,ymid);
rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
if(t==1)
x=1;
else if(t==2)
y=1;
for(i=0;i<2;i++)
{
p[i][0]=  p[i][0]*x;
p[i][1]=  p[i][1]*y;
}
 rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
 getch();
 closegraph();
}
