#include <stdio.h>
#include <string.h>

int main() {
	unsigned char ip[4] = {0, 0, 0, 0};
	unsigned char mask[4] = {0, 0, 0, 0}, bit = 1, cont = 0;	
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
				mask[0] = 255; mask[1] = 255; mask[2] = 255;	
				/*----------CLASE-----------*/
				puts("Es de clase C");
				/*----------MÁSCARA---------*/
				printf("La mascara de subred es: %i.%i.%i.%i\n", mask[0], mask[1], mask[2], mask[3]);
				/*----------TIPO-----------*/
				for(bit; bit < 128; bit = bit << 1) {
					if(ip[3] & bit){
						cont++;
					}
				}
				if(cont != 0) {
					if(cont == 7) {
						printf("La direccion IP es de broadcast\n");
					} else {
						printf("La direccion IP es de host\n");
					}
				} else {
					printf("La direccion IP es de red\n");
				}
				/*----------DIRECCION DE RED-----------*/
				printf("La ip de red es: %d.%d.%d.%d\n", ip[0] & mask[0], ip[1] & mask[1], ip[2] & mask[2], ip[3] & mask[3]);
				/*----------RANGO DE HOST-----------*/
				printf("El rango de host es %d.%d.%d.%d-", ip[0] & mask[0], ip[1] & mask[1], ip[2] & mask[2], (ip[3] & mask[3]) + 1);
				mask[0] = ~mask[0]; mask[1] = ~mask[1]; mask[2] = ~mask[2]; mask[3] = ~mask[3];
				printf("%d.%d.%d.%d\n", ip[0] | mask[0], ip[1] | mask[1], ip[2] | mask[2], (ip[3] | mask[3])-1);
				/*----------DIRECCION DE BROADCAST-----------*/							
				printf("La ip de broadcast es: %i.%i.%i.%i\n", ip[0] | mask[0], ip[1] | mask[1], ip[2] | mask[2], ip[3] | mask[3]);						
			}
		} else {	
			mask[0] = 255; mask[1] = 255;		
			/*----------CLASE-----------*/
			puts("es de clase B");
			/*----------MÁSCARA---------*/
			printf("La mascara de subred es: %i.%i.%i.%i\n", mask[0], mask[1], mask[2], mask[3]);
			/*----------TIPO-----------*/
			for(bit; bit < 128; bit = bit << 1) {
				if(ip[3] & bit) {
					cont++;
				}
			}
			for(bit; bit < 128; bit = bit << 1) {
				if(ip[2] & bit) {
					cont++;
				}
			}
			if(cont != 0) {
				if(cont == 14) {
					printf("La direccion IP es de broadcast\n");
				} else {
					printf("La direccion IP es de host\n");
				}
			} else {
				printf("La direccion IP es de red\n");
			}
			/*----------DIRECCION DE RED-----------*/
			printf("La ip de red es: %d.%d.%d.%d\n", ip[0] & mask[0], ip[1] & mask[1], ip[2] & mask[2], ip[3] & mask[3]);
			/*----------RANGO DE HOST-----------*/
			printf("El rango de host es %d.%d.%d.%d-", ip[0] & mask[0], ip[1] & mask[1], ip[2] & mask[2], (ip[3] & mask[3]) + 1);
			mask[0] = ~mask[0]; mask[1] = ~mask[1]; mask[2] = ~mask[2]; mask[3] = ~mask[3];
			printf("%d.%d.%d.%d\n", ip[0] | mask[0], ip[1] | mask[1], ip[2] | mask[2], (ip[3] | mask[3])-1);
			/*----------DIRECCION DE BROADCAST-----------*/								
			printf("La ip de broadcast es: %i.%i.%i.%i\n", ip[0] | mask[0], ip[1] | mask[1], ip[2] | mask[2], ip[3] | mask[3]);	

		}
	} else {		
		mask[0] = 255; 		
		/*----------CLASE----------*/
		puts("es de clase A");		
		/*----------MÁSCARA---------*/
		printf("La mascara de subred es: %i.%i.%i.%i\n", mask[0], mask[1], mask[2], mask[3]);
		/*----------TIPO-----------*/
		for(bit; bit < 128; bit = bit << 1) {			
			if(ip[3] & bit){
				cont++;						
			}										
		}		
		for(bit; bit < 128; bit = bit << 1) {
			if(ip[2] & bit) {
				cont++;
			}
		}
		for(bit; bit < 128; bit = bit << 1) {
			if(ip[1] & bit) {
				cont++;
			}
		}		
		if(cont != 0) {
			if(cont == 21) {
				printf("La direccion IP es de broadcast\n");
			} else {
				printf("La direccion IP es de host\n");
			}
		} else {
			printf("La direccion IP es de red\n");
		}
		/*----------DIRECCION DE RED-----------*/
		printf("La ip de red es: %d.%d.%d.%d\n", ip[0] & mask[0], ip[1] & mask[1], ip[2] & mask[2], ip[3] & mask[3]);
		/*----------RANGO DE HOST-----------*/		
		printf("El rango de host es %d.%d.%d.%d-", ip[0] & mask[0], ip[1] & mask[1], ip[2] & mask[2], (ip[3] & mask[3]) + 1);
		mask[0] = ~mask[0]; mask[1] = ~mask[1]; mask[2] = ~mask[2]; mask[3] = ~mask[3];
		printf("%d.%d.%d.%d\n", ip[0] | mask[0], ip[1] | mask[1], ip[2] | mask[2], (ip[3] | mask[3])-1);
		/*----------DIRECCION DE BROADCAST-----------*/		
		printf("La ip de broadcast es: %i.%i.%i.%i\n", ip[0] | mask[0], ip[1] | mask[1], ip[2] | mask[2], ip[3] | mask[3]);						
	}			
	system("pause");
	return 0;
}