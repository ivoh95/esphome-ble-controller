#pragma once

#include "esphome/core/defines.h"
#ifdef USE_TEXT_SENSOR

#include <string>

#include "esphome/components/text_sensor/text_sensor.h"

#include "ble_component_handler.h"

using std::string;

namespace esphome {
namespace esp32_ble_controller {

using text_sensor::TextSensor;

/**
 * Special component handler for sensors, which adds the sensor's unit of measure to the component description.
 */
class BLETextSensorHandler : public BLEComponentHandler<TextSensor> {
public:
  BLETextSensorHandler(TextSensor* component, const BLECharacteristicInfoForHandler& characteristic_info) : BLEComponentHandler(component, characteristic_info) {}
  virtual ~BLETextSensorHandler() {}

protected:
  virtual bool can_receive_writes() { return true; }
  virtual void on_characteristic_written() override;
};

} // namespace esp32_ble_controller
} // namespace esphome

#endif
