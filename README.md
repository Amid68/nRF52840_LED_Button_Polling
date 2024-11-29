# nRF52840 LED Button Polling

This project demonstrates how to control an LED using a button on the nRF52840 Development Kit (DK). The example is implemented using the Zephyr RTOS, leveraging the DeviceTree for hardware abstraction. The button's state is polled, and the LED is updated accordingly.

---

## **Prerequisites**

- **Hardware**: Nordic Semiconductor nRF52840 DK
- **Software**: 
  - Zephyr SDK
  - Nordic Semiconductor nRF Connect SDK
- A basic understanding of GPIO operations and Zephyr's DeviceTree.

---

## **Features**

- Reads input from a button (`Button 1`) on the nRF52840 DK.
- Controls an LED (`LED 1`) based on the button state.
- Implements a polling mechanism with a configurable sleep interval for power efficiency.

---

## **Hardware Setup**

### **Button and LED Mapping**
The code uses the following mappings:
- **Button 1** (`sw0`): Configured as an input.
- **LED 1** (`led0`): Configured as an output.

### **Button Location**
![Button Location](image-51.png)

### **Button Pin Mapping**
![Button Pin Mapping](image-522.png)

---

## **How to Run**

1. **Set Up the Environment**:
   - Install Zephyr and nRF Connect SDK.
   - Clone the repository.

2. **Build the Application**:
   - Navigate to the project directory and use west to build:
     ```bash
     west build -b nrf52840dk_nrf52840
     ```

3. **Flash the Firmware**:
   - Connect the nRF52840 DK and flash the firmware:
     ```bash
     west flash
     ```

4. **Test the Application**:
   - Press `Button 1` on the DK. The `LED 1` should toggle according to the button's state.
