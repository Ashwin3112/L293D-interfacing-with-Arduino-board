const int cp1=2;//control pin connect to pin 2 with l293d pin 2 
const int cp2=3;//control pin connect to pin 3 with l293d pin 7 
const int en =9;//enable pin
const int pot =A0; //connect potentiometer to pin A0
const int dpin=5; //direction control switch connect to pin 5 of arduino
const int swpin=4; // for on off connect to pin 4 of arduino
int dpinstate=0;
int swpinstate=0;
int motorspd=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(cp1,OUTPUT);
  pinMode(cp2,OUTPUT);
  pinMode(en,OUTPUT);
  pinMode(dpin,INPUT);
  pinMode(swpin,INPUT);
  digitalWrite(en,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
 dpinstate=digitalRead(dpin);
 swpinstate=digitalRead(swpin);
 motorspd=analogRead(pot)/4;
 if(swpinstate==HIGH) //Control on on off switch by enableing enable pin with analog voltage
 {analogWrite(en,motorspd);}
 else
 {analogWrite(en,motorspd*0);}

 if(dpinstate==HIGH)//controling direction of motion of motor
 {
  digitalWrite(cp1,HIGH);
  digitalWrite(cp2,LOW);
  }
  else if(dpinstate==LOW)
  { digitalWrite(cp2,HIGH);
  digitalWrite(cp1,LOW);}
 
}
