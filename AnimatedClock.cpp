#include "library.h"

void date_and_time(){
int time = get_clock_time();
int sec = time%100;
int minute = time/100%100;
int date =  get_calendar_date();
int year = date/10000;
int day = date%100;
int month = date/100%100;
print("year :");
print(year);
new_line();
print("month :");
print(month);
new_line();
print("day :");
print(day);
new_line();
print("hour :");
int hr = (time/10000);
if (hr < 12){
if (hr == 0)
print("12");
else
print(hr);
print(" A.M.");
}
if (hr >= 12){
print(hr-12);
print(" P.M.");
}
new_line();
print("minutes :");
print(minute);
}

void dashes(int n)
{
if (360 > n)
{
move_to(200,250);
set_heading_degrees(n);
set_pen_color(color::black);
set_pen_width(2);
draw_distance(150);
move_to(200,250);
set_heading_degrees(n);
set_pen_color(color::white);
set_pen_width(4);
draw_distance(130);
dashes(n+6);
move_to(200,250);
}}

void dashes_wider(int n){
if (360 > n){
move_to(200,250);
set_heading_degrees(n);
set_pen_color(color::black);
set_pen_width(4);
draw_distance(150);
move_to(200,250);
set_heading_degrees(n);
set_pen_color(color::white);
set_pen_width(4);
draw_distance(120);
dashes_wider(n+30);
move_to(200,250);
}}

void red_dashes(double n){
move_to(200,250);
set_heading_degrees(n);
set_pen_color(color::red);
set_pen_width(2);
draw_distance(150);
move_to(200,250);
}

void circle(int n)
{
	
	if(n>=0)
		{
		move_to(200,250);
		set_heading_degrees(1);
		set_pen_color(color::black);
		set_pen_width(4);
        move_distance(200);
		draw_point();
	}
}




void minute_hand(int minute){
move_to(200,250);
set_pen_width(6);
set_heading_degrees(6*minute);
draw_distance(125);
}

void hour_hand(int hour,int minute){
move_to(200,250);
set_pen_width(6);
set_heading_degrees(30*hour+minute/2);
draw_distance(100);
}

const string monthname[] =
{"  ","Januaury","Feburuary", "March", "April","May", "June", "July","August","september","October","november","december"};



void month_screen(int m){
set_pen_color(color ::black);
move_to(150,450);
if (m == 1)
write_string(monthname[1]);
if (m == 2)
write_string(monthname[2]);
if (m == 3)
write_string(monthname[3]);
if (m == 4)
write_string(monthname[4]);
if (m == 5)
write_string(monthname[5]);
if (m == 6)
write_string(monthname[6]);
if (m == 7)
write_string(monthname[7]);
if (m == 8)
write_string(monthname[8]);
if (m == 9)
write_string(monthname[9]);
if (m == 10)
write_string(monthname[10]);
if (m == 11)
write_string(monthname[11]);
if (m == 12)
write_string(monthname[12]);
}


void digital_clock(int hr,int min){
move_to(140,80);
if (hr < 12){
if (hr == 0)
write_string("12");
else
write_string(hr);
write_string(" : ");
write_string(min);
write_string(" A.M.");
}
if (hr >= 12){
write_string(hr-12);
write_string(" : ");
write_string(min);
write_string(" P.M.");
}}

void hands()	{
int time = get_clock_time();
int sec = time%100;
int minute = time/100%100;
int hour = time/10000;
int date =  get_calendar_date();
int year = date/10000;
int day = date%100;
int month = date/100%100;
while(true)	{
set_pen_color(color::black);
minute_hand(time/100%100);
hour_hand(time/10000-12,time/100%100);
red_dashes((time%100)*6);
sleep(1);
set_pen_color(color::white);
minute_hand(time/100%100);
hour_hand(time/10000-12,time/100%100);
set_pen_color(color::white);
set_pen_width(4);
draw_distance(130);
move_to(70,450);
write_string(day);
move_to(300,450);
write_string(year);
month_screen(month);
move_to(105,450);
digital_clock(hour,minute);
dashes(0);
dashes_wider(0);
hands();
}}

void main(){
int time = get_clock_time();
int sec = time%100;
int minute = (time/100)%100;
int hour = time/10000;
int date =  get_calendar_date();
int year = date/10000;
int day = date%100;
int month = (date/100) %100;
date_and_time();
make_window(400,500);
write_string(day);
move_to(250,450);
write_string(year);
month_screen(month);
move_to(90,450);
digital_clock(hour,minute);
circle(720);
make_window(400,500);
move_to(105,450);
write_string(day);
move_to(250,450);
write_string(year);
month_screen(month);
move_to(105,450);
dashes(0);
dashes_wider(0);
hands();}

