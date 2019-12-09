
VectorSwap.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z8PrintAllRKSt6vectorIiSaIiEE>:
};

std::chrono::steady_clock::time_point Profile::gProfile_startTime;

void PrintAll(const std::vector<int>& v)
{
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 40          	sub    rsp,0x40
   8:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
   c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  13:	00 00 
  15:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  19:	31 c0                	xor    eax,eax
    for (const auto& e : v)
  1b:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  1f:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  23:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  27:	48 89 c7             	mov    rdi,rax
  2a:	e8 00 00 00 00       	call   2f <_Z8PrintAllRKSt6vectorIiSaIiEE+0x2f>
  2f:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
  33:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  37:	48 89 c7             	mov    rdi,rax
  3a:	e8 00 00 00 00       	call   3f <_Z8PrintAllRKSt6vectorIiSaIiEE+0x3f>
  3f:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
  43:	48 8d 55 e0          	lea    rdx,[rbp-0x20]
  47:	48 8d 45 d8          	lea    rax,[rbp-0x28]
  4b:	48 89 d6             	mov    rsi,rdx
  4e:	48 89 c7             	mov    rdi,rax
  51:	e8 00 00 00 00       	call   56 <_Z8PrintAllRKSt6vectorIiSaIiEE+0x56>
  56:	84 c0                	test   al,al
  58:	74 3f                	je     99 <_Z8PrintAllRKSt6vectorIiSaIiEE+0x99>
  5a:	48 8d 45 d8          	lea    rax,[rbp-0x28]
  5e:	48 89 c7             	mov    rdi,rax
  61:	e8 00 00 00 00       	call   66 <_Z8PrintAllRKSt6vectorIiSaIiEE+0x66>
  66:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
    {
        std::cout << e << ' ';
  6a:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  6e:	8b 00                	mov    eax,DWORD PTR [rax]
  70:	89 c6                	mov    esi,eax
  72:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # 79 <_Z8PrintAllRKSt6vectorIiSaIiEE+0x79>
  79:	e8 00 00 00 00       	call   7e <_Z8PrintAllRKSt6vectorIiSaIiEE+0x7e>
  7e:	be 20 00 00 00       	mov    esi,0x20
  83:	48 89 c7             	mov    rdi,rax
  86:	e8 00 00 00 00       	call   8b <_Z8PrintAllRKSt6vectorIiSaIiEE+0x8b>
    for (const auto& e : v)
  8b:	48 8d 45 d8          	lea    rax,[rbp-0x28]
  8f:	48 89 c7             	mov    rdi,rax
  92:	e8 00 00 00 00       	call   97 <_Z8PrintAllRKSt6vectorIiSaIiEE+0x97>
  97:	eb aa                	jmp    43 <_Z8PrintAllRKSt6vectorIiSaIiEE+0x43>
    }
    std::cout << std::endl;
  99:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # a0 <_Z8PrintAllRKSt6vectorIiSaIiEE+0xa0>
  a0:	48 89 c6             	mov    rsi,rax
  a3:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # aa <_Z8PrintAllRKSt6vectorIiSaIiEE+0xaa>
  aa:	e8 00 00 00 00       	call   af <_Z8PrintAllRKSt6vectorIiSaIiEE+0xaf>
}
  af:	90                   	nop
  b0:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  b4:	64 48 33 04 25 28 00 	xor    rax,QWORD PTR fs:0x28
  bb:	00 00 
  bd:	74 05                	je     c4 <_Z8PrintAllRKSt6vectorIiSaIiEE+0xc4>
  bf:	e8 00 00 00 00       	call   c4 <_Z8PrintAllRKSt6vectorIiSaIiEE+0xc4>
  c4:	c9                   	leave  
  c5:	c3                   	ret    

00000000000000c6 <_Z5Add1MRSt6vectorIiSaIiEEb>:

void Add1M(std::vector<int>& v, bool reverse=false)
{
  c6:	55                   	push   rbp
  c7:	48 89 e5             	mov    rbp,rsp
  ca:	48 83 ec 20          	sub    rsp,0x20
  ce:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
  d2:	89 f0                	mov    eax,esi
  d4:	88 45 e4             	mov    BYTE PTR [rbp-0x1c],al
  d7:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  de:	00 00 
  e0:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  e4:	31 c0                	xor    eax,eax
    if (reverse)
  e6:	80 7d e4 00          	cmp    BYTE PTR [rbp-0x1c],0x0
  ea:	74 2c                	je     118 <_Z5Add1MRSt6vectorIiSaIiEEb+0x52>
    {
        for (int i=1e+8; i>=0; --i)
  ec:	c7 45 f4 00 e1 f5 05 	mov    DWORD PTR [rbp-0xc],0x5f5e100
  f3:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
  f6:	85 c0                	test   eax,eax
  f8:	78 4d                	js     147 <_Z5Add1MRSt6vectorIiSaIiEEb+0x81>
        {
            v.emplace_back(i);
  fa:	48 8d 55 f4          	lea    rdx,[rbp-0xc]
  fe:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 102:	48 89 d6             	mov    rsi,rdx
 105:	48 89 c7             	mov    rdi,rax
 108:	e8 00 00 00 00       	call   10d <_Z5Add1MRSt6vectorIiSaIiEEb+0x47>
        for (int i=1e+8; i>=0; --i)
 10d:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
 110:	83 e8 01             	sub    eax,0x1
 113:	89 45 f4             	mov    DWORD PTR [rbp-0xc],eax
 116:	eb db                	jmp    f3 <_Z5Add1MRSt6vectorIiSaIiEEb+0x2d>
        }
    }
    else
    {
        for (int i=1; i<=1e+8; ++i)
 118:	c7 45 f4 01 00 00 00 	mov    DWORD PTR [rbp-0xc],0x1
 11f:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
 122:	3d 00 e1 f5 05       	cmp    eax,0x5f5e100
 127:	7f 1e                	jg     147 <_Z5Add1MRSt6vectorIiSaIiEEb+0x81>
        {
            v.emplace_back(i);
 129:	48 8d 55 f4          	lea    rdx,[rbp-0xc]
 12d:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 131:	48 89 d6             	mov    rsi,rdx
 134:	48 89 c7             	mov    rdi,rax
 137:	e8 00 00 00 00       	call   13c <_Z5Add1MRSt6vectorIiSaIiEEb+0x76>
        for (int i=1; i<=1e+8; ++i)
 13c:	8b 45 f4             	mov    eax,DWORD PTR [rbp-0xc]
 13f:	83 c0 01             	add    eax,0x1
 142:	89 45 f4             	mov    DWORD PTR [rbp-0xc],eax
 145:	eb d8                	jmp    11f <_Z5Add1MRSt6vectorIiSaIiEEb+0x59>
        }
    }
}
 147:	90                   	nop
 148:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 14c:	64 48 33 04 25 28 00 	xor    rax,QWORD PTR fs:0x28
 153:	00 00 
 155:	74 05                	je     15c <_Z5Add1MRSt6vectorIiSaIiEEb+0x96>
 157:	e8 00 00 00 00       	call   15c <_Z5Add1MRSt6vectorIiSaIiEEb+0x96>
 15c:	c9                   	leave  
 15d:	c3                   	ret    

000000000000015e <main>:

int main()
{
 15e:	55                   	push   rbp
 15f:	48 89 e5             	mov    rbp,rsp
 162:	53                   	push   rbx
 163:	48 83 ec 58          	sub    rsp,0x58
 167:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
 16e:	00 00 
 170:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
 174:	31 c0                	xor    eax,eax
    std::vector<int> v1;
 176:	48 8d 45 b0          	lea    rax,[rbp-0x50]
 17a:	48 89 c7             	mov    rdi,rax
 17d:	e8 00 00 00 00       	call   182 <main+0x24>
    std::vector<int> v2;
 182:	48 8d 45 d0          	lea    rax,[rbp-0x30]
 186:	48 89 c7             	mov    rdi,rax
 189:	e8 00 00 00 00       	call   18e <main+0x30>

    Add1M(v1);
 18e:	48 8d 45 b0          	lea    rax,[rbp-0x50]
 192:	be 00 00 00 00       	mov    esi,0x0
 197:	48 89 c7             	mov    rdi,rax
 19a:	e8 00 00 00 00       	call   19f <main+0x41>
    Add1M(v2, true);
 19f:	48 8d 45 d0          	lea    rax,[rbp-0x30]
 1a3:	be 01 00 00 00       	mov    esi,0x1
 1a8:	48 89 c7             	mov    rdi,rax
 1ab:	e8 00 00 00 00       	call   1b0 <main+0x52>

    long int elapsed;
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
    
    return 0;
 25a:	bb 00 00 00 00       	mov    ebx,0x0
    std::vector<int> v2;
 25f:	48 8d 45 d0          	lea    rax,[rbp-0x30]
 263:	48 89 c7             	mov    rdi,rax
 266:	e8 00 00 00 00       	call   26b <main+0x10d>
    std::vector<int> v1;
 26b:	48 8d 45 b0          	lea    rax,[rbp-0x50]
 26f:	48 89 c7             	mov    rdi,rax
 272:	e8 00 00 00 00       	call   277 <main+0x119>
 277:	89 d8                	mov    eax,ebx
}
 279:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
 27d:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
 284:	00 00 
 286:	74 2d                	je     2b5 <main+0x157>
 288:	eb 26                	jmp    2b0 <main+0x152>
 28a:	48 89 c3             	mov    rbx,rax
    std::vector<int> v2;
 28d:	48 8d 45 d0          	lea    rax,[rbp-0x30]
 291:	48 89 c7             	mov    rdi,rax
 294:	e8 00 00 00 00       	call   299 <main+0x13b>
    std::vector<int> v1;
 299:	48 8d 45 b0          	lea    rax,[rbp-0x50]
 29d:	48 89 c7             	mov    rdi,rax
 2a0:	e8 00 00 00 00       	call   2a5 <main+0x147>
 2a5:	48 89 d8             	mov    rax,rbx
 2a8:	48 89 c7             	mov    rdi,rax
 2ab:	e8 00 00 00 00       	call   2b0 <main+0x152>
}
 2b0:	e8 00 00 00 00       	call   2b5 <main+0x157>
 2b5:	48 83 c4 58          	add    rsp,0x58
 2b9:	5b                   	pop    rbx
 2ba:	5d                   	pop    rbp
 2bb:	c3                   	ret    

00000000000002bc <_Z41__static_initialization_and_destruction_0ii>:
 2bc:	55                   	push   rbp
 2bd:	48 89 e5             	mov    rbp,rsp
 2c0:	48 83 ec 10          	sub    rsp,0x10
 2c4:	89 7d fc             	mov    DWORD PTR [rbp-0x4],edi
 2c7:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi
 2ca:	83 7d fc 01          	cmp    DWORD PTR [rbp-0x4],0x1
 2ce:	75 32                	jne    302 <_Z41__static_initialization_and_destruction_0ii+0x46>
 2d0:	81 7d f8 ff ff 00 00 	cmp    DWORD PTR [rbp-0x8],0xffff
 2d7:	75 29                	jne    302 <_Z41__static_initialization_and_destruction_0ii+0x46>
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  //@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
 2d9:	48 8d 3d 00 00 00 00 	lea    rdi,[rip+0x0]        # 2e0 <_Z41__static_initialization_and_destruction_0ii+0x24>
 2e0:	e8 00 00 00 00       	call   2e5 <_Z41__static_initialization_and_destruction_0ii+0x29>
 2e5:	48 8d 15 00 00 00 00 	lea    rdx,[rip+0x0]        # 2ec <_Z41__static_initialization_and_destruction_0ii+0x30>
 2ec:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 2f3 <_Z41__static_initialization_and_destruction_0ii+0x37>
 2f3:	48 8b 05 00 00 00 00 	mov    rax,QWORD PTR [rip+0x0]        # 2fa <_Z41__static_initialization_and_destruction_0ii+0x3e>
 2fa:	48 89 c7             	mov    rdi,rax
 2fd:	e8 00 00 00 00       	call   302 <_Z41__static_initialization_and_destruction_0ii+0x46>
 302:	90                   	nop
 303:	c9                   	leave  
 304:	c3                   	ret    

0000000000000305 <_GLOBAL__sub_I__ZN7Profile18gProfile_startTimeE>:
 305:	55                   	push   rbp
 306:	48 89 e5             	mov    rbp,rsp
 309:	be ff ff 00 00       	mov    esi,0xffff
 30e:	bf 01 00 00 00       	mov    edi,0x1
 313:	e8 a4 ff ff ff       	call   2bc <_Z41__static_initialization_and_destruction_0ii>
 318:	5d                   	pop    rbp
 319:	c3                   	ret    

Disassembly of section .text._ZnwmPv:

0000000000000000 <_ZnwmPv>:
#endif // __cpp_sized_deallocation
#endif // __cpp_aligned_new

// Default placement versions of operator new.
_GLIBCXX_NODISCARD inline void* operator new(std::size_t, void* __p) _GLIBCXX_USE_NOEXCEPT
{ return __p; }
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
   c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  10:	5d                   	pop    rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000000EEE5countEv:

0000000000000000 <_ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000000EEE5countEv>:
	~duration() = default;
	duration& operator=(const duration&) = default;

	// 20.11.5.2 observer
	constexpr rep
	count() const
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
	{ return __r; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	48 8b 00             	mov    rax,QWORD PTR [rax]
   f:	5d                   	pop    rbp
  10:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono8durationIlSt5ratioILl1ELl1000000000EEEC1IlvEERKT_:

0000000000000000 <_ZNSt6chrono8durationIlSt5ratioILl1ELl1000000000EEEC1IlvEERKT_>:
	  constexpr explicit duration(const _Rep2& __rep)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
	  : __r(static_cast<rep>(__rep)) { }
   c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  10:	48 8b 10             	mov    rdx,QWORD PTR [rax]
  13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  17:	48 89 10             	mov    QWORD PTR [rax],rdx
  1a:	90                   	nop
  1b:	5d                   	pop    rbp
  1c:	c3                   	ret    

Disassembly of section .text._ZN7Profile5StartEv:

0000000000000000 <_ZN7Profile5StartEv>:
    inline static void Start()
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
        gProfile_startTime = std::chrono::steady_clock::now();
   4:	e8 00 00 00 00       	call   9 <_ZN7Profile5StartEv+0x9>
   9:	48 89 05 00 00 00 00 	mov    QWORD PTR [rip+0x0],rax        # 10 <_ZN7Profile5StartEv+0x10>
    }
  10:	90                   	nop
  11:	5d                   	pop    rbp
  12:	c3                   	ret    

Disassembly of section .text._ZN7Profile3EndEv:

0000000000000000 <_ZN7Profile3EndEv>:
    inline static long int End()
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   f:	00 00 
  11:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  15:	31 c0                	xor    eax,eax
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count();
  17:	e8 00 00 00 00       	call   1c <_ZN7Profile3EndEv+0x1c>
  1c:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
  20:	48 8d 45 e0          	lea    rax,[rbp-0x20]
  24:	48 8d 35 00 00 00 00 	lea    rsi,[rip+0x0]        # 2b <_ZN7Profile3EndEv+0x2b>
  2b:	48 89 c7             	mov    rdi,rax
  2e:	e8 00 00 00 00       	call   33 <_ZN7Profile3EndEv+0x33>
  33:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  37:	48 8d 45 e8          	lea    rax,[rbp-0x18]
  3b:	48 89 c7             	mov    rdi,rax
  3e:	e8 00 00 00 00       	call   43 <_ZN7Profile3EndEv+0x43>
  43:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  47:	48 8d 45 f0          	lea    rax,[rbp-0x10]
  4b:	48 89 c7             	mov    rdi,rax
  4e:	e8 00 00 00 00       	call   53 <_ZN7Profile3EndEv+0x53>
    }
  53:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
  57:	64 48 33 14 25 28 00 	xor    rdx,QWORD PTR fs:0x28
  5e:	00 00 
  60:	74 05                	je     67 <_ZN7Profile3EndEv+0x67>
  62:	e8 00 00 00 00       	call   67 <_ZN7Profile3EndEv+0x67>
  67:	c9                   	leave  
  68:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEE12_Vector_implD2Ev:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEE12_Vector_implD1Ev>:
	  _M_copy_data(__x);
	  __x._M_copy_data(__tmp);
	}
      };

      struct _Vector_impl
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSt12_Vector_baseIiSaIiEE12_Vector_implD1Ev+0x18>
  18:	90                   	nop
  19:	c9                   	leave  
  1a:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEEC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEEC1Ev>:
      allocator_type
      get_allocator() const _GLIBCXX_NOEXCEPT
      { return allocator_type(_M_get_Tp_allocator()); }

#if __cplusplus >= 201103L
      _Vector_base() = default;
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSt12_Vector_baseIiSaIiEEC1Ev+0x18>
  18:	90                   	nop
  19:	c9                   	leave  
  1a:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEEC2Ev:

0000000000000000 <_ZNSt6vectorIiSaIiEEC1Ev>:

      /**
       *  @brief  Creates a %vector with no elements.
       */
#if __cplusplus >= 201103L
      vector() = default;
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSt6vectorIiSaIiEEC1Ev+0x18>
  18:	90                   	nop
  19:	c9                   	leave  
  1a:	c3                   	ret    

Disassembly of section .text._ZNSt6chronomiINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE:

0000000000000000 <_ZNSt6chronomiINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE>:
	return __time_point(__lhs.time_since_epoch() -__rhs);
      }

    template<typename _Clock, typename _Dur1, typename _Dur2>
      constexpr typename common_type<_Dur1, _Dur2>::type
      operator-(const time_point<_Clock, _Dur1>& __lhs,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
   c:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
  10:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  17:	00 00 
  19:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  1d:	31 c0                	xor    eax,eax
		const time_point<_Clock, _Dur2>& __rhs)
      { return __lhs.time_since_epoch() - __rhs.time_since_epoch(); }
  1f:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
  23:	48 89 c7             	mov    rdi,rax
  26:	e8 00 00 00 00       	call   2b <_ZNSt6chronomiINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE+0x2b>
  2b:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
  2f:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  33:	48 89 c7             	mov    rdi,rax
  36:	e8 00 00 00 00       	call   3b <_ZNSt6chronomiINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE+0x3b>
  3b:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  3f:	48 8d 55 f0          	lea    rdx,[rbp-0x10]
  43:	48 8d 45 e8          	lea    rax,[rbp-0x18]
  47:	48 89 d6             	mov    rsi,rdx
  4a:	48 89 c7             	mov    rdi,rax
  4d:	e8 00 00 00 00       	call   52 <_ZNSt6chronomiINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE+0x52>
  52:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
  56:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  5d:	00 00 
  5f:	74 05                	je     66 <_ZNSt6chronomiINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE+0x66>
  61:	e8 00 00 00 00       	call   66 <_ZNSt6chronomiINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEES6_EENSt11common_typeIJT0_T1_EE4typeERKNS_10time_pointIT_S8_EERKNSC_ISD_S9_EE+0x66>
  66:	c9                   	leave  
  67:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono13duration_castINS_8durationIlSt5ratioILl1ELl1000000EEEElS2_ILl1ELl1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE:

0000000000000000 <_ZNSt6chrono13duration_castINS_8durationIlSt5ratioILl1ELl1000000EEEElS2_ILl1ELl1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE>:
      duration_cast(const duration<_Rep, _Period>& __d)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
	return __dc::__cast(__d);
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSt6chrono13duration_castINS_8durationIlSt5ratioILl1ELl1000000EEEElS2_ILl1ELl1000000000EEEENSt9enable_ifIXsrNS_13__is_durationIT_EE5valueES8_E4typeERKNS1_IT0_T1_EE+0x18>
      }
  18:	c9                   	leave  
  19:	c3                   	ret    

Disassembly of section .text._ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000EEE5countEv:

0000000000000000 <_ZNKSt6chrono8durationIlSt5ratioILl1ELl1000000EEE5countEv>:
	count() const
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
	{ return __r; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	48 8b 00             	mov    rax,QWORD PTR [rax]
   f:	5d                   	pop    rbp
  10:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIiSaIiEE5beginEv:

0000000000000000 <_ZNKSt6vectorIiSaIiEE5beginEv>:
       *  Returns a read-only (constant) iterator that points to the
       *  first element in the %vector.  Iteration is done in ordinary
       *  element order.
       */
      const_iterator
      begin() const _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
   c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  13:	00 00 
  15:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  19:	31 c0                	xor    eax,eax
      { return const_iterator(this->_M_impl._M_start); }
  1b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  1f:	48 8b 00             	mov    rax,QWORD PTR [rax]
  22:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  26:	48 8d 55 e8          	lea    rdx,[rbp-0x18]
  2a:	48 8d 45 f0          	lea    rax,[rbp-0x10]
  2e:	48 89 d6             	mov    rsi,rdx
  31:	48 89 c7             	mov    rdi,rax
  34:	e8 00 00 00 00       	call   39 <_ZNKSt6vectorIiSaIiEE5beginEv+0x39>
  39:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  3d:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
  41:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  48:	00 00 
  4a:	74 05                	je     51 <_ZNKSt6vectorIiSaIiEE5beginEv+0x51>
  4c:	e8 00 00 00 00       	call   51 <_ZNKSt6vectorIiSaIiEE5beginEv+0x51>
  51:	c9                   	leave  
  52:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIiSaIiEE3endEv:

0000000000000000 <_ZNKSt6vectorIiSaIiEE3endEv>:
       *  Returns a read-only (constant) iterator that points one past
       *  the last element in the %vector.  Iteration is done in
       *  ordinary element order.
       */
      const_iterator
      end() const _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
   c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  13:	00 00 
  15:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  19:	31 c0                	xor    eax,eax
      { return const_iterator(this->_M_impl._M_finish); }
  1b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  1f:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
  23:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  27:	48 8d 55 e8          	lea    rdx,[rbp-0x18]
  2b:	48 8d 45 f0          	lea    rax,[rbp-0x10]
  2f:	48 89 d6             	mov    rsi,rdx
  32:	48 89 c7             	mov    rdi,rax
  35:	e8 00 00 00 00       	call   3a <_ZNKSt6vectorIiSaIiEE3endEv+0x3a>
  3a:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  3e:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
  42:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  49:	00 00 
  4b:	74 05                	je     52 <_ZNKSt6vectorIiSaIiEE3endEv+0x52>
  4d:	e8 00 00 00 00       	call   52 <_ZNKSt6vectorIiSaIiEE3endEv+0x52>
  52:	c9                   	leave  
  53:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxxneIPKiSt6vectorIiSaIiEEEEbRKNS_17__normal_iteratorIT_T0_EESB_:

0000000000000000 <_ZN9__gnu_cxxneIPKiSt6vectorIiSaIiEEEEbRKNS_17__normal_iteratorIT_T0_EESB_>:
    _GLIBCXX_NOEXCEPT
    { return __lhs.base() != __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline bool
    operator!=(const __normal_iterator<_Iterator, _Container>& __lhs,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 18          	sub    rsp,0x18
   9:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   d:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
	       const __normal_iterator<_Iterator, _Container>& __rhs)
    _GLIBCXX_NOEXCEPT
    { return __lhs.base() != __rhs.base(); }
  11:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  15:	48 89 c7             	mov    rdi,rax
  18:	e8 00 00 00 00       	call   1d <_ZN9__gnu_cxxneIPKiSt6vectorIiSaIiEEEEbRKNS_17__normal_iteratorIT_T0_EESB_+0x1d>
  1d:	48 8b 18             	mov    rbx,QWORD PTR [rax]
  20:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  24:	48 89 c7             	mov    rdi,rax
  27:	e8 00 00 00 00       	call   2c <_ZN9__gnu_cxxneIPKiSt6vectorIiSaIiEEEEbRKNS_17__normal_iteratorIT_T0_EESB_+0x2c>
  2c:	48 8b 00             	mov    rax,QWORD PTR [rax]
  2f:	48 39 c3             	cmp    rbx,rax
  32:	0f 95 c0             	setne  al
  35:	48 83 c4 18          	add    rsp,0x18
  39:	5b                   	pop    rbx
  3a:	5d                   	pop    rbp
  3b:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx17__normal_iteratorIPKiSt6vectorIiSaIiEEEppEv:

0000000000000000 <_ZN9__gnu_cxx17__normal_iteratorIPKiSt6vectorIiSaIiEEEppEv>:
      operator++() _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
	++_M_current;
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	48 8b 00             	mov    rax,QWORD PTR [rax]
   f:	48 8d 50 04          	lea    rdx,[rax+0x4]
  13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  17:	48 89 10             	mov    QWORD PTR [rax],rdx
	return *this;
  1a:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
      }
  1e:	5d                   	pop    rbp
  1f:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx17__normal_iteratorIPKiSt6vectorIiSaIiEEEdeEv:

0000000000000000 <_ZNK9__gnu_cxx17__normal_iteratorIPKiSt6vectorIiSaIiEEEdeEv>:
      operator*() const _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return *_M_current; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	48 8b 00             	mov    rax,QWORD PTR [rax]
   f:	5d                   	pop    rbp
  10:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_:

0000000000000000 <_ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_>:
#if __cplusplus > 201402L
      typename vector<_Tp, _Alloc>::reference
#else
      void
#endif
      vector<_Tp, _Alloc>::
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 18          	sub    rsp,0x18
   9:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   d:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
      emplace_back(_Args&&... __args)
      {
	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
  11:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  15:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
  19:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  1d:	48 8b 40 10          	mov    rax,QWORD PTR [rax+0x10]
  21:	48 39 c2             	cmp    rdx,rax
  24:	74 3c                	je     62 <_ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_+0x62>
	  {
	    _GLIBCXX_ASAN_ANNOTATE_GROW(1);
	    _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
  26:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  2a:	48 89 c7             	mov    rdi,rax
  2d:	e8 00 00 00 00       	call   32 <_ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_+0x32>
  32:	48 89 c2             	mov    rdx,rax
  35:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  39:	48 8b 48 08          	mov    rcx,QWORD PTR [rax+0x8]
  3d:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  41:	48 89 ce             	mov    rsi,rcx
  44:	48 89 c7             	mov    rdi,rax
  47:	e8 00 00 00 00       	call   4c <_ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_+0x4c>
				     std::forward<_Args>(__args)...);
	    ++this->_M_impl._M_finish;
  4c:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  50:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
  54:	48 8d 50 04          	lea    rdx,[rax+0x4]
  58:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  5c:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
	else
	  _M_realloc_insert(end(), std::forward<_Args>(__args)...);
#if __cplusplus > 201402L
	return back();
#endif
      }
  60:	eb 30                	jmp    92 <_ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_+0x92>
	  _M_realloc_insert(end(), std::forward<_Args>(__args)...);
  62:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  66:	48 89 c7             	mov    rdi,rax
  69:	e8 00 00 00 00       	call   6e <_ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_+0x6e>
  6e:	48 89 c3             	mov    rbx,rax
  71:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  75:	48 89 c7             	mov    rdi,rax
  78:	e8 00 00 00 00       	call   7d <_ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_+0x7d>
  7d:	48 89 c1             	mov    rcx,rax
  80:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  84:	48 89 da             	mov    rdx,rbx
  87:	48 89 ce             	mov    rsi,rcx
  8a:	48 89 c7             	mov    rdi,rax
  8d:	e8 00 00 00 00       	call   92 <_ZNSt6vectorIiSaIiEE12emplace_backIJRiEEEvDpOT_+0x92>
      }
  92:	90                   	nop
  93:	48 83 c4 18          	add    rsp,0x18
  97:	5b                   	pop    rbx
  98:	5d                   	pop    rbp
  99:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEE12_Vector_implC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEE12_Vector_implC1Ev>:
	_Vector_impl() _GLIBCXX_NOEXCEPT_IF(
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
	: _Tp_alloc_type()
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSt12_Vector_baseIiSaIiEE12_Vector_implC1Ev+0x18>
  18:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  1c:	48 89 c7             	mov    rdi,rax
  1f:	e8 00 00 00 00       	call   24 <_ZNSt12_Vector_baseIiSaIiEE12_Vector_implC1Ev+0x24>
	{ }
  24:	90                   	nop
  25:	c9                   	leave  
  26:	c3                   	ret    

Disassembly of section .text._ZNSaIiED2Ev:

0000000000000000 <_ZNSaIiED1Ev>:

      template<typename _Tp1>
	_GLIBCXX20_CONSTEXPR
	allocator(const allocator<_Tp1>&) _GLIBCXX_NOTHROW { }

      ~allocator() _GLIBCXX_NOTHROW { }
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSaIiED1Ev+0x18>
  18:	90                   	nop
  19:	c9                   	leave  
  1a:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEED2Ev:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEED1Ev>:
      ~_Vector_base() _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
		      _M_impl._M_end_of_storage - _M_impl._M_start);
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
  14:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  18:	48 8b 00             	mov    rax,QWORD PTR [rax]
  1b:	48 29 c2             	sub    rdx,rax
  1e:	48 89 d0             	mov    rax,rdx
  21:	48 c1 f8 02          	sar    rax,0x2
	_M_deallocate(_M_impl._M_start,
  25:	48 89 c2             	mov    rdx,rax
  28:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  2c:	48 8b 08             	mov    rcx,QWORD PTR [rax]
  2f:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  33:	48 89 ce             	mov    rsi,rcx
  36:	48 89 c7             	mov    rdi,rax
  39:	e8 00 00 00 00       	call   3e <_ZNSt12_Vector_baseIiSaIiEED1Ev+0x3e>
      }
  3e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  42:	48 89 c7             	mov    rdi,rax
  45:	e8 00 00 00 00       	call   4a <_ZNSt12_Vector_baseIiSaIiEED1Ev+0x4a>
  4a:	90                   	nop
  4b:	c9                   	leave  
  4c:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEED2Ev:

0000000000000000 <_ZNSt6vectorIiSaIiEED1Ev>:
      ~vector() _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
		      _M_get_Tp_allocator());
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSt6vectorIiSaIiEED1Ev+0x18>
  18:	48 89 c2             	mov    rdx,rax
	std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
  1b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  1f:	48 8b 48 08          	mov    rcx,QWORD PTR [rax+0x8]
  23:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  27:	48 8b 00             	mov    rax,QWORD PTR [rax]
  2a:	48 89 ce             	mov    rsi,rcx
  2d:	48 89 c7             	mov    rdi,rax
  30:	e8 00 00 00 00       	call   35 <_ZNSt6vectorIiSaIiEED1Ev+0x35>
      }
  35:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  39:	48 89 c7             	mov    rdi,rax
  3c:	e8 00 00 00 00       	call   41 <_ZNSt6vectorIiSaIiEED1Ev+0x41>
  41:	90                   	nop
  42:	c9                   	leave  
  43:	c3                   	ret    

Disassembly of section .text._ZSt4swapIiSaIiEEvRSt6vectorIT_T0_ES5_:

0000000000000000 <_ZSt4swapIiSaIiEEvRSt6vectorIT_T0_ES5_>:
    { return !(__x < __y); }

  /// See std::vector::swap().
  template<typename _Tp, typename _Alloc>
    inline void
    swap(vector<_Tp, _Alloc>& __x, vector<_Tp, _Alloc>& __y)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
    _GLIBCXX_NOEXCEPT_IF(noexcept(__x.swap(__y)))
    { __x.swap(__y); }
  10:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
  14:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  18:	48 89 d6             	mov    rsi,rdx
  1b:	48 89 c7             	mov    rdi,rax
  1e:	e8 00 00 00 00       	call   23 <_ZSt4swapIiSaIiEEvRSt6vectorIT_T0_ES5_+0x23>
  23:	90                   	nop
  24:	c9                   	leave  
  25:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE4swapERS1_:

0000000000000000 <_ZNSt6vectorIiSaIiEE4swapERS1_>:
      swap(vector& __x) _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 18          	sub    rsp,0x18
   9:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   d:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
	this->_M_impl._M_swap_data(__x._M_impl);
  11:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  15:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
  19:	48 89 d6             	mov    rsi,rdx
  1c:	48 89 c7             	mov    rdi,rax
  1f:	e8 00 00 00 00       	call   24 <_ZNSt6vectorIiSaIiEE4swapERS1_+0x24>
	_Alloc_traits::_S_on_swap(_M_get_Tp_allocator(),
  24:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  28:	48 89 c7             	mov    rdi,rax
  2b:	e8 00 00 00 00       	call   30 <_ZNSt6vectorIiSaIiEE4swapERS1_+0x30>
  30:	48 89 c3             	mov    rbx,rax
  33:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  37:	48 89 c7             	mov    rdi,rax
  3a:	e8 00 00 00 00       	call   3f <_ZNSt6vectorIiSaIiEE4swapERS1_+0x3f>
  3f:	48 89 de             	mov    rsi,rbx
  42:	48 89 c7             	mov    rdi,rax
  45:	e8 00 00 00 00       	call   4a <_ZNSt6vectorIiSaIiEE4swapERS1_+0x4a>
      }
  4a:	90                   	nop
  4b:	48 83 c4 18          	add    rsp,0x18
  4f:	5b                   	pop    rbx
  50:	5d                   	pop    rbp
  51:	c3                   	ret    

Disassembly of section .text._ZNKSt6chrono10time_pointINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv:

0000000000000000 <_ZNKSt6chrono10time_pointINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEE16time_since_epochEv>:
	time_since_epoch() const
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
	{ return __d; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	48 8b 00             	mov    rax,QWORD PTR [rax]
   f:	5d                   	pop    rbp
  10:	c3                   	ret    

Disassembly of section .text._ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_:

0000000000000000 <_ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_>:
      operator-(const duration<_Rep1, _Period1>& __lhs,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 48          	sub    rsp,0x48
   9:	48 89 7d b8          	mov    QWORD PTR [rbp-0x48],rdi
   d:	48 89 75 b0          	mov    QWORD PTR [rbp-0x50],rsi
  11:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  18:	00 00 
  1a:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  1e:	31 c0                	xor    eax,eax
	return __cd(__cd(__lhs).count() - __cd(__rhs).count());
  20:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
  24:	48 8b 00             	mov    rax,QWORD PTR [rax]
  27:	48 89 45 c8          	mov    QWORD PTR [rbp-0x38],rax
  2b:	48 8d 45 c8          	lea    rax,[rbp-0x38]
  2f:	48 89 c7             	mov    rdi,rax
  32:	e8 00 00 00 00       	call   37 <_ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_+0x37>
  37:	48 89 c3             	mov    rbx,rax
  3a:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
  3e:	48 8b 00             	mov    rax,QWORD PTR [rax]
  41:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
  45:	48 8d 45 d0          	lea    rax,[rbp-0x30]
  49:	48 89 c7             	mov    rdi,rax
  4c:	e8 00 00 00 00       	call   51 <_ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_+0x51>
  51:	48 29 c3             	sub    rbx,rax
  54:	48 89 d8             	mov    rax,rbx
  57:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
  5b:	48 8d 55 d8          	lea    rdx,[rbp-0x28]
  5f:	48 8d 45 e0          	lea    rax,[rbp-0x20]
  63:	48 89 d6             	mov    rsi,rdx
  66:	48 89 c7             	mov    rdi,rax
  69:	e8 00 00 00 00       	call   6e <_ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_+0x6e>
  6e:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
      }
  72:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
  76:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  7d:	00 00 
  7f:	74 05                	je     86 <_ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_+0x86>
  81:	e8 00 00 00 00       	call   86 <_ZNSt6chronomiIlSt5ratioILl1ELl1000000000EElS2_EENSt11common_typeIJNS_8durationIT_T0_EENS4_IT1_T2_EEEE4typeERKS7_RKSA_+0x86>
  86:	48 83 c4 48          	add    rsp,0x48
  8a:	5b                   	pop    rbx
  8b:	5d                   	pop    rbp
  8c:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000000EEEES2_ILl1ELl1000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE:

0000000000000000 <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000000EEEES2_ILl1ELl1000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE>:
	  __cast(const duration<_Rep, _Period>& __d)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
   c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  13:	00 00 
  15:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  19:	31 c0                	xor    eax,eax
	      static_cast<_CR>(__d.count()) / static_cast<_CR>(_CF::den)));
  1b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  1f:	48 89 c7             	mov    rdi,rax
  22:	e8 00 00 00 00       	call   27 <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000000EEEES2_ILl1ELl1000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE+0x27>
  27:	48 89 c1             	mov    rcx,rax
  2a:	48 ba cf f7 53 e3 a5 	movabs rdx,0x20c49ba5e353f7cf
  31:	9b c4 20 
  34:	48 89 c8             	mov    rax,rcx
  37:	48 f7 ea             	imul   rdx
  3a:	48 c1 fa 07          	sar    rdx,0x7
  3e:	48 89 c8             	mov    rax,rcx
  41:	48 c1 f8 3f          	sar    rax,0x3f
  45:	48 29 c2             	sub    rdx,rax
  48:	48 89 d0             	mov    rax,rdx
  4b:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  4f:	48 8d 55 e8          	lea    rdx,[rbp-0x18]
  53:	48 8d 45 f0          	lea    rax,[rbp-0x10]
  57:	48 89 d6             	mov    rsi,rdx
  5a:	48 89 c7             	mov    rdi,rax
  5d:	e8 00 00 00 00       	call   62 <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000000EEEES2_ILl1ELl1000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE+0x62>
  62:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
	  }
  66:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
  6a:	64 48 33 34 25 28 00 	xor    rsi,QWORD PTR fs:0x28
  71:	00 00 
  73:	74 05                	je     7a <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000000EEEES2_ILl1ELl1000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE+0x7a>
  75:	e8 00 00 00 00       	call   7a <_ZNSt6chrono20__duration_cast_implINS_8durationIlSt5ratioILl1ELl1000000EEEES2_ILl1ELl1000EElLb1ELb0EE6__castIlS2_ILl1ELl1000000000EEEES4_RKNS1_IT_T0_EE+0x7a>
  7a:	c9                   	leave  
  7b:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx17__normal_iteratorIPKiSt6vectorIiSaIiEEEC2ERKS2_:

0000000000000000 <_ZN9__gnu_cxx17__normal_iteratorIPKiSt6vectorIiSaIiEEEC1ERKS2_>:
      __normal_iterator(const _Iterator& __i) _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
      : _M_current(__i) { }
   c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  10:	48 8b 10             	mov    rdx,QWORD PTR [rax]
  13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  17:	48 89 10             	mov    QWORD PTR [rax],rdx
  1a:	90                   	nop
  1b:	5d                   	pop    rbp
  1c:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx17__normal_iteratorIPKiSt6vectorIiSaIiEEE4baseEv:

0000000000000000 <_ZNK9__gnu_cxx17__normal_iteratorIPKiSt6vectorIiSaIiEEE4baseEv>:
      base() const _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return _M_current; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	5d                   	pop    rbp
   d:	c3                   	ret    

Disassembly of section .text._ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE:

0000000000000000 <_ZSt7forwardIRiEOT_RNSt16remove_referenceIS1_E4typeE>:
   *
   *  This function is used to implement "perfect forwarding".
   */
  template<typename _Tp>
    constexpr _Tp&&
    forward(typename std::remove_reference<_Tp>::type& __t) noexcept
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
    { return static_cast<_Tp&&>(__t); }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	5d                   	pop    rbp
   d:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIiEE9constructIiJRiEEEvRS0_PT_DpOT0_:

0000000000000000 <_ZNSt16allocator_traitsISaIiEE9constructIiJRiEEEvRS0_PT_DpOT0_>:
       *
       *  Calls <tt> __a.construct(__p, std::forward<Args>(__args)...) </tt>
      */
      template<typename _Up, typename... _Args>
	static void
	construct(allocator_type& __a, _Up* __p, _Args&&... __args)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
	noexcept(noexcept(__a.construct(__p, std::forward<_Args>(__args)...)))
	{ __a.construct(__p, std::forward<_Args>(__args)...); }
  14:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  18:	48 89 c7             	mov    rdi,rax
  1b:	e8 00 00 00 00       	call   20 <_ZNSt16allocator_traitsISaIiEE9constructIiJRiEEEvRS0_PT_DpOT0_+0x20>
  20:	48 89 c2             	mov    rdx,rax
  23:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
  27:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  2b:	48 89 ce             	mov    rsi,rcx
  2e:	48 89 c7             	mov    rdi,rax
  31:	e8 00 00 00 00       	call   36 <_ZNSt16allocator_traitsISaIiEE9constructIiJRiEEEvRS0_PT_DpOT0_+0x36>
  36:	90                   	nop
  37:	c9                   	leave  
  38:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE3endEv:

0000000000000000 <_ZNSt6vectorIiSaIiEE3endEv>:
      end() _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  13:	00 00 
  15:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  19:	31 c0                	xor    eax,eax
      { return iterator(this->_M_impl._M_finish); }
  1b:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  1f:	48 8d 50 08          	lea    rdx,[rax+0x8]
  23:	48 8d 45 f0          	lea    rax,[rbp-0x10]
  27:	48 89 d6             	mov    rsi,rdx
  2a:	48 89 c7             	mov    rdi,rax
  2d:	e8 00 00 00 00       	call   32 <_ZNSt6vectorIiSaIiEE3endEv+0x32>
  32:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  36:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
  3a:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  41:	00 00 
  43:	74 05                	je     4a <_ZNSt6vectorIiSaIiEE3endEv+0x4a>
  45:	e8 00 00 00 00       	call   4a <_ZNSt6vectorIiSaIiEE3endEv+0x4a>
  4a:	c9                   	leave  
  4b:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE15_S_use_relocateEv:

0000000000000000 <_ZNSt6vectorIiSaIiEE15_S_use_relocateEv>:
      _S_use_relocate()
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   f:	00 00 
  11:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  15:	31 c0                	xor    eax,eax
	return _S_nothrow_relocate(__is_move_insertable<_Tp_alloc_type>{});
  17:	e8 00 00 00 00       	call   1c <_ZNSt6vectorIiSaIiEE15_S_use_relocateEv+0x1c>
      }
  1c:	48 8b 55 f8          	mov    rdx,QWORD PTR [rbp-0x8]
  20:	64 48 33 14 25 28 00 	xor    rdx,QWORD PTR fs:0x28
  27:	00 00 
  29:	74 05                	je     30 <_ZNSt6vectorIiSaIiEE15_S_use_relocateEv+0x30>
  2b:	e8 00 00 00 00       	call   30 <_ZNSt6vectorIiSaIiEE15_S_use_relocateEv+0x30>
  30:	c9                   	leave  
  31:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE19_S_nothrow_relocateESt17integral_constantIbLb1EE:

0000000000000000 <_ZNSt6vectorIiSaIiEE19_S_nothrow_relocateESt17integral_constantIbLb1EE>:
      _S_nothrow_relocate(true_type)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
					  std::declval<_Tp_alloc_type&>()));
   4:	b8 01 00 00 00       	mov    eax,0x1
      }
   9:	5d                   	pop    rbp
   a:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:

0000000000000000 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_>:

#if __cplusplus >= 201103L
  template<typename _Tp, typename _Alloc>
    template<typename... _Args>
      void
      vector<_Tp, _Alloc>::
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 68          	sub    rsp,0x68
   9:	48 89 7d a8          	mov    QWORD PTR [rbp-0x58],rdi
   d:	48 89 75 a0          	mov    QWORD PTR [rbp-0x60],rsi
  11:	48 89 55 98          	mov    QWORD PTR [rbp-0x68],rdx
  15:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  1c:	00 00 
  1e:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  22:	31 c0                	xor    eax,eax
    void
    vector<_Tp, _Alloc>::
    _M_realloc_insert(iterator __position, const _Tp& __x)
#endif
    {
      const size_type __len =
  24:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
  28:	48 8d 15 00 00 00 00 	lea    rdx,[rip+0x0]        # 2f <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2f>
  2f:	be 01 00 00 00       	mov    esi,0x1
  34:	48 89 c7             	mov    rdi,rax
  37:	e8 00 00 00 00       	call   3c <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x3c>
  3c:	48 89 45 c0          	mov    QWORD PTR [rbp-0x40],rax
	_M_check_len(size_type(1), "vector::_M_realloc_insert");
      pointer __old_start = this->_M_impl._M_start;
  40:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
  44:	48 8b 00             	mov    rax,QWORD PTR [rax]
  47:	48 89 45 c8          	mov    QWORD PTR [rbp-0x38],rax
      pointer __old_finish = this->_M_impl._M_finish;
  4b:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
  4f:	48 8b 40 08          	mov    rax,QWORD PTR [rax+0x8]
  53:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
      const size_type __elems_before = __position - begin();
  57:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
  5b:	48 89 c7             	mov    rdi,rax
  5e:	e8 00 00 00 00       	call   63 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x63>
  63:	48 89 45 b0          	mov    QWORD PTR [rbp-0x50],rax
  67:	48 8d 55 b0          	lea    rdx,[rbp-0x50]
  6b:	48 8d 45 a0          	lea    rax,[rbp-0x60]
  6f:	48 89 d6             	mov    rsi,rdx
  72:	48 89 c7             	mov    rdi,rax
  75:	e8 00 00 00 00       	call   7a <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x7a>
  7a:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
      pointer __new_start(this->_M_allocate(__len));
  7e:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
  82:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
  86:	48 89 d6             	mov    rsi,rdx
  89:	48 89 c7             	mov    rdi,rax
  8c:	e8 00 00 00 00       	call   91 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x91>
  91:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
      pointer __new_finish(__new_start);
  95:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  99:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax
	  // The order of the three operations is dictated by the C++11
	  // case, where the moves could alter a new element belonging
	  // to the existing vector.  This is an issue only for callers
	  // taking the element by lvalue ref (see last bullet of C++11
	  // [res.on.arguments]).
	  _Alloc_traits::construct(this->_M_impl,
  9d:	48 8b 45 98          	mov    rax,QWORD PTR [rbp-0x68]
  a1:	48 89 c7             	mov    rdi,rax
  a4:	e8 00 00 00 00       	call   a9 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0xa9>
  a9:	48 89 c2             	mov    rdx,rax
				   __new_start + __elems_before,
  ac:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  b0:	48 8d 0c 85 00 00 00 	lea    rcx,[rax*4+0x0]
  b7:	00 
	  _Alloc_traits::construct(this->_M_impl,
  b8:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  bc:	48 01 c1             	add    rcx,rax
  bf:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
  c3:	48 89 ce             	mov    rsi,rcx
  c6:	48 89 c7             	mov    rdi,rax
  c9:	e8 00 00 00 00       	call   ce <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0xce>
#if __cplusplus >= 201103L
				   std::forward<_Args>(__args)...);
#else
				   __x);
#endif
	  __new_finish = pointer();
  ce:	48 c7 45 b8 00 00 00 	mov    QWORD PTR [rbp-0x48],0x0
  d5:	00 

#if __cplusplus >= 201103L
	  if _GLIBCXX17_CONSTEXPR (_S_use_relocate())
  d6:	e8 00 00 00 00       	call   db <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0xdb>
  db:	84 c0                	test   al,al
  dd:	74 71                	je     150 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x150>
	    {
	      __new_finish = _S_relocate(__old_start, __position.base(),
					 __new_start, _M_get_Tp_allocator());
  df:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
  e3:	48 89 c7             	mov    rdi,rax
  e6:	e8 00 00 00 00       	call   eb <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0xeb>
  eb:	48 89 c3             	mov    rbx,rax
	      __new_finish = _S_relocate(__old_start, __position.base(),
  ee:	48 8d 45 a0          	lea    rax,[rbp-0x60]
  f2:	48 89 c7             	mov    rdi,rax
  f5:	e8 00 00 00 00       	call   fa <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0xfa>
  fa:	48 8b 30             	mov    rsi,QWORD PTR [rax]
  fd:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 101:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
 105:	48 89 d9             	mov    rcx,rbx
 108:	48 89 c7             	mov    rdi,rax
 10b:	e8 00 00 00 00       	call   110 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x110>
 110:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax

	      ++__new_finish;
 114:	48 83 45 b8 04       	add    QWORD PTR [rbp-0x48],0x4

	      __new_finish = _S_relocate(__position.base(), __old_finish,
					 __new_finish, _M_get_Tp_allocator());
 119:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 11d:	48 89 c7             	mov    rdi,rax
 120:	e8 00 00 00 00       	call   125 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x125>
 125:	48 89 c3             	mov    rbx,rax
	      __new_finish = _S_relocate(__position.base(), __old_finish,
 128:	48 8d 45 a0          	lea    rax,[rbp-0x60]
 12c:	48 89 c7             	mov    rdi,rax
 12f:	e8 00 00 00 00       	call   134 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x134>
 134:	48 8b 00             	mov    rax,QWORD PTR [rax]
 137:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 13b:	48 8b 75 d0          	mov    rsi,QWORD PTR [rbp-0x30]
 13f:	48 89 d9             	mov    rcx,rbx
 142:	48 89 c7             	mov    rdi,rax
 145:	e8 00 00 00 00       	call   14a <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x14a>
 14a:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax
 14e:	eb 6f                	jmp    1bf <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x1bf>
#endif
	    {
	      __new_finish
		= std::__uninitialized_move_if_noexcept_a
		(__old_start, __position.base(),
		 __new_start, _M_get_Tp_allocator());
 150:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 154:	48 89 c7             	mov    rdi,rax
 157:	e8 00 00 00 00       	call   15c <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x15c>
 15c:	48 89 c3             	mov    rbx,rax
		(__old_start, __position.base(),
 15f:	48 8d 45 a0          	lea    rax,[rbp-0x60]
 163:	48 89 c7             	mov    rdi,rax
 166:	e8 00 00 00 00       	call   16b <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x16b>
 16b:	48 8b 30             	mov    rsi,QWORD PTR [rax]
 16e:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 172:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
 176:	48 89 d9             	mov    rcx,rbx
 179:	48 89 c7             	mov    rdi,rax
 17c:	e8 00 00 00 00       	call   181 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x181>
 181:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax

	      ++__new_finish;
 185:	48 83 45 b8 04       	add    QWORD PTR [rbp-0x48],0x4

	      __new_finish
		= std::__uninitialized_move_if_noexcept_a
		(__position.base(), __old_finish,
		 __new_finish, _M_get_Tp_allocator());
 18a:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 18e:	48 89 c7             	mov    rdi,rax
 191:	e8 00 00 00 00       	call   196 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x196>
 196:	48 89 c3             	mov    rbx,rax
		(__position.base(), __old_finish,
 199:	48 8d 45 a0          	lea    rax,[rbp-0x60]
 19d:	48 89 c7             	mov    rdi,rax
 1a0:	e8 00 00 00 00       	call   1a5 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x1a5>
 1a5:	48 8b 00             	mov    rax,QWORD PTR [rax]
 1a8:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 1ac:	48 8b 75 d0          	mov    rsi,QWORD PTR [rbp-0x30]
 1b0:	48 89 d9             	mov    rcx,rbx
 1b3:	48 89 c7             	mov    rdi,rax
 1b6:	e8 00 00 00 00       	call   1bb <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x1bb>
 1bb:	48 89 45 b8          	mov    QWORD PTR [rbp-0x48],rax
	    std::_Destroy(__new_start, __new_finish, _M_get_Tp_allocator());
	  _M_deallocate(__new_start, __len);
	  __throw_exception_again;
	}
#if __cplusplus >= 201103L
      if _GLIBCXX17_CONSTEXPR (!_S_use_relocate())
 1bf:	e8 00 00 00 00       	call   1c4 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x1c4>
 1c4:	83 f0 01             	xor    eax,0x1
 1c7:	84 c0                	test   al,al
 1c9:	74 22                	je     1ed <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x1ed>
#endif
	std::_Destroy(__old_start, __old_finish, _M_get_Tp_allocator());
 1cb:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 1cf:	48 89 c7             	mov    rdi,rax
 1d2:	e8 00 00 00 00       	call   1d7 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x1d7>
 1d7:	48 89 c2             	mov    rdx,rax
 1da:	48 8b 4d d0          	mov    rcx,QWORD PTR [rbp-0x30]
 1de:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
 1e2:	48 89 ce             	mov    rsi,rcx
 1e5:	48 89 c7             	mov    rdi,rax
 1e8:	e8 00 00 00 00       	call   1ed <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x1ed>
      _GLIBCXX_ASAN_ANNOTATE_REINIT;
      _M_deallocate(__old_start,
 1ed:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
		    this->_M_impl._M_end_of_storage - __old_start);
 1f1:	48 8b 55 a8          	mov    rdx,QWORD PTR [rbp-0x58]
 1f5:	48 8b 52 10          	mov    rdx,QWORD PTR [rdx+0x10]
 1f9:	48 2b 55 c8          	sub    rdx,QWORD PTR [rbp-0x38]
 1fd:	48 c1 fa 02          	sar    rdx,0x2
      _M_deallocate(__old_start,
 201:	48 8b 4d c8          	mov    rcx,QWORD PTR [rbp-0x38]
 205:	48 89 ce             	mov    rsi,rcx
 208:	48 89 c7             	mov    rdi,rax
 20b:	e8 00 00 00 00       	call   210 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x210>
      this->_M_impl._M_start = __new_start;
 210:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 214:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
 218:	48 89 10             	mov    QWORD PTR [rax],rdx
      this->_M_impl._M_finish = __new_finish;
 21b:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 21f:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 223:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
      this->_M_impl._M_end_of_storage = __new_start + __len;
 227:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
 22b:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
 232:	00 
 233:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 237:	48 01 c2             	add    rdx,rax
 23a:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 23e:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
    }
 242:	90                   	nop
 243:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 247:	64 48 33 04 25 28 00 	xor    rax,QWORD PTR fs:0x28
 24e:	00 00 
 250:	0f 84 8e 00 00 00    	je     2e4 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2e4>
 256:	e9 84 00 00 00       	jmp    2df <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2df>
      __catch(...)
 25b:	48 89 c7             	mov    rdi,rax
 25e:	e8 00 00 00 00       	call   263 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x263>
	  if (!__new_finish)
 263:	48 83 7d b8 00       	cmp    QWORD PTR [rbp-0x48],0x0
 268:	75 24                	jne    28e <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x28e>
				   __new_start + __elems_before);
 26a:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
 26e:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
 275:	00 
	    _Alloc_traits::destroy(this->_M_impl,
 276:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 27a:	48 01 c2             	add    rdx,rax
 27d:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 281:	48 89 d6             	mov    rsi,rdx
 284:	48 89 c7             	mov    rdi,rax
 287:	e8 00 00 00 00       	call   28c <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x28c>
 28c:	eb 22                	jmp    2b0 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2b0>
	    std::_Destroy(__new_start, __new_finish, _M_get_Tp_allocator());
 28e:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 292:	48 89 c7             	mov    rdi,rax
 295:	e8 00 00 00 00       	call   29a <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x29a>
 29a:	48 89 c2             	mov    rdx,rax
 29d:	48 8b 4d b8          	mov    rcx,QWORD PTR [rbp-0x48]
 2a1:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
 2a5:	48 89 ce             	mov    rsi,rcx
 2a8:	48 89 c7             	mov    rdi,rax
 2ab:	e8 00 00 00 00       	call   2b0 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2b0>
	  _M_deallocate(__new_start, __len);
 2b0:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 2b4:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
 2b8:	48 8b 4d e0          	mov    rcx,QWORD PTR [rbp-0x20]
 2bc:	48 89 ce             	mov    rsi,rcx
 2bf:	48 89 c7             	mov    rdi,rax
 2c2:	e8 00 00 00 00       	call   2c7 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2c7>
	  __throw_exception_again;
 2c7:	e8 00 00 00 00       	call   2cc <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2cc>
 2cc:	48 89 c3             	mov    rbx,rax
      __catch(...)
 2cf:	e8 00 00 00 00       	call   2d4 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2d4>
 2d4:	48 89 d8             	mov    rax,rbx
 2d7:	48 89 c7             	mov    rdi,rax
 2da:	e8 00 00 00 00       	call   2df <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2df>
    }
 2df:	e8 00 00 00 00       	call   2e4 <_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_+0x2e4>
 2e4:	48 83 c4 68          	add    rsp,0x68
 2e8:	5b                   	pop    rbx
 2e9:	5d                   	pop    rbp
 2ea:	c3                   	ret    

Disassembly of section .text._ZNSaIiEC2Ev:

0000000000000000 <_ZNSaIiEC1Ev>:
      allocator() _GLIBCXX_NOTHROW { }
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSaIiEC1Ev+0x18>
  18:	90                   	nop
  19:	c9                   	leave  
  1a:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_dataC2Ev:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_dataC1Ev>:
	_Vector_impl_data() _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
	: _M_start(), _M_finish(), _M_end_of_storage()
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	48 c7 00 00 00 00 00 	mov    QWORD PTR [rax],0x0
  13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  17:	48 c7 40 08 00 00 00 	mov    QWORD PTR [rax+0x8],0x0
  1e:	00 
  1f:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  23:	48 c7 40 10 00 00 00 	mov    QWORD PTR [rax+0x10],0x0
  2a:	00 
	{ }
  2b:	90                   	nop
  2c:	5d                   	pop    rbp
  2d:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIiED2Ev:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIiED1Ev>:

      template<typename _Tp1>
	_GLIBCXX20_CONSTEXPR
	new_allocator(const new_allocator<_Tp1>&) _GLIBCXX_USE_NOEXCEPT { }

      ~new_allocator() _GLIBCXX_USE_NOEXCEPT { }
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	90                   	nop
   9:	5d                   	pop    rbp
   a:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPim:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPim>:
      _M_deallocate(pointer __p, size_t __n)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
	if (__p)
  14:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
  19:	74 17                	je     32 <_ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPim+0x32>
	  _Tr::deallocate(_M_impl, __p, __n);
  1b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  1f:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
  23:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
  27:	48 89 ce             	mov    rsi,rcx
  2a:	48 89 c7             	mov    rdi,rax
  2d:	e8 00 00 00 00       	call   32 <_ZNSt12_Vector_baseIiSaIiEE13_M_deallocateEPim+0x32>
      }
  32:	90                   	nop
  33:	c9                   	leave  
  34:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv>:
      _M_get_Tp_allocator() _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return this->_M_impl; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	5d                   	pop    rbp
   d:	c3                   	ret    

Disassembly of section .text._ZSt8_DestroyIPiiEvT_S1_RSaIT0_E:

0000000000000000 <_ZSt8_DestroyIPiiEvT_S1_RSaIT0_E>:
	__traits::destroy(__alloc, std::__addressof(*__first));
    }

  template<typename _ForwardIterator, typename _Tp>
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
	     allocator<_Tp>&)
    {
      _Destroy(__first, __last);
  14:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
  18:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  1c:	48 89 d6             	mov    rsi,rdx
  1f:	48 89 c7             	mov    rdi,rax
  22:	e8 00 00 00 00       	call   27 <_ZSt8_DestroyIPiiEvT_S1_RSaIT0_E+0x27>
    }
  27:	90                   	nop
  28:	c9                   	leave  
  29:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_swap_dataERS2_:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_swap_dataERS2_>:
	_M_swap_data(_Vector_impl_data& __x) _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
   c:	48 89 75 d0          	mov    QWORD PTR [rbp-0x30],rsi
  10:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  17:	00 00 
  19:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  1d:	31 c0                	xor    eax,eax
	  _Vector_impl_data __tmp;
  1f:	48 8d 45 e0          	lea    rax,[rbp-0x20]
  23:	48 89 c7             	mov    rdi,rax
  26:	e8 00 00 00 00       	call   2b <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_swap_dataERS2_+0x2b>
	  __tmp._M_copy_data(*this);
  2b:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
  2f:	48 8d 45 e0          	lea    rax,[rbp-0x20]
  33:	48 89 d6             	mov    rsi,rdx
  36:	48 89 c7             	mov    rdi,rax
  39:	e8 00 00 00 00       	call   3e <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_swap_dataERS2_+0x3e>
	  _M_copy_data(__x);
  3e:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
  42:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  46:	48 89 d6             	mov    rsi,rdx
  49:	48 89 c7             	mov    rdi,rax
  4c:	e8 00 00 00 00       	call   51 <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_swap_dataERS2_+0x51>
	  __x._M_copy_data(__tmp);
  51:	48 8d 55 e0          	lea    rdx,[rbp-0x20]
  55:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
  59:	48 89 d6             	mov    rsi,rdx
  5c:	48 89 c7             	mov    rdi,rax
  5f:	e8 00 00 00 00       	call   64 <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_swap_dataERS2_+0x64>
	}
  64:	90                   	nop
  65:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  69:	64 48 33 04 25 28 00 	xor    rax,QWORD PTR fs:0x28
  70:	00 00 
  72:	74 05                	je     79 <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_swap_dataERS2_+0x79>
  74:	e8 00 00 00 00       	call   79 <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_swap_dataERS2_+0x79>
  79:	c9                   	leave  
  7a:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx14__alloc_traitsISaIiEiE10_S_on_swapERS1_S3_:

0000000000000000 <_ZN9__gnu_cxx14__alloc_traitsISaIiEiE10_S_on_swapERS1_S3_>:
      { _Base_type::destroy(__a, std::__to_address(__p)); }

    static _Alloc _S_select_on_copy(const _Alloc& __a)
    { return _Base_type::select_on_container_copy_construction(__a); }

    static void _S_on_swap(_Alloc& __a, _Alloc& __b)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
    { std::__alloc_on_swap(__a, __b); }
  10:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
  14:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  18:	48 89 d6             	mov    rsi,rdx
  1b:	48 89 c7             	mov    rdi,rax
  1e:	e8 00 00 00 00       	call   23 <_ZN9__gnu_cxx14__alloc_traitsISaIiEiE10_S_on_swapERS1_S3_+0x23>
  23:	90                   	nop
  24:	c9                   	leave  
  25:	c3                   	ret    

Disassembly of section .text._ZNSt6chrono8durationIlSt5ratioILl1ELl1000000EEEC2IlvEERKT_:

0000000000000000 <_ZNSt6chrono8durationIlSt5ratioILl1ELl1000000EEEC1IlvEERKT_>:
	  constexpr explicit duration(const _Rep2& __rep)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
	  : __r(static_cast<rep>(__rep)) { }
   c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  10:	48 8b 10             	mov    rdx,QWORD PTR [rax]
  13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  17:	48 89 10             	mov    QWORD PTR [rax],rdx
  1a:	90                   	nop
  1b:	5d                   	pop    rbp
  1c:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIiE9constructIiJRiEEEvPT_DpOT0_:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIiE9constructIiJRiEEEvPT_DpOT0_>:
      }

#if __cplusplus >= 201103L
      template<typename _Up, typename... _Args>
	void
	construct(_Up* __p, _Args&&... __args)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 28          	sub    rsp,0x28
   9:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   d:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  11:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
	noexcept(noexcept(::new((void *)__p)
			    _Up(std::forward<_Args>(__args)...)))
	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
  15:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  19:	48 89 c7             	mov    rdi,rax
  1c:	e8 00 00 00 00       	call   21 <_ZN9__gnu_cxx13new_allocatorIiE9constructIiJRiEEEvPT_DpOT0_+0x21>
  21:	8b 18                	mov    ebx,DWORD PTR [rax]
  23:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  27:	48 89 c6             	mov    rsi,rax
  2a:	bf 04 00 00 00       	mov    edi,0x4
  2f:	e8 00 00 00 00       	call   34 <_ZN9__gnu_cxx13new_allocatorIiE9constructIiJRiEEEvPT_DpOT0_+0x34>
  34:	89 18                	mov    DWORD PTR [rax],ebx
  36:	90                   	nop
  37:	48 83 c4 28          	add    rsp,0x28
  3b:	5b                   	pop    rbx
  3c:	5d                   	pop    rbp
  3d:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEC2ERKS1_:

0000000000000000 <_ZN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEC1ERKS1_>:
      __normal_iterator(const _Iterator& __i) _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
      : _M_current(__i) { }
   c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  10:	48 8b 10             	mov    rdx,QWORD PTR [rax]
  13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  17:	48 89 10             	mov    QWORD PTR [rax],rdx
  1a:	90                   	nop
  1b:	5d                   	pop    rbp
  1c:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc:

0000000000000000 <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc>:
      _M_check_len(size_type __n, const char* __s) const
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 48          	sub    rsp,0x48
   9:	48 89 7d c8          	mov    QWORD PTR [rbp-0x38],rdi
   d:	48 89 75 c0          	mov    QWORD PTR [rbp-0x40],rsi
  11:	48 89 55 b8          	mov    QWORD PTR [rbp-0x48],rdx
  15:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  1c:	00 00 
  1e:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
  22:	31 c0                	xor    eax,eax
	if (max_size() - size() < __n)
  24:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  28:	48 89 c7             	mov    rdi,rax
  2b:	e8 00 00 00 00       	call   30 <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0x30>
  30:	48 89 c3             	mov    rbx,rax
  33:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  37:	48 89 c7             	mov    rdi,rax
  3a:	e8 00 00 00 00       	call   3f <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0x3f>
  3f:	48 29 c3             	sub    rbx,rax
  42:	48 89 da             	mov    rdx,rbx
  45:	48 8b 45 c0          	mov    rax,QWORD PTR [rbp-0x40]
  49:	48 39 c2             	cmp    rdx,rax
  4c:	0f 92 c0             	setb   al
  4f:	84 c0                	test   al,al
  51:	74 0c                	je     5f <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0x5f>
	  __throw_length_error(__N(__s));
  53:	48 8b 45 b8          	mov    rax,QWORD PTR [rbp-0x48]
  57:	48 89 c7             	mov    rdi,rax
  5a:	e8 00 00 00 00       	call   5f <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0x5f>
	const size_type __len = size() + (std::max)(size(), __n);
  5f:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  63:	48 89 c7             	mov    rdi,rax
  66:	e8 00 00 00 00       	call   6b <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0x6b>
  6b:	48 89 c3             	mov    rbx,rax
  6e:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  72:	48 89 c7             	mov    rdi,rax
  75:	e8 00 00 00 00       	call   7a <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0x7a>
  7a:	48 89 45 d8          	mov    QWORD PTR [rbp-0x28],rax
  7e:	48 8d 55 c0          	lea    rdx,[rbp-0x40]
  82:	48 8d 45 d8          	lea    rax,[rbp-0x28]
  86:	48 89 d6             	mov    rsi,rdx
  89:	48 89 c7             	mov    rdi,rax
  8c:	e8 00 00 00 00       	call   91 <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0x91>
  91:	48 8b 00             	mov    rax,QWORD PTR [rax]
  94:	48 01 d8             	add    rax,rbx
  97:	48 89 45 e0          	mov    QWORD PTR [rbp-0x20],rax
	return (__len < size() || __len > max_size()) ? max_size() : __len;
  9b:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  9f:	48 89 c7             	mov    rdi,rax
  a2:	e8 00 00 00 00       	call   a7 <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0xa7>
  a7:	48 39 45 e0          	cmp    QWORD PTR [rbp-0x20],rax
  ab:	72 12                	jb     bf <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0xbf>
  ad:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  b1:	48 89 c7             	mov    rdi,rax
  b4:	e8 00 00 00 00       	call   b9 <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0xb9>
  b9:	48 39 45 e0          	cmp    QWORD PTR [rbp-0x20],rax
  bd:	76 0e                	jbe    cd <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0xcd>
  bf:	48 8b 45 c8          	mov    rax,QWORD PTR [rbp-0x38]
  c3:	48 89 c7             	mov    rdi,rax
  c6:	e8 00 00 00 00       	call   cb <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0xcb>
  cb:	eb 04                	jmp    d1 <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0xd1>
  cd:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
      }
  d1:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
  d5:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  dc:	00 00 
  de:	74 05                	je     e5 <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0xe5>
  e0:	e8 00 00 00 00       	call   e5 <_ZNKSt6vectorIiSaIiEE12_M_check_lenEmPKc+0xe5>
  e5:	48 83 c4 48          	add    rsp,0x48
  e9:	5b                   	pop    rbx
  ea:	5d                   	pop    rbp
  eb:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE5beginEv:

0000000000000000 <_ZNSt6vectorIiSaIiEE5beginEv>:
      begin() _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  13:	00 00 
  15:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  19:	31 c0                	xor    eax,eax
      { return iterator(this->_M_impl._M_start); }
  1b:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
  1f:	48 8d 45 f0          	lea    rax,[rbp-0x10]
  23:	48 89 d6             	mov    rsi,rdx
  26:	48 89 c7             	mov    rdi,rax
  29:	e8 00 00 00 00       	call   2e <_ZNSt6vectorIiSaIiEE5beginEv+0x2e>
  2e:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  32:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
  36:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  3d:	00 00 
  3f:	74 05                	je     46 <_ZNSt6vectorIiSaIiEE5beginEv+0x46>
  41:	e8 00 00 00 00       	call   46 <_ZNSt6vectorIiSaIiEE5beginEv+0x46>
  46:	c9                   	leave  
  47:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_:

0000000000000000 <_ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_>:
#endif
    { return __lhs.base() - __rhs.base(); }

  template<typename _Iterator, typename _Container>
    inline typename __normal_iterator<_Iterator, _Container>::difference_type
    operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 18          	sub    rsp,0x18
   9:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   d:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
	      const __normal_iterator<_Iterator, _Container>& __rhs)
    _GLIBCXX_NOEXCEPT
    { return __lhs.base() - __rhs.base(); }
  11:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  15:	48 89 c7             	mov    rdi,rax
  18:	e8 00 00 00 00       	call   1d <_ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_+0x1d>
  1d:	48 8b 18             	mov    rbx,QWORD PTR [rax]
  20:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  24:	48 89 c7             	mov    rdi,rax
  27:	e8 00 00 00 00       	call   2c <_ZN9__gnu_cxxmiIPiSt6vectorIiSaIiEEEENS_17__normal_iteratorIT_T0_E15difference_typeERKS8_SB_+0x2c>
  2c:	48 8b 00             	mov    rax,QWORD PTR [rax]
  2f:	48 29 c3             	sub    rbx,rax
  32:	48 89 d8             	mov    rax,rbx
  35:	48 c1 f8 02          	sar    rax,0x2
  39:	48 83 c4 18          	add    rsp,0x18
  3d:	5b                   	pop    rbx
  3e:	5d                   	pop    rbp
  3f:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEE11_M_allocateEm:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEE11_M_allocateEm>:
      _M_allocate(size_t __n)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
	return __n != 0 ? _Tr::allocate(_M_impl, __n) : pointer();
  10:	48 83 7d f0 00       	cmp    QWORD PTR [rbp-0x10],0x0
  15:	74 15                	je     2c <_ZNSt12_Vector_baseIiSaIiEE11_M_allocateEm+0x2c>
  17:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  1b:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
  1f:	48 89 d6             	mov    rsi,rdx
  22:	48 89 c7             	mov    rdi,rax
  25:	e8 00 00 00 00       	call   2a <_ZNSt12_Vector_baseIiSaIiEE11_M_allocateEm+0x2a>
  2a:	eb 05                	jmp    31 <_ZNSt12_Vector_baseIiSaIiEE11_M_allocateEm+0x31>
  2c:	b8 00 00 00 00       	mov    eax,0x0
      }
  31:	c9                   	leave  
  32:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE11_S_relocateEPiS2_S2_RS0_:

0000000000000000 <_ZNSt6vectorIiSaIiEE11_S_relocateEPiS2_S2_RS0_>:
      _S_relocate(pointer __first, pointer __last, pointer __result,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  10:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
  14:	48 89 4d d0          	mov    QWORD PTR [rbp-0x30],rcx
  18:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  1f:	00 00 
  21:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  25:	31 c0                	xor    eax,eax
	return _S_do_relocate(__first, __last, __result, __alloc, __do_it{});
  27:	48 8b 4d d0          	mov    rcx,QWORD PTR [rbp-0x30]
  2b:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
  2f:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
  33:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  37:	48 89 c7             	mov    rdi,rax
  3a:	e8 00 00 00 00       	call   3f <_ZNSt6vectorIiSaIiEE11_S_relocateEPiS2_S2_RS0_+0x3f>
      }
  3f:	48 8b 7d f8          	mov    rdi,QWORD PTR [rbp-0x8]
  43:	64 48 33 3c 25 28 00 	xor    rdi,QWORD PTR fs:0x28
  4a:	00 00 
  4c:	74 05                	je     53 <_ZNSt6vectorIiSaIiEE11_S_relocateEPiS2_S2_RS0_+0x53>
  4e:	e8 00 00 00 00       	call   53 <_ZNSt6vectorIiSaIiEE11_S_relocateEPiS2_S2_RS0_+0x53>
  53:	c9                   	leave  
  54:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv:

0000000000000000 <_ZNK9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEE4baseEv>:
      base() const _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return _M_current; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	5d                   	pop    rbp
   d:	c3                   	ret    

Disassembly of section .text._ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_:

0000000000000000 <_ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_>:
    }

  template<typename _InputIterator, typename _ForwardIterator,
	   typename _Allocator>
    inline _ForwardIterator
    __uninitialized_move_if_noexcept_a(_InputIterator __first,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 28          	sub    rsp,0x28
   9:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   d:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  11:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
  15:	48 89 4d d0          	mov    QWORD PTR [rbp-0x30],rcx
				       _InputIterator __last,
				       _ForwardIterator __result,
				       _Allocator& __alloc)
    {
      return std::__uninitialized_copy_a
	(_GLIBCXX_MAKE_MOVE_IF_NOEXCEPT_ITERATOR(__first),
  19:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  1d:	48 89 c7             	mov    rdi,rax
  20:	e8 00 00 00 00       	call   25 <_ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_+0x25>
  25:	48 89 c3             	mov    rbx,rax
  28:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  2c:	48 89 c7             	mov    rdi,rax
  2f:	e8 00 00 00 00       	call   34 <_ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_+0x34>
  34:	48 89 c7             	mov    rdi,rax
  37:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
  3b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  3f:	48 89 d1             	mov    rcx,rdx
  42:	48 89 c2             	mov    rdx,rax
  45:	48 89 de             	mov    rsi,rbx
  48:	e8 00 00 00 00       	call   4d <_ZSt34__uninitialized_move_if_noexcept_aIPiS0_SaIiEET0_T_S3_S2_RT1_+0x4d>
	 _GLIBCXX_MAKE_MOVE_IF_NOEXCEPT_ITERATOR(__last), __result, __alloc);
    }
  4d:	48 83 c4 28          	add    rsp,0x28
  51:	5b                   	pop    rbx
  52:	5d                   	pop    rbp
  53:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIiEE7destroyIiEEvRS0_PT_:

0000000000000000 <_ZNSt16allocator_traitsISaIiEE7destroyIiEEvRS0_PT_>:
       *
       *  Calls @c __a.destroy(__p).
      */
      template<typename _Up>
	static void
	destroy(allocator_type& __a, _Up* __p)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
	noexcept(noexcept(__a.destroy(__p)))
	{ __a.destroy(__p); }
  10:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
  14:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  18:	48 89 d6             	mov    rsi,rdx
  1b:	48 89 c7             	mov    rdi,rax
  1e:	e8 00 00 00 00       	call   23 <_ZNSt16allocator_traitsISaIiEE7destroyIiEEvRS0_PT_+0x23>
  23:	90                   	nop
  24:	c9                   	leave  
  25:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIiEC2Ev:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIiEC1Ev>:
      new_allocator() _GLIBCXX_USE_NOEXCEPT { }
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	90                   	nop
   9:	5d                   	pop    rbp
   a:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIiEE10deallocateERS0_Pim:

0000000000000000 <_ZNSt16allocator_traitsISaIiEE10deallocateERS0_Pim>:
      deallocate(allocator_type& __a, pointer __p, size_type __n)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
      { __a.deallocate(__p, __n); }
  14:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
  18:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
  1c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  20:	48 89 ce             	mov    rsi,rcx
  23:	48 89 c7             	mov    rdi,rax
  26:	e8 00 00 00 00       	call   2b <_ZNSt16allocator_traitsISaIiEE10deallocateERS0_Pim+0x2b>
  2b:	90                   	nop
  2c:	c9                   	leave  
  2d:	c3                   	ret    

Disassembly of section .text._ZSt8_DestroyIPiEvT_S1_:

0000000000000000 <_ZSt8_DestroyIPiEvT_S1_>:
    _Destroy(_ForwardIterator __first, _ForwardIterator __last)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
	__destroy(__first, __last);
  10:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
  14:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  18:	48 89 d6             	mov    rsi,rdx
  1b:	48 89 c7             	mov    rdi,rax
  1e:	e8 00 00 00 00       	call   23 <_ZSt8_DestroyIPiEvT_S1_+0x23>
    }
  23:	90                   	nop
  24:	c9                   	leave  
  25:	c3                   	ret    

Disassembly of section .text._ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_copy_dataERKS2_:

0000000000000000 <_ZNSt12_Vector_baseIiSaIiEE17_Vector_impl_data12_M_copy_dataERKS2_>:
	_M_copy_data(_Vector_impl_data const& __x) _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
	  _M_start = __x._M_start;
   c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  10:	48 8b 10             	mov    rdx,QWORD PTR [rax]
  13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  17:	48 89 10             	mov    QWORD PTR [rax],rdx
	  _M_finish = __x._M_finish;
  1a:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  1e:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
  22:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  26:	48 89 50 08          	mov    QWORD PTR [rax+0x8],rdx
	  _M_end_of_storage = __x._M_end_of_storage;
  2a:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  2e:	48 8b 50 10          	mov    rdx,QWORD PTR [rax+0x10]
  32:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  36:	48 89 50 10          	mov    QWORD PTR [rax+0x10],rdx
	}
  3a:	90                   	nop
  3b:	5d                   	pop    rbp
  3c:	c3                   	ret    

Disassembly of section .text._ZSt15__alloc_on_swapISaIiEEvRT_S2_:

0000000000000000 <_ZSt15__alloc_on_swapISaIiEEvRT_S2_>:
  template<typename _Alloc>
    inline void __do_alloc_on_swap(_Alloc&, _Alloc&, false_type)
    { }

  template<typename _Alloc>
    inline void __alloc_on_swap(_Alloc& __one, _Alloc& __two)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  10:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  17:	00 00 
  19:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  1d:	31 c0                	xor    eax,eax
    {
      typedef allocator_traits<_Alloc> __traits;
      typedef typename __traits::propagate_on_container_swap __pocs;
      __do_alloc_on_swap(__one, __two, __pocs());
  1f:	48 8b 55 e0          	mov    rdx,QWORD PTR [rbp-0x20]
  23:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  27:	48 89 d6             	mov    rsi,rdx
  2a:	48 89 c7             	mov    rdi,rax
  2d:	e8 00 00 00 00       	call   32 <_ZSt15__alloc_on_swapISaIiEEvRT_S2_+0x32>
    }
  32:	90                   	nop
  33:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  37:	64 48 33 04 25 28 00 	xor    rax,QWORD PTR fs:0x28
  3e:	00 00 
  40:	74 05                	je     47 <_ZSt15__alloc_on_swapISaIiEEvRT_S2_+0x47>
  42:	e8 00 00 00 00       	call   47 <_ZSt15__alloc_on_swapISaIiEEvRT_S2_+0x47>
  47:	c9                   	leave  
  48:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIiSaIiEE8max_sizeEv:

0000000000000000 <_ZNKSt6vectorIiSaIiEE8max_sizeEv>:
      max_size() const _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return _S_max_size(_M_get_Tp_allocator()); }
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNKSt6vectorIiSaIiEE8max_sizeEv+0x18>
  18:	48 89 c7             	mov    rdi,rax
  1b:	e8 00 00 00 00       	call   20 <_ZNKSt6vectorIiSaIiEE8max_sizeEv+0x20>
  20:	c9                   	leave  
  21:	c3                   	ret    

Disassembly of section .text._ZNKSt6vectorIiSaIiEE4sizeEv:

0000000000000000 <_ZNKSt6vectorIiSaIiEE4sizeEv>:
      size() const _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	48 8b 50 08          	mov    rdx,QWORD PTR [rax+0x8]
  10:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  14:	48 8b 00             	mov    rax,QWORD PTR [rax]
  17:	48 29 c2             	sub    rdx,rax
  1a:	48 89 d0             	mov    rax,rdx
  1d:	48 c1 f8 02          	sar    rax,0x2
  21:	5d                   	pop    rbp
  22:	c3                   	ret    

Disassembly of section .text._ZSt3maxImERKT_S2_S2_:

0000000000000000 <_ZSt3maxImERKT_S2_S2_>:
   *  preprocessor macro.
  */
  template<typename _Tp>
    _GLIBCXX14_CONSTEXPR
    inline const _Tp&
    max(const _Tp& __a, const _Tp& __b)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
    {
      // concept requirements
      __glibcxx_function_requires(_LessThanComparableConcept<_Tp>)
      //return  __a < __b ? __b : __a;
      if (__a < __b)
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 8b 10             	mov    rdx,QWORD PTR [rax]
  13:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  17:	48 8b 00             	mov    rax,QWORD PTR [rax]
  1a:	48 39 c2             	cmp    rdx,rax
  1d:	73 06                	jae    25 <_ZSt3maxImERKT_S2_S2_+0x25>
	return __b;
  1f:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  23:	eb 04                	jmp    29 <_ZSt3maxImERKT_S2_S2_+0x29>
      return __a;
  25:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    }
  29:	5d                   	pop    rbp
  2a:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIiEE8allocateERS0_m:

0000000000000000 <_ZNSt16allocator_traitsISaIiEE8allocateERS0_m>:
      allocate(allocator_type& __a, size_type __n)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
      { return __a.allocate(__n); }
  10:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
  14:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  18:	ba 00 00 00 00       	mov    edx,0x0
  1d:	48 89 ce             	mov    rsi,rcx
  20:	48 89 c7             	mov    rdi,rax
  23:	e8 00 00 00 00       	call   28 <_ZNSt16allocator_traitsISaIiEE8allocateERS0_m+0x28>
  28:	c9                   	leave  
  29:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE14_S_do_relocateEPiS2_S2_RS0_St17integral_constantIbLb1EE:

0000000000000000 <_ZNSt6vectorIiSaIiEE14_S_do_relocateEPiS2_S2_RS0_St17integral_constantIbLb1EE>:
      _S_do_relocate(pointer __first, pointer __last, pointer __result,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
  14:	48 89 4d e0          	mov    QWORD PTR [rbp-0x20],rcx
	return std::__relocate_a(__first, __last, __result, __alloc);
  18:	48 8b 4d e0          	mov    rcx,QWORD PTR [rbp-0x20]
  1c:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
  20:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
  24:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  28:	48 89 c7             	mov    rdi,rax
  2b:	e8 00 00 00 00       	call   30 <_ZNSt6vectorIiSaIiEE14_S_do_relocateEPiS2_S2_RS0_St17integral_constantIbLb1EE+0x30>
      }
  30:	c9                   	leave  
  31:	c3                   	ret    

Disassembly of section .text._ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_:

0000000000000000 <_ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_>:
  // returning a constant iterator when we don't want to move.
  template<typename _Tp, typename _ReturnType
    = typename conditional<__move_if_noexcept_cond<_Tp>::value,
			   const _Tp*, move_iterator<_Tp*>>::type>
    inline _GLIBCXX17_CONSTEXPR _ReturnType
    __make_move_if_noexcept_iterator(_Tp* __i)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  13:	00 00 
  15:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  19:	31 c0                	xor    eax,eax
    { return _ReturnType(__i); }
  1b:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
  1f:	48 8d 45 f0          	lea    rax,[rbp-0x10]
  23:	48 89 d6             	mov    rsi,rdx
  26:	48 89 c7             	mov    rdi,rax
  29:	e8 00 00 00 00       	call   2e <_ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_+0x2e>
  2e:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  32:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
  36:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  3d:	00 00 
  3f:	74 05                	je     46 <_ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_+0x46>
  41:	e8 00 00 00 00       	call   46 <_ZSt32__make_move_if_noexcept_iteratorIiSt13move_iteratorIPiEET0_PT_+0x46>
  46:	c9                   	leave  
  47:	c3                   	ret    

Disassembly of section .text._ZSt22__uninitialized_copy_aISt13move_iteratorIPiES1_iET0_T_S4_S3_RSaIT1_E:

0000000000000000 <_ZSt22__uninitialized_copy_aISt13move_iteratorIPiES1_iET0_T_S4_S3_RSaIT1_E>:
    __uninitialized_copy_a(_InputIterator __first, _InputIterator __last,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
  14:	48 89 4d e0          	mov    QWORD PTR [rbp-0x20],rcx
    { return std::uninitialized_copy(__first, __last, __result); }
  18:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
  1c:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
  20:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  24:	48 89 ce             	mov    rsi,rcx
  27:	48 89 c7             	mov    rdi,rax
  2a:	e8 00 00 00 00       	call   2f <_ZSt22__uninitialized_copy_aISt13move_iteratorIPiES1_iET0_T_S4_S3_RSaIT1_E+0x2f>
  2f:	c9                   	leave  
  30:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIiE7destroyIiEEvPT_:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIiE7destroyIiEEvPT_>:

      template<typename _Up>
	void
	destroy(_Up* __p)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
	noexcept(noexcept( __p->~_Up()))
	{ __p->~_Up(); }
   c:	90                   	nop
   d:	5d                   	pop    rbp
   e:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIiE10deallocateEPim:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIiE10deallocateEPim>:
      deallocate(pointer __p, size_type)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
	::operator delete(__p);
  14:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  18:	48 89 c7             	mov    rdi,rax
  1b:	e8 00 00 00 00       	call   20 <_ZN9__gnu_cxx13new_allocatorIiE10deallocateEPim+0x20>
      }
  20:	90                   	nop
  21:	c9                   	leave  
  22:	c3                   	ret    

Disassembly of section .text._ZNSt12_Destroy_auxILb1EE9__destroyIPiEEvT_S3_:

0000000000000000 <_ZNSt12_Destroy_auxILb1EE9__destroyIPiEEvT_S3_>:
        __destroy(_ForwardIterator, _ForwardIterator) { }
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
   c:	90                   	nop
   d:	5d                   	pop    rbp
   e:	c3                   	ret    

Disassembly of section .text._ZSt18__do_alloc_on_swapISaIiEEvRT_S2_St17integral_constantIbLb0EE:

0000000000000000 <_ZSt18__do_alloc_on_swapISaIiEEvRT_S2_St17integral_constantIbLb0EE>:
    inline void __do_alloc_on_swap(_Alloc&, _Alloc&, false_type)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
    { }
   c:	90                   	nop
   d:	5d                   	pop    rbp
   e:	c3                   	ret    

Disassembly of section .text._ZNSt6vectorIiSaIiEE11_S_max_sizeERKS0_:

0000000000000000 <_ZNSt6vectorIiSaIiEE11_S_max_sizeERKS0_>:
      _S_max_size(const _Tp_alloc_type& __a) _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d d8          	mov    QWORD PTR [rbp-0x28],rdi
   c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
  13:	00 00 
  15:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
  19:	31 c0                	xor    eax,eax
	const size_t __diffmax
  1b:	48 b8 ff ff ff ff ff 	movabs rax,0x1fffffffffffffff
  22:	ff ff 1f 
  25:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
	const size_t __allocmax = _Alloc_traits::max_size(__a);
  29:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  2d:	48 89 c7             	mov    rdi,rax
  30:	e8 00 00 00 00       	call   35 <_ZNSt6vectorIiSaIiEE11_S_max_sizeERKS0_+0x35>
  35:	48 89 45 f0          	mov    QWORD PTR [rbp-0x10],rax
	return (std::min)(__diffmax, __allocmax);
  39:	48 8d 55 f0          	lea    rdx,[rbp-0x10]
  3d:	48 8d 45 e8          	lea    rax,[rbp-0x18]
  41:	48 89 d6             	mov    rsi,rdx
  44:	48 89 c7             	mov    rdi,rax
  47:	e8 00 00 00 00       	call   4c <_ZNSt6vectorIiSaIiEE11_S_max_sizeERKS0_+0x4c>
  4c:	48 8b 00             	mov    rax,QWORD PTR [rax]
      }
  4f:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
  53:	64 48 33 0c 25 28 00 	xor    rcx,QWORD PTR fs:0x28
  5a:	00 00 
  5c:	74 05                	je     63 <_ZNSt6vectorIiSaIiEE11_S_max_sizeERKS0_+0x63>
  5e:	e8 00 00 00 00       	call   63 <_ZNSt6vectorIiSaIiEE11_S_max_sizeERKS0_+0x63>
  63:	c9                   	leave  
  64:	c3                   	ret    

Disassembly of section .text._ZNKSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv:

0000000000000000 <_ZNKSt12_Vector_baseIiSaIiEE19_M_get_Tp_allocatorEv>:
      _M_get_Tp_allocator() const _GLIBCXX_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return this->_M_impl; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	5d                   	pop    rbp
   d:	c3                   	ret    

Disassembly of section .text._ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv:

0000000000000000 <_ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv>:
      allocate(size_type __n, const void* = static_cast<const void*>(0))
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
	if (__n > this->max_size())
  14:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  18:	48 89 c7             	mov    rdi,rax
  1b:	e8 00 00 00 00       	call   20 <_ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv+0x20>
  20:	48 39 45 f0          	cmp    QWORD PTR [rbp-0x10],rax
  24:	0f 97 c0             	seta   al
  27:	84 c0                	test   al,al
  29:	74 05                	je     30 <_ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv+0x30>
	  std::__throw_bad_alloc();
  2b:	e8 00 00 00 00       	call   30 <_ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv+0x30>
	return static_cast<_Tp*>(::operator new(__n * sizeof(_Tp)));
  30:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  34:	48 c1 e0 02          	shl    rax,0x2
  38:	48 89 c7             	mov    rdi,rax
  3b:	e8 00 00 00 00       	call   40 <_ZN9__gnu_cxx13new_allocatorIiE8allocateEmPKv+0x40>
      }
  40:	c9                   	leave  
  41:	c3                   	ret    

Disassembly of section .text._ZSt12__relocate_aIPiS0_SaIiEET0_T_S3_S2_RT1_:

0000000000000000 <_ZSt12__relocate_aIPiS0_SaIiEET0_T_S3_S2_RT1_>:
    }

  template <typename _InputIterator, typename _ForwardIterator,
	    typename _Allocator>
    inline _ForwardIterator
    __relocate_a(_InputIterator __first, _InputIterator __last,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	41 54                	push   r12
   6:	53                   	push   rbx
   7:	48 83 ec 20          	sub    rsp,0x20
   b:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   f:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  13:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
  17:	48 89 4d d0          	mov    QWORD PTR [rbp-0x30],rcx
		 _ForwardIterator __result, _Allocator& __alloc)
    noexcept(noexcept(__relocate_a_1(std::__niter_base(__first),
				     std::__niter_base(__last),
				     std::__niter_base(__result), __alloc)))
    {
      return __relocate_a_1(std::__niter_base(__first),
  1b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  1f:	48 89 c7             	mov    rdi,rax
  22:	e8 00 00 00 00       	call   27 <_ZSt12__relocate_aIPiS0_SaIiEET0_T_S3_S2_RT1_+0x27>
  27:	49 89 c4             	mov    r12,rax
  2a:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  2e:	48 89 c7             	mov    rdi,rax
  31:	e8 00 00 00 00       	call   36 <_ZSt12__relocate_aIPiS0_SaIiEET0_T_S3_S2_RT1_+0x36>
  36:	48 89 c3             	mov    rbx,rax
  39:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  3d:	48 89 c7             	mov    rdi,rax
  40:	e8 00 00 00 00       	call   45 <_ZSt12__relocate_aIPiS0_SaIiEET0_T_S3_S2_RT1_+0x45>
  45:	48 89 c7             	mov    rdi,rax
  48:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
  4c:	48 89 c1             	mov    rcx,rax
  4f:	4c 89 e2             	mov    rdx,r12
  52:	48 89 de             	mov    rsi,rbx
  55:	e8 00 00 00 00       	call   5a <_ZSt12__relocate_aIPiS0_SaIiEET0_T_S3_S2_RT1_+0x5a>
			    std::__niter_base(__last),
			    std::__niter_base(__result), __alloc);
    }
  5a:	48 83 c4 20          	add    rsp,0x20
  5e:	5b                   	pop    rbx
  5f:	41 5c                	pop    r12
  61:	5d                   	pop    rbp
  62:	c3                   	ret    

Disassembly of section .text._ZNSt13move_iteratorIPiEC2ES0_:

0000000000000000 <_ZNSt13move_iteratorIPiEC1ES0_>:
      move_iterator(iterator_type __i)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
      : _M_current(__i) { }
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
  14:	48 89 10             	mov    QWORD PTR [rax],rdx
  17:	90                   	nop
  18:	5d                   	pop    rbp
  19:	c3                   	ret    

Disassembly of section .text._ZSt18uninitialized_copyISt13move_iteratorIPiES1_ET0_T_S4_S3_:

0000000000000000 <_ZSt18uninitialized_copyISt13move_iteratorIPiES1_ET0_T_S4_S3_>:
    uninitialized_copy(_InputIterator __first, _InputIterator __last,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  10:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
      const bool __assignable = is_assignable<_RefType2, _RefType1>::value;
  14:	c6 45 ff 01          	mov    BYTE PTR [rbp-0x1],0x1
	__uninit_copy(__first, __last, __result);
  18:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
  1c:	48 8b 4d e0          	mov    rcx,QWORD PTR [rbp-0x20]
  20:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  24:	48 89 ce             	mov    rsi,rcx
  27:	48 89 c7             	mov    rdi,rax
  2a:	e8 00 00 00 00       	call   2f <_ZSt18uninitialized_copyISt13move_iteratorIPiES1_ET0_T_S4_S3_+0x2f>
    }
  2f:	c9                   	leave  
  30:	c3                   	ret    

Disassembly of section .text._ZNSt16allocator_traitsISaIiEE8max_sizeERKS0_:

0000000000000000 <_ZNSt16allocator_traitsISaIiEE8max_sizeERKS0_>:
      max_size(const allocator_type& __a) noexcept
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return __a.max_size(); }
   c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZNSt16allocator_traitsISaIiEE8max_sizeERKS0_+0x18>
  18:	c9                   	leave  
  19:	c3                   	ret    

Disassembly of section .text._ZSt3minImERKT_S2_S2_:

0000000000000000 <_ZSt3minImERKT_S2_S2_>:
    min(const _Tp& __a, const _Tp& __b)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
      if (__b < __a)
   c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  10:	48 8b 10             	mov    rdx,QWORD PTR [rax]
  13:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  17:	48 8b 00             	mov    rax,QWORD PTR [rax]
  1a:	48 39 c2             	cmp    rdx,rax
  1d:	73 06                	jae    25 <_ZSt3minImERKT_S2_S2_+0x25>
	return __b;
  1f:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  23:	eb 04                	jmp    29 <_ZSt3minImERKT_S2_S2_+0x29>
      return __a;
  25:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    }
  29:	5d                   	pop    rbp
  2a:	c3                   	ret    

Disassembly of section .text._ZNK9__gnu_cxx13new_allocatorIiE8max_sizeEv:

0000000000000000 <_ZNK9__gnu_cxx13new_allocatorIiE8max_sizeEv>:
      max_size() const _GLIBCXX_USE_NOEXCEPT
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
	return size_t(__PTRDIFF_MAX__) / sizeof(_Tp);
   8:	48 b8 ff ff ff ff ff 	movabs rax,0x1fffffffffffffff
   f:	ff ff 1f 
      }
  12:	5d                   	pop    rbp
  13:	c3                   	ret    

Disassembly of section .text._ZSt12__niter_baseIPiET_S1_:

0000000000000000 <_ZSt12__niter_baseIPiET_S1_>:

  // Fallback implementation of the function in bits/stl_iterator.h used to
  // remove the __normal_iterator wrapper. See copy, fill, ...
  template<typename _Iterator>
    inline _Iterator
    __niter_base(_Iterator __it)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
    _GLIBCXX_NOEXCEPT_IF(std::is_nothrow_copy_constructible<_Iterator>::value)
    { return __it; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	5d                   	pop    rbp
   d:	c3                   	ret    

Disassembly of section .text._ZSt14__relocate_a_1IiiENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E:

0000000000000000 <_ZSt14__relocate_a_1IiiENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E>:
    __relocate_a_1(_Tp* __first, _Tp* __last,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  10:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
  14:	48 89 4d d0          	mov    QWORD PTR [rbp-0x30],rcx
      ptrdiff_t __count = __last - __first;
  18:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  1c:	48 2b 45 e8          	sub    rax,QWORD PTR [rbp-0x18]
  20:	48 c1 f8 02          	sar    rax,0x2
  24:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
      if (__count > 0)
  28:	48 83 7d f8 00       	cmp    QWORD PTR [rbp-0x8],0x0
  2d:	7e 1f                	jle    4e <_ZSt14__relocate_a_1IiiENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E+0x4e>
	__builtin_memmove(__result, __first, __count * sizeof(_Tp));
  2f:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  33:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  3a:	00 
  3b:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
  3f:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  43:	48 89 ce             	mov    rsi,rcx
  46:	48 89 c7             	mov    rdi,rax
  49:	e8 00 00 00 00       	call   4e <_ZSt14__relocate_a_1IiiENSt9enable_ifIXsrSt24__is_bitwise_relocatableIT_vE5valueEPS2_E4typeES4_S4_S4_RSaIT0_E+0x4e>
      return __result + __count;
  4e:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  52:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  59:	00 
  5a:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  5e:	48 01 d0             	add    rax,rdx
    }
  61:	c9                   	leave  
  62:	c3                   	ret    

Disassembly of section .text._ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPiES3_EET0_T_S6_S5_:

0000000000000000 <_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPiES3_EET0_T_S6_S5_>:
        __uninit_copy(_InputIterator __first, _InputIterator __last,
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 20          	sub    rsp,0x20
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   c:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
  10:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
        { return std::copy(__first, __last, __result); }
  14:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
  18:	48 8b 4d f0          	mov    rcx,QWORD PTR [rbp-0x10]
  1c:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  20:	48 89 ce             	mov    rsi,rcx
  23:	48 89 c7             	mov    rdi,rax
  26:	e8 00 00 00 00       	call   2b <_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt13move_iteratorIPiES3_EET0_T_S6_S5_+0x2b>
  2b:	c9                   	leave  
  2c:	c3                   	ret    

Disassembly of section .text._ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_:

0000000000000000 <_ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_>:
   *  Note that the end of the output range is permitted to be contained
   *  within [first,last).
  */
  template<typename _II, typename _OI>
    inline _OI
    copy(_II __first, _II __last, _OI __result)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	53                   	push   rbx
   5:	48 83 ec 28          	sub    rsp,0x28
   9:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   d:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  11:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
      __glibcxx_function_requires(_OutputIteratorConcept<_OI,
	    typename iterator_traits<_II>::value_type>)
      __glibcxx_requires_can_increment_range(__first, __last, __result);

      return std::__copy_move_a2<__is_move_iterator<_II>::__value>
	     (std::__miter_base(__first), std::__miter_base(__last), __result);
  15:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  19:	48 89 c7             	mov    rdi,rax
  1c:	e8 00 00 00 00       	call   21 <_ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_+0x21>
  21:	48 89 c3             	mov    rbx,rax
  24:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  28:	48 89 c7             	mov    rdi,rax
  2b:	e8 00 00 00 00       	call   30 <_ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_+0x30>
  30:	48 89 c1             	mov    rcx,rax
  33:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  37:	48 89 c2             	mov    rdx,rax
  3a:	48 89 de             	mov    rsi,rbx
  3d:	48 89 cf             	mov    rdi,rcx
  40:	e8 00 00 00 00       	call   45 <_ZSt4copyISt13move_iteratorIPiES1_ET0_T_S4_S3_+0x45>
    }
  45:	48 83 c4 28          	add    rsp,0x28
  49:	5b                   	pop    rbx
  4a:	5d                   	pop    rbp
  4b:	c3                   	ret    

Disassembly of section .text._ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E:

0000000000000000 <_ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E>:
      typedef __true_type __type;
    };

  template<typename _Iterator>
    auto
    __miter_base(move_iterator<_Iterator> __it)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 10          	sub    rsp,0x10
   8:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
    -> decltype(__miter_base(__it.base()))
    { return __miter_base(__it.base()); }
   c:	48 8d 45 f8          	lea    rax,[rbp-0x8]
  10:	48 89 c7             	mov    rdi,rax
  13:	e8 00 00 00 00       	call   18 <_ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E+0x18>
  18:	48 89 c7             	mov    rdi,rax
  1b:	e8 00 00 00 00       	call   20 <_ZSt12__miter_baseIPiEDTcl12__miter_basecldtfp_4baseEEESt13move_iteratorIT_E+0x20>
  20:	c9                   	leave  
  21:	c3                   	ret    

Disassembly of section .text._ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_:

0000000000000000 <_ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_>:
    __copy_move_a2(_II __first, _II __last, _OI __result)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	41 54                	push   r12
   6:	53                   	push   rbx
   7:	48 83 ec 20          	sub    rsp,0x20
   b:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   f:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  13:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
      return std::__niter_wrap(__result,
  17:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  1b:	48 89 c7             	mov    rdi,rax
  1e:	e8 00 00 00 00       	call   23 <_ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_+0x23>
  23:	49 89 c4             	mov    r12,rax
  26:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  2a:	48 89 c7             	mov    rdi,rax
  2d:	e8 00 00 00 00       	call   32 <_ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_+0x32>
  32:	48 89 c3             	mov    rbx,rax
  35:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  39:	48 89 c7             	mov    rdi,rax
  3c:	e8 00 00 00 00       	call   41 <_ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_+0x41>
  41:	4c 89 e2             	mov    rdx,r12
  44:	48 89 de             	mov    rsi,rbx
  47:	48 89 c7             	mov    rdi,rax
  4a:	e8 00 00 00 00       	call   4f <_ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_+0x4f>
  4f:	48 89 c2             	mov    rdx,rax
  52:	48 8d 45 d8          	lea    rax,[rbp-0x28]
  56:	48 89 d6             	mov    rsi,rdx
  59:	48 89 c7             	mov    rdi,rax
  5c:	e8 00 00 00 00       	call   61 <_ZSt14__copy_move_a2ILb1EPiS0_ET1_T0_S2_S1_+0x61>
    }
  61:	48 83 c4 20          	add    rsp,0x20
  65:	5b                   	pop    rbx
  66:	41 5c                	pop    r12
  68:	5d                   	pop    rbp
  69:	c3                   	ret    

Disassembly of section .text._ZNKSt13move_iteratorIPiE4baseEv:

0000000000000000 <_ZNKSt13move_iteratorIPiE4baseEv>:
      base() const
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
      { return _M_current; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	48 8b 00             	mov    rax,QWORD PTR [rax]
   f:	5d                   	pop    rbp
  10:	c3                   	ret    

Disassembly of section .text._ZSt12__miter_baseIPiET_S1_:

0000000000000000 <_ZSt12__miter_baseIPiET_S1_>:

  // Fallback implementation of the function in bits/stl_iterator.h used to
  // remove the move_iterator wrapper.
  template<typename _Iterator>
    inline _Iterator
    __miter_base(_Iterator __it)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
    { return __it; }
   8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
   c:	5d                   	pop    rbp
   d:	c3                   	ret    

Disassembly of section .text._ZSt13__copy_move_aILb1EPiS0_ET1_T0_S2_S1_:

0000000000000000 <_ZSt13__copy_move_aILb1EPiS0_ET1_T0_S2_S1_>:
    __copy_move_a(_II __first, _II __last, _OI __result)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  10:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
      const bool __simple = (__is_trivially_copyable(_ValueTypeI)
  14:	c6 45 ff 01          	mov    BYTE PTR [rbp-0x1],0x1
			      _Category>::__copy_m(__first, __last, __result);
  18:	48 8b 55 d8          	mov    rdx,QWORD PTR [rbp-0x28]
  1c:	48 8b 4d e0          	mov    rcx,QWORD PTR [rbp-0x20]
  20:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
  24:	48 89 ce             	mov    rsi,rcx
  27:	48 89 c7             	mov    rdi,rax
  2a:	e8 00 00 00 00       	call   2f <_ZSt13__copy_move_aILb1EPiS0_ET1_T0_S2_S1_+0x2f>
    }
  2f:	c9                   	leave  
  30:	c3                   	ret    

Disassembly of section .text._ZSt12__niter_wrapIPiET_RKS1_S1_:

0000000000000000 <_ZSt12__niter_wrapIPiET_RKS1_S1_>:
    __niter_wrap(const _Iterator&, _Iterator __res)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
   8:	48 89 75 f0          	mov    QWORD PTR [rbp-0x10],rsi
    { return __res; }
   c:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
  10:	5d                   	pop    rbp
  11:	c3                   	ret    

Disassembly of section .text._ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_:

0000000000000000 <_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_>:
	__copy_m(const _Tp* __first, const _Tp* __last, _Tp* __result)
   0:	55                   	push   rbp
   1:	48 89 e5             	mov    rbp,rsp
   4:	48 83 ec 30          	sub    rsp,0x30
   8:	48 89 7d e8          	mov    QWORD PTR [rbp-0x18],rdi
   c:	48 89 75 e0          	mov    QWORD PTR [rbp-0x20],rsi
  10:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
	  const ptrdiff_t _Num = __last - __first;
  14:	48 8b 45 e0          	mov    rax,QWORD PTR [rbp-0x20]
  18:	48 2b 45 e8          	sub    rax,QWORD PTR [rbp-0x18]
  1c:	48 c1 f8 02          	sar    rax,0x2
  20:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
	  if (_Num)
  24:	48 83 7d f8 00       	cmp    QWORD PTR [rbp-0x8],0x0
  29:	74 1f                	je     4a <_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_+0x4a>
	    __builtin_memmove(__result, __first, sizeof(_Tp) * _Num);
  2b:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  2f:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  36:	00 
  37:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
  3b:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  3f:	48 89 ce             	mov    rsi,rcx
  42:	48 89 c7             	mov    rdi,rax
  45:	e8 00 00 00 00       	call   4a <_ZNSt11__copy_moveILb1ELb1ESt26random_access_iterator_tagE8__copy_mIiEEPT_PKS3_S6_S4_+0x4a>
	  return __result + _Num;
  4a:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
  4e:	48 8d 14 85 00 00 00 	lea    rdx,[rax*4+0x0]
  55:	00 
  56:	48 8b 45 d8          	mov    rax,QWORD PTR [rbp-0x28]
  5a:	48 01 d0             	add    rax,rdx
	}
  5d:	c9                   	leave  
  5e:	c3                   	ret    
