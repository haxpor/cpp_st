# std::swap and std::vector::swap

From test result as looked into assembly code output `Vector.s`, I have seen the following
as compile flags also included `-g`.

```
    // std::swap
    Profile::Start();
 1b0:	e8 00 00 00 00       	call   1b5 <main+0x57>
    std::swap(v1, v2);
 1b5:	48 8d 55 d0          	lea    rdx,[rbp-0x30]
 1b9:	48 8d 45 b0          	lea    rax,[rbp-0x50]
 1bd:	48 89 d6             	mov    rsi,rdx
 1c0:	48 89 c7             	mov    rdi,rax
 1c3:	e8 00 00 00 00       	call   1c8 <main+0x6a>
    elapsed = Profile::End();
 1c8:	e8 00 00 00 00       	call   1cd <main+0x6f>
 1cd:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
    std::cout << "via std::swap : " << elapsed << "ms\n";
 1d1:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 1d8 <main+0x7a>
 1d8:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # 1df <main+0x81>
 1df:	e8 00 00 00 00       	call   1e4 <main+0x86>
 1e4:	48 89 c2             	mov    rdx,rax
 1e7:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 1eb:	48 89 c6             	mov    rsi,rax
 1ee:	48 89 d7             	mov    rdi,rdx
 1f1:	e8 00 00 00 00       	call   1f6 <main+0x98>
 1f6:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 1fd <main+0x9f>
 1fd:	48 89 c7             	mov    rdi,rax
 200:	e8 00 00 00 00       	call   205 <main+0xa7>

    // std::vector::swap
    Profile::Start();
 205:	e8 00 00 00 00       	call   20a <main+0xac>
    v1.swap(v2);
 20a:	48 8d 55 d0          	lea    rdx,[rbp-0x30]
 20e:	48 8d 45 b0          	lea    rax,[rbp-0x50]
 212:	48 89 d6             	mov    rsi,rdx
 215:	48 89 c7             	mov    rdi,rax
 218:	e8 00 00 00 00       	call   21d <main+0xbf>
    elapsed = Profile::End();
 21d:	e8 00 00 00 00       	call   222 <main+0xc4>
 222:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
    std::cout << "via std::vector::swap : " << elapsed << "ms\n";
 226:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 22d <main+0xcf>
 22d:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # 234 <main+0xd6>
 234:	e8 00 00 00 00       	call   239 <main+0xdb>
 239:	48 89 c2             	mov    rdx,rax
 23c:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 240:	48 89 c6             	mov    rsi,rax
 243:	48 89 d7             	mov    rdi,rdx
 246:	e8 00 00 00 00       	call   24b <main+0xed>
 24b:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 252 <main+0xf4>
 252:	48 89 c7             	mov    rdi,rax
 255:	e8 00 00 00 00       	call   25a <main+0xfc>

```

so it's safe to say that at least on Linux, use either `std::swap` or `std::vector::swap` to swap
between two `std::vector` produce the same performance output.
