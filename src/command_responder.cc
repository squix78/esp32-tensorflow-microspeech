/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "command_responder.h"
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`


SSD1306Wire  display(0x3c, 21, 22);


// The default implementation writes out the name of the recognized command
// to the error console. Real applications will want to take some custom
// action instead, and should implement their own versions of this function.
void RespondToCommand(tflite::ErrorReporter* error_reporter,
                      int32_t current_time, const char* found_command,
                      uint8_t score, bool is_new_command) {
  static boolean isDisplayInitialized = false;
  if (!isDisplayInitialized) {
    display.init();
    display.clear();
    display.setFont(ArialMT_Plain_24);
    display.display();
    isDisplayInitialized = true;
  }
  static uint16_t lastInfo = 0;
  if (is_new_command) {
    TF_LITE_REPORT_ERROR(error_reporter, "Heard %s (%d) @%dms", found_command,
                         score, current_time);
    display.clear();                     
    display.drawString(0, 26, String(found_command));
    display.display();
    lastInfo = millis();
  } 
  if (millis() - lastInfo > 3000) {
    display.clear();
    display.display();
  }
}
