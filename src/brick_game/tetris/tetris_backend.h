/*! \mainpage My Personal Index Page
 *
 * \section Brick Game
 *
 * BrickGame - популярная портативная консоль 90-ых годов с несколькими тысячами
 * встроенными играми, разработанная в Китае. Изначально была копией
 * разработанной в СССР и выпущенной Nintendo в рамках платформы GameBoy игры
 * «Тетрис», но включала в себя также и множество других игр, которые
 * добавлялись с течением времени. Консоль имела небольшой экранчик с игровым
 * полем размера 10х20, представляющим из себя матрицу «пикселей». Справа от
 * поля находилось табло с цифровой индикацией состояния текущей игры, рекордами
 * и прочей дополнительной информацией. Самыми распространенными играми на
 * BrickGame были: тетрис, танки, гонки, фроггер и змейка.
 *
 * \section Tetris
 *
 * Для реализации игры "Тетрис" проект должен состоять из двух частей:
 * библиотеки, реализующей логику работы игры, которую можно подключать к
 * различным GUI в будущем, и терминального интерфейса, разработанного с
 * использованием библиотеки ncurses. Логика работы библиотеки должна быть
 * реализована с использованием конечных автоматов.
 */

#ifndef TETRIS_BACKEND_H_
#define TETRIS_BACKEND_H_

#include "objects.h"
#include "tetris_fsm.h"

/*!

    \brief Инициализация основных переменных игры

 */

void infoInit(GameInfo_t *gameInfo);

/*!
  @brief Освобождение памяти под главной структурой
 */
void infoFree(GameInfo_t *gameInfo);

/*!
   @brief Проверка на возможность спавна новой фигуры и её спавн
 */
int spawn_block(GameInfo_t *gameInfo, block block_type, Tetramino *current);

/*!
    \brief Проверка, можно ли заспавнить на текущих координатах фигуру
 */
int is_not_spawnable(GameInfo_t *gameInfo, Tetramino *current);

/*!
    \brief Инициализация координат фигуры I
 */
void tetramino_init_I(Tetramino *current);

/*!
    \brief Инициализация координат фигуры J
 */
void tetramino_init_J(Tetramino *current);

/*!
    \brief Инициализация координат фигуры L
 */
void tetramino_init_L(Tetramino *current);

/*!
    \brief Инициализация координат фигуры O
 */
void tetramino_init_O(Tetramino *current);

/*!
    \brief Инициализация координат фигуры S
 */
void tetramino_init_S(Tetramino *current);

/*!
    \brief Инициализация координат фигуры T
 */
void tetramino_init_T(Tetramino *current);

/*!
    \brief Инициализация координат фигуры Z

 */
void tetramino_init_Z(Tetramino *current);

/*!
    \brief Инициализация "Следующей фигуры I" для последующего отображения в
   окне справа
 */
void next_init_I(GameInfo_t *board);

/*!
    \brief Инициализация "Следующей фигуры J" для последующего отображения в
   окне справа
 */
void next_init_J(GameInfo_t *board);

/*!
    \brief Инициализация "Следующей фигуры L" для последующего отображения в
   окне справа
 */
void next_init_L(GameInfo_t *board);

/*!
    \brief Инициализация "Следующей фигуры O" для последующего отображения в
   окне справа
 */
void next_init_O(GameInfo_t *board);

/*!
    \brief Инициализация "Следующей фигуры S" для последующего отображения в
   окне справа
 */
void next_init_S(GameInfo_t *board);

/*!
    \brief Инициализация "Следующей фигуры T" для последующего отображения в
   окне справа
 */
void next_init_T(GameInfo_t *board);

/*!
    \brief Инициализация "Следующей фигуры Z" для последующего отображения в
   окне справа
 */
void next_init_Z(GameInfo_t *board);

/*!
    \brief Проверка заполненности целой линии и перенос блоков на один в низ в
   случае успеха
 */
int check_full_line(GameInfo_t *board);

/*!
    \brief Перевод количества собранных линий в очки и запись их
 */
void lines_to_score(GameInfo_t *gameInfo, int lines);

/*!
    \brief Запись в основную матрицу игрового поля блоков с координат переменной
 */
int board_update(GameInfo_t *board, Tetramino *current);

/*!
    \brief Инициализация "Следующей фигуры" для последующего отображения в окне
   справа

 */
void next_update(GameInfo_t *board, block nextBlock);

#endif