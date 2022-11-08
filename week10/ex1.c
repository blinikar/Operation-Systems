#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int page;
    uint8_t counter;
} page;

int getIndexInMemory(page *array, int n, int page) {
    int result = -1;
    for (int i = 0; i < n; i++) {
        if (page == array[i].page) {
            result = i;
        }
    }
    return result;
}

int load_page(page *pages, int n, int page) {
    int oldest_index = 0;
    uint8_t oldest_counter = 0b10000000;
    
    for (int i = 0; i < n; i++) {
        if (pages[i].page == 0) {
            pages[i].page = page;
            pages[i].counter |= 0b10000000;
            return i;
        } 

        if (oldest_counter >= pages[i].counter) {
            oldest_index = i;
        }
    }

    pages[oldest_index].page = page;
    pages[oldest_index].counter |= 0b10000000;
    return oldest_index;
}

int main (int argc, char *argv[]) {
    if (argc != 2) return EXIT_FAILURE;

    int page_frames = atoi(argv[1]);
    // int page_frames = 100;

    page *memory = malloc(page_frames*sizeof(page));

    FILE *fp;
    fp = fopen("input2.txt", "r");

    for (int i = 0; i < page_frames; i++) {
        memory[i].page = 0;
        memory[i].counter |= 0b0;
    }

    int hits = 0;
    int misses = 0;

    int count = 0;

    char buff[255];

    while (!feof(fp)) {
        count++;
        fscanf(fp, "%s", buff);
        int page = atoi(buff);
        
        int index = getIndexInMemory(memory, page_frames, page);
        if (index == -1) {
            misses++;
            index = load_page(memory, page_frames, page);
        } else {
            hits++;
            memory[index].counter |= 0b10000000;
        }

        for (int i = 0; i < page_frames; i++) {
            if (i == index) continue;
            memory[i].counter >> 1;
        }
    }

    printf("Hits: %d, Misses: %d, Ratio: %f\n", hits, misses, (float)hits/misses);
    
    return EXIT_SUCCESS;
}