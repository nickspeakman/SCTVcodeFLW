// ------------------------- Four letter words -----------------------------

char FlwStr[] = "word\n";      // four letters plus a NL and a 0
int fptr = 0;                 // index into that list
char TimeStr[] [6] = {""};      // time string 
char flwEndStr[] = "\n";


// A whole bunch of four letter words, no juicy ones. 
const char FLWs[] [6]  = 
 {"Shit\n","Cunt\n","Wank\n","Twat\n","Tits\n","Cums\n","Fuck\n","Arse\n","Feck\n","Puff\n",
 "Piss\n","Flap\n","Knob\n","Cock\n","Jizz\n","Ball\n","Clit\n","Boob\n","Frig\n","Wang\n",
 "Crap\n","Muff\n","Butt\n","Quim\n","Nads\n","Pube\n","Dick\n","Jerk\n","Smeg\n","Ring\n",
 "Toss\n","Gash\n","Anus\n","Bush\n"};

int FLWLen = 34;
const int FLWFrames = 300;  // how many frames to show each Word for 


// Four letter word draw list
struct item flwList[] = {
  {text,45,0,FlwStr,0,0},  // the nasty word itself
  {listend,0,0,BlankLn,0,0}
};

void MakeFLW(void) 
{
  if (Secs > 15) {
    fptr = random(FLWLen);
    strcpy(FlwStr, FLWs[fptr]);
    }
  else{
    strcpy(FlwStr, TimeStr[0]);//blank it
    strcpy(FlwStr, HrsStr);
    strcat(FlwStr, ColStr);
    strcat(FlwStr, MinStr);
    strcat(FlwStr, flwEndStr);
  }
}