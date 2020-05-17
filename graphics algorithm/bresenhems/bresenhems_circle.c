#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<graphics.h>
void circleplot(int,int,int,int);
int main()
{
  int gd = DETECT, gm;
 int  x0,y0,r,xmid,ymid,end,xin,yin,x,y,p;
 initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
 xmid=getmaxx()/2;
 ymid=getmaxy()/2;
 printf("Enter the centre coordinates...")   ;
 scanf("%d %d",&x0,&y0);
 printf("Enter the radius...")    ;
 scanf("%d",&r);
 p=3-2*r;
 line(0,ymid,2*xmid,ymid);
 line(xmid,0,xmid,2*ymid);
 x=0;
y=r;
 circleplot(xmid+x0,ymid-y0,x,y);
  while(x<y)
 {       if(p<0)
  {
   x++;
   p=p+4*x+6;
  }
  else
  {
   x++;
   y--;
   p=p+4*x-4*y+10;
  }
  circleplot(xmid+x0,ymid-y0,x,y);
 }

 getch();
 return 0;
}
void circleplot(int xc,int yc,int x,int y)
{
   putpixel(xc+x,yc+y,RED) ;
   putpixel(xc+y,yc+x,RED) ;
   putpixel(xc-y,yc+x,RED) ;
   putpixel(xc-x,yc+y,RED) ;
   putpixel(xc-x,yc-y,RED) ;
   putpixel(xc-y,yc-x,RED) ;
   putpixel(xc+y,yc-x,RED) ;
   putpixel(xc+x,yc-y,RED) ;

}
