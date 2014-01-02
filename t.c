#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char** argv)
{
	int fd; //file discript

	char * filename;
	filename = *(++argv);	
	off_t off_t_file;
	
	if((fd = open(filename, O_RDONLY)) == -1)
		error(fd);

	off_t_file = lseek(fd,0,SEEK_END);

	printf("off_set of the file '%s' is %d\n", filename, off_t_file);

	/*read the file filename to the vary string_consist_file*/
	int length_of_file;
	length_of_file = (int)off_t_file;
	char * string_consist_file;
	string_consist_file = malloc(sizeof(char) * length_of_file);
	if(string_consist_file == NULL)
		error("MALLOC ERROR");
	lseek(fd, 0, SEEK_SET);
	int n;
	if((n = read(fd, string_consist_file, length_of_file)) == -1)
		error("READ FILE ERROR,source file 29 row");
	printf("n is :%d\n", n);
	printf("**********start of %s*************\n", filename);
	printf("%s\n",string_consist_file);
    printf("************end of %s*************\n", filename);

	return 0;
}

