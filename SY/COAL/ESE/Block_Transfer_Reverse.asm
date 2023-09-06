; transfer block of size 10 from C000 to C009 to C003 to C00C

mvi b, 10
lxi h, 49161
lxi d, 49164


repeat: mov a, m
stax d
dcx h
dcx d
dcr b
jnz repeat
hlt