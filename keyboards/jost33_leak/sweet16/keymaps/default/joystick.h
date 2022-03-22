#pragma once 

//#define LX F7
//#define LY F6
#define RX F5
#define RY F4
#define LOW_AXIS_VALUE 1
#define REST_AXIS_VALUE 512
#define HIGH_AXIS_VALUE 1023
#define MAX_COORDINATE_VALUE 127
#define COORDINATE_THRESHOLD_VALUE 64

joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
  [0] = JOYSTICK_AXIS_VIRTUAL,
  [1] = JOYSTICK_AXIS_VIRTUAL
//  [2] = JOYSTICK_AXIS_VIRTUAL,
//  [3] = JOYSTICK_AXIS_VIRTUAL
  // [0] = JOYSTICK_AXIS_IN(X_PIN, LOW_AXIS_VALUE, REST_AXIS_VALUE, HIGH_AXIS_VALUE),
  // [1] = JOYSTICK_AXIS_IN(Y_PIN, LOW_AXIS_VALUE, REST_AXIS_VALUE, HIGH_AXIS_VALUE)
};

uint8_t timeoutThreshold = 10;
uint16_t lastTimestamp = 0;

int8_t axisCoordinate(uint8_t pin) {
  int8_t direction;
  int16_t range;
  int16_t distance;
  int16_t position = analogReadPin(pin);

  if (position == REST_AXIS_VALUE) {
    return 0;
  } else if (position < REST_AXIS_VALUE) {
    distance = REST_AXIS_VALUE - position;
    range = REST_AXIS_VALUE - LOW_AXIS_VALUE;
    direction = 1;
  } else {
    distance = position - REST_AXIS_VALUE;
    range = HIGH_AXIS_VALUE - REST_AXIS_VALUE;
    direction = -1;
  }

  float percent = (float)distance / range;
  int16_t coordinate = (int16_t)(percent * MAX_COORDINATE_VALUE);
  if (coordinate < 0) {
    return 0;
  } else if (coordinate > MAX_COORDINATE_VALUE) {
    return MAX_COORDINATE_VALUE * direction;
  } else {
    return coordinate * direction;
  }
}

int8_t axisToMouseComponent(uint8_t pin) {
  int coordinate = axisCoordinate(pin);
  if (coordinate == 0) {
    return 0;
  } else {
    int precisionRegulator = 1000;
    return abs(coordinate) * (float)coordinate / precisionRegulator;
  }
}

uint16_t axisToKeycodeComponent(uint8_t layer, uint8_t x_pin, uint8_t y_pin) {
  const keypos_t keypos[] = {
    [0] = (keypos_t) {.row = 2, .col = 1 }, // UP
    [1] = (keypos_t) {.row = 4, .col = 5 }, // DOWN
    [2] = (keypos_t) {.row = 6, .col = 1 }, // LEFT
    [3] = (keypos_t) {.row = 3, .col = 4 }  // RIGHT
  };
  int8_t x = axisCoordinate(RX);
  int8_t y = axisCoordinate(RY);

  if (abs(x) > abs(y)) {
    if (x > COORDINATE_THRESHOLD_VALUE) {
      return keymap_key_to_keycode(layer, keypos[3]);
    } else if ((x * -1) > COORDINATE_THRESHOLD_VALUE) {
      return keymap_key_to_keycode(layer, keypos[2]);
    }
  } else {
    if (y > COORDINATE_THRESHOLD_VALUE) {
      return keymap_key_to_keycode(layer, keypos[0]);
    } else if ((y * -1) > COORDINATE_THRESHOLD_VALUE) {
      return keymap_key_to_keycode(layer, keypos[1]);
    }
  }
  return KC_NO;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  if (layer == 1 || layer == 2) {
    if (timer_elapsed(lastTimestamp) > timeoutThreshold) {
      lastTimestamp = timer_read();
      uint16_t keycode = axisToKeycodeComponent(layer, RX, RY);
      tap_code(keycode);
    }
  } else if (layer == 3) {
    joystick_status.axes[0] = axisCoordinate(RX);
    joystick_status.axes[1] = axisCoordinate(RY);
    joystick_status.status |= JS_UPDATED;
  }
}

void pointing_device_task(void) {
  uint8_t layer = biton32(layer_state);
  if (layer == 0) {
    if (timer_elapsed(lastTimestamp) > timeoutThreshold) {
      lastTimestamp = timer_read();
      report_mouse_t report = pointing_device_get_report();
      report.x = axisToMouseComponent(RX);
      report.y = axisToMouseComponent(RY);
      pointing_device_set_report(report);
      pointing_device_send();
    }
  }