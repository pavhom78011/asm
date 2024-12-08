.486
.model flat
.data
one dd 1
ten dd 10
two dd 2
y dd 1
lenofmas dd 0
array dd 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
array2 dd 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
lastelement dd 0
.code
Public _digitis
_digitis proc
push ebp
mov ebp,esp
mov eax,[ebp+8]
mov ecx,0

digits:
cmp eax,0
jle endofasm
imul one
idiv ten
xchg eax,edx
mov ebx,edx
mov esi,eax
imul one
idiv two
cmp edx,1
je equal
mov eax,ebx
jmp digits

equal:
mov eax,y
imul esi
mov y,eax
mov eax,ebx
jmp digits

endofasm:
mov eax,y

pop ebp
ret 
_digitis endp

Public _some
_some proc
push ebp
mov ebp,esp

mov ecx,[ebp+8]
mov lenofmas,ecx
mov esi,0
mov edi,[ebp+12]
mov edx,lenofmas

moving:
mov eax,[edi+esi*4]
mov[array+4*esi],eax
inc esi
loop moving

mov ebx,[array+edx*4-4]
mov lastelement,ebx
pop ebp
_some endp

Public _digits
_digits proc

mov ebx,lenofmas
xor esi,esi
xor edi,edi
xor edx,edx

beginning:
mov edi,[array+esi*4]
cmp y,edi
jg Ygreater
inc esi
cmp esi,ebx
je endofasm
jmp beginning

Ygreater:
cmp lastelement,edi
jl lessif
inc esi
cmp esi,ebx
je endofasm
jmp beginning

lessif:
mov [array2+edx*4],edi
inc edx
inc esi
cmp esi,ebx
je endofasm
jmp beginning

endofasm:
mov esi,0
mov y,0
mov eax,[array2]
ret
_digits endp

Public _printing
_printing proc
mov esi,y
mov ebx,[array2+esi*4]
cmp ebx,0
je endofasm
mov eax,[array2+esi*4]
inc y
jmp endiff

endofasm:
mov eax,-1

endiff:
ret
_printing endp
end