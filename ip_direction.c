#include <stdio.h>
#include <string.h>

int main() {
	unsigned char ip[4];		
	printf("Ingresa tu direccion IP\n");
	scanf("%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);	
	if(ip[0] & 128){		
		if(ip[0] & 64){
			if(ip[0] & 32) {
				if(ip[0] & 16) {
					puts("Es de clase E");
				} else {
					puts("Es de clase D");
				}
			} else {
				puts("Es de clase C");
			}
		} else {
			puts("es de clase B");
		}
	} else {
		puts("es de clase A");
	}			
	system("pause");
	return 0;
}