// ------------------------- Four letter words -----------------------------

char WordclockStr1[] = "It is\n";      // 1st line
char WordclockStr2[] = "just gone\n";      // 2nd line
char WordclockStr3[] = "twenty five past\n";      // 3rd line
char WordclockStr4[] = "twenty five past\n";      // 4th line
char WordclockEndStr[] = "\n";

int Startpointer = 1;
int Prefpointer = 1;
int Minspointer = 1;
int Hrspointer = 1;

const char WCStart[3] [8]  = {"It is\n","It has\n",""};
const char WCPreface[4] [11]  = {"just gone\n","nearly\n","exactly\n","It is\n"};
const char WCMins[12] [20]  = {"five past\n","ten past\n","quarter past\n","twenty past\n","twenty five past\n","half past\n","twenty five to\n","twenty to\n","quarter to\n","ten to\n","five to\n","o'clock\n"};
const char WCHours[13] [8]  = {"twelve\n","one\n","two\n","three\n","four\n","five\n","six\n","seven\n","eight\n","nine\n","ten\n","eleven\n","twelve\n"};


// Text draw list
struct item wordlclockList[] = {
 
  {text,17,0,WordclockStr1,0,0},  
  {text,17,0,WordclockStr2,0,0},  
  {text,17,0,WordclockStr3,0,0},  
  {text,17,0,WordclockStr4,0,0},  
  {listend,0,0,BlankLn,0,0}};

void Wordclock(void) {
  
  // do the words
  Hrspointer = Hrs;   // "Zero\n" is effectifly a null placeholder

  if (Hrspointer>11) {
    Hrspointer = Hrspointer-12; // 24 hour clock fix
  }
  
  if (Mins>33){
    Hrspointer++;     // Add an hour if 33 mins or later.
  }
 

  if  (Mins==1 || Mins==6 || Mins==11 || Mins==16 || Mins==21 || Mins==26 || Mins==31 || Mins==36 || Mins==41 || Mins==46 || Mins==51 || Mins==56){ 
    Startpointer = 2; // null
    Prefpointer = 3; // It is
  }
  else {
    if (Mins==2 || Mins==7 || Mins==12 || Mins==17 || Mins==22 || Mins==27 || Mins==32 || Mins==37 || Mins==42 || Mins==47 || Mins==52 || Mins==57){  
    Startpointer = 1; // It has
    Prefpointer = 0; // just gone
  }
  else {
    if (Mins==3 || Mins==8 || Mins==13 || Mins==18 || Mins==23 || Mins==28 || Mins==33 || Mins==38 || Mins==43 || Mins==48 || Mins==53 || Mins==58){  
    Startpointer = 0; // It is
    Prefpointer = 1; // nearly
  }
  else {
    if (Mins==4 || Mins==9 || Mins==14 || Mins==19 || Mins==24 || Mins==29 || Mins==34 || Mins==39 || Mins==44 || Mins==49 || Mins==54 || Mins==59){  
    Startpointer = 2; // null
    Prefpointer = 3; // It is
  }
  else{
    Startpointer = 0; // It is
    Prefpointer = 2; // exactly
  }
  }
  }
  }

 
 if (Mins==58 || Mins==59 || Mins==0 || Mins==1 || Mins==2){ 
    Minspointer = 11; // o'clock
  }
else{
 if (Mins==3 || Mins==4 || Mins==5 || Mins==6 || Mins==7){ 
    Minspointer = 0; // five past
  }
else{
 if (Mins==8 || Mins==9 || Mins==10 || Mins==11 || Mins==12){ 
    Minspointer = 1; // ten past
  }
else{
 if (Mins==13 || Mins==14 || Mins==15 || Mins==16 || Mins==17){ 
    Minspointer = 2; // quarter past
  }
else{
 if (Mins==18 || Mins==19 || Mins==20 || Mins==21 || Mins==22){ 
    Minspointer = 3; // twenty past
  }
else{
 if (Mins==23 || Mins==24 || Mins==25 || Mins==26 || Mins==27){ 
    Minspointer = 4; // twenty five past
  }
else{
 if (Mins==28 || Mins==29 || Mins==30 || Mins==31 || Mins==32){ 
    Minspointer = 5; // half past
  }
else{
 if (Mins==33 || Mins==34 || Mins==35 || Mins==36 || Mins==37){ 
    Minspointer = 6; // twenty five to 
  }
else{
 if (Mins==38 || Mins==39 || Mins==40 || Mins==41 || Mins==42){ 
    Minspointer = 7; // twenty to
  }
else{
 if (Mins==43 || Mins==44 || Mins==45 || Mins==46 || Mins==47){ 
    Minspointer = 8; // quarter to
  }
else{
 if (Mins==48 || Mins==49 || Mins==50 || Mins==51 || Mins==52){ 
    Minspointer = 9; // ten to
  }
else{
 if (Mins==53 || Mins==54 || Mins==55 || Mins==56 || Mins==57){ 
    Minspointer = 10; // five to
  }
} } } } } } } } } } }

 if (Mins==58 || Mins==59 || Mins==0 || Mins==1 || Mins==2){ // swap last two lines
  strcpy(WordclockStr1, WCStart[Startpointer]);
  strcpy(WordclockStr2, WCPreface[Prefpointer]);
  strcpy(WordclockStr3, WCHours[Hrspointer]);
  strcpy(WordclockStr4, WCMins[Minspointer]);
  
  }
  else{ 
  strcpy(WordclockStr1, WCStart[Startpointer]);
  strcpy(WordclockStr2, WCPreface[Prefpointer]);
  strcpy(WordclockStr3, WCMins[Minspointer]);
  strcpy(WordclockStr4, WCHours[Hrspointer]);
  
  }
}