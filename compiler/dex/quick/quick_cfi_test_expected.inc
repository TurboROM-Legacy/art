static constexpr uint8_t expected_asm_kThumb2[] = {
    0x60, 0xB5, 0x2D, 0xED, 0x02, 0x8A, 0x8B, 0xB0, 0x00, 0x90, 0x0B, 0xB0,
    0xBD, 0xEC, 0x02, 0x8A, 0x60, 0xBD, 0x00, 0x00,
};
static constexpr uint8_t expected_cfi_kThumb2[] = {
    0x42, 0x0E, 0x0C, 0x85, 0x03, 0x86, 0x02, 0x8E, 0x01, 0x44, 0x0E, 0x14,
    0x05, 0x50, 0x05, 0x05, 0x51, 0x04, 0x42, 0x0E, 0x40, 0x42, 0x0A, 0x42,
    0x0E, 0x14, 0x44, 0x0E, 0x0C, 0x06, 0x50, 0x06, 0x51, 0x44, 0x0B, 0x0E,
    0x40,
};
// 0x00000000: push {r5, r6, lr}
// 0x00000002: .cfi_def_cfa_offset: 12
// 0x00000002: .cfi_offset: r5 at cfa-12
// 0x00000002: .cfi_offset: r6 at cfa-8
// 0x00000002: .cfi_offset: r14 at cfa-4
// 0x00000002: vpush.f32 {s16-s17}
// 0x00000006: .cfi_def_cfa_offset: 20
// 0x00000006: .cfi_offset_extended: r80 at cfa-20
// 0x00000006: .cfi_offset_extended: r81 at cfa-16
// 0x00000006: sub sp, sp, #44
// 0x00000008: .cfi_def_cfa_offset: 64
// 0x00000008: str r0, [sp, #0]
// 0x0000000a: .cfi_remember_state
// 0x0000000a: add sp, sp, #44
// 0x0000000c: .cfi_def_cfa_offset: 20
// 0x0000000c: vpop.f32 {s16-s17}
// 0x00000010: .cfi_def_cfa_offset: 12
// 0x00000010: .cfi_restore_extended: r80
// 0x00000010: .cfi_restore_extended: r81
// 0x00000010: pop {r5, r6, pc}
// 0x00000012: lsls r0, r0, #0
// 0x00000014: .cfi_restore_state
// 0x00000014: .cfi_def_cfa_offset: 64

static constexpr uint8_t expected_asm_kArm64[] = {
    0xFF, 0x03, 0x01, 0xD1, 0xE8, 0xA7, 0x01, 0x6D, 0xF3, 0xD3, 0x02, 0xA9,
    0xFE, 0x1F, 0x00, 0xF9, 0xE0, 0x03, 0x00, 0xB9, 0xE8, 0xA7, 0x41, 0x6D,
    0xF3, 0xD3, 0x42, 0xA9, 0xFE, 0x1F, 0x40, 0xF9, 0xFF, 0x03, 0x01, 0x91,
    0xC0, 0x03, 0x5F, 0xD6,
};
static constexpr uint8_t expected_cfi_kArm64[] = {
    0x44, 0x0E, 0x40, 0x44, 0x05, 0x48, 0x0A, 0x05, 0x49, 0x08, 0x44, 0x93,
    0x06, 0x94, 0x04, 0x44, 0x9E, 0x02, 0x44, 0x0A, 0x44, 0x06, 0x48, 0x06,
    0x49, 0x44, 0xD3, 0xD4, 0x44, 0xDE, 0x44, 0x0E, 0x00, 0x44, 0x0B, 0x0E,
    0x40,
};
// 0x00000000: sub sp, sp, #0x40 (64)
// 0x00000004: .cfi_def_cfa_offset: 64
// 0x00000004: stp d8, d9, [sp, #24]
// 0x00000008: .cfi_offset_extended: r72 at cfa-40
// 0x00000008: .cfi_offset_extended: r73 at cfa-32
// 0x00000008: stp x19, x20, [sp, #40]
// 0x0000000c: .cfi_offset: r19 at cfa-24
// 0x0000000c: .cfi_offset: r20 at cfa-16
// 0x0000000c: str lr, [sp, #56]
// 0x00000010: .cfi_offset: r30 at cfa-8
// 0x00000010: str w0, [sp]
// 0x00000014: .cfi_remember_state
// 0x00000014: ldp d8, d9, [sp, #24]
// 0x00000018: .cfi_restore_extended: r72
// 0x00000018: .cfi_restore_extended: r73
// 0x00000018: ldp x19, x20, [sp, #40]
// 0x0000001c: .cfi_restore: r19
// 0x0000001c: .cfi_restore: r20
// 0x0000001c: ldr lr, [sp, #56]
// 0x00000020: .cfi_restore: r30
// 0x00000020: add sp, sp, #0x40 (64)
// 0x00000024: .cfi_def_cfa_offset: 0
// 0x00000024: ret
// 0x00000028: .cfi_restore_state
// 0x00000028: .cfi_def_cfa_offset: 64

static constexpr uint8_t expected_asm_kX86[] = {
    0x83, 0xEC, 0x3C, 0x89, 0x6C, 0x24, 0x34, 0x89, 0x74, 0x24, 0x38, 0x89,
    0x04, 0x24, 0x8B, 0x6C, 0x24, 0x34, 0x8B, 0x74, 0x24, 0x38, 0x83, 0xC4,
    0x3C, 0xC3, 0x00, 0x00,
};
static constexpr uint8_t expected_cfi_kX86[] = {
    0x43, 0x0E, 0x40, 0x44, 0x85, 0x03, 0x44, 0x86, 0x02, 0x43, 0x0A, 0x44,
    0xC5, 0x44, 0xC6, 0x43, 0x0E, 0x04, 0x43, 0x0B, 0x0E, 0x40,
};
// 0x00000000: sub esp, 60
// 0x00000003: .cfi_def_cfa_offset: 64
// 0x00000003: mov [esp + 52], ebp
// 0x00000007: .cfi_offset: r5 at cfa-12
// 0x00000007: mov [esp + 56], esi
// 0x0000000b: .cfi_offset: r6 at cfa-8
// 0x0000000b: mov [esp], eax
// 0x0000000e: .cfi_remember_state
// 0x0000000e: mov ebp, [esp + 52]
// 0x00000012: .cfi_restore: r5
// 0x00000012: mov esi, [esp + 56]
// 0x00000016: .cfi_restore: r6
// 0x00000016: add esp, 60
// 0x00000019: .cfi_def_cfa_offset: 4
// 0x00000019: ret
// 0x0000001a: addb [eax], al
// 0x0000001c: .cfi_restore_state
// 0x0000001c: .cfi_def_cfa_offset: 64

static constexpr uint8_t expected_asm_kX86_64[] = {
    0x48, 0x83, 0xEC, 0x38, 0x48, 0x89, 0x5C, 0x24, 0x28, 0x48, 0x89, 0x6C,
    0x24, 0x30, 0xF2, 0x44, 0x0F, 0x11, 0x64, 0x24, 0x18, 0xF2, 0x44, 0x0F,
    0x11, 0x6C, 0x24, 0x20, 0x48, 0x8B, 0xC7, 0x89, 0x3C, 0x24, 0x48, 0x8B,
    0x5C, 0x24, 0x28, 0x48, 0x8B, 0x6C, 0x24, 0x30, 0xF2, 0x44, 0x0F, 0x10,
    0x64, 0x24, 0x18, 0xF2, 0x44, 0x0F, 0x10, 0x6C, 0x24, 0x20, 0x48, 0x83,
    0xC4, 0x38, 0xC3, 0x00,
};
static constexpr uint8_t expected_cfi_kX86_64[] = {
    0x44, 0x0E, 0x40, 0x45, 0x83, 0x06, 0x45, 0x86, 0x04, 0x47, 0x9D, 0x0A,
    0x47, 0x9E, 0x08, 0x46, 0x0A, 0x45, 0xC3, 0x45, 0xC6, 0x47, 0xDD, 0x47,
    0xDE, 0x44, 0x0E, 0x08, 0x42, 0x0B, 0x0E, 0x40,
};
// 0x00000000: subq rsp, 56
// 0x00000004: .cfi_def_cfa_offset: 64
// 0x00000004: movq [rsp + 40], rbx
// 0x00000009: .cfi_offset: r3 at cfa-24
// 0x00000009: movq [rsp + 48], rbp
// 0x0000000e: .cfi_offset: r6 at cfa-16
// 0x0000000e: movsd [rsp + 24], xmm12
// 0x00000015: .cfi_offset: r29 at cfa-40
// 0x00000015: movsd [rsp + 32], xmm13
// 0x0000001c: .cfi_offset: r30 at cfa-32
// 0x0000001c: movq rax, rdi
// 0x0000001f: mov [rsp], edi
// 0x00000022: .cfi_remember_state
// 0x00000022: movq rbx, [rsp + 40]
// 0x00000027: .cfi_restore: r3
// 0x00000027: movq rbp, [rsp + 48]
// 0x0000002c: .cfi_restore: r6
// 0x0000002c: movsd xmm12, [rsp + 24]
// 0x00000033: .cfi_restore: r29
// 0x00000033: movsd xmm13, [rsp + 32]
// 0x0000003a: .cfi_restore: r30
// 0x0000003a: addq rsp, 56
// 0x0000003e: .cfi_def_cfa_offset: 8
// 0x0000003e: ret
// 0x0000003f: addb al, al
// 0x00000040: .cfi_restore_state
// 0x00000040: .cfi_def_cfa_offset: 64

static constexpr uint8_t expected_asm_kMips[] = {
    0xF4, 0xFF, 0xBD, 0x27, 0x08, 0x00, 0xB2, 0xAF, 0x04, 0x00, 0xB3, 0xAF,
    0x00, 0x00, 0xBF, 0xAF, 0xCC, 0xFF, 0xBD, 0x27, 0x25, 0x10, 0x80, 0x00,
    0x00, 0x00, 0xA4, 0xAF, 0x3C, 0x00, 0xB2, 0x8F, 0x38, 0x00, 0xB3, 0x8F,
    0x34, 0x00, 0xBF, 0x8F, 0x40, 0x00, 0xBD, 0x27, 0x09, 0x00, 0xE0, 0x03,
    0x00, 0x00, 0x00, 0x00,
};
static constexpr uint8_t expected_cfi_kMips[] = {
    0x44, 0x0E, 0x0C, 0x44, 0x92, 0x01, 0x44, 0x93, 0x02, 0x44, 0x9F, 0x03,
    0x44, 0x0E, 0x40, 0x48, 0x0A, 0x44, 0xD2, 0x44, 0xD3, 0x44, 0xDF, 0x44,
    0x0E, 0x00, 0x48, 0x0B, 0x0E, 0x40,
};
// 0x00000000: addiu r29, r29, -12
// 0x00000004: .cfi_def_cfa_offset: 12
// 0x00000004: sw r18, +8(r29)
// 0x00000008: .cfi_offset: r18 at cfa-4
// 0x00000008: sw r19, +4(r29)
// 0x0000000c: .cfi_offset: r19 at cfa-8
// 0x0000000c: sw r31, +0(r29)
// 0x00000010: .cfi_offset: r31 at cfa-12
// 0x00000010: addiu r29, r29, -52
// 0x00000014: .cfi_def_cfa_offset: 64
// 0x00000014: or r2, r4, r0
// 0x00000018: sw r4, +0(r29)
// 0x0000001c: .cfi_remember_state
// 0x0000001c: lw r18, +60(r29)
// 0x00000020: .cfi_restore: r18
// 0x00000020: lw r19, +56(r29)
// 0x00000024: .cfi_restore: r19
// 0x00000024: lw r31, +52(r29)
// 0x00000028: .cfi_restore: r31
// 0x00000028: addiu r29, r29, 64
// 0x0000002c: .cfi_def_cfa_offset: 0
// 0x0000002c: jalr r0, r31
// 0x00000030: nop
// 0x00000034: .cfi_restore_state
// 0x00000034: .cfi_def_cfa_offset: 64

static constexpr uint8_t expected_asm_kMips64[] = {
    0xE8, 0xFF, 0xBD, 0x67, 0x10, 0x00, 0xB2, 0xFF, 0x08, 0x00, 0xB3, 0xFF,
    0x00, 0x00, 0xBF, 0xFF, 0xD8, 0xFF, 0xBD, 0x67, 0x25, 0x10, 0x80, 0x00,
    0x00, 0x00, 0xA4, 0xAF, 0x38, 0x00, 0xB2, 0xDF, 0x30, 0x00, 0xB3, 0xDF,
    0x28, 0x00, 0xBF, 0xDF, 0x40, 0x00, 0xBD, 0x67, 0x09, 0x00, 0xE0, 0x03,
    0x00, 0x00, 0x00, 0x00,
};
static constexpr uint8_t expected_cfi_kMips64[] = {
    0x44, 0x0E, 0x18, 0x44, 0x92, 0x02, 0x44, 0x93, 0x04, 0x44, 0x9F, 0x06,
    0x44, 0x0E, 0x40, 0x48, 0x0A, 0x44, 0xD2, 0x44, 0xD3, 0x44, 0xDF, 0x44,
    0x0E, 0x00, 0x48, 0x0B, 0x0E, 0x40,
};
// 0x00000000: daddiu r29, r29, -24
// 0x00000004: .cfi_def_cfa_offset: 24
// 0x00000004: sd r18, +16(r29)
// 0x00000008: .cfi_offset: r18 at cfa-8
// 0x00000008: sd r19, +8(r29)
// 0x0000000c: .cfi_offset: r19 at cfa-16
// 0x0000000c: sd r31, +0(r29)
// 0x00000010: .cfi_offset: r31 at cfa-24
// 0x00000010: daddiu r29, r29, -40
// 0x00000014: .cfi_def_cfa_offset: 64
// 0x00000014: or r2, r4, r0
// 0x00000018: sw r4, +0(r29)
// 0x0000001c: .cfi_remember_state
// 0x0000001c: ld r18, +56(r29)
// 0x00000020: .cfi_restore: r18
// 0x00000020: ld r19, +48(r29)
// 0x00000024: .cfi_restore: r19
// 0x00000024: ld r31, +40(r29)
// 0x00000028: .cfi_restore: r31
// 0x00000028: daddiu r29, r29, 64
// 0x0000002c: .cfi_def_cfa_offset: 0
// 0x0000002c: jr r31
// 0x00000030: nop
// 0x00000034: .cfi_restore_state
// 0x00000034: .cfi_def_cfa_offset: 64
