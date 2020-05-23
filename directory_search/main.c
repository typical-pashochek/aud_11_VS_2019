#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main(int argc, char* argv[])
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf = FindFirstFileA("*.txt", &FindFileData);
	if (hf != INVALID_HANDLE_VALUE)
	{
		if (FindFileData.nFileSizeLow > 20) {
			printf("%s   ", FindFileData.cFileName);
			printf("File size: %d\n", FindFileData.nFileSizeLow);
		}
		while (FindNextFile(hf, &FindFileData) != 0) {
			if (FindFileData.nFileSizeLow > 20) {
				printf("%ls   ", FindFileData.cFileName);
				printf("File size: %d\n", FindFileData.nFileSizeLow);
			}
		} ;
		FindClose(hf);
	}
	else {
		printf("There are no *.txt files...\n");
	}
	_getch();
	return 0;
}