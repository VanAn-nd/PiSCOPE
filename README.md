

![q](https://github.com/user-attachments/assets/ce25b431-6d24-49e7-9251-946a20a0c16d)


This is first test version!
- My problem is controll relays from PCF8575 (only a few mA).
- Firmware not completed but it can run basicly.
- Testing video: https://www.youtube.com/watch?v=tYiyRkHMCBc




![1](https://github.com/user-attachments/assets/7b3e4b2d-10e7-48e6-b6e0-9fb43e72fd99)




30/4/2025 Update Ver 1.1:
- Fix relay and opto switch issues.
- Select another amplifier AD8009 1GHz, or LMH6702 1.7Ghz.
- Use MT3608-Cuk converter as negative voltage regulator.
- Battery measure.
- Firmware: already work! but i will update date, fix bugs, calib...
- Going to add XY mode, FFT.



![z6798751336443_d7a12fdec96ae0f947d0633dd5c7b1f9](https://github.com/user-attachments/assets/1238477a-fde3-46bb-89a7-b2a209813ea6)




5/7/2025 Update firmware v1.1.2:
- Hardware work great.
- Added Acquisition modes (Average/Peak Detect).
- The trigger detection algorithm greater.
- Simple manual calibration mode.
- All configurations and calibration data are saved to a 24C256 EEPROM.
- FFT functionality has been implemented (will be update on next firmware version). 1024/RP2040  and 4096/RP2350.
  13/7/2025:
        Comparison between the RP2040 and RP2350A: The RP2350A has more than twice the amount of RAM compared to the RP2040, and importantly, it features an FPU (Floating Point Unit), which significantly speeds up computations compared to the RP2040. Currently, the FFT mode is set by default to 1024 points for the RP2040 and 4096 points for the RP2350A. Commonly used window functions include: HFT248D, Flat Top, Blackman-Harris, Hamming, and Hanning.
