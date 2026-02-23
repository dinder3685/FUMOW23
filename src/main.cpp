#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/************ MOTOR PINS (AYNI) ************/
#define IN1_A 5   // D1
#define IN2_A 4   // D2
#define IN1_B 0   // D3
#define IN2_B 2   // D4
#define IN1_C 14  // D5
#define IN2_C 12  // D6
#define IN1_D 13  // D7
#define IN2_D 16  // D0

/************ WiFi ************/
const char* ssid = "iPhone";
const char* password = "1234554321";

ESP8266WebServer server(80);
String currentState = "IDLE";

/************ MOTOR CONTROL ************/
void motorForward(int in1, int in2) {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void motorBackward(int in1, int in2) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void motorStop(int in1, int in2) {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void forward() {
  motorForward(IN1_A, IN2_A);
  motorForward(IN1_B, IN2_B);
  motorForward(IN1_C, IN2_C);
  motorForward(IN1_D, IN2_D);
  currentState = "FORWARD";
}

void backward() {
  motorBackward(IN1_A, IN2_A);
  motorBackward(IN1_B, IN2_B);
  motorBackward(IN1_C, IN2_C);
  motorBackward(IN1_D, IN2_D);
  currentState = "BACKWARD";
}

void turnLeft() {
  motorForward(IN1_A, IN2_A);
  motorForward(IN1_C, IN2_C);
  motorBackward(IN1_B, IN2_B);
  motorBackward(IN1_D, IN2_D);
  currentState = "LEFT";
}

void turnRight() {
  motorBackward(IN1_A, IN2_A);
  motorBackward(IN1_C, IN2_C);
  motorForward(IN1_B, IN2_B);
  motorForward(IN1_D, IN2_D);
  currentState = "RIGHT";
}

void stopAll() {
  motorStop(IN1_A, IN2_A);
  motorStop(IN1_B, IN2_B);
  motorStop(IN1_C, IN2_C);
  motorStop(IN1_D, IN2_D);
  currentState = "IDLE";
}

/************ WEB + COMMAND HANDLER ************/
void handleRoot() {

  // Komut geldiyse işle
  if (server.hasArg("cmd")) {
    String cmd = server.arg("cmd");
    Serial.println("CMD: " + cmd);

    if (cmd == "forward") forward();
    else if (cmd == "backward") backward();
    else if (cmd == "left") turnLeft();
    else if (cmd == "right") turnRight();
    else if (cmd == "stop") stopAll();
  }

  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Robot</title>
  <style>
  body{font-family:Arial;text-align:center;background:#111;color:white;}
  button{width:100px;height:60px;font-size:18px;margin:10px;border-radius:10px;border:none;}
  </style>
  </head>
  <body>

  <h2>ESP8266 Robot Control</h2>

  <button onmousedown="send('forward')" onmouseup="send('stop')">UP</button><br>
  <button onmousedown="send('left')" onmouseup="send('stop')">LEFT</button>
  <button onclick="send('stop')">STOP</button>
  <button onmousedown="send('right')" onmouseup="send('stop')">RIGHT</button><br>
  <button onmousedown="send('backward')" onmouseup="send('stop')">DOWN</button>

  <script>
  function send(cmd){
    fetch('/?cmd=' + cmd);
  }
  </script>

  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

/************ SETUP ************/
void setup() {

  Serial.begin(115200);

  pinMode(IN1_A, OUTPUT);
  pinMode(IN2_A, OUTPUT);
  pinMode(IN1_B, OUTPUT);
  pinMode(IN2_B, OUTPUT);
  pinMode(IN1_C, OUTPUT);
  pinMode(IN2_C, OUTPUT);
  pinMode(IN1_D, OUTPUT);
  pinMode(IN2_D, OUTPUT);

  stopAll();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();

  Serial.println("Web server started");
}

/************ LOOP ************/
void loop() {
  server.handleClient();
}
