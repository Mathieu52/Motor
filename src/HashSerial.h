#ifndef HashSerial_h
#define HashSerial_h
#include "Arduino.h"

/**
 Hash code based Arduino Serial extension class
 @author Mathieu Durand : mathieu_durand@icloud.com
 @version 1.0.0
 */
class HashSerial {
  public:
    HashSerial(HardwareSerial &serial);
    void begin(long speed);
    String update();
    void end();
    int available();
    int availableForWrite();
    
    size_t send(const String &s);
    size_t send(const char str[]);
    size_t send(char c);
    size_t send(unsigned char b, int base);
    size_t send(int n, int base);
    size_t send(unsigned int n, int base);
    size_t send(long n, int base);
    size_t send(unsigned long n, int base);
    size_t send(double n, int digits);

    String readMessage();
    void attachProcedure(void (*procedure)(String message));
    
    void setAcknowledgedTimeout(unsigned long time);
    
  private:
    HardwareSerial *serial;
    size_t writeHash(String key);
    void sendAcknowledge();
    String last_sent_message = "";
    unsigned long time_since_message;
    boolean message_acknowledged = true;

    unsigned acknowledged_timeout = 100;
    String message = "";

    void (*procedure)(String message);
    
    static String generateHashCode(char* key);
    static const int hashStrLength = 9;
    static const char acknowledgeControlCharacter = 0x06;
    static const char startControlCharacter = 0x02;
};
#endif
