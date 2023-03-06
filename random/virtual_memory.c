// Define a page size and maximum number of pages
#define PAGE_SIZE 4096
#define MAX_PAGES 1024

// Define a page table entry struct
typedef struct {
  int present;
  int frame;
  int dirty;
  int accessed;
  int permissions;
} page_table_entry;

// Define a page table
page_table_entry page_table[MAX_PAGES];

// Allocate a new page to a process
int allocate_page(int process_id) {
  int page_number = -1;
  for (int i = 0; i < MAX_PAGES; i++) {
    if (!page_table[i].present) {
      page_table[i].present = 1;
      page_table[i].frame = allocate_frame();
      page_table[i].dirty = 0;
      page_table[i].accessed = 0;
      page_table[i].permissions = get_process_permissions(process_id);
      page_number = i;
      break;
    }
  }
  return page_number;
}

// Handle a page fault
void handle_page_fault(int process_id, int page_number) {
  if (!page_table[page_number].present) {
    page_table[page_number].present = 1;
    page_table[page_number].frame = allocate_frame();
    page_table[page_number].dirty = 0;
    page_table[page_number].accessed = 0;
    page_table[page_number].permissions = get_process_permissions(process_id);
    load_page_from_disk(process_id, page_number);
  }
}
