#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main()
{
 int gd=DETECT,gm,i,j;
 int xmid=0,ymid=0,maxx,maxy;
 int p[2][2],t[2];
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
 printf("Enter the translation coordinates: ");
 for(i=0;i<2;i++)
{
scanf("%d",&t[i]);
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
  p[i][0]=(p[i][0])+t[0];
    p[i][1]=(p[i][1])+t[1];
 }
 rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
 getch();
 closegraph();
}
