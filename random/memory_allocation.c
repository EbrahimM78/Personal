// Define a memory block struct
typedef struct {
  int size;
  int used;
  void *data;
} memory_block;

// Define a memory manager struct
typedef struct {
  int block_count;
  memory_block *blocks;
} memory_manager;

// Initialize a new memory manager
memory_manager *create_memory_manager() {
  memory_manager *manager = malloc(sizeof(memory_manager));
  manager->block_count = 0;
  manager->blocks = NULL;
  return manager;
}

// Allocate memory from the memory manager
void *allocate_memory(memory_manager *manager, int size) {
  void *data = malloc(size);
  if (data) {
    manager->block_count++;
    manager->blocks = realloc(manager->blocks, manager->block_count * sizeof(memory_block));
    manager->blocks[manager->block_count - 1].size = size;
    manager->blocks[manager->block_count - 1].used = 1;
    manager->blocks[manager->block_count - 1].data = data;
  }
  return data;
}

// Deallocate memory from the memory manager
void deallocate_memory(memory_manager *manager, void *data) {
  for (int i = 0; i < manager->block_count; i++) {
    if (manager->blocks[i].data == data) {
      free(data);
      manager->blocks[i].used = 0;
      break;
    }
  }
}
