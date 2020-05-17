#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void main()
{
 int gd=DETECT,gm,i,j;
 int xmid=0,ymid=0,maxx,maxy,xf,yf,ra;
 float theta;
 float p[2][2];
 clrscr();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 printf("Enter the coordinates");
 for(i=0;i<2;i++)
 {
for(j=0;j<2;j++)
   {
scanf("%f",&p[i][j]);
}
 }
 printf("Enter the value of fixed point and angle of rotation:\n");
scanf("%d%d%d",&xf,&yf,&ra);
 xmid=getmaxx()/2;
 ymid=getmaxy()/2;
 maxx=getmaxx();
 maxy=getmaxy();
line(xmid,0,xmid,maxy);
line(0,ymid,maxx,ymid);
rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
theta=(float)(ra*(3.14/180));
for(i=0;i<2;i++)
{
  p[i][0]=ceil((xf+((p[i][0]-xf)*cos(theta)-(p[i][1]-yf)*sin(theta))));
  p[i][1]=ceil((xf+((p[i][0]-xf)*sin(theta)+(p[i][1]-yf)*cos(theta))));

}
rectangle(xmid+p[0][0],ymid-p[0][1],xmid+p[1][0],ymid-p[1][1]);
 getch();
 closegraph();
}
