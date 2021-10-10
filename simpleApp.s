	.file	"simpleApp.cpp"
	.text
	.section	.text._ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.type	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, @function
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB870:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movq	%rdx, %r15
	movq	%rsi, %rdx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	movq	8(%rdi), %rcx
	movq	(%rdi), %rbp
	movq	%rcx, %rax
	subq	%rbp, %rdx
	subq	%rbp, %rax
	sarq	$2, %rax
	je	.L10
	leaq	(%rax,%rax), %rdi
	movq	$-4, %r14
	cmpq	%rdi, %rax
	jbe	.L17
.L3:
	movq	%r14, %rdi
	movq	%rdx, 16(%rsp)
	movq	%rcx, 8(%rsp)
	call	_Znwm
	movq	16(%rsp), %rdx
	movq	8(%rsp), %rcx
	movq	%rax, %r13
	addq	%rax, %r14
.L4:
	movl	(%r15), %eax
	movq	%rcx, %r8
	leaq	4(%r13,%rdx), %r9
	subq	%r12, %r8
	movl	%eax, 0(%r13,%rdx)
	leaq	(%r9,%r8), %r15
	cmpq	%rbp, %r12
	je	.L5
	movq	%rbp, %rsi
	movq	%r13, %rdi
	movq	%r9, 24(%rsp)
	movq	%r8, 16(%rsp)
	movq	%rcx, 8(%rsp)
	call	memmove
	movq	8(%rsp), %rcx
	movq	16(%rsp), %r8
	movq	24(%rsp), %r9
	cmpq	%rcx, %r12
	je	.L9
.L6:
	movq	%r8, %rdx
	movq	%r12, %rsi
	movq	%r9, %rdi
	call	memcpy
.L8:
	testq	%rbp, %rbp
	jne	.L9
.L7:
	movq	%r13, (%rbx)
	movq	%r15, 8(%rbx)
	movq	%r14, 16(%rbx)
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L9:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZdlPv
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L17:
	movabsq	$4611686018427387903, %rax
	cmpq	%rax, %rdi
	ja	.L3
	xorl	%r14d, %r14d
	xorl	%r13d, %r13d
	testq	%rdi, %rdi
	je	.L4
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L5:
	cmpq	%rcx, %r12
	jne	.L6
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L10:
	movl	$1, %edi
.L2:
	leaq	0(,%rdi,4), %r14
	jmp	.L3
	.cfi_endproc
.LFE870:
	.size	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, .-_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"0"
.LC1:
	.string	"1"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.section	.text.startup,"ax",@progbits
.LHOTB2:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB835:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA835
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	xorl	%esi, %esi
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$56, %rsp
	.cfi_def_cfa_offset 80
	leaq	12(%rsp), %rdx
	leaq	16(%rsp), %rdi
	movq	$0, 16(%rsp)
	movq	$0, 24(%rsp)
	movq	$0, 32(%rsp)
	movl	$1, 12(%rsp)
.LEHB0:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	movl	$2, 12(%rsp)
	movq	24(%rsp), %rsi
	cmpq	32(%rsp), %rsi
	je	.L19
	movl	$2, (%rsi)
	addq	$4, %rsi
	movq	%rsi, 24(%rsp)
.L20:
	xorl	%ebx, %ebx
	cmpq	16(%rsp), %rsi
	je	.L24
	.p2align 4,,10
	.p2align 3
.L21:
	movl	$.LC0, %edi
	call	puts
	movq	24(%rsp), %rax
	subq	16(%rsp), %rax
	addq	$1, %rbx
	sarq	$2, %rax
	cmpq	%rbx, %rax
	ja	.L21
	movl	%eax, %ebp
	testl	%eax, %eax
	jle	.L24
	xorl	%ebx, %ebx
	.p2align 4,,10
	.p2align 3
.L25:
	movl	$.LC1, %edi
	call	puts
	addl	$1, %ebx
	cmpl	%ebx, %ebp
	jne	.L25
.L24:
	movq	16(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L35
	call	_ZdlPv
.L35:
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L19:
	.cfi_restore_state
	leaq	12(%rsp), %rdx
	leaq	16(%rsp), %rdi
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE0:
	movq	24(%rsp), %rsi
	jmp	.L20
.L29:
	movq	%rax, %rbx
	jmp	.L26
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA835:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE835-.LLSDACSB835
.LLSDACSB835:
	.uleb128 .LEHB0-.LFB835
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L29-.LFB835
	.uleb128 0
.LLSDACSE835:
	.section	.text.startup
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDAC835
	.type	main.cold.20, @function
main.cold.20:
.LFSB835:
.L26:
	.cfi_def_cfa_offset 80
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	movq	16(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L27
	call	_ZdlPv
.L27:
	movq	%rbx, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
	.cfi_endproc
.LFE835:
	.section	.gcc_except_table
.LLSDAC835:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC835-.LLSDACSBC835
.LLSDACSBC835:
	.uleb128 .LEHB1-.LCOLDB2
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSEC835:
	.section	.text.unlikely
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold.20, .-main.cold.20
.LCOLDE2:
	.section	.text.startup
.LHOTE2:
	.ident	"GCC: (GNU) 8.3.1 20191121 (Red Hat 8.3.1-5)"
	.section	.note.GNU-stack,"",@progbits
