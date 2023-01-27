; Sort ascending
lda 49152
mov b, a
dcr b
loop: mov c, b
lxi H, 49153
repeat: mov a, m
inx h
cmp m
jc skip
mov d, m
mov m, a
dcx h
mov m, d
inx h
skip: dcr c
jnz repeat
dcr b
jnz loop
hlt

; Sort descending
lda 49152
mov b, a
dcr b
loop1: mov c, b
lxi H, 49153
repeat1: mov a, m
inx h
cmp m
jnc skip1
mov d, m
mov m, a
dcx h
mov m, d
inx h
skip1: dcr c
jnz repeat1
dcr b
jnz loop1
hlt