
# ESP32 and BME280 based temperature, humidity, and barometric pressure measurer


## Zine
<img width="2250" height="3450" alt="Zine" src="https://github.com/user-attachments/assets/a94ebbda-1810-4cc1-a2e8-3dbaddabde81" />


## Description

### Made for [Fallout](https://fallout.hackclub.com/) during a online weekend hackathon

### Why did i make this

I always had this idea, because i never know what to wear outside before leaving my house and I can't be hassled to check the weather app, so i will place this at the door window, so i can look and and check the temperature and other weather stats before leaving.

### How to build

Download the Gerber files and the 3d models and print them out. (I recomend JLCPCB and Prining Leigion). Order all the parts from the BOM section. After everything arrives solder the components togeather with the board and put the PCB in the case and Screw it in with a 2mm Screw. After close the box and screw it in with 3mm Screws. Connect the ESP32 to your computer and flash it with the firmware.

### How to use

After flashing it, turn the ESP32 back on and it should start automaticly. If everything worked out it should start showing the data on the OLED screen.

## KICAD

### Schematic

<img width="1331" height="820" alt="image" src="https://github.com/user-attachments/assets/1e23a444-3d6b-4a8c-8392-7229521711cf" />

### PCB layout

<img width="422" height="676" alt="image" src="https://github.com/user-attachments/assets/e47e3847-c44c-40f7-876a-189b53b7137a" />

### PCB Render (Front/Back)

<img width="826" height="678" alt="image" src="https://github.com/user-attachments/assets/218feaec-7351-49ff-80a5-f60efd4a12aa" />

## FUSION (Front/Back)

<img width="995" height="682" alt="image" src="https://github.com/user-attachments/assets/b28c7f59-bb8f-41ab-b07d-2bbc3f2a864e" />


## BOM

| NAME | LINK | PRICE | QUANTITY | Need To buy? |
|------|------|-------|----------|--------------|
| XIAO ESP32-S3 | [AliExpress](https://www.aliexpress.com/item/1005007341749305.html) | $10,35 | 1 | Yes |
| BME280 | [AliExpress](https://www.aliexpress.com/item/1005006982994037.html) | $1,82 | 1 | Yes |
| 4,7k Resistors | [AliExpress](https://www.aliexpress.com/item/1005007345052730.html) | $1,36 | 1 | Yes |
| 3D Case | JLC3DP | $2,79 | 1 | Yes |
| PCB | JLCPCB | $5,00 | 1 | Yes |
| **TOTAL** | | **$23,53** | | |


