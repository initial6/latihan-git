//Mengirim data sensor ke server menggunakan ESP8266
//Oktavian Rizki Abdillah

#include <OneWire.h>
#include <DallasTemperature.h>

// koneksi akses point
#define SSID "hydrospot"    // SSID
#define PASS "lollo123456"  // Password router
//#define IP "oktavianabd.5gbfree.com" // ip komputer server
//#define IP "192.168.1.103"    
#define HOST "www.guardponic.kabapaski.com"// ip komputer server
#define PASSCODE "419550"

#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float s;  // EC
const byte pHpin = A4; // PH
float e; // suhu
float p;

void setup()
{
  pinMode(2, INPUT); // SUHU
  pinMode(A4, INPUT); // PH
  pinMode(A3, INPUT); // EC
  
  Serial.begin(115200); 
  sensors.begin();//sensor begin dallas DS18B20
  
  Serial.println("AT");
  delay(2000);
    if(Serial.find("OK")){
    connectWiFi();
  }
}

void loop(){

//-----SUHU
sensors.requestTemperatures();
s = sensors.getTempCByIndex(0); //membaca sensor suhu
   
//-----PH

//int measure = analogRead(A3);
//double voltage = 5/1024.0 * measure;
//p = 7 + ((2.5 - voltage)/0.18) ; //membaca sensor ph

p = ((1023 - analogRead(pHpin))/142.85)+0.19;

//int measureph = (analogRead(A4));
//double voltageph = measureph * 5.0/1023.0;
//p = map(voltageph,0,5,0,14); 

//-----EC  

int measure = analogRead(A3);
float ce = ((measure * 0.252) + 3.90 );
float e = ce/10-0.09927027027; //satuan mS/cm
//int m = (ce*100)-99.27027027; //satuan microsiemens

//float measureec = (analogRead(A1)); // membaca adc sensor ec
//e = measureec * 5.0/1023.0;

//float measureec = (analogRead(A1));
//float voltageec = measureec * 5.0/1023.0;
//e = map (voltageec,0,5,0,5);


  sendData(String(s), String(p), String(e));  // Call function to send data to Database Server.
  delay(300000);  //delay1 > mengirim setiap 300 detik (delay>ms) (5menit sekali)
}

void sendData(String tS, String tP, String tE)
{
  // Set up TCP connection.
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += HOST;
  cmd += "\",8081";
  Serial.println(cmd);
  delay(2000); //delay2 juga
  if(Serial.find("Error")){
  return;
  }
  // Send data.
  cmd = "GET /add_data.php?code=";
  cmd += PASSCODE;
  cmd += "&gS=";
  cmd += tS;
  cmd += "&gP=";
  cmd += tP;
  cmd += "&gE=";
  cmd += tE;
  cmd += " HTTP/1.1\r\nHost: ";
  cmd += HOST;
  cmd += "\r\n\r\n\r\n";
  Serial.print("AT+CIPSEND=");
  Serial.println(cmd.length());
  if(Serial.find(">")){
  Serial.print(cmd);
  delay(1000); //delay3 juga
  }
 else{
   Serial.println("AT+CIPCLOSE");
 }
}
// total delay = delay1+delay2+delay3


boolean connectWiFi(){
  Serial.println("AT+CWMODE=1");
  delay(2000);
  Serial.println("AT+CIPMUX=0");
  delay(2000);
  String cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  Serial.println(cmd);
  delay(5000);
  if(Serial.find("OK")){
    return true;
  }
  else{
    return false;
  }
}
