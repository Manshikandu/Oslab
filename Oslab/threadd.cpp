#include <stdio.h>
#include <pthread.h>


struct ThreadArgs {
    int *arr;
    int size;
};


void *calculate_sum(void *arg) {
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    int *arr = args->arr;
    int size = args->size;

    int total_sum = 0;
    for (int i = 0; i < size; i++) {
        total_sum += arr[i];
    }

    printf("Sum of array elements: %d\n", total_sum);

    pthread_exit(NULL);
}


void *calculate_product(void *arg) {
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    int *arr = args->arr;
    int size = args->size;

    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }

    printf("Product of array elements: %d\n", product);

    pthread_exit(NULL);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    
    struct ThreadArgs args = {arr, size};

    
    pthread_t sum_thread, product_thread;
    pthread_create(&sum_thread, NULL, calculate_sum, (void *)&args);
    pthread_create(&product_thread, NULL, calculate_product, (void *)&args);

   
    pthread_join(sum_thread, NULL);
    pthread_join(product_thread, NULL);

    return 0;
}

