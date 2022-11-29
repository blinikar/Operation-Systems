#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int is_pressed_only(int* array, int n, int* pressed_codes) {
	for (int j = 0; j < n; j++) {
		if (pressed_codes[array[j]] != 1) {
			return 0;
		}
	}
	for (int i = 0; i < 999; i++) {
		if (pressed_codes[i] == 1) {
			int found = 1;
			for (int j = 0; j < n; j++) {
				if (i != array[j]) found = 1;
				else {
					found = 0;
					break;
				}
			}
			if (found == 1) {
				return 0;
			}
		}
	}
	return 1;
}

int main (void) {
	int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);

	if (fd == -1) return EXIT_FAILURE;

	struct input_event event;
	ssize_t n;

	int pressed_codes[999];
	for (int i = 0; i < 999; i++) {
		pressed_codes[i] = 0;
	}

	FILE *fp = fopen("ex3.txt", "w");

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
			if (event.value == 0) pressed_codes[(int)event.code] = 0;
			else pressed_codes[(int)event.code] = 1;
		}
		
		int shortcut1[3] = {KEY_C, KEY_A, KEY_E};
		int shortcut2[2] = {KEY_P, KEY_E};
		int shortcut3[2] = {KEY_H, KEY_W};

		for (int i = 0; i < 999; i++) {
			if (is_pressed_only(shortcut1, 3, pressed_codes)) fprintf(fp, "Get some cappucchino\n");
			if (is_pressed_only(shortcut2, 2, pressed_codes)) fprintf(fp, "I passed the exam!\n");
			if (is_pressed_only(shortcut3, 2, pressed_codes)) fprintf(fp, "Hello world!\n");
		}
	}
	
	fclose(fp);
	printf("%s\n", strerror(errno));
	return EXIT_SUCCESS;
}
