.486
.model flat
.data
array dd 0,0,0,0,0,0,0,0,0,0
array2 dd 0,0,0,0,0,0,0,0,0,0
array3 dd 0,0,0,0,0,0,0,0,0,0
array4 dd 0,0,0,0,0,0,0,0,0,0
array5 dd 0,0,0,0,0,0,0,0,0,0
X dd 0,0,0,0,0,0,0,0,0,0
something dd 1
lenofmas dd 0
lenofmas2 dd 0
repeating dd 0
fl dd 0
.code
Public _sortmassiv
_sortmassiv proc
push ebp
mov ebp,esp

starting:
mov eax,[ebp+8]
mov lenofmas,eax
mov ecx,lenofmas
mov something,0
mov repeating,0
mov eax,0
xor edx,edx
xor esi,esi
xor edi,edi
mov esi,[ebp+12+4*edx]

movingelements:
mov edi,[esi+edx*4]
mov [array+edx*4],edi
inc edx
loop movingelements

sorting:
mov edi,[ebp+8]
inc something
cmp something,edi
je repeatif
mov ecx,[array+eax*4]
mov esi,[array+eax*4+4]
cmp ecx,esi
jg greater
inc eax
jmp sorting

greater:
mov [array+eax*4],esi
mov [array+eax*4+4],ecx
inc eax
jmp sorting

repeatif:
inc repeating
cmp repeating,edi
je somethingif
mov eax,0
mov something,1
jmp sorting

somethingif:
mov eax,[ebp+8]
mov lenofmas,eax
mov eax,[ebp+12]
xor edi,edi

massivX:
cmp fl,1
je endofasm
mov esi,[eax]
mov [X+edi*4],esi
xor esi,esi
inc edi
add eax,4
cmp edi,lenofmas
je endofasm
jmp massivX

endofasm:
mov something,0
inc fl
pop ebp
_sortmassiv endp
ret

Public _printing
_printing proc
mov edx,something
mov eax,[array+edx*4]
inc something
ret
_printing endp

Public _searching
_searching proc
push ebp
mov ebp,esp
xor edx,edx
mov repeating,0
mov something,0
mov fl,0
mov eax,0
mov ebx,-1
mov esi,[ebp+8]
mov edi,[ebp+12]

starting:
inc ebx
mov eax,0
cmp ebx,esi
je endiff

searchif:
mov ecx,[X+ebx*4]
mov edx,[array+eax*4]
cmp ecx,edx
je increase
inc eax
cmp eax,edi
je starting
jmp searchif

increase:
inc repeating
inc eax
cmp eax,edi
je starting
jmp searchif

endiff:
mov eax,repeating
pop ebp
ret
_searching endp

Public _sameelements
_sameelements proc

push ebp
mov ebp,esp
mov ebx,[ebp+8]
mov lenofmas,ebx
lea edx,X
mov ebx,0
mov esi,0
		
starting:
mov eax, [array2 + esi * 4]	
cmp [edx + ebx * 4], eax
je equalif
cmp eax,0
je zeroif
inc esi
cmp ebx,lenofmas
jl starting
jmp somethingif

equalif:
inc [array3 + esi * 4]
mov eax, [edx + ebx * 4]
mov [array2 + esi * 4], eax
xor esi, esi
inc ebx
jmp starting

zeroif:
mov eax, [edx + ebx * 4]
mov [array2 + esi * 4], eax
inc [array3 + esi * 4]
inc ebx
mov esi,0
jmp starting

somethingif:
pop ebp
ret
_sameelements endp

Public _sameelements2 ;dfghghjkdfghjkdfghjfghj
_sameelements2 proc

push ebp
mov ebp,esp
mov ebx,[ebp+8]
mov lenofmas,ebx
lea edx,array
mov ebx,0
mov esi,0
		
starting:
mov eax, [array4 + esi * 4]	
cmp [edx + ebx * 4], eax
je equalif
cmp eax,0
je zeroif
inc esi
cmp ebx,lenofmas
jl starting
jmp somethingif

equalif:
inc [array5 + esi * 4]
mov eax, [edx + ebx * 4]
mov [array4 + esi * 4], eax
xor esi, esi
inc ebx
jmp starting

zeroif:
mov eax, [edx + ebx * 4]
mov [array4 + esi * 4], eax
inc [array5 + esi * 4]
inc ebx
mov esi,0
jmp starting

somethingif:
pop ebp
mov eax,[array5+4]
ret
_sameelements2 endp

Public _numofelements
_numofelements proc
push ebp
mov ebp,esp
mov esi,0
mov edi,0
mov something,0
mov edx,[ebp+8]
mov lenofmas,edx
mov edx,[ebp+12]
mov lenofmas2,edx

starting:
mov eax,[array2+esi*4]
mov ebx,[array4+edi*4]
cmp eax,0
je endofasm
cmp eax,ebx
je equal
inc edi
cmp edi,lenofmas2
je some
cmp esi,lenofmas
je endofasm
jmp starting

some:
mov edi,0
inc esi
cmp esi,lenofmas
je endofasm
jmp starting

equal:
mov eax,[array3+esi*4]
mov ebx,[array5+edi*4]
cmp eax,ebx
jl lessif
add something,ebx
inc esi
mov edi,0
jmp starting

lessif:
add something,eax
inc esi
mov edi,0
jmp starting

endofasm:
mov eax,something
pop ebp
ret
_numofelements endp
end