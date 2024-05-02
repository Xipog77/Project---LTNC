#pragma once

#include "Graphic.h"

const int BALISTA_TURRET_ATTACK[][4] = {

    { 70  ,0,460,480 },
    { 670 ,0,460,480 },
    { 1270,0,460,480 },
    { 1870,0,460,480 },
    { 3070,0,460,480 },
};

const int SPELL_CLIPS[][4] = {

    { 20,0, 70,170 },
    { 130,0,70,170 },
    { 240,0,70,170 },
    { 350,0,70,170 },
    { 470,0,70,170 },
};

const int BACKGROUND[][4] = {

    { 0, 0   , 800 ,330},
    { 0, 336 , 800 ,330},
    { 0, 672 , 800 ,330},
    { 0, 1008, 800 ,330},
    { 0, 1344, 800 ,330},
};

const int WARRIOR_WALK_CLIP[5][4] = {

    { 0  ,0,65,60},
    { 65 ,0,65,60},
    { 130,0,65,60},
    { 195,0,65,60},
    { 260,0,65,60},
};

const int WARRIOR_ATTACK_CLIPS[5][4] = {

    { 0  ,0,65,65},
    { 90 ,0,65,65},
    { 195,0,75,65},
    { 285,0,75,65},
    { 375,0,75,65},
};

const int SKULL_WALK_CLIPS[5][4] = {

    { 20 ,0,80,137},
    { 125,0,80,137},
    { 230,0,80,137},
    { 330,0,85,137},
    { 435,0,80,137},    
};

const int SKULL_ATTACK_CLIPS[5][4] = {

    { 120,0,85,140 },
    { 340,0,85,140 },
    { 525,0,85,140 },
    { 725,0,85,140 },
    { 965,0,85,140 },
};

const int ARCHER_ATTACK_CLIPS[][4] = {

    { 7  ,0,45,50 },
    { 63 ,0,45,50 },
    { 115,0,45,50 },
    { 175,0,45,50 },
    { 231,0,45,50 }, 
};

const int ARCHER_WALK_CLIPS[][4] = {

    { 7  ,0,45,50 },
    { 58 ,0,45,50 },
    { 121,0,45,50 },
    { 177,0,45,50 },
    { 7  ,0,45,50 }, 
};

const int ALIEN_WALK_CLIPS[][4] = {

    { 25 ,0,55,85 },
    { 123,0,55,85 },
    { 219,0,55,85 },
    { 324,0,55,85 },
    { 425,0,55,85 }, 
};

const int ALIEN_ATTACK_CLIPS[][4] = {

    { 40 ,0,50,72 },
    { 102,0,89,72 },
    { 102,0,89,72 },
    { 102,0,89,72 },
    { 40 ,0,50,72 }, 
};

const int GHOST_ATTACK_CLIPS[][4] = {

    { 30, 15 , 50,50 },
    { 130,15 , 50,50 },
    { 225,15 , 50,50 },
    { 320,15 , 50,50 },
    { 430,30 , 50,50 }, 
};

const int GHOST_WALK_CLIPS[][4] = {

    { 15 , 5, 50,50 },
    { 90 ,5 , 50,50 },
    { 165,5 , 50,50 },
    { 240,5 , 50,50 },
    { 315,5 , 50,50 }, 
};

const int KNIGHT_WALK_CLIPS[][4] = {

    { 115 , 70 , 50 , 120 },
    { 470 , 65 , 50 , 125 },
    { 810 , 80 , 225, 110 },
    { 1190, 95 , 110, 90  },
    { 1550, 55 , 80 , 135 }, 
};

const int KNIGHT_ATTACK_CLIPS[][4] = {

    { 115 ,70 ,50 ,120},
    { 415 ,85 ,130,105},
    { 785 ,35 ,80 ,155},
    { 1135,85 ,125,105},
    { 1520,100,70 ,90 }, 
};

const int HERO_WALK_CLIPS[][4] = {

    { 15 ,0,40,70 },
    { 85 ,0,40,70 },
    { 155,0,40,70 },
    { 220,0,40,70 },
    { 290,0,40,70 },
};

const int HERO_ATTACK_CLIPS[][4] = {

    { 25 ,0,40,95 },
    { 130,0,45,95 },
    { 245,0,75,95 },
    { 355,0,70,95 },
    { 465,0,65,95 },
};

const int BOSS_WALK_CLIPS[][4] = {

    { 10,10, 240,195 },
    { 260,10,240,195},
    { 505,10,240,195 },
    { 760,10,240,195},
    { 1015,10,240,195},
};

const int BOSS_ATTACK_CLIPS[][4] = {

    { 290,0, 195,300 },
    { 715,0,275,300},
    { 1315,0,175,300 },
    { 1685,0,330,300},
    { 2190,0,280,300},
};

const int NON_SPECIAL_MOVESET[5] = { 0,0,0,0,0 };
const int SKULL_ATTACK_SPECIAL_MOVESET[5] = {0, 0, 0,-30,0};
const int ARCHER_ATTACK_SPECIAL_MOVESET[5] = { 0, 0, -9,0,0 };
const int ALIEN_ATTACK_SPECIAL_MOVESET[5] = { 0, -40, -40, -40,0 };
const int KNIGHT_WALK_SPECIAL_MOVESET[5] = { 0, 0, -10,-10, 0 };
const int KNIGHT_ATTACK_SPECIAL_MOVESET[5] = { 0, -50, -40, -40,0 };
const int BOSS_WALK_SPECIAL_MOVESET[5] = { 0, 0, -5, 0,0 };
const int BOSS_ATTACK_SPECIAL_MOVESET[5] = { 0, -70, 10, -70, -70 };
const int HERO_WALK_SPECIAL_MOVESET[5] = { 0, 0, 0,-4,-4 };


const int NON_RESIZE[2] = { 0, 0 };
const int CATAPULT_RESIZE[2] = { -306, -320};
const int GHOST_RESIZE[2] = {80,80};
const int WARRIOR_RESIZE[2] = {65,60};
const int ARCHER_RESIZE[2] = {45 , 50};
const int ALIEN_RESIZE[2] = {55,85};
const int HERO_RESIZE[2] = { 40,70 };
const int KNIGHT_RESIZE[2] = { 25, 60 };