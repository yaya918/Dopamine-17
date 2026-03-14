//
//  coruna_mach_o_builder.h
//  libjailbreak
//
//  Created by Security Researcher on 14.03.2024.
//

#ifndef coruna_mach_o_builder_h
#define coruna_mach_o_builder_h

#include <stdint.h>

// Coruna Mach-O载荷构建器函数声明
int coruna_build_mach_o_payload(uint8_t **payload, size_t *payload_size);
int coruna_inject_payload(uint8_t *payload, size_t payload_size);

#endif /* coruna_mach_o_builder_h */