#ifndef TETRIS_FSM_H_
#define TETRIS_FSM_H_

#include "objects.h"
#include "tetris_backend.h"

#define ESCAPE 27
#define ENTER_KEY 10

#define LEFT_X 3
#define RIGHT_X 24
#define TOP_Y 3
#define BOT_Y 23

#define NEXT_LEFT_X 27
#define NEXT_RIGHT_X 36
#define NEXT_TOP_Y 3
#define NEXT_BOT_Y 8

#define BORD_LEFT_X 0
#define BORD_RIGHT_X 47
#define BORD_TOP_Y 0
#define BORD_BOT_Y 26

/*!
    \brief Состояния конечного автомата
 */
typedef enum {
  START = 0,
  SPAWN,
  MOVING,
  ROTATE,
  SHIFTING,
  COLLIDE,
  GAMEOVER,
  EXIT_STATE,
  PAUSE
} tetris_state;

/*!

    \brief Сигналы которые принимает игра

 */
typedef enum {
  MOVE_DOWN = 0,
  MOVE_RIGHT,
  MOVE_LEFT,
  ESCAPE_BTN,
  ENTER_BTN,
  NOSIG
} signals;

/*!

    \brief Установка или получение переменной с использованием локальной
   статической переменной

 */
GameInfo_t *get_gameInfo(GameInfo_t *gameInfo);

/*!

    \brief Установка или получение переменной с использованием локальной
   статической переменной

 */
UserAction_t *get_UserAction_t(UserAction_t *sig);

/*!

    \brief Установка или получение переменной с использованием локальной
   статической переменной

 */
bool *get_fallTime(bool *fallTime);

/*!

    \brief Установка или получение переменной с использованием локальной
   статической переменной

 */
tetris_state *get_state(tetris_state *state);

/*!

    \brief Установка или получение переменной с использованием локальной
   статической переменной

 */
Tetramino *get_current(Tetramino *current);

/*!

    \brief Установка или получение переменной с использованием локальной
   статической переменной

 */
block *get_nextBlock(block *nextBlock);

/*!

    \brief Функция из спецификации. Вводим только код сигнала. Идет обработка
   всех нужных переменных на статической уровне и происходит игровой шаг

 */
void userInput(UserAction_t action, bool hold);

/*!

    \brief Сам конечный автомат состояний и переключений между состояниями

 */
void sigact(UserAction_t *sig, const bool *fallTime, tetris_state *state,
            GameInfo_t *gameInfo, Tetramino *current, block *nextBlock);

/*!

    \brief Состояние спавна новой фигуры и проверки можно ли
   заспавнить новую фигуру

*/
void spawn_state(GameInfo_t *gameInfo, Tetramino *current, block *nextBlock,
                 tetris_state *state);

/*!

    \brief Состояние движения фигуры, принимает на вход сигнал нажатия для
   определения направления движеия фигуры

*/
void move_state(UserAction_t *sig, GameInfo_t *gameInfo, Tetramino *current,
                tetris_state *state);

/*!

    \brief Состояние паузы. Проверка на нажатие паузы или выхода из игры

*/
void pause_state(UserAction_t *sig, GameInfo_t *gameInfo, tetris_state *state);

/*!

    \brief Проверка на возможность движения фигуры вниз. Движение фигуры вниз

*/
int movedown(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Проверка на возможность движения фигуры вправо. Движение фигуры
   вправо

*/
void moveright(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Проверка на возможность движения фигуры влево. Движение фигуры влево

*/
void moveleft(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Проверка на возможность движения фигуры вниз. Движение фигуры вниз
   после определенного таймера

*/
void movedown_clock_check(GameInfo_t *gameInfo, Tetramino *current,
                          tetris_state *state);

/*!

    \brief Функция определяющая поворот фигуры согласно её типу

*/
int rotate(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры I

*/
void rotate_I(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры J. Первые две формы

*/
int rotate_J_first(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры J. Вторые две формы


*/
void rotate_J_second(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры J

*/
void rotate_J(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры L. Первые две формы

*/
int rotate_L_first(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры L. Вторые две формы

*/
void rotate_L_second(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры L

*/
void rotate_L(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры S

*/
void rotate_S(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры T. Первые две формы

*/
int rotate_T_first(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры T. Вторые две формы

*/
void rotate_T_second(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры T

*/
void rotate_T(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Расчёт поворота для фигуры Z

*/
void rotate_Z(Tetramino *current, GameInfo_t *gameInfo);

/*!

    \brief Очистка поля от старого положения фигуры

*/
void clear_backpos(Tetramino *current, GameInfo_t *gameInfo);

/*!
    \brief Основная фукция, обеспечивающая игровой шаг
 */
tetris_state game_loop(GameInfo_t *gameInfo, UserAction_t sig);

#endif