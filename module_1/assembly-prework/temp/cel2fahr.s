	.file	"cel2fahr.c"
	.text
	.globl	cel2fahr
	.type	cel2fahr, @function
cel2fahr:
.LFB0:
	.cfi_startproc
	endbr64
	mulsd	.LC0(%rip), %xmm0
	addsd	.LC1(%rip), %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	cel2fahr, .-cel2fahr
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	-858993459
	.long	1073532108
	.align 8
.LC1:
	.long	0
	.long	1077936128
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
