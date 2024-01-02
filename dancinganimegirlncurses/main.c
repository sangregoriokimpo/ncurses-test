#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

void displayFrame(const char* frameFile) {
    FILE* frame = fopen(frameFile, "r");
    if (frame == NULL) {
        printf("Failed to open frame file: %s\n", frameFile);
        exit(1);
    }

    clear();
    char line[1024];
    int y = 0;

    while (fgets(line, sizeof(line), frame) != NULL) {
        mvprintw(y++, 0, "%s", line);
    }

    refresh();
    fclose(frame);
}

int main() {
    
    const char* frameFiles[] = {
        "message.txt",
        "message-2.txt",
        "message-3.txt",
        "message-4.txt",
        "message-5.txt",
        "message-6.txt",
        "message-7.txt",
        "message-8.txt",
        "message-9.txt",
        "message-10.txt",
        "message-11.txt",
        "message-12.txt",
        "message-13.txt",
        "message-14.txt",
        "message-15.txt",
        "message-16.txt",
        "message-17.txt",
        "message-18.txt",
        "message-19.txt",
        "message-20.txt",
        "message-21.txt",
        "message-22.txt",
        "message-23.txt",
        "message-24.txt",
        "message-25.txt",
        "message-26.txt",
        "message-27.txt"
        // Add more frame file names here
    };

    const int numFrames = sizeof(frameFiles) / sizeof(frameFiles[0]);

    initscr(); // Initialize ncurses
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_MAGENTA);
    bkgd(COLOR_PAIR(1));
    noecho();  // Don't echo user input
    curs_set(0); // Hide the cursor

    while (1) {
        for (int i = 0; i < numFrames; i++) {
            displayFrame(frameFiles[i]);
            usleep(30000); // Sleep for a short time (in microseconds) between frames
        }
    }

    endwin(); // Cleanup and exit ncurses

    return 0;
}
