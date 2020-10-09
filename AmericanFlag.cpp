#include "library.h"

void draw_a_star( int const x, int const y, int const dist)
{
	move_to(x,y);
	start_shape(); 
	note_position();
	set_heading_degrees(90);
	draw_distance(dist);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(dist);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(dist);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(dist);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(dist);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(dist);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(dist);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(dist);
	note_position();
	turn_right_by_degrees(144);
	draw_distance(dist);
	note_position();
	turn_left_by_degrees(72);
	draw_distance(dist);
	fill_shape();
	
}

void draw_rectangle(int const x, int const y, int const side1, int const side2)
{  

   set_heading_degrees(90);
   move_to(x,y);
   start_shape();
   draw_distance(side1);        note_position();
   turn_right_by_degrees(90);
   draw_distance(side2);        note_position();
   turn_right_by_degrees(90);
   draw_distance(side1);        note_position();
   turn_right_by_degrees(90);
   draw_distance(side2);        note_position();
   fill_shape(); 
}

void row_of_five_stars(int const x, int const y, int const dist, int const space)
 {
		draw_a_star(x,y,dist);
	    draw_a_star(x+(space),y,dist);
	    draw_a_star(x+(2*space),y,dist);
	    draw_a_star(x+(3*space),y,dist);
	    draw_a_star(x+(4*space),y,dist);
 }

void row_of_six_stars(int const x,int const y, int const dist, int const space)
{
	draw_a_star(x,y,dist);
	draw_a_star((x+space),y,dist);
	draw_a_star(x+(2*space),y,dist);
	draw_a_star(x+(3*space),y,dist);
	draw_a_star(x+(4*space),y,dist);
	draw_a_star(x+(5*space),y,dist);
}



void main()
{
	make_window (950,493);
	set_pen_width (1);
	set_pen_color(color::dark_blue);
	draw_rectangle (0,0,380,269);
	set_pen_color(color::red);
	draw_rectangle(381,0,570 ,38);
	draw_rectangle(381,76,570 ,38);
	draw_rectangle(381,76*2,570 ,38);
	draw_rectangle(381,(76*3)+3,570 ,38);
	draw_rectangle(0,304,950,38);
	draw_rectangle(0,380,950,38);
	draw_rectangle(0,456,950,38);
	set_pen_color(color::white);
	row_of_six_stars(10,10,10,65);
	row_of_five_stars(40,30,10,65);
	row_of_six_stars(10,50,10,65);
	row_of_five_stars(40,75,10,65);
	row_of_six_stars(10,100,10,65);
	row_of_five_stars(40,125,10,65);
	row_of_six_stars(10,150,10,65);
	row_of_five_stars(40,175,10,65);
	row_of_six_stars(10,200,10,65);
	row_of_five_stars(40,225,10,65);
		

	
}

	
