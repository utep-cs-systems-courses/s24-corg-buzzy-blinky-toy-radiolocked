	.arch msp430g2553
	.p2align 1,0
	.text

	.global let_init
	.global led_update
	.extern P1OUT

	.data			;initialize variables
red_on:
	.byte 0
green_on:
	.byte 0
led_changed:
	.byte 0
redVal:
	.byte 0
	.byte LED_RED
greenVAL:
	.byte 0
	.byte LED_GREEN

	;; Functions start here;;
led_init:
	bis &LEDS, &P1DIR
	mov #1, &led_changed
	call #led_update
	ret
	
led_update:
	cmp #0, &led_changed 	;if led_changed is 0, then jump to do nothing
	jnz end_led_update

	mov.b &redVal, r12	;move the address to r12
	add.b #red_on, r12	;add to r12 to access the selected element based on red_on(0/1)
	mov.b &greenVal, r13	;do the same thing for greenVal
	add.b #green_on, r13
	bis.b r13, r12		;Or gate for both values
	mov.b r12, &ledFlags

	mov.b #0xFF, r14	;loads 0xFF into r14
	xor.b &LEDS, r14	;XOR with leds
	bis.b r12, r14		;Or r14 with r12
	and.b r14, &P1OUT	;and P1OUT with r14

	bis.b r12, &P1OUT	;or P1OUT with r12

	mov.b #0, &led_changed
	
end_led_update:
	ret
