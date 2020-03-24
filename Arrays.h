PROGMEM const char CHEM[] = "CHEM";
PROGMEM const char MATH[] = "MATH";
PROGMEM const char PHY[] = "PHY ";
PROGMEM const char GEO[] = "GEO ";
PROGMEM const char LA2[] = "2LA ";
PROGMEM const char ENG[] = "ENG ";
PROGMEM const char HIST[] = "HIST";
PROGMEM const char COMP[] = "COMP";
PROGMEM const char BIO[] = "BIO ";
PROGMEM const char LIB[] = "LIB ";
PROGMEM const char SPA[] = "SPA ";
PROGMEM const char LUNCH[] = "LUN ";
PROGMEM const char SNACKS[] = "SNCK";
PROGMEM const char EMP[] = "    ";


const char* const MON[15] PROGMEM = {CHEM, ENG, SNACKS, MATH, MATH, GEO, LA2, PHY, PHY, LUNCH, ENG, HIST,  EMP,  EMP,  EMP};
const char* const TUE[15] PROGMEM = {ENG, HIST, SNACKS, BIO, PHY, MATH, MATH, COMP, COMP, LUNCH, LA2, GEO, EMP,  EMP,  EMP};
const char* const WED[15] PROGMEM = {CHEM, MATH, SNACKS, PHY, HIST, ENG, LA2, COMP, COMP, LUNCH, ENG, GEO, EMP,  EMP,  EMP};
const char* const THU[15] PROGMEM = {ENG, LA2, SNACKS , LIB, MATH, MATH, HIST, COMP, COMP, LUNCH, BIO, GEO, EMP,  EMP,  EMP};
const char* const FRI[15] PROGMEM = {CHEM, CHEM, SNACKS, ENG, MATH, BIO, BIO, GEO, LA2, LUNCH, SPA, SPA, EMP,  EMP,  EMP};
const char* const SAT[15] PROGMEM = {EMP,  EMP,  EMP, EMP,  EMP,  EMP, EMP,  EMP,  EMP,  EMP, EMP,  EMP,  EMP, EMP, EMP};
const char* const SUN[15] PROGMEM = {EMP,  EMP,  EMP, EMP,  EMP,  EMP, EMP,  EMP,  EMP,  EMP, EMP,  EMP,  EMP, EMP, EMP};

String daysOfTheWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int colours[15] = {CYAN, DARKCYAN, MAROON, PURPLE, LIGHTGREY, DARKGREY, BLUE, GREEN, RED, MAGENTA, YELLOW, WHITE, ORANGE};
