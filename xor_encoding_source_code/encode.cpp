#include<stdio.h>
#include<string>
extern FILE* fin, * fout;
extern int size;
extern char buf[1024];
void encode(char* filename,char* passwd) {
	fopen_s(&fin, filename, "rb");
	if (fin == NULL) {
		printf("打开文件失败\n");
		return;
	}
	strcat(filename, "batd");
	fopen_s(&fout, filename, "wb");
	if (fout == NULL) {
		printf("写入文件失败\n");
		return;
	}
	size = 0;
	memset(buf,0,sizeof(buf));
	while ((size = fread(buf, sizeof(buf[0]), 1024, fin)) != 0) {
		for (int i = 0; i < size; i++) buf[i] ^= passwd[i % strlen(passwd)];
		fwrite(buf, sizeof buf[0], size, fout);
	}
	fclose(fin);
	fclose(fout);
}