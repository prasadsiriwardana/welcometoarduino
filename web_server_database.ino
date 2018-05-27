#include <SPI.h>
#include <Ethernet.h>
#include "DHT.h"
#define DHTPIN 9
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {192, 168, 1, 18 }; //Read the code explanation below
byte serv[] = {192, 168, 1, 5} ; //Read the code explanation below
EthernetClient cliente;
void setup() {
Serial.begin(9600); //setting the baud rate at 9600
Ethernet.begin(mac, ip);
dht.begin();
}
void loop() {
float hum = dht.readHumidity(); //Reading the humidity and storing in hum
float temp = dht.readTemperature(); //Reading the temperature as Celsius and storing in temp
float fah = dht.readTemperature(true); //reading the temperature in Fahrenheit
float heat_index = dht.computeHeatIndex(fah, hum); //Reading the heat index in Fahrenheit
float heat_indexC = dht.convertFtoC(heat_index); //Converting the heat index in Celsius
 if (cliente.connect(serv, 8095)) { //Connecting at the IP address and port we saved before
Serial.println("connected");
cliente.print("GET /ethernet/data.php?"); //Connecting and Sending values to database
cliente.print("temperature=");
cliente.print(temp);
cliente.print("&humidity=");
cliente.print(hum);
cliente.print("&heat_index=");
cliente.println(heat_indexC);
//Printing the values on the serial monitor
Serial.print("Temperature= ");
Serial.println(temp);
Serial.print("Humidity= ");
Serial.println(hum);
cliente.stop(); //Closing the connection
}
else {
// if you didn't get a connection to the server:
Serial.println("connection failed");
}
delay(5000);
}
