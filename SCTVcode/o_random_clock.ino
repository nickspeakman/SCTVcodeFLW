/// ------------ Random Clock ------------

char RandomStr[] = "random clock\n";      // clock
char RandomTimeStr[] [13] = {""};      // time string 
char RandomEndStr[] = "\n";

int ClockCount = 16;          // Total clocks minus Pong and Tetris
int ClockChosen = 99;
int ClockOld = 98;
int SecsNew = 99;
int HrsOld = 99;
int DisplayRand = 0;

char SecsNewStr[] = "99\n";  // temp variables to debug
char SecsStr[] = "55\n";
char HrsOldStr[] = "88\n";  // temp variables to debug
char HrStr[] = "44\n";

// random clock draw list
struct item randList[] = {
  {text,15,0,RandomStr,0,0},  // the clock
//  {text,10,0,SecsStr,0,0},  // debug
//  {text,10,0,SecsNewStr,0,0},  // debug
//  {text,10,0,HrStr,0,0},  // debug
//  {text,10,0,HrsOldStr,0,0},  // debug
  {listend,0,0,BlankLn,0,0}
};



void Randclk(void) {

  if (SecsNew == 99) SecsNew = Secs + 3;

  if (SecsNew > 59) SecsNew -= 59;  // knock it back if over 60
  
  if (Secs == SecsNew){     //display "random" for 2 seconds
    SecsNew = 99;           // don't repeat! 
    DisplayRand = 1;        // flag for showing the word random is nulled
    HrsOld = 99;

  }else if ((HrsOld != Hrs) && (DisplayRand == 1)){       //ticked over an hour
    ClockChosen = random(1,ClockCount);

    if ((ClockOld!=ClockChosen) && (ClockChosen != 1) && (ClockChosen != 2)){  // no two hours should be the same and shouldn't be Tetris or Pong
      theClock = ClockChosen;
      SecsNew = 99;     //reset
      DisplayRand = 0;  // remove text off screen
      HrsOld = Hrs;     // note this hour
      ClockOld = ClockChosen; //don't repeat
      RandClockRunning = 1;   //unless anything is touched by the user... keep randomising!
    }
  }

  SecsStr[0] = (Secs / 10) | '0';   // debug timing
  SecsStr[1] = (Secs % 10) | '0';
  SecsNewStr[0] = (SecsNew / 10) | '0';
  SecsNewStr[1] = (SecsNew % 10) | '0';
  HrStr[0] = (Hrs / 10) | '0';   // debug timing
  HrStr[1] = (Hrs % 10) | '0';
  HrsOldStr[0] = (HrsOld / 10) | '0';
  HrsOldStr[1] = (HrsOld % 10) | '0';


}
