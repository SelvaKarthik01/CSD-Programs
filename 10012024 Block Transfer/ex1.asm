	AREA sam,CODE,READONLY
	LDR r0,=0x40000000;
	LDR r1,=0x40000050;
	LDR r2,[r0],#0x4;
L	LDR r3,[r0],#0x4;
	STR r3,[r1],#0x4;
	SUBS r2,r2,#01;
	BNE L
	end
	