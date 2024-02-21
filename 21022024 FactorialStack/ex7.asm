	AREA factstack , CODE , READONLY 
	LDR r0,=0x40000000
	LDR r1,[r0]
	MOV r2,#1
	bl lpush
	STR r2,[r0]
l	b l
lpush
	SUB sp,sp,#8
	STR lr,[sp,#4]
	STR r1,[sp]
	CMP r1,#1
	bgt loop
	b lpop
loop 
	SUB r1,r1,#1
	bl lpush
lpop
	LDR r1,[sp]
	LDR lr,[sp,#4]
	ADD sp,sp,#8
	CMP r1,#0
	MUL r2,r1,r2
	MOV pc,lr
	END