#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[]) {
	unsigned int i;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (-1);
	}

	for (i = 1; i < argc; i++) {
		_which(argv[i]);
	}

	return (0);
}

