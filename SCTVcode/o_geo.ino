char GeoSecs[] = "\n"; 
char GeoEndStr [] = "\n";
int modsecs = 0;
int seccircle = 0;
int xmcirc = 0;
int ymcirc = 0;
float xcircmvel = 0;
float ycircmvel = 0;
float minangle = 0;
int xhcirc = 0;
int yhcirc = 0;
float xcirchvel = 0;
float ycirchvel = 0;
float hrangle = 0;
int hranglebase = 0;

struct item geometryList[] = {
  {text,10,0,GeoSecs,0,0},
  {listend,0,0,BlankLn,0,0}};

void Geometry() 
{

//draw minute circle
minangle =  Mins ; 
minangle = (((minangle) * 426) / 4068); // convert to radians
xcircmvel = (sin (minangle) * 10);
ycircmvel = (cos (minangle) * 10);
xmcirc = xmcirc + xcircmvel;
ymcirc = ymcirc + ycircmvel;

drawACircle(xmcirc, ymcirc, 200);

if ((xmcirc > 1400) || (xmcirc < -1400))
{
 xmcirc = 0;
 ymcirc = 0;
}
if ((ymcirc > 1400) || (ymcirc < -1400))
{
 xmcirc = 0;
 ymcirc = 0;
}

//draw hours circle  
  hrangle = Hrs;
  hrangle = (((hrangle) * 2130) / 4068); // convert to radians
  xcirchvel = (sin (hrangle) * 15);
  ycirchvel = (cos (hrangle) * 15);

  xhcirc = xhcirc + xcirchvel;
  yhcirc = yhcirc + ycirchvel;
  
  drawACircle(xhcirc, yhcirc, 80);
  drawACircle(xhcirc, yhcirc, 60);
  drawACircle(xhcirc, yhcirc, 40);
  drawACircle(xhcirc, yhcirc, 20);


if ((xhcirc > 1400) || (xhcirc < -1400))
{
 xhcirc = 0;
 yhcirc = 0;
 hranglebase ++;
}
if ((yhcirc > 1400) || (yhcirc < -1400))
{
 xhcirc = 0;
 yhcirc = 0;
 hranglebase ++;
}

//draw seconds circle
  seccircle = (Secs * 45)+10;
  drawACircle(0, 0, seccircle);
  strcpy(GeoSecs, "");
  strcat(GeoSecs, GeoEndStr);  
 
}