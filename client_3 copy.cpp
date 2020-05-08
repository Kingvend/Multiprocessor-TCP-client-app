/*
 * client_3.cpp
 *
 * Copyright 2020 Alex <alex@alex-pc>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct sockaddr_in peer;
	int s, t, t1;
	int i;
	int CountStudent;
	int rc;
	char buf[256], p, p1, b[256];

	peer.sin_family = AF_INET;
	peer.sin_port = htons(7500);
	peer.sin_addr.s_addr=inet_addr("127.0.0.1");

	s = socket(AF_INET, SOCK_STREAM,0);
	rc = connect(s, (struct sockaddr *) &peer, sizeof(peer));

	while(true) {

		puts("Choise:");
		// menu;
		scanf("%s",buf);
		buf[1] = '\0';
		send(s, buf, sizeof(buf),0);
		p = buf[0];
		switch(p)
		{
			case '1':
			// add	

			// add Name
			printf("%s", "Name new Student: "); 
			fflush(stdin); fflush(stdout);
			scanf("%s", b); strcat(buf, b); strcat(buf," ");
			scanf("%s", b); strcat(buf, b); strcat(buf," ");
			scanf("%s", b); strcat(buf, b); strcat(buf,"\0");
			send(s, buf, sizeof(buf),0);

			//add Group
			printf("%s", "Group new Student: "); 
			fflush(stdin); fflush(stdout);
			scanf("%s", buf);
			send(s, buf, sizeof(buf),0);

			//add Birthday
			printf("%s", "Birthday new Student: "); 
			fflush(stdin); fflush(stdout);
			scanf("%s", buf);
			send(s, buf, sizeof(buf),0);

			// add tel
			printf("%s", "tel new Student: "); 
			fflush(stdin); fflush(stdout);
			scanf("%s", buf);
			send(s, buf, sizeof(buf),0);

			//add first year
			printf("%s", "first Year new Student: "); 
			fflush(stdin); fflush(stdout);
			scanf("%s", buf);
			send(s, buf, sizeof(buf),0);
			recv(s, buf, sizeof(buf),0);
			printf("%s\n", buf);
            break;
			case '2':
			// del	
			recv(s, buf, sizeof(buf),0);
			CountStudent = atoi(buf);
			for (i = 0; i < CountStudent; i++)
			{
				printf("%d: ",i+1);
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);	
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);
			}
			printf("%s", "Number note for delete: "); scanf("%s",buf);
			send(s, buf, sizeof(buf),0);
			recv(s, buf, sizeof(buf),0);
			printf("%s\n", buf);
			break;
			case '3':
			// edit
			recv(s, buf, sizeof(buf),0);
			CountStudent = atoi(buf);
			for (i = 0; i < CountStudent; i++)
			{
				printf("%d: ",i+1);
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);	
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("\t%s\n", buf);
			}
			printf("%s", "Number note for edit: "); scanf("%s",buf);
			send(s, buf, sizeof(buf),0);
			recv(s, buf, sizeof(buf),0);
			if(atoi(buf) != 0)
			{
				printf("%s", "Error!");
			}
			else
			{
				puts("What field (1-5) to edit");
				puts("\t1 - Name");
				puts("\t2 - Number group");
				puts("\t3 - Birthday");
				puts("\t4 - Phone");
				puts("\t5 - First year");
				scanf("%s",buf);
				send(s, buf, sizeof(buf),0);
				recv(s, buf, sizeof(buf),0);
				if(atoi(buf) != 0)
				{
					printf("%s", "Error!");
				}
				else
				{
					printf("%s", "write new note: "); scanf("%s",buf);
					send(s, buf, sizeof(buf),0);
					recv(s, buf, sizeof(buf),0);
					printf("%s\n", buf);
				}
				
			}
			break;
			case '4':
			//view all	
			recv(s, buf, sizeof(buf),0);
			CountStudent = atoi(buf);
			for (i = 0; i < CountStudent; i++)
			{
				recv(s, buf, sizeof(buf),0);
				printf("%s\n", buf);	
				recv(s, buf, sizeof(buf),0);
				printf("%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("%s\n", buf);
				recv(s, buf, sizeof(buf),0);
				printf("%s\n", buf);
			}
			break;
			case '5':
			// view filter
			break;
			case '6':
			// view sort
			break;
			case '7':
			// exit
			 exit(0);
		}
		
	}
	return 0;
}

/*
switch(p) {
			case '1':
			puts("kolvo mounths 1-12 :"); scanf("%s", buf);
			send(s, buf, sizeof(buf),0);
			puts("Symbol :"); scanf("%s", buf);
			send(s, buf, sizeof(buf),0);

			printf("sum taxes :");
			recv(s, buf, sizeof(buf),0);
			for(t = 0; buf[t+3];t++) printf("%c", buf[t]);
			printf(".");
			for(t1 = t; buf[t1];t1++) printf("%c",buf[t1]);
			printf("\n");
			break;
			case '2':
			puts("numder for edit (1 - 5)"); scanf("%s", buf);
			send(s, buf, sizeof(buf), 0);
			puts("What field (1-4) to edit");
			puts("\t1 - Name");
			puts("\t2 - Number");
			puts("\t3 - Income");
			puts("\t4 - Tax");
			scanf("%s", buf);
			send(s, buf, sizeof(buf), 0);
            p1 = buf[0];
            buf[0] = '\0';
            switch(p1) {
                case '1':
                    printf("Name: ");
                    fflush(stdin); fflush(stdout);
                    scanf("%s", b); strcat(buf, b); strcat(buf, " ");
                    scanf("%s", b); strcat(buf, b); strcat(buf, " ");
                    scanf("%s", b); strcat(buf, b); strcat(buf, "\0");
                    send(s, buf, sizeof(buf), 0);
                    break;
                case '2':
                    printf("Number: ");
                    fflush(stdin); fflush(stdout);
                    scanf("%s", buf);
                    send(s, buf, sizeof(buf), 0);
                    break;
                case '3':
                    printf("Income per months: ");
                    fflush(stdin); fflush(stdout);
                    scanf("%s", buf);
                    send(s, buf, sizeof(buf), 0);
                    break;
                case '4':
                    printf("Tax rate per month: ");
                    fflush(stdin); fflush(stdout);
                    scanf("%s", buf);
                    send(s, buf, sizeof(buf), 0);
                    break;
            }
			 break;
			case '3':
				recv(s, buf, sizeof(buf),0); printf("%s", buf);
				recv(s, buf, sizeof(buf),0); printf("%s", buf);
				recv(s, buf, sizeof(buf),0); printf("%s", buf);
				recv(s, buf, sizeof(buf),0); printf("%s", buf);
				recv(s, buf, sizeof(buf),0); printf("%s\n", buf);
				break;
			case '4':
				exit(0);
		}
*/