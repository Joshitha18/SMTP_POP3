#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <time.h>

//#define MYPORT 3456
#define BACKLOG 10
#define MAXDATASIZE 10000
/* the port users will be connecting to */
/* number of pending connections */
main(int argc,char*argv[])
{
int MYPORT;
MYPORT=atoi(argv[1]);
//printf("%d\n",MYPORT);
int sockfd, new_fd,numbytes;
char buf[MAXDATASIZE];
char buff[MAXDATASIZE];
char buffe[MAXDATASIZE];
char buffer[MAXDATASIZE];
/* listen on sock_fd,
new connection on new_fd */
struct sockaddr_in my_addr;
/* my address information */
struct sockaddr_in their_addr; /* client's address info */
int sin_size;
if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
{
perror("socket");
exit(1);
}
my_addr.sin_family = AF_INET;
my_addr.sin_port = htons(MYPORT);
my_addr.sin_addr.s_addr = INADDR_ANY; /* auto-fill with my IP */
bzero(&(my_addr.sin_zero), 8);
/* zero the rest */
if (bind(sockfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
{
perror("bind");
exit(1);
}
if (listen(sockfd, BACKLOG) == -1)
{
perror("listen");
exit(1);
}

/* main accept() loop */

sin_size = sizeof(struct sockaddr_in);
if ((new_fd = accept(sockfd,(struct sockaddr *)&their_addr,&sin_size)) ==
-1)
{
perror("accept");
}
printf("server: got connection from %d\n",
inet_ntoa(their_addr.sin_addr));

int n,v,m=1,no=0,g=0,s=0;
/*
	 if ((numbytes=recv(new_fd, buf, MAXDATASIZE, 0)) == -1)
		{
		perror("recv");
		exit(1);
		} 
n=numbytes;
	 buf[n] = '\0';
//printf("%s",buf);
//%s>... Sender ok
printf("250 OK Hello ");
for(v=0;v<n;v++){
	
	if(buf[v] != '^'&& no==0){printf("%c", buf[v]);}	
	else if(buf[v]=='^' && m==1){m++;no=1;}
	else if(buf[v] != '^' && m==2 && buf[v] != '\n'){buff[g]=buf[v];g++;}
	else if(buf[v]=='^' && m==2){m++;}
	else if(buf[v] != '^' && m==3 && buf[v] != '\n'){buffe[h]=buf[v];h++;}
	else if(buf[v]=='^' && m==3){m++;}
	else if(buf[v] != '^' && m==4 ){buffer[s]=buf[v];s++;}
		}


printf("\n250 <");
printf("%s",buff);
printf(">...Sender ok\n250 root...Recipient ok\n250 OK Message accepted for delivery\n");


printf("%s",buffer);

*/
char h[100],dm[100],hh[1000]="250 OK Hello ",aa[100],from[100],ff[100]="250 ",fr[100]="... Sender ok",rc[100],to[100],rr[100]="250 root... Recipient ok",sub[2000],email[2000],qu[5],ptr[100];
printf("\n");
read(new_fd,h,sizeof(h));
read(new_fd,dm,sizeof(dm));
read(new_fd,ptr,sizeof(ptr));
printf("%s",h);
strcat(hh,ptr);
write(new_fd,hh,sizeof(hh));
//read(new_fd,time,sizeof(time));
read(new_fd,aa,sizeof(aa));
read(new_fd,from,sizeof(from));
printf("%s",aa);
strcat(ff,from);
strcat(ff,fr);
write(new_fd,ff,sizeof(ff));
read(new_fd,rc,sizeof(rc));
read(new_fd,to,sizeof(to));
printf("%s",rc);
write(new_fd,rr,sizeof(rr));
read(new_fd,sub,sizeof(sub));
printf("data %s",sub);
//read(new_fd,email,sizeof(email));
//printf("email %s",email);
write(new_fd,"OK Message accepted for delivery",100);
read(new_fd,qu,sizeof(qu));
printf("%s\n",qu);
    time_t mytime = time(NULL);
    char * time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

char *u;
strtok_r(to, "@",&u);
strcat(to,"/MyMailBox.txt");
    // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen(to, "a");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    fprintf(fptr, "From: %s", from);
    //fprintf(fptr, "\n");
    fprintf(fptr, "Time: %s", time_str);
    fprintf(fptr, "\n");
    fprintf(fptr, "SUBJECT: %s", sub);
    fprintf(fptr, ".");
    fprintf(fptr, "\n\n");

    fclose(fptr);


while(waitpid(-1,NULL,WNOHANG) > 0); /* clean up child processes */

close(new_fd);
}

/*
sysad@sysad-XPS-13-9380:~/Downloads/180020009$ ./a.out
server: got connection from -1766271856
Received: Hello. how are you doing.
sysad@sysad-XPS-13-9380:~/Downloads/180020009$ 
*/
