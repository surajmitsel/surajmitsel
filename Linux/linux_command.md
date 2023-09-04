## Linux Commands
https://www.geeksforgeeks.org/linux-commands/ 
https://linuxhandbook.com/a-to-z-linux-commands/ 

### grep command
- `grep -r comm` => search word "comm" recursively in a folder
- `grep -ir Received`  => search recursively ignore case sesntivity
- `grep -r common CMakeLists.txt` => search word "common" recursively in a folder
- `grep -l common *` => list the number of file in which "common" is present
- `grep -ir comm --include=*cpp` => search word "comm" recursively in a folder in the .cpp files only

### Process kil
- ps aux | grep <process> => get the PID
- kill <pid> => kill process
- pkill <process> => kill process

### for ubunto release version
- lsb_release -a
- ifconfig -s -a

### Run java jar file as a command
java -jar modsak3.13.jar

### compress file
If we want to create a file name “jayesh” with gzip compression
- tar -czvf jayesh.tar.gz files

### decompress file
- tar -xzvf jayesh.tar.gz
### Copy Data from window to dev-vm machine
- scp C:\Users\surajver\Desktop\Test.py scc-dmz@192.168.10.199:~/Desktop/Modbus
- scp C:\Users\surajver\Desktop\SAF\SqliteWrapper.PNG surajver@surajver-ubn-01:/home/surajver/suraj/Project/edge-components/doc/StoreAndForward

### copy from dev vm to window
- scp surajver@suraj-bl-ubn-01:/home/surajver/Project/edge-components/lib-mqtt/unit-test/connector_events_test.cpp C:/SURAJ/code/new_event/

### N/W troubleshooting command
- https://www.geeksforgeeks.org/network-configuration-trouble-shooting-commands-linux/