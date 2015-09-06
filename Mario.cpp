/*	This program displays various aspects of Object Oriented Programming and file handling.
	We have chosen to do this using the Mario game.
	This program allows the user to continue old games and also automatically saves the game periodically.
	It retrieves high scores and past games.  

Header Files Included

1. #include<iostream.h>
2. #include<conio.h>
3. #include<math.h>
4. #include<iomanip.h>
5. #include<process.h>
6. #include<graphics.h>
7. #include<stdio.h>
8. #include<dos.h>
9. #include<time.h>
10. #include<string.h>
11. #include <fstream.h>
12. #include<stdlib.h>

Functions 

1. Float t1_retx()
2. Float t2_retx()
3. Float t3_retx()
4. Float e1_retx()
5. Float  e2_retx()
6. Float e3_retx()
7. Float c1_retx()
8. Float c2_retx()
9. Float c3_retx()
10. Float t1_rety()
11. Float t2_rety()
12. Float t3_rety()
13. Float e1_rety()
14. Float  e2_rety()
15. Float e3_rety()
16. Float c1_rety()
17. Float c2_rety()
18. Float c3_rety()
19. Void save(player me)
20. Void Mario(charac &p)
21. Void maria(charac &p)
22. Void back
23. Void front
24. Void tree(pt &p)
25. Void evilcrab(pt  a)
26. Void canpan(pt a)
27. Void initkeyboard(void)
28. Void restorekeyboard(void)
29. Void coin(pt &a)
30. Void score(float c)
31. Void distance(float x)
32. Void score2(float c)
33. Int new_player(account me)
34. Int selection()
35. Void disp_scores()
36. Void disp_high()
37. Void continue_game(account &me, player &k)
38. Void auto_save(player game)
39. Void login(account &me)
40. Void sky()
41. int ret_mario_maria()
42. void set_first_game(int m)
43. int ret_first_game()                             
44. int comp(char p[20])                             

Functions

45. int name_comp(char n[30])                        
46. int name_comp(account temp)                      
47. void set_auto_save(char ch)  
48. char ret_auto_save() 
49. float ref_lastgame_retx()    
50. float ref_lastgame_rety()    
51. friend void save(player game);
52. friend void continue_game(account &me,player &game);
53. friend void disp_high();
54. void interrupt(*OldKeyboard)
55. void interrupt MyKeyboard

*/


#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<iomanip.h>
#include<process.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<time.h>
#include<string.h>
#include <fstream.h>
#include<stdlib.h>

int new_player=0;               //To see if it is a players first time

int curr_dir=0;
float sc=0;  			//to hold score

void front();
void back();

class pt                        //class to store coordinates of the objects
{
	protected:

	float x;
	float y;

	static int lost;

	public:

	void xset(float z)      //To set the x coordinate
	{
	x=z;
	}

	void yset(float z)      //To set the y coordinate
	{
	y=z;
	}

	float retx() 	        //To retrieve the x coordinate
	{
	return x;
	}

	float rety()         	//To retreive the y coordinate
	{
	return y;
	}

	pt(float a,float b)     //Parameterised constructor to initialise object
	{
	x=a;
	y=b;
	}

	void mb()               //Function to move point back
	{

	if (lost==0)
	{
	}

	else
	{
	x-=10;
	}

	}

	void mf()               //Function to move point forwards
	{

	if (lost==0)
	{
	}

	else
	{
	x+=10;
	}

	}

};

int min_height=250;                        //Minimum Height of all points

class charac:public pt                     //Class inherited from pt
					   //used to control characters
{
	public:
	charac(float a,float b):pt(a,b)    //Parameterised Constructor
	{                                  //Calls constructor of point
	}

	static int j;

	static float trig;

	void jump()                        //Function to make the character jump
	{
	j+=1;
	trig+=(22/(7*35));

	if (lost==0)
	{
	}

	else if(j<10)
	{
		y-=10*cos(trig);

		if(curr_dir==1)
		{
		front();
		}

		else
		{
		back();
		}
		}

		else
		{

		if(lost==0)
		{
		}
		else
		{
		y+=10*cos(trig);

		if(curr_dir==1)
		{
		front();
		}
		else
		{
		back();
		}
		}
	}

	if(j>20)
	{
	j=0;
	}
	}

}p(100,250);

class account
{                               //Class holds account details
	private:

	char password[20];

	protected:

	int first_game;		//To see if it is players first time playing
	int mario_maria;        //To store the character player played with previously

	public:

	char name[30];

	void d()
	{
	puts(name);
	}

	account()               //Constructor to initialise objects
	{
	strcpy(name,"\0");
	mario_maria=0;
	strcpy(password,"\0");
	first_game=1;
	}

	void copy(char n[30],int f,char p[20],int m)     //Copies values into an account
	{
	strcpy(name,n);
	first_game=f;
	strcpy(password,p);
	mario_maria=m;
	}

	void copy(char n[30],int m)                      //Overloaded function
	{                                                //copies values into object
	strcpy(name,n);
	mario_maria=m;
	}

	void display()                                   //Displays name
	{
	setfillstyle(SOLID_FILL,2);
	outtextxy(200,10,name);
	}

	int ret_mario_maria()                            //Returns character selection
	{
	return mario_maria;
	}

	int ret_first_game()                             //To see if it is the players first game
	{
	return first_game;
	}

	void set_first_game(int m)                       //To change value of first game
	{
	first_game=m;
	}

	int comp(char p[20])                             //To check for right password
	{
	if(!strcmp(password,p))
	return 1;
	else
	return 0;
	}

	int name_comp(char n[30])                        //To check name
	{
	if(!strcmp(name,n))
	return 1;
	else
	return 0;
	}

	int name_comp(account temp)                      //To check name using an object
	{
	if(!strcmp(name,temp.name))
	return 1;
	else
	return 0;
	}
};

account me;

class player:public account                       //Class to hold details
						  //of player's games
{
		private:
		int no;
		float score;
		char auto_save;
		pt ref_lastgame;
		pt e1,e2,e3,t1,t2,t3,c1,c2,c3;

		public:

		//constructor
		player():ref_lastgame(0,250),e1(650,250),e2(650,250),e3(650,250),t1(650,250),t2(650,250),t3(650,250),c1(650,250),c2(650,250),c3(650,250)
		{
		strcpy(name,"\0");
		score=0;
		no=random(9999)+1;
		mario_maria=0;
		char auto_save='n';
		}

		//To copy values
		void copy(char n[30],float s,int m,pt ref,char aut_sv,pt e_1,pt e_2,pt e_3,pt t_1,pt t_2,pt t_3,pt c_1,pt c_2,pt c_3)
		{
		account::copy(n,m);
		score=s;
		ref_lastgame.xset(ref.retx());
		ref_lastgame.yset(ref.rety());
		auto_save=aut_sv;
		e1.xset(e_1.retx());
		e1.yset(e_1.rety());
		e2.xset(e_2.retx());
		e2.yset(e_2.rety());
		e3.xset(e_3.retx());
		e3.yset(e_3.rety());
		t1.xset(t_1.retx());
		t1.yset(t_1.rety());
		t2.xset(t_2.retx());
		t2.yset(t_2.rety());
		t3.xset(t_3.retx());
		t3.yset(t_3.rety());
		c1.xset(c_1.retx());
		c1.yset(c_1.rety());
		c2.xset(c_2.retx());
		c2.yset(c_2.rety());
		c3.xset(c_3.retx());
		c3.yset(c_3.rety());
		}

		//Copies values
		void copy(float s,pt ref,char aut_sv,pt e_1,pt e_2,pt e_3,pt t_1,pt t_2,pt t_3,pt c_1,pt c_2,pt c_3)
		{
		score=s;
		ref_lastgame.xset(ref.retx());
		ref_lastgame.yset(ref.rety());
		auto_save=aut_sv;
		e1.xset(e_1.retx());
		e1.yset(e_1.rety());
		e2.xset(e_2.retx());
		e2.yset(e_2.rety());
		e3.xset(e_3.retx());
		e3.yset(e_3.rety());
		t1.xset(t_1.retx());
		t1.yset(t_1.rety());
		t2.xset(t_2.retx());
		t2.yset(t_2.rety());
		t3.xset(t_3.retx());
		t3.yset(t_3.rety());
		c1.xset(c_1.retx());
		c1.yset(c_1.rety());
		c2.xset(c_2.retx());
		c2.yset(c_2.rety());
		c3.xset(c_3.retx());
		c3.yset(c_3.rety());
		}

		void display()    	//To display name,score,distance
		{
		account::display();
		cout<<"Score "<<score<<"\t";
		cout<<"Distance covered"<<ref_lastgame.retx();
		}

		char ret_auto_save()    //To check if it is an autosaved game
		{
		return auto_save;
		}

		void set_auto_save(char ch)  //To adjust Auto_save
		{
		auto_save=ch;
		}

		float ref_lastgame_retx()    //To return x coordinate of game
		{
		return ref_lastgame.retx();
		}

		float ref_lastgame_rety()    //To return y coordinate of game
		{
		return ref_lastgame.rety();
		}

		float t1_retx()              //To return x coordinate of tree 1
		{
		return t1.retx();
		}

		float t2_retx()              //To return x coordinate of tree 2
		{
		return t2.retx();
		}

		float t3_retx()              //To return x coordinate of coin 1
		{
		return t3.retx();
		}

		float e1_retx()              //To return x coordinate of crab 1
		{
		return e1.retx();
		}

		float e2_retx()              //To return x coordinate of crab 2
		{
		return e2.retx();
		}

		float e3_retx()              //To return x coordinate of coin 2
		{
		return e3.retx();
		}

		float c1_retx()              //To return x coordinate of plant 1
		{
		return c1.retx();
		}

		float c2_retx()              //To return x coordinate of coin 3
		{
		return c2.retx();
		}

		float c3_retx()              //To return x coordinate of coin 4
		{
		return c3.retx();
		}

		float t1_rety()              //To return y coordinate of tree 1
		{
		return t1.rety();
		}

		float t2_rety()              //To return y coordinate of tree 2
		{
		return t2.rety();
		}

		float t3_rety()              //To return y coordinate of coin 1
		{
		return t3.rety();
		}

		float e1_rety()              //To return y coordinate of crab 1
		{
		return e1.rety();
		}

		float e2_rety()              //To return y coordinate of crab 2
		{
		return e2.rety();
		}

		float e3_rety()              //To return y coordinate of coin 2
		{
		return e3.rety();
		}

		float c1_rety()              //To return y coordinate of plant 1
		{
		return c1.rety();
		}

		float c2_rety()
		{                            //To return y coordinate of coin 3
		return c2.rety();
		}

		float c3_rety()              //To return y coordinate of coin 4
		{
		return c3.rety();
		}

		friend void save(player game);
		friend void continue_game(account &me,player &game);
		friend void disp_high();
};

void save(player me);

player game;

int charac::j=0;
float charac::trig=0;
int pt::lost=1;

int lost=1;                                  //To see if the game is still continuing

//Declaration of objects for characters

pt ref(0,250);
pt t1(200,250);
pt t2(200,250);
pt t3(200,250);
pt e1(200,250);
pt e2(200,250);
pt e3(200,250);
pt c1(200,250);
pt c2(200,250);
pt c3(200,250);

int select=0;
int s=0;

int keypressed=0;

void mario(charac &p);    //Defines mario
void maria(charac &p);    //Defines maria

//Declaration of functions
void back();
void front();

void tree(pt &a);         //Define tree
void evilcrab(pt a);      //Defines crab
void canpan(pt a);        //Defines plant
void score(float a);      // To show score


void interrupt(*OldKeyboard)(...);
void InitKeyboard(void);                 //Initialises keyboard
void RestoreKeyboard(void);              //restores keyboard

void interrupt MyKeyboard(...)
{
unsigned key;
key=inp(0x60);
outp(0x20,0x20);

if(key==0x4b)
{
back();
keypressed=1;
}

else if(key==0x4d)
{
front();
keypressed=1;
}

if(select==1)
{
	if (key==0x48)
	{
	p.jump();
	keypressed=1;
	}
}

else if(select==0)
{
	if(key==0x39)
	{
	select=1;
	}
	if (key==0x48)
	{
	s++;
	}
	if(key==0x50)
	{
	s++;
	}
}

if (key==0X81)
save(game);

}


void InitKeyboard(void)
{
OldKeyboard=_dos_getvect(9);
_dos_setvect(9,MyKeyboard);
}

void RestoreKeyboard(void)
{
_dos_setvect(9,OldKeyboard);
}


//Function to move back in the game
void back()
{
t1.mf();
t2.mf();
t3.mf();
e1.mf();
e2.mf();
e3.mf();
c1.mf();
c2.mf();
c3.mf();
ref.mb();
curr_dir=-1;
}

//Function to move forward in the game
void front()
{
t1.mb();
t2.mb();
t3.mb();
e1.mb();
e2.mb();
e3.mb();
c1.mb();
c2.mb();
c3.mb();
ref.mf();
curr_dir=1;
}


//Defines the tree
void tree(pt &a)
{
setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
fillellipse(a.retx(),a.rety()-40,23,23);
fillellipse(a.retx()+10,a.rety()-15,9,9);
fillellipse(a.retx()+10,a.rety()-65,5,5);
fillellipse(a.retx()-25,a.rety()-40,15,15);
fillellipse(a.retx()+25,a.rety()-40,15,15);
fillellipse(a.retx(),a.rety()-15,10,10);
fillellipse(a.retx(),a.rety()-70,13,13);
fillellipse(a.retx()-10,a.rety()-15,5,6);
fillellipse(a.retx()-15,a.rety()-68,10,15);
fillellipse(a.retx()-21,a.rety()-22,10,15);
fillellipse(a.retx()-21,a.rety()-58,10,15);
fillellipse(a.retx()+28,a.rety()-32,10,15);
fillellipse(a.retx()+36,a.rety()-30,10,15);
fillellipse(a.retx()+26,a.rety()-32,10,5);
fillellipse(a.retx()+20,a.rety()-60,10,15);
fillellipse(a.retx()+28,a.rety()-56,9,9);
fillellipse(a.retx()+20,a.rety()-50,10,15);
setfillstyle(SOLID_FILL,BROWN);
bar(a.retx()-5,a.rety()-7.5,a.retx()+5,a.rety()+45);
setcolor(WHITE);
}

//Defines mario
void mario(charac &a)
{
setfillstyle(SOLID_FILL,014);
fillellipse(a.retx()+1,a.rety()+1,6,10);
setfillstyle(SOLID_FILL,BROWN);
fillellipse(a.retx()-1,a.rety()-7,7.5,3);
setfillstyle(1,6);
bar(a.retx()-7,a.rety()-4,a.retx()-1,a.rety()+10);
bar(a.retx()+2,a.rety()+6,a.retx()+8,a.rety()+10);
setfillstyle(SOLID_FILL,014);
sector(a.retx()+8,a.rety()-1,-17,268,5,8);
setfillstyle(SOLID_FILL,001);
fillellipse(a.retx(),a.rety()+27,5,14);
setfillstyle(1,8);
bar(a.retx()-5,a.rety()+48,a.retx()+4,a.rety()+38);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(a.retx()+5,a.rety()-1,1,1);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(a.retx()+10,a.rety()-2,2,2);
}

//Defines maria
void maria(charac &a)
{
setfillstyle(SOLID_FILL,014);
fillellipse(a.retx()+3,a.rety()-3,6,7);
setfillstyle(SOLID_FILL,BROWN);
fillellipse(a.retx()-2,a.rety()-10,6,6);
setfillstyle(SOLID_FILL,014);
sector(a.retx()+9,a.rety()-5,-50,270,3,3);
setfillstyle(SOLID_FILL,005);
fillellipse(a.retx()+1,a.rety()+12,5,9);
sector(a.retx()+1,a.rety()+15,-50,220,18,25);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(a.retx()+6,a.rety()-5,2,3);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(a.retx()+6,a.rety()-5,2,2);
setfillstyle(1,6);
bar(a.retx()-8,a.rety()-8,a.retx()+2,a.rety()+10);
}

float crab_trig=0;
int crab_time=0;

//Defines crab
void evilcrab(pt a)
{
crab_time+=1;

if(crab_time<500)
{crab_trig+=0.25;}
else
{crab_trig-=0.25;}
a.xset(a.retx()+(crab_trig));

if(crab_time>1000)
{crab_time=0;}

setfillstyle(SOLID_FILL,RED);
fillellipse(a.retx(),a.rety(),17,15);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(a.retx()+6,a.rety()-2,5,5);
fillellipse(a.retx()-6,a.rety()-2,5,5);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(a.retx()+6,a.rety()-2,4,4);
fillellipse(a.retx()-6,a.rety()-2,4,4);
setfillstyle(SOLID_FILL,RED);
fillellipse(a.retx()-5,a.rety()+18,1,6);
fillellipse(a.retx()+5,a.rety()+18,1,6);
fillellipse(a.retx()-10,a.rety()+17,1,8);
fillellipse(a.retx()+10,a.rety()+17,1,8);
sector(a.retx()-28,a.rety()+20,79,53,23,23);
sector(a.retx()-37,a.rety()+9,20,53,23,25);
sector(a.retx()+28,a.rety()+20,127,101,23,23);
sector(a.retx()+39,a.rety()+12,-220,120,23,25);

}

//Defines plant
float plant_trig=0;
int plant_time=0;

void canpan(pt a)
{

float p=a.retx();
float q=a.rety();

plant_time+=1;

if(plant_time<250)
{plant_trig-=0.20;}
else if(plant_time>250&&plant_time<500)
{plant_trig+=0.20;}

a.yset(a.rety()+(plant_trig));

if(plant_time>2500)
{plant_time=0;}

setfillstyle(SOLID_FILL,GREEN);
fillellipse(a.retx(),a.rety(),15,15);
fillellipse(a.retx()+5,a.rety()+15,2,2);
fillellipse(a.retx()+7.5,a.rety()+19,2,2);
fillellipse(a.retx()+7.5,a.rety()+23,2,2);
fillellipse(a.retx()+8,a.rety()+27,2,2);
fillellipse(a.retx()+7.5,a.rety()+31,2,2);
fillellipse(a.retx()+5,a.rety()+35,2,2);
fillellipse(a.retx()+5,a.rety()+39,2,2);
fillellipse(a.retx()+17,a.rety()+25,8,3);
fillellipse(a.retx(),a.rety()+25,5,3);
setfillstyle(SOLID_FILL,RED);
sector(a.retx(),a.rety(),220,170,15,15);
setfillstyle(1,1);
fillellipse(a.retx()+6,a.rety()-6,5,5);
setfillstyle(SOLID_FILL,WHITE);
sector(a.retx()-12,a.rety()+4.5,290,325,4,4);
sector(a.retx()-5,a.rety()+1.5,290,325,3,3);
sector(a.retx()-14.5,a.rety()+2,80,50,4,4);
sector(a.retx()-8.5,a.rety()+3.5,100,80,3,3);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(a.retx()+6,a.rety()-6,4,4);

setfillstyle(SOLID_FILL,BROWN);
bar(p-20,q-1,p+30,q+8);
bar(p-15,q+8,p+25,q+40);

}


//Defines coin
void coin(pt &a)
{
 setfillstyle(SOLID_FILL,RED);
 fillellipse(a.retx(),a.rety(),5,5);
setfillstyle(SOLID_FILL,YELLOW);
 fillellipse(a.retx(),a.rety(),3,3);
}


//Displays score
void score(float c)
{
setfillstyle(SOLID_FILL,000);
settextstyle(1,0,1);
if (fmod(c,100)==0)
outtextxy(450,50,"00");
if (fmod(c,100)==10)
outtextxy(450,50,"10");
if (fmod(c,100)==20)
outtextxy(450,50,"20");
if (fmod(c,100)==30)
outtextxy(450,50,"30");
else if (fmod(c,100)==40)
outtextxy(450,50,"40");
else if (fmod(c,100)==50)
outtextxy(450,50,"50");
else if (fmod(c,100)==60)
outtextxy(450,50,"60");
else if (fmod(c,100)==70)
outtextxy(450,50,"70");
else if (fmod(c,100)==80)
outtextxy(450,50,"80");
else if (fmod(c,100)==90)
outtextxy(450,50,"90");
if (fmod(c/100,100)==0)
outtextxy(440,50,"0");
if (fmod(c/100,100)==1)
outtextxy(440,50,"1");
if (fmod(c/100,100)==2)
outtextxy(440,50,"2");
if (fmod(c/100,100)==3)
outtextxy(440,50,"3");
else if (fmod(c/100,100)==4)
outtextxy(440,50,"4");
else if (fmod(c/100,100)==5)
outtextxy(440,50,"5");
else if (fmod(c/100,100)==6)
outtextxy(440,50,"6");
else if (fmod(c/100,100)==7)
outtextxy(440,50,"7");
else if (fmod(c/100,100)==8)
outtextxy(440,50,"8");
else if (fmod(c/100,100)==9)
outtextxy(440,50,"9");
}

//Displays distance
void distance(float x)
{
int c=x;
outtextxy(125,50,"DISTANCE:");
setfillstyle(SOLID_FILL,000);
settextstyle(1,0,1);

{
if (fmod(c,10)==0)
outtextxy(250,50,"0");
if (fmod(c,10)==1)
outtextxy(250,50,"1");
if (fmod(c,10)==2)
outtextxy(250,50,"2");
if (fmod(c,10)==3)
outtextxy(250,50,"3");
else if (fmod(c,10)==4)
outtextxy(250,50,"4");
else if (fmod(c,10)==5)
outtextxy(250,50,"5");
else if (fmod(c,10)==6)
outtextxy(250,50,"6");
else if (fmod(c,10)==7)
outtextxy(250,50,"7");
else if (fmod(c,10)==8)
outtextxy(250,50,"8");
else if (fmod(c,10)==9)
outtextxy(250,50,"9");
}

{
if (fmod(c/10,10)==0)
outtextxy(240,50,"0");
if (fmod(c/10,10)==1)
outtextxy(240,50,"1");
if (fmod(c/10,10)==2)
outtextxy(240,50,"2");
if (fmod(c/10,10)==3)
outtextxy(240,50,"3");
else if (fmod(c/10,10)==4)
outtextxy(240,50,"4");
else if (fmod(c/10,10)==5)
outtextxy(240,50,"5");
else if (fmod(c/10,10)==6)
outtextxy(240,50,"6");
else if (fmod(c/10,10)==7)
outtextxy(240,50,"7");
else if (fmod(c/10,10)==8)
outtextxy(240,50,"8");
else if (fmod(c/10,10)==9)
outtextxy(240,50,"9");
}

{
if (fmod(c/100,10)==0)
outtextxy(230,50,"0");
if (fmod(c/100,10)==1)
outtextxy(230,50,"1");
if (fmod(c/100,10)==2)
outtextxy(230,50,"2");
if (fmod(c/100,10)==3)
outtextxy(230,50,"3");
else if (fmod(c/100,10)==4)
outtextxy(230,50,"4");
else if (fmod(c/100,10)==5)
outtextxy(230,50,"5");
else if (fmod(c/100,10)==6)
outtextxy(230,50,"6");
else if (fmod(c/100,10)==7)
outtextxy(230,50,"7");
else if (fmod(c/100,10)==8)
outtextxy(230,50,"8");
else if (fmod(c/100,10)==9)
outtextxy(230,50,"9");
}

{
if (fmod(c/1000,10)==0)
outtextxy(220,50,"0");
if (fmod(c/1000,10)==1)
outtextxy(220,50,"1");
if (fmod(c/1000,10)==2)
outtextxy(220,50,"2");
if (fmod(c/1000,10)==3)
outtextxy(220,50,"3");
else if (fmod(c/1000,10)==4)
outtextxy(220,50,"4");
else if (fmod(c/1000,10)==5)
outtextxy(220,50,"5");
else if (fmod(c/1000,10)==6)
outtextxy(220,50,"6");
else if (fmod(c/1000,10)==7)
outtextxy(220,50,"7");
else if (fmod(c/1000,10)==8)
outtextxy(220,50,"8");
else if (fmod(c/1000,10)==9)
outtextxy(220,50,"9");
}

}

//Displays score
void score2 (float c)
{
setfillstyle(SOLID_FILL,001);
settextstyle(1,0,3);
{
if (fmod(c,100)==0)
outtextxy(450,250,"00");
if (fmod(c,100)==10)
outtextxy(450,250,"10");
if (fmod(c,100)==20)
outtextxy(450,250,"20");
if (fmod(c,100)==30)
outtextxy(450,250,"30");
else if (fmod(c,100)==40)
outtextxy(450,250,"40");
else if (fmod(c,100)==50)
outtextxy(450,250,"50");
else if (fmod(c,100)==60)
outtextxy(450,250,"60");
else if (fmod(c,100)==70)
outtextxy(450,250,"70");
else if (fmod(c,100)==80)
outtextxy(450,250,"80");
else if (fmod(c,100)==90)
outtextxy(450,250,"90");
}

{
if (fmod(c/100,100)==0)
outtextxy(430,250,"0");
if (fmod(c/100,100)==1)
outtextxy(430,250,"1");
if (fmod(c/100,100)==2)
outtextxy(430,250,"2");
if (fmod(c/100,100)==3)
outtextxy(430,250,"3");
else if (fmod(c/100,100)==4)
outtextxy(430,250,"4");
else if (fmod(c/100,100)==5)
outtextxy(430,250,"5");
else if (fmod(c/100,100)==6)
outtextxy(430,250,"6");
else if (fmod(c/100,100)==7)
outtextxy(430,250,"7");
else if (fmod(c/100,100)==8)
outtextxy(430,250,"8");
else if (fmod(c/100,100)==9)
outtextxy(430,250,"9");
}

}

int newplayer(account me);      //To see if player exists already

void save(player me)            //To save game to file
{
me.set_auto_save('n');

clrscr();

if(ref.retx())
{
	closegraph();
	RestoreKeyboard();
	cout<<"Do you wish to save your score?\n";
	char ch;
	cin>>ch;

	if(ch=='n'||ch=='N')
	return;

	else if(ch=='y'||ch=='Y')
	{
	fstream fout;
	fout.open("Stats.txt",ios::out|ios::ate|ios::binary);

	if(!fout)
		{
		cout<<"Error opening file.Aborting.\n";
		getch();
		return;
		}
	else
		{
		me.set_auto_save('n');
		fout.write((char*)&me,sizeof(me));

		cout<<"We have saved your score,";
		me.d();
		fout.close();
		getch();

		fstream fin;
		fin.open("Account.txt",ios::in|ios::out|ios::ate|ios::binary);
		if(!fin)
		{
		cout<<"Error opening file.Aborting.\n";
		return;
		}

		else
		{                           //To set first game to zero
		int i,j;
		account temp;
		clrscr();
		while(fin.read((char*)&game,sizeof(game)))
		{
		if(me.name==temp.name && temp.ret_first_game()==1)
		{
		temp.set_first_game(0);
		fin.seekp(-sizeof(temp),ios::cur);
		}
		}
	}
	delay(10);
}

}

else
cout<<"Sorry, wrong choice entered.Unable to save your high score.";
delay(10);
}

else
exit(0);

}

//To pick mario or maria as character
int selection()
{
clrscr();
cleardevice();

int q=0;
select=0;

do
{
	settextstyle(1,0,1);
	outtextxy(150,400,"PRESS DOWN ARROW TO SWITCH AND SPACE TO SELECT");
	settextstyle(1,0,4);
	if (s%2==0)
		{
		setfillstyle(1,0);
		bar(200,100,400,200);
		settextstyle(1,0,4);
		outtextxy(225,140,"MARIO" );
		setfillstyle(1,1);
		bar(200,225,400,325);
		settextstyle(1,0,4);
		outtextxy(225,265,"MARIA" );
		}

		if (s%2==1)
		{
		setfillstyle(1,1);
		bar(200,100,400,200);
		outtextxy(225,140,"MARIO" );
		setfillstyle(1,0);
		bar(200,225,400,325);
		outtextxy(225,265,"MARIA" );
		}

		if(s%2==0)
		q=0;
		else
		{q=1;}

}while(select==0);

return q;
}

void disp_scores();

void disp_high()            //To display high scores
{
fstream fin;
player temp;

fin.open("Stats.txt",ios::in|ios::binary);
if(!fin)
{
	cleardevice();
	cout<<"Error opening file.Aborting.\n";
	delay(1000);
	return;
}

else
{
	cleardevice();
	int max=0;
	cleardevice();
	RestoreKeyboard();
	fin.seekg(0,ios::beg);
	cout<<"Your highest score in the game (Game stats):";
	while(fin.read((char*)&temp,sizeof(temp)))
	{
	if(me.name_comp(temp.name))
	{
	if(game.score>max)
	max=game.score;
	}
}

fin.close();
fin.open("Stats.txt",ios::in|ios::binary);

while(fin.read((char*)&temp,sizeof(temp)))
{
if(temp.score==max)
{
break;
}
temp.display();

}
}
}

//To continue game
void continue_game(account &me,player &game)
{
setbkcolor(4);
cleardevice();
select=0;

if(newplayer(me)==0&&new_player==0)    //If it is an old player
{
s=0;
int p=0;

cleardevice();
do
{
	settextstyle(1,0,1);
	outtextxy(150,450,"PRESS ARROWS TO SWITCH AND SPACE TO SELECT");
	settextstyle(1,0,1);

	if (s%5==0)
	{
	setfillstyle(1,1);
	bar(150,50,450,100);
	settextstyle(1,0,1);
	outtextxy(225,75,"Start a new game" );
	setfillstyle(1,7);
	bar(150,125,450,175);
	settextstyle(1,0,1);
	outtextxy(225,150,"continue saved game" );
	setfillstyle(1,7);
	bar(150,200,450,250);
	settextstyle(1,0,1);
	outtextxy(225,225,"Start autosaved game" );
	setfillstyle(1,7);
	bar(150,275,450,325);
	settextstyle(1,0,1);
	outtextxy(225,300,"See your high score" );
	setfillstyle(1,7);
	bar(150,350,450,400);
	settextstyle(1,0,1);
	outtextxy(225,375,"See Past Games" );
	}

	if (s%5==1)
	{
	setfillstyle(1,7);
	bar(150,50,450,100);
	settextstyle(1,0,1);
	outtextxy(225,75,"Start a new game" );
	setfillstyle(1,1);
	bar(150,125,450,175);
	settextstyle(1,0,1);
	outtextxy(225,150,"continue saved game" );
	setfillstyle(1,7);
	bar(150,200,450,250);
	settextstyle(1,0,1);
	outtextxy(225,225,"Start autosaved game" );
	setfillstyle(1,7);
	bar(150,275,450,325);
	settextstyle(1,0,1);
	outtextxy(225,300,"See your high score" );
	setfillstyle(1,7);
	bar(150,350,450,400);
	settextstyle(1,0,1);
	outtextxy(225,375,"See Past Games" );
	}

	if (s%5==2)
	{
	setfillstyle(1,7);
	bar(150,50,450,100);
	settextstyle(1,0,1);
	outtextxy(225,75,"Start a new game" );
	setfillstyle(1,7);
	bar(150,125,450,175);
	settextstyle(1,0,1);
	outtextxy(225,150,"continue saved game" );
	setfillstyle(1,1);
	bar(150,200,450,250);
	settextstyle(1,0,1);
	outtextxy(225,225,"Start autosaved game" );
	setfillstyle(1,7);
	bar(150,275,450,325);
	settextstyle(1,0,1);
	outtextxy(225,300,"See your high score" );
	setfillstyle(1,7);
	bar(150,350,450,400);
	settextstyle(1,0,1);
	outtextxy(225,375,"See Past Games" );
	}

	if(s%5==3)
	{
	setfillstyle(1,7);
	bar(150,50,450,100);
	settextstyle(1,0,1);
	outtextxy(225,75,"Start a new game" );
	setfillstyle(1,7);
	bar(150,125,450,175);
	settextstyle(1,0,1);
	outtextxy(225,150,"continue saved game" );
	setfillstyle(1,7);
	bar(150,200,450,250);
	settextstyle(1,0,1);
	outtextxy(225,225,"Start autosaved game" );
	setfillstyle(1,1);
	bar(150,275,450,325);
	settextstyle(1,0,1);
	outtextxy(225,300,"See your high score" );
	setfillstyle(1,7);
	bar(150,350,450,400);
	settextstyle(1,0,1);
	outtextxy(225,375,"See Past Games" );
	}

	if(s%5==4)
	{
	setfillstyle(1,7);
	bar(150,50,450,100);
	settextstyle(1,0,1);
	outtextxy(225,75,"Start a new game" );
	setfillstyle(1,7);
	bar(150,125,450,175);
	settextstyle(1,0,1);
	outtextxy(225,150,"continue saved game" );
	setfillstyle(1,7);
	bar(150,200,450,250);
	settextstyle(1,0,1);
	outtextxy(225,225,"Start autosaved game" );
	setfillstyle(1,7);
	bar(150,275,450,325);
	settextstyle(1,0,1);
	outtextxy(225,300,"See your high score" );
	setfillstyle(1,1);
	bar(150,350,450,400);
	settextstyle(1,0,1);
	outtextxy(225,375,"See Past Games" );
	}

	if(s%5==0)
	p=0;
	else if(s%5==1)
	p=1;
	else if(s%5==2)
	p=2;
	else if(s%5==3)
	p=3;
	else if(s%5==4)
	p=4;

}while(select==0);

if(p==0)
{
cleardevice();
game.copy(me.name,0,selection(),pt(0,250),'n',pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250));
me.set_first_game(1);
return;
}

//To continue game
else if(p==1)
{
fstream fin;
fin.open("Stats.txt",ios::in|ios::binary);
if(!fin)
{
cleardevice();
cout<<"Error opening file.Aborting.\n";
delay(1000);
return;
}
else
{ cleardevice();
int i=1;
cleardevice();
RestoreKeyboard();

fin.seekg(0,ios::beg);

while(fin.read((char*)&game,sizeof(game)))
{
if(me.name_comp(game.name) && game.ret_auto_save()=='n')
{
cout<<i<<"\t";
game.display();
cout<<endl;
i++;
}
}
cout<<"Enter the game number you wish to continue with.\n";
int num;
cin>>num;

fin.close();
fin.open("Stats.txt",ios::in|ios::binary);
i=1;
while(fin.read((char*)&game,sizeof(game)))
{

if(me.name_comp(game.name))
{
if(i==num)
break;

cout<<i<<endl;
i++;
}

}

InitKeyboard();
return;
}
}

//To continue auto saved game
else if(p==2)
{
cleardevice();

fstream fin;
fin.open("stats.txt",ios::in|ios::binary);
if(!fin)
{
cout<<"Error opening file.Aborting.\n";
return;
}
else
{
fin.seekg(0);
while(fin.read((char*)&game,sizeof(game)))
{
if(me.name_comp(game.name) && game.ret_auto_save()=='y')
{
break;
}
}

return;
}
}

//To show high score
else if(p==3)
{
cleardevice();
RestoreKeyboard();
disp_high();
cout<<"/nPress any key to return to the menu.\n";
getch();

InitKeyboard();
continue_game(me,game);
}

//To see past games
else if(p==4)
{
cleardevice();
RestoreKeyboard();
disp_scores();
cout<<"/nPress any key to return to the menu.\n";
getch();
InitKeyboard();
continue_game(me,game);
}
}

if(new_player==1)       //If player is new

{

cleardevice();

account temp;
int x=selection();
game.copy(me.name,0,x,pt(0,250),'n',pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250),pt(650,250));

me.set_first_game(0);
cleardevice();

fstream fio("Account.txt",ios::in|ios::out|ios::ate|ios::binary);
while(fio.read((char*)&temp,sizeof(temp)))
{
if(temp.comp(me.name))
{
fio.seekp(-sizeof(temp),ios::cur);
fio.write((char*)&me,sizeof(me));
}
}

return;
}

}

//To auto save
void auto_save(player game)
{
player g;
game.set_auto_save('y');
fstream fio;

fio.open("stats.txt",ios::in|ios::out|ios::ate|ios::binary);
fio.seekg(0);
while(fio.read((char*)&g,sizeof(g)))
{
if(g.name_comp(game.name) && g.ret_auto_save()=='y')
{
fio.seekp((-1)*sizeof(game),ios::cur);
fio.write((char*)&game,sizeof(game));
}

}
fio.close();
}

//To login
void login(account &me)
{
InitKeyboard();

select=0;

while(!select)
{
setbkcolor(9);
settextstyle(1,0,4);
settextjustify(CENTER_TEXT,100);
settextstyle(1,0,6);
outtextxy(200,100,"MENU" );
settextstyle(1,0,2);
outtextxy(150,200,"This program uses OOPs and File handling in m\Mario" );
settextstyle(1,0,2);
outtextxy(150,300,"Press space to login." );
delay(30);
}
setbkcolor(0);


clrscr();
select=0;
int r;

do
{

settextstyle(1,0,1);
outtextxy(150,400,"PRESS ARROWS TO SWITCH AND SPACE TO SELECT");
settextstyle(1,0,1);
if (s%2==0)
{
	setfillstyle(1,0);
	bar(200,100,450,200);
	settextstyle(1,0,1);
	outtextxy(210,140,"Login with an old account" );
	setfillstyle(1,3);
	bar(200,225,450,325);
	settextstyle(1,0,1);
	outtextxy(210,265,"Create a new account" );

}

if (s%2==1)
{
	setfillstyle(1,3);
	bar(200,100,450,200);
	settextstyle(1,0,1);
	outtextxy(210,140,"Login with an old account" );
	setfillstyle(1,0);
	bar(200,225,450,325);
	outtextxy(210,265,"Create a new account" );
}

if(s%2==0)
r=0;
else if(s%2==1)
{r=1;}

delay(50);
}while(select==0);

if(r==0)      //To create account
{

clrscr();
char n[30],p[20];

cleardevice();

settextstyle(1,0,1);
outtextxy(150,350,"Enter your name");

RestoreKeyboard();
gets(n);

cleardevice();
outtextxy(175,400,"Enter your password");
gets(p);

cleardevice();
outtextxy(200,400,"Your account has been created");
me.copy(n,1,p,0);
new_player=1;
getch();
clrscr();

ofstream fout;
fout.open("account.txt",ios::out|ios::ate|ios::binary);
fout.write((char*)&me,sizeof(me));

return;
}

else if(r==1)    //To login with old account
{

int flag=0,try=0;

while(try<5)
{
RestoreKeyboard();
char n[30],p[20];

cleardevice();
outtextxy(150,350,"Enter your name");

gets(n);
fstream fio;
fio.seekg(0);
fio.open("account.txt",ios::out|ios::in|ios::binary);

while(fio.read((char*)&me,sizeof(me)))
{
	if(me.name_comp(n))
	{
	flag=1;
	break;
}

}
fio.close();

if (flag==0)
{
clrscr();
cleardevice();
cout<<"Sorry, no such user name exists.Try again\n";
getch();
exit(0);
}

cleardevice();
outtextxy(175,400,"Enter your password");
gets(p);

if(me.comp(p))
{
new_player=0;
return;
}
else
{
cleardevice();
outtextxy(150,400,"Sorry,wrong password,press enter and try again");
try++;
getch();
}
}

outtextxy(150,400,"Sorry,max 5 tries.Exiting from program.");
delay(1000);
exit(0);
}

clrscr();
}

//To show scores
void disp_scores()
{
ifstream fin("Stats.txt",ios::in|ios::binary);

player temp;

while(fin.read((char*)&temp,sizeof(temp)))
{
	if(me.name_comp(temp.name))
	{
	temp.display();
	cout<<endl;
	}
}
}

//To check if new player
int newplayer(account me)
{
ifstream fin("Stats.txt",ios::in|ios::binary);
account temp;

while(fin.read((char*)&temp,sizeof(temp)))
{
if(me.name_comp(temp));
return 0;
}
return 1;
}

//Defines sky
void sky()
{
setfillstyle(SOLID_FILL,LIGHTBLUE);
bar(100-100,100-100,100+600,100+190);
setfillstyle(SOLID_FILL,LIGHTGREEN);
bar(100-100,100+190,100+600,100+350);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(100+50,100,15,15);
fillellipse(100+115,100,15,15);
fillellipse(100+65,100-20,15,15);
fillellipse(100+65,100+20,15,15);
fillellipse(100+95,100+20,15,15);
fillellipse(100+95,100-20,15,15);
fillellipse(100+65,100+5,15,15);
fillellipse(100+85,100,20,20);
fillellipse(100+300,100,15,15);
fillellipse(100+365,100,15,15);
fillellipse(100+315,100-20,15,15);
fillellipse(100+315,100+20,15,15);
fillellipse(100+345,100+20,15,15);
fillellipse(100+345,100-20,15,15);
fillellipse(100+315,100+5,15,15);
fillellipse(100+335,100,20,20);
}

int GraphDriver;
int GraphMode;

void main()
{
clrscr();
randomize();

//Initialising graphics
GraphDriver=DETECT;
initgraph(&GraphDriver,&GraphMode,"");
if(graphresult()!=grOk)
exit(1);

login(me);

InitKeyboard();

int flag=0;

continue_game(me,game);

setbkcolor(0);

//Sets initial coordinates
ref.xset(game.ref_lastgame_retx());
ref.yset(game.ref_lastgame_rety());
t1.xset(game.t1_retx());
t1.yset(game.t1_rety());
t2.xset(game.t2_retx());
t2.yset(game.t2_rety());
t3.xset(game.t3_retx());
t3.yset(game.t3_rety());
e1.xset(game.e1_retx());
e1.yset(game.e1_rety());
e2.xset(game.e2_retx());
e2.yset(game.e2_rety());
e3.xset(game.e3_retx());
e3.yset(game.e3_rety());
c1.xset(game.c1_retx());
c1.yset(game.c1_rety());
c2.xset(game.c2_retx());
c2.yset(game.c2_rety());
c3.xset(game.c3_retx());
c3.yset(game.c3_rety());

clrscr();

//end of select


outtextxy(200,250,"LOADING");
delay(1000);

do
{

if (p.rety()>min_height)
p.yset(min_height);

sky();

//Position of tree one
if(ref.retx()>0&&ref.retx()<800)
tree(t1);

if(ref.retx()>1400&&ref.retx()<2100)
tree(t1);

if(ref.retx()>2300&&ref.retx()<3000)
tree(t1);

if(ref.retx()>3300&&ref.retx()<4000)
tree(t1);

if((ref.retx()>800&&ref.retx()<1400)||(ref.retx()>2100&&ref.retx()<3000)||ref.retx()>3300&&ref.retx()<4000&&ref.retx()>3100)
t1.xset(650);


//Position of tree two
if(ref.retx()>300&&ref.retx()<1000)
tree(t2);

if(ref.retx()>1600&&ref.retx()<2300)
tree(t2);

if(ref.retx()>2700&&ref.retx()<3400)
tree(t2);

if(ref.retx()>4100&&ref.retx()<4800)
tree(t2);

if(ref.retx()<300||(ref.retx()>1000&&ref.retx()<1600)||(ref.retx()>2300&&ref.retx()<2700)||ref.retx()>3400&&ref.retx()<4100&&ref.retx()>4800)
t2.xset(650);


//Position of crab one
if(ref.retx()>100&&ref.retx()<900)
evilcrab(e1);

if(ref.retx()>1100&&ref.retx()<1800)
evilcrab(e1);

if(ref.retx()>2200&&ref.retx()<2900)
evilcrab(e1);

if(ref.retx()>3200&&ref.retx()<3900)
evilcrab(e1);

if((ref.retx()<100)||(ref.retx()>900&&ref.retx()<1100)||(ref.retx()>1800&&ref.retx()<2200)||ref.retx()>2900&&ref.retx()<3200&&ref.retx()>3900)
e1.xset(650);

//Position of crab 2
if(ref.retx()>500&&ref.retx()<1200)
evilcrab(e2);

if(ref.retx()>1500&&ref.retx()<2300)
evilcrab(e2);

if(ref.retx()>2800&&ref.retx()<3500)
evilcrab(e2);

if((ref.retx()<500)||(ref.retx()>1200&&ref.retx()<1500)||(ref.retx()>2300&&ref.retx()<2800)||ref.retx()>3500)
e2.xset(650);


//Position of plant
if(ref.retx()>400&&ref.retx()<1100)
canpan(c1);

if(ref.retx()>1600&&ref.retx()<2500)
canpan(c1);

if(ref.retx()>3000&&ref.retx()<3800)
canpan(c1);

if((ref.retx()<400)||(ref.retx()>1100&&ref.retx()<1600)||(ref.retx()>2500&&ref.retx()<3000)||ref.retx()>3800)
c1.xset(650);


//Postion of coin 1
if(ref.retx()>0&&ref.retx()<700)
coin(e3);

if(ref.retx()>800&&ref.retx()<1400)
coin(e3);

if(ref.retx()>1600&&ref.retx()<2100)
coin(e3);


if((ref.retx()<0)||(ref.retx()>700&&ref.retx()<800)||(ref.retx()>1400&&ref.retx()<1600)||ref.retx()>2100)
e3.xset(600);


//Position of coin 2
if(ref.retx()>100&&ref.retx()<800)
coin(t3);

if(ref.retx()>900&&ref.retx()<1700)
coin(t3);

if(ref.retx()>2300&&ref.retx()<3000)
coin(t3);


if((ref.retx()<100)||(ref.retx()>800&&ref.retx()<900)||(ref.retx()>1700&&ref.retx()<2300)||ref.retx()>3000)
t3.xset(650);

//Postion of coin 3
if(ref.retx()>800&&ref.retx()<1500)
coin(c2);

if(ref.retx()>1600&&ref.retx()<2400)
coin(c2);

if(ref.retx()>2800&&ref.retx()<3500)
coin(c2);


if((ref.retx()<800)||(ref.retx()>1500&&ref.retx()<1600)||(ref.retx()>2400&&ref.retx()<2800)||ref.retx()>3500)
c2.xset(650);


//Position of coin 4
if(ref.retx()>500&&ref.retx()<1300)
coin(c3);

if(ref.retx()>2000&&ref.retx()<2800)
coin(c3);

if(ref.retx()>3000&&ref.retx()<3800)
coin(c3);

if((ref.retx()<500)||(ref.retx()>1300&&ref.retx()<2000)||(ref.retx()>2800&&ref.retx()<3000)||ref.retx()>3800)
c3.xset(650);



flag++;         //counter

if (game.ret_mario_maria()==1)
{
mario(p);
}

if(game.ret_mario_maria()==0)
maria(p);
settextstyle(1,0,1);
outtextxy(300,50,"your coins are:");

score(sc);
distance(ref.retx());
settextstyle(1,0,2);

//To see if crabs or plant have hit the character

if ((pow(((e1.retx()+(crab_trig))-p.retx()),2)+pow((e1.rety()-(p.rety())),2))<400)//&&(p.rety()>min_height-15))
{
goto lb;
}

if ((pow(((e2.retx()+(crab_trig))-p.retx()),2)+pow((e2.rety()-(p.rety())),2))<400)
{
goto lb;
}

if ((pow(((c1.retx())-p.retx()),2)+pow((c1.rety()+plant_trig-(p.rety())),2))<400)//&&(p.rety()>min_height-15))
{
goto lb;
}

//To increment score on picking up coins
if ((pow(((e3.retx())-p.retx()),2)+pow((e3.rety()-(p.rety())),2))<400)
{
sc+=10;
e3.xset(650);
}

if ((pow(((t3.retx())-p.retx()),2)+pow((t3.rety()-(p.rety())),2))<400)
{
sc+=10;
t3.xset(650);
}

if ((pow(((c3.retx())-p.retx()),2)+pow((c3.rety()-(p.rety())),2))<400)
{
sc+=10;
c3.xset(650);
}


//Saves game and clears screen
if (flag==10)
{flag=0;
cleardevice();
game.copy(sc,ref,'y',e1,e2,e3,t1,t2,t3,c1,c2,c3);
auto_save(game);
}

}while (ref.retx()<=5000);

lb:
lost=0;
flag=0;

//loop runs after game is lost
while(p.rety()>250)
{
setfillstyle(SOLID_FILL,YELLOW);
outtextxy(100,250,"aaaaaaaaaaaaaaaaaaaaaaaaah");

if (me.ret_mario_maria()==1)
mario(p);
if(me.ret_mario_maria()==0)
maria(p);
p.yset(p.rety()-1);
outtextxy(250,100,"Mamma Mia!!!");

if (flag==5)
{
flag=0;
cleardevice();
}

flag++;
delay(0);
}

while(p.rety()<500)
{

if (game.ret_mario_maria()==1)
mario(p);
if(game.ret_mario_maria()==0)
maria(p);
p.yset(p.rety()+1);

if (flag==5)
{
flag=0;
cleardevice();
}

if (flag==20)
{
flag=0;
}

flag++;
delay(0);
}

//If game is won
if(ref.retx()>=4900)
{
for(int w=0;w<=100;w++)
{
lost=1;
settextstyle(1,0,4);
outtextxy(300,200,"you won!!!!!!!!!!!!!" );}
}

if(lost==0)
{
settextstyle(1,0,3);
outtextxy(175,150,"you lost :(");
}
settextstyle(1,0,2);
outtextxy(50,250,"YOUR SCORE IS ");
score2(sc);

for(int o=0;o<=1000;o++)
{
delay(5);
}


closegraph();
RestoreKeyboard();


game.copy(sc,ref,'n',e1,e2,e3,t1,t2,t3,c1,c2,c3);
save(game);

getch();
}
