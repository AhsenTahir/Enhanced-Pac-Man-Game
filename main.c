#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
void display_screen();
void moveG1down();
void moveG1up();
void moveG2down();
void moveG2up();
void moveG3right();
void moveG3left();
void moveG4left();
void moveG4right();
int lives=3;
int total_score=0;
int total_food=461;
int total_food_boss=372;
int pac_x,pac_y,g1x,g1y,g2x,g2y,g3x,g3y,g4x,g4y,en=1;
int g1X=3, g1Y=8, g2X=7, g2Y=56, g3X=16, g3Y=34,g4X=21,g4Y=39;
int flag1,flag2,flag3,flag4;
char fire_flag;
int bullet=1;
int boss_row = 7, boss_col = 12;
time_t lastfiretime;
time_t lastfiretime1;
time_t entimedecreaser;



	char maze[24][71]=
	{
    "#####################################################################",
    "||O...................................... ..P.............  ...... O||",
    "||.. %%%%%%%%%%%%%%%%        ...     %%%%%%%%%%%%%%  |%|..   %%%%   ||",
    "||..    G   |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||",
    "||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||",
    "||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%%%     ..   %%%%.  ||",
    "||..        |%|       . . |%|...    ............... |%| ..       .  ||",
    "||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| G.   %%%%.  ||",
    "||..               |%|.             |%|......       |%| ..    |%|.  ||",
    "||..     ......... |%|.        E    |%|......|%|        ..    |%|.  ||",
    "||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%| |%|.  ||",
    "||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|         .|%|.      ||",
    "||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||",
    "||..|%|            .           ...|%|               |%| ..|%|.      ||",
    "||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||",
    "||...............................................   |%| ..........  ||",
    "||   .............................G..............          .......  ||",
    "||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||",
    "||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.   E  ||",
    "||..|%|            .           ...|%|               |%| ..|%|.      ||",
    "||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||",
    "||.....................................G.........   | | ..........  ||",
    "||O .............................................          ....... O||",
    "#####################################################################"
																			};
char mazeboss[23][71]= {
	"#####################################################################",
    "##O................                                        ...... O##",
    "## .  ...   ..  ....................         ............         .##",
    "## .    ..         ...    ...........       ..    ..............   ##",
    "##..    ..    . . ...          ..   .    ..............            ##",
    "##..  ..           . . ...    ...............  ..       .         .##",
    "## .   ..   . . ...        .   .     ................              ##",
    "## .        |||||||||||||||||||||||||||||||||||||||||||..        . ##",
    "##..   .....||                                       || .........  ##",
    "## .  ..    ||     ||||||  ||||||  ||||||  ||||||    ||            ##",
    "## .     .  ||     ||  ||  ||  ||  ||      ||        || .. .....   ##",
    "##..     .. ||     ||||||  ||  ||  ||||||  ||||||    ||           .##",
    "##..        ||     ||  ||  ||  ||      ||      ||    || ......     ##",
    "## .     ...||     ||||||  ||||||  ||||||  ||||||    ||            ##",
    "## .........||                                       ||  ........  ##",
    "## ........ |||||||||||||||||||||||||||||||||||||||||||   .......  ##",
    "##..     ..      ......     ...                                    ##",
    "##..     ..           ...          ...         .........           ##",
    "##..            .           ...                ...                 ##",
    "##..         ...    .......  ....          .....                   ##",
    "##..............................................     ..........    ##",
    "##O ........                                               .......O##",
    "#####################################################################"
																		 };

void moveG1up() {
    if (maze[g1X - 2][g1Y] == ' ') { // checking if upper box is empty 
        maze[g1X][g1Y] = ' '; // setting current ghost position to space _
        maze[g1X - 2][g1Y] = 'G'; // moving ghost up 
        g1X-=2; // decrementing x coordinate of g1 i_e row
    }
    else if (maze[g1X - 2][g1Y] == '.') { // checking if upper box contain point 
        maze[g1X - 2][g1Y] = 'G'; // moving guost1 up 
        maze[g1X][g1Y] = '.'; // mark current position with a  point 
        g1X-=2; // decrementing x coordinate of g1 i_e row
    }
    
    
    else if (maze[g1X - 2][g1Y] == 'P') { // checking if upper box contains pacman 
        if (en > 0) { // checking energizera remaining or not 
            maze[g1X][g1Y] = ' '; // current position mark with space and pacman eats g1 
            en--; // decrementing an energizer
            g1X=3;
			 g1Y=8;
        } else {
            lives--; // if no energizer remaining pacman die i_e one live minus 
        }
    }
    else if(maze[g1X-1][g1Y]=='|' || maze[g1X-1][g1Y]=='#' || maze[g1X-1][g1Y]=='%') {
	flag1=0;
	moveG1down();
}

}

void moveG1down() {
if(maze[g1X+2][g1Y]==' ') { // checking if down box is empty 
    maze[g1X][g1Y] = ' '; // mark current position as empty space or point
    maze[g1X+2][g1Y]='G'; // moving g1 down 
    g1X+=2; // incrementing row i_e incerement g1 x coordinate
}

else if(maze[g1X+2][g1Y]=='.') { // checking above box contains point
    maze[g1X+2][g1Y]='G'; // moving g1 down
    maze[g1X][g1Y]='.'; // mark current position as space _
    g1X+=2; // incerement row i_e incerement g1 x coordinate
}


else if(maze[g1X+2][g1Y]=='P') { //checking above box have pacman
    if(en>0) { // checking if energizer remaining
    maze[g1X][g1Y]='.'; // mark current position as space _

    g1X=3;
	g1Y=8;
    en--; // decrementing an energizer
}
else 
lives--;  // if no energizer remaining lives minus pacman die
}
else if(maze[g1X+2][g1Y]=='|' || maze[g1X+2][g1Y]=='#' || maze[g1X+2][g1Y]=='%') {
	flag1=1;
	moveG1up();
}


}


void moveG2up() {
    if (maze[g2X - 1][g2Y] == ' ') { // checking if upper box is empty 
        maze[g2X][g2Y] = ' '; // setting current ghost position to space _
        maze[g2X - 1][g2Y] = 'G'; // moving ghost up 
        g2X--; // decrementing x coordinate of g2 i_e row
    }
    else if (maze[g2X - 1][g2Y] == '.') { // checking if upper box contain point 
        maze[g2X - 1][g2Y] = 'G'; // moving guost2 up 
        maze[g2X][g2Y] = '.'; // mark current position with a  point 
        g2X--; // decrementing x coordinate of g2 i_e row
    }
    else if (maze[g2X - 1][g2Y] == 'P') { // checking if upper box contains pacman 
        if (en > 0) { // checking energizera remaining or not 
            maze[g2X][g2Y] = '.'; // current position mark with space and pacman eats g2 
            
			g2X=7;
			g2Y=56;
            en--; // decrementing an energizer
        } else {
            lives--; // if no energizer remaining pacman die i_e one live minus 
        }
    }
    else if( maze[g2X - 1][g2Y] == '|' || maze[g2X - 1][g2Y] == '%' || maze[g2X - 1][g2Y] == '#' ) {
    	flag2=0;
    	moveG2down();
	}
}

void moveG2down() {
if(maze[g2X+1][g2Y]==' ') { // checking if down box is empty 
    maze[g2X][g2Y]=' '; // mark current position as empty space _
    maze[g2X+1][g2Y]='G'; // moving g2 down 
    g2X++; // incrementing row i_e incerement g2 x coordinate
}

else if(maze[g2X+1][g2Y]=='.') { // checking above box contains point 
    maze[g2X][g2Y]='.'; // mark current position as space _
    maze[g2X+1][g2Y]='G'; // moving g2 down
    g2X++; // incerement row i_e incerement g2 x coordinate
}

else if(maze[g2X+1][g2Y]=='P') { //checking above box have pacman
    if(en>0) { // checking if energizer remaining
    maze[g2X][g2Y]='.'; // mark current position as space _
    
    g2X=7;
	 g2Y=56;
    en--; // decrementing an energizer
}
else 
lives--; // if no energizer remaining lives minus pacman die
}
else if(maze[g2X+1][g2Y]=='|' || maze[g2X+1][g2Y]=='%' || maze[g2X+1][g2Y]=='#') {
	flag2=1;
	moveG2up();
}
}


void moveG3right() {
if(maze[g3X][g3Y+2]==' ') { // checking if right box is empty 
    maze[g3X][g3Y]=' '; // mark current position as empty space _
    maze[g3X][g3Y+2]='G'; // moving g3 right 
    g3Y+=2; // incrementing col i_e incrementing g3 y coordinate
}

else if(maze[g3X][g3Y+2]=='.') { // checking if right box contains point 
    maze[g3X][g3Y]='.'; // mark current position as space _
    maze[g3X][g3Y+2]='G'; // moving g3 right
    g3Y+=2; // incrementingg col i_e incrementing g3 y coordinate
}

else if(maze[g3X][g3Y+2]=='P') { //checking right box have pacman
    if(en>0) { // checking if energizer remaining
    maze[g3X][g3Y]='.'; // mark current position as space _
    
    g3X=16;g3Y=34;
    en--; // decrementing an energizer
}
else 
lives--; // if no energizer remaining lives minus pacman die
}
else if( maze[g3X][g3Y+2]=='|' || maze[g3X][g3Y+1]=='#' || maze[g3X][g3Y+1]=='%' ) {
	flag3=1;
	moveG3left();
}
}


void moveG3left() {
if(maze[g3X][g3Y-2]==' ') { // checking if left box is empty 
    maze[g3X][g3Y]=' '; // mark current position as empty space _
    maze[g3X][g3Y-2]='G'; // moving g3 left
    g3Y-=2; // decrementing col i_e decrementing g3 y coordinate
}

else if(maze[g3X][g3Y-2]=='.') { // checking left box contains point 
    maze[g3X][g3Y-2]='G'; // moving g3 left
    maze[g3X][g3Y]='.'; // mark current position as space _
    g3Y-=2; // decrementing row i_e decrementing g1 y coordinate
}

else if(maze[g3X][g3Y-2]=='P') { //checking left box have pacman
    if(en>0) { // checking if energizer remaining
    maze[g3X][g3Y]='.'; // mark current position as space _
    
    g3X=16;
	 g3Y=34;
    en--; // decrementing an energizer
}
else 
lives--; // if no energizer remaining lives minus pacman die
}
else if ( maze[g3X][g3Y-1]=='|' || maze[g3X][g3Y-1]=='#' || maze[g3X][g3Y-1]=='%' ) {
	flag3=0;
	moveG3right();
}
}


void moveG4right() {
if(maze[g4X][g4Y+1]==' ') { // checking if right box is empty 
    maze[g4X][g4Y]=' '; // mark current position as empty space _
    maze[g4X][g4Y+1]='G'; // moving g4 right 
    g4Y++; // incrementing col i_e incrementing g4 y coordinate
}

else if(maze[g4X][g4Y+1]=='.') { // checking if right box contains point 
    maze[g4X][g4Y]='.'; // mark current position as space _
    maze[g4X][g4Y+1]='G'; // moving g4 right
    g4Y++; // incrementingg col i_e incrementing g4 y coordinate
}

else if(maze[g4X][g4Y+1]=='P') { //checking right box have pacman
    if(en>0) { // checking if energizer remaining
    maze[g4X][g4Y]='.'; // mark current position as space _
    
    g4X=21;
	g4Y=39;
    en--; // decrementing an energizer
}
else 
lives--; // if no energizer remaining lives minus pacman die
}
else if ( maze[g4X][g4Y+1]=='%' || maze[g4X][g4Y+1]=='#' || maze[g4X][g4Y+1]=='|' ) {
	flag4=0;
	moveG4left();
}
}


void moveG4left() {
if(maze[g4X][g4Y-1]==' ') { // checking if left box is empty 
    maze[g4X][g4Y]=' '; // mark current position as empty space _
    maze[g4X][g4Y-1]='G'; // moving g4 left
    g4Y--; // decrementing col i_e decrementing g4 y coordinate
}

else if(maze[g4X][g4Y-1]=='.') { // checking left box contains point 
    maze[g4X][g4Y]='.'; // mark current position as space _
    maze[g4X][g4Y-1]='G'; // moving g4 left
    g4Y--; // decrementing row i_e decrementing g4 y coordinate
}

else if(maze[g4X][g4Y-1]=='P') { //checking left box have pacman
    if(en>0) { // checking if energizer remaining
    maze[g4X][g4Y]='.'; // mark current position as space _
    
    g4X=21;
	g4Y=39;
    en--; // decrementing an energizer
}
else 
lives--; // if no energizer remaining lives minus pacman die
}
else if ( maze[g4X][g4Y-1]=='%' || maze[g4X][g4Y-1]=='#' || maze[g4X][g4Y-1]=='|' ) {
	flag4=1;
	moveG4right();
}
}


void moveGhosts() {
 	if (flag1==1) moveG1up();
    if (flag1==0)moveG1down();
    
   if(flag2==1) moveG2up();
   if(flag2==0) moveG2down();
    
    if (flag3==0) moveG3right();
    if (flag3==1) moveG3left();
    
    if (flag4==1) moveG4right();
    if (flag4==0) moveG4left();
}




void pac_position(){
	
	int i,j;
	if (total_score<461)
	{
		for(i=0;i<24;i++){
		for (j=0;j<71;j++){
			if(maze[i][j]=='P'){
				pac_x=j;
				pac_y=i;
			}
		}
	  }
	}
	else 
	{
		for(i=0;i<23;i++){
		for (j=0;j<71;j++){
			if(mazeboss[i][j]=='P'){
				pac_x=j;
				pac_y=i;
			}
		}
	  }
	}
}


void pac_fire(){

	time_t currenttime;
    time(&currenttime);
	if (bullet == 0 && difftime(currenttime, lastfiretime) >= 3.0) { // Reset bullet and update the last firing time
        bullet = 1;
        lastfiretime = currenttime;
    }
    if(bullet==1) {
	switch(fire_flag){
		int i,j;
		case 'w':	for(i=pac_y-1;i>0;i--){//for upward fire

    					    char previous=maze[i-1][pac_x];//to keep the previous record at that place
    					    
							maze[i-1][pac_x]='*';
							
							display_screen();	//it will display the maze before and 
							system("cls");		//after change in loop that would appear as if the bullet is moving
							
							//in case of obstacle the bullet would stop
							if(	( maze[i-2][pac_x]=='%' || 	maze[i-2][pac_x]=='#' || 	maze[i-2][pac_x]=='|'||maze[i-2][pac_x]=='G' )){
								//when bullet hits ghost we get powerup
								if( maze[i-2][pac_x]=='G'){
								en++;
							}
							maze[i-1][pac_x]=previous;
							bullet=0;
							break;	
								}
							maze[i-1][pac_x]=previous;
								}
								bullet=0;
								break;
		
		case 'd':   	for(i=pac_x+1;i<71;i++){//for rightward fire

    					    char previous=maze[pac_y][i+1];//to keep the previous record at that place
							maze[pac_y][i+1]='*';
							
							display_screen();//it will display the maze before and
							system("cls");//after change in loop that would appear as if the bullet is moving
							
							//in case of any obstacle bullet will stop
							if(	( maze[pac_y][i+2]=='%' || 	maze[pac_y][i+2]=='#' || 	maze[pac_y][i+2]=='|'||maze[pac_y][i+2]=='G' )){
							
							if(maze[pac_y][i+2]=='G'){
								en++;//when we hit ghost ,we get powerup
							}
							maze[pac_y][i+1]=previous;
							bullet=0;
							break;	
								}
							maze[pac_y][i+1]=previous;//to restore previous element in that place
							bullet=0;
								}
								break;
			
		case 's':for(i=pac_y+1;i<24;i++){//for downward fire

    					    char previous=maze[i+1][pac_x];
							maze[i+1][pac_x]='*';
							display_screen();
							system("cls");
							if(	( maze[i+2][pac_x]=='%' || 	maze[i+2][pac_x]=='#' || 	maze[i+2][pac_x]=='|'||maze[i+2][pac_x]=='G' )){
							if(maze[i+2][pac_x]=='G'){
								en++;
							}
							
							maze[i+1][pac_x]=previous;
							bullet=0;
							break;	
								}
							maze[i+1][pac_x]=previous;
							bullet=0;
								}
								break;
						
		case 'a':for(i=pac_x-1;i>0;i--){//for leftward fire

    					    char previous=maze[pac_y][i-1];
							maze[pac_y][i-1]='*';
							display_screen();
							system("cls");
							if(	( maze[pac_y][i-2]=='%' || 	maze[pac_y][i-2]=='#' || 	maze[pac_y][i-2]=='|'||maze[pac_y][i-2]=='G' )){
							
							if(maze[pac_y][i-2]=='G'){
								en++;
							}
							
							maze[pac_y][i-1]=previous;
							bullet=0;
							break;	
								}
							maze[pac_y][i-1]=previous;
							bullet=0;
								}
								break;
		
		default:break;
				
	}
}

	
	
	
}






void total_score_count(){
	int i,j;
	int count=0;
	if (total_score< 461)
	{
		for(i=0;i<24;i++){
		for(j=0;j<71;j++){
			if(maze[i][j]=='.'){
				count++;				
			}			
		}
	  }
	  total_score=total_food-count;
	}
	
	else
	{
		for(i=0;i<23;i++){
		for(j=0;j<71;j++){
			if(mazeboss[i][j]=='.'){
				count++;				
			}			
		}
	 }
	 total_score=total_food_boss-count;
	}
	
//	total_score= 485;
	if ( total_score == 461)
	{
		lives+2;// emter in bossfight upgrade of two lives
	}
}
//bossfight functions
void movebossdown(int* row, int* col) {
    int i, j, check;
    for (check = *row + 9; check < 21; check++) {
        for (i = 8; i >= 0; i--) {
            for (j = 0; j < 43; j++) {
            	if (mazeboss[*row + 1 + i][*col + j] == 'P')
	            {
			        mazeboss[1][44]= 'P';//initial position of pacman
			        lives--;
	            }
                mazeboss[*row + 1 + i][*col + j] = mazeboss[*row + i][*col + j];
                mazeboss[*row + i][*col + j]= ' ';
            }
        }
        (*row)++;
        break;
    }
}

void movebossup(int* row, int* col) {
    int i, j, check;
    for (check = *row - 1; check > 1; check--) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 43; j++) {
            	if (mazeboss[*row + i - 1][*col + j] == 'P')
	            {
			        mazeboss[1][44]= 'P';//initial position of pacman
			        lives--;
	            }
                mazeboss[*row + i - 1][*col + j] = mazeboss[*row + i][*col + j];
                mazeboss[*row + i][*col + j]= ' ';
            }
        }
        (*row)--;
        break;
    }
}

void movebossright(int* row, int* col) {
    int i, j, check;
    for (check = *col + 44; check < 67; check++) {
        for (j = 43; j >= 0; j--) {
            for (i = 0; i < 9; i++) {
            if (mazeboss[*row + i][*col + j + 1] == 'P')
	            {
			        mazeboss[1][44]= 'P';//initial position of pacman
			        lives--;
	            }
                mazeboss[*row + i][*col + j + 1] = mazeboss[*row + i][*col + j];
                mazeboss[*row + i][*col + j]= ' ';
            }
        }
        (*col)++;
        break;
    }
}

void movebossleft(int* row, int* col) {
    int i, j, check;
    for (check = *col - 1; check > 2; check--) {
        for (j = 0; j < 43; j++) {
            for (i = 0; i < 9; i++) {
            	if (mazeboss[*row + i][*col + j - 1] == 'P')
	            {
			        mazeboss[1][44]= 'P';//initial position of pacman
			        lives--;
	            }
                mazeboss[*row + i][*col + j - 1] = mazeboss[*row + i][*col + j];
                mazeboss[*row + i][*col + j]= ' ';
            }
        }
        (*col)--;
        break;
    }
}
void moveboss(int* row, int* col) {
	time_t currenttime1;
	time(&currenttime1);
	if( difftime(currenttime1,lastfiretime1) >= 3.0) {
		lastfiretime1 = currenttime1;
    if (*row+9 < pac_y ) { //pac position is below the boss
        movebossdown(row, col);
    } else if (*row > pac_y) { //pac position is above the boss
        movebossup(row, col);
    } else if (*col + 43 < pac_x) { //pac position is right to the boss
        movebossright(row, col);
    } else if (*col > pac_x) { //pac position is left to the boss
        movebossleft(row, col);
    }
}
}

//boss fire function
void fireupdown(int* row, int* col)
{
	int i,j, k, count=0;
	for (i=0; i<10; i+9)
	{
		for (k = *row-1+i; k >= 0; 
		{
			if (i==0)//upward firing
			{
				for (j = 0; j < 43; j += 3)//column change by 3
				{
					if (mazeboss[k][*col+j] !='#')
					{
						if (mazeboss[k][*col+j]=='P')
						{
							lives--;
							mazeboss[1][44]='P';
						}
					mazeboss[k][*col+j]='*';// smae column and row is changing upwards and firing up wards 
					display_screen();
					system("cls");
				   }
				}
			}
			break; // only one time it runs
		}
		for (k = *row+i; k <= 23; k++)
		{
			 if(i==9)//downward firing
			{
				for (j = 0; j < 43; j += 3)//column change by 3
				{
					if (mazeboss[k][*col+j] !='#')
					{
						if (mazeboss[k][*col+j]=='P')
						{
							lives--;
							mazeboss[1][44]='P';
						}
					   mazeboss[k][*col+j]='*';// smae column and row is changing upwards and firing up wards 
					   display_screen();
					   system("cls");
				   }
				}
			}
			break; // only one time it runs
		}
		break; // only one time it runs
	}
}

void firerightleft(int* row, int* col)
{
	int i,j, k;
	for (i=0; i<45; i+43)
	{
		for (k = *col-1+i; k >= 0; k--)
		{
			if (i==0)//upward firing
			{
				for (j = 0; j < 9; j += 3)//column change by 3
				{
					if (mazeboss[*row+j][k]!='#')
					{
						if (mazeboss[*row+j][k]=='P')
						{
							lives--;
							mazeboss[1][44]='P';
						}
					 mazeboss[*row+j][k]='*';// smae column and row is changing upwards and firing up wards 
					 display_screen();
					 system("cls");
				   }
				}
				break; // only one time it runs
			}
		}
		for (k = *col+i; k <= 71; k++)
		{
			 if(i==43)//downward firing
			{
				for (j = 0; j < 9; j += 3)//column change by 3
				{
					if (mazeboss[*row+j][k]!='#')
					{
						if (mazeboss[*row+j][k]=='P')
						{
							lives--;
							mazeboss[1][44]='P';
						}
						mazeboss[*row+j][k]='*';// smae column and row is changing upwards and firing up wards 
					    display_screen();
					    system("cls");
					}
				}
			}
			break; // only one time it runs
		}
		break; // only one time it runs
	}
}

void fireup()
{
	int i,j,k;
	for (i=0; i<23; i++)
	{
		for (j=0; j<71; j++)
		{
			if (mazeboss[i][j]=='*' && i< boss_row  )// move * upwards
			{
				if (mazeboss[i][j]!='#')
				{
					if(mazeboss[i][j]=='P')
					{
						mazeboss[1][44]='P';
						lives--;
					}
					else 
					  for( k=i;k<1; k--)
					  {
					  	mazeboss[k][j]='*';
					  	mazeboss[i][j]=' ';
					  	break;// only one time it moves up
					   } 
				}
			}
			else if (mazeboss[i][j]=='*' && i> boss_row+9 )//move * downward
			{
				if (mazeboss[i][j]!='#')
				{
					if(mazeboss[i][j]=='P')
					{
						mazeboss[1][44]='P';
						lives--;
					}
					else 
					  for( k=i;k<22; k++)
					  {
					  	mazeboss[k][j]='*';
					  	mazeboss[i][j]=' ';
					  	break;
					   } 
				}
			}
		}
	}
}

void fireleft()
{
	int i,j,k;
	for (i=0; i<23; i++)
	{
		for (j=0; j<71; j++)
		{
			if (mazeboss[i][j]=='*' && j< boss_col  )// move * upwards
			{
				if (mazeboss[i][j]!='#')
				{
					if(mazeboss[i][j]=='P')
					{
						mazeboss[1][44]='P';
						lives--;
					}
					else 
					  for( k=j;k<1; k--)
					  {
					  	mazeboss[i][k]='*';
					  	mazeboss[i][j]=' ';
					  	break;
					   } 
				}
			}
			else if (mazeboss[i][j]=='*' && j> boss_col+43 )//move * downward
			{
				if (mazeboss[i][j]!='#')
				{
					if(mazeboss[i][j]=='P')
					{
						mazeboss[1][44]='P';
						lives--;
					}
					else 
					  for( k=i;k<70; k++)
					  {
					  	mazeboss[k][j]='*';
					  	mazeboss[i][j]=' ';
					  	break;
					   } 
				}
			}
		}
	}
}
void bossfire(int* row, int* col, int* turn) {
	if (*turn>0)
	{
		fireup();
		fireleft();
	}
        fireupdown(row, col);
        firerightleft(row, col);
    *turn=  *turn+1;
        
}
void move(int  X,  int Y)
{
	int x= pac_x + X;
	int y= pac_y + Y;
	if ( total_score<461)
	{
		
	    if (maze[y][x]!= '#' || maze[y][x]!= '%' || maze[y][x]!= 'G' || maze[y][x]!= '|' )
	    {
	    	if (maze[y][x] == 'E') {
                maze[y][x] = ' '; 
                en++;  // Increment energizer count
            }
		    if(maze[y][x] == '.')
		    {
			    maze[y][x]= ' ';// food was eaten by pacman
			    maze[pac_y][pac_x]=' ';// prevous position of pacman becomes empty
			    maze[y][x]= 'P';// new position of pacman
			   // total_score+2; // score addition
		    }
		    else if (maze[y][x] == ' ')
		    {  	
			    maze[pac_y][pac_x]=' ';// prevous position of pacman becomes empty
			    maze[y][x]= 'P';// new position of pacman
		    }
	    }
	//if (maze[y][x]!= '#' || maze[y][x]!= '%' || maze[y][x]!= '|') pacman will not move it will be on its previous position
	    else if (maze[y][x] == 'G')
	    {
		    if (en>0)
		    {
			    //Ghost call
			    maze[y][x]= 'P';// new position of pacman
//			     g1X=3, g1Y=8;
			    en--;
		    }
		    else if (en<0)
		    {    maze[pac_y][pac_x]='G';
			    maze[1][44]= 'P';//initial position of pacman
			    lives--;
		    }
	    }
    }
    else if ( total_score>=461)
	{
		
	    if (mazeboss[y][x]!= '#' && mazeboss[y][x] != '|')
	    {
		    if(mazeboss[y][x] == '.')
		    {
			    mazeboss[y][x]= ' ';// food was eaten by pacman
			    mazeboss[pac_y][pac_x]=' ';// prevous position of pacman becomes empty
			    mazeboss[y][x]= 'P';// new position of pacman
			    //total_score+2; // score addition
		    }
		    else if (mazeboss[y][x] == ' ')
		    {  	
			    mazeboss[pac_y][pac_x]=' ';// prevous position of pacman becomes empty
			    mazeboss[y][x]= 'P';// new position of pacman
		    }
	    }
	//if (maze[y][x]!= '#' ) pacman will not move it will be on its previous position
	    else if (mazeboss[y][x] == '|')
	    {
			mazeboss[1][44]= 'P';//initial position of pacman
			lives--;
	    }
    }
    return;
}



	void display_screen(){		
		int i,j;
		if ( total_score<461)
		{
			for(i=0;i<24;i++){			//this loop will display maze 
			    for(j=0;j<71;j++){
				     printf("%c",maze[i][j]);
			    }
			    printf("\n");
		     }
		}
		else if (total_score>= 461)
		{
			for(i=0;i<23;i++){			//this loop will display maze 
			    for(j=0;j<71;j++){
				    printf("%c",mazeboss[i][j]);
			   }
			    printf("\n");
		    }
		}
		
		return;				
	}


int main(){
	
	int freeze, turn=0;
	char exit='c';
	char input_key;
	
	printf("INSTRUCTION\n");
    printf("press 'w'for up\n");
     printf("press 's'for down\n");
      printf("press 'd'for right\n");
       printf("press 'a'for left\n");
while(1){
	
	printf("YOUR SCORE:%d",total_score);
	printf("\t\tYOUR ENERGIZER:%d",en);
	printf("\t\t\tYOUR LIVES:%d",lives);
	printf("\t\t\t\tYOU GET 1 BULLET AFTER EVERY 3s");
	printf("\nENTER 'e' TO EXIT THE GAME\n");
	display_screen();
    input_key=getch();		//this will continuously take our single input character
	system("cls"); 	     //this will clear the screen after every itteration
	
	pac_position();
	printf("\nYOUR LOCATION: \nx axis:%d y axis:%d\n",pac_x,pac_y);
		
	switch(input_key){
		case 'w': move(0,-1);    //for moving up
		break;
		case 'd': move(1,0); 	//for moving right
		break;
		case 'a': move(-1,0);	 //for moving left
		break;
		case 's': move(0,1); 	//for moving down
		break;
		case 'z': pac_fire(); 	//for firing by pacman
		break;		
		case 'e':	exit='e';   
		break;
					
		}
		fire_flag=input_key;//so that pacman will fire in the direction of its movement
		
		if(total_score<461 )
		{
			moveGhosts();
		}
		
		else if( total_score >= 461)
		{
			freeze=0;// check point this code run once
			if (total_score== 485 && freeze==0)
			{
				bossfire(&boss_row, &boss_col, &turn);
				freeze=1;
			}
			else
			{
				moveboss(&boss_row, &boss_col);
			}
		}
        if(lives<=0) {
        printf("\tyour total score is :%d\n\n\t WELL PLAYED!!!",total_score);  //end output to be displayed
		break;  //it will exit from the while loop
        }
		total_score_count();
        
		if(exit=='e'){
			printf("\tyour total score is :%d\n\n\t WELL PLAYED!!!",total_score);  //end output to be displayed
			break;  //it will exit from the while loop
		}
		time_t current_time2;
		time(&current_time2);
		
        
		if(difftime(current_time2,entimedecreaser)>=10.0) {
			en--;
			entimedecreaser = current_time2;
		}
	}
	
	return 0;
}