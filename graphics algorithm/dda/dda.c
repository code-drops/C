#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>

int main()
{
  int gd = DETECT, gm;    
 float x0,y0,xn,yn,xmid,ymid,step,dx,dy,xin,yin,x,y;
int i;
 initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
 xmid=getmaxx()/2;
 ymid=getmaxy()/2;
 printf("Enter the starting coordinates...")   ;
 scanf("%f %f",&x0,&y0);
 printf("Enter the ending coordinates...")    ;
 scanf("%f %f",&xn,&yn);
 dx=xn-x0;
dy=yn-y0;
 line(0,ymid,2*xmid,ymid);
 line(xmid,0,xmid,2*ymid);
 if(abs(dx)>=abs(dy))
  step=dx;
 else
  step=dy;
 xin=dx/step;
x=x0;
 yin=dy/step;
y=y0;
 for(i=0;i<=step;i++)
 { 
  putpixel(x+xmid,ymid-y,RED);
  x=x+xin ;
  y=y+yin;
 }
 getch();
 return 0;
}
