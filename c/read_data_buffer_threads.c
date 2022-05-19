https://stackoverflow.com/questions/10307302/reading-from-text-file-using-buffer-and-multithreading-in-c

pthread_mutex_t mux;
pthread_cond_var_t valid_bytes_updated;

int g_valid_bytes = 0;    // high water mark

char buffer[10 * 1024];

void* io_thread(...)
{
    int offset = 0;

    while (!done) {
        // read the next block of data
        readdata( file_handle, &buffer[offset], 2 * 1024);

        // let consumer threads know there's more data
        offset += 2 * 1024;
        pthread_mutex_lock( &mux);
        g_valid_bytes = offset;
        pthread_mutex_unlock( &mux);

        pthread_cond_broadcast( &updated);
}


void* consumer_thread(...)
{
    int processed_bytes = 0;

    while (!done) {
        // wait until there's something to do
        pthread_mutex_lock( &mux);
        while (processed_bytes == g_valid_bytes) {
            pthread_cond_wait( &valid_bytes_updated, &mux);
        }
        int valid_bytes = g_valid_bytes;
        pthread_mutex_unlock( &mux);

        // process the data in range &buffer[processed_bytes] to &buffer[valid_bytes], 
        //  keeping in mind that the range is up to but not including the byte at
        //  &buffer[valid_bytes]

        processed_bytes = valid_bytes;
    }
}
