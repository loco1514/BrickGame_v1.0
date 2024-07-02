#include <check.h>
#include <stdio.h>

#include "../brick_game/tetris/tetris_fsm.h"

GameInfo_t gameInfo;

START_TEST(tetris_base_test1) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Right);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test2) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Left);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test3) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test4) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test5) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test6) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test7) {
  GameInfo_t gameInfo;
  gameInfo.field = (int **)malloc(10 * sizeof(int *));
  for (int i = 0; i < 10; ++i) {
    gameInfo.field[i] = (int *)malloc(20 * sizeof(int));
    for (int j = 0; j < 20; ++j) {
      gameInfo.field[i][j] = 0;
    }
  }
  Tetramino *current = (Tetramino *)malloc(sizeof(Tetramino));
  ck_assert_ptr_nonnull(current);

  tetramino_init_I(current);
  ck_assert_int_eq(current->x1, 3);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 4);
  ck_assert_int_eq(current->y2, 0);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 0);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 0);
  ck_assert_int_eq(current->type, I);

  tetramino_init_J(current);
  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 4);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 1);
  ck_assert_int_eq(current->type, J);

  tetramino_init_L(current);
  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 1);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 6);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 0);
  ck_assert_int_eq(current->type, L);

  tetramino_init_O(current);
  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 0);
  ck_assert_int_eq(current->x3, 4);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 5);
  ck_assert_int_eq(current->y4, 1);
  ck_assert_int_eq(current->type, O);

  tetramino_init_S(current);
  ck_assert_int_eq(current->x1, 5);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 6);
  ck_assert_int_eq(current->y2, 0);
  ck_assert_int_eq(current->x3, 4);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 5);
  ck_assert_int_eq(current->y4, 1);
  ck_assert_int_eq(current->type, S);

  tetramino_init_T(current);
  ck_assert_int_eq(current->x1, 5);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 4);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 1);
  ck_assert_int_eq(current->type, T);

  tetramino_init_Z(current);
  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 0);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 1);
  ck_assert_int_eq(current->type, Z);

  free(current);
}
END_TEST

START_TEST(tetris_base_test8) {
  GameInfo_t gameInfo;
  gameInfo.field = (int **)malloc(10 * sizeof(int *));
  for (int i = 0; i < 10; ++i) {
    gameInfo.field[i] = (int *)malloc(20 * sizeof(int));
    for (int j = 0; j < 20; ++j) {
      gameInfo.field[i][j] = 0;
    }
  }

  Tetramino *current = (Tetramino *)malloc(sizeof(Tetramino));
  ck_assert_ptr_nonnull(current);

  current->type = I;
  current->x1 = 5;
  current->y1 = 5;
  current->x2 = 5;
  current->y2 = 6;
  current->x3 = 5;
  current->y3 = 7;
  current->x4 = 5;
  current->y4 = 8;
  current->rotate_state = 0;

  rotate_I(current, &gameInfo);

  ck_assert_int_eq(current->x1, 7);
  ck_assert_int_eq(current->y1, 3);
  ck_assert_int_eq(current->x2, 6);
  ck_assert_int_eq(current->y2, 5);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 7);
  ck_assert_int_eq(current->x4, 4);
  ck_assert_int_eq(current->y4, 9);

  current->type = J;
  current->x1 = 4;
  current->y1 = 0;
  current->x2 = 4;
  current->y2 = 1;
  current->x3 = 5;
  current->y3 = 1;
  current->x4 = 6;
  current->y4 = 1;
  current->rotate_state = 0;

  rotate_J(current, &gameInfo);

  ck_assert_int_eq(current->x1, 6);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 0);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 5);
  ck_assert_int_eq(current->y4, 2);

  rotate_J(current, &gameInfo);

  ck_assert_int_eq(current->x1, 6);
  ck_assert_int_eq(current->y1, 2);
  ck_assert_int_eq(current->x2, 6);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 4);
  ck_assert_int_eq(current->y4, 1);

  rotate_J(current, &gameInfo);

  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 2);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 2);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 5);
  ck_assert_int_eq(current->y4, 0);

  rotate_J(current, &gameInfo);

  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 4);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 1);

  current->type = L;
  current->x1 = 4;
  current->y1 = 1;
  current->x2 = 5;
  current->y2 = 1;
  current->x3 = 6;
  current->y3 = 1;
  current->x4 = 6;
  current->y4 = 0;
  current->rotate_state = 0;

  rotate_L(current, &gameInfo);

  ck_assert_int_eq(current->x1, 5);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 2);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 2);

  rotate_L(current, &gameInfo);

  ck_assert_int_eq(current->x1, 6);
  ck_assert_int_eq(current->y1, 1);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 4);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 4);
  ck_assert_int_eq(current->y4, 2);

  rotate_L(current, &gameInfo);

  ck_assert_int_eq(current->x1, 5);
  ck_assert_int_eq(current->y1, 1);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 2);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 0);
  ck_assert_int_eq(current->x4, 4);
  ck_assert_int_eq(current->y4, 0);

  rotate_L(current, &gameInfo);

  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 1);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 6);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 0);

  current->type = O;
  current->x1 = 4;
  current->y1 = 0;
  current->x2 = 5;
  current->y2 = 0;
  current->x3 = 4;
  current->y3 = 1;
  current->x4 = 5;
  current->y4 = 1;
  current->rotate_state = 0;

  current->type = S;
  current->x1 = 5;
  current->y1 = 0;
  current->x2 = 6;
  current->y2 = 0;
  current->x3 = 4;
  current->y3 = 1;
  current->x4 = 5;
  current->y4 = 1;
  current->rotate_state = 0;

  rotate_S(current, &gameInfo);

  ck_assert_int_eq(current->x1, 5);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 6);
  ck_assert_int_eq(current->y2, 0);
  ck_assert_int_eq(current->x3, 4);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 5);
  ck_assert_int_eq(current->y4, 1);

  current->type = T;
  current->x1 = 5;
  current->y1 = 0;
  current->x2 = 4;
  current->y2 = 1;
  current->x3 = 5;
  current->y3 = 1;
  current->x4 = 6;
  current->y4 = 1;
  current->rotate_state = 0;

  rotate_T(current, &gameInfo);

  ck_assert_int_eq(current->x1, 6);
  ck_assert_int_eq(current->y1, 1);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 0);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 5);
  ck_assert_int_eq(current->y4, 2);

  rotate_T(current, &gameInfo);

  ck_assert_int_eq(current->x1, 5);
  ck_assert_int_eq(current->y1, 2);
  ck_assert_int_eq(current->x2, 6);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 4);
  ck_assert_int_eq(current->y4, 1);

  rotate_T(current, &gameInfo);

  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 1);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 2);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 5);
  ck_assert_int_eq(current->y4, 0);

  rotate_T(current, &gameInfo);

  ck_assert_int_eq(current->x1, 5);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 4);
  ck_assert_int_eq(current->y2, 1);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 1);

  current->type = Z;
  current->x1 = 4;
  current->y1 = 0;
  current->x2 = 5;
  current->y2 = 0;
  current->x3 = 5;
  current->y3 = 1;
  current->x4 = 6;
  current->y4 = 1;
  current->rotate_state = 0;

  rotate_Z(current, &gameInfo);

  ck_assert_int_eq(current->x1, 4);
  ck_assert_int_eq(current->y1, 0);
  ck_assert_int_eq(current->x2, 5);
  ck_assert_int_eq(current->y2, 0);
  ck_assert_int_eq(current->x3, 5);
  ck_assert_int_eq(current->y3, 1);
  ck_assert_int_eq(current->x4, 6);
  ck_assert_int_eq(current->y4, 1);

  free(current);
  for (int i = 0; i < 10; ++i) {
    free(gameInfo.field[i]);
  }
  free(gameInfo.field);
}
END_TEST

START_TEST(tetris_base_test9) {
  GameInfo_t gameInfo;
  gameInfo.next = (int **)malloc(10 * sizeof(int *));
  for (int i = 0; i < 10; ++i) {
    gameInfo.next[i] = (int *)malloc(20 * sizeof(int));
    for (int j = 0; j < 20; ++j) {
      gameInfo.next[i][j] = 0;
    }
  }
  next_init_I(&gameInfo);
  ck_assert_int_eq(gameInfo.next[1][0], 1);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 1);
  ck_assert_int_eq(gameInfo.next[1][3], 1);
  ck_assert_int_eq(gameInfo.next[2][0], 0);
  ck_assert_int_eq(gameInfo.next[2][1], 0);
  ck_assert_int_eq(gameInfo.next[2][2], 0);
  ck_assert_int_eq(gameInfo.next[2][3], 0);

  next_init_J(&gameInfo);
  ck_assert_int_eq(gameInfo.next[1][0], 1);
  ck_assert_int_eq(gameInfo.next[1][1], 0);
  ck_assert_int_eq(gameInfo.next[1][2], 0);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 1);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);

  next_init_L(&gameInfo);
  ck_assert_int_eq(gameInfo.next[1][0], 0);
  ck_assert_int_eq(gameInfo.next[1][1], 0);
  ck_assert_int_eq(gameInfo.next[1][2], 1);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 1);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);

  next_init_O(&gameInfo);
  ck_assert_int_eq(gameInfo.next[1][0], 0);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 1);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 0);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);

  next_init_S(&gameInfo);
  ck_assert_int_eq(gameInfo.next[1][0], 0);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 1);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 1);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 0);
  ck_assert_int_eq(gameInfo.next[2][3], 0);

  next_init_T(&gameInfo);
  ck_assert_int_eq(gameInfo.next[1][0], 0);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 0);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 1);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);

  next_init_Z(&gameInfo);
  ck_assert_int_eq(gameInfo.next[1][0], 1);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 0);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 0);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);

  for (int i = 0; i < 10; ++i) {
    free(gameInfo.next[i]);
  }
  free(gameInfo.next);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, tetris_base_test1);
  tcase_add_test(tc1_1, tetris_base_test2);
  tcase_add_test(tc1_1, tetris_base_test3);
  tcase_add_test(tc1_1, tetris_base_test4);
  tcase_add_test(tc1_1, tetris_base_test5);
  tcase_add_test(tc1_1, tetris_base_test6);
  tcase_add_test(tc1_1, tetris_base_test7);
  tcase_add_test(tc1_1, tetris_base_test8);
  tcase_add_test(tc1_1, tetris_base_test9);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
