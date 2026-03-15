//
//  coruna_primitives.h
//  libjailbreak
//
//  Created by Security Researcher on 14.03.2024.
//

#ifndef coruna_primitives_h
#define coruna_primitives_h

#include <stdint.h>

// Coruna内核读写原语函数声明
int coruna_kread64(uint64_t kaddr, uint64_t *out);
int coruna_kwrite64(uint64_t kaddr, uint64_t value);
int coruna_physread64(uint64_t physaddr, uint64_t *out);
int coruna_physwrite64(uint64_t physaddr, uint64_t value);

// 初始化Coruna原语
int coruna_primitives_init(void);

#endif /* coruna_primitives_h */