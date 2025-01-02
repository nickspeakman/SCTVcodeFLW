// ------------------- rotating cube clock -------------------


char CubeStr[] = "Wednesday\n";      // clock
char CubeTimeStr[] [11] = {""};      // time string 
char CubeEndStr[] = "\n";
float CubePointr = 0;
float CubePointx = 0;
float CubePointy = 0;
int CubeSizez = 800;
int CubeSizey = -400;
float CubeOffset = 0;


// cube clock draw list
struct item cubeList[] = {
  {text,20,0,CubeStr,0,0},  // the clock
  {listend,0,0,BlankLn,0,0}
};


void Cube(void) {

  strcpy(CubeStr, CubeTimeStr[0]);//blank it
  
  if ((Secs == 44) || (Secs == 33)){
  strcat(CubeStr, WDayStr);
  } else if ((Secs == 45) || (Secs == 34)){
  strcat(CubeStr, MonthStr);
  strcat(CubeStr, SpaStr);
  strcat(CubeStr, DayStr);  
  } else if ((Secs == 46) || (Secs ==35)){
  strcat(CubeStr, CenStr);
  strcat(CubeStr, YrsStr);
  } else {
  strcpy(CubeStr, HrsStr);
  strcat(CubeStr, ColStr);
  strcat(CubeStr, MinStr);
 }
  
 strcat(CubeStr, CubeEndStr);
 
  if ((Mins == 0) || (Mins == 30)){
    CubeOffset = CubeOffset + 0.1; //Fast and smooth
    
    if (CubeOffset > 314.1){ //Reset loop
    CubeOffset = 0;}}
  
   else if ((Mins == 10) || (Mins == 20) || (Mins == 40) || (Mins == 50)){
    CubeOffset = CubeOffset + 0.02; //Slow and smooth
    
    if (CubeOffset > 31.4){ //Reset loop
    CubeOffset = 0;}}
  
   else{
    CubeOffset = Secs / 9.5493; // Jerky
  }

  CubePointx = cos(CubeOffset) * 1000;
  CubePointy = (sin(CubeOffset) * 1000) - 500;
  CubePointr = cos(CubeOffset+CubeOffset) * 100 ;

  drawALine ( CubePointx , CubePointy-CubePointr+CubeSizey , -CubePointy ,  CubePointx-CubePointr+CubeSizey);
  drawALine (-CubePointy , CubePointx-CubePointr+CubeSizey , -CubePointx , -CubePointy-CubePointr+CubeSizey);
  drawALine (-CubePointx ,-CubePointy-CubePointr+CubeSizey ,  CubePointy , -CubePointx-CubePointr+CubeSizey);
  drawALine ( CubePointy ,-CubePointx-CubePointr+CubeSizey,  CubePointx ,  CubePointy-CubePointr+CubeSizey);
  drawALine ( CubePointx , CubePointy+CubeSizez+CubePointr+CubeSizey , -CubePointy ,  CubePointx+CubeSizez+CubePointr+CubeSizey);
  drawALine (-CubePointy , CubePointx+CubeSizez+CubePointr+CubeSizey , -CubePointx , -CubePointy+CubeSizez+CubePointr+CubeSizey);
  drawALine (-CubePointx ,-CubePointy+CubeSizez+CubePointr+CubeSizey ,  CubePointy , -CubePointx+CubeSizez+CubePointr+CubeSizey);
  drawALine ( CubePointy ,-CubePointx+CubeSizez+CubePointr+CubeSizey ,  CubePointx ,  CubePointy+CubeSizez+CubePointr+CubeSizey);
  drawALine ( CubePointx , CubePointy-CubePointr+CubeSizey ,  CubePointx ,  CubePointy+CubeSizez+CubePointr+CubeSizey);
  drawALine (-CubePointy , CubePointx-CubePointr+CubeSizey , -CubePointy ,  CubePointx+CubeSizez+CubePointr+CubeSizey);
  drawALine (-CubePointx ,-CubePointy-CubePointr+CubeSizey , -CubePointx , -CubePointy+CubeSizez+CubePointr+CubeSizey);
  drawALine ( CubePointy ,-CubePointx-CubePointr+CubeSizey ,  CubePointy , -CubePointx+CubeSizez+CubePointr+CubeSizey);

}