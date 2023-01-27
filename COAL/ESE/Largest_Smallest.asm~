; First we will read the size of array from location C000
; then we will store the minimum just after end of array and maximum after that

; First we find the minimum
LDA 49152
MOV B, A
LXI H, 49153
MVI A, 255
; Loop for minium
LOOP_MX: CMP M
JC SKIP_MX
MOV A, M
SKIP_MX: INX H
DCR B
JNZ LOOP_MX
MOV M, A


; Code for maximum
LDA 49152
MOV B, A
LXI H, 49153
MVI A, 0
; Loop for minium
LOOP_MN: CMP M
JNC SKIP_MN
MOV A, M
SKIP_MN: INX H
DCR B
JNZ LOOP_MN
INX H
MOV M, A
HLT