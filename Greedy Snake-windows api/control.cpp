#include<windows.h>
#include"graphic.h"
#include"control.h"
#include<time.h>
#include<stdlib.h>

namespace control_data
{

	int direct[82][51];
	POINT head;
	POINT tail;
	bool flag;
	
	int direction_temp;
	POINT point_destory;

	POINT target;
}
using namespace control_data;

void initial_control()
{
	memset(direct,0,sizeof(direct));
	head.x=61;
	head.y=25;
	direct[head.x][head.y]=3;
	tail.x=62;
	tail.y=25;
	direct[tail.x][tail.y]=3;

	flag=false;
	create_target();
}
void left()
{
	if(permision_revision(3))
	{
		if(direct[head.x][head.y]==1)
		{
			direct[head.x][head.y]=1;
		}
		else if(direct[head.x][head.y]==2)
		{
			direct[head.x][head.y]=3;
		}
		else if(direct[head.x][head.y]==3)
		{
			direct[head.x][head.y]=3;
		}
		else if(direct[head.x][head.y]==4)
		{
			direct[head.x][head.y]=3;
		}
	}
}
void right()
{
	if(permision_revision(1))
	{
		if(direct[head.x][head.y]==1)
		{
			direct[head.x][head.y]=1;
		}
		else if(direct[head.x][head.y]==2)
		{
			direct[head.x][head.y]=1;
		}
		else if(direct[head.x][head.y]==3)
		{
			direct[head.x][head.y]=3;
		}
		else if(direct[head.x][head.y]==4)
		{
			direct[head.x][head.y]=1;
		}
	}
}
void up()
{
	if(permision_revision(4))
	{
		if(direct[head.x][head.y]==1)
		{
			direct[head.x][head.y]=4;
		}
		else if(direct[head.x][head.y]==2)
		{
			direct[head.x][head.y]=2;
		}
		else if(direct[head.x][head.y]==3)
		{
			direct[head.x][head.y]=4;
		}
		else if(direct[head.x][head.y]==4)
		{
			direct[head.x][head.y]=4;
		}
	}
}
void down()
{
	if(permision_revision(2))
	{
		if(direct[head.x][head.y]==1)
		{
			direct[head.x][head.y]=2;
		}
		else if(direct[head.x][head.y]==2)
		{
			direct[head.x][head.y]=2;
		}
		else if(direct[head.x][head.y]==3)
		{
			direct[head.x][head.y]=2;
		}
		else if(direct[head.x][head.y]==4)
		{
			direct[head.x][head.y]=4;
		}
	}
}
void paint_snake()
{
	POINT now=tail;
	//绘制尾巴
	basic_tri(now.x,now.y,direct[now.x][now.y]);
	retrospect(&(now.x),&(now.y));
	//绘制身体
	while(now.x !=head.x || now.y != head.y)
	{
		basic_red_rect(now.x,now.y);
		retrospect(&(now.x),&(now.y));
	}
	//绘制头
	basic_round(now.x,now.y);
}
void paint()
{
	if(flag==true)
	{
		direction_temp=0;
		point_destory=tail;
		//空白尾巴填充，轨迹方向销毁
		basic_white_rect(tail.x,tail.y);
		retrospect(&(tail.x),&(tail.y));
		direct[point_destory.x][point_destory.y]=0;//轨迹销毁
		basic_white_rect(tail.x,tail.y);
		//头的追溯点方向保持
		direction_temp=direct[head.x][head.y];
		retrospect(&(head.x),&(head.y));
		direct[head.x][head.y]=direction_temp;
		//绘制蛇体
		paint_snake();
	}
	else
	{
		paint_snake();
		flag=true;
	}
}
void retrospect(LONG *x,LONG *y)
{
	if(direct[*x][*y]==1)
	{
		(*x)++;
	}
	else if(direct[*x][*y]==2)
	{
		(*y)++;
	}
	else if(direct[*x][*y]==3)
	{
		(*x)--;
	}
	else if(direct[*x][*y]==4)
	{
		(*y)--;
	}
}
bool defeat()
{
	POINT temp=head;
	retrospect(&(temp.x),&(temp.y));
	if(temp.x>81||temp.y>50||temp.x<0||temp.y<0||direct[temp.x][temp.y]!=0)
	{
		return true;
	}
	else
		return false;
}
void create_target()
{
	do
	{
	target.x=rand()%82;
	target.y=rand()%51;
	}while(direct[target.x][target.y]!=0);
	//wsprintf(a,b,target.x,target.y);
	//MessageBox(NULL,a,NULL,MB_OK);
	basic_round(target.x,target.y);
}
void approch_target()
{
	paint();
	if(head.x==target.x&&head.y==target.y)//到达目标
	{
		//方向保持
		direction_temp=direct[head.x][head.y];
		retrospect(&(head.x),&(head.y));
		direct[head.x][head.y]=direction_temp;
		//创建目标
		create_target();
		//按照false方式绘制蛇体
		flag=false;
	}
}
bool permision_revision(int direction)
{
	POINT temp=head;
	int direct_temp=direct[temp.x][temp.y];
	direct[temp.x][temp.y]=direction;
	retrospect(&(temp.x),&(temp.y));
	direct[head.x][head.y]=direct_temp;
	if(direct[temp.x][temp.y]==0)
		return true;
	else
	{
		retrospect(&(temp.x),&(temp.y));
		if(temp.x==head.x&&temp.y==head.y)
			return false;
		else
			return true;
	}
}