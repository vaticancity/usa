printf("Contents of output.txt:\n");
    char output_line[256];
    while (fgets(output_line, sizeof(output_line), file_output_file)) {
        output_line[strcspn(output_line, "\n")] = '\0'; // Remove the newline character
        printf("%s\n", output_line);
    }
    
    fclose(file_output_file);
    return 0;