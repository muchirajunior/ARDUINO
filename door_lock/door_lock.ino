#include<ESP8266WiFi.h>
const char *ssid = "Tech Space BD"; // write your wifi network's name here
const char *password = "newtech12"; // write your password here
int Lock = 4; //GPIO4 d4
WiFiServer server(80);
int LOCK=16;
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(LOCK, OUTPUT);
  digitalWrite(LOCK, LOW);
  //connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("connecting to");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED);
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  //Start the server
  server.begin();
  Serial.println("Server started");
  Serial.println("");
  Serial.println("************WiFi doorlock******************");
  //print the IP address
  Serial.println("use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  //check if a client has connected
  WiFiClient Client = Server.available();
  if (!Client){
    return;
  }
//wait until the client sends some data
Serial.println("new client");
while(!Client.available()){
  delay(1);
}
  //read the first line of the request
  String request = Client.readStringUntil('\r');
  Serial.println(request);
  Client.flush();
  //match the request
  int value=LOW;
  if(request.indexOf("/LOCK=ON") != -1)
  {
    digitalWrite(LOCK, HIGH);
    value = HIGH;
  }
    if(request.indexOf("/LOCK=OFF") !=-1)
  {
    digitalWrite(LOCK, LOW);
    value = LOW;
  }

 //set LOCK according to the request
 //digitalWrite(LOCK, value);
 //Return the response
 Client.println("HTTP/1.1 200 OK");
 Client.println("Content=Type: text/html");
 Client.println(""); //do not forget this one
 Client.println("<!DOCTYPE HTML>");
 Client.println("<html>");

 Client.print("Door is now: ");

 if (value == HIGH){
  Client.print("Open");
 }
 else{
  Client.print("Closed");
 }
 Client.println("<br><br>");
 Client.println("<a href=\"/LOCK=ON\"\"><button><h1>Turn On</h1> </button></a>");
 Client.println("<a href=\"/LOCK=OFF\"\"><button><h1>Turn Off</h1></button></a><br />");
 Client.println("</html>");
 delay(1);
 Serial.println("Client disconnected");
 Serial.println("");
}
