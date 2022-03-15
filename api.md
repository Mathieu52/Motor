# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`HashSerial`](#class_hash_serial) | Mathieu Durand : [mathieu_durand@icloud.com](mailto:mathieu_durand@icloud.com)

# class `HashSerial` 

Mathieu Durand : [mathieu_durand@icloud.com](mailto:mathieu_durand@icloud.com)

1.0.0 Hash code based Arduino Serial extension class

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`HashSerial`](#class_hash_serial_1a3ba440a5e2b3cf170e91f4c3d4d3cdaa)`(HardwareSerial & serial)` | Constructor of [HashSerial](#class_hash_serial)
`public void `[`begin`](#class_hash_serial_1a7b5e28f89a56052dfad2077f24c03a9d)`(long speed)` | Sets the data rate in bits per second (baud) for serial data transmission. 
`public String `[`update`](#class_hash_serial_1a408c006d67428cb35a48d201120d9870)`()` | Look for confirmation that the last sent message has been received as well as look for received message (make sure they are valid, if valid trigger attached procedure) 
`public void `[`end`](#class_hash_serial_1a38c88aca98f27ca71ba8e540a079e681)`()` | Disables serial communication, allowing the RX and TX pins to be used for general input and output. To re-enable serial communication, call `[HashSerial.begin()](#class_hash_serial_1a7b5e28f89a56052dfad2077f24c03a9d)`.
`public int `[`available`](#class_hash_serial_1adcd451d504d6a2b02e6ea3a13a79d214)`()` | Get the number of bytes (characters) available for reading from the serial port. This is data that’s already arrived and stored in the serial receive buffer (which holds 64 bytes). 
`public int `[`availableForWrite`](#class_hash_serial_1aaafae66ededbb19151df8103e8f5b845)`()` | Get the number of bytes (characters) available for writing in the serial buffer without blocking the write operation. 
`public size_t `[`send`](#class_hash_serial_1a2a92bec9bd9337fdfac5f563f393ba1c)`(const String & s)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public size_t `[`send`](#class_hash_serial_1a55ccbb6fdfb00b574848342e6dc955b3)`(const char str)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public size_t `[`send`](#class_hash_serial_1a79fa3f04d152363f08f2b59a9852fb70)`(char c)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public size_t `[`send`](#class_hash_serial_1a7740039485a40238bceda0785a8c8dba)`(unsigned char b,int base)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public size_t `[`send`](#class_hash_serial_1ab753fd6b279c6d7219a80c367cfd8a29)`(int n,int base)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public size_t `[`send`](#class_hash_serial_1a97082abf84d1b7dad75baddc04a93873)`(unsigned int n,int base)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public size_t `[`send`](#class_hash_serial_1a3ebdef0b231206a49414fa23b5071664)`(long n,int base)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public size_t `[`send`](#class_hash_serial_1a31a53b3371726af230eedd98a367e08a)`(unsigned long n,int base)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public size_t `[`send`](#class_hash_serial_1a80b01a94f5befeb6e6a29822951a89d6)`(double n,int digits)` | Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
`public String `[`readMessage`](#class_hash_serial_1a7e114c179d635688e4009b50954b5e11)`()` | Retrieve the last received message. 
`public void `[`attachProcedure`](#class_hash_serial_1af3ea8c6e1a72d2eff0773cbdc2010591)`(void(*)(String message) procedure)` | Attach a function to hashSerial. 
`public void `[`setAcknowledgedTimeout`](#class_hash_serial_1a2e7bcb5c5a8099fd85a04fa7972c1ca5)`(unsigned long time)` | Sets the maximum milliseconds to wait for Acknowledgedment before resending message. It defaults to 100 milliseconds. 

## Members

#### `public  `[`HashSerial`](#class_hash_serial_1a3ba440a5e2b3cf170e91f4c3d4d3cdaa)`(HardwareSerial & serial)` 

Constructor of [HashSerial](#class_hash_serial)
#### Parameters
* `serial` : HardwareSerial, Serial used to send data

#### `public void `[`begin`](#class_hash_serial_1a7b5e28f89a56052dfad2077f24c03a9d)`(long speed)` 

Sets the data rate in bits per second (baud) for serial data transmission. 
#### Parameters
* `speed` : in bits per second (baud). Allowed data types: long.

#### `public String `[`update`](#class_hash_serial_1a408c006d67428cb35a48d201120d9870)`()` 

Look for confirmation that the last sent message has been received as well as look for received message (make sure they are valid, if valid trigger attached procedure) 
#### Returns
String, A valid message in other case a blank string

#### `public void `[`end`](#class_hash_serial_1a38c88aca98f27ca71ba8e540a079e681)`()` 

Disables serial communication, allowing the RX and TX pins to be used for general input and output. To re-enable serial communication, call `[HashSerial.begin()](#class_hash_serial_1a7b5e28f89a56052dfad2077f24c03a9d)`.

#### `public int `[`available`](#class_hash_serial_1adcd451d504d6a2b02e6ea3a13a79d214)`()` 

Get the number of bytes (characters) available for reading from the serial port. This is data that’s already arrived and stored in the serial receive buffer (which holds 64 bytes). 
#### Returns
The number of bytes available to read.

#### `public int `[`availableForWrite`](#class_hash_serial_1aaafae66ededbb19151df8103e8f5b845)`()` 

Get the number of bytes (characters) available for writing in the serial buffer without blocking the write operation. 
#### Returns
The number of bytes available to write.

#### `public size_t `[`send`](#class_hash_serial_1a2a92bec9bd9337fdfac5f563f393ba1c)`(const String & s)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public size_t `[`send`](#class_hash_serial_1a55ccbb6fdfb00b574848342e6dc955b3)`(const char str)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public size_t `[`send`](#class_hash_serial_1a79fa3f04d152363f08f2b59a9852fb70)`(char c)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public size_t `[`send`](#class_hash_serial_1a7740039485a40238bceda0785a8c8dba)`(unsigned char b,int base)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public size_t `[`send`](#class_hash_serial_1ab753fd6b279c6d7219a80c367cfd8a29)`(int n,int base)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public size_t `[`send`](#class_hash_serial_1a97082abf84d1b7dad75baddc04a93873)`(unsigned int n,int base)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public size_t `[`send`](#class_hash_serial_1a3ebdef0b231206a49414fa23b5071664)`(long n,int base)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public size_t `[`send`](#class_hash_serial_1a31a53b3371726af230eedd98a367e08a)`(unsigned long n,int base)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public size_t `[`send`](#class_hash_serial_1a80b01a94f5befeb6e6a29822951a89d6)`(double n,int digits)` 

Prints data to the serial port as human-readable ASCII text preceded by it's hexadecimal hash code, followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '
'). 
#### Returns
returns the number of bytes written, though reading that number is optional. Data type: size_t.

#### `public String `[`readMessage`](#class_hash_serial_1a7e114c179d635688e4009b50954b5e11)`()` 

Retrieve the last received message. 
#### Returns
Last received message. Data type: String.

#### `public void `[`attachProcedure`](#class_hash_serial_1af3ea8c6e1a72d2eff0773cbdc2010591)`(void(*)(String message) procedure)` 

Attach a function to hashSerial. 
#### Parameters
* `procedure` : function that will be executed when a valid message is received

#### `public void `[`setAcknowledgedTimeout`](#class_hash_serial_1a2e7bcb5c5a8099fd85a04fa7972c1ca5)`(unsigned long time)` 

Sets the maximum milliseconds to wait for Acknowledgedment before resending message. It defaults to 100 milliseconds. 
#### Parameters
* `time` : timeout duration in milliseconds. Allowed data types: unsigned long.

Generated by [Moxygen](https://sourcey.com/moxygen)