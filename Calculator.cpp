#include "library.h"

void blackscreen()
{
	set_pen_color(color::black);
fill_rectangle(0,0,290,90);
}
void calculate()
{
	int Pressed = 0;
	for(int i = 0; i<1000; i++)
	{
	int T, t;
	float Total;
	T = 0;
	wait_for_mouse_click();
	int x = get_click_x(), y = get_click_y();
	cout << "Mouse clicked at position (" << x << ", " << y << ")\n";
	if(x > 300 && x < 375 && y > 680 && y < 760)
	{
		Pressed = 0;
		T = 1;
	}
	if(x>=10 && x<=60 && y>=100 && y<=150)
	{
		Pressed =Pressed*10 + 7;
		T = 1;
	}
	else if(x>=80 && x<=130 && y>=100 && y<=150)
	{
		Pressed =Pressed*10 + 8;
		T = 1;
	}
	else if(x>=150 && x<=200 && y>=100 && y<=150)
	{
		Pressed =Pressed*10 + 9;
		T = 1;
	}
	else if(x>=10 && x<=60 && y>=170 && y<=200)
	{
		Pressed =Pressed*10 + 4;
		T = 1;
	}
	else if(x>=80 && x<=130 && y>=170 && y<=220)
	{
		Pressed =Pressed*10 + 5;
		T = 1;
	}
	else if(x>=150 && x<=200 && y>=170 && y<=220)
	{
		Pressed =Pressed*10 + 6;
		T = 1;
	}
	else if(x>=10 && x<=60 && y>=240 && y<=290)
	{
		Pressed =Pressed*10 + 1;
		T = 1;
	}
	else if(x>=80 && x<=130 && y>=240 && y<=290)
	{
		Pressed =Pressed*10 + 2;
		T = 1;
	}
	else if(x>=150 && x<=200 && y>=240 && y<=290)
	{
		Pressed =Pressed*10 + 3;
		T = 1;
	}
	else if(x>=80 && x<=130 && y>=310 && y<=360)
	{
		Pressed = Pressed*10 + 0;
		T = 1;
	}
	if(T == 1)
	{
		blackscreen();
		move_to(280,60);
		set_pen_color(color::white);
		write_string(Pressed,direction::west);
		cout << Pressed << "\n";
	}

	if(x>=220 && x<=270 && y>=100 && y<=150) 
	{
		T = 2;
	}
	else if(x>=220 && x<=270 && y>=170 && y<=220)
	{
		T = 3;
	}
	else if(x>=220 && x<=270 && y>=240 && y<=290)
	{
		T = 4;
	}
	else if(x>=220 && x<=270 && y>=310 && y<=360)
	{
		T = 5;
		cout << T;
	}
	
	int NewPressed = 0;
	
	while(T > 1 && T < 6)
	{
		wait_for_mouse_click();
		x = get_click_x();
		y = get_click_y();
		cout << "Mouse clicked at position (" << x << ", " << y << ")\n";
		cout << Pressed;
		if(x>=10 && x<=60 && y>=100 && y<=150)
		{
			NewPressed =NewPressed*10 + 7;
			t = 10;
		}
		else if(x>=80 && x<=130 && y>=100 && y<=150)
		{
			NewPressed =NewPressed*10 + 8;
			t = 10;
		}
		else if(x>=150 && x<=200 && y>=100 && y<=150)
		{
			NewPressed =NewPressed*10 + 9;
			t = 10;
		}
		else if(x>=10 && x<=60 && y>=170 && y<=200)
		{
			NewPressed =NewPressed*10 + 4;
			t = 10;
		}
		else if(x>=80 && x<=130 && y>=170 && y<=220)
		{
			NewPressed = NewPressed*10 + 5;
			t = 10;
		}
		else if(x>=150 && x<=200 && y>=170 && y<=220)
		{
			NewPressed =NewPressed*10 + 6;
			t = 10;
		}
		else if(x>=10 && x<=60 && y>=240 && y<=290)
		{
			NewPressed =NewPressed*10 + 1;
			t = 10;
		}
		else if(x>=80 && x<=130 && y>=240 && y<=290)
		{
			NewPressed =NewPressed*10 + 2;
			t = 10;
		}
		else if(x>=150 && x<=200 && y>=240 && y<=290)
		{
			NewPressed =NewPressed*10 + 3;
			t = 10;
		}
		else if(x>=80 && x<=130 && y>=310 && y<=360)
		{
			NewPressed = NewPressed*10 + 0;
			t = 10;
		}
	if(t == 10)
	{
		blackscreen();
		move_to(250,80);
		set_pen_color(color::white);
		write_string(NewPressed);

	if(x>=150 && x<=200 && y>=310 && y<=360)
	{
		if(T == 2)
		{
			Total = Pressed + NewPressed;
		}
		else if(T == 3)
		{
			Total = Pressed - NewPressed;
		}
		else if(T == 4)
		{
			Total = Pressed * NewPressed;
		}
		else if(T == 5)
		{
			Total = Pressed / NewPressed;
		}
		blackscreen();
		move_to(280,60);
		set_pen_color(color::white);
		write_string(Total,direction::west);
		cout << Total << "\n";
		Pressed = Total;
		NewPressed = 0;
		T = 0;
	
	}
	}
	}
		if(x>=10 && x<=60 && y>=310 && y<=360)
		{blackscreen();
		set_pen_color(color::white);
		move_to(280,60);
		write_string(NewPressed);
		Pressed=0;
		T = 0;
		}
	}
	
}
void drawbuttons1()
{ int s=4;
while (s>0)
{start_shape();
	note_position();
	move_relative(50,0);
	note_position();
	move_relative(0,-50);
	note_position();
	move_relative(-50,0);
	note_position();
	move_relative(0,50);
	set_pen_color(color::blue);
	fill_shape();
	set_pen_color(color::red);
	draw_relative(50,0);
	draw_relative(0,-50);
	draw_relative(-50,0);
	draw_relative(0,50);
	move_relative(70,0);
	s--;

}

}
void drawbuttons2()
{
int r=4;
while(r>0)
{	drawbuttons1();
move_relative(-280,-70);
r--;}
}
void text()
{
	set_font_size(50);
	move_to(35,335);
	write_string("C",direction::center);
	move_to(105,335);
	write_string("0",direction::center);
	move_to(175,335);
	write_string("=",direction::center);
	move_to(245,335);
	write_string("/",direction::center);
	move_to(35,265);
	write_string("1",direction::center);
	move_to(105,265);
	write_string("2",direction::center);
	move_to(175,265);
	write_string("3",direction::center);
	move_to(245,265);
	write_string("*",direction::center);
	move_to(35,195);
	write_string("4",direction::center);
	move_to(105,195);
	write_string("5",direction::center);
	move_to(175,195);
	write_string("6",direction::center);
	move_to(35,125);
	write_string("7",direction::center);
	move_to(105,125);
	write_string("8",direction::center);
	move_to(175,125);
	write_string("9",direction::center);
	move_to(245,125);
	write_string("+",direction::center);
	move_to(245,195);
	write_string("-",direction::center);
}
void calculator()
{
make_window(280,370);
double g;
g=random_in_range(0,1.0);
double r;
r=random_in_range(0,1.0);
double b;
b=random_in_range(0,1.0);
set_pen_color(r,g,b);
fill_rectangle(0,0,280,370);
	set_caption("Calculator");
	move_to(10,360);
	drawbuttons2();
	blackscreen();
	text();
	calculate();
}
void main()
{
	calculator();
}
