/*
** EPITECH PROJECT, 2018
** My RPG
** File description:
** Configuration file
*/

#ifndef CONF_H_
#define CONF_H_

// General section
#define LEAFLET "\t\t\t---RPG---\nThis game is a reproduction "\
		"of a rpg game ""it's a kind of game really famous !\n"\
		"To win you should finish quests\n"

#define WINDOW_NAME "My RPG"
#define WINDOW_STYLE sfFullscreen
#define VIDEO_MODE {1920, 1080, 4}

// Global audio options (Use only to play audio between scenes transitions)
#define GLOBAL_MAX_AUDIO 2
#define GLOBAL_AUDIO_OK "assets/global/click.wav"
#define GLOBAL_AUDIO_NO "assets/global/click_wrong.wav"

//Font
#define FONT "assets/font/font.ttf"

// Main menu section
#define MENU_MAX_SPRITES 2
#define MENU_MAX_BUTTONS 3
#define MENU_MAX_AUDIO 1

#define MENU_BG_FILE "assets/menu/bg.png"
#define MENU_AUDIO_BACKGROUND "assets/menu/ambient.ogg"

#define MENU_LOGO_FILE "assets/menu/logo.png"
#define MENU_LOGO_X 100
#define MENU_LOGO_Y 100

#define MENU_BUTTON_Y 800
#define MENU_BUTTON_SIZE_X 500
#define MENU_BUTTON_SIZE_Y 120
#define MENU_HTP_SIZE_X 100
#define MENU_HTP_SIZE_Y 100
#define MENU_PLAY_BUTTON_FILE "assets/menu/ng.png"
#define MENU_PLAY_BUTTON_X 400
#define MENU_EXIT_BUTTON_FILE "assets/menu/exit.png"
#define MENU_EXIT_BUTTON_X 1200
#define MENU_HTP_BUTTON_FILE "assets/menu/htp.png"
#define MENU_HTP_BUTTON_X 1000

// How to play section
#define HTP_MAX_SPRITES 3
#define HTP_MAX_BUTTONS 3
#define HTP_MAX_PAGES 2
#define HTP_MAX_AUDIO 3

#define HTP_AUDIO_BACKGROUND "assets/htp/ambient.ogg"
#define HTP_AUDIO_OK "assets/global/click.wav"
#define HTP_AUDIO_NO "assets/global/click_wrong.wav"

#define HTP_BG_FILE "assets/htp/bg.png"
#define HTP_PAGE_1_FILE "assets/htp/page1.png"
#define HTP_POSITION_X 260
#define HTP_POSITION_Y 50
#define HTP_PAGE_2_FILE "assets/htp/page2.png"

#define HTP_BUTTON_Y 900
#define HTP_BUTTON_SIZE_X 300
#define HTP_BUTTON_SIZE_Y 100
#define HTP_PREV_BUTTON_FILE "assets/htp/prev.png"
#define HTP_PREV_BUTTON_X 50
#define HTP_EXIT_BUTTON_FILE "assets/htp/exit.png"
#define HTP_EXIT_BUTTON_X 925
#define HTP_NEXT_BUTTON_FILE "assets/htp/next.png"
#define HTP_NEXT_BUTTON_X 1725

// Game section

// Game board X and Y offsets
#define GXO get_tile_pos_x
#define GYO get_tile_pos_y

#define GAME_MAX_SPRITES 5
#define GAME_MAX_BUTTONS 3
#define GAME_MAX_AUDIO 1
#define GAME_MAX_CHARAC 3

#define GAME_PAUSE_Y 900
#define GAME_PAUSE_SIZEX 570
#define GAME_PAUSE_SIZEY 150
#define GAME_PAUSE_QUIT_FILE "assets/game/exit.png"
#define GAME_PAUSE_QUIT_X 1300
#define GAME_PAUSE_RESUME_FILE "assets/game/resume.png"
#define GAME_PAUSE_RESUME_X 100
#define GAME_PAUSE_MENU_FILE "assets/game/gomenu.png"
#define GAME_PAUSE_MENU_X 700

#define GAME_AUDIO_BACKGROUND "assets/game/ambient.ogg"
#define GAME_MENU_BG_FILE "assets/game/menu.png"
#define GAME_CHARACTER_FILE "assets/game/character.png"
#define GAME_PNJ_FILE "assets/game/link.png"
#define GAME_PNJ_01_FILE "assets/game/pnj.png"
#define GAME_CHAT "assets/game/back.png"
#define GAME_MOB "assets/game/mob.png"

#define MOB_X 5
#define MOB_Y 3
#define PNJ_X 13
#define PNJ_Y 6
#define CHARAC_X 13
#define CHARAC_Y 11
#define NB_PNJ 1
#define NB_MOB 1

#define GAME_QUEST_1 "assets/game/board_pg.png"

#define NB_TEXT_PNJ_01 8
#define TEXT_PNJ_01 "Moi:\nSalut toi, qui es-tu ?\n"
#define TEXT_PNJ_02 "???:\nSalut, moi c'est Link.\nSalut, moi c'est Link.\n"\
"Salut, moi c'est Link.\n"
#define TEXT_PNJ_03 "Moi:\nTu ne sais pas dire autre chose j'imagine ?\n"\
"Tu ne sais pas qui je suis par hasard ?\n"\
"Ces foutus developpeurs m'ont foutu ici..."
#define TEXT_PNJ_04 "Link:\nJ'ai reussi a me delivrer de leur code de merde !"\
"\nToi, tu t'appelles Zelda et moi, c'est Link."
#define TEXT_PNJ_05 "Zelda:\nDonc tu veux dire que leur jeu s'appelle Link et"\
"\nque je suis le personnage principal...\nQuelle bande de cons.\n"
#define TEXT_PNJ_06 "Zelda:\nBon sinon, histoire de faire quelque chose, \n"\
"tu n'aurais pas une petite quete pour moi ?\n"
#define TEXT_PNJ_07 "Link:\nOn va faire comme dans les RPG habituels...\n"\
"Va voir le pnj dans la maison, parle lui \net reviens, tu gagneras de l'experience...\n"
#define TEXT_PNJ_08 "Link:\nVa voir un PNJ !"
#define TEXT_PNJ_09 "Link:\nBravo ! Tu as termine la premiere\n"\
"et la derniere quete !\n"

#define NB_TEXT_PNJ_02 2
#define TEXT_PNJ_10 "???:\nSalut, moi c'est Nayru, \nje vis dans cette maison "\
"depuis 2 ans et\nj'aime les pates, on s'en fou hein ?"
#define TEXT_PNJ_11 "Zelda:\nOui.\n"

#define NB_QUEST_PNJ_02 3
#define TEXT_PNJ_12 "Nayru:\nTu viens juste me parler pour une quete,\n"\
" c'est ca ? Allez tiens, casse toi...\n"
#define TEXT_PNJ_13 "Moi:\nTu n'es que du code, ferme la !\n"
#define TEXT_PNJ_14 "Nayru:\nHein, euh quoi?"

#define TEXT_PNJ_15 "???:\nRegarde, il se reveille !\n"

#define QUIT "Tu... Tu veux vraiment quitter ..? s..senpai ?"

#define NB_TILES_OVERWORLD 65
#define NB_TILES_HOUSE 43
#define NB_TILES_TEST 5
#define TILES_OVERWORLD "assets/game/tiles.png"
#define TILES_HOUSE "assets/game/tiles_house.png"
#define TILES_TEST "assets/game/test_tiles.png"
#define MAP_OVERWORLD "assets/game/maps/overworld.map"
#define MAP_OVERWORLD2 "assets/game/maps/overworld2.map"
#define MAP_HOUSE "assets/game/maps/house.map"
#define MAP_BAP "assets/game/maps/bap.map"
#define MAP_TEST "assets/game/maps/bitmap.map"

#endif /* !CONF_H_ */
