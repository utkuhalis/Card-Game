#include <graphics.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>

int card1; //Create card 1
int card2; //Create card 2
int card3; //Create card 3
int card4; //Create card 4

int cardType1; //Create card Type 1
int cardType2; //Create card Type 2
int cardType3; //Create card Type 3
int cardType4; //Create card Type 4

bool cardS1 = false; //Set Card 1 close
bool cardS2 = false; //Set Card 2 close
bool cardS3 = false; //Set Card 3 close
bool cardS4 = false; //Set Card 4 close

int round = 1; //set Round

int Player = 0; // Player Score
int Ai = 0; // AI Score

void my_sleep(unsigned msec) {
    struct timespec req, rem;
    int err;
    req.tv_sec = msec / 1000;
    req.tv_nsec = (msec % 1000) * 1000000;
    while ((req.tv_sec != 0) || (req.tv_nsec != 0)) {
        if (nanosleep(&req, &rem) == 0)
            break;
        err = errno;
        // Interrupted; continue
        if (err == EINTR) {
            req.tv_sec = rem.tv_sec;
            req.tv_nsec = rem.tv_nsec;
        }
        // Unhandleable error (EFAULT (bad pointer), EINVAL (bad timeval in tv_nsec), or ENOSYS (function not supported))
        break;
    }
}

void setScore(int player, int cardType, int score){
	if (player == 0){
		if (cardType == 1){
			Player+=score;
		}else if (cardType == 2){
			Player-=score;
		}else if (cardType == 3){
			Player+=score*3;
		}else if (cardType == 4){
			Player=0;
		}
	}else{
		if (cardType == 1){
			Ai+=score;
		}else if (cardType == 2){
			Ai-=score;
		}else if (cardType == 3){
			Ai+=score*3;
		}else if (cardType == 4){
			Ai=0;
		}
	}
}

void drawMenu(){
   outtextxy(10,10,"Card Game With AI");
   outtextxy(10,25,"Press Number For Choose Card");	
}

void drawCards(){	
   if (cardS1 == true){
   	char text[20] = "";
	sprintf(text, "%d", card1);
	outtextxy(70,190,text);
	
	char cardType[20] = "";
	sprintf(cardType, "cards/cardType%d.jpg", cardType1);
	readimagefile(cardType,20,100,150,300);
	
   }else{
   	readimagefile("cards/card.jpg",20,100,150,300);
   }
   
   if (cardS2 == true){
   	char text[20] = "";
	sprintf(text, "%d", card2);
	outtextxy(220,190,text);
	char cardType[20] = "";
	sprintf(cardType, "cards/cardType%d.jpg", cardType2);
	readimagefile(cardType,160,100,300,300);
   }else{
   	readimagefile("cards/card.jpg",160,100,300,300);
   }
   
   if (cardS3 == true){
   	char text[20] = "";
	sprintf(text, "%d", card3);
	outtextxy(370,190,text);
	char cardType[20] = "";
	sprintf(cardType, "cards/cardType%d.jpg", cardType3);
	readimagefile(cardType,310,100,450,300);
   }else{
   	readimagefile("cards/card.jpg",310,100,450,300);
   }
   
   if (cardS4 == true){
   	char text[20] = "";
	sprintf(text, "%d", card4);
	outtextxy(520,190,text);
	char cardType[20] = "";
	sprintf(cardType, "cards/cardType%d.jpg", cardType4);
	readimagefile(cardType,460,100,600,300);
   }else{
   	readimagefile("cards/card.jpg",460,100,600,300);
   }
}

void runWinAnim(){
	while(1){
		readimagefile("win/coinAnim1.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("win/coinAnim2.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("win/coinAnim3.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("win/coinAnim4.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("win/coinAnim5.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("win/coinAnim6.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("win/coinAnim7.bmp",550,10,600,70);
	   	my_sleep(100);
	}
}

void runLoseAnim(){
	while(1){
		readimagefile("lose/coinAnim1.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("lose/coinAnim2.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("lose/coinAnim3.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("lose/coinAnim4.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("lose/coinAnim5.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("lose/coinAnim6.bmp",550,10,600,70);
	   	my_sleep(100);
	   	readimagefile("lose/coinAnim7.bmp",550,10,600,70);
	   	my_sleep(100);
	}
}

void playAI(){
	bool wait = true;
	
	while (wait){
		int selectedCard = rand();
		
		if (selectedCard == 1 && cardS1 == false){
          cardS1 = true; //open Card 1
	      round++; //up round
	      setScore(1, cardType1, card1); //set AI Score
	      wait = false;
		}else if (selectedCard == 2 && cardS2 == false){
          cardS2 = true; //open Card 1
	      round++; //up round
	      setScore(1, cardType2, card2); //set AI Score
	      wait = false;
		}else if (selectedCard == 3 && cardS3 == false){
          cardS3 = true; //open Card 1
	      round++; //up round
	      setScore(1, cardType3, card3); //set AI Score
	      wait = false;
		}else if (selectedCard == 4 && cardS4 == false){
          cardS4 = true; //open Card 1
	      round++; //up round
	      setScore(1, cardType4, card4); //set AI Score
	      wait = false;
		}
	}
	
	drawCards(); //draw cards

}

void drawScores(){
	char PlayerScore[20] = "";
	sprintf(PlayerScore, "Player Score %d", Player);
	outtextxy(10,370,PlayerScore);
	char AiScore[20] = "";
	sprintf(AiScore, "Ai Score %d", Ai);
	outtextxy(10,390,AiScore);
}

int main()
{	
   int gd = DETECT, gm;
   srand(time(NULL));
   card1 = rand() % 100; //Set card1 value
   card2 = rand() % 100; //Set card2 value
   card3 = rand() % 100; //Set card3 value
   card4 = rand() % 100; //Set card4 value
   
   cardType1 = card1 = rand() % 4 + 1; //Set card1 type
   cardType2 = card1 = rand() % 4 + 1; //Set card2 type
   cardType3 = card1 = rand() % 4 + 1; //Set card3 type
   cardType4 = card1 = rand() % 4 + 1; //Set card4 type
   initwindow(620, 480, "Card game with Ai in C");

   settextstyle(DEFAULT_FONT, HORIZ_DIR, 2); //set Font Directoin and Font Size for text style
   
   drawMenu(); //run drawMenu void for draw Texts
   drawCards(); //run drawCards void for draw Cards
   
   while(round != 5){ //start loop for rounds	
   	char key = getch(); //key pressed key
   	
   	if (key != 49 && key != 50 && key != 51 && key != 52){ //check selected  card
   	   cleardevice(); //clear screen
	   drawMenu(); //run drawMenu void for draw Texts
	   drawCards(); //draw cards
	   outtextxy(10,350,"Please use 1-2-3-4 Keys."); //print if not choose card
   	}else{ //else
   	   cleardevice(); //clear screen
	   drawMenu(); //run drawMenu void for draw Texts
	   if (key == 49 && cardS1 == false){
	      cardS1 = true; //open Card 1
	      setScore(0, cardType1, card1); //Set player score
	      round++; //up round
	      playAI();
	   }else if (key == 50 && cardS2 == false){
	      cardS2 = true; //open Card 2
	      setScore(0, cardType2, card2); //Set player score
	      round++; //up round
	      playAI();
	   }else if (key == 51 && cardS3 == false){
	      cardS3 = true; //open Card 3
	      setScore(0, cardType3, card3); //Set player score
	      round++; //up round
	      playAI();
	   }else if (key == 52 && cardS4 == false){
	      cardS4 = true; //open Card 4
	      setScore(0, cardType4, card4); //Set player score
	      round++; //up round
	      playAI();
	   }else{
	      outtextxy(10,350,"This card already opened please try another.");
	   }
	   drawCards(); //run drawCards void for draw Cards
	   drawScores(); //run drawScores void for draw Scores
   	}
   }
   
   cleardevice(); //clear screen
   drawMenu(); //run drawMenu void for draw Texts
   drawCards(); //run drawCards void for draw Cards
   drawScores(); //run drawScores void for draw Scores
   if (Ai > Player){
   	setcolor(4);
   	outtextxy(10,350,"Ai Win.");
   	runLoseAnim(); //run coin animation
   }else if(Player > Ai){
   	setcolor(2);
   	outtextxy(10,350,"Player Win.");
   	runWinAnim(); //run coin animation
   }else{
   	outtextxy(10,350,"No one Win.");
   }
   
   getch(); //wait last key press
   closegraph(); //exit
   return 0;
}
