#include <stdio.h>
#include <stdlib.h>

struct objects{
    int* table;
    int table_size;
} objects;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void write_numbers_to_Table(){
    int tableLength = 0;
    printf("Create default table length: ");
    scanf("%d", &tableLength);

    if(tableLength <= 0){
        return;
    }

    objects.table_size = tableLength;
    objects.table = malloc(objects.table_size * sizeof(int));
}

void apply_letters_to_Table(){
    printf("Table length: %d \n \n", objects.table_size);
    for(int i=0; i < objects.table_size; i++){
        printf("write number: ");
        scanf("%d", &objects.table[i]);
    }
}

void allow_sort_Table(){
    for(int i=0; i < objects.table_size - 1; i++){
        for(int j = 0; j < objects.table_size - i - 1; j++){
            if(objects.table[j] > objects.table[j + 1]){
                swap(&objects.table[j], &objects.table[j + 1]);
            }
        }
    }
}

void sias_Table(){ 
    printf("Sorted Table: ");
    for(int i=0; i < objects.table_size; i++){
        printf("%d, ", objects.table[i]);
    }
    free(objects.table);
}

int main(){
    write_numbers_to_Table();
    apply_letters_to_Table();
    allow_sort_Table();
    sias_Table();
    return 0;
}