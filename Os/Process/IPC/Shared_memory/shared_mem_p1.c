#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#define SHM_NAME "/shared_mem.txt"
#define SHM_SIZE 1024

int main(){
    int shm_fd = shm_open(SHM_NAME,O_CREAT | O_RDWR ,0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

   if(ftruncate(shm_fd, SHM_SIZE) == -1){
        perror("ftruncate");
        printf("-1??\n");
        close(shm_fd);
        shm_unlink(SHM_NAME);
        exit(EXIT_FAILURE);
    }

    void *shm_ptr = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(!shm_ptr){
        perror("mmap failed");
        close(shm_fd);
        exit(EXIT_FAILURE);
    }

     char *message = "Hello from Process 1!";
    memcpy(shm_ptr, message, strlen(message) + 1);

        printf("Process 1 wrote: %s\n", (char *)shm_ptr);

    // Clean up
    munmap(shm_ptr, SHM_SIZE);
    close(shm_fd);
    return 0;
}
