# ConstexprInRuntime

## GCC

## MSVC (2019)

* non-`constexpr` receiving variable from calling `constexpr` function

It won't optimize it, and will make a call to such function. Computation is not at compile time.

* `constexpr` for receiving variable from calling `constexpr` function

It optimizes it by compute at compile time, not making a function call. See from the following assembly code generated from it.
Try to search for `Compute` in which there is one occurrence, another is inline the result at the bottom.

```
$LN3:
	sub	rsp, 56					; 00000038H

; 11   : 	// for non-constexpr receiving variable from calling constexpr function
; 12   : 	int result1 = Compute(5);

	mov	ecx, 5
	call	?Compute@@YAHH@Z			; Compute
	mov	DWORD PTR result1$[rsp], eax

; 13   : 	std::cout << "result1: " << result1 << std::endl;		// just to not let it optimize code away

	lea	rdx, OFFSET FLAT:$SG33131
	lea	rcx, OFFSET FLAT:?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A ; std::cout
	call	??$?6U?$char_traits@D@std@@@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@PEBD@Z ; std::operator<<<std::char_traits<char> >
	mov	edx, DWORD PTR result1$[rsp]
	mov	rcx, rax
	call	??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QEAAAEAV01@H@Z ; std::basic_ostream<char,std::char_traits<char> >::operator<<
	lea	rdx, OFFSET FLAT:??$endl@DU?$char_traits@D@std@@@std@@YAAEAV?$basic_ostream@DU?$char_traits@D@std@@@0@AEAV10@@Z ; std::endl<char,std::char_traits<char> >
	mov	rcx, rax
	call	??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QEAAAEAV01@P6AAEAV01@AEAV01@@Z@Z ; std::basic_ostream<char,std::char_traits<char> >::operator<<

; 14   : 
; 15   : 	// for constexpr receiving variable from calling constexpr function
; 16   : 	constexpr int result2 = Compute(7);

	mov	DWORD PTR result2$[rsp], 17
```

## GCC

* non-`constexpr` receiving variable from calling `constexpr` function

GCC still optimizes it away even at optimization level default. It computes at compile time.

* `constexpr` for receiving variable from calling `constexpr` function

GCC optimizes it away starting from default optimization level.

# Conclusion

We cannot force `constexpr` function to compute in runtime but technically deep down compiler can decide
whether to do it or not as we see from the generated assembly code.
