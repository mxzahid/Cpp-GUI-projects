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
	draw_distance(50);
	turn_right_by_degrees(90);
	draw_distance(90);
	turn_right_by_degrees(94.5);
	draw_distance(400);
	turn_right_by_degrees(85.5);
	draw_distance(60);
	draw_to(x-radius,y);
    /*move_to(x+50,y);
	set_heading_degrees(90);
	draw_distance(250);
	turn_left_by_degrees(90);
	draw_distance(60);
	turn_left_by_degrees(85.5);
	draw_distance(400);*/

}

	
void main()
{
	int const x = 410;
	int const y =500;
	int const N = 360;
	int const angle = 360 / N;
	int const side = 4;
	int a=read_int();
	//int const a = 0;
	double const radius = 50;
	make_window(800,800);
	set_pen_width(3);
	set_heading_degrees(90);
	cannon(x,y,a,radius);

}
