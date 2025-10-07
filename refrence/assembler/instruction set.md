param codes
REG     specifies a register number EX:3
16V     specifies a 16-bit value EX: "11011001 10011100"
ADR     specifies a 16-bit memory address EX:"00100110 11011100"
R/A     means either a register number or a 16-bit mem address
R/V     means either a register number or a 16-bit value
LB:     specifies a label that corisponds to a memory address EX:GetKeyboardInput: 
Str     means a value used only for readability and does not effect program values
CHR     can be used in place of 16V and converts an ascii character to an 16-bit code EX:A equivelant:"00000000 01000001"
1/0     mean it only takes a "1" or a "0" EX:"1"
**#     specifies a binary number with length #

conversion codes
#**     hex code 16-bit
$**     decimal 16-Bit

binary symbols
# - instruction id
* - doesn't matter for instruction group



register/memory code:   010###00 00000000
SET REG, R/V            #set register REG to R/V                                        #id 000

INC REG                 #INCrement register REG by 1                                    #id 001
DEC REG                 #DECrement register REG by 1                                    #id 010

LOD R/A, REG            #LOaDS the value at address R/A to REG                          #id 011
STO R/A, REG            #STOres the value from REG to memory at R/A                     #id 100


math code:              011####0 00000000
ADD REG1, REG2, REG3    #ADDs the values of REG1 & REG2 then stores it to REG3          #id 0000
SUB REG1, REG2, REG3    #SUBtracts the values of REG1 & REG2 then stores it to REG3     #id 0001
MUL REG1, REG2, REG3    #MULtiplies the values of REG1 & REG2 then stores it to REG3    #id 0010
DIV REG1, REG2, REG3    #DIVides the values of REG1 & REG2 then stores it to REG3       #id 0011

SHL REG1, REG2          #SHifts the value of REG1 Left then stores it to REG2           #id 0100
SHR REG1, REG2          #SHifts the value of REG1 Right then stores it to REG2          #id 0101

NOT REG1, REG2          #inverts the value of REG1 then stores it in REG2               #id 0110
AND REG1, REG2, REG3                                                                    #id 0111
 OR REG1, REG2, REG3                                                                    #id 1000
XOR REG1, REG2, REG3                                                                    #id 1001


jump related code:      00###000 00000000
JMZ R/A1, R/A2 OR       #JumP to instruction R/A2 if R/A1 equals Zero                   #id 000
JMZ R/A, LB:            #JumP to LB: if R/A equals Zero

JPE R/A1, R/A2, R/A3 OR #JumP to R/A3 if R/A1 & R/A2 are Equal                          #id 001
JPE R/A1, R/A2, LB:     #JumP to LB: if R/A1 & R/A2 are Equal

JMP R/A OR              #JuMPs to R/A                                                   #id 010
JMP LB:                 #JuMPs to LB:

EXS Str                 #Starts an EXecution block with id Str                          #id 100
EXE Str                 #Ends an EXecution block with id Str                            #id 101
EXC Str                 #runs an EXeCution block with id Str then returns               #id 110


input code:             10*##$00 ********
IMD 1/0                 #sets the Input MoDe 1=ascii keys 0=u/d/l/r/z/x/e/s             #id 00      $1/0
SIP R/A                 #Sets the register or mem address to the InPut byte             #id 01      $R/A


output:                 11*##$00 ********
DSM 1/0                 #sets the DisPlay Mode 1=graphics 0=ascii                       #id 00      $1/0
VRR R/A                 #Reads the VRam value at R/A                                    #id 01      $R/A
VRW R/A                 #Writes to the VRam address at R/A                              #id 10      $R/A

misc:                   1**##*** ********              
HALT                    #kills the cpu                                                  #id 11

0000011000110001 0000110010110001       #jmp 3, 1, #0ca1 

bit1  - 1I/O/misc \ 0other                          #i/o or other codes
bit2  - output1/input0 \ reg/math1 \ jmp0           #((if b1 is 1) input or output) or ((if b1 is 0)reg/math or jmp codes)
bit3  - math1/reg0                                  #((if b1 is 0)and(if b2 is 1) math or reg code) or if in jmp mode instruction id
bit4  - #                                           #instruction id
bit5  - #                                           #instruction id
bit6  - param r1/val0;1 \ mid                       #if in math/reg mode this becomes an instruction id
bit7  - param r1/val0;2 \ mid                       #if in math mode this becomes an instruction id, if in reg mode the 1st param
bit8  - param r1/val0;3                             #the 3rd jump param or the second register param id

bit9  - regid11 /
bit10 - regid12 /
bit11 - regid13 /
bit12 - regid14 /
bit13 - regid21 /
bit14 - regid22 /
bit15 - regid23 /
bit16 - regid24 /