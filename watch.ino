const int light = 2;
const int btn = 0;
int WPM = 40;


//DO NOT CHANGE THESE VALUES
int dot = 3 * WPM;
int dash = 9 * WPM;


int hours = 0;
int minutes = 0;
int seconds = 0;

int inBetweenDelay = 200;



 //                       0          1        2       3       4         5        6        7      8          9             
 String signals[10] = { "_____", ".____", "..___", "...__", "...._", ".....", "_....", "__...", "___..", "____." };


void changeOver(int value){

  String strValue = "";


  if(value < 10){
    translate(value);
    delay(inBetweenDelay);


  }
  else{
    strValue = String(value);
     translate(strValue.substring(0,1).toInt());
     delay(inBetweenDelay);
    translate(strValue.substring(1,2).toInt());
    delay(inBetweenDelay);

  }








}




void translate(int value) {

  String mySignal = signals[value];
  Serial.println(mySignal);
  for (int i = 0; i < 5; i++) {

    digitalWrite(light, HIGH);
    if (mySignal.substring(i, i + 1) == ".") {
      delay(dot);
    } else {
      delay(dash);
    }

    digitalWrite(light, LOW);
    delay(inBetweenDelay);
  }
}




void time(){
  if(hours > 12){
    hours -= 12;
  }

    if (minutes >= 59){
      minutes = 0;
      hours ++;
    }

    if(seconds >= 59 || digitalRead(btn) == HIGH){
      seconds = 0;
      minutes++;
    }


}





void setup() {
  Serial.begin(115200);
  pinMode(light, OUTPUT);
  pinMode(btn, INPUT);




  hours = 15;
  minutes = 29;
}

void loop() {

  time();
  changeOver(hours);
  Serial.println(" = = = = ");
  delay(1000);
  changeOver(minutes);

  Serial.println("Cycle");
  
  delay(500);
  seconds+=9.5;


 
}
