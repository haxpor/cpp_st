	.file	"main.cpp"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1662:
	.cfi_startproc
	endbr64
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1662:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Widget2::Foo()"
	.text
	.p2align 4
	.globl	_ZN7Widget23FooEv
	.type	_ZN7Widget23FooEv, @function
_ZN7Widget23FooEv:
.LFB1906:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$14, %edx
	leaq	.LC0(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	_ZSt4cout(%rip), %rax
	leaq	_ZSt4cout(%rip), %rdx
	movq	-24(%rax), %rax
	movq	240(%rdx,%rax), %rbp
	testq	%rbp, %rbp
	je	.L9
	cmpb	$0, 56(%rbp)
	je	.L5
	movsbl	67(%rbp), %esi
.L6:
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo3putEc@PLT
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movq	%rax, %rdi
	jmp	_ZNSo5flushEv@PLT
	.p2align 4,,10
	.p2align 3
.L5:
	.cfi_restore_state
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	movl	$10, %esi
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L6
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L6
.L9:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE1906:
	.size	_ZN7Widget23FooEv, .-_ZN7Widget23FooEv
	.section	.rodata.str1.1
.LC1:
	.string	"Widget:Foo()"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1908:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$12, %edx
	leaq	.LC1(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@PLT
	call	_ZN7Widget23FooEv
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1908:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__ZN7Widget23FooEv, @function
_GLOBAL__sub_I__ZN7Widget23FooEv:
.LFB2389:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2389:
	.size	_GLOBAL__sub_I__ZN7Widget23FooEv, .-_GLOBAL__sub_I__ZN7Widget23FooEv
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN7Widget23FooEv
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
