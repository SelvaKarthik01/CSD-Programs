	AREA quadexp,CODE,READONLY ; ax^2 + bx + c
	
	LDR r0,=0x40000000
	LDM r0,{r1-r4} ;
	MOV r1,#0x3;
	MOV r2,#0x1;
	MOV r3,#0x1;
	MOV r4,#0x1;
	MUL r5,r1,r1 ;
	MUL r2,r5,r2 ;
	MUL r1,r3,r1 ;
	ADD r1,r1,r2 ;
	ADD r1,r1,r4 ;
	str r1,[r0,#0x10]
l	b l
	END