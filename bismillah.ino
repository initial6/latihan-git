#include <dht.h>
#include <Servo.h>
//#include <SoftwareSerial.h>

#define SSID "DEMIT"    // SSID
//#define PASS "aufnaxs22vyyuz6vchtv" // Password router
#define PASS "parabola2k16" // Password router
#define IP "10.252.111.58"    // ipkomputer server
//#define HOST "www.mushroom.kabapaski.com"
//#define IP "192.168.1.116"
#define dht1_dpin A1
#define dht2_dpin A2
#define dht3_dpin A3

Servo myservo;
dht DHT;

float f; // suhu
float g; //kelembaban
float h; // suhu
float i; //kelembaban
float j; // suhu
float k; //kelembaban
int l; // cahaya
char m; // kondisi
int n; // sudut servo

boolean bahaya = false;
boolean normal = false;
boolean lembab = false;

int servoPin = 5; //servo
int pulseTime;

//double sendDat = 10000;
//double previous = 0;
//double timeMillis = 0;

//SoftwareSerial D(2,3); // RX, TX

void setup()
{
  pinMode(A1, INPUT);  // DHT-11
  pinMode(A2, INPUT);  // DHT-11
  pinMode(A3, INPUT);  // DHT-11
  pinMode(A4, INPUT);  // LDR
  pinMode(servoPin, OUTPUT); //SERVO

  myservo.attach(5);

  Serial.begin(115200);

  //sensors.begin();

  Serial.println("AT");
  delay(2000);
  if (Serial.find("OK")) {
    connectWiFi();
  }
}


void loop() {
  //timeMillis = millis();

  DHT.read11(dht1_dpin);   //membaca sensor DHT1
  f = (DHT.temperature);  //membacasuhu
  g = (DHT.humidity);     //membacakelembaban
  DHT.read11(dht2_dpin);   //membaca sensor DHT2
  h = (DHT.temperature);  //membacasuhu
  i = (DHT.humidity);     //membacakelembaban
  DHT.read11(dht3_dpin);   //membaca sensor DHT3
  j = (DHT.temperature);  //membaca suhu
  k = (DHT.humidity);     //membaca kelembaban
  l = analogRead(A4); //membaca sensor cahaya
  rule();
  //Serial.println(timeMillis);
  //if (timeMillis - previous > 0 && timeMillis - previous >= sendDat)
  {
    //Serial.println("Send Data");
    sendData(String(f), String(g), String(h), String(i), String(j), String(k), String(l), String(m), String(n));
    //previous = timeMillis;
  }
  delay(100);
}
void rule() { //Rules Fuzzy
  //r1
  if (f >= 27 && f <= 35)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r2
  if (f >= 27 && f <= 35)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r3
  if (f >= 27 && f <= 35)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r4
  if (f >= 26 && f <= 28)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r5
  if (f >= 26 && f <= 28)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r6
  if (f >= 26 && f <= 28)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r7
  if (f >= 0 && f <= 27)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r8
  if (f >= 0 && f <= 27)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r9
  if (f >= 0 && f <= 27)
  {
    if (g >= 75 && g <= 150)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r10
  if (f >= 27 && f <= 35)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r11
  if (f >= 27 && f <= 35)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r12
  if (f >= 27 && f <= 35)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r13
  if (f >= 26 && f <= 28)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r14
  if (f >= 26 && f <= 28)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r15
  if (f >= 26 && f <= 28)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r16
  if (f >= 0 && f <= 27)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r17
  if (f >= 0 && f <= 27)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r18
  if (f >= 0 && f <= 27)
  {
    if (g >= 70 && g <= 80)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(0);
        lembab = true;
      }
    }
  }
  //r19
  if (f >= 27 && f <= 35)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(90);
        bahaya = true;
      }
    }
  }
  //r20
  if (f >= 27 && f <= 35)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(90);
        bahaya = true;
      }
    }
  }
  //r21
  if (f >= 27 && f <= 35)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(90);
        bahaya = true;
      }
    }
  }
  //r22
  if (f >= 26 && f <= 28)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(45);
        normal = true;
      }
    }
  }
  //r23
  if (f >= 26 && f <= 28)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(45);
        normal = true;
      }
    }
  }
  //r24
  if (f >= 26 && f <= 28)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(45);
        normal = true;
      }
    }
  }
  //r25
  if (f >= 0 && f <= 27)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 175 && l <= 1200)
      {
        myservo.write(45);
        normal = true;
      }
    }
  }
  //r26
  if (f >= 0 && f <= 27)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 50 && l <= 300)
      {
        myservo.write(45);
        normal = true;
      }
    }
  }
  //r27
  if (f >= 0 && f <= 27)
  {
    if (g >= 0 && g <= 75)
    {
      if (l >= 0 && l <= 175)
      {
        myservo.write(45);
        normal = true;
      }
    }
  }

  delay(100);

  if (lembab)
  {
    m = 'L';
    n = 0;
    lembab = false;
  }

  if (normal)
  {
    m = 'N';
    n = 45;
    normal = false;
  }
  if (bahaya)
  {
    m = 'B';
    n = 90;
    bahaya = false;
  }
}
void sendData(String tF, String tG, String tH, String tI, String tJ, String tK, String tL, String tM, String tN)
{
  // Set up TCP connection.
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  Serial.println(cmd);
  delay(2000);
  if (Serial.find("Error")) {
    return;
  }

  // Send data.
  cmd = "GET /data.php?";
  cmd += "1=";
  cmd += tF;
  cmd += "&2=";
  cmd += tG;
  cmd += "&3=";
  cmd += tH;
  cmd += "&4=";
  cmd += tI;
  cmd += "&5=";
  cmd += tJ;
  cmd += "&6=";
  cmd += tK;
  cmd += "&7=";
  cmd += tL;
  cmd += "&8=";
  cmd += tM;
  cmd += "&9=";
  cmd += tN;
  //cmd += " HTTP/1.1\r\nHost :";
  //cmd += HOST;
  cmd += "\r\n\r\n\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  if (Serial.find(">")) {
    Serial.print(cmd);
    delay(100000);
  }
  else {
    Serial.println("AT+CIPCLOSE");
  }
}


boolean connectWiFi() {
  Serial.println("AT+CWMODE=1");
  delay(2000);
  Serial.println("AT+CIPMUX=0");
  delay(2000);
  String cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  Serial.println(cmd);
  delay(50000);
  if (Serial.find("OK")) {
    return true;

  }
  else {
    return false;
  }
}
