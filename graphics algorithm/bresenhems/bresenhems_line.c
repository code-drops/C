#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
int main()
{
  int gd = DETECT, gm;    
 float x0,y0,xn,yn,xmid,ymid,end,dx,dy,xin,yin,x,y,p;
 initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
 xmid=getmaxx()/2;
 ymid=getmaxy()/2;
 printf("Enter the starting coordinates...")   ;
 scanf("%f %f",&x0,&y0);
 printf("Enter the ending coordinates...")    ;
 scanf("%f %f",&xn,&yn);
 dx=xn-x0;
dy=yn-y0; 
       p=2*dy-dx;
 line(0,ymid,2*xmid,ymid);
 line(xmid,0,xmid,2*ymid);
 if(x0>xn)
 {
  x=xn;
  y=yn;
  end=x0;
}
 else
 {
  x=x0;
  y=y0;
  end=xn;
 }
 putpixel(x+xmid,ymid-y,RED);
 while(x<=end)
 {
  if(p<0)
  {
   x++;
   p=p+2*dy;
  }
  else
  {
   x++;
   y++;
   p=p+2*(dy-dx);
  }
  putpixel(x+xmid,ymid-y,RED);
  delay(100);
 }
 getch();
 return 0;
}
