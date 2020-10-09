#include "library.h"

double height(double const v, double t)
{
	double const h = ((v*t) - (0.5*9.807*t*t));
	return(h);
}

void count(double A, double t, double const v, double const a)
{
	if (A<= t)
	{
		print ("After "); print(A); print( " seconds, the height is ");
		double result = height(v,A);
		print(result);
		new_line();
		double xcoord = (v*A)*(sin(a));
		set_pen_width(8);
	    set_pen_color(color::red);
		draw_point((xcoord+190),(630-result));
		count(A+0.05,t, v,a);
	}
}

void draw_square(int const x1, int const y1)
{ 
   set_heading_degrees(90);
   move_to(x1,y1);
   start_shape();
   draw_distance(100);        note_position();
   turn_right_by_degrees(90);
   draw_distance(100);        note_position();
   turn_right_by_degrees(90);
   draw_distance(100);        note_position();
   turn_right_by_degrees(90);
   draw_distance(100);        note_position();
}


void rectangle(int const x1, int const y1)
{
	 set_heading_degrees(90);
   move_to(x1,y1);
   start_shape();
   draw_distance(20);        note_position();
   turn_right_by_degrees(90);
   draw_distance(10);        note_position();
   turn_right_by_degrees(90);
   draw_distance(20);        note_position();
   turn_right_by_degrees(90);
   draw_distance(10);        note_position();
}





void line_and_turn(int const N, double const side, int const angle)
{
	if (N > 0)
	{
		draw_distance(side);
		turn_right_by_degrees(angle);
		line_and_turn(N-1,side,angle);
	}
}

void draw_circle(double const x, double const y, double const radius)
{


	double const PI = acos(-1.0);
	double const circumference = 2 * radius * PI;
	double const side = circumference / 360;
	draw_point(x,y);
	move_to(x,y-radius);
	line_and_turn(360,side,1);
}
void cannon(int const x,int const y,int const a,int const radius)
{ 
	draw_circle(x,y,radius);
	move_to(x-radius,y);
	set_heading_degrees(270-a);
	draw_distance(10);
	turn_right_by_degrees(90);
	draw_distance(35);
	turn_right_by_degrees(94.5);
	draw_distance(175);
	turn_right_by_degrees(85.5);
	draw_distance(20);
	draw_to(x-radius,y);
	


}

void main ()
{
	print ("enter velocity of cannonball: ");
	double const v = read_double();
	print("enter angle of cannon: ");
	int const a = read_int();
	double t = (2*v)/9.807;
	double A =0;
	int const x = 55;
	int const y = 695;
	int x1 = random_in_range(500,900);
	int y1 = 620;
	make_window(1500,700);
	draw_square(x1,y1);
	rectangle(x1+10, y1+15);
	rectangle(x1+50, y1+15);
	cannon(x,y,a,20);
	count(A,t,v,a);
    
}
