	AREA linearsearch,CODE,READONLY 
	mov r0,#4
	ldr r1,=0x40000000
	ldr r2,=0x4000000c
	bl ls
	b done
ls
	push{lr}
	mov r3,#-1
searchloop
	add r3,r3,#1
	cmp r3,r0
	bge nf
	ldr r4,[r1,r3,lsl#2]
	cmp r4,r2
	bne searchloop 
	pop{lr}
	bx lr
nf
	mov r3,#-1
	pop {lr}
	bx lr
done
	end