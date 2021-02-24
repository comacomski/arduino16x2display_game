#include<LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
byte ciko1 [8] = {
B01110 ,
B01110 ,
B00100 ,
B11111 ,
B00100 ,
B01010 ,
B10001 ,
};
byte ciko2 [8] = {
B01110 ,
B01110 ,
B00101 ,
B01110 ,
B10100 ,
B01010 ,
B01010 ,
};
byte srce [8] = {
B00000 ,
B01010 ,
B11111 ,
B11111 ,
B01110 ,
B00100 ,
B00000 ,
};
byte prazno[8]={
B00000 ,
B00000 ,
B00000 ,
B00000 ,
B00000 ,
B00000 ,
B00000 ,  
  };


int a[5],b,c=0,niz[15]={0},vr=300,lvl=0;
int ma=0;
void setup() {

  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.createChar(0, ciko1);
    lcd.createChar(1, ciko2);
        lcd.createChar(2, srce);
         lcd.createChar(3, prazno);
  lcd.setCursor(0,0);
  randomSeed ( analogRead (0) ) ;
  //aa
  a[0]=random(1,14);
a[1]=random(1,14);
a[2]=random(1,14);
a[3]=random(1,14);
a[4]=random(1,14);
niz[a[0]]=1;
niz[a[1]]=1;
niz[a[2]]=1;
niz[a[3]]=1;
niz[a[4]]=1;
for(int d=0;d<16;d++)
{
  lcd.setCursor(d,1);
 if(niz[d]==0) 
 {lcd.print("_");}
 if(niz[d]==1) 
 {
  if(d<5 && ma<4){
  lcd.print("_");
  Serial.println("ojsasa");
 }else lcd.print("-");}
 }

 while(Serial.available()==0);
}


int i=0,zivoti=3,pd=0,dugme=0;
void loop() { 
 
  if(zivoti>0)
  {
 char aa=0;
if(Serial.available()!=0)
{
  aa=Serial.read();
  }
  if(aa=='a')
  {
    dugme=1;
  
    }
    if(aa!='a')
    dugme=0;
lcd.setCursor (7, 0) ;
lcd.print("lvl:");
lcd.setCursor (11, 0) ;
lcd.print(lvl);
lcd.setCursor (14, 0) ;
lcd.write(byte(2));
lcd.setCursor (15 , 0) ;
lcd.print(zivoti);

if(dugme==0)
{
    lcd . setCursor (1 , 1) ;
 }
if(dugme!=0)
    {lcd . setCursor (1 , 0) ;
    pd=1;
    //dugme=0;
    }
//lcd.clear();
lcd.write(byte(0));
delay(vr);
  if(dugme==0 && niz[0]==1)
{

  }
//lcd.clear();
if(dugme==0)
{
    lcd . setCursor (1 , 1) ;
   // pd=0;
}
if(dugme!=0)
 {   lcd . setCursor (1 , 0) ;
 //pd=1;

 }
   if(dugme==0 && niz[1]==1)
{
lcd.write(byte(3));
  }
  else
  lcd.write(byte(1));
delay(vr);
if(pd==1)
{
  lcd.setCursor(1,0);
lcd.write(byte(3));
//pd=0;
  
  }


//aaaaaaaaa
//aaaaa
int temp;
niz[15]=niz[0];
niz[0]=niz[1];
niz[1]=niz[2];
niz[2]=niz[3];
niz[3]=niz[4];
niz[4]=niz[5];
niz[5]=niz[6];
niz[6]=niz[7];
niz[7]=niz[8];
niz[8]=niz[9];
niz[9]=niz[10];
niz[10]=niz[11];
niz[11]=niz[12];
niz[12]=niz[13];
niz[13]=niz[14];
niz[14]=niz[15];




for(int d=0;d<16;d++)
{
  lcd.setCursor(d,1);
 if(niz[d]==0) 
 {lcd.print("_");}
 if(niz[d]==1) 
 {if(ma<4 && d<5){
  lcd.print("_");
 }else lcd.print("-");
  }
 }

  if(dugme==0 && niz[0]==1)
{
  if(ma>=4)
  {
  pd=0;
  zivoti--;
  }
  }
   else if(dugme==1 && niz[0]==1)
{
  lvl++;
  }

  
  
i++;
ma++;
}
else
{zz:
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print(lvl);
 lcd.setCursor(3,0);
lcd.print(" ugasio si ga.");
 lcd.setCursor(0,1);
 lcd.print("'b' za ponovo.");
   while(Serial.available()==0);
   int bb=Serial.read();
   if(bb=='b')
   {
 //delay(5000);
 zivoti=3;
 vr=300;
 lvl=0;
 lcd.clear();
   }
   else goto zz;

}
if(vr>150)
vr--;
}

  

  
