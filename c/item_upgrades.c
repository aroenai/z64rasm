#include "item_upgrades.h"

#include "z64.h"

uint16_t no_upgrade(z64_file_t *save, uint16_t item_id) {
    return item_id;
}

uint16_t hookshot_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->items[Z64_SLOT_HOOKSHOT]) {
        case -1: return 0x08; // Hookshot
        default: return 0x09; // Longshot
    }
}

uint16_t strength_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->strength_upgrade) {
        case 0: return 0x54; // Goron Bracelet
        case 1: return 0x35; // Silver Gauntlets
        default: return 0x36; // Gold Gauntlets
    }
}

uint16_t bomb_bag_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->bomb_bag) {
        case 0: return 0x32; // Bomb Bag
        case 1: return 0x33; // Bigger Bomb Bag
        default: return 0x34; // Biggest Bomb Bag
    }
}

uint16_t bow_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->quiver) {
        case 0: return 0x04; // Bow
        case 1: return 0x30; // Big Quiver
        default: return 0x31; // Biggest Quiver
    }
}

uint16_t slingshot_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->bullet_bag) {
        case 0: return 0x05; // Slingshot
        case 1: return 0x60; // Bullet Bag (40)
        default: return 0x7B; // Bullet Bag (50)
    }
}

uint16_t wallet_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->wallet) {
        case 0: return 0x45; // Adult's Wallet
        case 1: return 0x46; // Giant's Wallet
        default: return item_id; // Tycoon's Wallet (unchanged)
    }
}

uint16_t scale_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->diving_upgrade) {
        case 0: return 0x37; // Silver Scale
        default: return 0x38; // Gold Scale
    }
}

uint16_t nut_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->nut_upgrade) {
        case 0: return 0x79; // 30 Nuts
        default: return 0x7A; // 40 Nuts
    }
}

uint16_t stick_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->stick_upgrade) {
        case 0: return 0x77; // 20 Sticks
        default: return 0x78; // 30 Sticks
    }
}

uint16_t magic_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->magic_capacity_set) {
        case 0: return 0xC0; // Single Magic
        default: return 0xC1; // Double Magic
    }
}

uint16_t bombchu_upgrade(z64_file_t *save, uint16_t item_id) {
    if (save->items[Z64_SLOT_BOMBCHU] == -1) {
        return 0x6B; // Bombchu 20 pack
    }
    if (save->ammo[8] <= 5) {
        return 0x03; // Bombchu 10 pack
    }
    return 0x6A; // Bombchu 5 pack
}

uint16_t ocarina_upgrade(z64_file_t *save, uint16_t item_id) {
    switch (save->items[Z64_SLOT_OCARINA]) {
        case -1: return item_id; // Fairy Ocarina (unchanged)
        default: return 0x0C; // Ocarina of Time
    }
}

uint16_t arrows_to_rupee(z64_file_t *save, uint16_t item_id) {
    return save->quiver ? item_id : 0x4D; // Blue Rupee
}

uint16_t bombs_to_rupee(z64_file_t *save, uint16_t item_id) {
    return save->bomb_bag ? item_id : 0x4D; // Blue Rupee
}

uint16_t seeds_to_rupee(z64_file_t *save, uint16_t item_id) {
    return save->bullet_bag ? item_id : 0x4D; // Blue Rupee
}
