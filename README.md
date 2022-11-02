# PIC Microcontroller

## Controller Used
- PIC16F877A

### PIC16F(PIC16F877A) Peripherals

- GPIO's (PORTA, B, C, D, E)
- ADC
- External Interrupt
- PWM
- Timers
- EEPROM
- Communication Protocols - USART, I2C, SPI

  #### Port Structure and Pin Layout
  
  - PIN#11/32 - VDD - 5 v( Power pin)
  - PIN#12/31 - Vss - GND (Ground pin)
  - PIN13 - OSC1/CLK1 (External Crystal oscillator)
  - PIN14 - OSC2/CLK2 (External Crystal oscialator)
  - PORTA = 6 Pins (RA0 to RA5) - PIN#2 to PIN#7
  - PORTB = 8 Pins (RB0 to RB7) - PIN#33 to PIN#40
  - PORTC = 8 Pins (RC0 to RC7) - PIN#15 to PIN#18 & PIN#23 to PIN#26
  - PORTD = 8 Pins (RD0 to RD7) - PIN#19 to PIN#22 & PIN#27 to PIN#30
  - PORTE = 3 Pins (RE0 to RE2) - PIN#8 to PIN#10

### GPIO 

#### GPIO Structure

| 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | = here, total 8bits structure because pic16f is a 8bit.

- Here, 0th bit to 3rd bit called LSB and 4th to 7th bit called MSB

#### GPIO Registers

- TRISx - 8bit register used to indicate the direction of the pin Input/Output.
- x = PORTA to PORTE
- 1 = Input, 0 = Output

- PORTx - 8bit register used to write or read the state of the pin (HIGH/LOW).
- x = PORTA to PORTE
- 1 = HIGH,0 = LOW.

