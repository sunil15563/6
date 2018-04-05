#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void colorpixel(int x,int y,int color)
{
	putpixel(x+(getmaxx()/2),(getmaxy()/2)-y,color);
}
void drawaxis()
{
	int xmid=getmaxx()/2;
	int ymid=getmaxy()/2;
	line(xmid,0,xmid,getmaxy());
	line(0,ymid,getmaxx(),ymid);
}