/**@file HashSerial.cpp */

#include "Arduino.h"
#include "HashSerial.h"
/**
 * Constructor of HashSerial
 * @param serial : HardwareSerial, Serial used to send data
 */
HashSerial::HashSerial(HardwareSerial &serial) {
  this->serial = &serial;
}

/**
 * Sets the data rate in bits per second (baud) for serial data transmission.
 * @param speed : in bits per second (baud). Allowed data types: long.
 */
void HashSerial::begin(long speed) {
  serial->begin(speed);
}

/**
 * Disables serial communication, allowing the RX and TX pins to be used for general input and output. To re-enable serial communication, call {@link #begin HashSerial.begin()}.
 */
void HashSerial::end() {
  serial->end();
}

/**
 * Look for confirmation that the last sent message has been received as well as look for received message (make sure they are valid, if valid trigger attached procedure)
 * @return String, A valid message in other case a blank string
 */
String HashSerial::update() {
  if (!message_acknowledged) {
    
    if (millis() - time_since_message > acknowledged_timeout) {
      send(last_sent_message);
    }
      
    while(available() > 0 && serial->peek() == acknowledgeControlCharacter) {
      serial->read();
      message_acknowledged = true;
    }
    
  }

  if (available() == 0)
    return "";
    
  message = serial->readString();
  message = message.substring(0, message.length() - 1);

  if (message.length() == 0)
    return "";
  
  const int hashLength = HashSerial::hashStrLength;
  //#3F75CCC1test
  String hash = message.substring(0, hashLength);
  message = message.substring(hashLength);

  String processedHash = HashSerial::generateHashCode(message.c_str());

  if (hash.equals(processedHash)) {
    sendAcknowledge();
    procedure(message);
  } else
    message == "";
  
  return message;
}

/**
 * Get the number of bytes (characters) available for reading from the serial port. This is data that’s already arrived and stored in the serial receive buffer (which holds 64 bytes).
 * @return The number of bytes available to read.
 */
int HashSerial::available() {
  return serial->available();
}


/**
 * Get the number of bytes (characters) available for writing in the serial buffer without blocking the write operation.
 * @return The number of bytes available to write.
 */
int HashSerial::availableForWrite() {
  return serial->availableForWrite();
}

/**
 * Sets the maximum milliseconds to wait for Acknowledgedment before resending message. It defaults to 100 milliseconds.
 * @param time : timeout duration in milliseconds. Allowed data types: unsigned long.
 */
void HashSerial::setAcknowledgedTimeout(unsigned long time) {
  acknowledged_timeout = time;
}

/**
 * Send Acknowledge character through serial.
 */
void HashSerial::sendAcknowledge() {
  return serial->write(acknowledgeControlCharacter);
}

/**
 * Retrieve the last received message.
 * @return Last received message. Data type: String.
 */
String HashSerial::readMessage() {
  return message;
}

/**
 * Attach a function to hashSerial.
 * @param procedure : function that will be executed when a valid message is received
 */
void HashSerial::attachProcedure(void (*procedure)(String message)) {
  this->procedure = procedure;
}

/**
 * Send the hash code of a String through serial.
 * @param key : String that will be used to generate the hash code
 * @return will return the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::writeHash(String key) {
  const String hash = HashSerial::generateHashCode(key.c_str());
  return serial->write(hash.c_str(), HashSerial::hashStrLength);
}

/**
 * Generate the hash code of String.
 * @param key : String that will be used to generate the hash code
 * @return will return the hashcode in hexadecimal format. Data type: String.
 */
String HashSerial::generateHashCode(char* key) {
  size_t i = 0;
  uint32_t hash = 0;
  while (i != strlen(key)) {
    hash += key[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;

  String hashString = '#' + String(hash, HEX);
  hashString.toUpperCase();
  return hashString;
}


/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(const String &s) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = s;
  return writeHash(last_sent_message) + serial->println(s);
}

/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(const char str[]) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = String(str);
  return writeHash(last_sent_message) + serial->println(str);
}

/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(char c) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = String(c);
  return writeHash(last_sent_message) + serial->println(c);
}

/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(unsigned char b, int base) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = String(b, base);
  return writeHash(last_sent_message) + serial->println(b, base);
}

/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(int n, int base) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = String(n, base);
  return writeHash(last_sent_message) + serial->println(n, base);
}

/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(unsigned int n, int base) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = String(n, base);
  return writeHash(last_sent_message) + serial->println(n, base);
}

/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(long n, int base) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = String(n, base);
  return writeHash(last_sent_message) + serial->println(n, base);
}

/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(unsigned long n, int base) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = String(n, base);
  return writeHash(last_sent_message) + serial->println(n, base);
}

/**
 * Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').
 * @return returns the number of bytes written, though reading that number is optional. Data type: size_t.
 */
size_t HashSerial::send(double n, int digits) {
  time_since_message = millis();
  message_acknowledged = false;
  last_sent_message = String(n, digits);
  return writeHash(last_sent_message) + serial->println(n, digits);
}
