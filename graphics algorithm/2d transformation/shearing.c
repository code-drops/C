#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm,i,j;
 int xmid=0,ymid=0,maxx,maxy,ch;
 float p[2][2],xf,yf,x1s,y1s;
 clrscr();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 printf("Enter the coordinates:");
 for(i=0;i<2;i++)
 {
  for(j=0;j<2;j++)
 {
  scanf("%f",&p[i][j]);
}
 }
printf("\nEnter your choice:\n1.x-direction shear\n2.y-direction shear\nEnter your choice:\n");
scanf("%d",&ch);
xmid=getmaxx()/2;
 ymid=getmaxy()/2;
 maxx=getmaxx();
 maxy=getmaxy();

switch(ch)
{
case 1:
printf("Enter the value of shear:\n");
scanf("%f",&x1s);
printf("Enter the value of fixed point:\n");
scanf("%f",&yf);
line(xmid,0,xmid,maxy);
 line(0,ymid,maxx,ymid);
 rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
for(i=0;i<2;i++)
{
   p[i][0]=p[i][0]+(p[i][0]-yf)*x1s;
   p[i][1]=p[i][1];
  
}
break;
case 2:
printf("Enter the value of shear:\n");
scanf("%f",&y1s);
printf("Enter the value of fixed point:\n");
scanf("%f",&xf);
line(xmid,0,xmid,maxy);
 line(0,ymid,maxx,ymid);
 rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
for(i=0;i<2;i++)
{
   p[i][0]=p[i][0];
   p[i][1]=p[i][1]+(p[i][1]-xf)*y1s;
 }
break;
default:
exit(0);
}

rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
 getch();
 closegraph();
}
