LXI B, 0000
LHLD 0002
XCHG
LHLD 0000
MOV A, L
LOOP: SUB E
MOV L, A
MOV A, H
SBB D
MOV H, A
MOV A, L
JC SKIP
INX B
JMP LOOP
SKIP: DAD D
SHLD 0006
MOV L, C
MOV H, B
SHLD 0004
HLT