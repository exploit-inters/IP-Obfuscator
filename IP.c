#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void banner() {
  fflush(stdin);
  const static char *banner = 
"\n\t    IP Obfuscator   \n"
"\t   Coded by @X_b3o1   \n"
"\t  https://t.me/X_b3o1 \n";
  for(banner; *banner; ++banner) fprintf(stdout, "%c", *banner);            
}

int isValidIp(char *str) {
    int segs = 0;    
    int chcnt = 0;   
    int accum = 0;   

    if (!str) return 0;

    while (*str) {
        if (*str == '.') {
            if (!chcnt) return 0;
            if (++segs == 4) return 0;
            chcnt = accum = 0;
            str++;
            continue;
        }
        if ((*str < '0') || (*str > '9')) return 0;
        if ((accum = accum * 10 + *str - '0') > 255) return 0;
        chcnt++;
        str++;
    }
    if (segs != 3) return 0;
    if (!chcnt) return 0;
    return 1;
}

int main(){
	banner();
	size_t i;
	char ip[100], *token;
	unsigned int dec[3];
	const char deli[2] = ".";
	const char *http = "[+] http://";

	printf("\n[+] IP: ");
	fgets(ip, sizeof(ip), stdin);
	strtok(ip, "\n");
	
	if(!isValidIp(ip)) {
		fprintf(stderr,"%s","[!] Enter a valid ip\n");
		exit(-1);
	}
	token = strtok(ip, deli);
	
	for(i=0; token; i++){
		*(dec+i) = atoi(token);
		token = strtok(NULL, deli);
	}
	
	puts("\n[~] Obfuscated IPs :\n");
	printf("[+] http://%u\n",(*dec << 24)|(*(dec+1) << 16)|(*(dec+2) << 8)|*(dec+3));
	printf("%s", http);
	for(i=0;i<4;i++) printf( i == 3 ? "0x%02X\n" : "0x%02X.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++) printf( i == 3 ? "%04o\n" : "%04o.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++) printf( i == 3 ? "0x%010X\n" : "0x%010X.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++) printf( i == 3 ? "%010o\n\n" : "%010o.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++) printf( i == 3 ? "%i\n" :"0x%02X.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++)
		printf( i >= 2 ? i == 3 ? "%i\n" : "%i." : "0x%02X.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++)
		printf( i >= 1 ? i == 3 ? "%i\n\n" : "%i." : "0x%02X.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++) printf( i == 3 ? "%i\n" :"%04o.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++)
		printf( i >= 2 ? i == 3 ? "%i\n" : "%i." : "%04o.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++)
		printf( i >= 1 ? i == 3 ? "%i\n\n" : "%i." : "%04o.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++) 
		if(i < 2) printf("0x%02X.",dec[i]);
		printf("%u\n", (*(dec+2) << 8)|*(dec+3));
	printf("%s", http);
	for(i=0;i<4;i++) 
		if(i < 2) printf("%04o.",dec[i]);
		printf("%u\n", (*(dec+2) << 8)|*(dec+3));
	printf("%s", http);
	for(i=0;i<2;i++)
		printf( i >= 1 ? "%04o." : "0x%02X.",dec[i]);
		printf("%u\n", (*(dec+2) << 8)|*(dec+3));
	printf("%s", http);
	for(i=0;i<4;i++) 
		if(i < 1) printf("0x%02X.",dec[i]);
		printf("%u\n", (*(dec+1) << 16)|(*(dec+2) << 8)|*(dec+3));
	printf("%s", http);
	for(i=0;i<4;i++) 
		if(i < 1) printf("%04o.",dec[i]);
		printf("%u\n", (*(dec+1) << 16)|(*(dec+2) << 8)|*(dec+3));
	printf("%s", http);
	for(i=0;i<4;i++)
		printf( i >= 2 ? i == 3 ? "%04o\n" : "%04o." : "0x%02X.",dec[i]);
	printf("%s", http);
	for(i=0;i<4;i++)
		printf( i >= 1 ? i == 3 ? "%04o\n" : "%04o." : "0x%02X.",dec[i]);
	printf("%s", http);
	for(i=0;i<2;i++)
		printf( i >= 1 ? "%04o." : "0x%02X.",dec[i]);
		printf("%u\n",(*(dec+2) << 8)|*(dec+3));

#ifndef __unix__ 
	system("pause > nul");
#endif
	return 0;
}

