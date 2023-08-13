## MODBUS ##
- Modbus is a data communications protocol originally published by Modicon (now Schneider Electric) in 1979 for use with its programmable logic controllers (PLCs). 
- Modbus has become a de facto standard communication protocol and is now a commonly available means of connecting industrial electronic devices.
- Modbus is often used to connect a plant/system supervisory computer with a remote terminal unit (RTU) in supervisory control and data acquisition (SCADA) systems. 

## Modbus object types
The following object types may be provided by a Modbus server to a Modbus client device:
![](image/MODBUS_ObjectType.png)

## Modbus RTU (Remote Terminal Unit) 
- It is used in serial communication, and is the most common implementation available for Modbus. 
- Modbus RTU makes use of a compact, binary representation of the data for protocol communication. 
- The RTU format follows the commands/data with a cyclic redundancy check checksum as an error check mechanism to ensure the reliability of data. 
- A Modbus RTU message must be transmitted continuously without inter-character hesitations. Modbus messages are framed (separated) by idle (silent) periods.
### RTU Frame format
![](image/MODBUS_FrameRTU.png)
![](image/MODBUS_RTU_Frame.jpeg)

## Modbus TCP/IP or Modbus TCP 
- A Modbus variant used for communications over TCP/IP networks, connecting over port 502. 
- It does not require a checksum calculation, as lower layers already provide checksum protection.
### Modbus TCP frame format
![](image/MODBUS_FrameTCP.png)

## Modbus over UDP 
Some have experimented with using Modbus over UDP on IP networks, which removes the overhead of TCP.

## Commands
Modbus commands can instruct a Modbus device to:

- Change the value in one of its registers, by write to Coil or Holding register
send back one or more contained values, by read from Coil or Holding register
read a physical input port, by read from Discrete Input or Input register   

### Functions and commands
Prominent conceptual entities in a Modbus server include the following:
- `Coils`: readable and writeable, 1 bit (off/on)
- `Discrete Inputs`: read-only, 1 bit (off/on)
- `Input Registers`: read-only measurements and statuses, 16 bits (0–65,535)
- `Holding Registers`: readable and writeable configuration values, 16 bits (0–65,535)

### Function code
![](image/MODBUS_FunctionCode.png)

### Exception responses
![](image/MODBUS_exception.png)