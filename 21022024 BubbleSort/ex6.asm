	AREA bubble , CODE , READONLY ;
	LDR r0,=0x40000000
	LDR r1 , [r0] ; No. of Elements
	
Outer 
l	MOV r2 ,r1 ; Inner looping  variable 
	LDR r0,=0x40000004
Inner 
	LDR r4,[r0]
	LDR r5,[r0,#4]!
	CMP r4,r5 
	BLE Continue
	STR r4,[r0]
	STR r5,[r0,#-0x04]
Continue
	SUBS r2,r2,#1 
	BNE Inner
		SUBS r1,r1,#1
	BNE Outer 
		B l
	END
	
	
	