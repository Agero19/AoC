#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

bool is_safe_report(const char *line) {
    int prev = -1, current;
    int difference;
    bool increasing = false, decreasing = false;

    // Tokenize the line
    char *token = strtok((char *)line, " ");
    if (!token) return false; 

    
    prev = atoi(token);
    token = strtok(NULL, " ");

    while (token) {
        current = atoi(token);
        difference = abs(current - prev);

        
        if (difference < 1 || difference > 3) {
            return false; 
        }

        // Determine direction of the sequence
        if (current > prev) {

            if (decreasing) return false; 
            increasing = true;
        } else if (current < prev) {
            
            if (increasing) return false;
            decreasing = true;
        } else {
            return false; 
        }

        prev = current;
        token = strtok(NULL, " ");
    }

    return true; 
}

void evaluate_reports(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int safe_count = 0;

    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Check if the line is safe
        if (is_safe_report(line)) {
            safe_count++;
        }
    }

    fclose(file);

    printf("Total safe reports: %d\n", safe_count);
}

int main() {
    const char *filename = "data/report.txt";
    evaluate_reports(filename);
    return 0;
}
