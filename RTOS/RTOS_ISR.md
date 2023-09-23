### ISR
- ISR should be small in size.
- We cannot pass any argument to ISR and ISR cannot return any value because we dont call ISR in any function it is called by interrupt handler at any time so how we can pass argument to it and how can we utilize the return value from it, so it is having void as argument and void as return type.
- Generally we dont want to use `printf` since it is not valid for reenterant also ISR is supposed to be short but `printf` take so much time. `printf` is not thead safe and uses dynamica allocation which take lot of time and affect the speed of ISR upto great extent.
- We cannot put the breakpoint in ISR but i think we can only set breakpoint where hardware is emulated. Since during the process of ISR it occupy CPU resource.
- When handlng the interrupt we devide the routine into two halves `top half` will respond queckly and `bottom half` which will continue to handle interrupt.
- Message queue cannot be use to send message from ISR to task.
- ISR should be keep small because when ISR is serving other interrupt will be lost and you may miss data if it is too long and if the nesting of interrupt is not supported.
- Traditional design method is to have very short ISR that capture data and push to an event queue. All processing in the main loop. This gives short latancy and faster response and reduce the risk if ISR depending on each other.

### Interrupt Latency
- It is the number of clock cycle that is taken by the processor to respond to an interrupt request. These no. of clock cycle is count b/w the assertion of the interrupt request and first instruction of the interrupt handler.

### measure interrupt latency
- With the help of ossiloscpoce.
- First take two GPIO pin. Configure one GPIO pin to generate the interrupt and second for toggling.
- Monitor the pin using ossciloscop or analyzer which you have configured to generate interrupt and also monitor the second pin whihc is toggled at the begining of the interrupt service routine.
- We can reduce the interrupt latancy by reducing the ISR size and avoid to calling a function within the ISR.

### cause of interrupt latency
- The first delay is caused by hardware. The interrupt signal needs to be synchronized to the cpu clock.Depending upon the synchronization logic upto 3 cycle may expire before the interrupt request has reached the CPU core.
- CPU perform a mode switch pr pushes register to the stack. Morden CPU such as ARM generally perform a mode switch. Which takes fewer CPU cycles then saving registers.
- If the interrupt request signal comes from outside of the processor device, the signal must be firstly synchronized to the bus/peripheral clock.
- The RTOS may temporarily disable the interrupts when accessing critical resources. The latency is longer if the interrupt request asserts during the interrupt is disabled
- Some processor architectures need additional software statements to select the right ISR.
- For most processor architectures, the processor usually completes the current instruction, which
may be a multi-cycle instruction.
- To save the current scene to restore the states when returning from the ISR, the processor pushes
various necessary core registers (usually the program counter, flag registers, linker register, and
so on) to the stack.
- Yes we can call function in the ISR but it is not recommondate becaue it can increase interrupt latency and decrease the performance of the system.The function wich is called from ISR should be re-enterant other wise it can create the issue.
- In nested interrupt system low priority ISR can be pre-empted by high priority ISR. The same priority ISR must be executed by time order.

- Pipeline fill: Most morden CPU are piplined. The mode switch flush the pipeline a few extra cycles are required to refill the pipeline.
- 

