#include "library.h"

void print_maze(string maze[], int row_size, int col_size)
{
	for(int i=0; i<row_size; i++)
	{
		for(int j=0; j<col_size; j++)
		{
			if(maze[i][j]=='#')
			{
				cout<<"O";
			}
			else if(maze[i][j]=='~')
			{
				cout<<" ";
			}
			else if(maze[i][j]=='+')
			{
				cout<<"R";
			}
			else if(maze[i][j]=='$')
			{
				cout<<"G";
			}
		}
		cout<<endl;
	}
}

void draw_grid(int row_size, int col_size, int square_width)
{
	move_to(0,0);
	int r_width= row_size*square_width;
	int c_width= col_size*square_width;
	set_pen_width(1);
	set_pen_color(color::black);
	for(int i=0;i<row_size+1;i++)
	{
		set_heading_degrees(90);
		draw_distance(c_width);
		move_relative(-c_width,square_width);
	}
	move_to(0,0);
	for(int i=0;i<col_size+1;i++)
	{
		set_heading_degrees(180);
		draw_distance(r_width);
		move_relative(square_width,-r_width);
	}
}

void move_robot(string maze[], int a_col,int a_row,int b_col,int b_row,int square_width, int row_size, int col_size)
{
	while(true)
	{
		if(a_row==b_row && a_col==b_col)
		{
			cout<<"You win";
			fill_rectangle(50,50,400,100,color::red);
			move_to(65,100);
			set_font_size(40);
			set_pen_color(color::white);
			write_string("YOU WIN!");
			move_to(65,140);
			set_font_size(25);
			set_pen_color(color::white);
			write_string("You have passed the test young one");
			break;
		}
		char c= wait_for_key_typed();
		if(c==-91)//left
		{
			if(maze[a_row][a_col-1] != '#')
			{
				set_pen_color(color::white);
				fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
				a_col--;
				set_pen_color(color::green);
				fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
				draw_grid(row_size, col_size, square_width);
			}
		}
		if(c==-89)//right
		{
			if(maze[a_row][a_col+1] != '#')
			{
				set_pen_color(color::white);
				fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
				a_col++;
				set_pen_color(color::green);
				fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
				draw_grid(row_size, col_size, square_width);
			}
		}
		if(c==-90)//up
		{
			if(maze[a_row-1][a_col] != '#')
			{
				set_pen_color(color::white);
				fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
				a_row--;
				set_pen_color(color::green);
				fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
				draw_grid(row_size, col_size, square_width);
			}
		}
		if(c==-88)//down
		{
			if(maze[a_row+1][a_col] != '#')
			{
				set_pen_color(color::white);
				fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
				a_row++;
				set_pen_color(color::green);
				fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
				draw_grid(row_size, col_size, square_width);
			}
		}
		if(c=='x')
			break;
		if(c=='a')
		{
			while (true)
				{   wait(0.1);
					int safe=0;
			set_pen_color(color::white);
			fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
			while(true)
			{
				a_row= random_in_range(1,9);
				a_col= random_in_range(1,30);
				if(maze[a_row][a_col] != '#')
					break;
			}
			set_pen_color(color::green);
			fill_rectangle(a_col*square_width,a_row*square_width,square_width,square_width);
			draw_grid(row_size, col_size, square_width);

			if(a_row==b_row && a_col==b_col)
		{
			cout<<"You win";
			fill_rectangle(5,50,400,100,color::red);
			move_to(65,100);
			set_font_size(40);
			set_pen_color(color::white);
			write_string("YOU WIN!");
			move_to(65,140);
			set_font_size(25);
			set_pen_color(color::white);
			write_string("You have passed the test young one");
			break;
		}

			}

		}
	}
	
}

void draw_maze(string maze[], int row_size, int col_size, int square_width)
{
	int r_width= row_size*square_width;
	int c_width= col_size*square_width;
	make_window(c_width,r_width);
	int a_col,a_row,b_col,b_row;
	a_col = 1;
	a_row = 1;
	b_col = 1;
	b_row = 1;
	for(int i=0; i<row_size; i++)
	{
		for(int j=0; j<col_size; j++)
		{
			if(maze[i][j]=='#')
				set_pen_color(color::dark_grey);
			else if(maze[i][j]=='~')
				set_pen_color(color::white);
			else if(maze[i][j]=='+')
			{
				set_pen_color(color::green);
				a_col = j;
				a_row = i;
			}
			if(maze[i][j]=='$')
			{
				set_pen_color(color::red);
				b_col = j;
				b_row = i;
			}
			fill_rectangle(j*square_width,i*square_width,square_width,square_width);
		}
	}
	draw_grid(row_size, col_size, square_width);
	move_robot(maze, a_col, a_row, b_col, b_row, square_width,row_size, col_size);
}

void read_maze()
{
	int row_size = 11;
	int col_size = 31;
	int square_width = 30;//to change size of maze
	string maze[100];
	ifstream fin("maze.txt");
	if(fin.fail())
	{
		cout<<"Not available"<<endl;
	}
	for(int i=0; i<100; i++)
	{
		fin>>maze[i];
	}
	fin.close();
	print_maze(maze, row_size, col_size);
	draw_maze(maze, row_size, col_size, square_width);

}

void main()
{
	cout<<"Keys to use: "<<"\na-auto-mode      x-exit     arrow keys to move \n\n";  
	read_maze();
}
