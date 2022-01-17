#include "bts.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("bts", "[bts]") {

    SECTION("found") {
        srand(time(NULL));
        int n = 1000;
        int arr[n];
        arr[0] = rand() % 10;
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + rand() % 10;
        }
        int key = arr[rand() % n];
        REQUIRE(binarySearch(arr, n, key) != -1);
    }

    SECTION("not found") {
        srand(123456);
        int n = 1000;
        int arr[n];
        arr[0] = rand() % 10;
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + rand() % 10;
        }
        int key = rand() % (n * n);
        REQUIRE(binarySearch(arr, n, key) == -1);
    }

    SECTION("found-heap") {
        srand(time(NULL));
        int n = 100000;
        int* arr = new int[n];
        arr[0] = rand() % 10;
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + rand() % 10;
        }
        int key = arr[rand() % n];
        REQUIRE(binarySearch(arr, n, key) != -1);
        delete [] arr;
    }

}
