#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096 // Size of each page in bytes
#define PAGE_TABLE_SIZE 1024 // Number of entries in the page table

// Function to convert a virtual address to page number and offset
void convertAddress(int virtual_address, int *page_number, int *offset) {
    *page_number = virtual_address / PAGE_SIZE;
    *offset = virtual_address % PAGE_SIZE;
}

// Function to load data from memory using paging
void loadData(int *page_table, int virtual_address) {
    int page_number, offset;
    convertAddress(virtual_address, &page_number, &offset);

    // Check if the page is in the page table   
    if (page_table[page_number] == -1) {
        printf("Page Fault! Page %d not in memory.\n", page_number);
    } else {
        int physical_address = page_table[page_number] * PAGE_SIZE + offset;
        printf("Data at virtual address %d is loaded from physical address %d.\n", virtual_address, physical_address);
    }
}

int main() {
    int page_table[PAGE_TABLE_SIZE];
    
    // Initialize the page table with -1 to indicate that no pages are in memory
    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        page_table[i] = -1;
    }

    // Input the page table entries from the user
    printf("Enter the page table entries (page number -> frame number):\n");
    for (int i = 0; i < PAGE_TABLE_SIZE; i++) {
        printf("Page %d -> ", i);
        scanf("%d", &page_table[i]);
    }

    // Input the virtual address from the user
    int virtual_address;
    printf("Enter a virtual address: ");
    scanf("%d", &virtual_address);

    // Check if the virtual address is out of bounds
    if (virtual_address < 0 || virtual_address >= PAGE_SIZE * PAGE_TABLE_SIZE) {
        printf("Error! Virtual address out of bounds.\n");
        return 1; // Exit with an error code
    }

    // Load data using the load function
    loadData(page_table, virtual_address);

    return 0;
}
