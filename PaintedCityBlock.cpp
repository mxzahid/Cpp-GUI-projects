#include "library.h"

void window(int height, int width, int x, int y,int color)
{
	double b;
	b=random_in_range(0.0,1.0);
start_shape();
move_to(x,y);
set_heading_degrees(0);
set_pen_color(1.0,1.0,b);
draw_distance(height);note_position();
set_heading_degrees(90);
draw_distance(width);note_position();
set_heading_degrees(180);
draw_distance(height);note_position();
set_heading_degrees(270);
draw_distance(width);note_position();
fill_shape();
}
void row_windows(int height,int width, int x, int y, int number_of_windows, int color)
{
	while(number_of_windows>0)
	{
	window(height,width,x,y,color);
	x=x+30;
	number_of_windows--;
	}
}
void row_windowshouse(int height,int width, int x, int y, int number_of_windows, int color)
{
	while(number_of_windows>0)
	{
	window(height,width,x,y,color);
	x=x+60;
	number_of_windows--;
	}
}
void block_of_windows(int number_of_floors, int number_of_windows,int x, int y,int height, int width, int color)
{
	while(number_of_floors>0)
	{
set_pen_color(0.7,1.0,color);
	row_windows(height,width,x,y,number_of_windows,color);
	y=y+30;
	number_of_floors--;
	}
}
void building(int x, int y, int overallwidth)
{
	int height=random_in_range(10,20);
	int colorbuilding=random_in_range(0.5,1.0);
	int colorbuilding2=random_in_range(0.0,1.0);
	int color=random_in_range(1,7);
	int floornumber=height;
	int windownumber=random_in_range(3,overallwidth);
	set_pen_color(0.7,colorbuilding2,colorbuilding);
	int z=31*windownumber;
fill_rectangle(x-10,y-15,z,height+y);
block_of_windows(floornumber,windownumber,x,y,10,20,color);
}
void house(int x, int y)
{
	double r,g,b;
	r=random_in_range(0.2,1.0);
	g=random_in_range(0.0,1.0);
	b=random_in_range(0.4,1.0);
	set_pen_color(r,g,b);
	fill_rectangle(x-15,y-25,110,110,-2);
	row_windowshouse(10,20,x,y,2,2);
	window(10,20,x,y+40,2);
	set_pen_color(color::black);
	fill_rectangle(x+25,y+30,30,50,-2);
	window(10,20,x+60,y+40,2);
	move_to(x+30,y-25);
	start_shape();
	int r1=random_in_range(0.2,1.0);
	int g1=random_in_range(0.0,0.8);
	int b1=random_in_range(0.4,1.0);
	set_pen_color(r1,g1,b1);
	draw_distance(90);note_position();
	set_heading_degrees(60);
	draw_distance(100);note_position();
	set_heading_degrees(115);
	draw_distance(120);note_position();
	set_heading_degrees(270);
	draw_distance(90);note_position();
	fill_shape();
}
void stars()
{
	int r=random_in_range(0,1000);
	while(r>0)
	{
	int x;
	int y;
	x=random_in_range(0,1000);
	y=random_in_range(0,1000);
	set_pen_color(color::white);
	draw_point(x,y);
	r=r-1;
	}
}
void trees()
{
	int x=random_in_range(0,1000);
	int y=random_in_range(0,1000);
	set_pen_color(color::brown);
	move_to(x,700);
	start_shape();
	set_heading_degrees(90);
	draw_distance(10);note_position();
	set_heading_degrees(180);
	draw_distance(70);note_position();
	set_heading_degrees(270);
	draw_distance(10);note_position();
	set_heading_degrees(360);
	draw_distance(70);note_position();
	fill_shape();
	move_to(x,700);
	set_pen_width(50);
	int times=1000;
	while(times>0)
	{
	set_pen_color(color::green);
	draw_point();
	times--;
	}
	set_pen_width(1);

}
void sky()
{
	int time = random_in_range(0,23);
	set_pen_color(color::white);
	move_to(40,40);
	if (time <= 6 || time >= 19)
	{
		set_pen_color(color::black);
		fill_rectangle(0,0,1000,1000);
		stars();
		set_pen_color(color::white);
		set_pen_width(55);
		draw_point(700,200);
	    set_pen_width(1);
	}
	else 
	{ 
		set_pen_color(color::light_blue);
		fill_rectangle(0,0,1000,1000);
		move_to(800,200);
		set_pen_color(color::yellow);
		set_pen_width(60);
		draw_point();
		set_pen_width(1);

	}
}
void cityscene(double x, int y)
{
		sky();
		
	while(x<=1000)
	{
	building(x,y+x/3,10);
	house(x+33,680);
	x=x+200;
	trees();
	}
}
void main()
{
make_window(1000,1000);
	//block_of_windows(5,5,40,40,10,20,7);
	//building(17,380,20);
cityscene(30,380);

}
