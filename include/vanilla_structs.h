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

typedef struct collected_item_struct {
	/* 0x000 */ short id;
	/* 0x002 */ short obj_type;
	/* 0x004 */ char unk_04[0x1A - 0x4];
	/* 0x01A */ unsigned char is_homing;
	/* 0x01B */ char unk_1B;
	/* 0x01C */ void* next_item;
} collected_item_struct;

typedef struct buttons {
	unsigned char a : 1; // 0x8000
	unsigned char b : 1; // 0x4000
	unsigned char z : 1; // 0x2000
	unsigned char start : 1; // 0x1000
	unsigned char d_up : 1; // 0x0800
	unsigned char d_down : 1; // 0x0400
	unsigned char d_left : 1; // 0x0200
	unsigned char d_right : 1; // 0x0100
	unsigned char unused_0 : 1; // 0x0080
	unsigned char unused_1 : 1; // 0x0040
	unsigned char l : 1; // 0x0020
	unsigned char r : 1; // 0x0010
	unsigned char c_up : 1; // 0x0008
	unsigned char c_down : 1; // 0x0004
	unsigned char c_left : 1; // 0x0002
	unsigned char c_right : 1; // 0x0001
} buttons;

typedef struct Controller {
	/* 0x000 */ buttons Buttons;
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
	/* 0x29E */ s8 unk_29E[0x2C0-0x29E];
	/* 0x2C0 */ s8 size;
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

typedef struct hudData {
	/* 0x000 */ HUDDisplay item[0xE];
} hudData;

typedef struct map_bitfield {
	unsigned char test_map : 1;
	unsigned char funkys_store : 1;
	unsigned char dk_arcade : 1;
	unsigned char k_rool_barrel_lankys_maze : 1;
	unsigned char jungle_japes_mountain : 1;
	unsigned char crankys_lab : 1;
	unsigned char jungle_japes_minecart : 1;
	unsigned char jungle_japes : 1;
	unsigned char jungle_japes_army_dillo : 1;
	unsigned char jetpac : 1;
	unsigned char kremling_kosh_very_easy : 1;
	unsigned char stealthy_snoop_normal_no_logo : 1;
	unsigned char jungle_japes_shell : 1;
	unsigned char jungle_japes_lankys_cave : 1;
	unsigned char angry_aztec_beetle_race : 1;
	unsigned char snides_hq : 1;
	unsigned char angry_aztec_tinys_temple : 1;
	unsigned char hideout_helm : 1;
	unsigned char teetering_turtle_trouble_very_easy : 1;
	unsigned char angry_aztec_five_door_temple_dk : 1;
	unsigned char angry_aztec_llama_temple : 1;
	unsigned char angry_aztec_five_door_temple_diddy : 1;
	unsigned char angry_aztec_five_door_temple_tiny : 1;
	unsigned char angry_aztec_five_door_temple_lanky : 1;
	unsigned char angry_aztec_five_door_temple_chunky : 1;
	unsigned char candys_music_shop : 1;
	unsigned char frantic_factory : 1;
	unsigned char frantic_factory_car_race : 1;
	unsigned char hideout_helm_level_intros_game_over : 1;
	unsigned char frantic_factory_power_shed : 1;
	unsigned char gloomy_galleon : 1;
	unsigned char gloomy_galleon_k_rools_ship : 1;
	unsigned char batty_barrel_bandit_very_easy : 1;
	unsigned char jungle_japes_chunkys_cave : 1;
	unsigned char dk_isles_overworld : 1;
	unsigned char k_rool_barrel_dks_target_game : 1;
	unsigned char frantic_factory_crusher_room : 1;
	unsigned char jungle_japes_barrel_blast : 1;
	unsigned char angry_aztec : 1;
	unsigned char gloomy_galleon_seal_race : 1;
	unsigned char nintendo_logo : 1;
	unsigned char angry_aztec_barrel_blast : 1;
	unsigned char troff_n_scoff : 1;
	unsigned char gloomy_galleon_shipwreck_diddy_lanky_chunky : 1;
	unsigned char gloomy_galleon_treasure_chest : 1;
	unsigned char gloomy_galleon_mermaid : 1;
	unsigned char gloomy_galleon_shipwreck_dk_tiny : 1;
	unsigned char gloomy_galleon_shipwreck_lanky_tiny : 1;
	unsigned char fungi_forest : 1;
	unsigned char gloomy_galleon_lighthouse : 1;
	unsigned char k_rool_barrel_tinys_mushroom_game : 1;
	unsigned char gloomy_galleon_mechanical_fish : 1;
	unsigned char fungi_forest_ant_hill : 1;
	unsigned char battle_arena_beaver_brawl : 1;
	unsigned char gloomy_galleon_barrel_blast : 1;
	unsigned char fungi_forest_minecart : 1;
	unsigned char fungi_forest_diddys_barn : 1;
	unsigned char fungi_forest_diddys_attic : 1;
	unsigned char fungi_forest_lankys_attic : 1;
	unsigned char fungi_forest_dks_barn : 1;
	unsigned char fungi_forest_spider : 1;
	unsigned char fungi_forest_front_part_of_mill : 1;
	unsigned char fungi_forest_rear_part_of_mill : 1;
	unsigned char fungi_forest_mushroom_puzzle : 1;
	unsigned char fungi_forest_giant_mushroom : 1;
	unsigned char stealthy_snoop_normal : 1;
	unsigned char mad_maze_maul_hard : 1;
	unsigned char stash_snatch_normal : 1;
	unsigned char mad_maze_maul_easy : 1;
	unsigned char mad_maze_maul_normal : 1;
	unsigned char fungi_forest_mushroom_leap : 1;
	unsigned char fungi_forest_shooting_game : 1;
	unsigned char crystal_caves : 1;
	unsigned char battle_arena_kritter_karnage : 1;
	unsigned char stash_snatch_easy : 1;
	unsigned char stash_snatch_hard : 1;
	unsigned char dk_rap : 1;
	unsigned char minecart_mayhem_easy : 1;
	unsigned char busy_barrel_barrage_easy : 1;
	unsigned char busy_barrel_barrage_normal : 1;
	unsigned char main_menu : 1;
	unsigned char title_screen_not_for_resale_version : 1;
	unsigned char crystal_caves_beetle_race : 1;
	unsigned char fungi_forest_dogadon : 1;
	unsigned char crystal_caves_igloo_tiny : 1;
	unsigned char crystal_caves_igloo_lanky : 1;
	unsigned char crystal_caves_igloo_dk : 1;
	unsigned char creepy_castle : 1;
	unsigned char creepy_castle_ballroom : 1;
	unsigned char crystal_caves_rotating_room : 1;
	unsigned char crystal_caves_shack_chunky : 1;
	unsigned char crystal_caves_shack_dk : 1;
	unsigned char crystal_caves_shack_diddy_middle_part : 1;
	unsigned char crystal_caves_shack_tiny : 1;
	unsigned char crystal_caves_lankys_hut : 1;
	unsigned char crystal_caves_igloo_chunky : 1;
	unsigned char splish_splash_salvage_normal : 1;
	unsigned char k_lumsy : 1;
	unsigned char crystal_caves_ice_castle : 1;
	unsigned char speedy_swing_sortie_easy : 1;
	unsigned char crystal_caves_igloo_diddy : 1;
	unsigned char krazy_kong_klamour_easy : 1;
	unsigned char big_bug_bash_very_easy : 1;
	unsigned char searchlight_seek_very_easy : 1;
	unsigned char beaver_bother_easy : 1;
	unsigned char creepy_castle_tower : 1;
	unsigned char creepy_castle_minecart : 1;
	unsigned char kong_battle_battle_arena : 1;
	unsigned char creepy_castle_crypt_lanky_tiny : 1;
	unsigned char kong_battle_arena_1 : 1;
	unsigned char frantic_factory_barrel_blast : 1;
	unsigned char gloomy_galleon_pufftoss : 1;
	unsigned char creepy_castle_crypt_dk_diddy_chunky : 1;
	unsigned char creepy_castle_museum : 1;
	unsigned char creepy_castle_library : 1;
	unsigned char kremling_kosh_easy : 1;
	unsigned char kremling_kosh_normal : 1;
	unsigned char kremling_kosh_hard : 1;
	unsigned char teetering_turtle_trouble_easy : 1;
	unsigned char teetering_turtle_trouble_normal : 1;
	unsigned char teetering_turtle_trouble_hard : 1;
	unsigned char batty_barrel_bandit_easy : 1;
	unsigned char batty_barrel_bandit_normal : 1;
	unsigned char batty_barrel_bandit_hard : 1;
	unsigned char mad_maze_maul_insane : 1;
	unsigned char stash_snatch_insane : 1;
	unsigned char stealthy_snoop_very_easy : 1;
	unsigned char stealthy_snoop_easy : 1;
	unsigned char stealthy_snoop_hard : 1;
	unsigned char minecart_mayhem_normal : 1;
	unsigned char minecart_mayhem_hard : 1;
	unsigned char busy_barrel_barrage_hard : 1;
	unsigned char splish_splash_salvage_hard : 1;
	unsigned char splish_splash_salvage_easy : 1;
	unsigned char speedy_swing_sortie_normal : 1;
	unsigned char speedy_swing_sortie_hard : 1;
	unsigned char beaver_bother_normal : 1;
	unsigned char beaver_bother_hard : 1;
	unsigned char searchlight_seek_easy : 1;
	unsigned char searchlight_seek_normal : 1;
	unsigned char searchlight_seek_hard : 1;
	unsigned char krazy_kong_klamour_normal : 1;
	unsigned char krazy_kong_klamour_hard : 1;
	unsigned char krazy_kong_klamour_insane : 1;
	unsigned char peril_path_panic_very_easy : 1;
	unsigned char peril_path_panic_easy : 1;
	unsigned char peril_path_panic_normal : 1;
	unsigned char peril_path_panic_hard : 1;
	unsigned char big_bug_bash_easy : 1;
	unsigned char big_bug_bash_normal : 1;
	unsigned char big_bug_bash_hard : 1;
	unsigned char creepy_castle_dungeon : 1;
	unsigned char hideout_helm_intro_story : 1;
	unsigned char dk_isles_dk_theatre : 1;
	unsigned char frantic_factory_mad_jack : 1;
	unsigned char battle_arena_arena_ambush : 1;
	unsigned char battle_arena_more_kritter_karnage : 1;
	unsigned char battle_arena_forest_fracas : 1;
	unsigned char battle_arena_bish_bash_brawl : 1;
	unsigned char battle_arena_kamikaze_kremlings : 1;
	unsigned char battle_arena_plinth_panic : 1;
	unsigned char battle_arena_pinnacle_palaver : 1;
	unsigned char battle_arena_shockwave_showdown : 1;
	unsigned char creepy_castle_basement : 1;
	unsigned char creepy_castle_tree : 1;
	unsigned char k_rool_barrel_diddys_kremling_game : 1;
	unsigned char creepy_castle_chunkys_toolshed : 1;
	unsigned char creepy_castle_trash_can : 1;
	unsigned char creepy_castle_greenhouse : 1;
	unsigned char jungle_japes_lobby : 1;
	unsigned char hideout_helm_lobby : 1;
	unsigned char dks_house : 1;
	unsigned char rock_intro_story : 1;
	unsigned char angry_aztec_lobby : 1;
	unsigned char gloomy_galleon_lobby : 1;
	unsigned char frantic_factory_lobby : 1;
	unsigned char training_grounds : 1;
	unsigned char dive_barrel : 1;
	unsigned char fungi_forest_lobby : 1;
	unsigned char gloomy_galleon_submarine : 1;
	unsigned char orange_barrel : 1;
	unsigned char barrel_barrel : 1;
	unsigned char vine_barrel : 1;
	unsigned char creepy_castle_crypt : 1;
	unsigned char enguarde_arena : 1;
	unsigned char creepy_castle_car_race : 1;
	unsigned char crystal_caves_barrel_blast : 1;
	unsigned char creepy_castle_barrel_blast : 1;
	unsigned char fungi_forest_barrel_blast : 1;
	unsigned char fairy_island : 1;
	unsigned char kong_battle_arena_2 : 1;
	unsigned char rambi_arena : 1;
	unsigned char kong_battle_arena_3 : 1;
	unsigned char creepy_castle_lobby : 1;
	unsigned char crystal_caves_lobby : 1;
	unsigned char dk_isles_snides_room : 1;
	unsigned char crystal_caves_army_dillo : 1;
	unsigned char angry_aztec_dogadon : 1;
	unsigned char training_grounds_end_sequence : 1;
	unsigned char creepy_castle_king_kut_out : 1;
	unsigned char crystal_caves_shack_diddy_upper_part : 1;
	unsigned char k_rool_barrel_diddys_rocketbarrel_game : 1;
	unsigned char k_rool_barrel_lankys_shooting_game : 1;
	unsigned char k_rool_fight_dk_phase : 1;
	unsigned char k_rool_fight_diddy_phase : 1;
	unsigned char k_rool_fight_lanky_phase : 1;
	unsigned char k_rool_fight_tiny_phase : 1;
	unsigned char k_rool_fight_chunky_phase : 1;
	unsigned char bloopers_ending : 1;
	unsigned char k_rool_barrel_chunkys_hidden_kremling_game : 1;
	unsigned char k_rool_barrel_tinys_pony_tail_twirl_game : 1;
	unsigned char k_rool_barrel_chunkys_shooting_game : 1;
	unsigned char k_rool_barrel_dks_rambi_game : 1;
	unsigned char k_lumsy_ending : 1;
	unsigned char k_rools_shoe : 1;
	unsigned char k_rools_arena : 1;
} map_bitfield;

typedef struct movement_bitfield {
	unsigned char null_state : 1;
	unsigned char idle_enemy : 1;
	unsigned char first_person_camera : 1;
	unsigned char first_person_camera_water : 1;
	unsigned char fairy_camera : 1;
	unsigned char fairy_camera_water : 1;
	unsigned char locked_bonus_barrel_0x6 : 1;
	unsigned char minecart_idle : 1;
	unsigned char minecart_crouch : 1;
	unsigned char minecart_jump : 1;
	unsigned char minecart_left : 1;
	unsigned char minecart_right : 1;
	unsigned char idle : 1;
	unsigned char walking : 1;
	unsigned char skidding : 1;
	unsigned char sliding_beetle_race : 1;
	unsigned char sliding_beetle_race_left : 1;
	unsigned char sliding_beetle_race_right : 1;
	unsigned char sliding_beetle_race_forward : 1;
	unsigned char sliding_beetle_race_back : 1;
	unsigned char jumping_beetle_race : 1;
	unsigned char slipping : 1;
	unsigned char slipping_helm_slope : 1;
	unsigned char jumping : 1;
	unsigned char baboon_blast_pad : 1;
	unsigned char bouncing_mushroom : 1;
	unsigned char double_jump : 1;
	unsigned char simian_spring : 1;
	unsigned char simian_slam : 1;
	unsigned char long_jumping : 1;
	unsigned char falling : 1;
	unsigned char falling_gun : 1;
	unsigned char falling_or_splat : 1;
	unsigned char falling_beetle_race : 1;
	unsigned char pony_tail_twirl : 1;
	unsigned char attacking_enemy : 1;
	unsigned char primate_punch : 1;
	unsigned char attacking_enemy_0x25 : 1;
	unsigned char ground_attack : 1;
	unsigned char attacking_enemy_0x27 : 1;
	unsigned char ground_attack_final : 1;
	unsigned char moving_ground_attack : 1;
	unsigned char aerial_attack : 1;
	unsigned char rolling : 1;
	unsigned char throwing_orange : 1;
	unsigned char shockwave : 1;
	unsigned char chimpy_charge : 1;
	unsigned char charging_rambi : 1;
	unsigned char bouncing : 1;
	unsigned char damaged : 1;
	unsigned char stunlocked_kasplat : 1;
	unsigned char damaged_mad_jack : 1;
	unsigned char unknown_0x34 : 1;
	unsigned char damaged_klump_knockback : 1;
	unsigned char death : 1;
	unsigned char damaged_underwater : 1;
	unsigned char damaged_vehicle : 1;
	unsigned char shrinking : 1;
	unsigned char unknown_0x3a : 1;
	unsigned char death_dogadon : 1;
	unsigned char crouching : 1;
	unsigned char uncrouching : 1;
	unsigned char backflip : 1;
	unsigned char entering_orangstand : 1;
	unsigned char orangstand : 1;
	unsigned char jumping_orangstand : 1;
	unsigned char barrel_tag_barrel : 1;
	unsigned char barrel_underwater : 1;
	unsigned char baboon_blast_shot : 1;
	unsigned char cannon_shot : 1;
	unsigned char pushing_object : 1;
	unsigned char picking_up_object : 1;
	unsigned char idle_carrying_object : 1;
	unsigned char walking_carrying_object : 1;
	unsigned char dropping_object : 1;
	unsigned char throwing_object : 1;
	unsigned char jumping_carrying_object : 1;
	unsigned char throwing_object_air : 1;
	unsigned char surface_swimming : 1;
	unsigned char underwater : 1;
	unsigned char leaving_water : 1;
	unsigned char jumping_water : 1;
	unsigned char bananaporter : 1;
	unsigned char monkeyport : 1;
	unsigned char bananaport_multiplayer : 1;
	unsigned char unknown_0x55 : 1;
	unsigned char locked_funky_and_candy : 1;
	unsigned char swinging_on_vine : 1;
	unsigned char leaving_vine : 1;
	unsigned char climbing_tree : 1;
	unsigned char leaving_tree : 1;
	unsigned char grabbed_ledge : 1;
	unsigned char pulling_up_on_ledge : 1;
	unsigned char idle_gun : 1;
	unsigned char walking_gun : 1;
	unsigned char putting_away_gun : 1;
	unsigned char pulling_out_gun : 1;
	unsigned char jumping_gun : 1;
	unsigned char aiming_gun : 1;
	unsigned char rocketbarrel : 1;
	unsigned char taking_photo : 1;
	unsigned char taking_photo_underwater : 1;
	unsigned char damaged_tnt_barrels : 1;
	unsigned char instrument : 1;
	unsigned char unknown_0x68 : 1;
	unsigned char car_race : 1;
	unsigned char learning_gun : 1;
	unsigned char locked_bonus_barrel_0x6b : 1;
	unsigned char feeding_tns : 1;
	unsigned char boat : 1;
	unsigned char baboon_balloon : 1;
	unsigned char updraft : 1;
	unsigned char gb_dance : 1;
	unsigned char key_dance : 1;
	unsigned char crown_dance : 1;
	unsigned char loss_dance : 1;
	unsigned char victory_dance : 1;
	unsigned char vehicle_castle_car_race : 1;
	unsigned char entering_battle_crown : 1;
	unsigned char locked_cutscenes : 1;
	unsigned char gorilla_grab : 1;
	unsigned char learning_move : 1;
	unsigned char locked_car_race_loss : 1;
	unsigned char locked_beetle_race_loss : 1;
	unsigned char trapped : 1;
	unsigned char klaptrap_kong : 1;
	unsigned char surface_swimming_enguarde : 1;
	unsigned char underwater_enguarde : 1;
	unsigned char attacking_enguarde_surface : 1;
	unsigned char attacking_enguarde : 1;
	unsigned char leaving_water_enguarde : 1;
	unsigned char fairy_refill : 1;
	unsigned char unknown_0x84 : 1;
	unsigned char main_menu : 1;
	unsigned char entering_main_menu : 1;
	unsigned char entering_portal : 1;
	unsigned char exiting_portal : 1;
} movement_bitfield;

typedef struct stack_trace_address_struct {
	/* 0x000 */ void* address;
	/* 0x004 */ int used;
} stack_trace_address_struct;