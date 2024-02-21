	AREA rootexp,CODE,READONLY ; b^2 - 4ac 
	LDR r0,=0x40000000 
	LDM r0,{r1-r3}
	MUL r4,r2,r2
	LSL r1,#2
	MUL r5,r1,r3
	SUB r6,r4,r5
	STR r6,[r0,#0x0c]
l	b l
	END