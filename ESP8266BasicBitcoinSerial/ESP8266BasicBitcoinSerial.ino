#include <ESP8266WiFi.h>

const char* ssid     = "iainhendry"; // insert your SSID
const char* password = "iain061271"; // insert your password

const char* host = "api.coindesk.com";
String url = "/v1/bpi/currentprice.json";

String id;
String value;

void setup() 
{
  Serial.begin(115200);
  delay(10);

  Serial.println("Bitcoin Prices");

  //We start by connecting to a WiFi network

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(host);
  
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) 
  {
    Serial.println("connection failed");
    return;
  }
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(10);
   
  unsigned int i = 0;
  int n = 1;
  char json[500] ="{";
  while (!client.find("\"USD\":{")){} 
  while (i<600) 
  {
    if(client.available()) 
    {
      char c = client.read();
      json[n]=c;
      if(c=='}') break;
      n++;
      i=0;
    }
    i++;
  }

  Serial.println(json);
  id += json;
  value += json;
  
  id = id.substring(9,12);
  Serial.print(id);
  Serial.print("= ");
  
  value = value.substring(99,106);
  Serial.println(value);
  
  id="";
  value="";
 
  Serial.println("closing");
  delay(60000);
}
