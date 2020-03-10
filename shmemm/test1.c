#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int *array; /* Указатель на разделяемую память */
    int shmid;  /* IPC дескриптор для области разделяемой памяти */
    char pathname[] = argv[0];
    key_t key;

    //generate PIC key
    if ((key = ftok(pathname, 0)))
    {
        printf("Cant\'t generate IPC key");
        exit(-1);
    }
    else
    {
        printf("IPC key is %d\n", key);
    }

    // Making shared memory
    shmid = shmget(key, 250 * sizeof(int), 0666 | IPC_CREAT | IPC_EXCL);

    return 0;
}