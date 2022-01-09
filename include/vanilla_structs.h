typedef struct floatPos {
	/* 0x000 */ f32 xPos;
	/* 0x004 */ f32 yPos;
	/* 0x008 */ f32 zPos;
} floatPos;

typedef struct actorData {
	/* 0x000 */ s8 unk_00[0x58];
	/* 0x058 */ s32 actorType;
	/* 0x05C */ s8 unk_5C[0x7C-0x5C];
	/* 0x07C */ f32 xPos;
	/* 0x080 */ f32 yPos;
	/* 0x084 */ f32 zPos;
	/* 0x088 */ s8 unk_80[0xB8-0x88];
	/* 0x0B8 */ f32 hSpeed;
	/* 0x0BC */ s8 unk_BC[0x154-0xBC];
	/* 0x154 */ s8 control_state;
	/* 0x155 */ s8 control_state_progress;
	/* 0x156 */ s8 unk_156[0x180-0x156];
	/* 0x180 */ void* tied_character_spawner;
} actorData;

typedef struct cameraData {
	/* 0x000 */ s8 unk_00[0x7C];
	/* 0x07C */ f32 xPos;
	/* 0x080 */ f32 yPos;
	/* 0x084 */ f32 zPos;
	/* 0x088 */ s8 unk_88[0x15F-0x88];
	/* 0x15F */ s8 facing_angle;
	/* 0x160 */ s8 unk_160[0x1FC-0x160];
	/* 0x1FC */ f32 viewportX;
	/* 0x200 */ f32 viewportY;
	/* 0x204 */ f32 viewportZ;
	/* 0x208 */ s8 unk_208[0x22A-0x208];
	/* 0x22A */ s16 viewportRotation;
	/* 0x22C */ s8 unk_22C[0x26B-0x22C];
	/* 0x26B */ s8 camera_state;
} cameraData;

typedef struct bone_array {
	/* 0x000 */ s8 unk_00[0x58];
	/* 0x058 */ s16 xPos;
	/* 0x05A */ s16 yPos;
	/* 0x05C */ s16 zPos;
} bone_array;

typedef struct rendering_params {
	/* 0x000 */ s8 unk_00[0x14];
	/* 0x014 */ bone_array* bone_array1;
	/* 0x018 */ bone_array* bone_array2;
} rendering_params;

typedef struct playerData {
	/* 0x000 */ s8 unk_00[0x4];
	/* 0x004 */ rendering_params* rendering_param_pointer;
	/* 0x008 */ s8 unk_08[0x58 - 0x8];
	/* 0x058 */ s32 characterID; //02 is dk, 03 is diddy, 04 is lanky, etc
	/* 0x05C */ s8 unk_5C[0x60-0x5C];
	/* 0x060 */ s32 obj_props_bitfield;
	/* 0x064 */ s8 unk_64[0x6A-0x64];
	/* 0x06A */ s16 grounded_bitfield;
	/* 0x06C */ s16 unk_bitfield;
	/* 0x06E */ s8 unk_6E[0x7C-0x6E];
	/* 0x07C */ f32 xPos;
	/* 0x080 */ f32 yPos;
	/* 0x084 */ f32 zPos;
	/* 0x088 */ s8 unk_88[0xA4-0x88];
	/* 0x0A4 */ f32 floor;
	/* 0x0A8 */ s8 unk_A8[0xB8-0xA8];
	/* 0x0B8 */ f32 hSpeed;
	/* 0x0BC */ s8 unk_BC[0x4];
	/* 0x0C0 */ f32 yVelocity;
	/* 0x0C4 */ f32 yAccel;
	/* 0x0C8 */ s8 unk_C4[0xE6 - 0xC8];
	/* 0x0E6 */ s16 facing_angle;
	/* 0x0E8 */ s16 skew_angle;
	/* 0x0EA */ s8 unk_EA[0xEE - 0xEA];
	/* 0x0EE */ s16 next_facing_angle;
	/* 0x0F0 */ s8 unk_F0[0x110 - 0xF0];
	/* 0x110 */ s8 touching_object;
	/* 0x111 */ s8 unk_111[0x128 - 0x111];
	/* 0x128 */ s16 strong_kong_value;
	/* 0x12A */ s8 unk_12A[2];
	/* 0x12C */ s16 chunk;
	/* 0x12E */ s8 unk_12E[0x13C - 0x12E];
	/* 0x13C */ void* collision_queue_pointer;
	/* 0x140 */ s8 unk_140[0x147 - 0x140];
	/* 0x147 */ s8 hand_state;
	/* 0x148 */ s8 unk_148[0x154 - 0x148];
	/* 0x154 */ s8 control_state;
	/* 0x155 */ s8 control_state_progress;
	/* 0x156 */ s8 unk_156[0x18A-0x156];
	/* 0x18A */ s16 moving_angle;
	/* 0x18C */ s8 unk_18C[0x1B8-0x18C];
	/* 0x1B8 */ f32 velocity_cap;
	/* 0x1BC */ s8 unk_1BC[0x1D0-0x1BC];
	/* 0x1D0 */ s16 ostand_value;
	/* 0x1D2 */ s8 unk_1D2[0x208-0x1D2];
	/* 0x208 */ actorData* vehicle_actor_pointer;
	/* 0x20C */ s8 was_gun_out;
	/* 0x20D */ s8 unk_20D[0x23C - 0x20D];
	/* 0x23C */ s16 unk_rocketbarrel_value1;
	/* 0x23E */ s16 unk_rocketbarrel_value2;
	/* 0x240 */ s8 unk_240[0x284 - 0x240];
	/* 0x284 */ cameraData* camera_pointer;
	/* 0x288 */ s8 unk_288[0x323 - 0x288];
	/* 0x323 */ s8 unk_rocketbarrel_value3;
	/* 0x324 */ s8 unk_324[0x328 - 0x324];
	/* 0x328 */ actorData* krool_timer_pointer;
	/* 0x32C */ actorData* held_actor;
	/* 0x330 */ s8 unk_330[0x36F - 0x330];
	/* 0x36F */ s8 new_kong;
	/* 0x370 */ s32 strong_kong_ostand_bitfield;
} playerData; //size 0x630

typedef struct TextOverlay {
	/* 0x000 */ s8 unk_00[0x84];
	/* 0x004 */ //u16
	/* 0x006 */ //u16
	/* 0x008 */ //u8
	/* 0x009 */ //u8
	/* 0x054 */ //layer ID?
	/* 0x084 */ f32 style;
	/* 0x088 */ s8 unk_88[0x15F-0x88];
	/* 0x15F */ s8 opacity;
	/* 0x160 */ s8 unk_160[0x0A];
	/* 0x16A */ u8 red;
	/* 0x16B */ u8 green;
	/* 0x16C */ u8 blue;
	/* 0x16D */ s8 unk_16D[0x0B];
	/* 0x178 */ char* string;
} TextOverlay;

typedef struct Controller {
	/* 0x000 */ s16 Buttons;
	/* 0x002 */ s8 stickX;
	/* 0x003 */ s8 stickY;
} Controller;

typedef struct InventoryBase {
	/* 0x000 */ s16 StandardAmmo;
	/* 0x002 */ s16 HomingAmmo;
	/* 0x004 */ s16 Oranges;
	/* 0x006 */ s16 Crystals;
	/* 0x008 */ s16 Film;
	/* 0x00A */ s8 unk0A;
	/* 0x00B */ s8 Health;
	/* 0x00C */ s8 Melons;
} InventoryBase;

typedef struct RGB {
	/* 0x000 */ u8 red;
	/* 0x001 */ u8 green;
	/* 0x002 */ u8 blue;
} RGB;

typedef struct KongBase {
	/* 0x000 */ s8 special_moves;
	/* 0x001 */ s8 simian_slam;
	/* 0x002 */ s8 weapon_bitfield;
	/* 0x003 */ s8 ammo_belt;
	/* 0x004 */ s8 instrument_bitfield;
	/* 0x005 */ s8 unk_05[0x2];
	/* 0x007 */ s8 coins;
	/* 0x008 */ s16 instrument_energy;
	/* 0x00A */ s16 cb_count[0xE];
	/* 0x026 */ s16 tns_cb_count[0xE];
	/* 0x042 */ s16 gb_count[0xE];
} KongBase;

typedef struct SwapObjectData {
	/* 0x000 */ s8 unk_00[0x210];
	/* 0x210 */ floatPos cameraPositions[4];
	/* 0x240 */ s8 unk_21C[0x29C-0x240];
	/* 0x29C */ s16 action_type;
} SwapObjectData;

typedef struct ModelTwoData {
	/* 0x000 */ s8 unk_00[0x7C];
	/* 0x07C */ void* behaviour_pointer;
	/* 0x080 */ s8 unk_80[0x84-0x80];
	/* 0x084 */ s16 object_type;
	/* 0x086 */ s8 unk_86[0x4];
	/* 0x08A */ s16 object_id;
	/* 0x08C */ s8 unk_8C[0x4];
} ModelTwoData;

typedef struct WarpInfo {
	/* 0x000 */ s16 xPos;
	/* 0x002 */ s16 yPos;
	/* 0x004 */ s16 zPos;
	/* 0x006 */ u8 facing_angle; // (val / 255) * 4096
	/* 0x007 */ u8 camera_angle; // (player + 0x284)->0x15F
	/* 0x008 */ s8 will_autowalk;
	/* 0x009 */ s8 spawn_at_origin;
} WarpInfo;

typedef struct submapInfo {
	/* 0x000 */ s8 in_submap;
	/* 0x001 */ s8 unk_01;
	/* 0x003 */ s16 transition_properties_bitfield;
	/* 0x004 */ s8 unk_04[0x12-4];
	/* 0x012 */ s16 parent_map;
	/* 0x014 */ s8 parent_exit;
} submapInfo;

typedef struct SpawnerInfo {
	/* 0x000 */ u8 enemy_value;
	/* 0x001 */ s8 unk_01[0x14-0x1];
	/* 0x014 */ s8 respawnTimerInit;
	/* 0x015 */ s8 unk_15[0x18-0x15];
	/* 0x018 */ void* tied_actor;
	/* 0x01C */ s8 unk_1C[0x42-0x1C];
	/* 0x042 */ s8 spawn_state;
	/* 0x043 */ s8 unk_43[0x48 - 0x43];
} SpawnerInfo;

typedef struct loadedActorArr {
	/* 0x000 */ actorData* actor;
	/* 0x004 */ s32 unk_04;
} loadedActorArr;

typedef struct actorSpawnerData {
	/* 0x000 */ s8 unk_00[4];
	/* 0x004 */ floatPos positions;
	/* 0x010 */ s8 unk_10[0x44-0x10];
	/* 0x044 */ void* tied_actor;
	/* 0x048 */ s8 unk_48[0x5A-0x58];
	/* 0x05A */ s16 id;
	/* 0x05C */ s8 unk_5C[0x64-0x5C];
	/* 0x064 */ void* previous_spawner;
	/* 0x068 */ void* next_spawner;
} actorSpawnerData;

typedef struct HUDDisplay {
	/* 0x000 */ void* actual_count_pointer;
	/* 0x004 */	s16 hud_count;
	/* 0x006 */	s8 freeze_timer;
	/* 0x007 */	s8 counter_timer;
	/* 0x008 */	u32 screen_x;
	/* 0x00C */	u32 screen_y;
	/* 0x010 */ s8 unk_10[0x20-0x10];
	/* 0x020 */ u32 hud_state;
	/* 0x024 */ s32 unk_24;
	/* 0x028 */	void* counter_pointer;
	/* 0x02C */ s32 unk_2c;
} HUDDisplay;