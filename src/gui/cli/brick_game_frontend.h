#ifndef BRICK_GAME_FRONTEND_H_
#define BRICK_GAME_FRONTEND_H_

#include <ncurses.h>
#include <string.h>

#include "../../brick_game/tetris/tetris_fsm.h"

/*!

    \brief Перевод сигнала в код UserAction_t

 */
UserAction_t get_signal(int user_input);

/*!

    \brief Рисует основной интерфейс для игры
 */
void print_overlay(void);

/*!

    \brief Рисует прямоугольник по заданным координатам

 */
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);

/*!

    \brief Выводит статы в правом блоке интерфейса

 */
void print_stats(GameInfo_t *stats);

/*!

    \brief Выводит статы в правом блоке интерфейса

 */
void print_board(GameInfo_t *board);

/*!

    \brief Выводит баннер поражения

 */
void print_banner(GameInfo_t *stats);

/*!

    \brief Рисует фигуру в блоке следующей фигуры тетриса

 */
void print_next_section(GameInfo_t *stats);

/*!

    \brief Выводит надпись Игра остановлена
 */
void print_pause();

/*!

    \brief Получаем или задаём в статическую переменную структуру GameInfo_t

 */
GameInfo_t *change_GameInfo_t(GameInfo_t *gameInfo);

/*!

    \brief Основная функция отрисовки всего интерфеса
 */
GameInfo_t updateCurrentState();

/*!

    \brief Отрисовка границ игры
 */
void print_border(int top_y, int bottom_y, int left_x, int right_x);

#endif