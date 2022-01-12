#include <iostream>
#include <plog/Appenders/ColorConsoleAppender.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Init.h>
#include <plog/Log.h>

int binarySearch(int arr[], int n, int key) {
    int s = 0;
    int e = n;
    while (s <= e) {
        int mid = (s + e) / 2;
        PLOG_DEBUG << "Mid: " << mid;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int binarySearchRun(int n) {
    srand(time(NULL));
    // PLOG_DEBUG << "Size: " << n;
    int arr[n];
    arr[0] = rand() % n;
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + rand() % n;
    }
    int key = arr[rand() % n];
    // PLOG_DEBUG << "Key: " << key;
    return binarySearch(arr, n, key);
}