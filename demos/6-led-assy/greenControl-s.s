	.arch msp430g2553
	.p2align 1,0
	.text


	.global greenControl
	.extern P1OUT

greenControl:
	cmp #0, r12
	jz off
	bis #1, &P1OUT		;or. Fixed bits by changing 64 to 1 since green is P1.0
	pop r0
off:	and #0, &P1OUT
	pop r0
