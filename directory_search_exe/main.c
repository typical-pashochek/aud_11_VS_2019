#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main(int argc, char* argv[])
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf = FindFirstFileA("*.exe", &FindFileData);
	if (hf != INVALID_HANDLE_VALUE)
	{
		printf("%s   ", FindFileData.cFileName);
		printf("File size: %d\n", FindFileData.nFileSizeLow);
		while (FindNextFile(hf, &FindFileData) != 0) {
			printf("%ls   ", FindFileData.cFileName);
			printf("File size: %d\n", FindFileData.nFileSizeLow);
		};
		FindClose(hf);
	}
	else {
		printf("There are no executable files...\n");
	}
	_getch();
	return 0;
}