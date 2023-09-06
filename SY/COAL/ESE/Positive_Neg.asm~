; all +ve stored from C100, -ve from C200, and 0s from C300

; First find all positive numbers
lda 49152
mov b, a
lxi h, 49153
lxi d, 49408
mvi c, 0

repeat: mov a, m
ani 128
jnz skip
mov a, m
stax d
inx d
inr c
skip: inx h
dcr b
jnz repeat
mov a, c
sta 49407

; Find all negative numbers
lda 49152
mov b, a
lxi h, 49153
lxi d, 49665
mvi c, 0

repeat2: mov a, m
ani 128
jz skip2
mov a, m
stax d
inx d
inr c
skip2: inx h
dcr b
jnz repeat2
mov a, c
sta 49664

; Find all zero numbers
lda 49152
mov b, a
lxi h, 49153
lxi d, 49921
mvi c, 0

repeat3: mov a, m
ana a
jnz skip3
mov a, m
stax d
inx d
inr c
skip3: inx h
dcr b
jnz repeat3
mov a, c
sta 49920

hlt