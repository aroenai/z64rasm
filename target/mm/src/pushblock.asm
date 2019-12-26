misc_get_push_block_speed_hook:
    addiu   sp, sp, -0x10

    sw      ra, 0x0000 (sp)
    sw      at, 0x0004 (sp)
    sw      a0, 0x0008 (sp)

    jal     misc_get_push_block_speed
    sw      a1, 0x000C (sp)

    ; Place return value from F0 into F6
    mfc1    v0, f0
    mtc1    v0, f6

    lw      ra, 0x0000 (sp)
    lw      at, 0x0004 (sp)
    lw      a0, 0x0008 (sp)
    lw      a1, 0x000C (sp)

    ; Displaced code
    mtc1    r0, f4

    jr      ra
    addiu   sp, sp, 0x10

misc_get_iceblock_push_speed_hook:
    addiu   sp, sp, -0x10
    sw      ra, 0x0000 (sp)
    swc1    f0, 0x0004 (sp)

    jal     misc_get_iceblock_push_speed
    addiu   a2, sp, 0x8

    ; Move return values to F6 and F18 from stack
    lwc1    f6, 0x0008 (sp)
    lwc1    f18, 0x000C (sp)

    lw      ra, 0x0000 (sp)
    lwc1    f0, 0x0004 (sp)

    jr      ra
    addiu   sp, sp, 0x10

misc_get_great_bay_temple_faucet_speed_hook:
    addiu   sp, sp, -0x10

    sw      ra, 0x0000 (sp)
    sw      a0, 0x0004 (sp)

    jal     misc_get_great_bay_temple_faucet_speed
    sw      a1, 0x0008 (sp)

    ; Place bitfield results into T8 and T9
    srl     t8, v0, 16
    andi    t9, v0, 0xFFFF

    lw      ra, 0x0000 (sp)
    lw      a0, 0x0004 (sp)
    lw      a1, 0x0008 (sp)

    ; Displaced code
    or      s0, a0, r0

    jr      ra
    addiu   sp, sp, 0x10
