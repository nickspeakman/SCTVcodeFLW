// ------------------- dot analogue cube clock -------------------

float dotxvel = 0;
float dotyvel = 0;
float dotangle = 0;
int dothr = 0;

// dot clock draw list
struct item dotList[]  = {
  {text,35,0,BlankLn, 0,0}, 
  {text,7,0,WDayStr, 0,0},   // day of week
  {text,7,0,MonthStr,0,0},   // month
  {text,7,0,SpaStr,  0,0},   
  {text,7,0,DayStr,  0,0},   // day
  {listend,0,0,BlankLn, 0,0}
};

void Dot(void) {

  //draw 4 rectangles
  drawALine (40 ,1500 , 40 , 1200); //12 o'clock
  drawALine (40 ,1200 , -40 , 1200); 
  drawALine (-40 ,1200 , -40 , 1500); 
  drawALine (-40 ,1500 , 40 , 1500); 
  
  drawALine (40 ,-1500 , 40 , -1200); //6 o'clock
  drawALine (40 ,-1200 , -40 , -1200); 
  drawALine (-40 ,-1200 , -40 , -1500); 
  drawALine (-40 ,-1500 , 40 , -1500); 
  
  drawALine (-1500 ,40 ,-1200 , 40); //9 o'clock
  drawALine (-1200 ,40 ,-1200 , -40); 
  drawALine (-1200 ,-40 ,-1500 , -40); 
  drawALine (-1500 ,-40 ,-1500 , 40); 

  drawALine (1500 ,40 ,1200 , 40); //3 o'clock
  drawALine (1200 ,40 ,1200 , -40); 
  drawALine (1200 ,-40 ,1500 , -40); 
  drawALine (1500 ,-40 ,1500 , 40); 

  //draw circles

  for (int dothr = 1; dothr < 12; dothr++) {
    if ((dothr != 3) && (dothr != 6) && (dothr != 9)){ // miss out quarters
      dotangle = (dothr * 0.523598); // convert to radians
      dotxvel = (sin (dotangle) * 1360);
      dotyvel = (cos (dotangle) * 1360);
      drawACircle(dotxvel, dotyvel, 125);
    }  
  }

  for (int dothr = 1; dothr < 60; dothr++) {
    if (dothr % 5) { // miss out 5s
      dotangle = (dothr * 0.10472); // convert to radians
      dotxvel = (sin (dotangle) * 1360);
      dotyvel = (cos (dotangle) * 1360);
      drawACircle(dotxvel, dotyvel, 25);
    }  
  }

  drawACircle(0, 0, 180);  

  dotangle = (Secs * 0.10472);
  dotxvel = (sin (dotangle) * 1200);
  dotyvel = (cos (dotangle) * 1200);
  drawACircle(dotxvel, dotyvel, 125);
  drawACircle(dotxvel, dotyvel, 100);
  drawACircle(dotxvel, dotyvel, 75);
  drawACircle(dotxvel, dotyvel, 50);
  drawACircle(dotxvel, dotyvel, 25);
  
  
  drawACircle(0, 0, 180);  

  DoHand(2250, (Secs * 4));
  DoHand(2300, (Secs / 15) + (Mins << 2));
  DoHand(2300, (Secs / 15) + (Mins << 2));   // make the hour and minute hands bright by doubling up
  DoHand(1800, (Hrs % 12) * 20 + Mins / 3);
  DoHand(1800, (Hrs % 12) * 20 + Mins / 3);

}