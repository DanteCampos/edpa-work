#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "bst.c"
#include "avl.c"
#include "treap.c"

void shuffle(long* array, long n_elements, long seed) {
    srand(seed);
    if (n_elements > 1) {
        for (long i = 0; i < n_elements - 1; i++) {
            long j = i + rand() / (RAND_MAX / (n_elements - i) + 1);
            long t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

long* generateRandomArray(long n_elements, long seed){
    long* array = (long*) malloc(n_elements * sizeof(long));
    srand(seed);
    for (long i = 0; i < n_elements; i++){
        array[i] = rand() % LONG_MAX; // random values
    }
    shuffle(array, n_elements, seed); // shuffle the array
    return array;
}

long* generateRandomOrder(long n_elements, long seed){
    long* order = (long*) malloc(n_elements * sizeof(long));
    srand(seed);
    for (long i = 0; i < n_elements; i++){
        order[i] = i; // indices from 0 to n_elements - 1
    }
    shuffle(order, n_elements, seed); // shuffle the array
    return order;
}

int main(){
    int n_steps = 1e1; // 1e3 when doing the real experiment
    int operations_per_step = 1e6; // Must be high to obtain accurated time measurements
    int n_nodes = n_steps*operations_per_step; // Each operation happens to one single node
    int seed = 0;

    long *keys, *prior, *order;
    struct timespec start, end;
    FILE *fp; // To save results

    // Time (ms) for each operation
    double *timeTreapInsert,*timeTreapSearch, *timeTreapRemove, *timeTreapSearchAfterInsertion, *timeTreapSearchAfterRemoval,
           *timeBstInsert, *timeBstSearch, *timeBstRemove, *timeBstSearchAfterInsertion, *timeBstSearchAfterRemoval,
           *timeAvlInsert, *timeAvlSearch, *timeAvlRemove, *timeAvlSearchAfterInsertion, *timeAvlSearchAfterRemoval;

    // ----------------------------- EXPERIMENT -----------------------------

    // Generate random keys and priorities
    keys  = generateRandomArray(n_nodes, seed++);
    prior = generateRandomArray(n_nodes, seed++);

    // Allocate the time arrays
    timeTreapInsert = (double*) malloc(n_steps * sizeof(double));
    timeTreapSearch = (double*) malloc(n_steps * sizeof(double));
    timeTreapRemove = (double*) malloc(n_steps * sizeof(double));
    timeTreapSearchAfterInsertion = (double*) malloc(n_steps * sizeof(double));
    timeTreapSearchAfterRemoval = (double*) malloc(n_steps * sizeof(double));
    timeBstInsert = (double*) malloc(n_steps * sizeof(double));
    timeBstSearch = (double*) malloc(n_steps * sizeof(double));
    timeBstRemove = (double*) malloc(n_steps * sizeof(double));
    timeBstSearchAfterInsertion = (double*) malloc(n_steps * sizeof(double));
    timeBstSearchAfterRemoval = (double*) malloc(n_steps * sizeof(double));
    timeAvlInsert = (double*) malloc(n_steps * sizeof(double));
    timeAvlSearch = (double*) malloc(n_steps * sizeof(double));
    timeAvlRemove = (double*) malloc(n_steps * sizeof(double));
    timeAvlSearchAfterInsertion = (double*) malloc(n_steps * sizeof(double));
    timeAvlSearchAfterRemoval = (double*) malloc(n_steps * sizeof(double));
    
    // Initialize the treap
    pTNODE root = NULL;
    pBNODE bstRoot = NULL;
    pANODE avlRoot = NULL;

    // Insert and search
    order = generateRandomOrder(n_nodes, seed++);
    for (int j = 0; j < n_steps; j++){
        printf("Insertion step %d of %d\n", j+1, n_steps);

        // Treap insertion
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = j*operations_per_step; i < (j+1)*operations_per_step; i++)
            treapInsert(keys[i], prior[i], &root);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeTreapInsert[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // Treap search after insertion
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = j*operations_per_step; i < (j+1)*operations_per_step; i++)
            treapSearch(keys[i], root);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeTreapSearchAfterInsertion[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // BST insertion
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = j*operations_per_step; i < (j+1)*operations_per_step; i++)
            bstInsert(keys[i], &bstRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeBstInsert[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // BST search after insertion
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = j*operations_per_step; i < (j+1)*operations_per_step; i++)
            bstSearch(keys[i], bstRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeBstSearchAfterInsertion[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // AVL insertion
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = j*operations_per_step; i < (j+1)*operations_per_step; i++)
            avlInsert(keys[i], &avlRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeAvlInsert[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // AVL search after insertion
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = j*operations_per_step; i < (j+1)*operations_per_step; i++)
            avlSearch(keys[i], avlRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeAvlSearchAfterInsertion[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;
    }
    free(order);

    // Batch search
    order = generateRandomOrder(n_nodes, seed++);
    for (int j = 0; j < n_steps; j++){
        printf("Search step %d of %d\n", j+1, n_steps);

        // Treap search
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            treapSearch(keys[i], root);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeTreapSearch[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // BST search
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            bstSearch(keys[i], bstRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeBstSearch[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // AVL search
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            avlSearch(keys[i], avlRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeAvlSearch[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;
    }
    free(order);

    // Remove and search
    order = generateRandomOrder(n_nodes, seed++);
    for (int j = 0; j < n_steps; j++){
        printf("Removal step %d of %d\n", j+1, n_steps);

        // Treap removal
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            treapRemove(keys[i], &root);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeTreapRemove[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // Treap search after removal
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            treapSearch(keys[i], root);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeTreapSearchAfterRemoval[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // BST removal
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            bstRemove(keys[i], &bstRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeBstRemove[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // BST search after removal
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            bstSearch(keys[i], bstRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeBstSearchAfterRemoval[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // AVL removal
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            avlRemove(keys[i], &avlRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeAvlRemove[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;

        // AVL search after removal
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int i = 0; i < n_nodes; i++)
            avlSearch(keys[i], avlRoot);
        clock_gettime(CLOCK_MONOTONIC, &end);
        timeAvlSearchAfterRemoval[j] = ((end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec))/1e6;
    }
    free(order);
    
    // Save results
    fp = fopen("results.csv", "w");
    fprintf(fp,
        "treap_insert,treap_search_after_insertion,treap_remove,treap_search_after_removal,treap_search"
        "bst_insert,bst_search_after_insertion,bst_remove,bst_search_after_removal,bst_search"
        "avl_insert,avl_search_after_insertion,avl_remove,avl_search_after_removal,avl_search"
        "\n"
    );
    for (int i = 0; i < n_steps; i++){
        fprintf(fp, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
            timeTreapInsert[i], timeTreapSearchAfterInsertion[i], timeTreapRemove[i], timeTreapSearchAfterRemoval[i], timeTreapSearch[i],
            timeBstInsert[i], timeBstSearchAfterInsertion[i], timeBstRemove[i], timeBstSearchAfterRemoval[i], timeBstSearch[i],
            timeAvlInsert[i], timeAvlSearchAfterInsertion[i], timeAvlRemove[i], timeAvlSearchAfterRemoval[i], timeAvlSearch[i]
        );
    }
    fclose(fp);

    // Free time arrays
    free(timeTreapInsert);
    free(timeTreapRemove);
    free(timeTreapSearch);
    free(timeTreapSearchAfterInsertion);
    free(timeTreapSearchAfterRemoval);
    free(timeBstInsert);
    free(timeBstRemove);
    free(timeBstSearch);
    free(timeBstSearchAfterInsertion);
    free(timeBstSearchAfterRemoval);
    free(timeAvlInsert);
    free(timeAvlRemove);
    free(timeAvlSearch);
    free(timeAvlSearchAfterInsertion);
    free(timeAvlSearchAfterRemoval);

    // Free keys and priorities
    free (keys);
    free (prior);
    return 0;
}