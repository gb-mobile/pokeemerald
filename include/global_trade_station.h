#ifndef GUARD_GTS_MENU_H
#define GUARD_GTS_MENU_H
#define MAX_MONS_ON_SCREEN 4

u16 GetGTSBaseBlock(void);
void CB2_MysteryGiftEReader(void);
void PrintGTSTopMenu(bool8 isJapanese, bool32 usePickOkCancel);
void GTS_DrawCheckerboardPattern(u32 bg);
void MainCB_GTSFreeAllBuffersAndReturnToInitTitleScreen(void);
bool32 PrintGTSMenuMessage(u8 *textState, const u8 *str);
void GTSAddTextPrinterToWindow1(const u8 *src);
void CB2_InitEReader(void);
void CB2_InitGlobalTradeStation(void);
void GTS_DrawTextBorder(u8 windowId);
s8 DoGTSYesNo(u8 *textState, u16 *windowId, bool8 yesNoBoxPlacement, const u8 *str);

struct PokedexListItem
{
    u16 dexNum;
    u16 seen:1;
    u16 owned:1;
};

struct GTSResult
{
    u32 checksum;
    u32 pid;
    struct BoxPokemon boxmon;
    u16 dexNum;
    u8 gender;
    u8 level;
    u16 natDexRequest;
    u8 genderRequest;
    u8 minLevel;
    u8 maxLevel;
    u8 trainerGender;
    u16 trainerID;
    u16 secretID;
    char OTName[7];
    u8 country;
    u8 region;
    u8 trainerClass;
    bool8 isExchanged;
    u16 gameVersion;
    u16 romHackID;
    u16 romHackVersion;
    u8 language;
};

struct GTSPokedexView
{
    struct PokedexListItem pokedexList[NATIONAL_DEX_COUNT + 1];
    u16 pokemonListCount; //keep
    u16 selectedPokemon;
    u16 offerPokemon;
    s16 dexMode;
    u16 windowid;
    u16 dexOrder;
    u16 monSpriteIds[MAX_MONS_ON_SCREEN];
    u16 cursorRelPos;
    u8 atTop;
    u8 atBottom;
    u8 initialVOffset;
    u8 scrollTimer;
    u8 scrollDirection;
    s16 listVOffset;
    s16 listMovingVOffset;
    u16 scrollMonIncrement;
    u16 maxScrollTimer;
    u16 scrollSpeed;
    u8 numResults;
    u8 currentPage; //keep
    struct GTSResult searchResult[7];
};

//extern EWRAM_DATA struct GTSPokedexView *sGTSPokedexView;

#endif // GUARD_GTS_MENU_H