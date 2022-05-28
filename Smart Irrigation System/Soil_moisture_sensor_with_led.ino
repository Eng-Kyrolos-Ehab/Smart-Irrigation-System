int soilMoistureValue = 0;
int percentage=0;
int val; 
int tempPin = PA0; 

#define soilWet 80   // Define max value we consider soil 'wet'
#define soilDry 90   // Define min value we consider soil 'dry'

//================ About Us ==================

// Wellcome to our project ^-^

// Project Idea: Smart Irrigation System

/*  Team Members:
 *  --------------

- Team Leader: Kyrolos Ehab      20191998
- Team Member: Mohammed Ibrahim  20195419
- Team Member: Mohammed Tarek    2019
- Team Member: Mohanned Ahmed    20191764
*/


void setup() {
  //led for soil moisture:
  pinMode(PB11, OUTPUT);    //red     Led:  Soil Moisture
  pinMode(PB0, OUTPUT);     //yallow  Led:  Soil Moisture
  pinMode(PA7, OUTPUT);     //green   Led:  Soil Moisture
  pinMode(PA5, OUTPUT);     //white   Led:  Soil Moisture
  pinMode(PB3, OUTPUT);     //Green   Led:  Soil Moisture

  //led for soil moisture:
  pinMode(PB6, OUTPUT);     //Red     Led:  Temperature 

  
  Serial.begin(9600);

}


void loop() {
  //get the reading from the function below and print it
  int percentage = analogRead(PA3)/40;
  Serial.print("soil moisture percentage: ");
  Serial.println(percentage);
  digitalWrite(PB11, HIGH); //red Led:  Soil Moisture

  // Determine status of our soil
  
  if (percentage < soilWet) {
  //  digitalWrite(PB11, HIGH); //Red led on
    digitalWrite(PA7, HIGH); //Green led on
    digitalWrite(PA5, LOW);  //White led Off
    digitalWrite(PB0, LOW);  //yallow  led Off
    
    Serial.println("Status: Soil is too wet");
    
} else if (percentage >= soilWet && percentage < soilDry) {
  //digitalWrite(PB11, HIGH); //Red led on
    digitalWrite(PA5, HIGH); //White led on
    digitalWrite(PB0, LOW);  //yallow  led Off
    digitalWrite(PA7, LOW); //Green led Off
    Serial.println("Status: Soil moisture is perfect");
    
  } else {
   // digitalWrite(PB11, HIGH); //Red led on
    digitalWrite(PB0, HIGH);  //yallow led on
    digitalWrite(PA5, LOW);   //White led Off
    digitalWrite(PA7, LOW);   //Green led Off
    digitalWrite(PB3, HIGH); //Green led on
    Serial.println("Status: Soil is too dry - time to water!");
  }


  //===== Heat ======
    
    Serial.print("   "); 
    val = analogRead(tempPin); 
    float mv = ( val/500.0)*100; 

    float cel = mv/20;
     
    float farh = (cel*9)/5 + 32; 
    Serial.print("TEMPRATURE *C = "); 
    Serial.print(cel); 
    Serial.print("*C"); 
    Serial.println(); 
    
    Serial.print("TEMPRATURE *F = "); 
    Serial.print(farh); 
    Serial.print("*F"); 
    Serial.println(); 

     if (cel < 60) {
      
      Serial.println("Status: temp. degree safe for human and plant");
      Serial.println(); 
      Serial.println(); 

     }else{
      
      Serial.println("Status: we stronglly recommend don't touch sensor + the temp. degree isn't safe for planet");
      Serial.println();       
      Serial.println(); 
     }

  
  delay(3000);  // Take a reading every second for testing
          // Normally you should take reading perhaps once or twice a day
  Serial.println();
}
