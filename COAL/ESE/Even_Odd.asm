; all even numbers stored from memory location C100 and odd from memory location C200

; First find all even numbers
lda 49152
mov b, a
lxi h, 49153
lxi d, 49408
mvi c, 0

repeat: mov a, m
ani 1
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


lda 49152
mov b, a
lxi h, 49153
lxi d, 49665
mvi c, 0

repeat2: mov a, m
ani 1
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

hlt