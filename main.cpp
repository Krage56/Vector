#include "vector2.h"

int main()
{
    //SECTION("getSize, clear, getCapacity > getSize, append") {
        Vector *v = createVector();
        clear(v);
        if(getSize(v) == 0){
            cout << "1!" << endl;
        }
        if(getCapacity(v) >= getSize(v)){
            cout << "2!" << endl;
        }

        for(int i = 0; i < 100; i++) append(v, i);
        if(getSize(v) == 100){
            cout << "3!" << endl;
        }
        if(getCapacity(v) >= getSize(v)){
            cout << "4!" << endl;
        }
        for(int i = 0; i < 100; i++) if(getValue(v, i) == i);
        deleteVector(v);
    //}

    //SECTION("reserve"){
        v = createVector();
        clear(v);
        squeeze(v);

        reserve(v, 10);
        append(v, 10);
        if(getValue(v, 0) == 10){
            cout << "5!" << endl;
        }

        reserve(v, 100);
        if(getValue(v, 0) == 10){
            cout << "6!" << endl;
        }
        deleteVector(v);
//    }

    //SECTION("print") {
      //  nitori::hijack_stdout();

        v = createVector();
        clear(v);
        append(v, 10);

        deleteVector(v);
        //SECTION("getSize, clear, getCapacity > getSize, append") {
            v = createVector();
            clear(v);
            if(getSize(v) == 0){
                cout << "7!" << endl;
            }
            if(getCapacity(v) >= getSize(v)){
                cout << "8!" << endl;
            }

            for(int i = 1; i < 101; i++) append(v, i);
            if(getSize(v) == 100){
                cout << "9!" << endl;
            }
            if(getCapacity(v) >= getSize(v)){
                cout << "10!" << endl;
            }
            for(int i = 0; i < 100; i++){
                if(getValue(v, i) == i){
                    cout << "11!" << endl;
                }
            }
            print(v);
            deleteVector(v);
        //}

       // SECTION("reserve"){
            v = createVector();
            clear(v);
            squeeze(v);

            reserve(v, 10);
            append(v, 10);
            if(getValue(v, 0) == 10){
                cout << "12!" << endl;
            }

            reserve(v, 100);
            if(getValue(v, 0) == 10){
                cout << "13!" << endl;
            }
            deleteVector(v);
        //}

        //SECTION("squeeze") {
            v = createVector();
            clear(v);
            reserve(v, 100);
            squeeze(v);

            if(getCapacity(v) == 0){
                cout << "14!" << endl;
            }

            clear(v);
            reserve(v, 100);
            for(size_t i = 0; i < 50; i++) append(v, i);
            squeeze(v);

            if(getCapacity(v) == 50){
                cout << "15!" << endl;
            }
            deleteVector(v);
        //}

        //SECTION("append") {
           v = createVector();
            clear(v);
            int arr[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
            append(v, arr, 10);
            for(size_t i = 0; i < 10; i++)
                if(getValue(v, i) == arr[i]){
                    cout << "16!" << endl;
                }
            deleteVector(v);
        //}

        //SECTION("insert") {
           v = createVector();
            clear(v);
            int arr0[] = {0, 1, 2, 3, /*4, */5, 6, 7, 8, 9};
            append(v, arr0, 9);

            insert(v, 4, 4);
            for(size_t i = 0; i < 10; i++)
                if(getValue(v, i) == i){
                    cout << "17!" << endl;
                }
            deleteVector(v);
        //}

        //SECTION("erase") {
            v = createVector();
            clear(v);
            int arr1[] = {0, 1, 2, 3, 4,     5, 6, 7, 8, 9};
            int arr2[] = {0, 1, 2, 3, /*4, */5, 6, 7, 8, 9};

            append(v, arr1, 10);
            erase(v, 4);

            for(size_t i = 0; i < 9; i++)
                if(getValue(v, i) == arr2[i]){
                    cout << "18!" << endl;
                }
            deleteVector(v);
        //}

        //SECTION("indexOf") {
            v = createVector();
            clear(v);
            int arr00[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
            append(v, arr00, 10);

            if(indexOf(v, 100) == -1){
                cout << "19!" << endl;
            }
            if(indexOf(v, 0) == 0){
                cout << "20!" << endl;
            }
            if(indexOf(v, 10) == 1){
                cout << "21!" << endl;
            }
            if(indexOf(v, 50) == 5){
                cout << "22!" << endl;
            }
            deleteVector(v);
        //}

        //SECTION("copy") {
            v = createVector();
            clear(v);
            append(v, 1);
            append(v, 2);
            append(v, 3);

            Vector *copy = copyVector(v);
            if(getValue(v, 0) == getValue(copy, 0)){
                cout << "23!" << endl;
            }
            if(getValue(v, 1) == getValue(copy, 1)){
                cout << "24!" << endl;
            }
            if(getValue(v, 2) == getValue(copy, 2)){
                cout << "25!" << endl;
            }
        //}

        //SECTION("swap") {
            Vector *v1 = createVector();
            clear(v1);
            append(v1, 1);
            append(v1, 2);
            append(v1, 3);

            Vector *v2 = createVector();
            clear(v2);
            append(v2, 10);
            append(v2, 20);
            append(v2, 30);

            swapVector(v1, v2);

            if(getValue(v1, 0) == 10){
                cout << "26!" << endl;
            }
            if(getValue(v1, 1) == 20){
                cout << "27!" << endl;
            }
            if(getValue(v1, 2) == 30){
                cout << "28!" << endl;
            }

            if(getValue(v2, 0) == 1){
                cout << "29!" << endl;
            }
            if(getValue(v2, 1) == 2){
                cout << "30!" << endl;
            }
            if(getValue(v2, 2) == 3){
                cout << "31!" << endl;
            }
        //}
    return 0;
}
