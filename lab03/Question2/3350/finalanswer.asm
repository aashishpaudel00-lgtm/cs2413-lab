.386
.model flat, stdcall
.stack 4096

.data
    myarr sbyte -5, -6, -7, -4

.code
main PROC
    mov esi, OFFSET myarr
    mov ecx, 4
    mov dl, 0

sumLoop:
    mov al, [esi]
    neg al          ; convert to positive (absolute value)
    add dl, al      ; add to dl
    inc esi
    loop sumLoop

    ; dl = 22 (5+6+7+4 = 22)

main ENDP
END main