## Code Dump
- A core dump is a file containing a process's address space (memory) when the process terminates unexpectedly. Core dumps may be produced on-demand (such as by a debugger), or automatically upon termination.
- The Linux kernel can write a file containing the state of a process when the process receives certain signals, e.g. segmentation fault or illegal instruction. Such files are called core dumps and contain a snapshot of the allocated memory and registers and can later be used with gdb to analyse the causes of the signal.
- Several tools are available to capture a core dump file, such as gcore, gdb, and several tools to analyze a core dump file, such as objdump, kdump, gdb, and lldb.
- In Ubuntu the core dumps are handled by Apport and can be located in `/var/crash/`. But it is disabled by default in stable releases. To enable Apport, run: sudo systemctl enable apport.service or sudo service apport start.
- The default option is to store the vmcore file in the `/var/crash` directory of the local file system. The option path `/var/crash` represents the file system path in which the kdump saves the vmcore file. 

### Generate Core Dump
Linux and Mac OS X
1. When enabled, core dump files in Linux and Mac OS X are generated automatically before a process crashes. You can check whether core dump files are enabled with the following command:
    - `ulimit -c`By default core dump files are disabled, in which case this command will return 0. To enable core dump files, use the following command:
    - `ulimit -c unlimited` The unlimited argument refers to the core dump file size. By effectively removing a file size limit, we prevent the file from being truncated and from losing out on any useful information.

2. (Linux only step) Locate and open the following files in a text editor:
    - /etc/init.d/asperacentral
    - /etc/init.d/asperahttpd
    - /etc/init.d/asperanoded
    - /etc/init.d/asperawatchd
    -  Find the DAEMON_COREFILE_LIMIT setting. If it is set to a limited value like 5000:
    - DAEMON_COREFILE_LIMIT=5000
    - Replace it with the following line:
    - DAEMON_COREFILE_LIMIT=unlimited

3. To test that your core dump files can be generated, send an abort signal to an Aspera process such as asperanoded. You can do so by looking up the process ID ofasperanoded and then sending a kill signal, such as with the following commands:
    - `pgrep asperanoded`
    - `kill -SIGQUIT process_ID`

4. On Linux, the core dump file is generally found in the location defined by the core_pattern file, which can be viewed with the following command:
    - `cat /proc/sys/kernel/core_pattern` If the file pipes output to another program (if there is aasperanoded in front), or if the core dump files are being saved to the directory of the process (which may not be writeable), you can change the location. For example, with the following command you can save core dump files to the tmp directory, with files named core_processName_processID: `/cores/core.X`