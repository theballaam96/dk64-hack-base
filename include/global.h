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
extern void initStackTrace(void);
extern void handleGrabbingLock(void* player, int player_index, int allow_vines);
extern void handleActionSet(int action, void* actor, int player_index);

extern const s16 kong_flags[5];
extern char tag_locked;
extern char grab_lock_timer;