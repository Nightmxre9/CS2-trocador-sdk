#define GET_HIGHEST_ENTITY_INDEX CS2_SDK_SIG("33 DB E8 ? ? ? ? 8B 08")
 
#define GET_BASE_ENTITY CS2_SDK_SIG("8B D3 E8 ? ? ? ? 48 8B F8 48 85 C0 74 76")
 
#define PRINT_SCHEMA_DETAILED_CLASS_LAYOUT \
    CS2_SDK_SIG("48 89 5C 24 ? 48 89 6C 24 ? 48 89 4C 24 ?")
 
#define SET_MESH_GROUP_MASK \
    CS2_SDK_SIG("E8 ? ? ? ? 48 8B 5C 24 ? 4C 8B 7C 24 ? 4C 8B 74 24 ?")
 
#define GET_INVENTORY_MANAGER \
    CS2_SDK_SIG("E8 ? ? ? ? 48 63 BB ? ? ? ? 48 8D 68 28 83 FF FF")
 
#define CREATE_SHARED_OBJECT_SUBCLASS_ECON_ITEM \
    CS2_SDK_SIG(                                \
        "48 83 EC 28 B9 ? ? ? ? E8 ? ? ? ? 48 85 C0 74 3D 48 8D 0D ? ? ? ?")
 
#define GET_GC_CLIENT_SYSTEM CS2_SDK_SIG("E8 ? ? ? ? 48 8B 4F 10 8B 1D ? ? ? ?")
 
#define CREATE_BASE_TYPE_CACHE CS2_SDK_SIG("E8 ? ? ? ? 33 C9 8B D1")
 
#define FIND_SO_CACHE CS2_SDK_SIG("E8 ? ? ? ? 48 8B F0 48 85 C0 74 0E 4C 8B C3")
 
#define GET_LOCAL_PLAYER_CONTROLLER CS2_SDK_SIG("E8 ? ? ? ? 49 89 47 08")
 
#define SET_DYNAMIC_ATTRIBUTE_VALUE_UINT                                       \
    CS2_SDK_SIG(                                                               \
        "E9 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC 49 8B C0 48 " \
        "8B CA 48 8B D0")
 
#define SET_MODEL CS2_SDK_SIG("E8 ? ? ? ? F3 0F 10 4C 3B ?")
 
#define COMPUTE_HITBOX_SURROUNDING_BOX CS2_SDK_SIG("E9 ? ? ? ? F6 43 5B FD")
 
#define MOUSE_INPUT_ENABLED \
    CS2_SDK_SIG("40 53 48 83 EC 20 80 B9 ? ? ? ? ? 48 8B D9 75 78")
 
#define GET_MATRICES_FOR_VIEW CS2_SDK_SIG("40 53 48 81 EC ? ? ? ? 49 8B C1")
 
#define FIRE_EVENT_CLIENT_SIDE \
    CS2_SDK_SIG("48 89 5C 24 ? 56 57 41 54 48 83 EC 30 48 8B F2")
 
#define ADD_STATTRAK_ENTITY CS2_SDK_SIG("4C 8B DC 55 41 55 49 8D 6B A8")
 
#define ADD_NAMETAG_ENTITY \
    CS2_SDK_SIG("40 55 41 56 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 8B 51 04")
 
#define IS_PAINT_KIT_USING_LEGACY_MODEL \
    CS2_SDK_SIG("48 8B C4 48 89 70 20 55 48 8D 68 A1")