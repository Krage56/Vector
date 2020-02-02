#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

/**
 * Динамически создаёт структуру вектора,
 * инициализирует нулями и возвращает указатель
 * на неё.
 */
Vector *createVector();

/**
 * Удаляет данные внутри вектора
 * и сам вектор.
 *
 * @param v Удаляемый вектор
 */
void deleteVector(Vector *v);

/**
 * Динамически создаёт новый вектор ---
 * полную копию указанного.
 *
 * @param v Копируемый вектор
 */
Vector *copyVector(Vector *v);

/**
 * Меняет местами содержимое векторов
 * @param lh Первый вектор
 * @param rh Второй вектор
 */
void swapVector(Vector *lh, Vector *rh);

/**
 * Получить значение элемента по заданной позиции
 * @param v Вектор
 * @param index Позиция
 */
int getValue(Vector *v, size_t index);

/**
 * Получить размер вектора
 * (количество добавленных элементов)
 * @param v Вектор
 */
size_t getSize(Vector *v);

/**
 * Получить вместимость вектора
 * (максимальное количество элементов, которое можно хранить в
 *  выделенном на данный момент блоке памяти)
 * @param v Вектор
 */
size_t getCapacity(Vector *v);

/**
 * Добавить значение в конец вектора.
 * Если выделенной памяти не достаточно
 * для добавления элемента,
 * выделить новый массив большего размера
 * и скопировать в него старые значения
 * @param v Вектор
 * @param value Значение
 */
void append(Vector *v, int value);

/**
 * Добавить несколько значений из массива в конец вектора.
 * Если выделенной памяти недостаточно,
 * см. void append(int)
 * @param v Вектор
 * @param array Массив
 * @param count Количество элементов
 */
void append(Vector *v, int *array, size_t count);

/**
 * Вставить значение на заданную позицию.
 * и сдвинуть элементы справа.
 * Если выделенной памяти недостаточно,
 * см. void append(int)
 * @param v Вектор
 * @param index Позиция вставки
 * @param value Значение
 */
void insert(Vector *v, size_t index, int value);

/**
 * Удалить элемент на заданной позиции
 * @param v Вектор
 * @param index Позиция
 */
void erase(Vector *v, size_t index);

/**
 * Найти первый элемент с заданным значением
 * и вернуть его индекс.
 * Если элемента нет, вернуть -1
 * @param v Вектор
 * @param value Значение
 */
size_t indexOf(Vector *v, int value);

/**
 * Установить объём (capacity) вектора в значение большее или равное newCap.
 * Если `newCap <= capacity`, ничего не делает.
 * @param v Вектор
 * @param newCap Новый объём
 */
void reserve(Vector *v, size_t newCap);

/**
 * Изменить размер выделенной памяти так,
 * чтобы он соответствовал
 * количеству элементов в векторе.
 * Если размер вектора равен нулю,
 * очистить память (delete[]).
 * @param v Вектор
 */
void squeeze(Vector *v);

/**
 * Очистить вектор --- заполнить выделенную память нулями
 * и установить размер, равный нулю.
 * @param v Вектор
 */
void clear(Vector *v);

/**
 * Вывести в std::cout элементы массива,
 * последовательно, через пробел и запятую.
 * Пример:
 * 1, 2, 3, 4
 * @param v Вектор
 */
void print(Vector *v);
