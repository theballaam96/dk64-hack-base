#include "vars.h"

extern void setPermanentFlag(s16 flagIndex);
extern void setGlobalFlag(s16 flagIndex);
extern void setTemporaryFlag(s16 flagIndex);
extern void* findActorWithType(s32 search_actor_type);

// Stuff to do with Tag Anywhere and the stack trace
extern void tagAnywhereBunch(int player, int obj, int player_index);
extern void tagAnywhereAmmo(int player, int obj, int is_homing);
extern void tagAnywhereInit(int is_homing, int model2_id, int obj);
extern void initHack(void);
extern void tagAnywhere(void);
void initStackTrace(void);

extern const s16 kong_flags[5];