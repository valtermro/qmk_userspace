// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

// Autocorrection dictionary (11 entries):
//   nao:         -> n~ao
//   :voce:       -> voc^e
//   :comeco      -> come'co
//   :ha:         -> h'a
//   :acao:       -> a'c~ao
//   :alteracao:  -> altera'c~ao
//   :compilacao: -> compila'c~ao
//   :macacao:    -> macac~ao
//   :macarrao:   -> macarr~ao
//   :mantem:     -> mant'em
//   :posicao:    -> posi'c~ao

#define AUTOCORRECT_MIN_LENGTH 4 // "nao:"
#define AUTOCORRECT_MAX_LENGTH 12 // ":compilacao:"
#define DICTIONARY_SIZE 164

static const uint8_t autocorrect_data[DICTIONARY_SIZE] PROGMEM = {
    0x6C, 0x07, 0x00, 0x12, 0x98, 0x00, 0x00, 0x44, 0x14, 0x00, 0x08, 0x1B, 0x00, 0x10, 0x24, 0x00,
    0x12, 0x30, 0x00, 0x00, 0x0B, 0x2C, 0x00, 0x81, 0x27, 0x61, 0x00, 0x06, 0x12, 0x19, 0x2C, 0x00,
    0x81, 0x5E, 0x65, 0x00, 0x08, 0x17, 0x11, 0x04, 0x10, 0x2C, 0x00, 0x82, 0x27, 0x65, 0x6D, 0x00,
    0x04, 0x00, 0x46, 0x3C, 0x00, 0x11, 0x87, 0x00, 0x15, 0x8C, 0x00, 0x00, 0x44, 0x43, 0x00, 0x0C,
    0x7B, 0x00, 0x00, 0x6C, 0x50, 0x00, 0x06, 0x57, 0x00, 0x0F, 0x60, 0x00, 0x15, 0x6E, 0x00, 0x00,
    0x83, 0x27, 0x63, 0x7E, 0x61, 0x6F, 0x00, 0x04, 0x10, 0x2C, 0x00, 0x82, 0x7E, 0x61, 0x6F, 0x00,
    0x0C, 0x13, 0x10, 0x12, 0x06, 0x2C, 0x00, 0x83, 0x27, 0x63, 0x7E, 0x61, 0x6F, 0x00, 0x08, 0x17,
    0x0F, 0x04, 0x2C, 0x00, 0x83, 0x27, 0x63, 0x7E, 0x61, 0x6F, 0x00, 0x16, 0x12, 0x13, 0x2C, 0x00,
    0x83, 0x27, 0x63, 0x7E, 0x61, 0x6F, 0x00, 0x82, 0x7E, 0x61, 0x6F, 0x00, 0x15, 0x04, 0x06, 0x04,
    0x10, 0x2C, 0x00, 0x82, 0x7E, 0x61, 0x6F, 0x00, 0x06, 0x08, 0x10, 0x12, 0x06, 0x2C, 0x00, 0x81,
    0x27, 0x63, 0x6F, 0x00
};
