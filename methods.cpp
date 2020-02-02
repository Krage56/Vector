#include "vector2.h"

Vector *createVector(){
    Vector *v = new Vector;
    v->capacity = 0;
    v->size = 0;
    v->data = nullptr;
    return v;
}

void deleteVector(Vector *v){
    if(v->data){
        v->capacity = 0;
        v->size = 0;
        int *arr = (v->data);
        v->data = 0;
        delete[](arr);
    }
//    if (v){
//        delete[](v);
//        v = nullptr;
//    }
}

Vector *copyVector(Vector *v){
    Vector *new_v = createVector();
    new_v->data = new int[v->capacity];
    new_v->size = v->size;
    new_v->capacity = v->capacity;
    memcpy(new_v->data, v->data, sizeof(int) * (v->size));
    return new_v;
}


void swapVector(Vector *lh, Vector *rh){
    Vector *tmp = copyVector(lh);

    reserve(lh, rh->capacity);
    memcpy((lh -> data), (rh -> data), (sizeof(int) * (rh -> capacity)));
    lh -> size = rh -> size;
    lh -> capacity = rh -> capacity;

    reserve(rh, tmp->capacity);
    memcpy((rh -> data), (tmp -> data), (sizeof(int) * (tmp -> capacity)));
    rh -> size = tmp -> size;
    rh -> capacity = tmp -> capacity;

    deleteVector(tmp);
}

int getValue(Vector *v, size_t index){
    if((v -> data) && (getSize(v) > index))
        return *((v -> data) + index);
}

size_t getSize(Vector *v){
    return (v -> size);
}

size_t getCapacity(Vector *v){
    return (v -> capacity);
}

void reserve(Vector *v, size_t newCap){
    if (newCap > getCapacity(v)){
        int *arr = new int[newCap];
        memcpy(arr, v->data, (v->size) * sizeof(int));
        delete [](v->data);
        v->data = arr;
        v->capacity = newCap;
    }
}

void append(Vector *v, int value){
    if(getSize(v) + 1  < getCapacity(v)){
        (v -> data)[getSize(v)] = value;
    }
    else{
        int tmp = (v -> data) ? 0 : 1;
        reserve(v, getCapacity(v) * 2 + tmp);
        (v -> data)[getSize(v)] = value;
    }
    (v -> size) += 1;

}

void append(Vector *v, int *array, size_t count){
    if(count + getSize(v) > getCapacity(v)){
        int tmp = (count + getSize(v)) ? 0 : 1;
        reserve(v, count + getSize(v) + tmp);
    }
    int tmp_count = getSize(v);
    for(int i = 0; i < count; i++){
        (v -> data)[i + tmp_count] = array[i];
    }
    (v -> size) += count;
}

void insert(Vector *v, size_t index, int value){
    if(getSize(v) + 1 > getCapacity(v)){
        int tmp = (v -> data) ? 0 : 1;
        reserve(v, getCapacity(v) * 2 + tmp);
    }
    for(int i = getSize(v) - 1; i >= index; i--){
        (v -> data)[i + 1] = (v -> data)[i];
    }
    if(index < getSize(v)){
        (v -> data)[index] = value;
        v -> size += 1;
    }
}

void erase(Vector *v, size_t index){
    if(index < getSize(v)){
        for(int i = index; i < getSize(v) - 1; i++){
            (v -> data)[i] = (v -> data)[i + 1];
        }
        v -> size -= 1;
    }
}

size_t indexOf(Vector *v, int value){
    for(int i = 0; i < getSize(v); i++){
        if((v -> data)[i] == value)
            return i;
    }
    return -1;
}

void squeeze(Vector *v){
    if(getSize(v) != 0){
        int *arr = new int[getSize(v)];
        memcpy(arr, (v -> data), sizeof(int) * getSize(v));
        delete [](v -> data);
        (v -> data) = arr;
        v -> capacity = v -> size;
    }
    else
        deleteVector(v);
}

void clear(Vector *v){
    for(int i = 0; i < getCapacity(v); i++){
        *((v -> data) + i) = 0;
    }
    v -> size = 0;
}

void print(Vector *v){
    for(int i = 0; i < getSize(v); i++){
        cout << (v -> data)[i];
        i == getSize(v) - 1 ? cout << "" : cout << ", ";
    }
    cout << "\n";
}
