#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
 int gd=DETECT,gm,i,j;
 int xmid=0,ymid=0,maxx,maxy;
 float p[2][2],t[2],xf,yf;
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
 printf("Enter the value of fixed point:\n");
scanf("%f%f",&xf,&yf);
 printf("Enter the scaling coordinates:");
 for(i=0;i<2;i++)
{
  scanf("%f",&t[i]);
}
xmid=getmaxx()/2;
 ymid=getmaxy()/2;
 maxx=getmaxx();
 maxy=getmaxy();
 line(xmid,0,xmid,maxy);
 line(0,ymid,maxx,ymid);
 rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
for(i=0;i<2;i++)
{
p[i][0]=(xf+(p[i][0]-xf)*t[0]);
   p[i][1]=(yf+(p[i][1]-yf)*t[1]);
  
}

rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
 getch();
 closegraph();
}
