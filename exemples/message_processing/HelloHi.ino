/**
 * Mathieu Durand - mathieu_durand@icloud.com
 * Send and see (be carefull to also send to empty character at the start).
 * #715CE7ECHello
 */

#include <HashSerial.h>

HashSerial hashSerial(Serial);

void setup() {
  //  hashSerial.begin() replaces Serial.begin()
  hashSerial.begin(9600);

  //  Link lower timout can sometimes help if you experience issue
  Serial.setTimeout(10);

  //  Link sayHi to hashSerial so it can be called when a valid message is received
  hashSerial.attachProcedure(sayHi);
}

void loop() {
  //  Update hashSerial so it can process incoming message and verification
  hashSerial.update();
}


void sayHi(String message) {
  if (message.equals("Hello"))
    Serial.println("Hi!");

  //Do more message processing stuff or really whatever you want...
}
