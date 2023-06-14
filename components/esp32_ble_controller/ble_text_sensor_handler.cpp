#include "ble_text_sensor_handler.h"

#ifdef USE_TEXT_SENSOR


#include "esphome/core/log.h"

namespace esphome {
namespace esp32_ble_controller {

static const char *TAG = "ble_text_sensor_handler";

void BLETextSensorHandler::on_characteristic_written() {
  std::string value = get_characteristic()->getValue();
  ESP_LOGD(TAG, "Text Sensor chracteristic written: %d", value);
  get_component()->publish_state(value);
}

} // namespace esp32_ble_controller
} // namespace esphome

#endif
