#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main (void) {
	int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);

	if (fd == -1) return EXIT_FAILURE;

	struct input_event event;
	ssize_t n;

	FILE *fp = fopen("ex2.txt", "w");

	while(1) {
		n = read(fd, &event, sizeof(event));

		if (n == (ssize_t)-1) {
			if (errno == EINTR) continue;
			else break;
		} else if (n != sizeof(event)) {
			errno = EIO;
			break;
		}

		if (event.type == EV_KEY && event.value >= 0 && event.value <= 1) {
			if (event.value == 0) fprintf(fp, "%s 0x%04x (%d)\n", "RELEASED", (int)event.code, (int)event.code);
			else fprintf(fp, "%s 0x%04x (%d)\n", "PRESSED", (int)event.code, (int)event.code);
		}
	}
	
	fclose(fp);
	printf("%s\n", strerror(errno));
	return EXIT_SUCCESS;
}
