	AREA binary , CODE , READONLY 
	
	LDR r0,= 0x40000000 ;
	MOV r13,#0x00 ;
	LDRB r1,[r0] ;
	LDRB r2,[r0,#0x01]! ;
	MOV r3 ,#0x00 ;
	MOV r4,r1 ;
	
rep CMP r3,r4
	BGT exit 
	ADD r5,r3,r4
	LSR r5,#0x01 
	LDRB r7,[r0,r5]
	CMP r7,r2
	BGE HE
	ADD r3,r5,#0x01 ;
	B rep
	
HE 	BEQ found 
	SUB r4,r5,#0x01 
	B rep

found	MOV r13,#0x11
exit
L	B L
	END
