//
// Code reading MPX5500DP as Vaccum sensor and reporting to OpenPnP.
//
// Licenced under  GNU GENERAL PUBLIC LICENSE
//
// 2017 Thomas S. Knutsen la3pna@gmail.com
//
//

int inData;

void setup() {
  // put your setup code here, to run once:
      Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
    inData = 0;
    if (Serial.available() > 0)   // see if incoming serial data:
    {
       inData = Serial.read();  // read oldest byte in serial buffer:
    }

    if (inData == 'M')
    {
     int code = Serial.parseInt();  // get the number part of the Mnnn code

     if (code == 830) // M830
     {
      Serial.println("vacuum:" + analogRead(A0));
      }

     if (code == 831)  // M831
     {
      Serial.println("vacuum:" + analogRead(A1));
      }

    }

  
}
