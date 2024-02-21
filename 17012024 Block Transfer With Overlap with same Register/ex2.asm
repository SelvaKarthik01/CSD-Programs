	AREA sam,CODE,READONLY 

	LDR r0, = 0x40000000 ;
	LDR r2,[r0],#0x4 ;
	ADD r3,r0,r2,LSL #2 ;
L	LDR r4,[r3,#-0x4] ;
	STR r4,[r3],#-0x4 ;
	subs r2,r2,#01 ;
	BNE L
l	B l
	END