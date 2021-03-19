
/****************************************/
/* Title of Project2: scheduler         */
/* Subject:           Computer Systems  */
/* Student Name:      Peter Goulas      */
/* Student ID:                          */
/* Last Edit:         11-6-2020         */
/* LOC:               2361              */
/*        Programming is Fun  =)        */
/****************************************/

// include the libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// constants
#define LINE_MAX 1000
#define ELEMENTS 120000
#define QUANTUM    10
#define SIXTY      60
#define PAGES       4
#define TWO         2
#define HUNDRED   100
#define FOUR_PAGES  4

// void clearArray(char A[]){
//     memset(A,0, strlen(A));
// }

// sort the array -  insertion sort https://www.geeksforgeeks.org/insertion-sort/
void sort_the_array_before_minus1(int arr[], int n){


    int i = 0, key = 0, j = 0; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 

        /* Move elements of arr[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

// checks if an array has an element - works
int check_if_array_has_a_number(int array111[], int n, int num){
    int i = 0, result11 = 0;

    for (i = 0;i<n; i++){
        if (array111[i] == num){
            result11 = 1;
        }
    }
    return result11;
}

// checks if array is empty
int check_if_array_is_empty(int newArray2[], int n){
    int i = 0, result = 1;

    for (i = 0; i < n; i++){
        if (newArray2[i] != -1){
            //printf(" its not empty because of %d index. element = %d\n", i, newArray2[i]);
            result = 0;
        }
    }
    return result;
}

// function to printf an array of a certain size - works
void print_the_array(int my_new_lovely_array[], int n){
    int i = 0;

    for (i=0; i<n; i++){
        if (i != 0){
            printf(",");
        }
        printf("%d", my_new_lovely_array[i]);
    }
}

// compares strings gives 1 if they are same and 0 if they are not - works
int compare_strings(char string1[], char string2[]) {
    int result = 0;

    if (strcmp(string1, string2) == 0){
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

void print_arrays(int timeArray[],int processArray[],int sizeArray[], int runningTimeArray[], int counter){
    int i = 0;
    printf("\n\ntime process size running_T\n");
    for (i = 0; i < counter; i++){
        printf("%d %d %d %d\n", timeArray[i],processArray[i],sizeArray[i],runningTimeArray[i]);
    }
    printf("\n\n");
}

void sort_the_arrays(int timeArray[], int processArray[], int sizeArray[], int runningTimeArray[], int counter){
    int i = 0, tempNum = 0;
    //  check if sorted or else sort according to lowest id -  works
    for (i=0; i<(counter-1); i++){
        // if we have the same arrival time and processID is not sorted then swap them
        // printf("timeArray[i] = %d, timeArray[i+1] = %d\n", timeArray[i], timeArray[i+1]);
        // printf("processArray[i] = %d, processArray[i+1] = %d\n\n", processArray[i], processArray[i+1]);
        if (timeArray[i] == timeArray[i+1]){
            if (processArray[i] > processArray[i+1]){
                // swap processes
                tempNum = processArray[i+1];
                processArray[i+1] = processArray[i];
                processArray[i] = tempNum;

                // swap size
                tempNum = sizeArray[i+1];
                sizeArray[i+1] = sizeArray[i];
                sizeArray[i] = tempNum;

                // swap running time
                tempNum = runningTimeArray[i+1];
                runningTimeArray[i+1] = runningTimeArray[i];
                runningTimeArray[i] = tempNum;
            }
        }
    }
}

// finds min of array - tested - works
int find_min_num(int A[], int n){
    int i = 0, min_num = 0;

    min_num = A[0];
    for (i=0;i<n;i++){
        if (A[i] < min_num){
            min_num =  A[i];
        }
    }
    return min_num;
}

// finds max of array - tested - works
int find_max_num(int A[], int n){
    int i = 0, max_num = 0;

    for (i=0;i<n;i++){
        if (A[i] > max_num){
            max_num =  A[i];
        }
    }
    return max_num;
}


// check if an int if found in an array -  not tested
int check_if_new_process(int processArray[],int counter, int check,int timeArray[],int sizeArray[], int runningTimeArray[]){
    int i = 0, found = 0;

    // printf("check = %d\n", check);

    for (i = 0; i < counter; i++){
        if (check == processArray[i]){
            found = 1;
            //printf("processArray = %d\n", processArray[i]);
            processArray[i] = -1;
            sizeArray[i] = -1;
            runningTimeArray[i] = -1;
            timeArray[i] = -1;
            //printf("115 i = %d\n", i);
            return found;
        }
    }
    return found;
}

// self exaplantory function for rr algor -  not tested
int check_if_a_process_arrived(int timeArray[],int processArray[],int sizeArray[],int runningTimeArray[],int timeArray2[],int processArray2[],int sizeArray2[],int runningTimeArray2[],int counter, int counter2, int counterCopy2, int time_robin, int *num_of_proc_added, int remainingTimeSaved, int quantum){
    int i = 0, end_of_stack = 0, num_of_proc_added2 = 0;

    end_of_stack = counterCopy2;
    num_of_proc_added2 = *num_of_proc_added;
    num_of_proc_added2 += 1; 

    // time_robin += QUANTUM;
    if (remainingTimeSaved < QUANTUM){
        time_robin += remainingTimeSaved;
    } else {
        time_robin += quantum;
    }
    //printf("134 time robin = %d\n", time_robin);
    for (i=num_of_proc_added2; i<counter; i++){
        // if arrived add at the end of the queue
        if (timeArray[i] != -1){
            if (timeArray[i] <= time_robin){
                // printf("138 time array = %d\n", timeArray[i]);
                timeArray2[counterCopy2 + 1] = timeArray[i];
                processArray2[counterCopy2 + 1] = processArray[i];
                sizeArray2[counterCopy2 + 1] = sizeArray[i];
                runningTimeArray2[counterCopy2 + 1] = runningTimeArray[i];
                counterCopy2+=1;
                end_of_stack += 1;
                //printf("end of the stack = %d\n", end_of_stack);
                //printf("\n*************** added 1 process at the end of the stuck *****************\n\n");
                *num_of_proc_added += 1;
                //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 10);
            }
        }
    }
    return end_of_stack;
}

// gets inside the memory array and saved the process id that is using that page
// counts and gives back the amount of pages stored successfully
int place_pages_in_memory(int memoryArray[],int memory_pages_on_disk,int timeArray[], int processArray[], int sizeArray[], int runningTimeArray[], int counter, int j, int pages_required){
    int i = 0, pages1 = 0, counting_pages = 0, final_result = 0;

    pages1 = sizeArray[i];
    pages1 = pages1/PAGES;
    // place 1 in the indexes which are occupied in memory currently -> 1 for occupied 0 for not occupied
    for(i=0; i < memory_pages_on_disk; i++){
        if ((memoryArray[i] == -1) && (counting_pages <=  pages_required)){

            // memoryArray[i] = 1;
            memoryArray[i] = processArray[j];
            counting_pages += 1;
        }
    }
    final_result = pages_required-counting_pages;
    for(i=0; i<memory_pages_on_disk; i++){
        // printf("186// memory array: %d\n", memoryArray[i]);
    }
    // gives back amount of pages saved successfully
    return final_result;
}

// zeros an array of ints - works
void initialize_the_ints(int array5[], int n){
    int i = 0;

    for (i=0; i<n; i++){
        array5[i] = -1;
    }
}

// https://stackoverflow.com/questions/499939/how-to-extract-the-decimal-part-from-a-floating-point-number-in-c
// tested works
float round_up_float(float num1){
    float num3 = 0.0;

    int int_num1 = (int)num1;
    num3 = ((int_num1)*1.0) + 1.0;
    if ((num3-num1) == 1.0) {
        return num1;
    }
    if ((num3-num1) <= 1.0) {
        return num3;
    }

    return 0.0;
}

void printing_pages(int pages_req){
    int k = 0, count2 = 0;
    for (k=0; k<pages_req; k++){
        if (k==0){
            printf("%d", count2);
        }
        if (k>0){
            printf(",%d", count2);
        }
        if (k == (pages_req-1)){
            printf("]\n");
        }
        count2+=1;
    }
}

// prints the right amount of pages like specified in the ff algorithm
void printing_pages2(int memoryArray[], int pages_required, int j){
    int i = 0, count = 0;

    for (i=0; i<pages_required; i++){
        if (memoryArray[i] == j){
            if (count!= 0){
                printf(",");
            }
            printf("%d", i);
            count+=1;

        }
    }
    printf("]\n");
}

// gives back 1 if we have enough space for this process or 0 if we dont - tested works
int check_for_space(int arr[], int num, int memory_cap){
    int j = 0, counter = 0, result1 = 0;

    for (j = 0; j < memory_cap;j++){
        //printf("arr[%d] = %d\n", j, arr[j]);
        if (arr[j] == -1){
            // printf("arr[%d] = %d\n", j, arr[j]);
            counter+=1;
        }
    }
    // printf("num = %d, counter = %d\n", num, counter);
    // not enough memory in the disk we gotta evict
    if (num > counter){
        //printf("no\n");
        result1 = 0;
    } 
    if (num <= counter){
        //printf("yes\n");
        result1 = 1;
    } 
    return result1;
}

int count_how_many_of_an_element(int A[], int n, int num){
    int i = 0, count_nums = 0;

    for (i = 0; i<n; i++){

        if(A[i] == num){
            count_nums += 1;
        }
    }

    return count_nums;
}

// finds the element replaces with -1 and gives the counter back - works
int find_and_replace_with_minusOne(int array1[], int n, int num_to_find, int processes_evicted[], int *processes_evicted_counter2){
    int i = 0, counting2 = 0, processes_evicted_counter3 = 0;

    processes_evicted_counter3 = *processes_evicted_counter2;

    for (i = 0; i<n; i++){
        if (array1[i] == num_to_find){
            array1[i] = -1;
            processes_evicted[processes_evicted_counter3] = i;
            counting2 += 1;
            processes_evicted_counter3 += 1;
        }
    }
    *processes_evicted_counter2 = processes_evicted_counter3;
    return counting2;
}

//  find_and_replace_with_process_vr(memoryArray, memory_pages_on_disk, temp_num, processes_evicted, &processes_evicted_counter2, current_process, &current_pages_filled2);
int find_and_replace_with_process_vr(int array1[], int n, int num_to_find, int processes_evicted[], int *processes_evicted_counter2, int current_process, int count_pages, int *current_pages_filled2, int new_threshold) {
    int i = 0, counting2 = 0, processes_evicted_counter3 = 0, current_pages_filled3 = 0;

    processes_evicted_counter3 = *processes_evicted_counter2;
    current_pages_filled3 = *current_pages_filled2;
    //printf("find and replace function start, current pages filled3 = %d\n", current_pages_filled3);

    for (i = 0; i<n; i++){
        // if (array1[i] == current_process) {
        //     count_pages -= 1;
        //     counting2 += 1;
        //     current_pages_filled3 += 1;
        //     if (current_pages_filled3 == FOUR_PAGES){
        //         break;
        //     }
        //     if (count_pages == 0){
        //         break;
        //     }
        // }
        if (array1[i] == num_to_find){
            array1[i] = current_process;
            processes_evicted[processes_evicted_counter3] = i;
            counting2 += 1;
            processes_evicted_counter3 += 1;
            // count_pages -= 1;
            
            //printf("find and replace function before increment, current pages filled3 = %d, count_pages = %d\n", current_pages_filled3, count_pages);
            current_pages_filled3 += 1;
            //printf("find and replace function before increment, current pages filled3 = %d, count_pages = %d\n", current_pages_filled3, count_pages);
            if (current_pages_filled3 == FOUR_PAGES){
                break;
            }
            // if (count_pages == 0){
            //     break;
            // }
        }
    }
    *processes_evicted_counter2 = processes_evicted_counter3;
    *current_pages_filled2 = current_pages_filled3;
    return counting2;
}

// finds the element replaces with -1 and gives the counter back - works
void find_and_replace_with_minusOne_Void(int array1[], int n, int num_to_find){
    int i = 0, counting2 = 0;

    for (i = 0; i<n; i++){
        if (array1[i] == num_to_find){
            array1[i] = -1;
            counting2 += 1;
        }
    }
}

// fill up empty spaces (-1) with the element given and returns current pages 
int fill_up_empty_spaces(int array2[], int max_num, int element_num, int current_pages2){
    int i = 0;

    // printf("element_num = %d\n", element_num);
    // printf("current_pages2 = %d\n", current_pages2);

    for (i = 0; i<max_num; i++){
        if(array2[i] == -1){
            if (current_pages2 > 0 ){
                array2[i] = element_num;
                current_pages2 -= 1;
            }
        }
    }
    // current_pages2 = current_pages2 - counting;

    return current_pages2;
}

// fill up empty spaces (-1) with the element given and returns current pages 
int fill_up_empty_spaces2(int array2[], int max_num, int element_num, int current_pages2, int *sum_pages){
    int i = 0;

    // printf("element_num = %d\n", element_num);
    // printf("current_pages2 = %d\n", current_pages2);

    for (i = 0; i<max_num; i++){
        if(array2[i] == -1){
            if (current_pages2 > 0 ){
                array2[i] = element_num;
                current_pages2 -= 1;
                *sum_pages += 1;
            }
        }
    }
    // current_pages2 = current_pages2 - counting;

    return current_pages2;
}

// creating space by eviction - swapping works in rr algorithm i think
int create_space_evict(int memoryArray[],int memory_pages_on_disk, int processes_to_evict[],int processes_to_evict_total, int pages_required,int temp_val2, int current_pages, int processes_evicted[], int *processes_evicted_counter){
    int condition = 0, temp_num = 0, count_pages = 0, evicted_pages = 0, processes_evicted_counter2 = 0;

    processes_evicted_counter2 = *processes_evicted_counter;
    count_pages = current_pages;
    while (condition == 0){
        if (count_pages > 0){
            // temp_v1 = processes_to_evict[temp_val2]
            // find_and_replace_with_minusOne(memoryArray, memory_pages_on_disk, temp_v1);
            // result2 = fill_up_empty_spaces(memoryArray, memory_pages_on_disk, temp_v1, current_pages);
            // current_pages = current_pages - result2;
            temp_num = processes_to_evict[temp_val2];
            temp_val2 += 1;
            evicted_pages = find_and_replace_with_minusOne(memoryArray, memory_pages_on_disk, temp_num, processes_evicted, &processes_evicted_counter2);
            //print_the_array(processes_evicted, processes_evicted_counter2);
            count_pages = count_pages - evicted_pages;
            if (count_pages == 0){
                condition = 1;
            }
        }
    }

    *processes_evicted_counter = processes_evicted_counter2;

    return temp_val2;

}

// prints out the memory on disk or any other array - works
void print_the_memory(int memoryArray[], int memory_pages_on_disk){
    int i = 0;

    for (i=0; i<memory_pages_on_disk; i++) {
        printf(" %d", memoryArray[i]);
    }
    printf("\n");
}

// create space evict in vr algorithm AND also replace with the process we need
int create_space_evict_vr(int memoryArray[],int memory_pages_on_disk, int processes_to_evict[],int processes_to_evict_total, int pages_required,int temp_val2, int current_pages, int processes_evicted[], int *processes_evicted_counter, int current_process, int *current_pages_filled, int *real_current_pages_filled){
    int condition = 0, temp_num = 0, count_pages = 0, evicted_pages = 0, processes_evicted_counter2 = 0, current_pages_filled2 = 0, result5 = 0, same_process_quantity = 0, new_threshold = FOUR_PAGES;

    processes_evicted_counter2 = *processes_evicted_counter;
    count_pages = current_pages;
    current_pages_filled2 = *current_pages_filled;

    // count how many we already have in memory
    same_process_quantity = count_how_many_of_an_element(memoryArray, memory_pages_on_disk, current_process);

    // if we found what we need then reduce the needed quantity
    // new_threshold -= same_process_quantity;

    current_pages_filled2 += same_process_quantity;

    if (current_pages_filled2 == FOUR_PAGES){
        return temp_val2;
    }

    // printf("488|| same_process_quantity == %d\n", same_process_quantity);
    // printf("488|| new_threshold == %d\n", new_threshold);

    while (condition == 0) {
        // grab the oldest process
        temp_num = processes_to_evict[temp_val2];

        // if the process to evict is the current process then skip it nothing to do here
        if (temp_num == current_process) {
            temp_val2 += 1;

        // if process to evict is not the current process then we have something to actually evict
        } else {
            // printf("501 - process to evict = %d, current_pages_filled2 = %d, current_process =%d\n", temp_num, current_pages_filled2, current_process);

            // printf("before eviction memory array below:\n");
            // print_the_memory(memoryArray, memory_pages_on_disk);
            // replace it with the process
            evicted_pages = find_and_replace_with_process_vr(memoryArray, memory_pages_on_disk, temp_num, processes_evicted, &processes_evicted_counter2, current_process,count_pages, &current_pages_filled2, new_threshold);
            // printf("after eviction memory array below:\n");
            // print_the_memory(memoryArray, memory_pages_on_disk);
            // if we the count pages are 0 we re good
            // count_pages = count_pages - evicted_pages;
            //current_pages_filled2 = count_pages;

            //printf("451 || current_pages_filled2 = %d\n",current_pages_filled2);
            // only proceed to the next element if there are no other processes to evict in the memory - we did as many as we could from this one
            result5 = check_if_array_has_a_number(memoryArray, memory_pages_on_disk, temp_num);
            if (result5 == 0){
                temp_val2 += 1;
            }

            if (current_pages_filled2 == FOUR_PAGES){
                condition = 1;
            }
            // if (count_pages == 0){
            //     condition = 1;
            // }
        }

    }

    *real_current_pages_filled = current_pages_filled2 - same_process_quantity;
    *current_pages_filled = current_pages_filled2;
    *processes_evicted_counter = processes_evicted_counter2;
    return temp_val2;
}

// create space evict in vr algorithm AND also replace with the process we need
int create_space_evict_vr2(int memoryArray[],int memory_pages_on_disk, int processes_to_evict[],int *processes_to_evict_total, int pages_required,int temp_val2, int current_pages, int processes_evicted[], int *processes_evicted_counter, int current_process, int *current_pages_filled, int *real_current_pages_filled, int *saved_eviction){
    int condition = 0, temp_num = 0, count_pages = 0, evicted_pages = 0, processes_evicted_counter2 = 0, current_pages_filled2 = 0, result5 = 0, same_process_quantity = 0, new_threshold = FOUR_PAGES, vr_counter = 0;

    // printf("\ninside vr2\n\n");
    // printf("this is the latest process to evict = %d\n", processes_to_evict[*processes_to_evict_total - 1]);
    // printf("this is the one before that process to evict = %d\n", processes_to_evict[*processes_to_evict_total - 2]);
    // processes_to_evict_total2 = *processes_to_evict_total;
    processes_evicted_counter2 = *processes_evicted_counter;
    count_pages = current_pages;
    current_pages_filled2 = *current_pages_filled;

    // count how many we already have in memory
    same_process_quantity = count_how_many_of_an_element(memoryArray, memory_pages_on_disk, current_process);

    // if we found what we need then reduce the needed quantity
    // new_threshold -= same_process_quantity;

    current_pages_filled2 += same_process_quantity;

    if (current_pages_filled2 == FOUR_PAGES){
        return temp_val2;
    }

    // printf("488|| same_process_quantity == %d\n", same_process_quantity);
    // printf("488|| new_threshold == %d\n", new_threshold);

    // if (*saved_eviction == -1){
    //     *saved_eviction = processes_to_evict[*processes_to_evict_total-1];
    //     temp_num2 = *saved_eviction;
    // }

    // if (*saved_eviction != -1){
    //     temp_num2 = saved_eviction;
    //     vr_counter = *processes_to_evict_total-1;

    // }
    // if (*saved_eviction == -1) {
    //     temp_num2 = processes_to_evict[*processes_to_evict_total-1];
    //     *saved_eviction = temp_num2;
    //     vr_counter = *processes_to_evict_total-1;
    // }

    vr_counter = *processes_to_evict_total-1;

    while (condition == 0) {
        // grab the oldest process
        // temp_num = processes_to_evict[temp_val2];
        //temp_num = processes_to_evict[*processes_to_evict_total-1];


        if (*saved_eviction != -1){
            temp_num = *saved_eviction;
            vr_counter = *processes_to_evict_total-1;

        }
        if (*saved_eviction == -1) {
            temp_num = processes_to_evict[vr_counter];
            *saved_eviction = temp_num;
            vr_counter -= 1;  
        }
        // printf("624||  processes_to_evict[vr_counter] = temp_num = %d\n", temp_num);
        // printf("saved_eviction = %d, processes_to_evict_total-1 = %d\n", *saved_eviction, *processes_to_evict_total-1);
        // printf("vr_counter = %d\n", vr_counter);


        // printf("temp_num official to evict == %d  ||memory below\n", temp_num);

        //print_the_memory(memoryArray, memory_pages_on_disk);

        //printf("590 inside create space func || process to evict = %d, temp_val2 = %d ,current_pages_filled2 = %d, current_process =%d\n", temp_num, temp_val2, current_pages_filled2, current_process);

        // if the process to evict is the current process then skip it nothing to do here
        if (temp_num == current_process) {
            // temp_val2 += 1;
            // *processes_to_evict_total -= 1;
            //printf("\n\n\n 618|| RED ALERT \n\n\n");
            *saved_eviction = -1;

        // if process to evict is not the current process then we have something to actually evict
        } else {
            // printf("596 - process to evict = %d, current_pages_filled2 = %d, current_process =%d\n", temp_num, current_pages_filled2, current_process);

            // printf("646|| before eviction - replacement inside inside memory array below:\n");
            // print_the_memory(memoryArray, memory_pages_on_disk);
            // replace it with the process
            evicted_pages = find_and_replace_with_process_vr(memoryArray, memory_pages_on_disk, temp_num, processes_evicted, &processes_evicted_counter2, current_process,count_pages, &current_pages_filled2, new_threshold);
            // printf("after eviction memory array below:\n");
            // print_the_memory(memoryArray, memory_pages_on_disk);
            // if we the count pages are 0 we re good
            // count_pages = count_pages - evicted_pages;
            //current_pages_filled2 = count_pages;

            //printf("451 || current_pages_filled2 = %d\n",current_pages_filled2);
            // only proceed to the next element if there are no other processes to evict in the memory - we did as many as we could from this one
            result5 = check_if_array_has_a_number(memoryArray, memory_pages_on_disk, temp_num);
            if (result5 == 0){
                // temp_val2 += 1;
                // *processes_to_evict_total -= 1;
                *saved_eviction = -1;
                // printf("temp_val2 has been incremented by 1 = %d\n", temp_val2);
                //printf("saved eviction = -1 = \n");
            }

            if (current_pages_filled2 == FOUR_PAGES){
                condition = 1;
            }
            // if (count_pages == 0){
            //     condition = 1;
            // }
        }

    }

    *processes_to_evict_total -= 1;
    *real_current_pages_filled = current_pages_filled2 - same_process_quantity;
    *current_pages_filled = current_pages_filled2;
    *processes_evicted_counter = processes_evicted_counter2;
    return temp_val2;
}

// checks if processes arrived and placed at the end of the queue for ff
int check_if_a_process_arrived_for_ff(int timeArray[], int counter, int time1){
    int i = 0,counting2 = 0; 

    for (i=0; i<counter; i++){
        if(time1 >= timeArray[i] ){
            counting2 += 1;
        }
    }
    // printf("counting2 = %d\n", counting2);
    return counting2;
}

// checks if second array's next element is empty
int check_if_secondArray_empty_next(int timeArray2[],int processArray2[],int sizeArray2[],int runningTimeArray2[], int counter2){
    int result3 = 0;

    if (timeArray2[counter2+1] == -1){
        result3 = 1;
    }
    return result3;
}

// check if a number is in an array and return 1 if yes and 0 if no - works
int check_if_element_in_array(int arr[], int n, int num_to_find2){
    int i = 0, result2 = 0;

    //printf("num_to_find = %d\n", num_to_find2);

    for (i=0; i<n;i++){
        if (arr[i] == num_to_find2){
            //printf("arr[i] = %d, num_to_find2 = %d\n", arr[i], num_to_find2);
            result2 = 1;
        }
    }
    //printf("result = %d\n", result2);
    return result2;
}

// check if we have more processes on the original list timeArray. if we do give a signal so we dont finish the program and adjust the time - works
int check_if_we_have_more_processes_in_list(int timeArray2[],int processArray2[],int sizeArray2[],int runningTimeArray2[],int counter2, int *time_robin, int counter, int *counterCopy, int timeArray[],int processArray[],int sizeArray[],int runningTimeArray[]){
    int i=0, result4 = 0, result5 = 0, condition = 0, temp_timeArray = 0;

    // printf("timerobin = %d\n", *time_robin);
    for(i=0;i<counter;i++){
        // check if there are more processes with larger times
        if (*time_robin <= timeArray[i]){
            // check if we processes it before
            // printf("yes line 376 timeArray = %d\n", timeArray[i]); 
            result4 = check_if_element_in_array(timeArray2, *counterCopy, timeArray[i]);
            if (result4 == 0){
                // allow this to happen only one time
                if (condition == 0){
                    result5 = 1;
                    // for safety
                    temp_timeArray = timeArray[i];
                    // printf("377 timeArray = %d\n", timeArray[i]); 
                    // change time robin to the next time
                    *time_robin = temp_timeArray;
                    condition = 1;
                    // add at the end of the queue
                    processArray2[*counterCopy+1] = processArray[i];
                    runningTimeArray2[*counterCopy+1] = runningTimeArray[i];
                    timeArray2[*counterCopy+1] = timeArray[i];
                    sizeArray2[*counterCopy+1] = sizeArray[i];
                    *counterCopy += 1;
                    // printf("adding now 395, counterCopy = %d\n", *counterCopy);
                    // print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 10);
                }
            }
        }
    }
    return result5;
}

// checks if we allocated space for the process_id - works
int check_if_we_placed_the_pages(int arr[],int n,int pages_required,int process_id){
    int i = 0, counting3 = 0, result33 = 0;

    for(i=0;i<n;i++){
        if(arr[i] == process_id){
            counting3 += 1;
        }
    }
    if (counting3 == pages_required){
        result33 = 1;
    }
    return result33;
}

// works
int count_how_many_not_minus1(int anotherArray[], int n){
    int i = 0, anotherCounter = 0;

    for(i=0;i<n;i++){
        if (anotherArray[i] != -1){
            anotherCounter += 1;
        }
    }
    return anotherCounter;
}

// works i think
int count_how_many_not_minus1_after_element(int array3[], int n, int current_position){
    int i = 0, counter3 = 0;

    for(i=current_position;i<n;i++){
        if (array3[i] != -1){
            counter3 += 1;
        }
    }
    return counter3;
}

// adds the arrived processes to the third arrayfor cs alg
int check_what_process_has_arrived_and_add_to_thirdArray(int processArray3[],int sizeArray3[],int runningTimeArray3[],int timeArray3[],int processArray[],int sizeArray[],int runningTimeArray[],int timeArray[],int counter,int counter3, int time_robin, int counterCopy, int timeArray2[]){
    int i = 0, total_count = 0, result = 0, counterCopy2 = 0;

    counterCopy2 = counterCopy;
    counterCopy2 -= 1;

    for (i = 0; i<counter; i++){
        if ((timeArray[i] <= time_robin) && (timeArray[i] != 0)){
            result = check_if_element_in_array(timeArray2, counter, timeArray[i]);
            if (result == 0){
                printf("process to be added to the third array since it arrived now = %d\n", timeArray[i]);
                processArray3[total_count] = processArray[i];
                sizeArray3[total_count] = sizeArray[i];
                runningTimeArray3[total_count] = runningTimeArray[i];
                timeArray3[total_count] = timeArray[i];
                total_count += 1; 
            }
        }
    }
    return total_count;
}

// https://www.geeksforgeeks.org/bubble-sort/
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

//https://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
// https://www.geeksforgeeks.org/bubble-sort/
// A function to implement bubble sort  
void bubbleSort(int processArray3[],int sizeArray3[],int arr[],int timeArray3[], int n)  
{  
    int i= 0, j = 0;  
    int temp_val4 = 0;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place  
        for (j = 0; j < n-i-1; j++){  
            //printf("ar[j] = %d, ar[j+1] = %d\n", arr[j], arr[j+1]);
            if (arr[j] > arr[j+1]){  
                // swap(&arr[j], &arr[j+1]);
                // printf("yes arj > arj+1\n");
                // printf("ar[j] = %d, ar[j+1] = %d\n", arr[j], arr[j+1]);

                // swap(&processArray3[j], &processArray3[j+1]);
                // swap(&sizeArray3[j], &sizeArray3[j+1]);
                // swap(&timeArray3[j], &timeArray3[j+1]);

                temp_val4 = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp_val4;

                temp_val4 = processArray3[j];
                processArray3[j] = processArray3[j+1];
                processArray3[j+1] = temp_val4;

                temp_val4 = sizeArray3[j];
                sizeArray3[j] = sizeArray3[j+1];
                sizeArray3[j+1] = temp_val4;

                temp_val4 = timeArray3[j];
                timeArray3[j] = timeArray3[j+1];
                timeArray3[j+1] = temp_val4;
            }
        }
    }
} 


// main
int main(int argc, char ** argv)
{
    int time = 0, process = 0, size = 0, runningTime = 0, counter = 0, i = 0, start = 0, finish = 0, temp_current_pages_filled = 0;
    int quantum = 0, condition = 0,remainingTime = 0,counter2 = 0,counterCopy = 0, k = 0;
    int timeArray[ELEMENTS]= {0}, processArray[ELEMENTS]= {0}, sizeArray[ELEMENTS]= {0},runningTimeArray[ELEMENTS]= {0};
    int result = 0, alg_condition = 0, file_condition = 0, time_robin = 0, makespan = 0, proc_remain=0;
    int countProcesses[ELEMENTS] = {0}, min_proc = 0, max_proc = 0;
    char algorithm[ELEMENTS] = "", fileName[ELEMENTS] = "",memoryTypeArray[ELEMENTS] = "", memorySpaceArray[ELEMENTS] = "", quantumArray[ELEMENTS] = "";
    char justOneLine[LINE_MAX]="";
    float turnAroundTime=0.0, timeOverhead = 0.0, timeOverheadMax = 0.0, timeOverheadSum = 0.0, twoSteps = 0.0, aver_proc = 0.0, aver_proc2 = 0.0, mem_usage_float = 0.0,  mem_usage_float2 =0.0;
    int remainder = 0, remainder_max = 0, saved_finish = 0, processes_to_evict[ELEMENTS] = {0}, processes_evicted[ELEMENTS]= {0}, processes_evicted_counter = 0, sum_pages = 0, total_count3 = 0, saved_eviction = 0;
    int timeArray2[ELEMENTS]= {0}, processArray2[ELEMENTS]= {0}, sizeArray2[ELEMENTS]= {0},runningTimeArray2[ELEMENTS]= {0};
    int timeArray3[ELEMENTS]= {0}, processArray3[ELEMENTS]= {0}, sizeArray3[ELEMENTS]= {0},runningTimeArray3[ELEMENTS]= {0};
    int new_process = 0, counterCopy2 = 0, num_of_proc_added = 0, mem_condition = 0, mem_condition2 = 0, aver_proc2_int = 0, processes_to_evict_counter = 0, processes_to_evict_total = 0, current_pages2 = 0, counter3 = 0;
    int memory_pages_on_disk = 0, memoryArray[ELEMENTS] = {0}, pages_required = 0, load_time = 0, mem_usage = 0, temp_val2 = 0,current_pages = 0, temp_val3 = 0, page_fault_number = 0, temp_num2 = 0, actual_current_pages_filled = 0;
    int finished_proc = 0, empty_second_array_next = 0, placed_pages_status = 0, remainingTimeSaved = 0, quant_condition = 0, quantExists = 0, check_eviction_status = 0, pick_your_mem = 0, pick_your_alg = 0, current_pages_filled = 0, real_current_pages_filled = 0;

    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");
    // printf("****************************************************************************************\n");


    //print the arguments
    for(i = 1; i < argc; i++) {
        // printf("%s\n", argv[i]);

        if (alg_condition == 1){
            strcpy(algorithm, argv[i]);
            alg_condition = 0;
        }
        if (file_condition == 1){
            strcpy(fileName, argv[i]);
            file_condition = 0;
        }
        if (mem_condition == 1){
            strcpy(memoryTypeArray, argv[i]);
            mem_condition = 0;
        }
        if (mem_condition2 == 1){
            strcpy(memorySpaceArray, argv[i]);
            mem_condition2 = 0;
        }
        if (quant_condition == 1){
            strcpy(quantumArray, argv[i]);
            quant_condition = 0;
            quantExists = 1;
        }
        result = compare_strings(argv[i], "-a");
        if (result == 1) {
            //printf("-f detected !! \n");
            alg_condition = 1;
        }
        result = compare_strings(argv[i], "-f");
        if (result == 1) {
            //printf("-f detected !! \n");
            file_condition = 1;
        }
        result = compare_strings(argv[i], "-m");
        if (result == 1) {
            //printf("-f detected !! \n");
            mem_condition = 1;
        }
        result = compare_strings(argv[i], "-s");
        if (result == 1) {
            //printf("-f detected !! \n");
            mem_condition2 = 1;
        }
        result = compare_strings(argv[i], "-q");
        if (result == 1) {
            //printf("-f detected !! \n");
            quant_condition = 1;
        }
    }
    // calculate the amount of pages available for us in memory
    memory_pages_on_disk = atoi(memorySpaceArray);
    memory_pages_on_disk = memory_pages_on_disk/PAGES;

    saved_eviction = -1;

    // figure out what's the quantum
    if (quantExists == 1){
        quantum = atoi(quantumArray);
    } else {
        quantum = QUANTUM;
    }
    
    // printf("memory_pages_on_disk = %d\n", memory_pages_on_disk);  
    result = 0;

    // printf("Algorithm is %s\n", algorithm);
    // printf("File Name is %s\n", fileName);
    // printf("memorySpaceArray = %s\n", memorySpaceArray);
    // printf("memoryTypeArray = %s\n", memoryTypeArray);

    // printf("\n");
    // printf("\n");
    // printf("\n");

    // printf("\n");
    // source: https://www.youtube.com/watch?v=8nIilb2kiSU
    // open, read and save the file

    // FILE * file2;
    // int fileNameLimit2 = strlen(fileName2);
    // fileName2[fileNameLimit2]='\0';
    // file2 = fopen(fileName2, "r");
    // // char justOneLine2[LINE_MAX];
    // while(fgets(justOneLine2, LINE_MAX, file2)) {
    //     counter+=1;
    // }
    // counter = 0;

    FILE * file1;

    int fileNameLimit = strlen(fileName);
    fileName[fileNameLimit]='\0';

    file1 = fopen(fileName, "r");

    // char justOneLine[LINE_MAX];

    // initialize arrays
    // memset(processArray,-1, sizeof(processArray));
    memset(memoryArray,-1, sizeof(memoryArray));
    memset(processes_to_evict,-1, sizeof(processes_to_evict));
    memset(processArray2 ,-1, sizeof(processArray2));
    memset(timeArray2,-1, sizeof(timeArray2));
    memset(sizeArray2 ,-1, sizeof(sizeArray2));
    memset(runningTimeArray2 ,-1, sizeof(runningTimeArray2));
    memset(processes_to_evict ,-1, sizeof(processes_to_evict));
    memset(processes_evicted ,-1, sizeof(processes_evicted));


    // read line by line and save the values with sscanf
    while(fgets(justOneLine, LINE_MAX, file1)) {
        // printf("%s\n", justOneLine);
        //puts(justOneLine);
        // parsing the line into variables in order to save them
        sscanf(justOneLine, "%d%d%d%d", &time, &process, &size, &runningTime);
        // printf("%d\n", time);
        // printf("%d\n", process);
        // printf("%d\n", size);
        // printf("%d\n\n", runningTime);

        // save into arrays
        timeArray[counter] = time;
        processArray[counter] = process;
        sizeArray[counter] = size;
        runningTimeArray[counter] = runningTime;
        counter += 1;
    }

    //printf("counter = %d\n", counter);

    sort_the_arrays(timeArray, processArray, sizeArray, runningTimeArray, counter);


    //print_arrays(timeArray,processArray,sizeArray,runningTimeArray, counter);
    memcpy(timeArray3,timeArray,counter*sizeof(int));
    memcpy(processArray3,processArray,counter*sizeof(int));
    memcpy(sizeArray3,sizeArray,counter*sizeof(int));
    memcpy(runningTimeArray3,runningTimeArray,counter*sizeof(int));
    //print_arrays(timeArray3,processArray3,sizeArray3,runningTimeArray3, counter);

    // check which algorithm we re going for and which memory we re going for from the command line
    result = compare_strings(algorithm, "ff");
    if (result == 1) {
        pick_your_alg = 1;
    }
    result = compare_strings(algorithm, "rr");
    if (result == 1) {
        pick_your_alg = 2;
    }
    result = compare_strings(algorithm, "cs");
    if (result == 1) {
        pick_your_alg = 3;
    }
    result = compare_strings(memoryTypeArray, "u");
    if (result == 1){
        pick_your_mem = 1;
    }
    result = compare_strings(memoryTypeArray, "p");
    if (result == 1){
        pick_your_mem = 2;
    }
    result = compare_strings(memoryTypeArray, "v");
    if (result == 1){
        pick_your_mem = 3;
    }
    result = compare_strings(memoryTypeArray, "cm");
    if (result == 1){
        pick_your_mem = 4;
    }

    // run fcfs algorithm if triggered from the command line - works
    if (pick_your_alg == 1){

        for (i = 0; i < counter; i++){
            if (i == 0) {
                start = timeArray[i];
            } else {
                // printf("saved_finish = %d\n", saved_finish);
                start = saved_finish;
                // in case a process comes later then adjsut the start time to match it
                if (start < timeArray[i]){
                    start = timeArray[i];
                }
            }
            finish = start + runningTimeArray[i];
            // proc_remain -=1;
            if (pick_your_mem == 1){
                // printf("result = 0\n\n\n\n\n");
                printf("%d, RUNNING, id=%d, remaining-time=%d\n", start, processArray[i], runningTimeArray[i]);

                // check for virtual memory and proceed with that option if necessaary
            }

            // /Swapping Mode on
            if (pick_your_mem == 2) {
                // printf("result = 1\n\n\n\n\n");
                pages_required = sizeArray[i]/PAGES;
                // printf("345 pages pages_required = %d\n", pages_required);

                // // check how many pages available and free in memory at the moment
                // pages_free_in_memory = check_for_space(memoryArray, pages_required,memory_pages_on_disk);

                // print_the_memory(memoryArray, memory_pages_on_disk);

                temp_val3 = processArray[i];
                // printf("line 500 process = %d\n", temp_val3);
                current_pages = pages_required;
                current_pages2 = current_pages;
                current_pages =  fill_up_empty_spaces(memoryArray, memory_pages_on_disk, temp_val3, current_pages2);
                // printf("681 memory below array, current_pages = %d\n", current_pages);
                // print_the_memory(memoryArray, memory_pages_on_disk);

                // current_pages = pages_required - pages_used;

                // if we filled up all the available spaces but we still need to allocate pages then evict - swapping
                if (current_pages > 0 ){
                    // copy and give back the current position of the next to evict
                    temp_val2 = processes_to_evict_counter;
                    processes_to_evict_counter = create_space_evict(memoryArray,memory_pages_on_disk, processes_to_evict, processes_to_evict_total, pages_required,temp_val2, current_pages, processes_evicted, &processes_evicted_counter);
                    //printf("691 memory below array\n");
                    //print_the_memory(memoryArray, memory_pages_on_disk);
                    current_pages2 = current_pages;
                    current_pages =  fill_up_empty_spaces(memoryArray, memory_pages_on_disk, temp_val3, current_pages2);
                    //printf("695 memory below array\n");
                    //print_the_memory(memoryArray, memory_pages_on_disk);
                }

                check_eviction_status = check_if_array_is_empty(processes_evicted, memory_pages_on_disk);
                if (check_eviction_status == 0){
                    printf("%d, EVICTED, mem-addresses=[", finish);
                    // printing_pages2(memoryArray, pages_required, processArray[i]);
                    print_the_array(processes_evicted, processes_evicted_counter);
                    printf("]\n");
                    initialize_the_ints(processes_evicted, processes_evicted_counter);
                    processes_evicted_counter = 0;
                }

                //printf("724|| check_eviction_status = %d\n", check_eviction_status);


                // // place pages in memory after we make sure we have space
                // pages_remaining = place_pages_in_memory(memoryArray,memory_pages_on_disk,timeArray,processArray,sizeArray,runningTimeArray,counter, i, pages_required);

                // save the process used in the list in case we want to evict later
                processes_to_evict[processes_to_evict_total] = processArray[i];
                processes_to_evict_total += 1;

                load_time = TWO * pages_required;
                finish += load_time;
                // mem_usage = (pages_required*HUNDRED)/memory_pages_on_disk;
                mem_usage = count_how_many_not_minus1(memoryArray, memory_pages_on_disk);
                // mem_usage = (mem_usage*HUNDRED)/memory_pages_on_disk;

                mem_usage_float = (mem_usage*HUNDRED*1.0)/memory_pages_on_disk;

                mem_usage_float2 = round_up_float(mem_usage_float);

                mem_usage = (int)(mem_usage_float2);

                // aver_proc = ((counter*1.0) / remainder_max);
                // aver_proc2 = round_up_float(aver_proc);
                // aver_proc2_int = (int)(aver_proc2);

                printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", start, processArray[i], runningTimeArray[i], load_time, mem_usage);
                printing_pages2(memoryArray, pages_required, processArray[i]);
            }


            // /Virtual Memory Mode on
            if (pick_your_mem == 3) {
                // get pages required
                pages_required = sizeArray[i]/PAGES;
                temp_val3 = processArray[i];
                // printf("line 500 process = %d\n", temp_val3);
                // fill up the array first 
                current_pages = pages_required;
                current_pages2 = current_pages;
                current_pages =  fill_up_empty_spaces(memoryArray, memory_pages_on_disk, temp_val3, current_pages2);

                // calculate how many pages we filled so we know for virtual memory
                current_pages_filled = pages_required - current_pages;
                // printf("current_pages_filled = %d\n", current_pages_filled);
                // print_the_memory(memoryArray, memory_pages_on_disk);

                // if we filled up all the available spaces but we still need to allocate pages (cause not 4 yet) then evict - VR
                if (current_pages_filled < FOUR_PAGES){
                    if (current_pages > 0 ){
                        temp_val2 = processes_to_evict_counter;
                        processes_to_evict_counter = create_space_evict_vr(memoryArray,memory_pages_on_disk, processes_to_evict, processes_to_evict_total, pages_required,temp_val2, current_pages, processes_evicted, &processes_evicted_counter, processArray[i], &current_pages_filled, &real_current_pages_filled);
                        page_fault_number = pages_required - current_pages_filled;
                    }
                }

                check_eviction_status = check_if_array_is_empty(processes_evicted, memory_pages_on_disk);
                // print_the_array(processes_evicted, 10);
                if (check_eviction_status == 0){
                    printf("%d, EVICTED, mem-addresses=[", finish);
                    // printing_pages2(memoryArray, pages_required, processArray[i]);
                    print_the_array(processes_evicted, processes_evicted_counter);
                    printf("]\n");
                    initialize_the_ints(processes_evicted, processes_evicted_counter);
                    processes_evicted_counter = 0;
                }
                //printf("check_eviction_status = %d\n", check_eviction_status);
                // print_the_array(processes_evicted, 30);
                // printf("\npage fault = %d, pages required = %d, current pages filled = %d\n", page_fault_number, pages_required, current_pages_filled);


                //printf("724|| check_eviction_status = %d\n", check_eviction_status);

                // // place pages in memory after we make sure we have space
                // pages_remaining = place_pages_in_memory(memoryArray,memory_pages_on_disk,timeArray,processArray,sizeArray,runningTimeArray,counter, i, pages_required);

                // save the process used in the list in case we want to evict later
                processes_to_evict[processes_to_evict_total] = processArray[i];
                processes_to_evict_total += 1;

                // printf(" processes to evict array below: \n");
                // print_the_array(processes_to_evict, 15);
                // printf("\n");

                load_time = TWO * pages_required;
                load_time += page_fault_number;
                finish += load_time;
                // mem_usage = (pages_required*HUNDRED)/memory_pages_on_disk;
                mem_usage = count_how_many_not_minus1(memoryArray, memory_pages_on_disk);
                // mem_usage = (mem_usage*HUNDRED)/memory_pages_on_disk;

                mem_usage_float = (mem_usage*HUNDRED*1.0)/memory_pages_on_disk;

                mem_usage_float2 = round_up_float(mem_usage_float);

                mem_usage = (int)(mem_usage_float2);

                // aver_proc = ((counter*1.0) / remainder_max);
                // aver_proc2 = round_up_float(aver_proc);
                // aver_proc2_int = (int)(aver_proc2);

                printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", start, processArray[i], runningTimeArray[i], load_time, mem_usage);
                printing_pages2(memoryArray, pages_required, processArray[i]);




            }



            saved_finish = finish;
            proc_remain = check_if_a_process_arrived_for_ff(timeArray, counter, finish);
            finished_proc += 1;
            proc_remain -= finished_proc;
            if ((pick_your_mem == 2) || (pick_your_mem == 3)) {
                // EVICTED printf
                printf("%d, EVICTED, mem-addresses=[", finish);
                printing_pages2(memoryArray, memory_pages_on_disk, processArray[i]);
                // erase them from memory - replace with -1
                find_and_replace_with_minusOne_Void(memoryArray, memory_pages_on_disk, processArray[i]);
                // printf("754|| lets see if it's erased below\n");
                // print_the_array(memoryArray, memory_pages_on_disk);
                // printf("756|| lets see if it's erased above\n");

            }
            printf("%d, FINISHED, id=%d, proc-remaining=%d\n", finish, processArray[i], proc_remain);
            // print_the_memory(memoryArray, memory_pages_on_disk);
            turnAroundTime += ((finish - timeArray[i])*1.0);
            timeOverhead = (((finish - timeArray[i])*1.0) / runningTimeArray[i]);
            if (timeOverhead > timeOverheadMax){
                timeOverheadMax = timeOverhead;
            }
            timeOverheadSum += timeOverhead;

            remainder = (finish-1)/60;
            // remainder = remainder - 1;
            // printf("remainder = %d, finish = %d\n", remainder, finish);
            // printf("countProcesses[remainder] = %d\n", countProcesses[remainder]);
            countProcesses[remainder] += 1;
            if (remainder > remainder_max) {
                remainder_max = remainder;
            }
            remainder = 0;

            // printf("\n\n273 current_proc = %d, proc_counter = %d \n\n", current_proc, proc_counter);
        }
        // for (i=0;i<intervalsCounter;i++){
        //     printf("\nfinal countProcesses: %d\n", countProcesses[i]);
        // }

        makespan = finish;
        // min_proc = find_min_num(countProcesses, intervalsCounter);
        // // printf("min is: %d\n", min_proc);
        // max_proc = find_max_num(countProcesses, intervalsCounter);
        // aver_proc = counter / intervalsCounter;
        // float yes = 0.0;
        // yes = ceil((turnAroundTime*1.0)/counter);
        // printf("this is yes: %f\n", yes);
        timeOverheadSum = (timeOverheadSum / counter);

        turnAroundTime = ceil((turnAroundTime/counter)*1.0);
        int turnAroundTime2 = (int)turnAroundTime;

        // for(i=0;i<remainder_max+1;i++){
        //     // printf("this is the countProcesses array: %d\n", countProcesses[i]);
        // }
        // printf("this is the remainder_max = %d\n", remainder_max);
        remainder_max += 1;
        min_proc = find_min_num(countProcesses, remainder_max);
        // printf("min is: %d\n", min_proc);
        max_proc = find_max_num(countProcesses, remainder_max);
        // printf("max is: %d\n", max_proc);
        aver_proc = ((counter*1.0) / remainder_max);
        aver_proc2 = round_up_float(aver_proc);
        aver_proc2_int = (int)(aver_proc2);

        printf("Throughput %d, %d, %d\n", aver_proc2_int, min_proc, max_proc);
        // printf("Turnaround time %d\n", turnAroundTime2);
        // printf("Throughput %d, %d, %d\n", aver_proc, min_proc, max_proc);
        // printf("Throughput %d, %d, %d\n", aver_proc, min_proc, max_proc);
        printf("Turnaround time %d\n", turnAroundTime2);
        printf("Time overhead %.2f %.2f\n", timeOverheadMax,timeOverheadSum);
        printf("Makespan %d\n", makespan);
        //print_arrays(timeArray,processArray,sizeArray,runningTimeArray, counter);
        fclose(file1);
        return 0;
    }

    // run rr algorithm - works
    // result = compare_strings(algorithm, "rr");
    // printf("in robin hood\n");
    if (pick_your_alg == 2){
        proc_remain = counter;

        // // check if we turn swapping mode on or not
        // result = compare_strings(memoryTypeArray, "p"); 
        // counterCopy = counter - 1;
        // we keep track of the end of the processes (exactly not plus 1) in order to add another one in the queue -> counterCopy
        counterCopy = 0;
        // copy the first process and the data
        processArray2[0] = processArray[0];
        sizeArray2[0]=sizeArray[0];
        runningTimeArray2[0]=runningTimeArray[0];
        timeArray2[0] = timeArray[0];

        // print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, counter);
        // print_arrays(timeArray,processArray,sizeArray,runningTimeArray, counter);
        while (condition == 0) {

            //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, counter);
            // print_arrays(timeArray,processArray,sizeArray,runningTimeArray, counter);
            // printf("counter2 = %d\n", counter2);
            new_process = check_if_new_process(processArray,counter, processArray2[counter2], timeArray,sizeArray, runningTimeArray);

            // printf("376// new process = %d\n", new_process);
            // print_arrays(timeArray,processArray,sizeArray,runningTimeArray, 4);
            // print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 17);


            // if (counter2 < counter) {
            //     // start = timeArray[counter2];
            //     // time_robin = 0;
            //     printf("%d, RUNNING, id=%d, remaining--time=%d\n", time_robin, processArray2[counter2], runningTimeArray2[counter2]);
            // }

            // remainingTime = runningTimeArray2[counter2] - quantum;
            // if (counter2 >= counter){
            //     printf("%d, RUNNING, id=%d, remaining-time=%d\n", time_robin, processArray2[counter2], remainingTime);
            // }

            // if swapping mode off then do it as normal
            if (pick_your_mem == 1){
                // check if it's a new process or not, if it is put running in full time
                if (new_process == 1){
                    remainingTime = runningTimeArray2[counter2];
                    printf("%d, RUNNING, id=%d, remaining-time=%d\n", time_robin, processArray2[counter2], remainingTime);
                    remainingTimeSaved = remainingTime;
                    // if (remainingTime < quantum){
                    //     remainingTime = runningTimeArray2[counter2] - remainingTimeSaved;
                    // } else {
                    //     remainingTime = runningTimeArray2[counter2] - quantum;
                    // }
                    remainingTime = runningTimeArray2[counter2] - quantum;


                }
                // if its not put runningtime - quantum
                if (new_process == 0){
                    remainingTimeSaved = remainingTime;
                    remainingTime = runningTimeArray2[counter2] - quantum;
                    printf("%d, RUNNING, id=%d, remaining-time=%d\n", time_robin, processArray2[counter2], runningTimeArray2[counter2]);
                }
            }
            // if swapping mode on then we gotta print differnent running
            if (pick_your_mem == 2) {
                pages_required = sizeArray2[counter2]/PAGES;
                // printf("761 pages pages_required = %d\n", pages_required);

                //print_the_memory(memoryArray, memory_pages_on_disk);

                temp_val3 = processArray2[counter2];
                // printf("line 765 process = %d\n", temp_val3);

                // check if we have already placed the pages in memory so we dont do it again
                placed_pages_status = check_if_we_placed_the_pages(memoryArray, memory_pages_on_disk, pages_required, temp_val3);
                if (placed_pages_status == 0){

                    // fix the load time
                    load_time = TWO*pages_required;

                    current_pages = pages_required;
                    current_pages2 = current_pages;
                    current_pages =  fill_up_empty_spaces(memoryArray, memory_pages_on_disk, temp_val3, current_pages2);
                    // printf("memory after filling it up: \n");
                    // print_the_memory(memoryArray, memory_pages_on_disk);


                    if (current_pages > 0){
                        temp_val2 = processes_to_evict_counter;
                        processes_to_evict_counter = create_space_evict(memoryArray, memory_pages_on_disk, processes_to_evict, processes_to_evict_total, pages_required, temp_val2, current_pages, processes_evicted, &processes_evicted_counter);

                        current_pages2 = current_pages;
                        current_pages = fill_up_empty_spaces(memoryArray, memory_pages_on_disk, temp_val3, current_pages);
                    }

                    check_eviction_status = check_if_array_is_empty(processes_evicted, memory_pages_on_disk);

                    if (check_eviction_status == 0) {
                        printf("%d, EVICTED, mem-addresses=[", time_robin);
                        print_the_array(processes_evicted, processes_evicted_counter);
                        printf("]\n");
                        initialize_the_ints(processes_evicted, processes_evicted_counter);
                        processes_evicted_counter = 0;
                    }

                    processes_to_evict[processes_to_evict_total] = processArray2[counter2];
                    processes_to_evict_total += 1;

                    //print_the_memory(memoryArray, memory_pages_on_disk);
                }


                // load time is 0 the second time we run the process
                if (placed_pages_status == 1){
                    load_time = 0;
                }
                // load_time = TWO*pages_required;
                // mem_usage = (pages_required*HUNDRED)/memory_pages_on_disk;
                mem_usage = count_how_many_not_minus1(memoryArray, memory_pages_on_disk);
                mem_usage = (mem_usage*HUNDRED)/memory_pages_on_disk;
                // check if it's a new process or not, if it is put running in full time
                if (new_process == 1){
                    remainingTime = runningTimeArray2[counter2];
                    remainingTimeSaved = remainingTime;
                    printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", time_robin, processArray2[counter2], remainingTime, load_time, mem_usage);
                    remainingTime = runningTimeArray2[counter2] - quantum;
                    printing_pages2(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                    time_robin += load_time;
                    // printf("842 time robin = %d\n", time_robin);
                }
                // if its not put runningtime - quantum
                if (new_process == 0){
                    remainingTimeSaved = remainingTime;
                    remainingTime = runningTimeArray2[counter2] - quantum;
                    printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", time_robin, processArray2[counter2], runningTimeArray2[counter2], load_time, mem_usage);
                    printing_pages2(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                    
                    // if(remainingTime < quantum){
                    //     time_robin += remainingTime;
                    // } else { 
                    //     time_robin += load_time;
                    // }
                    time_robin += load_time;
                    // printf("851 time robin = %d\n", time_robin);
                }
                // printf("memory below:\n");
                // print_the_memory(memoryArray, memory_pages_on_disk);
            }

            if (pick_your_mem == 3) {

                // printf("time process memory running time || counter2 = || %d %d %d %d || %d\n", timeArray2[counter2], processArray2[counter2], sizeArray2[counter2], runningTimeArray2[counter2], counter2);

                // printf("1274 || sum_pages = %d\n", sum_pages);

                pages_required = sizeArray2[counter2]/PAGES;
                // printf("761 pages pages_required = %d\n", pages_required);

                // print_the_memory(memoryArray, memory_pages_on_disk);

                temp_val3 = processArray2[counter2];
                // printf("line 1282 process = %d\n", temp_val3);

                // check if we have already placed the pages in memory so we dont do it again
                placed_pages_status = check_if_we_placed_the_pages(memoryArray, memory_pages_on_disk, pages_required, temp_val3);
                if (placed_pages_status == 0){

                    // load_time = TWO*pages_required;

                    // fill up the pages first
                    current_pages = pages_required;
                    current_pages2 = count_how_many_of_an_element(memoryArray, memory_pages_on_disk, temp_val3);
                    //printf("1267|| memory array found this many of our process|| current_pages2 == %d\n", current_pages2);
                    current_pages = current_pages - current_pages2;
                    current_pages2 = current_pages;
                    //printf("1270|| current_pages = %d, current_pages2(inside fill up pages2) = %d\n", current_pages, current_pages2);

                    current_pages =  fill_up_empty_spaces2(memoryArray, memory_pages_on_disk, temp_val3, current_pages2, &sum_pages);
                    // printf("line 1299 below memory after filled up spaces, current pages = %d\n", current_pages);

                    load_time = TWO * sum_pages;
                    // printf("line 1302|| load time = %d\n", load_time);
                    // printf("1301 || sum_pages = %d\n", sum_pages);

                    // print_the_memory(memoryArray, memory_pages_on_disk);

                    // calculate how many pages we filled so we know for VR
                    current_pages_filled = pages_required - current_pages;

                    if (current_pages_filled >=FOUR_PAGES){
                        // load_time = TWO * current_pages_filled;
                        //printf("line 1284|| load time = %d\n", load_time);
                    }

                    //printf("1279|| current_pages_filled = %d\n", current_pages_filled);
                    // print_the_memory(memoryArray, memory_pages_on_disk);

                    // if we filled up all the available spaces but we still need to allocate pages (cause not 4 yet) then evict - VR
                    if (current_pages_filled < FOUR_PAGES){
                        if (pages_required >= FOUR_PAGES){
                            temp_val2 = processes_to_evict_counter;
                            current_pages_filled = 0;
                            processes_to_evict_counter = create_space_evict_vr(memoryArray,memory_pages_on_disk, processes_to_evict, processes_to_evict_total, pages_required,temp_val2, current_pages, processes_evicted, &processes_evicted_counter, processArray2[counter2], &current_pages_filled, &real_current_pages_filled);
                            // page_fault_number = pages_required - current_pages_filled;
                        }
                    }

                    // printf("line 1186 below memory after eviction\n");
                    // print_the_memory(memoryArray, memory_pages_on_disk);

                    check_eviction_status = check_if_array_is_empty(processes_evicted, real_current_pages_filled);

                    // printf("before sorting the processes_evicted, memory_pages_on_disk = %d\n", memory_pages_on_disk);

                    // print_the_array(processes_evicted, real_current_pages_filled);

                    // printf("\n");

                    sort_the_array_before_minus1(processes_evicted, real_current_pages_filled);

                    // printf("processes_evicted array below:\n");

                    // print_the_array(processes_evicted, real_current_pages_filled);

                    // printf("\n");

                    // printf("check_eviction_status = %d\n", check_eviction_status);

                    if (check_eviction_status == 0) {
                        printf("%d, EVICTED, mem-addresses=[", time_robin);
                        print_the_array(processes_evicted, processes_evicted_counter);
                        printf("]\n");

                        temp_current_pages_filled = count_how_many_not_minus1(processes_evicted, processes_evicted_counter);
                        load_time += TWO *  temp_current_pages_filled;
                        //printf("temp_current_pages_filled = %d\n", temp_current_pages_filled);

                        initialize_the_ints(processes_evicted, processes_evicted_counter);
                        processes_evicted_counter = 0;
                    }

                    processes_to_evict[processes_to_evict_total] = processArray2[counter2];
                    processes_to_evict_total += 1;

                    temp_current_pages_filled = count_how_many_not_minus1(processes_evicted, real_current_pages_filled);

                    // load_time = TWO * current_pages_filled;
                    // load_time = TWO *  temp_current_pages_filled;

                    actual_current_pages_filled = count_how_many_of_an_element(memoryArray, memory_pages_on_disk, processArray2[counter2]);

                    page_fault_number = pages_required - actual_current_pages_filled;
                    // printf("page_fault_number = %d\n", page_fault_number);
                    // printf("pages required = %d\n", pages_required);
                    // printf("current_pages_filled = %d\n", current_pages_filled);
                    // print_the_memory(memoryArray, memory_pages_on_disk);
                    // printf(" processes to evict array below: \n");
                    // print_the_array(processes_to_evict, 15);
                    // printf("\n");

                }

                // load time is 0 the second time we run the process
                if (placed_pages_status == 1){
                    load_time = 0;
                }

                // load_time = TWO*pages_required;
                // mem_usage = (pages_required*HUNDRED)/memory_pages_on_disk;
                mem_usage = count_how_many_not_minus1(memoryArray, memory_pages_on_disk);
                mem_usage = (mem_usage*HUNDRED)/memory_pages_on_disk;
                
                // check if it's a new process or not, if it is put running in full time
                if (new_process == 1){
                    remainingTime = runningTimeArray2[counter2] + page_fault_number;
                    remainingTimeSaved = remainingTime;
                    printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", time_robin, processArray2[counter2], remainingTime, load_time, mem_usage);
                    remainingTime = runningTimeArray2[counter2] - quantum + page_fault_number;
                    printing_pages2(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                    time_robin += load_time;
                    // printf("842 time robin = %d\n", time_robin);
                    //printf("1296|| remaining time = %d\n", remainingTime);
                }

                // if its not put runningtime - quantum
                if (new_process == 0){
                    // remainingTimeSaved = remainingTime;
                    // remainingTime = runningTimeArray2[counter2] - quantum + page_fault_number;
                    // printf("runningTimeArray2[counter2] = %d\n", runningTimeArray2[counter2]);
                    // printf("page_fault_number = %d\n", page_fault_number);
                    // printf("remainingTime = %d\n", remainingTime);
                    temp_num2 = runningTimeArray2[counter2] + page_fault_number;
                    printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", time_robin, processArray2[counter2], temp_num2, load_time, mem_usage);
                    
                    printing_pages2(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                    remainingTimeSaved = temp_num2;
                    remainingTime = runningTimeArray2[counter2] - quantum + page_fault_number;
                    
                    //printf("1304|| remaining time = %d\n", remainingTime);
                    // printf("runningTimeArray2[counter2] = %d\n", runningTimeArray2[counter2]);
                    // printf("page_fault_number = %d\n", page_fault_number);
                    // printf("remainingTime = %d\n", remainingTime);
                    // printf("remainingTimeSaved = %d\n", remainingTimeSaved);


                    
                    // if(remainingTime < quantum){
                    //     time_robin += remainingTime;
                    // } else { 
                    //     time_robin += load_time;
                    // }
                    time_robin += load_time;

                    // printf("851 time robin = %d\n", time_robin);
                }
                load_time = 0;
                sum_pages = 0;
                // printf("memory below:\n");
                // print_the_memory(memoryArray, memory_pages_on_disk);

            }

            if (pick_your_mem == 4) {

                //printf("time process memory running time || counter2 = || %d %d %d %d || %d\n", timeArray2[counter2], processArray2[counter2], sizeArray2[counter2], runningTimeArray2[counter2], counter2);

                // printf("1274 || sum_pages = %d\n", sum_pages);

                pages_required = sizeArray2[counter2]/PAGES;
                // printf("761 pages pages_required = %d\n", pages_required);

                // print_the_memory(memoryArray, memory_pages_on_disk);

                temp_val3 = processArray2[counter2];
                // printf("line 1282 process = %d\n", temp_val3);

                // check if we have already placed the pages in memory so we dont do it again
                placed_pages_status = check_if_we_placed_the_pages(memoryArray, memory_pages_on_disk, pages_required, temp_val3);
                if (placed_pages_status == 0){

                    // load_time = TWO*pages_required;

                    // fill up the pages first
                    current_pages = pages_required;
                    current_pages2 = count_how_many_of_an_element(memoryArray, memory_pages_on_disk, temp_val3);
                    //printf("1267|| memory array found this many of our process|| current_pages2 == %d\n", current_pages2);
                    current_pages = current_pages - current_pages2;
                    current_pages2 = current_pages;
                    //printf("1270|| current_pages = %d, current_pages2(inside fill up pages2) = %d\n", current_pages, current_pages2);

                    current_pages =  fill_up_empty_spaces2(memoryArray, memory_pages_on_disk, temp_val3, current_pages2, &sum_pages);
                    //printf("line 1299 below memory after filled up spaces, current pages = %d\n", current_pages);

                    //print_the_memory(memoryArray, memory_pages_on_disk);

                    load_time = TWO * sum_pages;
                    // printf("line 1302|| load time = %d\n", load_time);
                    // printf("1301 || sum_pages = %d\n", sum_pages);

                    // print_the_memory(memoryArray, memory_pages_on_disk);

                    // calculate how many pages we filled so we know for VR
                    current_pages_filled = pages_required - current_pages;

                    if (current_pages_filled >=FOUR_PAGES){
                        // load_time = TWO * current_pages_filled;
                        //printf("line 1284|| load time = %d\n", load_time);
                    }

                    //printf("1279|| current_pages_filled = %d\n", current_pages_filled);
                    // printf("memory before vr function\n");
                    // print_the_memory(memoryArray, memory_pages_on_disk);
                    //printf("1649|| processes_evicted_counter  before create space evict vr=%d\n", processes_to_evict_counter);
                    // if we filled up all the available spaces but we still need to allocate pages (cause not 4 yet) then evict - VR
                    if (current_pages_filled < FOUR_PAGES){
                        if (pages_required >= FOUR_PAGES){
                            temp_val2 = processes_to_evict_counter;
                            //printf("1654|| processes_evicted_counter  before create space evict vr=%d\n", processes_to_evict_counter);
                            current_pages_filled = 0;
                            processes_to_evict_counter = create_space_evict_vr2(memoryArray,memory_pages_on_disk, processes_to_evict, &processes_to_evict_total, pages_required,temp_val2, current_pages, processes_evicted, &processes_evicted_counter, processArray2[counter2], &current_pages_filled, &real_current_pages_filled, &saved_eviction);
                            //printf("1657|| processes_evicted_counter  after create space evict vr=%d\n", processes_to_evict_counter);
                            //printf("went inside the 2 IFFS 1658\n");
                            // page_fault_number = pages_required - current_pages_filled;
                        }
                    }
                    //printf("1661|| processes_evicted_counter  after create space evict vr=%d\n", processes_to_evict_counter);
                    // printf("memory after vr function\n");
                    // print_the_memory(memoryArray, memory_pages_on_disk);

                    // printf("line 1186 below memory after eviction\n");
                    // print_the_memory(memoryArray, memory_pages_on_disk);

                    check_eviction_status = check_if_array_is_empty(processes_evicted, real_current_pages_filled);

                    // printf("before sorting the processes_evicted, memory_pages_on_disk = %d\n", memory_pages_on_disk);

                    // print_the_array(processes_evicted, real_current_pages_filled);

                    // printf("\n");

                    sort_the_array_before_minus1(processes_evicted, real_current_pages_filled);



                    // printf("processes_evicted array below:\n");

                    // print_the_array(processes_evicted, real_current_pages_filled);

                    // printf("\n");

                    // printf("check_eviction_status = %d\n", check_eviction_status);

                    if (check_eviction_status == 0) {
                        printf("%d, EVICTED, mem-addresses=[", time_robin);
                        print_the_array(processes_evicted, processes_evicted_counter);
                        printf("]\n");

                        temp_current_pages_filled = count_how_many_not_minus1(processes_evicted, processes_evicted_counter);
                        load_time += TWO *  temp_current_pages_filled;
                        //printf("temp_current_pages_filled = %d\n", temp_current_pages_filled);

                        initialize_the_ints(processes_evicted, processes_evicted_counter);
                        processes_evicted_counter = 0;
                    }
                    // printf("before addition of processes to evict: || processes_to_evict_total = %d\n", processes_to_evict_total);
                    // print_the_array(processes_to_evict, 30);
                    processes_to_evict[processes_to_evict_total] = processArray2[counter2];
                    //printf("1700|| processes_to_evict[total] = %d\n", processes_to_evict[processes_to_evict_total]);
                    processes_to_evict_total += 1;

                    // printf("after addition of processes to evict: || processes_to_evict_total = %d\n", processes_to_evict_total);
                    // print_the_array(processes_to_evict, 30);
                    // printf("\n");

                    temp_current_pages_filled = count_how_many_not_minus1(processes_evicted, real_current_pages_filled);

                    // load_time = TWO * current_pages_filled;
                    // load_time = TWO *  temp_current_pages_filled;

                    actual_current_pages_filled = count_how_many_of_an_element(memoryArray, memory_pages_on_disk, processArray2[counter2]);

                    page_fault_number = pages_required - actual_current_pages_filled;
                    // printf("page_fault_number = %d\n", page_fault_number);
                    // printf("pages required = %d\n", pages_required);
                    // printf("current_pages_filled = %d\n", current_pages_filled);
                    // print_the_memory(memoryArray, memory_pages_on_disk);
                    // printf(" processes to evict array below: \n");
                    // print_the_array(processes_to_evict, 15);
                    // printf("\n");

                }

                // load time is 0 the second time we run the process
                if (placed_pages_status == 1){
                    load_time = 0;
                }

                // load_time = TWO*pages_required;
                // mem_usage = (pages_required*HUNDRED)/memory_pages_on_disk;
                mem_usage = count_how_many_not_minus1(memoryArray, memory_pages_on_disk);
                mem_usage = (mem_usage*HUNDRED)/memory_pages_on_disk;
                
                // check if it's a new process or not, if it is put running in full time
                if (new_process == 1){
                    remainingTime = runningTimeArray2[counter2] + page_fault_number;
                    remainingTimeSaved = remainingTime;
                    printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", time_robin, processArray2[counter2], remainingTime, load_time, mem_usage);
                    remainingTime = runningTimeArray2[counter2] - quantum + page_fault_number;
                    printing_pages2(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                    time_robin += load_time;
                    // printf("842 time robin = %d\n", time_robin);
                    //printf("1296|| remaining time = %d\n", remainingTime);
                }


                // if its not put runningtime - quantum
                if (new_process == 0){
                    // remainingTimeSaved = remainingTime;
                    // remainingTime = runningTimeArray2[counter2] - quantum + page_fault_number;
                    // printf("runningTimeArray2[counter2] = %d\n", runningTimeArray2[counter2]);
                    // printf("page_fault_number = %d\n", page_fault_number);
                    // printf("remainingTime = %d\n", remainingTime);
                    temp_num2 = runningTimeArray2[counter2] + page_fault_number;
                    printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", time_robin, processArray2[counter2], temp_num2, load_time, mem_usage);
                    
                    printing_pages2(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                    remainingTimeSaved = temp_num2;
                    remainingTime = runningTimeArray2[counter2] - quantum + page_fault_number;
                    
                    //printf("1304|| remaining time = %d\n", remainingTime);
                    // printf("runningTimeArray2[counter2] = %d\n", runningTimeArray2[counter2]);
                    // printf("page_fault_number = %d\n", page_fault_number);
                    // printf("remainingTime = %d\n", remainingTime);
                    // printf("remainingTimeSaved = %d\n", remainingTimeSaved);


                    
                    // if(remainingTime < quantum){
                    //     time_robin += remainingTime;
                    // } else { 
                    //     time_robin += load_time;
                    // }
                    time_robin += load_time;

                    // printf("851 time robin = %d\n", time_robin);
                }

                load_time = 0;
                sum_pages = 0;
                // printf("memory below:\n");
                // print_the_memory(memoryArray, memory_pages_on_disk);

            }


            // printf("403 counterCopy = %d\n", counterCopy);
            // Step1: check if other processes arrived and add them at the end of the new array
            //printf("869|| time_robin = %d, remainingTime= %d, remainingTimeSaved = %d no additions: \n", time_robin, remainingTime, remainingTimeSaved);
            //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 30);
            
            counterCopy2 = counterCopy;
            counterCopy = check_if_a_process_arrived(timeArray,processArray,sizeArray,runningTimeArray,timeArray2,processArray2,sizeArray2,runningTimeArray2, counter, counter2, counterCopy2, time_robin, &num_of_proc_added, remainingTimeSaved, quantum);
            //printf("line 871 possibly added\n");
            //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 30);
            // printf("405 counterCopy = %d\n", counterCopy);
            // // performance statistics
            // current_proc = processArray[counter2];

            
            // printf("line 169|| %d %d %d %d\n", timeArray[counter2],processArray[counter2],sizeArray[counter2],runningTimeArray[counter2]);
            //printf("remainingTime = %d, counter2 = %d, counterCopy = %d, time_robin = %d\n\n\n", remainingTime, counter2, counterCopy, time_robin);

            // Step2: check if the remaining time is 0 or not and accordingly add to the end of the queue to re run
            // if there is still remaining time add it to the end of the queue to run again
            if (remainingTime > 0) {
                processArray2[counterCopy+1] = processArray2[counter2];
                runningTimeArray2[counterCopy+1] = remainingTime;
                timeArray2[counterCopy+1] = timeArray2[counter2];
                sizeArray2[counterCopy+1] = sizeArray2[counter2];
                counterCopy += 1;
                // finish = finish + runningTimeArray[counter2];
                //printf("time_robin = %d, remainingTime = %d, remainingTimeSaved = %d\n", time_robin, remainingTime,remainingTimeSaved);
                // if (remainingTimeSaved < quantum){
                //     time_robin += remainingTime;
                // } else{
                //     time_robin += quantum;
                // }
               // printf("906 time robin = %d, quantum = %d\n", time_robin, quantum);
                time_robin += quantum;
                //printf("906 time robin = %d\n", time_robin);
                //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 25);
                // printf("423 time robin = %d\n", time_robin);
                // print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 17);

                // this one was on
                //printf("interrupted: %d, process = %d, remaining time = %d\n", time_robin, processArray[counter2], remainingTime);
                

                // printf("saved at location = %d\n", counterCopy);
                // printf("%d %d %d %d\n", timeArray[counterCopy],processArray[counterCopy],sizeArray[counterCopy],runningTimeArray[counterCopy]);
                //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, counter2+1);
            }
            if (remainingTime <= 0) {
                // finish = finish + runningTimeArray[counter2];
                if (remainingTime < 0){
                    time_robin += remainingTimeSaved;
                } else {
                    time_robin += quantum;
                }
                // time_robin += quantum;
                //printf("remainingTimeSaved = %d\n", remainingTimeSaved);
               // printf("901 time robin = %d\n", time_robin);

                // printf("******** memory before final eviction\n");
                // print_the_memory(memoryArray, memory_pages_on_disk);
                
                if ((pick_your_mem == 2)||(pick_your_mem == 3)||(pick_your_mem == 4)) {
                    // EVICTED printf
                    printf("%d, EVICTED, mem-addresses=[", time_robin);
                    printing_pages2(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                    // erase them from memory - replace with -1
                    find_and_replace_with_minusOne_Void(memoryArray, memory_pages_on_disk, processArray2[counter2]);

                    // proc_remain = check_if_a_process_arrived_for_ff(timeArray2, counter2, time_robin);
                }

                // printf("******** memory before final eviction\n");
                // print_the_memory(memoryArray, memory_pages_on_disk);

                proc_remain = count_how_many_not_minus1_after_element(processArray2, counterCopy+1, counter2);

                proc_remain -= 1;

                //printf("915 = time robin = %d and arrays below\n", time_robin);
                //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 30);
                printf("%d, FINISHED, id=%d, proc-remaining=%d\n", time_robin, processArray2[counter2], proc_remain);

                // printf("memory below: after finish \n");
                //print_the_memory(memoryArray, memory_pages_on_disk);


                twoSteps = ((time_robin - timeArray2[counter2])*1.0);
                turnAroundTime += twoSteps;
                // printf("twoSteps = %f\n", twoSteps);
                // // printf("360 timeArray: %d\n", timeArray[turnAroundCounter]);
                // // turnAroundCounter+=1;
                // printf("time_robin %d\n", time_robin);
                // printf("timeArray2[counter2] = %d\n", timeArray2[counter2]);
                // // printf("turnAroundCounter: %d\n", turnAroundCounter);
                // printf("turnaroundTime: %f\n\n", turnAroundTime);
                // // printf("time_robin %d\n", time_robin);



                // performance statistics throughput
                remainder = (time_robin-1)/60;
                // remainder = remainder - 1;
                // printf("remainder = %d, time_robin = %d\n", remainder, time_robin);
                countProcesses[remainder] = countProcesses[remainder] + 1;
                if (remainder > remainder_max) {
                    remainder_max = remainder;
                }
                remainder = 0;



                // time overhead
                int temp_k = 0;
                for (k=0;k<counter;k++){
                    // printf("processArray2[counter2] = %d\n\n", processArray2[counter2]);
                    // printf("processArray3[k] = %d\n", processArray3[k]);
                    if (processArray2[counter2] == processArray3[k]){
                        temp_k = k;
                    }
                }
                // printf("temp_k = %d\n", temp_k);
                timeOverhead = (((time_robin - timeArray3[temp_k])*1.0) / runningTimeArray3[temp_k]);
                // printf("time overhead = %f\n", timeOverhead);
                // printf(" arithmitis = %f\n", ((time_robin - timeArray2[counter2])*1.0));
                if (timeOverhead > timeOverheadMax){
                    timeOverheadMax = timeOverhead;
                }
                timeOverheadSum += timeOverhead;










                // check if there is no next element in the 2nd array queque
                empty_second_array_next = check_if_secondArray_empty_next(timeArray2,processArray2,sizeArray2,runningTimeArray2, counter2);

                // printf("922 empty_second_array_next = %d\n", empty_second_array_next);
                // printf("923 timeArray2[counter2+1] = %d\n", timeArray2[counter2+1]);

                //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 30);

                // if it's empty then check if we have more processes on the list and DONT finish -> add to queue
                if (empty_second_array_next == 1){

                    // printf("line 801\n");
                    // check and add

                    // printf("933 time robin = %d\n", time_robin);
                    empty_second_array_next = check_if_we_have_more_processes_in_list(timeArray2,processArray2,sizeArray2,runningTimeArray2, counter2, &time_robin, counter, &counterCopy, timeArray,processArray,sizeArray,runningTimeArray);

                    // printf("936 empty_second_array_next = %d\n", empty_second_array_next);

                    // printf("938 time robin = %d\n", time_robin);

                    // printf("940 array below\n");

                   // print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 25);
                    // if (empty_second_array_next == 1){
                    //     // fix time and add next
                    // }
                }   



                
                // // performance statistics throughput
                // remainder = (time_robin-1)/60;
                // // remainder = remainder - 1;
                // // printf("remainder = %d, time_robin = %d\n", remainder, time_robin);
                // countProcesses[remainder] = countProcesses[remainder] + 1;
                // if (remainder > remainder_max) {
                //     remainder_max = remainder;
                // }
                // remainder = 0;



                // printf("time_robin %d\n", time_robin);
                // performance statistics Turnaround time 
                // for (k=0;k<counter;k++){
                //     // printf("processArray[counter2] = %d\n",  processArray[counter2]);
                //     // printf("processArray[k] = %d\n",  processArray[k]);
                //     // printf("k = %d\n", k);
                //     if (processArray[counter2] == processArray[k]){
                //         turnAroundCounter = k;
                //     }
                // }

                // printf("turnAroundCounter = %d\n", turnAroundCounter);

                // twoSteps = ((time_robin - timeArray2[counter2])*1.0);
                // turnAroundTime += twoSteps;
                // printf("twoSteps = %f\n", twoSteps);
                // // printf("360 timeArray: %d\n", timeArray[turnAroundCounter]);
                // // turnAroundCounter+=1;
                // printf("time_robin %d\n", time_robin);
                // printf("timeArray2[counter2] = %d\n", timeArray2[counter2]);
                // // printf("turnAroundCounter: %d\n", turnAroundCounter);
                // printf("turnaroundTime: %f\n\n", turnAroundTime);
                // // printf("time_robin %d\n", time_robin);



                // // time overhead
                // int temp_k = 0;
                // for (k=0;k<counter;k++){
                //     // printf("processArray2[counter2] = %d\n\n", processArray2[counter2]);
                //     // printf("processArray3[k] = %d\n", processArray3[k]);
                //     if (processArray2[counter2] == processArray3[k]){
                //         temp_k = k;
                //     }
                // }
                // // printf("temp_k = %d\n", temp_k);
                // timeOverhead = (((time_robin - timeArray3[temp_k])*1.0) / runningTimeArray3[temp_k]);
                // // printf("time overhead = %f\n", timeOverhead);
                // // printf(" arithmitis = %f\n", ((time_robin - timeArray2[counter2])*1.0));
                // if (timeOverhead > timeOverheadMax){
                //     timeOverheadMax = timeOverhead;
                // }
                // timeOverheadSum += timeOverhead;



            }
            // changing to the next - in the while loop
            counter2 += 1;
            //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 35);
            // check  if the processes array is done


            if (processArray2[counter2] == -1){
                condition = 1;
            }

        }

        // performance statistics for the overhead
        timeOverheadSum = (timeOverheadSum / counter);
        // performance statistics for turnaround time
        turnAroundTime = ceil((turnAroundTime/counter)*1.0);
        int turnAroundTime2 = (int)turnAroundTime;

        // for(i=0;i<remainder_max+1;i++){
        //     printf("this is the countProcesses array: %d\n", countProcesses[i]);
        // }
        // printf("this is the remainder_max = %d\n", remainder_max);
        remainder_max += 1;
        min_proc = find_min_num(countProcesses, remainder_max);
        // printf("min is: %d\n", min_proc);
        max_proc = find_max_num(countProcesses, remainder_max);
        // printf("max is: %d\n", max_proc);

        aver_proc = ((counter*1.0) / remainder_max);
        aver_proc2 = round_up_float(aver_proc);
        aver_proc2_int = (int)(aver_proc2);

        printf("Throughput %d, %d, %d\n", aver_proc2_int, min_proc, max_proc);
        printf("Turnaround time %d\n", turnAroundTime2);
        printf("Time overhead %.2f %.2f\n", timeOverheadMax,timeOverheadSum);
        makespan = time_robin;
        printf("Makespan %d\n", makespan);
        fclose(file1);
        return 0;
    }

    // cs algorithm
    if (pick_your_alg == 3){
        condition = 0;
        counter2 = 0;
        counterCopy = 0;
        time_robin = 0;
        start = 0;
        finish = 0;
        i = 0;
        counterCopy = 0;
        saved_finish = 0;
        proc_remain = 0;

        processArray2[0] = processArray[0];
        sizeArray2[0]=sizeArray[0];
        runningTimeArray2[0]=runningTimeArray[0];
        timeArray2[0] = timeArray[0];
        counterCopy += 1;

        // initialize the 3rsd array
        memset(timeArray3 ,-1, sizeof(timeArray3));
        memset(processArray3 ,-1, sizeof(processArray3));
        memset(sizeArray3 ,-1, sizeof(sizeArray3));
        memset(runningTimeArray3 ,-1, sizeof(runningTimeArray3));

        while(condition == 0){

            // printf("time process memory running time || counter2 = || %d %d %d %d || %d\n", timeArray2[counter2], processArray2[counter2], sizeArray2[counter2], runningTimeArray2[counter2], counter2);

            // printf("initial array2 arrays: \n");
            // print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 15);

            // printf("array3\n");
            // print_arrays(timeArray3,processArray3,sizeArray3,runningTimeArray3, 10);


            if (counter2 == 0){
                start = timeArray2[counter2];
            } else {
                start = saved_finish;

                // adjust timer for timejumps
                if (start < timeArray2[counter2]){
                    start = timeArray2[counter2];
                }
            }
            finish = start + runningTimeArray2[counter2];



            if (pick_your_mem == 1){

                // printf("result = 0\n\n\n\n\n");
                printf("%d, RUNNING, id=%d, remaining-time=%d\n", start, processArray2[counter2], runningTimeArray2[counter2]);

                // check for virtual memory and proceed with that option if necessaary
            }

            if (pick_your_mem == 3){
                pages_required = sizeArray2[counter2] / PAGES;
                temp_val3 = processArray2[counter2];

                current_pages = pages_required;
                current_pages2 = current_pages;

                // printf("the memory before fill up is this: \n");
                // print_the_memory(memoryArray, memory_pages_on_disk);
                current_pages = fill_up_empty_spaces(memoryArray, memory_pages_on_disk, temp_val3, current_pages2);
                // printf("the memory after fill up is this: \n");
                // print_the_memory(memoryArray, memory_pages_on_disk);

                current_pages_filled = pages_required - current_pages;

                page_fault_number = pages_required - current_pages_filled;

                load_time = TWO * pages_required;
                load_time += page_fault_number;
                finish += load_time;

                mem_usage = count_how_many_not_minus1(memoryArray, memory_pages_on_disk);
                // mem_usage = (mem_usage*HUNDRED)/memory_pages_on_disk;

                mem_usage_float = (mem_usage*HUNDRED*1.0)/memory_pages_on_disk;

                mem_usage_float2 = round_up_float(mem_usage_float);

                mem_usage = (int)(mem_usage_float2);

                // aver_proc = ((counter*1.0) / remainder_max);
                // aver_proc2 = round_up_float(aver_proc);
                // aver_proc2_int = (int)(aver_proc2);

                printf("%d, RUNNING, id=%d, remaining-time=%d, load-time=%d, mem-usage=%d%%, mem-addresses=[", start, processArray2[counter2], runningTimeArray2[counter2], load_time, mem_usage);
                printing_pages2(memoryArray, pages_required, processArray2[counter2]);
            }

            saved_finish = finish;
            proc_remain = check_if_a_process_arrived_for_ff(timeArray, counter, finish);
            //check what arrived and add to 3rd array
            finished_proc += 1;
            proc_remain -= finished_proc;

            // printf("the memory before final eviction up is this: \n");
            // print_the_memory(memoryArray, memory_pages_on_disk);

            if (pick_your_mem == 3){
                // EVICTED printf
                printf("%d, EVICTED, mem-addresses=[", finish);
                printing_pages2(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                // erase them from memory - replace with -1
                find_and_replace_with_minusOne_Void(memoryArray, memory_pages_on_disk, processArray2[counter2]);
                // printf("754|| lets see if it's erased below\n");
                // print_the_array(memoryArray, memory_pages_on_disk);
                // printf("756|| lets see if it's erased above\n");
            }
            printf("%d, FINISHED, id=%d, proc-remaining=%d\n", finish, processArray2[counter2], proc_remain);

            // printf("the memory after final eviction up is this: \n");
            // print_the_memory(memoryArray, memory_pages_on_disk);

            // performance statistics for each round
            turnAroundTime += ((finish - timeArray2[counter2])*1.0);
            timeOverhead = (((finish - timeArray2[counter2])*1.0) / runningTimeArray2[counter2]);
            //printf("time overhead for this round = %f\n\n", timeOverhead);
            if (timeOverhead > timeOverheadMax){
                timeOverheadMax = timeOverhead;
            }
            timeOverheadSum += timeOverhead;

            remainder = (finish-1)/60;
            // remainder = remainder - 1;
            // printf("remainder = %d, finish = %d\n", remainder, finish);
            // printf("countProcesses[remainder] = %d\n", countProcesses[remainder]);
            countProcesses[remainder] += 1;
            if (remainder > remainder_max) {
                remainder_max = remainder;
            }
            remainder = 0;


            // --------------------------after it finished make additions-----------------------------------
            // printf("before the check function for additions\n");
            // print_arrays(timeArray3,processArray3,sizeArray3,runningTimeArray3, 10);

            total_count3 = check_what_process_has_arrived_and_add_to_thirdArray(processArray3,sizeArray3,runningTimeArray3,timeArray3,processArray,sizeArray,runningTimeArray,timeArray,counter,counter3, finish, counterCopy, timeArray2);

            // printf("total_count3 = %d and array3 after check function - for additions\n", total_count3);
            // print_arrays(timeArray3,processArray3,sizeArray3,runningTimeArray3, 10);

            // if we found something then add it
            if (total_count3 !=0){
                // printf("after arrival arrays3: \n");
                // print_arrays(timeArray3,processArray3,sizeArray3,runningTimeArray3, 10);
                // sort according to runningTime - shortest job
                bubbleSort(processArray3,sizeArray3,runningTimeArray3,timeArray3, total_count3);

                //printf("after bubblesort arrays3: \n");
                //print_arrays(timeArray3,processArray3,sizeArray3,runningTimeArray3, 10);

                // add at the end of the queue
                for (i = 0; i<total_count3; i++){
                    processArray2[counterCopy] = processArray3[i];
                    sizeArray2[counterCopy] = sizeArray3[i];
                    runningTimeArray2[counterCopy] = runningTimeArray3[i];
                    timeArray2[counterCopy] = timeArray3[i];
                    counterCopy += 1;
                }

                // printf("1815 || with the additions array2: \n");
                // print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 10);

                //printf("processArray2[counter2] = %d\n\n", processArray2[counter2]);

                initialize_the_ints(timeArray3, 30);
                initialize_the_ints(sizeArray3, 30);
                initialize_the_ints(processArray3, 30);
                initialize_the_ints(runningTimeArray3, 30);
            }

            //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 10);
            counter2 += 1;
            // if (counter2 == 3){
            //     break;
            // }

            // finished? bye bye
            if (processArray2[counter2] == -1){
                condition = 1;
            }
        }

        makespan = finish;
        // min_proc = find_min_num(countProcesses, intervalsCounter);
        // // printf("min is: %d\n", min_proc);
        // max_proc = find_max_num(countProcesses, intervalsCounter);
        // aver_proc = counter / intervalsCounter;
        // float yes = 0.0;
        // yes = ceil((turnAroundTime*1.0)/counter);
        // printf("this is yes: %f\n", yes);
        timeOverheadSum = (timeOverheadSum / counter);

        turnAroundTime = ceil((turnAroundTime/counter)*1.0);
        int turnAroundTime2 = (int)turnAroundTime;

        // for(i=0;i<remainder_max+1;i++){
        //     // printf("this is the countProcesses array: %d\n", countProcesses[i]);
        // }
        // printf("this is the remainder_max = %d\n", remainder_max);
        remainder_max += 1;
        min_proc = find_min_num(countProcesses, remainder_max);
        // printf("min is: %d\n", min_proc);
        max_proc = find_max_num(countProcesses, remainder_max);
        // printf("max is: %d\n", max_proc);
        aver_proc = ((counter2*1.0) / remainder_max);
        aver_proc2 = round_up_float(aver_proc);
        aver_proc2_int = (int)(aver_proc2);

        printf("Throughput %d, %d, %d\n", aver_proc2_int, min_proc, max_proc);
        // printf("Turnaround time %d\n", turnAroundTime2);
        // printf("Throughput %d, %d, %d\n", aver_proc, min_proc, max_proc);
        // printf("Throughput %d, %d, %d\n", aver_proc, min_proc, max_proc);
        printf("Turnaround time %d\n", turnAroundTime2);
        printf("Time overhead %.2f %.2f\n", timeOverheadMax,timeOverheadSum);
        printf("Makespan %d\n", makespan);
        //print_arrays(timeArray,processArray,sizeArray,runningTimeArray, counter);
        fclose(file1);
        return 0;


        fclose(file1);
        return 0;
    }

    //print_arrays(timeArray2,processArray2,sizeArray2,runningTimeArray2, 35);
    fclose(file1);
    return 0;
}


/*        Programming is Fun  =)        */
/*        ---------P.G.---------        */
/*        Have a nice day!!   =)        */     
