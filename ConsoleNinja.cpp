#include <iostream>
#include <time.h>
#include <cstring>
#include <conio.h>
#include <windows.h>

using namespace std;

enum Direction
{
	UP, DOWN, LEFT, RIGHT, STILL
};

class Ninja
{
public:
	int x;
	int y;
};

class Enemy
{
public:
	int x;
	int y;
	string character;

};

int RNG(int);
void GenerateMap();
void Render();
void GetUserInput();

void DrawNinja(int, int);
void HideNinja(int, int);
void DrawNinjaSlash(int, int);
void HideNinjaSlash(int, int);
void DrawScore();
void HideScore();
void Slash();

void DrawEnemy();
void HideEnemy();
void MoveEnemies();

string* map = new string[23];
Direction currentDirection;

Ninja ninja;
Enemy enemy;

int main()
{
	enemy.character = "a";
	enemy.x = 50;
	enemy.y = 14;

	ninja.x = 1;
	ninja.y = 14;
	GenerateMap();
	currentDirection = STILL;
	DrawNinja(ninja.x, ninja.y);
	DrawEnemy();
	//HideEnemy();
	Render();
	while(true)
	{
		GetUserInput();
		MoveEnemies();	
	}
	


	return 0;	
}

void GetUserInput()
{
	if (_kbhit())
	{
		switch(_getch())
		{
			case ' ':
				Slash();
				break;
			case 'w':
				if(ninja.y > 1)
				{
					HideNinja(ninja.x, ninja.y);
					ninja.y = ninja.y - 1;
					DrawNinja(ninja.x, ninja.y);
					Render();
				}

				break;
			case 'a':
				if(ninja.x > 1)
				{			
					HideNinja(ninja.x, ninja.y);
					ninja.x = ninja.x - 1;
					DrawNinja(ninja.x, ninja.y);
					Render();		
				}		
				break;				
			case 's':
				if(ninja.y < 14)
				{
					HideNinja(ninja.x, ninja.y);
					ninja.y = ninja.y + 1;
					DrawNinja(ninja.x, ninja.y);
					Render();	
				}			
				break;
			case 'd':
				if(ninja.x < 34)
				{
					HideNinja(ninja.x, ninja.y);
					ninja.x = ninja.x + 1;
					DrawNinja(ninja.x, ninja.y);
					Render();					
				}
			
				break;				
			case 'C':
				system("CLS");
				exit(0);
				break;
		}
	}
}
void MoveEnemies()
{
	if(enemy.x > 0)
	{
		HideEnemy();
		enemy.x = enemy.x-1;
		DrawEnemy();
		Render();		
	}

}

void Slash()
{
	DrawNinjaSlash(ninja.x, ninja.y);
	Render();
	HideNinjaSlash(ninja.x, ninja.y);
	Render();
	DrawNinja(ninja.x, ninja.y);
	Render();
}
void Render()
{
	system("CLS");
	for(int i = 0; i < 23; i++)
	{
		cout << map[i] << endl;
	}
	Sleep(10);	
}

void DrawNinja(int x, int y)
{
	//Height = 8
	map[y].replace( x,7, "    OOO");
	map[y+1].replace(x,6, "   OOO");
	map[y+2].replace(x,7, "  o | o");
	map[y+3].replace(x,9, "{} |/| {}");
	map[y+4].replace(x,6, "   /o\\");
	map[y+5].replace(x,8, " o/   \\o");
	map[y+6].replace(x,8, " /     \\");
	map[y+7].replace(x,11,"o[]     o[]");
}
void HideNinja(int x, int y)
{
	map[y].replace( x,7, "       ");
	map[y+1].replace(x,6, "      ");
	map[y+2].replace(x,7, "       ");
	map[y+3].replace(x,9, "         ");
	map[y+4].replace(x,6, "      ");
	map[y+5].replace(x,8, "        ");
	map[y+6].replace(x,8, "        ");
	map[y+7].replace(x,11,"           ");	
}
void DrawNinjaSlash(int x, int y)
{
	map[y].replace( x,7, "    OOO");
	map[y+1].replace(x,6, "   OOO");
	map[y+2].replace(x,7, "   O| >");
	map[y+3].replace(x,9, "   |/| {>");
			map[y+3].replace(x+9, 13, "o=[]::::::::>");
	map[y+4].replace(x,10,"   /o\\    ");
	map[y+5].replace(x,8, "    >  >");
	map[y+6].replace(x,8, "   /   \\");
	map[y+7].replace(x,11,"  o[]   o[]");
}
void HideNinjaSlash(int x, int y)
{
	map[y+3].replace(x+9, 13, "             ");
}
void DrawScore()
{
	map[1].replace(10, 7, "Score: ");
}
void HideScore()
{
	map[1].replace(0, 78, "#                                                                            #");	
}

void DrawEnemy()
{
	int x = enemy.x;
	int y = enemy.y;
	map[y].replace(x,1,enemy.character);
}
void HideEnemy()
{
	int x = enemy.x;
	int y = enemy.y;
	map[y].replace(x,1," ");
}

void GenerateMap()
{
			//			 10		   20		 30		   40		 50		   60		 70		
			// 0123456789 123456789 123456789 123456789 123456789 123456789 123456789 1234567
	map[0]  = "##############################################################################";
	map[1]  = "#                                                                            #";
	map[2]  = "#                                                                            #";
	map[3]  = "#                                                                            #";
	map[4]  = "#                                                                            #";
	map[5]  = "#                                                                            #";
	map[6]  = "#                                                                            #";
	map[7]  = "#                                                                            #";
	map[8]  = "#                                                                            #";
	map[9]  = "#                                                                            #";
	map[10] = "#                                                                            #";
	map[11] = "#                                                                            #";
	map[12] = "#                                                                            #";
	map[13] = "#                                                                            #";
	map[14] = "#                                                                            #";
	map[15] = "#                                                                            #";
	map[16] = "#                                                                            #";
	map[17] = "#                                                                            #";
	map[18] = "#                                                                            #";
	map[19] = "#                                                                            #";
	map[20] = "#                                                                            #";
	map[21] = "#                                                                            #";
	map[22] = "##############################################################################";

}

int RNG(int max)
{
	srand(time(NULL));
	int randomNumber = rand() % max;

	return randomNumber;
}
