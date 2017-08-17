char input;
String inputString="";
int enable = 11,test = 12;
int sta = 13;
int in1 = 2;
int in2 = 4;
int in5 = 5;
int in3 = 7;
int in4 = 8;
boolean rev = HIGH;

void setup()                    
{
 Serial.begin(9600);            
 pinMode(test,INPUT);
 pinMode(sta,OUTPUT);
 pinMode(in1,OUTPUT);
 pinMode(in2,OUTPUT);
 pinMode(in3,OUTPUT);
 pinMode(in4,OUTPUT);
 pinMode(in5,OUTPUT);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      input = (char)Serial.read();
      inputString += input;
    }
    while (Serial.available() > 0)  
    {char junk = Serial.read() ; }      
    if(inputString == "1"){   
      Serial.println(digitalRead(test)); 
      setMotor(rev);  
    }else if(inputString == "2"){   
      setMotor(!rev);
    }else if(inputString == "3"){   
      brake(!rev);
    }
    inputString = "";
  }
}
void setMotor(boolean rev){
   digitalWrite(in1,rev);
   digitalWrite(in2,rev);
   digitalWrite(in3,!rev);
   digitalWrite(in4,!rev);
   digitalWrite(in5,!rev);
   digitalWrite(sta,rev);
}

void brake(boolean rev){
   digitalWrite(in1,rev);
   digitalWrite(in2,rev);
   digitalWrite(in3,rev);
   digitalWrite(in4,rev);
   digitalWrite(in5,rev);
   digitalWrite(sta,LOW);
}
