#include <stdio.h>

int main(void) {
	int x, y;
	printf("Początkowa wartość: x=%d, y=%d\n", x, y);

	y = 2137;
	x = y;

	x += 3;
	x *= 2;

	printf("Końcowa wartość: x=%d, y=%d\n", x, y);

	return 0;
}

// GDB main disassemble
/* 0x0000000000001139 <+0>:		push   rbp
   0x000000000000113a <+1>:		mov    rbp,rsp
   0x000000000000113d <+4>:		sub    rsp,0x10                         ? Alokuje pamięć na stosie
   0x0000000000001141 <+8>:		mov    edx,DWORD PTR [rbp-0x4]          ? Deklaracja x, y
   0x0000000000001144 <+11>:	mov    eax,DWORD PTR [rbp-0x8]
   0x0000000000001147 <+14>:	mov    esi,eax
   0x0000000000001149 <+16>:	lea    rax,[rip+0xeb8]        # 0x2008
   0x0000000000001150 <+23>:	mov    rdi,rax
   0x0000000000001153 <+26>:	mov    eax,0x0
   0x0000000000001158 <+31>:	call   0x1030 <printf@plt>				? Pierwsze wywołanie printf
   0x000000000000115d <+36>:	mov    DWORD PTR [rbp-0x4],0x859		? y=2137
   0x0000000000001164 <+43>:	mov    eax,DWORD PTR [rbp-0x4]			
   0x0000000000001167 <+46>:	mov    DWORD PTR [rbp-0x8],eax			? x = y
   0x000000000000116a <+49>:	add    DWORD PTR [rbp-0x8],0x3			? x += 3
   0x000000000000116a <+49>:	shl    DWORD PTR [rbp-0x8],1			? x *= 2 (https://www.aldeid.com/wiki/X86-assembly/Instructions/shl)
   0x000000000000116d <+52>:	mov    edx,DWORD PTR [rbp-0x4]
   0x0000000000001170 <+55>:	mov    eax,DWORD PTR [rbp-0x8]
   0x0000000000001173 <+58>:	mov    esi,eax
   0x0000000000001175 <+60>:	lea    rax,[rip+0xeb4]        # 0x2030
   0x000000000000117c <+67>:	mov    rdi,rax
   0x000000000000117f <+70>:	mov    eax,0x0
   0x0000000000001184 <+75>:	call   0x1030 <printf@plt>				? Drugie wywołanie printf
*/

