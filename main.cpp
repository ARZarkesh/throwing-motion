#include <graphics.h>
#include <iostream>
#include <cstdlib> 
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#define g 9.81
#define pi 3.1415
using namespace std;

void print_line(int x1, int y1, int x2, int y2, int color, int thickness);
void print_empty_circle(int x, int y, int radius, int color);
void print_filled_circle(int x, int y, int radius, int border_color, int inner_color, int pattern);
void print_text(int x, int y, char *textstring, int font, int direction, int size, int color);
string num_to_string(double x);
void print_variables(string s,int x, int y, int font, int direction, int size, int color);

int main()
{
	system("color 1F");
	double v0, x0, t0, d, t, vi, y0, r, vj, x, y, Ri, hj, hi, tm, tr, delta, v0i, v0j, t1,f;
	printf("please enter the angle(degree)\n");
	scanf("%lf", &d);
	system("color 0F");
	printf("please enter the Initial speed(m/s)\n");
	scanf("%lf", &v0);
	system("color 72");
	printf("please enter the Primary location(i^)\n");
	scanf("%lf", &x0);
	system("color 50");
	printf("please enter the Primary location(j^)\n");
	scanf("%lf", &y0);
	system("color 20");
	printf("please enter the time(s)\n");
	scanf("%lf", &t);
	system("color 74");
	r = (pi*d) / 180;
	v0i = cos(r)*v0;
	v0j = sin(r)*v0;
	vi = v0i;
	vj = (-1 * g)*t + v0j;
	printf("speed=(%.2f)i+(%.2f)j\n", vi, vj);
	
	y = (-0.5*g*t*t) + (v0j*t) + y0;
	if (y < 0)
	{
		y = 0;
	}
	x = (v0i*t) + x0;
	printf("location=(%.2f)i+(%.2f)j\n", x, y);

	tm = v0j / g;
	hj = (-0.5*g*tm*tm) + (v0j*tm) + y0;
	hi = (vi*tm) + x0;
	printf("Tipping point=(%.2f)i+(%.2f)j\n", hi, hj);

	delta = (v0j*v0j) + (2 * g*y0);
	tr = ((-1 * v0j) - (sqrt(delta))) / (-1 * g);
	Ri = (vi*tr) + x0;
	printf("Range=%.2f", Ri);

	int n, m;
	initwindow(1380, 800, "", 10, 10);
	setbkcolor(11);

	int k;
	for (k = x0; k <= Ri; k++)
	{
		print_line(80, 620, 80, 20, 10, 3);
		print_text(75, 0, "y", 5, 0, 2, 10);
		print_line(50, 600, 1350, 600, 10, 3);
		print_text(1340, 610, "x", 5, 0, 2, 10);

		t1 = (k - x0) / v0i;
		m = -1 * ((-0.5*g*t1*t1) + (v0j*t1) + y0);

		if (k >= hi)
			print_filled_circle((5 * hi) + 100, (-5 * hj) + 600, 10, 14, 14, 8);

		if (t1 >= t)
			print_filled_circle((5 * x) + 100, (-5 * y) + 600, 10, 4, 4, 8);


		print_filled_circle((5 * k) + 100, (5 * m) + 600, 10, 8, 8, 4);
		delay(20);
		cleardevice();
				
		for (f = x0; f <= k; f++)
		{
			t1 = (f - x0) / v0i;
			m = -1 * ((-0.5*g*t1*t1) + (v0j*t1) + y0);
	
			print_line((5 * f) + 100,(5 * m) + 600, (5 * f) + 101, (5 * m) + 601, 1,1);
			print_line(80, 620, 80, 20, 10, 3);
			print_text(75, 0, "y", 5, 0, 2, 10);
			print_line(50, 600, 1350, 600, 10, 3);
			print_text(1340, 610, "x", 5, 0, 2, 10);
		}
	 
	}

	/*
	for (k = x0; k <= Ri; k++)
	{
		t1 = (k - x0) / v0i;
		m = -1 * ((-0.5*g*t1*t1) + (v0j*t1) + y0);

		print_line((5 * k) + 100,(5 * m) + 600, (5 * k) + 101, (5 * m) + 601, 0,1);
		print_line(80, 620, 80, 20, 10, 3);
		print_text(75, 0, "y", 5, 0, 2, 10);
		print_line(50, 600, 1350, 600, 10, 3);
		print_text(1340, 610, "x", 5, 0, 2, 10);
		delay(25);
	}	 		*/
	k--;
	
	print_line(80, 620, 80, 20, 10, 3);
	print_text(75, 0, "y", 5, 0, 2, 10);
	print_line(50, 600, 1350, 600, 10, 3);
	print_text(1340, 610, "x", 5, 0, 2, 10);

	print_filled_circle((5 * k) + 100, (5 * m) + 600, 10, 0, 0, 8);

	print_filled_circle((5 * hi) + 100, (-5 * hj) + 600, 10, 14, 14,8);

	print_filled_circle((5 * x) + 100, (-5 * y) + 600, 10, 4, 4, 8);
	
	print_text(800, 30, "Speed      =", 8, 0, 2, 8);
	print_variables(num_to_string(vi),1000,30,8,0,1,8);
	if (vj>0)
		print_text(1070, 30, "i+", 8, 0, 2, 8);
	else
		print_text(1070, 30, "i-", 8, 0, 2, 8);
	print_variables(num_to_string(vj),1100,30,8,0,1,8);	
	print_text(1160, 30, "j      ", 8, 0, 2, 8);
	
	print_text(800, 50, "Location     =", 8, 0, 2,8);
	print_variables(num_to_string(x),1000,50,8,0,1,8);
	print_text(1070, 50, "i+", 8, 0, 2, 8);
	print_variables(num_to_string(y),1100,50,8,0,1,8);	
	print_text(1160, 50, "j        ", 8, 0, 2, 8);	
	
	
	print_text(800, 70, "Tipping Point =", 8, 0, 2, 8);
	print_variables(num_to_string(hi),1000,70,8,0,1,8);
	print_text(1070, 70, "i+", 8, 0, 2, 8);
	print_variables(num_to_string(hj),1100,70,8,0,1,8);	
	print_text(1160, 70, "j       ", 8, 0, 2, 8);
	
	
	print_text(800, 90, "Range     =", 8, 0, 2, 8);
	print_variables(num_to_string(Ri),1000,90,8,0,1,8);	
	print_text(1100, 90, "       ", 8, 0, 2, 8);
	
	setcolor(8);
	rectangle(780,10,1300,130);
	
	
	
	getch();
	closegraph();
}










void print_line(int x1, int y1, int x2, int y2, int color, int thickness)
{
	setlinestyle(0, 0, thickness);
	setcolor(color);
	line(x1, y1, x2, y2);
}

void print_empty_circle(int x, int y, int radius, int color)
{
	setcolor(color);
	circle(x, y, radius);
}

void print_filled_circle(int x, int y, int radius, int border_color, int inner_color, int pattern)
{
	setcolor(border_color);
	circle(x, y, radius);
	setfillstyle(pattern, inner_color);
	floodfill(x, y, border_color);
}

void print_text(int x, int y, char *textstring, int font, int direction, int size, int color)
{
	setcolor(color);
	settextstyle(font, direction, size);
	outtextxy(x, y, textstring);
}

string num_to_string(double x)
{
	x = fabs(x);
	string s = "            ";
	int i, j;
	int a[10];
	x *= 100;
	int y = int(x);
	for (i = 0; y > 0; i++)
	{
		a[i] = y % 10;
		if (i == 2)
		{
			s[i] = '.';
			continue;
		}
		s[i] = a[i] + 48;
		y /= 10;
	}
	while (s.find(" ") != -1)
	{
		s.erase(s.find(' '), 1);
	}

	int len = s.length();
	string z(len, ' ');
	for (j = 0, i = len - 1; i >= 0; j++, i--)
	{
		z[j] = s[i];
	}

	return z;
}
void print_variables(string s,int x, int y, int font, int direction, int size, int color)
{
	int len = s.length();
	char u[10];
	for (int i = 0 ; i<10 ; i++)
	{
		if (i<len)
			u[i] = s[i];
		else
			u[i] = ' ';
	}
	for (int i = 0; i<len ; i++)
	{
		print_text(x,y,u,font,direction,size,color);
	}
}
