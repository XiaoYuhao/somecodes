	.file	"float.c"
	.text
	.section	.rodata
.LC2:
	.string	"%f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -4(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	movss	-4(%rbp), %xmm0
	addss	-8(%rbp), %xmm0
	movss	%xmm0, -12(%rbp)
	cvtss2sd	-12(%rbp), %xmm0
	movl	$.LC2, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1078530000
	.align 4
.LC1:
	.long	1066536010
	.ident	"GCC: (GNU) 8.3.1 20191121 (Red Hat 8.3.1-5)"
	.section	.note.GNU-stack,"",@progbits
