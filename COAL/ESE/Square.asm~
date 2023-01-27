; Program to find the square of given number
; the code reads a 8-bit number from memory location C000 and stores the square at locations C001 and C002
LDA 49152
LXI H, 00
MVI D, 00
MOV E, A
MVI B, 08
REPEAT: DAD H
RAL 
JNC SKIP
DAD D
SKIP: DCR B
JNZ REPEAT
SHLD 49153 
HLT