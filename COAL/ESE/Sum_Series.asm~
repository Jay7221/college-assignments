; We will iterate over the whole array to find the sum
; Here DE pair will store the address of current element
; HL pair will store the sum, we will assume that sum fits in a 16-bit integer

lxi d, 49152
lxi h, 00
ldax d
inx d
mov b, a

; loop
repeat: ldax d
inx d
;add a to hl pair
add l
mov l, a
mvi a, 00
adc h
mov h, a
dcr b
jnz repeat
mov a, l
stax d
inx d
mov a, h
stax d
hlt