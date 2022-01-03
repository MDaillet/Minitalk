# Minitalk

42 project about Unix Signals. The goal is to send a string from a client to a server using only two signals : SIGUSR1 and SIGUSR2. You will have to use binary conversion and sigaction, a Linux signal managing library, to succeed with the best performances.

This project was very interesting for three reasons :
  --> Bitwise operations to decode the binary string and reconstruct each characters.
  --> Unix signals as a way of communication between processes.
  --> And also UTF-32 encoding, and the reasons why 8 bytes wasn't enough anymore.

![Minitalk](https://user-images.githubusercontent.com/55747965/147948534-c5aa97af-66fc-4697-ab1a-ee0492227931.gif)
