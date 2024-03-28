#ifndef SCREEN_DRAWING_CHARACTERS
#define SCREEN_DRAWING_CHARACTERS

enum DrawingCharacters {
    // ' ', 32
    SPACE = 0x0020, 
    // '|', 448
    PIPE = 0x01C0,
    // '_', 818
    UNDERSCORE = 0x0332,
    // '‾', 8254
    OVERSCORE = 0x203E,
    // '.', 46
    DOT = 0x002E,
    // ''', 39
    QUOTE1 = 0x0027,
	// '╠', 9568
	PIPE_FACED_LEFT = 0x2560,
    // '═', 9552
	PIPE_HORIZONTAL = 0x2550,
    // '╣', 9571
	PIPE_FACED_RIGHT = 0x2563,
	// '╦', 9574
	PIPE_FACED_DOWN = 0x2566,
    // '║', 9553
	PIPE_VERTICAL = 0x2551,
    // '╩', 9577
	PIPE_FACED_UP = 0x2569,
	// '╔', 9556
	ANGLE_TOP_LEFT = 0x2554,
    // '╗', 9559
	ANGLE_TOP_RIGHT = 0x2557,
	// '╚', 9562
	ANGLE_BOTTOM_LEFT = 0x255A,
    // '╝', 9565
	ANGLE_BOTTOM_RIGHT = 0x255D,
	// '╬', 9580
	CROSS = 0x256C
};

#endif
