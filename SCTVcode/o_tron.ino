/// ------------ Tron Clock ------------

char TronStr[] = "          12:34:56 Wednesday 12 Nov 2024.         \n";      // clock
char TronTimeStr[] [36] = {""};      // time string 
char TronEndStr[] = "\n";

int startpoint = -250;

float LineA1 = startpoint-50;// -300
float LineA2 = startpoint-250;//-500
float LineA3 = startpoint-550;//-800
float LineA4 = startpoint-1150;//-1300

int TextPtSize = 2;
float TextPtInt = 2;
float TextPtInc = 1;
int OldSecs = 61;

// tron clock draw list
struct item tronList[] = {
  {text,15,0,TronStr,0,0},  // the clock
  {listend,0,0,BlankLn,0,0}
};



void Tron(void) {

//trigger start
if (Secs != OldSecs){
 if ((Secs != 55) && (Secs != 57) && (Secs != 59)){ // half speed for date and year
    OldSecs = Secs;
    TextPtInt = 2;
    TextPtSize = 2;
}
}
  strcpy(TronStr, TronTimeStr[0]);//blank it
  if ((Secs == 54) || (Secs == 55)){
  TextPtInc = 0.5;// half speed for date and year
  strcat(TronStr, WDayStr);
  strcat(TronStr, TronEndStr);
  
  } else if ((Secs == 56) || (Secs == 57)){
  TextPtInc = 0.5;// half speed for date and year
  strcat(TronStr, MonthStr);
  strcat(TronStr, SpaStr);
  strcat(TronStr, DayStr);
  strcat(TronStr, TronEndStr);
  
  } else if ((Secs == 58) || (Secs ==59)){
  TextPtInc = 0.5;// half speed for date and year
  strcat(TronStr, CenStr);
  strcat(TronStr, YrsStr);
  strcat(TronStr, TronEndStr);
  } else {
  
  TextPtInc = 1;
  strcat(TronStr, HrsStr);
  strcat(TronStr, ColStr);
  strcat(TronStr, MinStr);
  strcat(TronStr, ColStr);
  strcat(TronStr, SecStr);
  strcat(TronStr, TronEndStr);
  }

  TextPtInt = TextPtInt + TextPtInc ;
  int TextPtSize = TextPtInt;
  if (TextPtSize > 38){
    TextPtInt = 2;
  }
  tronList[0] = {text,TextPtSize,0,TronStr,0,0}; 

  drawALine (-100 , startpoint , -500 , -1700); //vertical lines underneath (X1, Y1, X2, Y2)
  drawALine (100 , startpoint , 500 , -1700); 
  drawALine (-300 , startpoint , -1050 , -1100); 
  drawALine (300 , startpoint , 1050 , -1100); 
  drawALine (-550 , startpoint , -1500 , -700); 
  drawALine (550 , startpoint , 1500 , -700); 
  drawALine (-850 , startpoint , -1700 , -450); 
  drawALine (850 , startpoint , 1700 , -450); 


  drawALine (-1500 , startpoint , 1500 , startpoint); // horizontal below
  drawALine ((-1750 - (LineA1 / 1.75)) , LineA1 , (1750 + (LineA1 / 1.75)) , LineA1);// narrow the lines as the go down
  drawALine ((-1750 - (LineA2 / 1.75)) , LineA2 , (1750 + (LineA2 / 1.75)) , LineA2);
  drawALine ((-1750 - (LineA3 / 1.75)) , LineA3 , (1750 + (LineA3 / 1.75)) , LineA3);
  drawALine ((-1750 - (LineA4 / 1.75)) , LineA4 , (1750 + (LineA4 / 1.75)) , LineA4);


  LineA1 = LineA1 - ((abs(LineA1)-100) / 30);
  if (LineA1 < -1700){
  LineA1 = startpoint;
  }
  LineA2 = LineA2 - ((abs(LineA2)-100) / 30);
  if (LineA2 < -1700){
  LineA2 = startpoint;
  }
  LineA3 = LineA3 - ((abs(LineA3)-100) / 30);
  if (LineA3 < -1700){
  LineA3 = startpoint;
  }
  LineA4 = LineA4 - ((abs(LineA4)-100) / 30);
  if (LineA4 < -1700){
  LineA4 = startpoint;
  }


}