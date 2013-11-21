
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
//Game Data
int l=0,m=0;
int score;         //Keeps the count of game score
int gamedelay=5;
int level=0;
int flag=0;               //Lower the game delay faster is the game speed.
struct Snake_Data
{
	int length;
	int head_x; // Stores Head X Coordinate
	int head_y; // Stores Head Y Coordinate
	int head_dir; // Stores Head Direction
	int tail_x; // Stores Tail X Coordinat
	int tail_y; // Stores Tail Y Coordinat
	int tail_dir; // Stores Tail Direction
	int bend_x [1000]; //Stores X Bend Coordinate Declare it big enough to accomodate maximum bends
	int bend_y[1000]; // Stores Y Bend Coordinate Declare it big enough to accomodate maximum bends
	int bend_dir [1000];
} Snake; // Declares a variable of the structure
// User - Defined functions -
void initscreen() //Draws Intial Screen.
{
	int i=0;
	char scorestring [100];
	//Draw Boundary
	setcolor (4);
	line(10,10,10,700);
	line(1008,10,1008,700);
	line(10,700,1008,700);
	line (10,10,1008,10);
	//Write Score on scree
	sprintf(scorestring, "Score : %d     LEVEL :%d", score,level);
	outtextxy(20,710, scorestring);
	//Draw Intial Snake Body
	for (i = Snake.length; i>0;i--) //This part should be redesigned for change of code of intial values
	{
		putpixel(Snake.head_x-i,Snake.head_y,15);
	}
}

int randomvalue (int starting, int ending) // Return a random int value between end and starting parameters
{
	static int previous = 0;
	int answer;
	if (previous <0) previous = 0;
	int difference = starting - ending;
	time_t t;
	srand((unsigned) time(&t));
	for (int i = 0; i <previous;i++) rand ();
	answer = (rand () % difference);
	previous++;
	return answer;
} 

void initgamedata ( ) //Snakes starting coordinate if you modify any one make sure also modify dependent values
{
	int i;
	Snake.length = 100;
	Snake.head_x = 200;
	Snake.head_y = 200;
	Snake.head_dir = RIGHT;
	Snake.tail_x = Snake.head_x- Snake.length;
	Snake.tail_y = Snake.head_y;
	Snake.tail_dir = RIGHT;
	for ( i = 0; i <1000;i++) // There is no bend initally
	{
		Snake.bend_x[i] = 0;
		Snake.bend_y[i] = 0;
		Snake.bend_dir[i] = 0;
	}
	score = 0;
	// Should be change according to game speed need.
}


void gamephysics ()
{
	static int foodcount = 0;//Keep Count of food
	int futurex, futurey, futurepixel;
	int i;
	char scorestring [100];
	if (foodcount < 500) //Adds a food if no food is present and upto maximum 500 food
	{
		int valid = 0;
		int foodx;
		int foody;
		while (!valid)
		{
			foodx = randomvalue (15,1003);
			foody = randomvalue (15,695);
			if (getpixel (foodx,foody)!= 15)
			{
				putpixel (foodx,foody,2);
				foodcount++;
				valid = 1;}
		}
	}

	//Boundary Collision Check -
	if (Snake.head_x <= 10 || Snake.head_x >= 1008 || Snake.head_y <= 10 || Snake.head_y >= 700){
		outtextxy (499,345, "Game Over");
		delay (3000);
		exit (1);
	}
	//Get future value of head in int variable futurex and futurey and calculate the logic
	futurex = Snake.head_x;
	futurey = Snake.head_y;
	if(Snake.head_dir == LEFT){
		futurex --;
	}
	if (Snake.head_dir == RIGHT) {
		futurex ++;
	}
	if (Snake.head_dir == UP) {
		futurey --;
	}
	if (Snake.head_dir == DOWN) {
		futurey ++;
	}
	futurepixel = getpixel(futurex,futurey);
	//Food Eaten
	if (futurepixel == 2){
		foodcount --; //Reduce count
		if(score==2){
			score=0;
			level++;
			flag=1;
			//	initgamedata();
			//	gamedelay--;
		}
		else{
			score++; }//Increase Score
		setcolor (0);//Rewrite Score
		setfillstyle (0,0);
		bar (11,701,1007, 735);
		setcolor (4);
		sprintf(scorestring, "Score : %d     LEVEL :%d", score,level);
		outtextxy (20,710, scorestring);
		//Increase the size of snake by 100 pixel you can put as much as you want
		if(flag==0){
			if (Snake.tail_dir == UP)
			{for (i = 0; i<101;i++)
				putpixel (Snake.tail_x,Snake.tail_y+i,15);
			Snake.tail_y +=100;
			}
			if (Snake.tail_dir == DOWN){
				for (i = 0; i<101;i++)
					putpixel (Snake.tail_x,Snake.tail_y-i,15);
				Snake.tail_y -=100;
			}
			if (Snake.tail_dir == LEFT){
				for (i = 0; i<101;i++)
					putpixel (Snake.tail_x+i,Snake.tail_y,15);
				Snake.tail_x +=100;
				//printf ("LEFT");
			}
			if (Snake.tail_dir == RIGHT){
				for (i = 0; i<101;i++)
					putpixel (Snake.tail_x-i,Snake.tail_y,15);
				Snake.tail_x -=100;
				// printf ("RIGHT");
			}
		}}
	if(futurepixel == 15)
	{outtextxy (499,345, "Game Over");
	delay(3000);
	exit (1);
	}}

void userinput ()// This Function changes the direction of motion of snake according to input.
{
	//static int i = 0;
	//if ( i > 1000)

	if ( l > 1000)l = 0;; // Makes the bend array a circular queue
	//static int j = 0;
	//
	if ( m > 1000) m = 0;
	char input;
	//printf(" user input %d\n",flag);
	if(flag==0){
		if (kbhit ())
		{
			input = getch ();
			//Change Respective Return value to our MACRO Direction Code Value
			if (input == 80) input = DOWN;
			if (input == 72) input = UP;
			if (input == 75) input = LEFT;
			if (input == 77) input = RIGHT;
			if(input ==112){input++;
			while(input!=112){input=getch();
			}
			}
			//Change head direction based on logic
			if (input == LEFT && Snake.head_dir != RIGHT && Snake.head_dir != LEFT){
				Snake.head_dir = LEFT;
				Snake.bend_x [l] = Snake.head_x;
				Snake.bend_y [l] = Snake.head_y;
				Snake.bend_dir [l] = LEFT;
				l++;
			}
			if (input == RIGHT && Snake.head_dir != LEFT && Snake.head_dir != RIGHT){
				Snake.head_dir = RIGHT;
				Snake.bend_x [l] = Snake.head_x;
				Snake.bend_y [l] = Snake.head_y;
				Snake.bend_dir [l] = RIGHT;
				l++; }
			if (input == UP && Snake.head_dir != DOWN && Snake.head_dir != UP ){
				Snake.head_dir = UP;
				Snake.bend_x [l] = Snake.head_x;
				Snake.bend_y [l] = Snake.head_y;
				Snake.bend_dir [l] = UP;
				l++;
			}
			if (input == DOWN && Snake.head_dir != UP && Snake.head_dir != DOWN ){
				Snake.head_dir = DOWN;
				Snake.bend_x [l] = Snake.head_x;
				Snake.bend_y [l] = Snake.head_y;
				Snake.bend_dir [l] = DOWN;
				l++;
			}}

		//Code to change the y direction at respective time
		if (Snake.tail_x == Snake.bend_x [m] && Snake.tail_y == Snake.bend_y [m] ){
			Snake.tail_dir = Snake.bend_dir [m];
			m++;
		}}}

void movesnake () //Moves The Snake Across the Screen
{
	int i;
	//Move the Head
	if(flag==0){
		if (Snake.head_dir == LEFT){
			Snake.head_x --; }
		if (Snake.head_dir == RIGHT) {
			Snake.head_x ++; }
		if (Snake.head_dir == UP) {
			Snake.head_y --;
		}
		if (Snake.head_dir == DOWN) {
			Snake.head_y ++; }
		putpixel (Snake.head_x, Snake.head_y,15);

		//Move the Tail
		putpixel (Snake.tail_x, Snake.tail_y,0);
		if (Snake.tail_dir == LEFT)
		{
			Snake.tail_x --;
		}
		if (Snake.tail_dir == RIGHT)
		{
			Snake.tail_x ++;
		}
		if (Snake.tail_dir == UP)
		{
			Snake.tail_y --;
		}
		if (Snake.tail_dir == DOWN)
		{
			Snake.tail_y ++;
		}}
}

void removesnake(){
	printf("\n%d,%d",Snake.head_x,Snake.head_y);
	printf("\n%d,%d",Snake.tail_x,Snake.tail_y);
	while(!((Snake.tail_x-Snake.head_x==0)&&(Snake.tail_y-Snake.head_y==0))){
		putpixel (Snake.tail_x, Snake.tail_y,0);
		setfillstyle (0,0);
		printf("  %d,%d",Snake.tail_x,Snake.tail_y);
		if (Snake.tail_dir == LEFT)
		{
			Snake.tail_x --;
		}
		if (Snake.tail_dir == RIGHT)
		{
			Snake.tail_x ++;
		}
		if (Snake.tail_dir == UP)
		{
			Snake.tail_y --;
		}
		if (Snake.tail_dir == DOWN)
		{
			Snake.tail_y ++;
		}
		putpixel (Snake.tail_x, Snake.tail_y,2);
		printf("  %d,%d",Snake.tail_x,Snake.tail_y);
		if(Snake.tail_x==Snake.bend_x[m] && Snake.tail_y==Snake.bend_y[m]){
			Snake.tail_dir = Snake.bend_dir[m];
			printf("UP hi \n");
			m++; }
	}  putpixel (Snake.tail_x, Snake.tail_y,0);
}

void gameengine ()//Soul of our game.
{long int i;
while (1)
{
	if(flag==0){
		movesnake ();}
	if(flag==1){

		delay(1000);
		setcolor (0);//Rewrite Score
		setfillstyle (0,0);
		bar (10,701,1007, 735);

		// initscreen();
		removesnake();
		initgamedata();
		initscreen();
		// printf("%d\n",);
		printf("INDRESH %d\n",flag);
		flag=0;
		l=0;
		m=0;
		initgamedata();
		initscreen();
		gamedelay--;
	}
	// printf("%d\n",flag);
	userinput ();
	//printf("%d\n",flag);
	gamephysics ();
	delay (gamedelay);
}
}

// Main Functionint

int main ()
{
	initwindow(1018,736,"Snake 1.0"); // Create the Snake Window with value is optimize for mode 1024 * 768
	initgamedata();
	initscreen();
	gameengine (); // Holds the window for a while
	closegraph (); // This close down the graphics
	getch();
	return 0;
}

