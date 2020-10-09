void stars(int const N)
{
	if (N>0)
	{
		print("*");
		return(stars(N-1));
	}

}

void dots(int const M)
{
	if (M>0)
	{
		print(".");
		return(dots(M-1));
	}
}

void space(int const M)
{
	if (M>0)
	{
		print(" ");
		return(dots(M-1));
	}
}

void up_pyramid (int const N, int const M)
{
	if(N>0)
	{
		dots(N);
		stars(M);
		dots(N);
		new_line();
		up_pyramid(N-1,M+2);
	}
}

void down_pyramid (int const N, int const M)
{
	if (N>0)
	{
		dots(M);
		stars(N);
		stars(N-1);
		dots(M);
		new_line();
		down_pyramid(N-1,M+1);
	}
}


void diamond(int const N, int const M)
{ 
	up_pyramid(N,M);
	down_pyramid(N,M);

}


void main ()
{
	diamond(5,1);
}
