#include "brick_game_frontend.h"

UserAction_t get_signal(int user_input) {
  UserAction_t rc = -1;

  if (user_input == KEY_UP) rc = Up;
  if (user_input == KEY_DOWN)
    rc = Down;
  else if (user_input == KEY_LEFT)
    rc = Left;
  else if (user_input == KEY_RIGHT)
    rc = Right;
  else if (user_input == ESCAPE)
    rc = Terminate;
  else if (user_input == ENTER_KEY)
    rc = Action;
  else if (user_input == KEY_BACKSPACE)
    rc = Pause;

  return rc;
}

void print_overlay(void) {
  print_border(BORD_TOP_Y, BORD_BOT_Y, BORD_LEFT_X, BORD_RIGHT_X);
  print_rectangle(TOP_Y, BOT_Y, LEFT_X, RIGHT_X);
  print_rectangle(NEXT_TOP_Y, NEXT_BOT_Y, NEXT_LEFT_X, NEXT_RIGHT_X);

  mvprintw(1, 22, "TETRIS");
  mvprintw(2, 30, "NEXT");
  mvprintw(11, 27, "LEVEL");
  mvprintw(14, 27, "SPEED");
  mvprintw(17, 27, "SCORE");
  mvprintw(20, 27, "HIGH SCORE");

  mvprintw(13, 4, "Press ENTER to START");

  mvprintw(26, 20, "Control");
  mvprintw(28, 25, "ESC - exit");
  mvprintw(29, 25, "BACKSPACE - pause");
  mvprintw(27, 7, "-> - left");
  mvprintw(28, 7, "<- - right");
  mvprintw(29, 7,
           "V - down");  // ↓ (этот символ выводится на терминале странно)
  mvprintw(30, 7, "ENTER - rotate");
}
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  for (int y = top_y; y < bottom_y + 1; y++) {
    mvprintw(y, left_x, "|");
    mvprintw(y, right_x, "|");
  }
  for (int y = top_y; y < bottom_y + 1; y++) {
    for (int x = left_x; x < right_x - 1; x++) {
      if (x % 2 == 1) {
        mvaddch(y, x + 1, '.');
      }
    }
  }
  for (int x = left_x; x < right_x + 1; x++) {
    mvaddch(bottom_y, x, '=');
  }
}
void print_stats(GameInfo_t *stats) {
  mvprintw(12, 27, "%d", stats->level);
  mvprintw(15, 27, "%d", stats->speed);
  mvprintw(18, 27, "%d", stats->score);
  mvprintw(21, 27, "%d", stats->high_score);
}
void print_board(GameInfo_t *board) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 20; y++) {
      if (board->field[x][y] == 1) {
        mvaddch(y + TOP_Y, x * 2 + (LEFT_X + 1), '[');
        mvaddch(y + TOP_Y, x * 2 + 1 + (LEFT_X + 1), ']');
      } else {
        mvaddch(y + TOP_Y, x * 2 + (LEFT_X + 1), ' ');
        mvaddch(y + TOP_Y, x * 2 + 1 + (LEFT_X + 1), '.');
      }
    }
  }
}
void print_banner(GameInfo_t *stats) {
  mvprintw(9, 7, "            ");
  mvprintw(10, 7, "  GAMEOVER  ");
  mvprintw(11, 7, "            ");
  mvprintw(12, 7, "  Level: %d  ", stats->level);
  mvprintw(13, 7, "              ");
  mvprintw(14, 6, "  Score: %d  ", stats->score);
  mvprintw(15, 6, "                 ");
  mvprintw(16, 5, "  High Score: %d  ", stats->high_score);
  mvprintw(17, 5, "                      ");
  mvprintw(18, 4, "  Press ESC to Quit  ");
  mvprintw(19, 4, "                     ");
}
void print_next_section(GameInfo_t *stats) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (stats->next[j][i] == 1) {
        mvprintw(NEXT_TOP_Y + j, NEXT_LEFT_X + 1 + i * 2, "[]");
      } else {
        mvprintw(NEXT_TOP_Y + j, NEXT_LEFT_X + 1 + i * 2, " .");
      }
    }
  }
}

void print_pause() { mvprintw(13, 7, " GAME PAUSED "); }

void print_border(int top_y, int bottom_y, int left_x, int right_x) {
  for (int y = top_y; y < bottom_y + 7; y++) {
    mvprintw(y, left_x, "|");
    mvprintw(y, right_x, "|");
  }
  for (int x = left_x; x < right_x + 1; x++) {
    mvaddch(bottom_y - 2, x, '-');
    mvaddch(top_y, x, '-');
    mvaddch(bottom_y + 6, x, '-');
  }
}

GameInfo_t updateCurrentState() {
  GameInfo_t *gameInfo = change_GameInfo_t(NULL);
  if (gameInfo->pause == 1) {
    print_pause(gameInfo);
  } else {
    print_board(gameInfo);
    print_next_section(gameInfo);
    print_stats(gameInfo);
  }
  return *gameInfo;
}

GameInfo_t *change_GameInfo_t(GameInfo_t *gameInfo) {
  static GameInfo_t *Info;
  if (gameInfo == NULL) return Info;
  Info = gameInfo;
  return Info;
}