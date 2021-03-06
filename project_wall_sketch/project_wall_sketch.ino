
#include <Shifter.h>
#include <SPI.h>
#include <Ethernet.h>

int led = 4;
int led1 = 6;
int led2 = 2;
int led3 = 1;
int i;
int n;


#define SER_Pin 8 //SER_IN
#define RCLK_Pin 9 //L_CLOCK
#define SRCLK_Pin 10 //CLOCK

#define NUM_REGISTERS 7 //how many registers are in the chain


//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS);

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //physical mac address
byte ip[] = { 172, 21, 160, 63 };                      // ip in lan (that's what you need to use in your browser. ("192.168.1.178")
byte gateway[] = { 172, 21, 160, 1 };                   // internet access via router
byte subnet[] = { 255, 255, 252, 0 };                  //subnet mask
EthernetServer server(8080);                             //server port
String readString;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

}

void loop() {
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        //read char by char HTTP request
        if (readString.length() < 100) {
          //store characters to string
          readString += c;
          //Serial.print(c);
        }

        //if HTTP request has ended
        if (c == '\n') {
          Serial.println(readString); //print to serial monitor for debuging

          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          client.println();
          client.println("<HTML>");
          client.println("<HEAD>");

          client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
          client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
          client.println("<link rel='stylesheet' type='text/css' href='http://randomnerdtutorials.com/ethernetcss.css' />");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<a href=\"/?wall01_all\"\">Turn On all </a>"); //LED
          client.println("<a href=\"/?wall01_off\"\">Turn off all </a>"); //LED
                    client.println("<a href=\"/?wall01_01\"\">Turn LED 1 </a>"); //LED
                              client.println("<a href=\"/?wall01_02\"\">Turn LED 2 </a>"); //LED
                                        client.println("<a href=\"/?wall01_03\"\">Turn LED 3 </a>"); //LED
          client.println("</BODY>");
          client.println("</HTML>");

          delay(1);
          //stopping client
          client.stop();

          if (readString.indexOf("?wall01_all") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setAll(HIGH); //Set all pins on the chain high
            shifter.write();

          }

          if (readString.indexOf("?wall01_off") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setAll(LOW); //Set all pins on the chain off
            shifter.write();

          }

          if (readString.indexOf("?wall01_01") > 0) {


            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, HIGH);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.write();
        

          }




          if (readString.indexOf("?wall01_02") > 0) { //G2
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, HIGH);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_03") > 0) { //G3
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, HIGH);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_04") > 0) { //G4
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, HIGH);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_05") > 0) { //G5
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, HIGH);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_06") > 0) { //G5
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, HIGH);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_07") > 0) { //G7
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, HIGH);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_08") > 0) { //G8
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, HIGH);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_09") > 0) { //F1
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, HIGH);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_10") > 0) { //F2
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, HIGH);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_11") > 0) { //F3
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, HIGH);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_12") > 0) { //F4
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, HIGH);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_13") > 0) { //F5
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, HIGH);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_14") > 0) { //F6
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, HIGH);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }


          if (readString.indexOf("?wall01_15") > 0) { //F7
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, HIGH);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_16") > 0) { //F8
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, HIGH);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_17") > 0) { //E1
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, HIGH);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_18") > 0) { //E2
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, HIGH);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("wall01_19") > 0) { //E3
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, HIGH);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }


          if (readString.indexOf("?wall01_20") > 0) { //E4
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, HIGH);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }


          if (readString.indexOf("?wall01_21") > 0) { //E5
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, HIGH);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_22") > 0) { //E6
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, HIGH);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_23") > 0) { //E7
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, HIGH);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_24") > 0) { //E8
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, HIGH);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();
          }

          if (readString.indexOf("?wall01_25") > 0) { //D1
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, HIGH);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();
          }

          if (readString.indexOf("?wall01_26") > 0) { //D2
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, HIGH);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();
          }

          if (readString.indexOf("?wall01_27") > 0) { //D3
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, HIGH);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();
          }

          if (readString.indexOf("?wall01_28") > 0) { //D4
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, HIGH);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();
          }

          if (readString.indexOf("?wall01_29") > 0) { //D5
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, HIGH);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_30") > 0) { //D6
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, HIGH);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_31") > 0) { //D7
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, HIGH);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }


          if (readString.indexOf("?wall01_32") > 0) { //D8
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, HIGH);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_33") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, HIGH);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }


          if (readString.indexOf("?wall01_34") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, HIGH);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }


          if (readString.indexOf("?wall01_35") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, HIGH);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }


          if (readString.indexOf("?wall01_36") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, HIGH);
            shifter.setPin(37, LOW);
            shifter.setPin(38, LOW);
            shifter.write();

          }

          if (readString.indexOf("?wall01_37") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, HIGH);
            shifter.setPin(38, LOW);
            shifter.write();

          }


          if (readString.indexOf("?wall01_38") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(1, LOW);
            shifter.setPin(2, LOW);
            shifter.setPin(3, LOW);
            shifter.setPin(4, LOW);
            shifter.setPin(5, LOW);
            shifter.setPin(6, LOW);
            shifter.setPin(7, LOW);
            shifter.setPin(8, LOW);
            shifter.setPin(9, LOW);
            shifter.setPin(10, LOW);
            shifter.setPin(11, LOW);
            shifter.setPin(12, LOW);
            shifter.setPin(13, LOW);
            shifter.setPin(14, LOW);
            shifter.setPin(15, LOW);
            shifter.setPin(16, LOW);
            shifter.setPin(17, LOW);
            shifter.setPin(18, LOW);
            shifter.setPin(19, LOW);
            shifter.setPin(20, LOW);
            shifter.setPin(21, LOW);
            shifter.setPin(22, LOW);
            shifter.setPin(23, LOW);
            shifter.setPin(24, LOW);
            shifter.setPin(25, LOW);
            shifter.setPin(26, LOW);
            shifter.setPin(27, LOW);
            shifter.setPin(28, LOW);
            shifter.setPin(29, LOW);
            shifter.setPin(30, LOW);
            shifter.setPin(31, LOW);
            shifter.setPin(32, LOW);
            shifter.setPin(33, LOW);
            shifter.setPin(34, LOW);
            shifter.setPin(35, LOW);
            shifter.setPin(36, LOW);
            shifter.setPin(37, LOW);
            shifter.setPin(38, HIGH);

            shifter.write();

          }

          if (readString.indexOf("?wall02_01") > 0) {
            digitalWrite(led, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            shifter.setPin(39, HIGH);
            shifter.setPin(40, LOW);
            shifter.setPin(41, LOW);
            shifter.setPin(42, LOW);
            shifter.setPin(43, LOW);
            shifter.setPin(44, LOW);
            shifter.setPin(45, LOW);
            shifter.setPin(46, LOW);
            shifter.setPin(47, LOW);
            shifter.setPin(48, LOW);
            shifter.setPin(49, LOW);
            shifter.setPin(50, LOW);
            shifter.setPin(51, LOW);
            shifter.setPin(52, LOW);
            shifter.setPin(53, LOW);
            shifter.setPin(54, LOW);
            shifter.setPin(55, LOW);
            shifter.setPin(56, LOW);
            shifter.setPin(57, LOW);
            shifter.setPin(58, LOW);
            shifter.setPin(59, LOW);
            shifter.setPin(60, LOW);
            shifter.setPin(61, LOW);
            shifter.setPin(62, LOW);
            shifter.setPin(63, LOW);
            shifter.setPin(64, LOW);
            shifter.setPin(65, LOW);
            shifter.setPin(66, LOW);
            shifter.setPin(67, LOW);
            shifter.setPin(68, LOW);
            shifter.setPin(69, LOW);
            shifter.setPin(70, LOW);
            shifter.setPin(71, LOW);
            shifter.setPin(72, LOW);
            shifter.setPin(73, LOW);
            shifter.setPin(74, LOW);
            shifter.setPin(75, LOW);
            shifter.setPin(76, LOW);
            shifter.write();

          }


          if (readString.indexOf("?button1onA1") > 0) {

            if (readString.indexOf("?button1onA1") > 0) {



              shifter.write();
              for (i = 0; i < 3; i++)
              {

                shifter.setPin(4, HIGH);
                shifter.write();
                delay(200);

                shifter.setPin(4, LOW);
                shifter.write();
                delay(200);

              }


            }

            //clearing string for next read
            readString = "";

          }
        }
      }
    }
  }
}

